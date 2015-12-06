/* This file is automatically generated. DO NOT EDIT! */

#ifndef _sf_alloc_h
#define _sf_alloc_h


#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


#if defined(_MSC_VER) && (_MSC_VER < 1800)
#define strdup _strdup
#define snprintf _snprintf
#endif
#include "_bool.h"


/*------------------------------------------------------------*/
/*@out@*/ void *sf_alloc (size_t n    /* number of elements */,
                          size_t size /* size of one element */);
/*< output-checking allocation >*/


/*------------------------------------------------------------*/
void *sf_realloc (void* ptr   /* previous data */,
                  size_t n    /* number of elements */,
                  size_t size /* size of one element */);
/*< output-checing reallocation >*/


/*------------------------------------------------------------*/
/*@out@*/ char *sf_charalloc (size_t n /* number of elements */);
/*< char allocation >*/


/*------------------------------------------------------------*/
/*@out@*/ unsigned char *sf_ucharalloc (size_t n /* number of elements */);
/*< unsigned char allocation >*/


/*------------------------------------------------------------*/
/*@out@*/ short *sf_shortalloc (size_t n /* number of elements */);
/*< short allocation >*/


/*------------------------------------------------------------*/
/*@out@*/ int *sf_intalloc (size_t n /* number of elements */);
/*< int allocation >*/


/*------------------------------------------------------------*/
/*@out@*/ off_t *sf_largeintalloc (size_t n /* number of elements */);
/*< sf_largeint allocation >*/


/*------------------------------------------------------------*/
/*@out@*/ float *sf_floatalloc (size_t n /* number of elements */);
/*< float allocation >*/

/*------------------------------------------------------------*/
/*@out@*/ double *sf_doublealloc (size_t n /* number of elements */);
/*< double allocation >*/


/*------------------------------------------------------------*/
/*@out@*/ bool *sf_boolalloc (size_t n /* number of elements */);
/*< bool allocation >*/


/*@out@*/ bool **sf_boolalloc2 (size_t n1 /* fast dimension */,
                                size_t n2 /* slow dimension */);
/*< bool 2-D allocation, out[0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ bool ***sf_boolalloc3 (size_t n1 /* fast dimension */,
                                  size_t n2 /* slower dimension */,
                                  size_t n3 /* slowest dimension */);
/*< bool 3-D allocation, out[0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ float **sf_floatalloc2 (size_t n1 /* fast dimension */,
                                  size_t n2 /* slow dimension */);
/*< float 2-D allocation, out[0] points to a contiguous array >*/

/*------------------------------------------------------------*/

/*@out@*/ double **sf_doublealloc2(size_t n1 /* fast dimension */,
    size_t n2 /* slow dimension */);
/*< float 2-D allocation, out[0] points to a contiguous array >*/

/*------------------------------------------------------------*/
/*@out@*/ float ***sf_floatalloc3 (size_t n1 /* fast dimension */,
                                   size_t n2 /* slower dimension */,
                                   size_t n3 /* slowest dimension */);
/*< float 3-D allocation, out[0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ float ****sf_floatalloc4 (size_t n1 /* fast dimension */,
                                    size_t n2 /* slower dimension */,
                                    size_t n3 /* slower dimension */,
                                    size_t n4 /* slowest dimension */);
/*< float 4-D allocation, out[0][0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ float *****sf_floatalloc5 (size_t n1 /* fast dimension */,
                                     size_t n2 /* slower dimension */,
                                     size_t n3 /* slower dimension */,
                                     size_t n4 /* slower dimension */,
                                     size_t n5 /* slowest dimension */);
/*< float 5-D allocation, out[0][0][0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ float ******sf_floatalloc6 (size_t n1 /* fast dimension */,
                                      size_t n2 /* slower dimension */,
                                      size_t n3 /* slower dimension */,
                                      size_t n4 /* slower dimension */,
                                      size_t n5 /* slower dimension */,
                                      size_t n6 /* slowest dimension */);
/*< float 6-D allocation, out[0][0][0][0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ int **sf_intalloc2 (size_t n1 /* fast dimension */,
                              size_t n2 /* slow dimension */);
/*< float 2-D allocation, out[0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ int ***sf_intalloc3 (size_t n1 /* fast dimension */,
                               size_t n2 /* slower dimension */,
                               size_t n3 /* slowest dimension */);
/*< int 3-D allocation, out[0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ int ****sf_intalloc4 (size_t n1 /* fast dimension */,
                               size_t n2 /* slower dimension */,
                               size_t n3 /* slower dimension */,
                               size_t n4 /* slowest dimension */ );
/*< int 4-D allocation, out[0][0][0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ char **sf_charalloc2 (size_t n1 /* fast dimension */,
                                size_t n2 /* slow dimension */);
/*< char 2-D allocation, out[0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ unsigned char **sf_ucharalloc2 (size_t n1 /* fast dimension */,
                                          size_t n2 /* slow dimension */);
/*< unsigned char 2-D allocation, out[0] points to a contiguous array >*/


/*------------------------------------------------------------*/
/*@out@*/ unsigned char ***sf_ucharalloc3 (size_t n1 /* fast dimension */,
                                           size_t n2 /* slower dimension */,
                                           size_t n3 /* slowest dimension */);
/*< unsigned char 3-D allocation, out[0][0] points to a contiguous array >*/

#endif
