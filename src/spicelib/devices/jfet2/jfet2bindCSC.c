/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "jfet2defs.h"
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
JFET2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    JFET2model *model = (JFET2model *)inModel ;
    JFET2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the JFET2 models */
    for ( ; model != NULL ; model = model->JFET2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->JFET2instances ; here != NULL ; here = here->JFET2nextInstance)
        {
            XFOO(JFET2drainDrainPrimePtr, JFET2drainDrainPrimeBinding, JFET2drainNode, JFET2drainPrimeNode);
            XFOO(JFET2gateDrainPrimePtr, JFET2gateDrainPrimeBinding, JFET2gateNode, JFET2drainPrimeNode);
            XFOO(JFET2gateSourcePrimePtr, JFET2gateSourcePrimeBinding, JFET2gateNode, JFET2sourcePrimeNode);
            XFOO(JFET2sourceSourcePrimePtr, JFET2sourceSourcePrimeBinding, JFET2sourceNode, JFET2sourcePrimeNode);
            XFOO(JFET2drainPrimeDrainPtr, JFET2drainPrimeDrainBinding, JFET2drainPrimeNode, JFET2drainNode);
            XFOO(JFET2drainPrimeGatePtr, JFET2drainPrimeGateBinding, JFET2drainPrimeNode, JFET2gateNode);
            XFOO(JFET2drainPrimeSourcePrimePtr, JFET2drainPrimeSourcePrimeBinding, JFET2drainPrimeNode, JFET2sourcePrimeNode);
            XFOO(JFET2sourcePrimeGatePtr, JFET2sourcePrimeGateBinding, JFET2sourcePrimeNode, JFET2gateNode);
            XFOO(JFET2sourcePrimeSourcePtr, JFET2sourcePrimeSourceBinding, JFET2sourcePrimeNode, JFET2sourceNode);
            XFOO(JFET2sourcePrimeDrainPrimePtr, JFET2sourcePrimeDrainPrimeBinding, JFET2sourcePrimeNode, JFET2drainPrimeNode);
            XFOO(JFET2drainDrainPtr, JFET2drainDrainBinding, JFET2drainNode, JFET2drainNode);
            XFOO(JFET2gateGatePtr, JFET2gateGateBinding, JFET2gateNode, JFET2gateNode);
            XFOO(JFET2sourceSourcePtr, JFET2sourceSourceBinding, JFET2sourceNode, JFET2sourceNode);
            XFOO(JFET2drainPrimeDrainPrimePtr, JFET2drainPrimeDrainPrimeBinding, JFET2drainPrimeNode, JFET2drainPrimeNode);
            XFOO(JFET2sourcePrimeSourcePrimePtr, JFET2sourcePrimeSourcePrimeBinding, JFET2sourcePrimeNode, JFET2sourcePrimeNode);
        }
    }

    return (OK) ;
}

int
JFET2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    JFET2model *model = (JFET2model *)inModel ;
    JFET2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the JFET2 models */
    for ( ; model != NULL ; model = model->JFET2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->JFET2instances ; here != NULL ; here = here->JFET2nextInstance)
        {
            BFOO(JFET2drainDrainPrimePtr, JFET2drainDrainPrimeBinding, JFET2drainNode, JFET2drainPrimeNode);
            BFOO(JFET2gateDrainPrimePtr, JFET2gateDrainPrimeBinding, JFET2gateNode, JFET2drainPrimeNode);
            BFOO(JFET2gateSourcePrimePtr, JFET2gateSourcePrimeBinding, JFET2gateNode, JFET2sourcePrimeNode);
            BFOO(JFET2sourceSourcePrimePtr, JFET2sourceSourcePrimeBinding, JFET2sourceNode, JFET2sourcePrimeNode);
            BFOO(JFET2drainPrimeDrainPtr, JFET2drainPrimeDrainBinding, JFET2drainPrimeNode, JFET2drainNode);
            BFOO(JFET2drainPrimeGatePtr, JFET2drainPrimeGateBinding, JFET2drainPrimeNode, JFET2gateNode);
            BFOO(JFET2drainPrimeSourcePrimePtr, JFET2drainPrimeSourcePrimeBinding, JFET2drainPrimeNode, JFET2sourcePrimeNode);
            BFOO(JFET2sourcePrimeGatePtr, JFET2sourcePrimeGateBinding, JFET2sourcePrimeNode, JFET2gateNode);
            BFOO(JFET2sourcePrimeSourcePtr, JFET2sourcePrimeSourceBinding, JFET2sourcePrimeNode, JFET2sourceNode);
            BFOO(JFET2sourcePrimeDrainPrimePtr, JFET2sourcePrimeDrainPrimeBinding, JFET2sourcePrimeNode, JFET2drainPrimeNode);
            BFOO(JFET2drainDrainPtr, JFET2drainDrainBinding, JFET2drainNode, JFET2drainNode);
            BFOO(JFET2gateGatePtr, JFET2gateGateBinding, JFET2gateNode, JFET2gateNode);
            BFOO(JFET2sourceSourcePtr, JFET2sourceSourceBinding, JFET2sourceNode, JFET2sourceNode);
            BFOO(JFET2drainPrimeDrainPrimePtr, JFET2drainPrimeDrainPrimeBinding, JFET2drainPrimeNode, JFET2drainPrimeNode);
            BFOO(JFET2sourcePrimeSourcePrimePtr, JFET2sourcePrimeSourcePrimeBinding, JFET2sourcePrimeNode, JFET2sourcePrimeNode);
        }
    }

    return (OK) ;
}

int
JFET2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    JFET2model *model = (JFET2model *)inModel ;
    JFET2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the JFET2 models */
    for ( ; model != NULL ; model = model->JFET2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->JFET2instances ; here != NULL ; here = here->JFET2nextInstance)
        {
            CFOO(JFET2drainDrainPrimePtr, JFET2drainDrainPrimeBinding, JFET2drainNode, JFET2drainPrimeNode);
            CFOO(JFET2gateDrainPrimePtr, JFET2gateDrainPrimeBinding, JFET2gateNode, JFET2drainPrimeNode);
            CFOO(JFET2gateSourcePrimePtr, JFET2gateSourcePrimeBinding, JFET2gateNode, JFET2sourcePrimeNode);
            CFOO(JFET2sourceSourcePrimePtr, JFET2sourceSourcePrimeBinding, JFET2sourceNode, JFET2sourcePrimeNode);
            CFOO(JFET2drainPrimeDrainPtr, JFET2drainPrimeDrainBinding, JFET2drainPrimeNode, JFET2drainNode);
            CFOO(JFET2drainPrimeGatePtr, JFET2drainPrimeGateBinding, JFET2drainPrimeNode, JFET2gateNode);
            CFOO(JFET2drainPrimeSourcePrimePtr, JFET2drainPrimeSourcePrimeBinding, JFET2drainPrimeNode, JFET2sourcePrimeNode);
            CFOO(JFET2sourcePrimeGatePtr, JFET2sourcePrimeGateBinding, JFET2sourcePrimeNode, JFET2gateNode);
            CFOO(JFET2sourcePrimeSourcePtr, JFET2sourcePrimeSourceBinding, JFET2sourcePrimeNode, JFET2sourceNode);
            CFOO(JFET2sourcePrimeDrainPrimePtr, JFET2sourcePrimeDrainPrimeBinding, JFET2sourcePrimeNode, JFET2drainPrimeNode);
            CFOO(JFET2drainDrainPtr, JFET2drainDrainBinding, JFET2drainNode, JFET2drainNode);
            CFOO(JFET2gateGatePtr, JFET2gateGateBinding, JFET2gateNode, JFET2gateNode);
            CFOO(JFET2sourceSourcePtr, JFET2sourceSourceBinding, JFET2sourceNode, JFET2sourceNode);
            CFOO(JFET2drainPrimeDrainPrimePtr, JFET2drainPrimeDrainPrimeBinding, JFET2drainPrimeNode, JFET2drainPrimeNode);
            CFOO(JFET2sourcePrimeSourcePrimePtr, JFET2sourcePrimeSourcePrimeBinding, JFET2sourcePrimeNode, JFET2sourcePrimeNode);
        }
    }

    return (OK) ;
}
