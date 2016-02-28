/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
**********/

/*
 * String functions
 */

#include "ngspice/ngspice.h"
#include "ngspice/stringutil.h"

#include <stdarg.h>


int
prefix(const char *p, const char *s)
{
    while (*p && (*p == *s))
        p++, s++;
    if (!*p)
        return (TRUE);
    else
        return (FALSE);
}

/* Create a copy of a string. */

char *
copy(const char *str)
{
    char *p;
    
    if (!str)
        return NULL;

    if ((p = TMALLOC(char, strlen(str) + 1)) != NULL)
	    (void) strcpy(p, str);
    return(p);
}

char *
copy_substring(const char *str, const char *end)
{
    size_t n = (size_t) (end - str);
    char *p;

    if ((p = TMALLOC(char, n + 1)) != NULL) {
        (void) strncpy(p, str, n);
        p[n] = '\0';
    }
    return(p);
}


char *
tvprintf(const char *fmt, va_list args)
{
    char buf[1024];
    char *p = buf;
    int size = sizeof(buf);

    for (;;) {

        int nchars;
        va_list ap;

        va_copy(ap, args);
        nchars = vsnprintf(p, (size_t) size, fmt, ap);
        va_end(ap);

        if (nchars == -1) {     // compatibility to old implementations
            size *= 2;
        } else if (size < nchars + 1) {
            size = nchars + 1;
        } else {
            break;
        }

        if (p == buf)
            p = TMALLOC(char, size);
        else
            p = TREALLOC(char, p, size);
    }


    return (p == buf) ? copy(p) : p;
}


char *
tprintf(const char *fmt, ...)
{
    char *rv;
    va_list ap;

    va_start(ap, fmt);
    rv = tvprintf(fmt, ap);
    va_end(ap);

    return rv;
}


/* Determine whether sub is a substring of str. */
/* Like strstr( ) XXX */

int
substring(const char *sub, const char *str)
{
    const char *s, *t;

    while (*str) {
        if (*str == *sub) {
	    t = str;
            for (s = sub; *s; s++) {
                if (!*t || (*s != *t++))
                    break;
            }
            if (*s == '\0')
                return (TRUE);
        }
        str++;
    }
    return (FALSE);
}

/* Append one character to a string. Don't check for overflow. */
/* Almost like strcat( ) XXX */

void
appendc(char *s, char c)
{
    while (*s)
        s++;
    *s++ = c;
    *s = '\0';
    return;
}

/* Try to identify an integer that begins a string. Stop when a non-
 * numeric character is reached.
 */
/* Like atoi( ) XXX */

int
scannum(char *str)
{
    int i = 0;

    while(isdigit(char_to_int(*str)))
        i = i * 10 + *(str++) - '0';
    return(i);
}

/* Case insensitive str eq. */
/* Like strcasecmp( ) XXX */

int
cieq(const char *p, const char *s)
{
    while (*p) {
        if ((isupper(char_to_int(*p)) ? tolower(char_to_int(*p)) : *p) !=
            (isupper(char_to_int(*s)) ? tolower(char_to_int(*s)) : *s))
            return(FALSE);
        p++;
        s++;
    }
    return (*s ? FALSE : TRUE);
}

/* Case insensitive prefix. */

int
ciprefix(const char *p, const char *s)
{
    while (*p) {
        if ((isupper(char_to_int(*p)) ? tolower(char_to_int(*p)) : *p) !=
            (isupper(char_to_int(*s)) ? tolower(char_to_int(*s)) : *s))
            return(FALSE);
        p++;
        s++;
    }
    return (TRUE);
}

/* Case insensitive prefix.
 * s may be shorter than p */
int
cisymprefix(const char *p, const char *s)
{
    while (*p) {
        if (!s || (isupper(char_to_int(*p)) ? tolower(char_to_int(*p)) : *p) !=
            (isupper(char_to_int(*s)) ? tolower(char_to_int(*s)) : *s))
            return(FALSE);
        p++;
        s++;
    }
    return (TRUE);
}




void
strtolower(char *str)
{
    if (str)
        while (*str) {
            if(isupper(char_to_int(*str)))
                *str = (char) tolower(char_to_int(*str));
            str++;
        }
}

void
strtoupper(char *str)
{
    if (str)
        while (*str) {
            if(islower(char_to_int(*str)))
                *str = (char) toupper(char_to_int(*str));
            str++;
        }
}
