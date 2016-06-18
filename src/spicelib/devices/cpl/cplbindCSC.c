/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "cpldefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

#include <stdlib.h>


static
int
BindCompare (const void *a, const void *b)
{
    BindElement *A, *B ;
    A = (BindElement *)a ;
    B = (BindElement *)b ;

    return ((int)(A->Sparse - B->Sparse)) ;
}

int
CPLbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CPLmodel *model = (CPLmodel *)inModel ;
    CPLinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;
    int m, p ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the CPL models */
    for ( ; model != NULL ; model = model->CPLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CPLinstances ; here != NULL ; here = here->CPLnextInstance)
        {
            for (m = 0; m < here->dimension; m++) {
                XFOO(CPLibr1Ibr1Ptr[m], CPLibr1Ibr1Binding[m], CPLibr1[m], CPLibr1[m]);
                XFOO(CPLibr2Ibr2Ptr[m], CPLibr2Ibr2Binding[m], CPLibr2[m], CPLibr2[m]);
                XFOO(CPLposIbr1Ptr[m], CPLposIbr1Binding[m], CPLposNodes[m], CPLibr1[m]);
                XFOO(CPLnegIbr2Ptr[m], CPLnegIbr2Binding[m], CPLnegNodes[m], CPLibr2[m]);
                XFOO(CPLposPosPtr[m], CPLposPosBinding[m], CPLposNodes[m], CPLposNodes[m]);
                XFOO(CPLnegNegPtr[m], CPLnegNegBinding[m], CPLnegNodes[m], CPLnegNodes[m]);
                XFOO(CPLnegPosPtr[m], CPLnegPosBinding[m], CPLnegNodes[m], CPLposNodes[m]);
                XFOO(CPLposNegPtr[m], CPLposNegBinding[m], CPLposNodes[m], CPLnegNodes[m]);

                for (p = 0; p < here->dimension; p++) {
                    XFOO(CPLibr1PosPtr[m][p], CPLibr1PosBinding[m][p], CPLibr1[m], CPLposNodes[p]);
                    XFOO(CPLibr2NegPtr[m][p], CPLibr2NegBinding[m][p], CPLibr2[m], CPLnegNodes[p]);
                    XFOO(CPLibr1NegPtr[m][p], CPLibr1NegBinding[m][p], CPLibr1[m], CPLnegNodes[p]);
                    XFOO(CPLibr2PosPtr[m][p], CPLibr2PosBinding[m][p], CPLibr2[m], CPLposNodes[p]);
                    XFOO(CPLibr1Ibr2Ptr[m][p], CPLibr1Ibr2Binding[m][p], CPLibr1[m], CPLibr2[p]);
                    XFOO(CPLibr2Ibr1Ptr[m][p], CPLibr2Ibr1Binding[m][p], CPLibr2[m], CPLibr1[p]);
                }
            }
        }
    }

    return (OK) ;
}

int
CPLbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CPLmodel *model = (CPLmodel *)inModel ;
    CPLinstance *here ;
    int m, p;

    NG_IGNORE (ckt) ;

    /* loop through all the CPL models */
    for ( ; model != NULL ; model = model->CPLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CPLinstances ; here != NULL ; here = here->CPLnextInstance)
        {
            for (m = 0; m < here->dimension; m++) {
                BFOO(CPLibr1Ibr1Ptr[m], CPLibr1Ibr1Binding[m], CPLibr1[m], CPLibr1[m]);
                BFOO(CPLibr2Ibr2Ptr[m], CPLibr2Ibr2Binding[m], CPLibr2[m], CPLibr2[m]);
                BFOO(CPLposIbr1Ptr[m], CPLposIbr1Binding[m], CPLposNodes[m], CPLibr1[m]);
                BFOO(CPLnegIbr2Ptr[m], CPLnegIbr2Binding[m], CPLnegNodes[m], CPLibr2[m]);
                BFOO(CPLposPosPtr[m], CPLposPosBinding[m], CPLposNodes[m], CPLposNodes[m]);
                BFOO(CPLnegNegPtr[m], CPLnegNegBinding[m], CPLnegNodes[m], CPLnegNodes[m]);
                BFOO(CPLnegPosPtr[m], CPLnegPosBinding[m], CPLnegNodes[m], CPLposNodes[m]);
                BFOO(CPLposNegPtr[m], CPLposNegBinding[m], CPLposNodes[m], CPLnegNodes[m]);

                for (p = 0; p < here->dimension; p++) {
                    BFOO(CPLibr1PosPtr[m][p], CPLibr1PosBinding[m][p], CPLibr1[m], CPLposNodes[p]);
                    BFOO(CPLibr2NegPtr[m][p], CPLibr2NegBinding[m][p], CPLibr2[m], CPLnegNodes[p]);
                    BFOO(CPLibr1NegPtr[m][p], CPLibr1NegBinding[m][p], CPLibr1[m], CPLnegNodes[p]);
                    BFOO(CPLibr2PosPtr[m][p], CPLibr2PosBinding[m][p], CPLibr2[m], CPLposNodes[p]);
                    BFOO(CPLibr1Ibr2Ptr[m][p], CPLibr1Ibr2Binding[m][p], CPLibr1[m], CPLibr2[p]);
                    BFOO(CPLibr2Ibr1Ptr[m][p], CPLibr2Ibr1Binding[m][p], CPLibr2[m], CPLibr1[p]);
                }
            }
        }
    }

    return (OK) ;
}

int
CPLbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CPLmodel *model = (CPLmodel *)inModel ;
    CPLinstance *here ;
    int m, p;

    NG_IGNORE (ckt) ;

    /* loop through all the CPL models */
    for ( ; model != NULL ; model = model->CPLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CPLinstances ; here != NULL ; here = here->CPLnextInstance)
        {
            for (m = 0; m < here->dimension; m++) {
                CFOO(CPLibr1Ibr1Ptr[m], CPLibr1Ibr1Binding[m], CPLibr1[m], CPLibr1[m]);
                CFOO(CPLibr2Ibr2Ptr[m], CPLibr2Ibr2Binding[m], CPLibr2[m], CPLibr2[m]);
                CFOO(CPLposIbr1Ptr[m], CPLposIbr1Binding[m], CPLposNodes[m], CPLibr1[m]);
                CFOO(CPLnegIbr2Ptr[m], CPLnegIbr2Binding[m], CPLnegNodes[m], CPLibr2[m]);
                CFOO(CPLposPosPtr[m], CPLposPosBinding[m], CPLposNodes[m], CPLposNodes[m]);
                CFOO(CPLnegNegPtr[m], CPLnegNegBinding[m], CPLnegNodes[m], CPLnegNodes[m]);
                CFOO(CPLnegPosPtr[m], CPLnegPosBinding[m], CPLnegNodes[m], CPLposNodes[m]);
                CFOO(CPLposNegPtr[m], CPLposNegBinding[m], CPLposNodes[m], CPLnegNodes[m]);

                for (p = 0; p < here->dimension; p++) {
                    CFOO(CPLibr1PosPtr[m][p], CPLibr1PosBinding[m][p], CPLibr1[m], CPLposNodes[p]);
                    CFOO(CPLibr2NegPtr[m][p], CPLibr2NegBinding[m][p], CPLibr2[m], CPLnegNodes[p]);
                    CFOO(CPLibr1NegPtr[m][p], CPLibr1NegBinding[m][p], CPLibr1[m], CPLnegNodes[p]);
                    CFOO(CPLibr2PosPtr[m][p], CPLibr2PosBinding[m][p], CPLibr2[m], CPLposNodes[p]);
                    CFOO(CPLibr1Ibr2Ptr[m][p], CPLibr1Ibr2Binding[m][p], CPLibr1[m], CPLibr2[p]);
                    CFOO(CPLibr2Ibr1Ptr[m][p], CPLibr2Ibr1Binding[m][p], CPLibr2[m], CPLibr1[p]);
                }
            }
        }
    }

    return (OK) ;
}
