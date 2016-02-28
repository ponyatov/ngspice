/* Copyright 1990
   Regents of the University of California.
   All rights reserved.

   Author: 1985 Wayne A. Christopher

   The main routine for ngspice
*/

#include "ngspice/ngspice.h"

#include <setjmp.h>
#include <signal.h>

/* Added GNU Readline Support 11/3/97 -- Andrew Veliath <veliaa@rpi.edu> */
/* from spice3f4 patch to ng-spice. jmr */
#ifdef HAVE_GNUREADLINE
# include <readline/readline.h>
# include <readline/history.h>
#endif

/* SJB added editline support 2005-05-05 */
#ifdef HAVE_BSDEDITLINE
# include <editline/readline.h>
extern VFunction *rl_event_hook;    /* missing from editline/readline.h */
extern int rl_catch_signals;        /* missing from editline/readline.h */
#endif

#include "ngspice/iferrmsg.h"
#include "ngspice/fteext.h"
#include "misc/ivars.h"
#include "misc/misc_time.h"
#include "misc/util.h"

#if defined(HAS_WINGUI) || defined(_MSC_VER) || defined(__MINGW32__)
# include "misc/mktemp.h"
#endif

#if defined(HAVE_GETOPT_LONG) && defined(HAVE_GETOPT_H)
# include <getopt.h>
#else
# include "misc/getopt_bsd.h"
#endif


#if defined(HAVE_GNUREADLINE) || defined(HAVE_BSDEDITLINE)
char history_file[512] = {'\0'};
static char *application_name;
#endif

/* Undefine this next line for debug tracing */
/* #define TRACE */

/* Main options */
static bool ft_servermode = FALSE;
bool ft_batchmode = FALSE;
bool ft_pipemode = FALSE;
bool rflag = FALSE; /* has rawfile */

/* Frontend options */
bool ft_intrpt = FALSE;     /* Set by the (void) signal handlers. TRUE = we've been interrupted. */
bool ft_setflag = FALSE;    /* TRUE = Don't abort simulation after an interrupt. */
char *ft_rawfile = "rawspice.raw";

#ifdef HAS_WINGUI
extern void winmessage(char *new_msg); /* display a message box (defined in winmain.c)*/
extern void SetSource(char *Name);    /* display the source file name in the source window */
extern int  xmain(int argc, char **argv);
FILE *flogp = NULL;         /* log file ('-o logfile' command line option) */
#else
bool orflag = FALSE; /* global for -o option */
#endif

FILE *slogp = NULL;          /* soa log file ('--soa-log file' command line option) */

/* Frontend and circuit options */
IFsimulator *ft_sim = NULL;

char *errRtn;     /* name of the routine declaring error */
char *errMsg = NULL;     /* descriptive message about what went wrong */

char *Infile_Path = NULL; /* Path to netlist input file */


/* Globals definitions for Machine Accuracy Limits
 * (needed by CIDER)
 */
double BMin;                /* lower limit for B(x) */
double BMax;                /* upper limit for B(x) */
double ExpLim;              /* limit for exponential */
double Accuracy;            /* accuracy of the machine */
double MuLim, MutLim;

#ifdef CIDER
/* Global debug flags from CIDER, soon they will become
 * spice variables :)
 */
BOOLEAN ONEacDebug   = FALSE;
BOOLEAN ONEdcDebug   = TRUE;
BOOLEAN ONEtranDebug = TRUE;
BOOLEAN ONEjacDebug  = FALSE;

BOOLEAN TWOacDebug   = FALSE;
BOOLEAN TWOdcDebug   = TRUE;
BOOLEAN TWOtranDebug = TRUE;
BOOLEAN TWOjacDebug  = FALSE;

/* CIDER Global Variable Declarations */

int BandGapNarrowing;
int TempDepMobility, ConcDepMobility, FieldDepMobility, TransDepMobility;
int SurfaceMobility, MatchingMobility, MobDeriv;
int CCScattering;
int Srh, Auger, ConcDepLifetime, AvalancheGen;
int FreezeOut = FALSE;
int OneCarrier;

int MaxIterations = 100;
int AcAnalysisMethod = DIRECT;

double Temp, RelTemp, Vt;
double RefPsi;/* potential at Infinity */
double EpsNorm, VNorm, NNorm, LNorm, TNorm, JNorm, GNorm, ENorm;

/* end cider globals */
#endif /* CIDER */


/* static functions */
int SIMinit(void);
static ATTRIBUTE_NORETURN void sp_shutdown(int exitval);

#if defined(HAVE_GNUREADLINE) || defined(HAVE_BSDEDITLINE)
static char *prompt(void);
#endif

#ifndef X_DISPLAY_MISSING
# ifdef HAVE_GNUREADLINE
static int app_event_func(void);
# endif
# ifdef HAVE_BSDEDITLINE
static void app_event_func(void);
# endif
#endif

static void show_help(void);
static void show_version(void);
static bool read_initialisation_file(char *dir, char *name);

static void append_to_stream(FILE *dest, FILE *source);


extern IFsimulator SIMinfo;


const bool ft_nutmeg = FALSE;

extern int OUTpBeginPlot(CKTcircuit *, JOB *, IFuid, IFuid, int, int, IFuid *, int, runDesc **);
extern int OUTpData(runDesc *, IFvalue *, IFvalue *);
extern int OUTwBeginPlot(CKTcircuit *, JOB *, IFuid, IFuid, int, int, IFuid *, int, runDesc **);
extern int OUTwReference(runDesc *, IFvalue *, void **);
extern int OUTwData(runDesc *, int, IFvalue *, void *), OUTwEnd(runDesc *), OUTendPlot(runDesc *);
extern int OUTbeginDomain(runDesc *, IFuid, int, IFvalue *);
extern int OUTendDomain(runDesc *), OUTstopnow(void);
extern void OUTerror(int, char *, IFuid *);

#ifdef __GNUC__
extern void OUTerrorf(int, const char *fmt, ...)  __attribute__ ((format (__printf__, 2, 3)));
#else
extern void OUTerrorf(int, const char *fmt, ...);
#endif

extern int OUTattributes(runDesc *, IFuid, int, IFvalue *);

extern void initw(void);



char *hlp_filelist[] = { "ngspice", NULL };


/* allocate space for global constants in 'CONST.h' */

double CONSTroot2;
double CONSTvt0;
double CONSTKoverQ;
double CONSTe;
IFfrontEnd *SPfrontEnd = NULL;
int DEVmaxnum = 0;

/* -------------------------------------------------------------------------- */
/* Set a compatibility flag.
   Currently available are flags for:
   - ngspice (standard)
   - a commercial simulator
   - Spice3
   - all compatibility stuff
*/


/* -------------------------------------------------------------------------- */
int
SIMinit(void)
{
    return OK;
}


/* -------------------------------------------------------------------------- */
/* Shutdown gracefully. */
static ATTRIBUTE_NORETURN void
sp_shutdown(int exitval)
{
    destroy_ivars();
#ifdef HAS_WINGUI
    if (exitval == EXIT_BAD)
        winmessage("Fatal error in SPICE");
    else if (exitval == EXIT_INFO)
        winmessage("Information during setup, see main window!");
#endif
    if  (exitval == EXIT_INFO)
        exitval = EXIT_NORMAL;
    exit(exitval);
}

/* -------------------------------------------------------------------------- */

#if defined(HAVE_GNUREADLINE) || defined(HAVE_BSDEDITLINE)
/* Adapted ../lib/cp/lexical.c:prompt() for GNU Readline -- Andrew Veliath <veliaa@rpi.edu> */
static char *
prompt(void)
{
    static char pbuf[128];
    char *p = pbuf, *s;

    if (cp_interactive == FALSE)
        return NULL;    /* NULL means no prompt */

    s = get_alt_prompt();

    if (!s)
        s = cp_promptstring;

    if (!s)
        s = "->";

    while (*s) {
        char c = (char) strip(*s++);
        switch (c) {
        case '!':
            p += sprintf(p, "%d", where_history() + 1);
            break;
        case '\\':
            if (*s)
                c = (char) strip(*s++);
        default:
            *p++ = c;
            break;
        }
    }

    *p = '\0';

    return pbuf;
}
#endif /* HAVE_GNUREADLINE || HAVE_BSDEDITLINE */

#ifndef X_DISPLAY_MISSING
#ifdef HAVE_GNUREADLINE
/* -------------------------------------------------------------------------- */
/* Process device events in Readline's hook since there is no where
   else to do it now - AV */
static int
app_event_func(void)
/* called by GNU readline periodically to know what to do about keypresses */
{
    static REQUEST reqst = { char_option, 0 };
    reqst.fp = rl_instream;
    X11_Input(&reqst, NULL);
    return 0;
}
#endif /* HAVE_GNUREADLINE */

#ifdef HAVE_BSDEDITLINE
/* -------------------------------------------------------------------------- */
/* Process device events in Editline's hook.
   similar to the readline function above but returns void */
static void
app_event_func(void)
/* called by GNU readline periodically to know what to do about keypresses */
{
    static REQUEST reqst = { char_option, 0 };
    reqst.fp = rl_instream;
    X11_Input(&reqst, NULL);
}
#endif /* HAVE_BSDEDITLINE */
#endif

/* -------------------------------------------------------------------------- */
/* This is the command processing loop for spice and nutmeg.
   The function is called even when GNU readline is unavailable, in which
   case it falls back to repeatable calling cp_evloop()
   SJB 26th April 2005 */


/* -------------------------------------------------------------------------- */
static void
show_help(void)
{
    printf("Usage: %s [OPTION]... [FILE]...\n"
           "Simulate the electical circuits in FILE.\n"
           "\n"
           "  -a  --autorun             run the loaded netlist\n"
           "  -b, --batch               process FILE in batch mode\n"
           "  -c, --circuitfile=FILE    set the circuitfile\n"
           "  -i, --interactive         run in interactive mode\n"
           "  -n, --no-spiceinit        don't load the local or user's config file\n"
           "  -o, --output=FILE         set the outputfile\n"
           "  -p, --pipe                run in I/O pipe mode\n"
           "  -q, --completion          activate command completion\n"
           "  -r, --rawfile=FILE        set the rawfile output\n"
           "      --soa-log=FILE        set the outputfile for SOA warnings\n"
           "  -s, --server              run spice as a server process\n"
           "  -t, --term=TERM           set the terminal type\n"
           "  -h, --help                display this help and exit\n"
           "  -v, --version             output version information and exit\n"
           "\n"
           "Report bugs to %s.\n", "ff", Bug_Addr);
}

/* -------------------------------------------------------------------------- */
static void
show_version(void)
{
    printf("%s compiled from %s revision %s\n"
           "Written originally by Berkeley University\n"
           "Currently maintained by the NGSpice Project\n\n"
           "Copyright (C) 1985-1996,"
           "  The Regents of the University of California\n"
           "Copyright (C) 1999-2011,"
           "  The NGSpice Project\n", "" , PACKAGE, VERSION);
}

#ifdef SIMULATOR
/* -------------------------------------------------------------------------- */
static void
append_to_stream(FILE *dest, FILE *source)
{
    char buf[BSIZE_SP];
    size_t n;

    while ((n = fread(buf, 1, BSIZE_SP, source)) > 0)
        fwrite(buf, n, 1, dest);
}
#endif /* SIMULATOR */

/* -------------------------------------------------------------------------- */
/* Read an initialisation file.
   dir    is the directory (use NULL or "" for current directory)
   name   is the initialisation file's name
   Return true on success
   SJB 25th April 2005 */
static bool
read_initialisation_file(char *dir, char *name)
{
    char *path;
    bool result = FALSE;

    /* check name */
    if (!name || *name == '\0')
        return FALSE;   /* Fail; name needed */

    /* contruct the full path */
    if (!dir || *dir == '\0') {
        path = name;
    } else {
        path = tprintf("%s" DIR_PATHSEP "%s", dir, name);
        if (!path)
            return FALSE;    /* memory allocation error */
    }

    /* now access the file */
#ifdef HAVE_UNISTD_H
    if (access(path, R_OK) == 0)
        result = TRUE;
#else
    {
        FILE *fp = fopen(path, "r");
        if (fp) {
            fclose(fp);
            result = TRUE;
        }
    }
#endif

    if (path != name)
        tfree(path);

    return result;
}

/* -------------------------------------------------------------------------- */

static void
print_news(void)
{
    fprintf(stderr, "foo\n");
}


#ifdef HAS_WINGUI
#define main xmain
#endif

int
main(int argc, char **argv)
{
    char log_file[BSIZE_SP];
    char soa_log_file[BSIZE_SP];
    volatile bool readinit = TRUE;
    volatile bool istty = TRUE;
    bool iflag = FALSE;
    bool qflag = FALSE;

    FILE * volatile circuit_file;
    bool oflag = FALSE;
    bool srflag = FALSE;

#if defined(HAVE_GNUREADLINE) || defined(HAVE_BSDEDITLINE)
    application_name = strrchr(argv[0], '/');
    if (application_name)
        application_name ++;
    else
        application_name = argv[0];
#endif

    ivars(argv[0]);

    {
        int rv = SIMinit();
        if (rv != OK) {
            ft_sperror(rv, "SIMinit");
            sp_shutdown(EXIT_BAD);
        }
    }

    srand((unsigned int) getpid());

    /* --- Process command line options --- */
    for (;;) {
        enum { soa_log = 1001, };

        static struct option long_options[] = {
            {"help",         no_argument,       NULL, 'h'},
            {"version",      no_argument,       NULL, 'v'},
            {"batch",        no_argument,       NULL, 'b'},
            {"autorun",      no_argument,       NULL, 'a'},
            {"circuitfile",  required_argument, NULL, 'c'},
            {"interactive",  no_argument,       NULL, 'i'},
            {"no-spiceinit", no_argument,       NULL, 'n'},
            {"output",       required_argument, NULL, 'o'},
            {"pipe",         no_argument,       NULL, 'p'},
            {"completion",   no_argument,       NULL, 'q'},
            {"rawfile",      required_argument, NULL, 'r'},
            {"server",       no_argument,       NULL, 's'},
            {"terminal",     required_argument, NULL, 't'},
            {"soa-log",      required_argument, NULL, soa_log},
            {NULL,           0,                 NULL, 0}
        };

        int option_index = 0;

        int c = getopt_long(argc, argv, "hvbac:ino:pqr:st:",
                            long_options, &option_index);

        if (c == -1)
            break;

        switch (c) {
        case 'h':       /* Help */
            show_help();
            sp_shutdown(EXIT_INFO);
            break;

        case 'v':       /* Version info */
            show_version();
            sp_shutdown(EXIT_INFO);
            break;

        case 'b':       /* Batch mode */
            ft_batchmode = TRUE;
            break;

        case 'a':       /* Add control section for autorun */
            break;

        case 'c':       /* Circuit file */
            if (optarg) {
                if ((circuit_file = fopen(optarg, "r")) == NULL) {
                    perror(optarg);
                    sp_shutdown(EXIT_BAD);
                }
                istty = FALSE;
            }
            break;

        case 'i':       /* Interactive mode */
            iflag = TRUE;
            break;

        case 'n':       /* Don't read initialisation file */
            readinit = FALSE;
            break;

        case 'o':       /* Output file */
            if (optarg) {
                /* switch to line buffering for stdout */
                setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
                sprintf(log_file, "%s", optarg);
                oflag = TRUE;
            }
            break;

        case 'p':       /* Run in pipe mode */
            iflag = TRUE;
            istty = TRUE;
            ft_pipemode = TRUE;
            /* switch to line buffering for stdout */
            setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
            break;

        case 'q':       /* Command completion */
            qflag = TRUE;
            break;

        case 'r':       /* The raw file */
            rflag = TRUE;
            break;

        case 's':       /* Server mode */
            ft_servermode = TRUE;
            break;

        case 't':
            break;

        case soa_log:
            if (optarg) {
                sprintf(soa_log_file, "%s", optarg);
                srflag = TRUE;
            }
            break;

        case '?':
            break;

        default:
            printf ("?? getopt returned character code 0%o ??\n", c);
        }
    }  /* --- End of command line option processing (While(1)-loop) --- */


    if (oflag) {   /* -o option has been set */

        if (ft_servermode)
            fprintf(stdout, "\nServer mode\n\n");
        else if (ft_batchmode)
            fprintf(stdout, "\nBatch mode\n\n");
        else
            fprintf(stdout, "\nInteractive mode, better used without -o option\n\n");

        if (rflag)
            fprintf(stdout, "Simulation output goes to rawfile: %s\n", ft_rawfile);

        fprintf(stdout, "Comments and warnings go to log-file: %s\n\n", log_file);

        /* Open the log file */
#ifdef HAS_WINGUI
        /* flogp used by winmain's putc which writes to file 'log_file' */
        flogp = fopen(log_file, "w");
        if (!flogp) {
            perror(log_file);
            sp_shutdown(EXIT_BAD);
        }
#else
        orflag = TRUE;
        /* Connect stdout and stderr to file log_file and log stdout */
        if (!freopen(log_file, "w", stdout)) {
            perror(log_file);
            sp_shutdown(EXIT_BAD);
        }
        dup2(fileno(stdout), fileno(stderr));
        setvbuf(stdout, NULL, _IOLBF, BUFSIZ); /* enable line buffering */
#endif
    } /* orflag */

    if (srflag) {   /* --soa-log option has been set */

        fprintf(stdout, "\nSOA warnings go to log-file: %s\n", soa_log_file);

        /* Open the soa log file */
        slogp = fopen(soa_log_file, "w");
        if (!slogp) {
            perror(soa_log_file);
            sp_shutdown(EXIT_BAD);
        }
    } /* srflag */

    if ((!iflag && !istty) || ft_servermode) /* (batch and file) or server operation */
        ft_batchmode = TRUE;

    if (ft_servermode)              /* in server no init file */
        readinit = FALSE;


    if (readinit) {
        /* load user's initialisation file
           try accessing the initialisation file in the current directory
           if that fails try the alternate name */
        if (FALSE == read_initialisation_file("", INITSTR)  &&
            FALSE == read_initialisation_file("", ALT_INITSTR)) {
            /* if that failed try in the user's home directory
               if their HOME environment variable is set */
            char *homedir = getenv("HOME");
            if (homedir)
                if (FALSE == read_initialisation_file(homedir, INITSTR)  &&
                    FALSE == read_initialisation_file(homedir, ALT_INITSTR)) {
                    ;
                }
        }
    }

    if (!ft_batchmode) {
        print_news();
    }



    /* Pass 2 -- get the filenames. If we are spice, then this means
     * build a circuit for this file. If this is in server mode, don't
     * process any of these args.  */


        if (!ft_servermode) {

            int err = 0;

            /* Concatenate all non-option arguments into a temporary file
               and load that file into the spice core.

               The original routine took a special path if there was only
               one non-option argument.  In that case, it didn't create
               the temporary file but used the original file instead.  The
               current algorithm is uniform at the expense of a little
               startup time.  */

            FILE *tempfile = tmpfile();

#if defined(HAS_WINGUI) || defined(_MSC_VER) || defined(__MINGW32__)
            char *dname = NULL;   /* input file*/
            char *tpf = NULL;     /* temporary file */

            /* tmpfile() returns NULL, if in MS Windows as non admin user
               in directory C:\something (no write permission to root C:).
               Then we add a tempfile in the local directory.
               File will be removed automatically due to TD option in fopen */

            if (tempfile == NULL) {
                tpf = smktemp("sp");
                tempfile = fopen(tpf, "w+bTD");
                if (tempfile == NULL) {
                    fprintf(stderr, "Could not open a temporary file to save and use optional arguments.");
                    sp_shutdown(EXIT_BAD);
                }
            }
#endif

            if (!tempfile) {
                perror("tmpfile()");
                sp_shutdown(EXIT_BAD);
            }

            if (optind == argc && !istty)
                append_to_stream(tempfile, stdin);

            while (optind < argc) {
                char *arg = argv[optind++];
                FILE *tp;
                /* Copy the the path of the first filename only */
                if (!Infile_Path)
                    Infile_Path = ngdirname(arg);

                /* Copy all the arguments into the temporary file */
                tp = fopen(arg, "r");
                if (!tp) {
                    char *lbuffer = getenv("NGSPICE_INPUT_DIR");
                    if (lbuffer && *lbuffer) {
                        char *p = tprintf("%s%s%s", lbuffer, DIR_PATHSEP, arg);
                        tp = fopen(p, "r");
                        tfree(p);
                    }
                    if (!tp) {
                        perror(arg);
                        err = 1;
                        break;
                    }
                }

#if defined(HAS_WINGUI) || defined(_MSC_VER) || defined(__MINGW32__)
                /* Copy the input file name which otherwise will be lost due to the
                   temporary file */
                dname = copy(arg);
#endif
#if defined(HAS_WINGUI)
                /* write source file name into source window */
                SetSource(dname);
#endif

                append_to_stream(tempfile, tp);
                fclose(tp);
            }

            fseek(tempfile, 0L, SEEK_SET);

            if (ft_batchmode && err)
                sp_shutdown(EXIT_BAD);

        }   /* ---  if (!ft_servermode) --- */



    return 0;
}
