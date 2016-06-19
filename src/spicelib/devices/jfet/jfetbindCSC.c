/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "jfetdefs.h"
#include "ngspice/sperror.h"

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
JFETbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    JFETmodel *model = (JFETmodel *)inModel ;
    JFETinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the JFET models */
    for ( ; model != NULL ; model = model->JFETnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->JFETinstances ; here != NULL ; here = here->JFETnextInstance)
        {
            if ((here->JFETdrainNode != 0) && (here->JFETdrainPrimeNode != 0))
            {
                i = here->JFETdrainDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETdrainDrainPrimeBinding = matched ;
                here->JFETdrainDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFETgateNode != 0) && (here->JFETdrainPrimeNode != 0))
            {
                i = here->JFETgateDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETgateDrainPrimeBinding = matched ;
                here->JFETgateDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFETgateNode != 0) && (here->JFETsourcePrimeNode != 0))
            {
                i = here->JFETgateSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETgateSourcePrimeBinding = matched ;
                here->JFETgateSourcePrimePtr = matched->CSC ;
            }

            if ((here->JFETsourceNode != 0) && (here->JFETsourcePrimeNode != 0))
            {
                i = here->JFETsourceSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETsourceSourcePrimeBinding = matched ;
                here->JFETsourceSourcePrimePtr = matched->CSC ;
            }

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETdrainNode != 0))
            {
                i = here->JFETdrainPrimeDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETdrainPrimeDrainBinding = matched ;
                here->JFETdrainPrimeDrainPtr = matched->CSC ;
            }

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETgateNode != 0))
            {
                i = here->JFETdrainPrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETdrainPrimeGateBinding = matched ;
                here->JFETdrainPrimeGatePtr = matched->CSC ;
            }

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETsourcePrimeNode != 0))
            {
                i = here->JFETdrainPrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETdrainPrimeSourcePrimeBinding = matched ;
                here->JFETdrainPrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETgateNode != 0))
            {
                i = here->JFETsourcePrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETsourcePrimeGateBinding = matched ;
                here->JFETsourcePrimeGatePtr = matched->CSC ;
            }

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETsourceNode != 0))
            {
                i = here->JFETsourcePrimeSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETsourcePrimeSourceBinding = matched ;
                here->JFETsourcePrimeSourcePtr = matched->CSC ;
            }

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETdrainPrimeNode != 0))
            {
                i = here->JFETsourcePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETsourcePrimeDrainPrimeBinding = matched ;
                here->JFETsourcePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFETdrainNode != 0) && (here->JFETdrainNode != 0))
            {
                i = here->JFETdrainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETdrainDrainBinding = matched ;
                here->JFETdrainDrainPtr = matched->CSC ;
            }

            if ((here->JFETgateNode != 0) && (here->JFETgateNode != 0))
            {
                i = here->JFETgateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETgateGateBinding = matched ;
                here->JFETgateGatePtr = matched->CSC ;
            }

            if ((here->JFETsourceNode != 0) && (here->JFETsourceNode != 0))
            {
                i = here->JFETsourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETsourceSourceBinding = matched ;
                here->JFETsourceSourcePtr = matched->CSC ;
            }

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETdrainPrimeNode != 0))
            {
                i = here->JFETdrainPrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETdrainPrimeDrainPrimeBinding = matched ;
                here->JFETdrainPrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETsourcePrimeNode != 0))
            {
                i = here->JFETsourcePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->JFETsourcePrimeSourcePrimeBinding = matched ;
                here->JFETsourcePrimeSourcePrimePtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
JFETbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    JFETmodel *model = (JFETmodel *)inModel ;
    JFETinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the JFET models */
    for ( ; model != NULL ; model = model->JFETnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->JFETinstances ; here != NULL ; here = here->JFETnextInstance)
        {
            if ((here->JFETdrainNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETdrainDrainPrimePtr = here->JFETdrainDrainPrimeBinding->CSC_Complex ;

            if ((here->JFETgateNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETgateDrainPrimePtr = here->JFETgateDrainPrimeBinding->CSC_Complex ;

            if ((here->JFETgateNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETgateSourcePrimePtr = here->JFETgateSourcePrimeBinding->CSC_Complex ;

            if ((here->JFETsourceNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETsourceSourcePrimePtr = here->JFETsourceSourcePrimeBinding->CSC_Complex ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETdrainNode != 0))
                here->JFETdrainPrimeDrainPtr = here->JFETdrainPrimeDrainBinding->CSC_Complex ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETgateNode != 0))
                here->JFETdrainPrimeGatePtr = here->JFETdrainPrimeGateBinding->CSC_Complex ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETdrainPrimeSourcePrimePtr = here->JFETdrainPrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETgateNode != 0))
                here->JFETsourcePrimeGatePtr = here->JFETsourcePrimeGateBinding->CSC_Complex ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETsourceNode != 0))
                here->JFETsourcePrimeSourcePtr = here->JFETsourcePrimeSourceBinding->CSC_Complex ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETsourcePrimeDrainPrimePtr = here->JFETsourcePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->JFETdrainNode != 0) && (here->JFETdrainNode != 0))
                here->JFETdrainDrainPtr = here->JFETdrainDrainBinding->CSC_Complex ;

            if ((here->JFETgateNode != 0) && (here->JFETgateNode != 0))
                here->JFETgateGatePtr = here->JFETgateGateBinding->CSC_Complex ;

            if ((here->JFETsourceNode != 0) && (here->JFETsourceNode != 0))
                here->JFETsourceSourcePtr = here->JFETsourceSourceBinding->CSC_Complex ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETdrainPrimeDrainPrimePtr = here->JFETdrainPrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETsourcePrimeSourcePrimePtr = here->JFETsourcePrimeSourcePrimeBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
JFETbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    JFETmodel *model = (JFETmodel *)inModel ;
    JFETinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the JFET models */
    for ( ; model != NULL ; model = model->JFETnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->JFETinstances ; here != NULL ; here = here->JFETnextInstance)
        {
            if ((here->JFETdrainNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETdrainDrainPrimePtr = here->JFETdrainDrainPrimeBinding->CSC ;

            if ((here->JFETgateNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETgateDrainPrimePtr = here->JFETgateDrainPrimeBinding->CSC ;

            if ((here->JFETgateNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETgateSourcePrimePtr = here->JFETgateSourcePrimeBinding->CSC ;

            if ((here->JFETsourceNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETsourceSourcePrimePtr = here->JFETsourceSourcePrimeBinding->CSC ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETdrainNode != 0))
                here->JFETdrainPrimeDrainPtr = here->JFETdrainPrimeDrainBinding->CSC ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETgateNode != 0))
                here->JFETdrainPrimeGatePtr = here->JFETdrainPrimeGateBinding->CSC ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETdrainPrimeSourcePrimePtr = here->JFETdrainPrimeSourcePrimeBinding->CSC ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETgateNode != 0))
                here->JFETsourcePrimeGatePtr = here->JFETsourcePrimeGateBinding->CSC ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETsourceNode != 0))
                here->JFETsourcePrimeSourcePtr = here->JFETsourcePrimeSourceBinding->CSC ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETsourcePrimeDrainPrimePtr = here->JFETsourcePrimeDrainPrimeBinding->CSC ;

            if ((here->JFETdrainNode != 0) && (here->JFETdrainNode != 0))
                here->JFETdrainDrainPtr = here->JFETdrainDrainBinding->CSC ;

            if ((here->JFETgateNode != 0) && (here->JFETgateNode != 0))
                here->JFETgateGatePtr = here->JFETgateGateBinding->CSC ;

            if ((here->JFETsourceNode != 0) && (here->JFETsourceNode != 0))
                here->JFETsourceSourcePtr = here->JFETsourceSourceBinding->CSC ;

            if ((here->JFETdrainPrimeNode != 0) && (here->JFETdrainPrimeNode != 0))
                here->JFETdrainPrimeDrainPrimePtr = here->JFETdrainPrimeDrainPrimeBinding->CSC ;

            if ((here->JFETsourcePrimeNode != 0) && (here->JFETsourcePrimeNode != 0))
                here->JFETsourcePrimeSourcePrimePtr = here->JFETsourcePrimeSourcePrimeBinding->CSC ;

        }
    }

    return (OK) ;
}
