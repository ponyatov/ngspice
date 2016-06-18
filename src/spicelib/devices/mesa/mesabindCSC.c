/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mesadefs.h"
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
MESAbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MESAmodel *model = (MESAmodel *)inModel ;
    MESAinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MESA models */
    for ( ; model != NULL ; model = model->MESAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MESAinstances ; here != NULL ; here = here->MESAnextInstance)
        {
            if ((here->MESAdrainNode != 0) && (here->MESAdrainNode != 0))
            {
                i = here->MESAdrainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainDrainBinding = matched ;
                here->MESAdrainDrainPtr = matched->CSC ;
            }

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
            {
                i = here->MESAdrainPrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrimeDrainPrimeBinding = matched ;
                here->MESAdrainPrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAdrainPrmPrmNode != 0))
            {
                i = here->MESAdrainPrmPrmDrainPrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrmPrmDrainPrmPrmBinding = matched ;
                here->MESAdrainPrmPrmDrainPrmPrmPtr = matched->CSC ;
            }

            if ((here->MESAgateNode != 0) && (here->MESAgateNode != 0))
            {
                i = here->MESAgateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgateGateBinding = matched ;
                here->MESAgateGatePtr = matched->CSC ;
            }

            if ((here->MESAgatePrimeNode != 0) && (here->MESAgatePrimeNode != 0))
            {
                i = here->MESAgatePrimeGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgatePrimeGatePrimeBinding = matched ;
                here->MESAgatePrimeGatePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourceNode != 0) && (here->MESAsourceNode != 0))
            {
                i = here->MESAsourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourceSourceBinding = matched ;
                here->MESAsourceSourcePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
            {
                i = here->MESAsourcePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrimeSourcePrimeBinding = matched ;
                here->MESAsourcePrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAsourcePrmPrmNode != 0))
            {
                i = here->MESAsourcePrmPrmSourcePrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrmPrmSourcePrmPrmBinding = matched ;
                here->MESAsourcePrmPrmSourcePrmPrmPtr = matched->CSC ;
            }

            if ((here->MESAdrainNode != 0) && (here->MESAdrainPrimeNode != 0))
            {
                i = here->MESAdrainDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainDrainPrimeBinding = matched ;
                here->MESAdrainDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainNode != 0))
            {
                i = here->MESAdrainPrimeDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrimeDrainBinding = matched ;
                here->MESAdrainPrimeDrainPtr = matched->CSC ;
            }

            if ((here->MESAgatePrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
            {
                i = here->MESAgatePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgatePrimeDrainPrimeBinding = matched ;
                here->MESAgatePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAgatePrimeNode != 0))
            {
                i = here->MESAdrainPrimeGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrimeGatePrimeBinding = matched ;
                here->MESAdrainPrimeGatePrimePtr = matched->CSC ;
            }

            if ((here->MESAgatePrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
            {
                i = here->MESAgatePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgatePrimeSourcePrimeBinding = matched ;
                here->MESAgatePrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAgatePrimeNode != 0))
            {
                i = here->MESAsourcePrimeGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrimeGatePrimeBinding = matched ;
                here->MESAsourcePrimeGatePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourceNode != 0) && (here->MESAsourcePrimeNode != 0))
            {
                i = here->MESAsourceSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourceSourcePrimeBinding = matched ;
                here->MESAsourceSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourceNode != 0))
            {
                i = here->MESAsourcePrimeSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrimeSourceBinding = matched ;
                here->MESAsourcePrimeSourcePtr = matched->CSC ;
            }

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
            {
                i = here->MESAdrainPrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrimeSourcePrimeBinding = matched ;
                here->MESAdrainPrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
            {
                i = here->MESAsourcePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrimeDrainPrimeBinding = matched ;
                here->MESAsourcePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESAgatePrimeNode != 0) && (here->MESAgateNode != 0))
            {
                i = here->MESAgatePrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgatePrimeGateBinding = matched ;
                here->MESAgatePrimeGatePtr = matched->CSC ;
            }

            if ((here->MESAgateNode != 0) && (here->MESAgatePrimeNode != 0))
            {
                i = here->MESAgateGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgateGatePrimeBinding = matched ;
                here->MESAgateGatePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAsourcePrimeNode != 0))
            {
                i = here->MESAsourcePrmPrmSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrmPrmSourcePrimeBinding = matched ;
                here->MESAsourcePrmPrmSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourcePrmPrmNode != 0))
            {
                i = here->MESAsourcePrimeSourcePrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrimeSourcePrmPrmBinding = matched ;
                here->MESAsourcePrimeSourcePrmPrmPtr = matched->CSC ;
            }

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAgatePrimeNode != 0))
            {
                i = here->MESAsourcePrmPrmGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAsourcePrmPrmGatePrimeBinding = matched ;
                here->MESAsourcePrmPrmGatePrimePtr = matched->CSC ;
            }

            if ((here->MESAgatePrimeNode != 0) && (here->MESAsourcePrmPrmNode != 0))
            {
                i = here->MESAgatePrimeSourcePrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgatePrimeSourcePrmPrmBinding = matched ;
                here->MESAgatePrimeSourcePrmPrmPtr = matched->CSC ;
            }

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAdrainPrimeNode != 0))
            {
                i = here->MESAdrainPrmPrmDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrmPrmDrainPrimeBinding = matched ;
                here->MESAdrainPrmPrmDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainPrmPrmNode != 0))
            {
                i = here->MESAdrainPrimeDrainPrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrimeDrainPrmPrmBinding = matched ;
                here->MESAdrainPrimeDrainPrmPrmPtr = matched->CSC ;
            }

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAgatePrimeNode != 0))
            {
                i = here->MESAdrainPrmPrmGatePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAdrainPrmPrmGatePrimeBinding = matched ;
                here->MESAdrainPrmPrmGatePrimePtr = matched->CSC ;
            }

            if ((here->MESAgatePrimeNode != 0) && (here->MESAdrainPrmPrmNode != 0))
            {
                i = here->MESAgatePrimeDrainPrmPrmPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESAgatePrimeDrainPrmPrmBinding = matched ;
                here->MESAgatePrimeDrainPrmPrmPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
MESAbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MESAmodel *model = (MESAmodel *)inModel ;
    MESAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MESA models */
    for ( ; model != NULL ; model = model->MESAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MESAinstances ; here != NULL ; here = here->MESAnextInstance)
        {
            if ((here->MESAdrainNode != 0) && (here->MESAdrainNode != 0))
                here->MESAdrainDrainPtr = here->MESAdrainDrainBinding->CSC_Complex ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAdrainPrimeDrainPrimePtr = here->MESAdrainPrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAdrainPrmPrmNode != 0))
                here->MESAdrainPrmPrmDrainPrmPrmPtr = here->MESAdrainPrmPrmDrainPrmPrmBinding->CSC_Complex ;

            if ((here->MESAgateNode != 0) && (here->MESAgateNode != 0))
                here->MESAgateGatePtr = here->MESAgateGateBinding->CSC_Complex ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAgatePrimeGatePrimePtr = here->MESAgatePrimeGatePrimeBinding->CSC_Complex ;

            if ((here->MESAsourceNode != 0) && (here->MESAsourceNode != 0))
                here->MESAsourceSourcePtr = here->MESAsourceSourceBinding->CSC_Complex ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAsourcePrimeSourcePrimePtr = here->MESAsourcePrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAsourcePrmPrmNode != 0))
                here->MESAsourcePrmPrmSourcePrmPrmPtr = here->MESAsourcePrmPrmSourcePrmPrmBinding->CSC_Complex ;

            if ((here->MESAdrainNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAdrainDrainPrimePtr = here->MESAdrainDrainPrimeBinding->CSC_Complex ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainNode != 0))
                here->MESAdrainPrimeDrainPtr = here->MESAdrainPrimeDrainBinding->CSC_Complex ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAgatePrimeDrainPrimePtr = here->MESAgatePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAdrainPrimeGatePrimePtr = here->MESAdrainPrimeGatePrimeBinding->CSC_Complex ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAgatePrimeSourcePrimePtr = here->MESAgatePrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAsourcePrimeGatePrimePtr = here->MESAsourcePrimeGatePrimeBinding->CSC_Complex ;

            if ((here->MESAsourceNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAsourceSourcePrimePtr = here->MESAsourceSourcePrimeBinding->CSC_Complex ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourceNode != 0))
                here->MESAsourcePrimeSourcePtr = here->MESAsourcePrimeSourceBinding->CSC_Complex ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAdrainPrimeSourcePrimePtr = here->MESAdrainPrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAsourcePrimeDrainPrimePtr = here->MESAsourcePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAgateNode != 0))
                here->MESAgatePrimeGatePtr = here->MESAgatePrimeGateBinding->CSC_Complex ;

            if ((here->MESAgateNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAgateGatePrimePtr = here->MESAgateGatePrimeBinding->CSC_Complex ;

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAsourcePrmPrmSourcePrimePtr = here->MESAsourcePrmPrmSourcePrimeBinding->CSC_Complex ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourcePrmPrmNode != 0))
                here->MESAsourcePrimeSourcePrmPrmPtr = here->MESAsourcePrimeSourcePrmPrmBinding->CSC_Complex ;

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAsourcePrmPrmGatePrimePtr = here->MESAsourcePrmPrmGatePrimeBinding->CSC_Complex ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAsourcePrmPrmNode != 0))
                here->MESAgatePrimeSourcePrmPrmPtr = here->MESAgatePrimeSourcePrmPrmBinding->CSC_Complex ;

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAdrainPrmPrmDrainPrimePtr = here->MESAdrainPrmPrmDrainPrimeBinding->CSC_Complex ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainPrmPrmNode != 0))
                here->MESAdrainPrimeDrainPrmPrmPtr = here->MESAdrainPrimeDrainPrmPrmBinding->CSC_Complex ;

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAdrainPrmPrmGatePrimePtr = here->MESAdrainPrmPrmGatePrimeBinding->CSC_Complex ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAdrainPrmPrmNode != 0))
                here->MESAgatePrimeDrainPrmPrmPtr = here->MESAgatePrimeDrainPrmPrmBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
MESAbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MESAmodel *model = (MESAmodel *)inModel ;
    MESAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MESA models */
    for ( ; model != NULL ; model = model->MESAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MESAinstances ; here != NULL ; here = here->MESAnextInstance)
        {
            if ((here->MESAdrainNode != 0) && (here->MESAdrainNode != 0))
                here->MESAdrainDrainPtr = here->MESAdrainDrainBinding->CSC ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAdrainPrimeDrainPrimePtr = here->MESAdrainPrimeDrainPrimeBinding->CSC ;

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAdrainPrmPrmNode != 0))
                here->MESAdrainPrmPrmDrainPrmPrmPtr = here->MESAdrainPrmPrmDrainPrmPrmBinding->CSC ;

            if ((here->MESAgateNode != 0) && (here->MESAgateNode != 0))
                here->MESAgateGatePtr = here->MESAgateGateBinding->CSC ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAgatePrimeGatePrimePtr = here->MESAgatePrimeGatePrimeBinding->CSC ;

            if ((here->MESAsourceNode != 0) && (here->MESAsourceNode != 0))
                here->MESAsourceSourcePtr = here->MESAsourceSourceBinding->CSC ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAsourcePrimeSourcePrimePtr = here->MESAsourcePrimeSourcePrimeBinding->CSC ;

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAsourcePrmPrmNode != 0))
                here->MESAsourcePrmPrmSourcePrmPrmPtr = here->MESAsourcePrmPrmSourcePrmPrmBinding->CSC ;

            if ((here->MESAdrainNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAdrainDrainPrimePtr = here->MESAdrainDrainPrimeBinding->CSC ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainNode != 0))
                here->MESAdrainPrimeDrainPtr = here->MESAdrainPrimeDrainBinding->CSC ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAgatePrimeDrainPrimePtr = here->MESAgatePrimeDrainPrimeBinding->CSC ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAdrainPrimeGatePrimePtr = here->MESAdrainPrimeGatePrimeBinding->CSC ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAgatePrimeSourcePrimePtr = here->MESAgatePrimeSourcePrimeBinding->CSC ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAsourcePrimeGatePrimePtr = here->MESAsourcePrimeGatePrimeBinding->CSC ;

            if ((here->MESAsourceNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAsourceSourcePrimePtr = here->MESAsourceSourcePrimeBinding->CSC ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourceNode != 0))
                here->MESAsourcePrimeSourcePtr = here->MESAsourcePrimeSourceBinding->CSC ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAdrainPrimeSourcePrimePtr = here->MESAdrainPrimeSourcePrimeBinding->CSC ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAsourcePrimeDrainPrimePtr = here->MESAsourcePrimeDrainPrimeBinding->CSC ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAgateNode != 0))
                here->MESAgatePrimeGatePtr = here->MESAgatePrimeGateBinding->CSC ;

            if ((here->MESAgateNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAgateGatePrimePtr = here->MESAgateGatePrimeBinding->CSC ;

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAsourcePrimeNode != 0))
                here->MESAsourcePrmPrmSourcePrimePtr = here->MESAsourcePrmPrmSourcePrimeBinding->CSC ;

            if ((here->MESAsourcePrimeNode != 0) && (here->MESAsourcePrmPrmNode != 0))
                here->MESAsourcePrimeSourcePrmPrmPtr = here->MESAsourcePrimeSourcePrmPrmBinding->CSC ;

            if ((here->MESAsourcePrmPrmNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAsourcePrmPrmGatePrimePtr = here->MESAsourcePrmPrmGatePrimeBinding->CSC ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAsourcePrmPrmNode != 0))
                here->MESAgatePrimeSourcePrmPrmPtr = here->MESAgatePrimeSourcePrmPrmBinding->CSC ;

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAdrainPrimeNode != 0))
                here->MESAdrainPrmPrmDrainPrimePtr = here->MESAdrainPrmPrmDrainPrimeBinding->CSC ;

            if ((here->MESAdrainPrimeNode != 0) && (here->MESAdrainPrmPrmNode != 0))
                here->MESAdrainPrimeDrainPrmPrmPtr = here->MESAdrainPrimeDrainPrmPrmBinding->CSC ;

            if ((here->MESAdrainPrmPrmNode != 0) && (here->MESAgatePrimeNode != 0))
                here->MESAdrainPrmPrmGatePrimePtr = here->MESAdrainPrmPrmGatePrimeBinding->CSC ;

            if ((here->MESAgatePrimeNode != 0) && (here->MESAdrainPrmPrmNode != 0))
                here->MESAgatePrimeDrainPrmPrmPtr = here->MESAgatePrimeDrainPrmPrmBinding->CSC ;

        }
    }

    return (OK) ;
}
