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
            if ((here->HFET2drainNode != 0) && (here->HFET2drainPrimeNode != 0))
            {
                i = here->HFET2drainDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2drainDrainPrimeBinding = matched ;
                here->HFET2drainDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFET2gateNode != 0) && (here->HFET2drainPrimeNode != 0))
            {
                i = here->HFET2gateDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2gateDrainPrimeBinding = matched ;
                here->HFET2gateDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFET2gateNode != 0) && (here->HFET2sourcePrimeNode != 0))
            {
                i = here->HFET2gateSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2gateSourcePrimeBinding = matched ;
                here->HFET2gateSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFET2sourceNode != 0) && (here->HFET2sourcePrimeNode != 0))
            {
                i = here->HFET2sourceSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2sourceSourcePrimeBinding = matched ;
                here->HFET2sourceSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2drainNode != 0))
            {
                i = here->HFET2drainPrimeDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2drainPrimeDrainBinding = matched ;
                here->HFET2drainPrimeDrainPtr = matched->CSC ;
            }

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2gateNode != 0))
            {
                i = here->HFET2drainPrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2drainPrimeGateBinding = matched ;
                here->HFET2drainPrimeGatePtr = matched->CSC ;
            }

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2sourcePrimeNode != 0))
            {
                i = here->HFET2drainPriHFET2ourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2drainPriHFET2ourcePrimeBinding = matched ;
                here->HFET2drainPriHFET2ourcePrimePtr = matched->CSC ;
            }

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2gateNode != 0))
            {
                i = here->HFET2sourcePrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2sourcePrimeGateBinding = matched ;
                here->HFET2sourcePrimeGatePtr = matched->CSC ;
            }

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2sourceNode != 0))
            {
                i = here->HFET2sourcePriHFET2ourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2sourcePriHFET2ourceBinding = matched ;
                here->HFET2sourcePriHFET2ourcePtr = matched->CSC ;
            }

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2drainPrimeNode != 0))
            {
                i = here->HFET2sourcePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2sourcePrimeDrainPrimeBinding = matched ;
                here->HFET2sourcePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFET2drainNode != 0) && (here->HFET2drainNode != 0))
            {
                i = here->HFET2drainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2drainDrainBinding = matched ;
                here->HFET2drainDrainPtr = matched->CSC ;
            }

            if ((here->HFET2gateNode != 0) && (here->HFET2gateNode != 0))
            {
                i = here->HFET2gateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2gateGateBinding = matched ;
                here->HFET2gateGatePtr = matched->CSC ;
            }

            if ((here->HFET2sourceNode != 0) && (here->HFET2sourceNode != 0))
            {
                i = here->HFET2sourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2sourceSourceBinding = matched ;
                here->HFET2sourceSourcePtr = matched->CSC ;
            }

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2drainPrimeNode != 0))
            {
                i = here->HFET2drainPrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2drainPrimeDrainPrimeBinding = matched ;
                here->HFET2drainPrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2sourcePrimeNode != 0))
            {
                i = here->HFET2sourcePriHFET2ourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFET2sourcePriHFET2ourcePrimeBinding = matched ;
                here->HFET2sourcePriHFET2ourcePrimePtr = matched->CSC ;
            }

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
            if ((here->HFET2drainNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2drainDrainPrimePtr = here->HFET2drainDrainPrimeBinding->CSC_Complex ;

            if ((here->HFET2gateNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2gateDrainPrimePtr = here->HFET2gateDrainPrimeBinding->CSC_Complex ;

            if ((here->HFET2gateNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2gateSourcePrimePtr = here->HFET2gateSourcePrimeBinding->CSC_Complex ;

            if ((here->HFET2sourceNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2sourceSourcePrimePtr = here->HFET2sourceSourcePrimeBinding->CSC_Complex ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2drainNode != 0))
                here->HFET2drainPrimeDrainPtr = here->HFET2drainPrimeDrainBinding->CSC_Complex ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2gateNode != 0))
                here->HFET2drainPrimeGatePtr = here->HFET2drainPrimeGateBinding->CSC_Complex ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2drainPriHFET2ourcePrimePtr = here->HFET2drainPriHFET2ourcePrimeBinding->CSC_Complex ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2gateNode != 0))
                here->HFET2sourcePrimeGatePtr = here->HFET2sourcePrimeGateBinding->CSC_Complex ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2sourceNode != 0))
                here->HFET2sourcePriHFET2ourcePtr = here->HFET2sourcePriHFET2ourceBinding->CSC_Complex ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2sourcePrimeDrainPrimePtr = here->HFET2sourcePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->HFET2drainNode != 0) && (here->HFET2drainNode != 0))
                here->HFET2drainDrainPtr = here->HFET2drainDrainBinding->CSC_Complex ;

            if ((here->HFET2gateNode != 0) && (here->HFET2gateNode != 0))
                here->HFET2gateGatePtr = here->HFET2gateGateBinding->CSC_Complex ;

            if ((here->HFET2sourceNode != 0) && (here->HFET2sourceNode != 0))
                here->HFET2sourceSourcePtr = here->HFET2sourceSourceBinding->CSC_Complex ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2drainPrimeDrainPrimePtr = here->HFET2drainPrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2sourcePriHFET2ourcePrimePtr = here->HFET2sourcePriHFET2ourcePrimeBinding->CSC_Complex ;

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
            if ((here->HFET2drainNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2drainDrainPrimePtr = here->HFET2drainDrainPrimeBinding->CSC ;

            if ((here->HFET2gateNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2gateDrainPrimePtr = here->HFET2gateDrainPrimeBinding->CSC ;

            if ((here->HFET2gateNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2gateSourcePrimePtr = here->HFET2gateSourcePrimeBinding->CSC ;

            if ((here->HFET2sourceNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2sourceSourcePrimePtr = here->HFET2sourceSourcePrimeBinding->CSC ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2drainNode != 0))
                here->HFET2drainPrimeDrainPtr = here->HFET2drainPrimeDrainBinding->CSC ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2gateNode != 0))
                here->HFET2drainPrimeGatePtr = here->HFET2drainPrimeGateBinding->CSC ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2drainPriHFET2ourcePrimePtr = here->HFET2drainPriHFET2ourcePrimeBinding->CSC ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2gateNode != 0))
                here->HFET2sourcePrimeGatePtr = here->HFET2sourcePrimeGateBinding->CSC ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2sourceNode != 0))
                here->HFET2sourcePriHFET2ourcePtr = here->HFET2sourcePriHFET2ourceBinding->CSC ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2sourcePrimeDrainPrimePtr = here->HFET2sourcePrimeDrainPrimeBinding->CSC ;

            if ((here->HFET2drainNode != 0) && (here->HFET2drainNode != 0))
                here->HFET2drainDrainPtr = here->HFET2drainDrainBinding->CSC ;

            if ((here->HFET2gateNode != 0) && (here->HFET2gateNode != 0))
                here->HFET2gateGatePtr = here->HFET2gateGateBinding->CSC ;

            if ((here->HFET2sourceNode != 0) && (here->HFET2sourceNode != 0))
                here->HFET2sourceSourcePtr = here->HFET2sourceSourceBinding->CSC ;

            if ((here->HFET2drainPrimeNode != 0) && (here->HFET2drainPrimeNode != 0))
                here->HFET2drainPrimeDrainPrimePtr = here->HFET2drainPrimeDrainPrimeBinding->CSC ;

            if ((here->HFET2sourcePrimeNode != 0) && (here->HFET2sourcePrimeNode != 0))
                here->HFET2sourcePriHFET2ourcePrimePtr = here->HFET2sourcePriHFET2ourcePrimeBinding->CSC ;

        }
    }

    return (OK) ;
}
