#ifndef ngspice_RANDNUMB_H
#define ngspice_RANDNUMB_H

#include "ngspice/wordlist.h"
extern void com_sseed(wordlist *wl);
extern void setseedinfo(void);

/* initialize random number generators */
extern void initw(void);

extern void checkseed(void); /* seed random or set by 'set rndseed=value'*/
extern double drand(void);  /* from randnumb.c */
extern double gauss0(void);  /* from randnumb.c */
extern double gauss1(void);  /* from randnumb.c */
extern int poisson(double);  /* from randnumb.c */
extern double exprand(double);  /* from randnumb.c */

extern unsigned int CombLCGTausInt(void);
extern void TausSeed(void);
extern unsigned int CombLCGTausInt2(void);

#endif
