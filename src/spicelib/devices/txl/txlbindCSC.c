/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "txldefs.h"
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
TXLbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    TXLmodel *model = (TXLmodel *)inModel ;
    TXLinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the TXL models */
    for ( ; model != NULL ; model = model->TXLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TXLinstances ; here != NULL ; here = here->TXLnextInstance)
        {
            XFOO(TXLposPosPtr, TXLposPosBinding, TXLposNode, TXLposNode);
            XFOO(TXLposNegPtr, TXLposNegBinding, TXLposNode, TXLnegNode);
            XFOO(TXLnegPosPtr, TXLnegPosBinding, TXLnegNode, TXLposNode);
            XFOO(TXLnegNegPtr, TXLnegNegBinding, TXLnegNode, TXLnegNode);
            XFOO(TXLibr1PosPtr, TXLibr1PosBinding, TXLibr1, TXLposNode);
            XFOO(TXLibr2NegPtr, TXLibr2NegBinding, TXLibr2, TXLnegNode);
            XFOO(TXLnegIbr2Ptr, TXLnegIbr2Binding, TXLnegNode, TXLibr2);
            XFOO(TXLposIbr1Ptr, TXLposIbr1Binding, TXLposNode, TXLibr1);
            XFOO(TXLibr1Ibr1Ptr, TXLibr1Ibr1Binding, TXLibr1, TXLibr1);
            XFOO(TXLibr2Ibr2Ptr, TXLibr2Ibr2Binding, TXLibr2, TXLibr2);
            XFOO(TXLibr1NegPtr, TXLibr1NegBinding, TXLibr1, TXLnegNode);
            XFOO(TXLibr2PosPtr, TXLibr2PosBinding, TXLibr2, TXLposNode);
            XFOO(TXLibr1Ibr2Ptr, TXLibr1Ibr2Binding, TXLibr1, TXLibr2);
            XFOO(TXLibr2Ibr1Ptr, TXLibr2Ibr1Binding, TXLibr2, TXLibr1);
        }
    }

    return (OK) ;
}

int
TXLbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    TXLmodel *model = (TXLmodel *)inModel ;
    TXLinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the TXL models */
    for ( ; model != NULL ; model = model->TXLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TXLinstances ; here != NULL ; here = here->TXLnextInstance)
        {
            BFOO(TXLposPosPtr, TXLposPosBinding, TXLposNode, TXLposNode);
            BFOO(TXLposNegPtr, TXLposNegBinding, TXLposNode, TXLnegNode);
            BFOO(TXLnegPosPtr, TXLnegPosBinding, TXLnegNode, TXLposNode);
            BFOO(TXLnegNegPtr, TXLnegNegBinding, TXLnegNode, TXLnegNode);
            BFOO(TXLibr1PosPtr, TXLibr1PosBinding, TXLibr1, TXLposNode);
            BFOO(TXLibr2NegPtr, TXLibr2NegBinding, TXLibr2, TXLnegNode);
            BFOO(TXLnegIbr2Ptr, TXLnegIbr2Binding, TXLnegNode, TXLibr2);
            BFOO(TXLposIbr1Ptr, TXLposIbr1Binding, TXLposNode, TXLibr1);
            BFOO(TXLibr1Ibr1Ptr, TXLibr1Ibr1Binding, TXLibr1, TXLibr1);
            BFOO(TXLibr2Ibr2Ptr, TXLibr2Ibr2Binding, TXLibr2, TXLibr2);
            BFOO(TXLibr1NegPtr, TXLibr1NegBinding, TXLibr1, TXLnegNode);
            BFOO(TXLibr2PosPtr, TXLibr2PosBinding, TXLibr2, TXLposNode);
            BFOO(TXLibr1Ibr2Ptr, TXLibr1Ibr2Binding, TXLibr1, TXLibr2);
            BFOO(TXLibr2Ibr1Ptr, TXLibr2Ibr1Binding, TXLibr2, TXLibr1);
        }
    }

    return (OK) ;
}

int
TXLbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    TXLmodel *model = (TXLmodel *)inModel ;
    TXLinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the TXL models */
    for ( ; model != NULL ; model = model->TXLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TXLinstances ; here != NULL ; here = here->TXLnextInstance)
        {
            CFOO(TXLposPosPtr, TXLposPosBinding, TXLposNode, TXLposNode);
            CFOO(TXLposNegPtr, TXLposNegBinding, TXLposNode, TXLnegNode);
            CFOO(TXLnegPosPtr, TXLnegPosBinding, TXLnegNode, TXLposNode);
            CFOO(TXLnegNegPtr, TXLnegNegBinding, TXLnegNode, TXLnegNode);
            CFOO(TXLibr1PosPtr, TXLibr1PosBinding, TXLibr1, TXLposNode);
            CFOO(TXLibr2NegPtr, TXLibr2NegBinding, TXLibr2, TXLnegNode);
            CFOO(TXLnegIbr2Ptr, TXLnegIbr2Binding, TXLnegNode, TXLibr2);
            CFOO(TXLposIbr1Ptr, TXLposIbr1Binding, TXLposNode, TXLibr1);
            CFOO(TXLibr1Ibr1Ptr, TXLibr1Ibr1Binding, TXLibr1, TXLibr1);
            CFOO(TXLibr2Ibr2Ptr, TXLibr2Ibr2Binding, TXLibr2, TXLibr2);
            CFOO(TXLibr1NegPtr, TXLibr1NegBinding, TXLibr1, TXLnegNode);
            CFOO(TXLibr2PosPtr, TXLibr2PosBinding, TXLibr2, TXLposNode);
            CFOO(TXLibr1Ibr2Ptr, TXLibr1Ibr2Binding, TXLibr1, TXLibr2);
            CFOO(TXLibr2Ibr1Ptr, TXLibr2Ibr1Binding, TXLibr2, TXLibr1);
        }
    }

    return (OK) ;
}
