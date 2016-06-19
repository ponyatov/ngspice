/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mesdefs.h"
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
MESbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MESmodel *model = (MESmodel *)inModel ;
    MESinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MES models */
    for ( ; model != NULL ; model = model->MESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MESinstances ; here != NULL ; here = here->MESnextInstance)
        {
            if ((here->MESdrainNode != 0) && (here->MESdrainPrimeNode != 0))
            {
                i = here->MESdrainDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESdrainDrainPrimeBinding = matched ;
                here->MESdrainDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESgateNode != 0) && (here->MESdrainPrimeNode != 0))
            {
                i = here->MESgateDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESgateDrainPrimeBinding = matched ;
                here->MESgateDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESgateNode != 0) && (here->MESsourcePrimeNode != 0))
            {
                i = here->MESgateSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESgateSourcePrimeBinding = matched ;
                here->MESgateSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESsourceNode != 0) && (here->MESsourcePrimeNode != 0))
            {
                i = here->MESsourceSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESsourceSourcePrimeBinding = matched ;
                here->MESsourceSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESdrainPrimeNode != 0) && (here->MESdrainNode != 0))
            {
                i = here->MESdrainPrimeDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESdrainPrimeDrainBinding = matched ;
                here->MESdrainPrimeDrainPtr = matched->CSC ;
            }

            if ((here->MESdrainPrimeNode != 0) && (here->MESgateNode != 0))
            {
                i = here->MESdrainPrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESdrainPrimeGateBinding = matched ;
                here->MESdrainPrimeGatePtr = matched->CSC ;
            }

            if ((here->MESdrainPrimeNode != 0) && (here->MESsourcePrimeNode != 0))
            {
                i = here->MESdrainPrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESdrainPrimeSourcePrimeBinding = matched ;
                here->MESdrainPrimeSourcePrimePtr = matched->CSC ;
            }

            if ((here->MESsourcePrimeNode != 0) && (here->MESgateNode != 0))
            {
                i = here->MESsourcePrimeGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESsourcePrimeGateBinding = matched ;
                here->MESsourcePrimeGatePtr = matched->CSC ;
            }

            if ((here->MESsourcePrimeNode != 0) && (here->MESsourceNode != 0))
            {
                i = here->MESsourcePrimeSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESsourcePrimeSourceBinding = matched ;
                here->MESsourcePrimeSourcePtr = matched->CSC ;
            }

            if ((here->MESsourcePrimeNode != 0) && (here->MESdrainPrimeNode != 0))
            {
                i = here->MESsourcePrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESsourcePrimeDrainPrimeBinding = matched ;
                here->MESsourcePrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESdrainNode != 0) && (here->MESdrainNode != 0))
            {
                i = here->MESdrainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESdrainDrainBinding = matched ;
                here->MESdrainDrainPtr = matched->CSC ;
            }

            if ((here->MESgateNode != 0) && (here->MESgateNode != 0))
            {
                i = here->MESgateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESgateGateBinding = matched ;
                here->MESgateGatePtr = matched->CSC ;
            }

            if ((here->MESsourceNode != 0) && (here->MESsourceNode != 0))
            {
                i = here->MESsourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESsourceSourceBinding = matched ;
                here->MESsourceSourcePtr = matched->CSC ;
            }

            if ((here->MESdrainPrimeNode != 0) && (here->MESdrainPrimeNode != 0))
            {
                i = here->MESdrainPrimeDrainPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESdrainPrimeDrainPrimeBinding = matched ;
                here->MESdrainPrimeDrainPrimePtr = matched->CSC ;
            }

            if ((here->MESsourcePrimeNode != 0) && (here->MESsourcePrimeNode != 0))
            {
                i = here->MESsourcePrimeSourcePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MESsourcePrimeSourcePrimeBinding = matched ;
                here->MESsourcePrimeSourcePrimePtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
MESbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MESmodel *model = (MESmodel *)inModel ;
    MESinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MES models */
    for ( ; model != NULL ; model = model->MESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MESinstances ; here != NULL ; here = here->MESnextInstance)
        {
            if ((here->MESdrainNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESdrainDrainPrimePtr = here->MESdrainDrainPrimeBinding->CSC_Complex ;

            if ((here->MESgateNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESgateDrainPrimePtr = here->MESgateDrainPrimeBinding->CSC_Complex ;

            if ((here->MESgateNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESgateSourcePrimePtr = here->MESgateSourcePrimeBinding->CSC_Complex ;

            if ((here->MESsourceNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESsourceSourcePrimePtr = here->MESsourceSourcePrimeBinding->CSC_Complex ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESdrainNode != 0))
                here->MESdrainPrimeDrainPtr = here->MESdrainPrimeDrainBinding->CSC_Complex ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESgateNode != 0))
                here->MESdrainPrimeGatePtr = here->MESdrainPrimeGateBinding->CSC_Complex ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESdrainPrimeSourcePrimePtr = here->MESdrainPrimeSourcePrimeBinding->CSC_Complex ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESgateNode != 0))
                here->MESsourcePrimeGatePtr = here->MESsourcePrimeGateBinding->CSC_Complex ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESsourceNode != 0))
                here->MESsourcePrimeSourcePtr = here->MESsourcePrimeSourceBinding->CSC_Complex ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESsourcePrimeDrainPrimePtr = here->MESsourcePrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->MESdrainNode != 0) && (here->MESdrainNode != 0))
                here->MESdrainDrainPtr = here->MESdrainDrainBinding->CSC_Complex ;

            if ((here->MESgateNode != 0) && (here->MESgateNode != 0))
                here->MESgateGatePtr = here->MESgateGateBinding->CSC_Complex ;

            if ((here->MESsourceNode != 0) && (here->MESsourceNode != 0))
                here->MESsourceSourcePtr = here->MESsourceSourceBinding->CSC_Complex ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESdrainPrimeDrainPrimePtr = here->MESdrainPrimeDrainPrimeBinding->CSC_Complex ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESsourcePrimeSourcePrimePtr = here->MESsourcePrimeSourcePrimeBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
MESbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MESmodel *model = (MESmodel *)inModel ;
    MESinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MES models */
    for ( ; model != NULL ; model = model->MESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MESinstances ; here != NULL ; here = here->MESnextInstance)
        {
            if ((here->MESdrainNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESdrainDrainPrimePtr = here->MESdrainDrainPrimeBinding->CSC ;

            if ((here->MESgateNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESgateDrainPrimePtr = here->MESgateDrainPrimeBinding->CSC ;

            if ((here->MESgateNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESgateSourcePrimePtr = here->MESgateSourcePrimeBinding->CSC ;

            if ((here->MESsourceNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESsourceSourcePrimePtr = here->MESsourceSourcePrimeBinding->CSC ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESdrainNode != 0))
                here->MESdrainPrimeDrainPtr = here->MESdrainPrimeDrainBinding->CSC ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESgateNode != 0))
                here->MESdrainPrimeGatePtr = here->MESdrainPrimeGateBinding->CSC ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESdrainPrimeSourcePrimePtr = here->MESdrainPrimeSourcePrimeBinding->CSC ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESgateNode != 0))
                here->MESsourcePrimeGatePtr = here->MESsourcePrimeGateBinding->CSC ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESsourceNode != 0))
                here->MESsourcePrimeSourcePtr = here->MESsourcePrimeSourceBinding->CSC ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESsourcePrimeDrainPrimePtr = here->MESsourcePrimeDrainPrimeBinding->CSC ;

            if ((here->MESdrainNode != 0) && (here->MESdrainNode != 0))
                here->MESdrainDrainPtr = here->MESdrainDrainBinding->CSC ;

            if ((here->MESgateNode != 0) && (here->MESgateNode != 0))
                here->MESgateGatePtr = here->MESgateGateBinding->CSC ;

            if ((here->MESsourceNode != 0) && (here->MESsourceNode != 0))
                here->MESsourceSourcePtr = here->MESsourceSourceBinding->CSC ;

            if ((here->MESdrainPrimeNode != 0) && (here->MESdrainPrimeNode != 0))
                here->MESdrainPrimeDrainPrimePtr = here->MESdrainPrimeDrainPrimeBinding->CSC ;

            if ((here->MESsourcePrimeNode != 0) && (here->MESsourcePrimeNode != 0))
                here->MESsourcePrimeSourcePrimePtr = here->MESsourcePrimeSourcePrimeBinding->CSC ;

        }
    }

    return (OK) ;
}
