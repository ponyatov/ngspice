/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "hfet2defs.h"
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
HFET2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    HFET2model *model = (HFET2model *)inModel ;
    HFET2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the HFET2 models */
    for ( ; model != NULL ; model = model->HFET2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HFET2instances ; here != NULL ; here = here->HFET2nextInstance)
        {
            XFOO(HFET2drainDrainPrimePtr, HFET2drainDrainPrimeBinding, HFET2drainNode, HFET2drainPrimeNode);
            XFOO(HFET2gateDrainPrimePtr, HFET2gateDrainPrimeBinding, HFET2gateNode, HFET2drainPrimeNode);
            XFOO(HFET2gateSourcePrimePtr, HFET2gateSourcePrimeBinding, HFET2gateNode, HFET2sourcePrimeNode);
            XFOO(HFET2sourceSourcePrimePtr, HFET2sourceSourcePrimeBinding, HFET2sourceNode, HFET2sourcePrimeNode);
            XFOO(HFET2drainPrimeDrainPtr, HFET2drainPrimeDrainBinding, HFET2drainPrimeNode, HFET2drainNode);
            XFOO(HFET2drainPrimeGatePtr, HFET2drainPrimeGateBinding, HFET2drainPrimeNode, HFET2gateNode);
            XFOO(HFET2drainPriHFET2ourcePrimePtr, HFET2drainPriHFET2ourcePrimeBinding, HFET2drainPrimeNode, HFET2sourcePrimeNode);
            XFOO(HFET2sourcePrimeGatePtr, HFET2sourcePrimeGateBinding, HFET2sourcePrimeNode, HFET2gateNode);
            XFOO(HFET2sourcePriHFET2ourcePtr, HFET2sourcePriHFET2ourceBinding, HFET2sourcePrimeNode, HFET2sourceNode);
            XFOO(HFET2sourcePrimeDrainPrimePtr, HFET2sourcePrimeDrainPrimeBinding, HFET2sourcePrimeNode, HFET2drainPrimeNode);
            XFOO(HFET2drainDrainPtr, HFET2drainDrainBinding, HFET2drainNode, HFET2drainNode);
            XFOO(HFET2gateGatePtr, HFET2gateGateBinding, HFET2gateNode, HFET2gateNode);
            XFOO(HFET2sourceSourcePtr, HFET2sourceSourceBinding, HFET2sourceNode, HFET2sourceNode);
            XFOO(HFET2drainPrimeDrainPrimePtr, HFET2drainPrimeDrainPrimeBinding, HFET2drainPrimeNode, HFET2drainPrimeNode);
            XFOO(HFET2sourcePriHFET2ourcePrimePtr, HFET2sourcePriHFET2ourcePrimeBinding, HFET2sourcePrimeNode, HFET2sourcePrimeNode);
        }
    }

    return (OK) ;
}

int
HFET2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    HFET2model *model = (HFET2model *)inModel ;
    HFET2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HFET2 models */
    for ( ; model != NULL ; model = model->HFET2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HFET2instances ; here != NULL ; here = here->HFET2nextInstance)
        {
            BFOO(HFET2drainDrainPrimePtr, HFET2drainDrainPrimeBinding, HFET2drainNode, HFET2drainPrimeNode);
            BFOO(HFET2gateDrainPrimePtr, HFET2gateDrainPrimeBinding, HFET2gateNode, HFET2drainPrimeNode);
            BFOO(HFET2gateSourcePrimePtr, HFET2gateSourcePrimeBinding, HFET2gateNode, HFET2sourcePrimeNode);
            BFOO(HFET2sourceSourcePrimePtr, HFET2sourceSourcePrimeBinding, HFET2sourceNode, HFET2sourcePrimeNode);
            BFOO(HFET2drainPrimeDrainPtr, HFET2drainPrimeDrainBinding, HFET2drainPrimeNode, HFET2drainNode);
            BFOO(HFET2drainPrimeGatePtr, HFET2drainPrimeGateBinding, HFET2drainPrimeNode, HFET2gateNode);
            BFOO(HFET2drainPriHFET2ourcePrimePtr, HFET2drainPriHFET2ourcePrimeBinding, HFET2drainPrimeNode, HFET2sourcePrimeNode);
            BFOO(HFET2sourcePrimeGatePtr, HFET2sourcePrimeGateBinding, HFET2sourcePrimeNode, HFET2gateNode);
            BFOO(HFET2sourcePriHFET2ourcePtr, HFET2sourcePriHFET2ourceBinding, HFET2sourcePrimeNode, HFET2sourceNode);
            BFOO(HFET2sourcePrimeDrainPrimePtr, HFET2sourcePrimeDrainPrimeBinding, HFET2sourcePrimeNode, HFET2drainPrimeNode);
            BFOO(HFET2drainDrainPtr, HFET2drainDrainBinding, HFET2drainNode, HFET2drainNode);
            BFOO(HFET2gateGatePtr, HFET2gateGateBinding, HFET2gateNode, HFET2gateNode);
            BFOO(HFET2sourceSourcePtr, HFET2sourceSourceBinding, HFET2sourceNode, HFET2sourceNode);
            BFOO(HFET2drainPrimeDrainPrimePtr, HFET2drainPrimeDrainPrimeBinding, HFET2drainPrimeNode, HFET2drainPrimeNode);
            BFOO(HFET2sourcePriHFET2ourcePrimePtr, HFET2sourcePriHFET2ourcePrimeBinding, HFET2sourcePrimeNode, HFET2sourcePrimeNode);
        }
    }

    return (OK) ;
}

int
HFET2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    HFET2model *model = (HFET2model *)inModel ;
    HFET2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HFET2 models */
    for ( ; model != NULL ; model = model->HFET2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HFET2instances ; here != NULL ; here = here->HFET2nextInstance)
        {
            CFOO(HFET2drainDrainPrimePtr, HFET2drainDrainPrimeBinding, HFET2drainNode, HFET2drainPrimeNode);
            CFOO(HFET2gateDrainPrimePtr, HFET2gateDrainPrimeBinding, HFET2gateNode, HFET2drainPrimeNode);
            CFOO(HFET2gateSourcePrimePtr, HFET2gateSourcePrimeBinding, HFET2gateNode, HFET2sourcePrimeNode);
            CFOO(HFET2sourceSourcePrimePtr, HFET2sourceSourcePrimeBinding, HFET2sourceNode, HFET2sourcePrimeNode);
            CFOO(HFET2drainPrimeDrainPtr, HFET2drainPrimeDrainBinding, HFET2drainPrimeNode, HFET2drainNode);
            CFOO(HFET2drainPrimeGatePtr, HFET2drainPrimeGateBinding, HFET2drainPrimeNode, HFET2gateNode);
            CFOO(HFET2drainPriHFET2ourcePrimePtr, HFET2drainPriHFET2ourcePrimeBinding, HFET2drainPrimeNode, HFET2sourcePrimeNode);
            CFOO(HFET2sourcePrimeGatePtr, HFET2sourcePrimeGateBinding, HFET2sourcePrimeNode, HFET2gateNode);
            CFOO(HFET2sourcePriHFET2ourcePtr, HFET2sourcePriHFET2ourceBinding, HFET2sourcePrimeNode, HFET2sourceNode);
            CFOO(HFET2sourcePrimeDrainPrimePtr, HFET2sourcePrimeDrainPrimeBinding, HFET2sourcePrimeNode, HFET2drainPrimeNode);
            CFOO(HFET2drainDrainPtr, HFET2drainDrainBinding, HFET2drainNode, HFET2drainNode);
            CFOO(HFET2gateGatePtr, HFET2gateGateBinding, HFET2gateNode, HFET2gateNode);
            CFOO(HFET2sourceSourcePtr, HFET2sourceSourceBinding, HFET2sourceNode, HFET2sourceNode);
            CFOO(HFET2drainPrimeDrainPrimePtr, HFET2drainPrimeDrainPrimeBinding, HFET2drainPrimeNode, HFET2drainPrimeNode);
            CFOO(HFET2sourcePriHFET2ourcePrimePtr, HFET2sourcePriHFET2ourcePrimeBinding, HFET2sourcePrimeNode, HFET2sourcePrimeNode);
        }
    }

    return (OK) ;
}
