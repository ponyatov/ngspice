/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1986 Wayne A. Christopher, U. C. Berkeley CAD Group
Modified: 1999 Paolo Nenzi - 2000 AlansFixes
**********/

/*
 * Definitions for all external symbols in FTE.
 */

#ifndef ngspice_FTEEXT_H
#define ngspice_FTEEXT_H

#include "ngspice/config.h"

/* needed to find out what the interface structures look like */
#include "ngspice/typedefs.h"

/* circuits.c */

extern struct circ *ft_curckt;


/* define.c */

extern struct pnode *ft_substdef(const char *name, struct pnode *args);
extern void ft_pnode(struct pnode *pn);

/* error.c */

extern void fperror(char *mess, int code);
extern void ft_sperror(int code, char *mess);
extern char ErrorMessage[];
extern void internalerror(char *); 
extern void externalerror(char *);
extern bool ft_pipemode;



/* evaluate.c */

extern struct dvec *ft_evaluate(struct pnode *node);

/* inp.c */

extern void inp_source(char *file);
void inp_spsource(FILE *fp, bool comfile, char *filename, bool intfile);
extern void inp_casefix(char *string);
extern struct line *inp_readall(FILE *fp, char *dir_name, bool comfile, bool intfile);
extern FILE *inp_pathopen(char *name, char *mode);

extern char** circarray;

/* nutinp.c */

void inp_nutsource(FILE *fp, bool comfile, char *filename);

/* numparse.c */

extern bool ft_strictnumparse;
double * ft_numparse(char **s, bool whole);

/* options.c */

extern bool ft_simdb;
extern bool ft_parsedb;
extern bool ft_evdb;
extern bool ft_vecdb;
extern bool ft_grdb;
extern bool ft_gidb;
extern bool ft_controldb;
extern bool ft_asyncdb;
extern char *ft_setkwords[];
extern struct line *inp_getopts(struct line *deck);
extern struct line *inp_getoptsc(char *in_line, struct line *com_options);
extern bool ft_ngdebug;
extern bool ft_stricterror;

/* rawfile.c */
extern int raw_prec;

/* resource.c */

extern void ft_ckspace(void);

/* runcoms.c */

extern int ft_dorun(char *file);


/* spice.c & nutmeg.c */

extern const bool ft_nutmeg;
extern IFsimulator *ft_sim;
extern char *ft_rawfile;
extern int main(int argc, char **argv);

/* spiceif.c & nutmegif.c */

extern bool if_tranparams(struct circ *ci, double *start, double *stop, double *step);
extern char *if_errstring(int code);
extern struct variable *(*if_getparam)(CKTcircuit *ckt, char** name, char* param, int ind, int do_model);
extern struct variable * nutif_getparam(CKTcircuit *ckt, char **name, char *param, int ind, int do_model);
extern struct variable *spif_getparam(CKTcircuit *ckt, char **name, char *param, int ind, int do_model);
extern struct variable *spif_getparam_special(CKTcircuit *ckt, char **name, char *param, int ind, int do_model);
extern void if_setndnames(char *line);
extern void if_setparam_model(CKTcircuit *ckt, char **name, char *val );
extern void if_setparam(CKTcircuit *ckt, char **name, char *param, struct dvec *val, int do_model);
extern struct variable *if_getstat(CKTcircuit *ckt, char *name);
extern int ft_find_analysis(char *name);
extern IFparm * ft_find_analysis_parm(int which, char *name);

/* typesdef.c */

extern char *ft_typabbrev(int);
extern char *ft_typenames(int);
extern char *ft_plotabbrev(char *);
extern int ft_typnum(char *);


/* main.c */
extern bool ft_intrpt;
extern bool ft_setflag;

/* error.c */

#endif
