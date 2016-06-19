/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "nbjt2def.h"
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
NBJT2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJT2model *model = (NBJT2model *)inModel ;
    NBJT2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the NBJT2 models */
    for ( ; model != NULL ; model = model->NBJT2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NBJT2instances ; here != NULL ; here = here->NBJT2nextInstance)
        {
            XFOO(NBJT2colColPtr, NBJT2colColBinding, NBJT2colNode, NBJT2colNode);
            XFOO(NBJT2colBasePtr, NBJT2colBaseBinding, NBJT2colNode, NBJT2baseNode);
            XFOO(NBJT2colEmitPtr, NBJT2colEmitBinding, NBJT2colNode, NBJT2emitNode);
            XFOO(NBJT2baseColPtr, NBJT2baseColBinding, NBJT2baseNode, NBJT2colNode);
            XFOO(NBJT2baseBasePtr, NBJT2baseBaseBinding, NBJT2baseNode, NBJT2baseNode);
            XFOO(NBJT2baseEmitPtr, NBJT2baseEmitBinding, NBJT2baseNode, NBJT2emitNode);
            XFOO(NBJT2emitColPtr, NBJT2emitColBinding, NBJT2emitNode, NBJT2colNode);
            XFOO(NBJT2emitBasePtr, NBJT2emitBaseBinding, NBJT2emitNode, NBJT2baseNode);
            XFOO(NBJT2emitEmitPtr, NBJT2emitEmitBinding, NBJT2emitNode, NBJT2emitNode);
        }
    }

    return (OK) ;
}

int
NBJT2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJT2model *model = (NBJT2model *)inModel ;
    NBJT2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NBJT2 models */
    for ( ; model != NULL ; model = model->NBJT2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NBJT2instances ; here != NULL ; here = here->NBJT2nextInstance)
        {
            BFOO(NBJT2colColPtr, NBJT2colColBinding, NBJT2colNode, NBJT2colNode);
            BFOO(NBJT2colBasePtr, NBJT2colBaseBinding, NBJT2colNode, NBJT2baseNode);
            BFOO(NBJT2colEmitPtr, NBJT2colEmitBinding, NBJT2colNode, NBJT2emitNode);
            BFOO(NBJT2baseColPtr, NBJT2baseColBinding, NBJT2baseNode, NBJT2colNode);
            BFOO(NBJT2baseBasePtr, NBJT2baseBaseBinding, NBJT2baseNode, NBJT2baseNode);
            BFOO(NBJT2baseEmitPtr, NBJT2baseEmitBinding, NBJT2baseNode, NBJT2emitNode);
            BFOO(NBJT2emitColPtr, NBJT2emitColBinding, NBJT2emitNode, NBJT2colNode);
            BFOO(NBJT2emitBasePtr, NBJT2emitBaseBinding, NBJT2emitNode, NBJT2baseNode);
            BFOO(NBJT2emitEmitPtr, NBJT2emitEmitBinding, NBJT2emitNode, NBJT2emitNode);
        }
    }

    return (OK) ;
}

int
NBJT2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJT2model *model = (NBJT2model *)inModel ;
    NBJT2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NBJT2 models */
    for ( ; model != NULL ; model = model->NBJT2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NBJT2instances ; here != NULL ; here = here->NBJT2nextInstance)
        {
            CFOO(NBJT2colColPtr, NBJT2colColBinding, NBJT2colNode, NBJT2colNode);
            CFOO(NBJT2colBasePtr, NBJT2colBaseBinding, NBJT2colNode, NBJT2baseNode);
            CFOO(NBJT2colEmitPtr, NBJT2colEmitBinding, NBJT2colNode, NBJT2emitNode);
            CFOO(NBJT2baseColPtr, NBJT2baseColBinding, NBJT2baseNode, NBJT2colNode);
            CFOO(NBJT2baseBasePtr, NBJT2baseBaseBinding, NBJT2baseNode, NBJT2baseNode);
            CFOO(NBJT2baseEmitPtr, NBJT2baseEmitBinding, NBJT2baseNode, NBJT2emitNode);
            CFOO(NBJT2emitColPtr, NBJT2emitColBinding, NBJT2emitNode, NBJT2colNode);
            CFOO(NBJT2emitBasePtr, NBJT2emitBaseBinding, NBJT2emitNode, NBJT2baseNode);
            CFOO(NBJT2emitEmitPtr, NBJT2emitEmitBinding, NBJT2emitNode, NBJT2emitNode);
        }
    }

    return (OK) ;
}
