/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "hfetdefs.h"
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
HFETAbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    HFETAmodel *model = (HFETAmodel *)inModel ;
    HFETAinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the HFETA models */
    for ( ; model != NULL ; model = model->HFETAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HFETAinstances ; here != NULL ; here = here->HFETAnextInstance)
        {
            if ((here->HFETAdrainNode != 0) && (here->HFETAdrainPrimeNode != 0))
            {
                i = here->HFETAdrainDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainDrainPrimeBinding = matched ;
                here->HFETAdrainDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
            {
                i = here->HFETAgatePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgatePrimeDrainPrimeBinding = matched ;
                here->HFETAgatePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
            {
                i = here->HFETAgatePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgatePrimeSourcePrimeBinding = matched ;
                here->HFETAgatePrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFETAsourceNode != 0) && (here->HFETAsourcePrimeNode != 0))
            {
                i = here->HFETAsourceSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourceSourcePrimeBinding = matched ;
                here->HFETAsourceSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainNode != 0))
            {
                i = here->HFETAdrainPrimeDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrimeDrainBinding = matched ;
                here->HFETAdrainPrimeDrainPtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
            {
                i = here->HFETAdrainPrimeGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrimeGatePrimeBinding = matched ;
                here->HFETAdrainPrimeGatePrimePtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
            {
                i = here->HFETAdrainPrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrimeSourcePrimeBinding = matched ;
                here->HFETAdrainPrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
            {
                i = here->HFETAsourcePrimeGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrimeGatePrimeBinding = matched ;
                here->HFETAsourcePrimeGatePrimePtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourceNode != 0))
            {
                i = here->HFETAsourcePrimeSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrimeSourceBinding = matched ;
                here->HFETAsourcePrimeSourcePtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
            {
                i = here->HFETAsourcePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrimeDrainPrimeBinding = matched ;
                here->HFETAsourcePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFETAdrainNode != 0) && (here->HFETAdrainNode != 0))
            {
                i = here->HFETAdrainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainDrainBinding = matched ;
                here->HFETAdrainDrainPtr = matched->CSC ;
            }

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
            {
                i = here->HFETAgatePrimeGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgatePrimeGatePrimeBinding = matched ;
                here->HFETAgatePrimeGatePrimePtr = matched->CSC ;
            }

            if ((here->HFETAsourceNode != 0) && (here->HFETAsourceNode != 0))
            {
                i = here->HFETAsourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourceSourceBinding = matched ;
                here->HFETAsourceSourcePtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
            {
                i = here->HFETAdrainPrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrimeDrainPrimeBinding = matched ;
                here->HFETAdrainPrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
            {
                i = here->HFETAsourcePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrimeSourcePrimeBinding = matched ;
                here->HFETAsourcePrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
            {
                i = here->HFETAdrainPrimeDrainPrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrimeDrainPrmPrmBinding = matched ;
                here->HFETAdrainPrimeDrainPrmPrmPtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAdrainPrimeNode != 0))
            {
                i = here->HFETAdrainPrmPrmDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrmPrmDrainPrimeBinding = matched ;
                here->HFETAdrainPrmPrmDrainPrimePtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAgatePrimeNode != 0))
            {
                i = here->HFETAdrainPrmPrmGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrmPrmGatePrimeBinding = matched ;
                here->HFETAdrainPrmPrmGatePrimePtr = matched->CSC ;
            }

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
            {
                i = here->HFETAgatePrimeDrainPrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgatePrimeDrainPrmPrmBinding = matched ;
                here->HFETAgatePrimeDrainPrmPrmPtr = matched->CSC ;
            }

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
            {
                i = here->HFETAdrainPrmPrmDrainPrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAdrainPrmPrmDrainPrmPrmBinding = matched ;
                here->HFETAdrainPrmPrmDrainPrmPrmPtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
            {
                i = here->HFETAsourcePrimeSourcePrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrimeSourcePrmPrmBinding = matched ;
                here->HFETAsourcePrimeSourcePrmPrmPtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAsourcePrimeNode != 0))
            {
                i = here->HFETAsourcePrmPrmSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrmPrmSourcePrimeBinding = matched ;
                here->HFETAsourcePrmPrmSourcePrimePtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAgatePrimeNode != 0))
            {
                i = here->HFETAsourcePrmPrmGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrmPrmGatePrimeBinding = matched ;
                here->HFETAsourcePrmPrmGatePrimePtr = matched->CSC ;
            }

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
            {
                i = here->HFETAgatePrimeSourcePrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgatePrimeSourcePrmPrmBinding = matched ;
                here->HFETAgatePrimeSourcePrmPrmPtr = matched->CSC ;
            }

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
            {
                i = here->HFETAsourcePrmPrmSourcePrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAsourcePrmPrmSourcePrmPrmBinding = matched ;
                here->HFETAsourcePrmPrmSourcePrmPrmPtr = matched->CSC ;
            }

            if ((here->HFETAgateNode != 0) && (here->HFETAgateNode != 0))
            {
                i = here->HFETAgateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgateGateBinding = matched ;
                here->HFETAgateGatePtr = matched->CSC ;
            }

            if ((here->HFETAgateNode != 0) && (here->HFETAgatePrimeNode != 0))
            {
                i = here->HFETAgateGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgateGatePrimeBinding = matched ;
                here->HFETAgateGatePrimePtr = matched->CSC ;
            }

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAgateNode != 0))
            {
                i = here->HFETAgatePrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HFETAgatePrimeGateBinding = matched ;
                here->HFETAgatePrimeGatePtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
HFETAbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    HFETAmodel *model = (HFETAmodel *)inModel ;
    HFETAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HFETA models */
    for ( ; model != NULL ; model = model->HFETAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HFETAinstances ; here != NULL ; here = here->HFETAnextInstance)
        {
            if ((here->HFETAdrainNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAdrainDrainPrimePtr = here->HFETAdrainDrainPrimeBinding->CSC_Complex ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAgatePrimeDrainPrimePtr = here->HFETAgatePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAgatePrimeSourcePrimePtr = here->HFETAgatePrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->HFETAsourceNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAsourceSourcePrimePtr = here->HFETAsourceSourcePrimeBinding->CSC_Complex ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainNode != 0))
                here->HFETAdrainPrimeDrainPtr = here->HFETAdrainPrimeDrainBinding->CSC_Complex ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAdrainPrimeGatePrimePtr = here->HFETAdrainPrimeGatePrimeBinding->CSC_Complex ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAdrainPrimeSourcePrimePtr = here->HFETAdrainPrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAsourcePrimeGatePrimePtr = here->HFETAsourcePrimeGatePrimeBinding->CSC_Complex ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourceNode != 0))
                here->HFETAsourcePrimeSourcePtr = here->HFETAsourcePrimeSourceBinding->CSC_Complex ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAsourcePrimeDrainPrimePtr = here->HFETAsourcePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->HFETAdrainNode != 0) && (here->HFETAdrainNode != 0))
                here->HFETAdrainDrainPtr = here->HFETAdrainDrainBinding->CSC_Complex ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAgatePrimeGatePrimePtr = here->HFETAgatePrimeGatePrimeBinding->CSC_Complex ;

            if ((here->HFETAsourceNode != 0) && (here->HFETAsourceNode != 0))
                here->HFETAsourceSourcePtr = here->HFETAsourceSourceBinding->CSC_Complex ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAdrainPrimeDrainPrimePtr = here->HFETAdrainPrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAsourcePrimeSourcePrimePtr = here->HFETAsourcePrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
                here->HFETAdrainPrimeDrainPrmPrmPtr = here->HFETAdrainPrimeDrainPrmPrmBinding->CSC_Complex ;

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAdrainPrmPrmDrainPrimePtr = here->HFETAdrainPrmPrmDrainPrimeBinding->CSC_Complex ;

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAdrainPrmPrmGatePrimePtr = here->HFETAdrainPrmPrmGatePrimeBinding->CSC_Complex ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
                here->HFETAgatePrimeDrainPrmPrmPtr = here->HFETAgatePrimeDrainPrmPrmBinding->CSC_Complex ;

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
                here->HFETAdrainPrmPrmDrainPrmPrmPtr = here->HFETAdrainPrmPrmDrainPrmPrmBinding->CSC_Complex ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
                here->HFETAsourcePrimeSourcePrmPrmPtr = here->HFETAsourcePrimeSourcePrmPrmBinding->CSC_Complex ;

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAsourcePrmPrmSourcePrimePtr = here->HFETAsourcePrmPrmSourcePrimeBinding->CSC_Complex ;

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAsourcePrmPrmGatePrimePtr = here->HFETAsourcePrmPrmGatePrimeBinding->CSC_Complex ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
                here->HFETAgatePrimeSourcePrmPrmPtr = here->HFETAgatePrimeSourcePrmPrmBinding->CSC_Complex ;

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
                here->HFETAsourcePrmPrmSourcePrmPrmPtr = here->HFETAsourcePrmPrmSourcePrmPrmBinding->CSC_Complex ;

            if ((here->HFETAgateNode != 0) && (here->HFETAgateNode != 0))
                here->HFETAgateGatePtr = here->HFETAgateGateBinding->CSC_Complex ;

            if ((here->HFETAgateNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAgateGatePrimePtr = here->HFETAgateGatePrimeBinding->CSC_Complex ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAgateNode != 0))
                here->HFETAgatePrimeGatePtr = here->HFETAgatePrimeGateBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
HFETAbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    HFETAmodel *model = (HFETAmodel *)inModel ;
    HFETAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HFETA models */
    for ( ; model != NULL ; model = model->HFETAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HFETAinstances ; here != NULL ; here = here->HFETAnextInstance)
        {
            if ((here->HFETAdrainNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAdrainDrainPrimePtr = here->HFETAdrainDrainPrimeBinding->CSC ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAgatePrimeDrainPrimePtr = here->HFETAgatePrimeDrainPrimeBinding->CSC ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAgatePrimeSourcePrimePtr = here->HFETAgatePrimeSourcePrimeBinding->CSC ;

            if ((here->HFETAsourceNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAsourceSourcePrimePtr = here->HFETAsourceSourcePrimeBinding->CSC ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainNode != 0))
                here->HFETAdrainPrimeDrainPtr = here->HFETAdrainPrimeDrainBinding->CSC ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAdrainPrimeGatePrimePtr = here->HFETAdrainPrimeGatePrimeBinding->CSC ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAdrainPrimeSourcePrimePtr = here->HFETAdrainPrimeSourcePrimeBinding->CSC ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAsourcePrimeGatePrimePtr = here->HFETAsourcePrimeGatePrimeBinding->CSC ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourceNode != 0))
                here->HFETAsourcePrimeSourcePtr = here->HFETAsourcePrimeSourceBinding->CSC ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAsourcePrimeDrainPrimePtr = here->HFETAsourcePrimeDrainPrimeBinding->CSC ;

            if ((here->HFETAdrainNode != 0) && (here->HFETAdrainNode != 0))
                here->HFETAdrainDrainPtr = here->HFETAdrainDrainBinding->CSC ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAgatePrimeGatePrimePtr = here->HFETAgatePrimeGatePrimeBinding->CSC ;

            if ((here->HFETAsourceNode != 0) && (here->HFETAsourceNode != 0))
                here->HFETAsourceSourcePtr = here->HFETAsourceSourceBinding->CSC ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAdrainPrimeDrainPrimePtr = here->HFETAdrainPrimeDrainPrimeBinding->CSC ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAsourcePrimeSourcePrimePtr = here->HFETAsourcePrimeSourcePrimeBinding->CSC ;

            if ((here->HFETAdrainPrimeNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
                here->HFETAdrainPrimeDrainPrmPrmPtr = here->HFETAdrainPrimeDrainPrmPrmBinding->CSC ;

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAdrainPrimeNode != 0))
                here->HFETAdrainPrmPrmDrainPrimePtr = here->HFETAdrainPrmPrmDrainPrimeBinding->CSC ;

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAdrainPrmPrmGatePrimePtr = here->HFETAdrainPrmPrmGatePrimeBinding->CSC ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
                here->HFETAgatePrimeDrainPrmPrmPtr = here->HFETAgatePrimeDrainPrmPrmBinding->CSC ;

            if ((here->HFETAdrainPrmPrmNode != 0) && (here->HFETAdrainPrmPrmNode != 0))
                here->HFETAdrainPrmPrmDrainPrmPrmPtr = here->HFETAdrainPrmPrmDrainPrmPrmBinding->CSC ;

            if ((here->HFETAsourcePrimeNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
                here->HFETAsourcePrimeSourcePrmPrmPtr = here->HFETAsourcePrimeSourcePrmPrmBinding->CSC ;

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAsourcePrimeNode != 0))
                here->HFETAsourcePrmPrmSourcePrimePtr = here->HFETAsourcePrmPrmSourcePrimeBinding->CSC ;

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAsourcePrmPrmGatePrimePtr = here->HFETAsourcePrmPrmGatePrimeBinding->CSC ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
                here->HFETAgatePrimeSourcePrmPrmPtr = here->HFETAgatePrimeSourcePrmPrmBinding->CSC ;

            if ((here->HFETAsourcePrmPrmNode != 0) && (here->HFETAsourcePrmPrmNode != 0))
                here->HFETAsourcePrmPrmSourcePrmPrmPtr = here->HFETAsourcePrmPrmSourcePrmPrmBinding->CSC ;

            if ((here->HFETAgateNode != 0) && (here->HFETAgateNode != 0))
                here->HFETAgateGatePtr = here->HFETAgateGateBinding->CSC ;

            if ((here->HFETAgateNode != 0) && (here->HFETAgatePrimeNode != 0))
                here->HFETAgateGatePrimePtr = here->HFETAgateGatePrimeBinding->CSC ;

            if ((here->HFETAgatePrimeNode != 0) && (here->HFETAgateNode != 0))
                here->HFETAgatePrimeGatePtr = here->HFETAgatePrimeGateBinding->CSC ;

        }
    }

    return (OK) ;
}
