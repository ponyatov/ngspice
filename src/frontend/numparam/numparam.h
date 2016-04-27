/*
 * numparam.h
 */

/*** interface to spice frontend  subckt.c ***/

#include "numpaif.h"
#include "ngspice/hash.h"

/***** numparam internals ********/

typedef enum {Nodekey = '#'} _nNodekey;  /* Introduces node symbol */
typedef enum {Intro   = '&'} _nIntro;    /* Introduces preprocessor tokens */
typedef enum {Comment = '*'} _nComment;  /* Spice Comment lines */
typedef enum {Psp     = '{'} _nPsp;      /* Ps expression */


/* -----------------------------------------------------------------
 * I believe the entry_t should be a union of type but I need more info.
 * ----------------------------------------------------------------- */

typedef struct {                /* used as a type-checked enum */
} *nupa_type;

#define NUPA_REAL     ((nupa_type) 1)
#define NUPA_STRING   ((nupa_type) 2)
#define NUPA_UNKNOWN  ((nupa_type) 3)
#define NUPA_SUBCKT   ((nupa_type) 4)
#define NUPA_MODEL    ((nupa_type) 5)

typedef struct entry_s {
    nupa_type tp;      /* type: I)nt R)eal S)tring F)unction M)acro P)ointer */
    char *symbol;
    int  level;                 /* subckt nesting level */
    double vl;                  /* float value if defined */
    int  ivl;                   /* int value or string buffer index */
    char *sbbase;               /* string buffer base address if any */
    struct entry_s *pointer;    /* pointer chain */
} entry_t;


typedef struct {                /* the input scanner data structure */
    SPICE_DSTRING srcfile;      /* last piece of source file name */
    SPICE_DSTRING option;       /* one-character translator options */
    SPICE_DSTRING lookup_buf;   /* useful temp buffer for quick symbol lookup */
    int srcline;
    int oldline;
    int errcount;
    int max_stack_depth;        /* alloced maximum depth of the symbol stack */
    int stack_depth;            /* current depth of the symbol stack */
    NGHASHPTR *symbols;         /* stack of scopes for symbol lookup */
                                /*  [0] denotes global scope */
    NGHASHPTR inst_symbols;     /* instance qualified symbols - after a pop */
    char **inst_name;           /* name of subcircuit */
    char **dynrefptr;
    char *dyncategory;
    int hs_compatibility;       /* allow extra keywords */
} dico_t;


void initdico(dico_t *);
int donedico(dico_t *);
void dico_free_entry(entry_t *);
bool defsubckt(dico_t *, char *s, int w, nupa_type categ);
int findsubckt(dico_t *, char *s, SPICE_DSTRINGPTR subname);
bool nupa_substitute(dico_t *, char *s, char *r, bool err);
bool nupa_assignment(dico_t *, char *s, char mode);
bool nupa_subcktcall(dico_t *, char *s, char *x, bool err);
void nupa_subcktexit(dico_t *);
dico_t *nupa_fetchinstance(void);
nupa_type getidtype(dico_t *, char *s);
entry_t *attrib(dico_t *, NGHASHPTR htable, char *t, char op);
void del_attrib(void *);
