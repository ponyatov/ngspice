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
            if ((here->JFET2drainNode != 0) && (here->JFET2drainPrimeNode != 0))
            {
                i = here->JFET2drainDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2drainDrainPrimeBinding = matched ;
                here->JFET2drainDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFET2gateNode != 0) && (here->JFET2drainPrimeNode != 0))
            {
                i = here->JFET2gateDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2gateDrainPrimeBinding = matched ;
                here->JFET2gateDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFET2gateNode != 0) && (here->JFET2sourcePrimeNode != 0))
            {
                i = here->JFET2gateSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2gateSourcePrimeBinding = matched ;
                here->JFET2gateSourcePrimePtr = matched->CSC ;
            }

            if ((here->JFET2sourceNode != 0) && (here->JFET2sourcePrimeNode != 0))
            {
                i = here->JFET2sourceSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2sourceSourcePrimeBinding = matched ;
                here->JFET2sourceSourcePrimePtr = matched->CSC ;
            }

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2drainNode != 0))
            {
                i = here->JFET2drainPrimeDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2drainPrimeDrainBinding = matched ;
                here->JFET2drainPrimeDrainPtr = matched->CSC ;
            }

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2gateNode != 0))
            {
                i = here->JFET2drainPrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2drainPrimeGateBinding = matched ;
                here->JFET2drainPrimeGatePtr = matched->CSC ;
            }

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2sourcePrimeNode != 0))
            {
                i = here->JFET2drainPrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2drainPrimeSourcePrimeBinding = matched ;
                here->JFET2drainPrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2gateNode != 0))
            {
                i = here->JFET2sourcePrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2sourcePrimeGateBinding = matched ;
                here->JFET2sourcePrimeGatePtr = matched->CSC ;
            }

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2sourceNode != 0))
            {
                i = here->JFET2sourcePrimeSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2sourcePrimeSourceBinding = matched ;
                here->JFET2sourcePrimeSourcePtr = matched->CSC ;
            }

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2drainPrimeNode != 0))
            {
                i = here->JFET2sourcePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2sourcePrimeDrainPrimeBinding = matched ;
                here->JFET2sourcePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFET2drainNode != 0) && (here->JFET2drainNode != 0))
            {
                i = here->JFET2drainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2drainDrainBinding = matched ;
                here->JFET2drainDrainPtr = matched->CSC ;
            }

            if ((here->JFET2gateNode != 0) && (here->JFET2gateNode != 0))
            {
                i = here->JFET2gateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2gateGateBinding = matched ;
                here->JFET2gateGatePtr = matched->CSC ;
            }

            if ((here->JFET2sourceNode != 0) && (here->JFET2sourceNode != 0))
            {
                i = here->JFET2sourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2sourceSourceBinding = matched ;
                here->JFET2sourceSourcePtr = matched->CSC ;
            }

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2drainPrimeNode != 0))
            {
                i = here->JFET2drainPrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2drainPrimeDrainPrimeBinding = matched ;
                here->JFET2drainPrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2sourcePrimeNode != 0))
            {
                i = here->JFET2sourcePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFET2sourcePrimeSourcePrimeBinding = matched ;
                here->JFET2sourcePrimeSourcePrimePtr = matched->CSC ;
            }

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
            if ((here->JFET2drainNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2drainDrainPrimePtr = here->JFET2drainDrainPrimeBinding->CSC_Complex ;

            if ((here->JFET2gateNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2gateDrainPrimePtr = here->JFET2gateDrainPrimeBinding->CSC_Complex ;

            if ((here->JFET2gateNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2gateSourcePrimePtr = here->JFET2gateSourcePrimeBinding->CSC_Complex ;

            if ((here->JFET2sourceNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2sourceSourcePrimePtr = here->JFET2sourceSourcePrimeBinding->CSC_Complex ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2drainNode != 0))
                here->JFET2drainPrimeDrainPtr = here->JFET2drainPrimeDrainBinding->CSC_Complex ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2gateNode != 0))
                here->JFET2drainPrimeGatePtr = here->JFET2drainPrimeGateBinding->CSC_Complex ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2drainPrimeSourcePrimePtr = here->JFET2drainPrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2gateNode != 0))
                here->JFET2sourcePrimeGatePtr = here->JFET2sourcePrimeGateBinding->CSC_Complex ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2sourceNode != 0))
                here->JFET2sourcePrimeSourcePtr = here->JFET2sourcePrimeSourceBinding->CSC_Complex ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2sourcePrimeDrainPrimePtr = here->JFET2sourcePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->JFET2drainNode != 0) && (here->JFET2drainNode != 0))
                here->JFET2drainDrainPtr = here->JFET2drainDrainBinding->CSC_Complex ;

            if ((here->JFET2gateNode != 0) && (here->JFET2gateNode != 0))
                here->JFET2gateGatePtr = here->JFET2gateGateBinding->CSC_Complex ;

            if ((here->JFET2sourceNode != 0) && (here->JFET2sourceNode != 0))
                here->JFET2sourceSourcePtr = here->JFET2sourceSourceBinding->CSC_Complex ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2drainPrimeDrainPrimePtr = here->JFET2drainPrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2sourcePrimeSourcePrimePtr = here->JFET2sourcePrimeSourcePrimeBinding->CSC_Complex ;

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
            if ((here->JFET2drainNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2drainDrainPrimePtr = here->JFET2drainDrainPrimeBinding->CSC ;

            if ((here->JFET2gateNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2gateDrainPrimePtr = here->JFET2gateDrainPrimeBinding->CSC ;

            if ((here->JFET2gateNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2gateSourcePrimePtr = here->JFET2gateSourcePrimeBinding->CSC ;

            if ((here->JFET2sourceNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2sourceSourcePrimePtr = here->JFET2sourceSourcePrimeBinding->CSC ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2drainNode != 0))
                here->JFET2drainPrimeDrainPtr = here->JFET2drainPrimeDrainBinding->CSC ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2gateNode != 0))
                here->JFET2drainPrimeGatePtr = here->JFET2drainPrimeGateBinding->CSC ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2drainPrimeSourcePrimePtr = here->JFET2drainPrimeSourcePrimeBinding->CSC ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2gateNode != 0))
                here->JFET2sourcePrimeGatePtr = here->JFET2sourcePrimeGateBinding->CSC ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2sourceNode != 0))
                here->JFET2sourcePrimeSourcePtr = here->JFET2sourcePrimeSourceBinding->CSC ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2sourcePrimeDrainPrimePtr = here->JFET2sourcePrimeDrainPrimeBinding->CSC ;

            if ((here->JFET2drainNode != 0) && (here->JFET2drainNode != 0))
                here->JFET2drainDrainPtr = here->JFET2drainDrainBinding->CSC ;

            if ((here->JFET2gateNode != 0) && (here->JFET2gateNode != 0))
                here->JFET2gateGatePtr = here->JFET2gateGateBinding->CSC ;

            if ((here->JFET2sourceNode != 0) && (here->JFET2sourceNode != 0))
                here->JFET2sourceSourcePtr = here->JFET2sourceSourceBinding->CSC ;

            if ((here->JFET2drainPrimeNode != 0) && (here->JFET2drainPrimeNode != 0))
                here->JFET2drainPrimeDrainPrimePtr = here->JFET2drainPrimeDrainPrimeBinding->CSC ;

            if ((here->JFET2sourcePrimeNode != 0) && (here->JFET2sourcePrimeNode != 0))
                here->JFET2sourcePrimeSourcePrimePtr = here->JFET2sourcePrimeSourcePrimeBinding->CSC ;

        }
    }

    return (OK) ;
}
