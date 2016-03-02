/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Wayne A. Christopher, U. C. Berkeley CAD Group
**********/

/*
 * Initial lexer.
 */

#include "ngspice/ngspice.h"
#include "ngspice/cpdefs.h"

#include <errno.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_PWD_H
#include <sys/types.h>
#include <pwd.h>
#endif

/* MW. Linux has TIOCSTI, so we include all headers here */
#if !defined(__MINGW32__) && !defined(_MSC_VER)
#include <sys/ioctl.h>
#endif

#ifdef HAVE_SGTTY_H
#include <sys/types.h>
#include <sgtty.h>
#else
#ifdef HAVE_TERMIO_H
#include <sys/types.h>
#include <termio.h>
#else
#ifdef HAVE_TERMIOS_H
#include <sys/types.h>
#include <termios.h>
#endif
#endif
#endif

#define NEW_BSIZE_SP 2*BSIZE_SP

#include "ngspice/fteinput.h"
#include "lexical.h"

static void prompt(void);

extern bool cp_echo;  /* For CDHW patches: defined in variable.c */

FILE *cp_inp_cur = NULL;
int cp_event = 1;
bool cp_interactive = TRUE;
bool cp_bqflag = FALSE;
char *cp_promptstring = NULL;
char *cp_altprompt = NULL;
char cp_hash = '#';

static int numeofs = 0;


#define ESCAPE  '\033'


/* Return a list of words, with backslash quoting and '' quoting done.
 * Strings enclosed in "" or `` are made single words and returned,
 * but with the "" or `` still present. For the \ and '' cases, the
 * 8th bit is turned on (as in csh) to prevent them from being recognized,
 * and stripped off once all processing is done. We also have to deal with
 * command, filename, and keyword completion here.
 * If string is non-NULL, then use it instead of the fp. Escape and EOF
 * have no business being in the string.
 */

#define append(word)                            \
    wl_append_word(&wlist, &cw, word)


#define newword                                 \
    do {                                        \
        append(copy(buf));                      \
        bzero(buf, (size_t) len);               \
        i = 0;                                  \
    } while(0)


/* CDHW Debug function */
/* CDHW used to perform function of set echo */

static void
pwlist_echo(wordlist *wlist, char *name)
{
    wordlist *wl;

    if (!cp_echo || cp_debug)
        return;

    fprintf(cp_err, "%s ", name);
    for (wl = wlist; wl; wl = wl->wl_next)
        fprintf(cp_err, "%s ", wl->wl_word);
    fprintf(cp_err, "\n");
}


static int
cp_readchar(char **string, FILE *fptr)
{
    if (*string == NULL)
        return input(fptr);

    if (**string)
        return *(*string)++;
    else
        return '\n';
}


/* CDHW */

wordlist *
cp_lexer(char *string)
{
    int c, d;
    int i, j;
    wordlist *wlist = NULL, *cw = NULL;
    char *buf, *linebuf;
    int paren, len;

    if (!cp_inp_cur)
        cp_inp_cur = cp_in;

    /* prompt for string if none is passed */
    if (!string && cp_interactive) {
        cp_ccon(TRUE);
        prompt();
    }

nloop:
    wlist = cw = NULL;
    i = 0;
    j = 0;
    paren = 0;
    if (string)
        len = (int) strlen(string) + 3;
    else
        len = 64;
    buf = TMALLOC(char, len);
    linebuf = TMALLOC(char, len);

    for (;;) {
        /* if string, read from string, else read from stdin */
        c = cp_readchar(&string, cp_inp_cur);

    gotchar:

        if (string && (c == ESCAPE))
            continue;

        if ((c != EOF) && (c != ESCAPE))
            linebuf[j++] = (char) c;

        if (c != EOF)
            numeofs = 0;

        /* If number of char allocated is reached, double the
           buffer size by realloc and fill new memory with \0 */
        if (i == len - 1) {
            int ii;
            len = 2 * len;
            buf = TREALLOC(char, buf, len);
            for (ii = i; ii < len; ii++ )
                buf[ii] = '\0';
            linebuf = TREALLOC(char, linebuf, len);
            for (ii = j; ii < len; ii++ )
                linebuf[ii] = '\0';
        }

        /* Probably only measuring j is needed, because j (line
           position) should be larger than i (word position) */
        if (j == len - 1) {
            int ii;
            len = 2 * len;
            buf = TREALLOC(char, buf, len);
            for (ii = i; ii < len; ii++ )
                buf[ii] = '\0';
            linebuf = TREALLOC(char, linebuf, len);
            for (ii = j; ii < len; ii++ )
                linebuf[ii] = '\0';
        }

        if (c != EOF)           /* Don't need to do this really. */
            c = strip(c);

        /* if '\' or '^', add following character to linebuf */
        if ((c == '\\' && DIR_TERM != '\\') || (c == '\026') /* ^V */ ) {
            c = quote(cp_readchar(&string, cp_inp_cur));
            linebuf[j++] = (char) strip(c);
        }

        /* if reading from fcn backeval() for backquote subst. */
        if ((c == '\n') && cp_bqflag)
            c = ' ';

        if ((c == EOF) && cp_bqflag)
            c = '\n';

        /* '#' as first character, batch mode, read from stdin
         * go to end of line, and then restart reading */
        /* What is this ?? */
        if ((c == cp_hash) && !cp_interactive && (j == 1)) {
            wl_free(wlist);
            wlist = cw = NULL;
            tfree(buf);
            tfree(linebuf);
            if (string)
                return NULL;
            while (((c = cp_readchar(&string, cp_inp_cur)) != '\n') && (c != EOF))
                ;
            goto nloop;
        }

        /* check if we are inside of parens during reading:
         * if we are and ',' or ';' occur: no new line */
        if ((c == '(') || (c == '['))
            paren++;
        else if ((c == ')') || (c == ']'))
            paren--;

        /* What else has to be decided, depending on c ?*/
        switch (c) {

        /* new word to wordlist, when space or tab follow */
        case ' ':
        case '\t':
            if (i > 0) {
                buf[i] = '\0';
                newword;
            }
            break;

        /* new word to wordlist, when \n follows */
        case '\n':
            if (i) {
                buf[i] = '\0';
                newword;
            }
            if (!cw)
                append(NULL);
            goto done;

        /* if ' read until next ' is hit, will form a new word,
           but without the ' */
        case '\'':
            while (((c = cp_readchar(&string, cp_inp_cur)) != '\'') &&
                (i < len - 1))
            {
                if ((c == '\n') || (c == EOF) || (c == ESCAPE))
                    goto gotchar;
                buf[i++] = (char) quote(c);
                linebuf[j++] = (char) c;
            }
            linebuf[j++] = '\'';
            break;

        /* if " or `, read until next " or ` is hit, will form a new word,
           including the quotes.
           In case of \, the next character gets the eights bit set. */
        case '"':
        case '`':
            d = c;
            buf[i++] = (char) d;
            while (((c = cp_readchar(&string, cp_inp_cur)) != d) &&
                (i < len - 2))

            {
                if ((c == '\n') || (c == EOF) || (c == ESCAPE))
                    goto gotchar;
                if (c == '\\') {
                    linebuf[j++] = (char) c;
                    c = cp_readchar(&string, cp_inp_cur);
                    buf[i++] = (char) quote(c);
                    linebuf[j++] = (char) c;
                } else {
                    buf[i++] = (char) c;
                    linebuf[j++] = (char) c;
                }
            }
            buf[i++] = (char) d;
            linebuf[j++] = (char) d;
            break;

        case '\004':
        case EOF:
            /* upon command completion, not used actually */
            if (cp_interactive && !cp_nocc && !string) {

                if (j == 0) {
                    if (cp_ignoreeof && (numeofs++ < 23)) {
                        fputs("Use \"quit\" to quit.\n", stdout);
                    } else {
                        fputs("quit\n", stdout);
                        cp_doquit();
                    }
                    append(NULL);
                    goto done;
                }

                // cp_ccom doesn't mess wlist, read only access to wlist->wl_word
                cp_ccom(wlist, buf, FALSE);
                wl_free(wlist);
                (void) fputc('\r', cp_out);
                prompt();
                for (j = 0; linebuf[j]; j++)
#ifdef TIOCSTI
                    (void) ioctl(fileno(cp_out), TIOCSTI, linebuf + j);
#else
                fputc(linebuf[j], cp_out);  /* But you can't edit */
#endif
                wlist = cw = NULL;
                tfree(buf);
                tfree(linebuf);
                goto nloop;
            }

            /* EOF during a source */
            if (cp_interactive) {
                fputs("quit\n", stdout);
                cp_doquit();
                append(NULL);
                goto done;
            }

            wl_free(wlist);
            tfree(buf);
            tfree(linebuf);
            return NULL;

        case ESCAPE:
            /* upon command completion, not used actually */
            if (cp_interactive && !cp_nocc) {
                fputs("\b\b  \b\b\r", cp_out);
                prompt();
                for (j = 0; linebuf[j]; j++)
#ifdef TIOCSTI
                    (void) ioctl(fileno(cp_out), TIOCSTI, linebuf + j);
#else
                fputc(linebuf[j], cp_out);  /* But you can't edit */
#endif
                // cp_ccom doesn't mess wlist, read only access to wlist->wl_word
                cp_ccom(wlist, buf, TRUE);
                wl_free(wlist);
                wlist = cw = NULL;
                tfree(buf);
                tfree(linebuf);
                goto nloop;
            }
            goto ldefault;

        case ',':
            if ((paren < 1) && (i > 0)) {
                newword;
                break;
            }
            goto ldefault;

        case ';':  /* CDHW semicolon inside parentheses is part of expression */
            if (paren > 0) {
                buf[i++] = (char) c;
                break;
            }
            goto ldefault;

        case '&':  /* va: $&name is one word */
            if ((i >= 1) && (buf[i-1] == '$') && (c == '&')) {
                buf[i++] = (char) c;
                break;
            }
            goto ldefault;

        case '<':
        case '>':  /* va: <=, >= are unbreakable words */
            if (string)
                if ((i == 0) && (*string == '=')) {
                    buf[i++] = (char) c;
                    break;
                }
            goto ldefault;

        default:
            /* We have to remember the special case $<
             * here
             */
        ldefault:
            if ((cp_chars[c] & CPC_BRL) && (i > 0))
                if ((c != '<') || (buf[i-1] != '$'))
                    newword;
            buf[i++] = (char) c;
            if (cp_chars[c] & CPC_BRR)
                if ((c != '<') || (i < 2) || (buf[i-2] != '$'))
                    newword;
        }
    }

done:
    if (wlist->wl_word)
        pwlist_echo(wlist, "Command>");
    tfree(buf);
    tfree(linebuf);
    return wlist;
}


static void
prompt(void)
{
    char *s;

    if (cp_interactive == FALSE)
        return;

    if (cp_altprompt)
        s = cp_altprompt;
    else if (cp_promptstring)
        s = cp_promptstring;
    else
        s = "-> ";

    while (*s) {
        switch (strip(*s)) {
        case '!':
            fprintf(cp_out, "%d", cp_event);
            break;
        case '\\':
            if (s[1])
                (void) putc(strip(*++s), cp_out);
        default:
            (void) putc(strip(*s), cp_out);
        }
        s++;
    }

    (void) fflush(cp_out);
}
