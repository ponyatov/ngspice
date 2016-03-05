#ifndef _sf_defs_h
#define _sf_defs_h

#include <float.h>

#define SF_MAX(a,b) ((a) < (b) ? (b) : (a))
#define SF_MIN(a,b) ((a) < (b) ? (a) : (b))

#if defined(_MSC_VER) && (_MSC_VER < 1800)
#define strdup _strdup
#define snprintf _snprintf
#endif

#include <stdio.h>

#endif
