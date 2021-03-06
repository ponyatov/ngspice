#ifndef ngspice_RANDNUMB_H
#define ngspice_RANDNUMB_H

/* initialize random number generators */
extern void initw(void);

extern void checkseed(void);    /* seed random or set by 'set rndseed=value'*/
extern double drand(void);
extern double gauss0(void);
extern int poisson(double);
extern double exprand(double);

extern void TausSeed(void);
extern unsigned int CombLCGTausInt(void);
extern unsigned int CombLCGTausInt2(void);

#endif
