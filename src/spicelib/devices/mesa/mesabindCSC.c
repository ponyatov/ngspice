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
            XFOO(MESAdrainDrainPtr, MESAdrainDrainBinding, MESAdrainNode, MESAdrainNode);
            XFOO(MESAdrainPrimeDrainPrimePtr, MESAdrainPrimeDrainPrimeBinding, MESAdrainPrimeNode, MESAdrainPrimeNode);
            XFOO(MESAdrainPrmPrmDrainPrmPrmPtr, MESAdrainPrmPrmDrainPrmPrmBinding, MESAdrainPrmPrmNode, MESAdrainPrmPrmNode);
            XFOO(MESAgateGatePtr, MESAgateGateBinding, MESAgateNode, MESAgateNode);
            XFOO(MESAgatePrimeGatePrimePtr, MESAgatePrimeGatePrimeBinding, MESAgatePrimeNode, MESAgatePrimeNode);
            XFOO(MESAsourceSourcePtr, MESAsourceSourceBinding, MESAsourceNode, MESAsourceNode);
            XFOO(MESAsourcePrimeSourcePrimePtr, MESAsourcePrimeSourcePrimeBinding, MESAsourcePrimeNode, MESAsourcePrimeNode);
            XFOO(MESAsourcePrmPrmSourcePrmPrmPtr, MESAsourcePrmPrmSourcePrmPrmBinding, MESAsourcePrmPrmNode, MESAsourcePrmPrmNode);
            XFOO(MESAdrainDrainPrimePtr, MESAdrainDrainPrimeBinding, MESAdrainNode, MESAdrainPrimeNode);
            XFOO(MESAdrainPrimeDrainPtr, MESAdrainPrimeDrainBinding, MESAdrainPrimeNode, MESAdrainNode);
            XFOO(MESAgatePrimeDrainPrimePtr, MESAgatePrimeDrainPrimeBinding, MESAgatePrimeNode, MESAdrainPrimeNode);
            XFOO(MESAdrainPrimeGatePrimePtr, MESAdrainPrimeGatePrimeBinding, MESAdrainPrimeNode, MESAgatePrimeNode);
            XFOO(MESAgatePrimeSourcePrimePtr, MESAgatePrimeSourcePrimeBinding, MESAgatePrimeNode, MESAsourcePrimeNode);
            XFOO(MESAsourcePrimeGatePrimePtr, MESAsourcePrimeGatePrimeBinding, MESAsourcePrimeNode, MESAgatePrimeNode);
            XFOO(MESAsourceSourcePrimePtr, MESAsourceSourcePrimeBinding, MESAsourceNode, MESAsourcePrimeNode);
            XFOO(MESAsourcePrimeSourcePtr, MESAsourcePrimeSourceBinding, MESAsourcePrimeNode, MESAsourceNode);
            XFOO(MESAdrainPrimeSourcePrimePtr, MESAdrainPrimeSourcePrimeBinding, MESAdrainPrimeNode, MESAsourcePrimeNode);
            XFOO(MESAsourcePrimeDrainPrimePtr, MESAsourcePrimeDrainPrimeBinding, MESAsourcePrimeNode, MESAdrainPrimeNode);
            XFOO(MESAgatePrimeGatePtr, MESAgatePrimeGateBinding, MESAgatePrimeNode, MESAgateNode);
            XFOO(MESAgateGatePrimePtr, MESAgateGatePrimeBinding, MESAgateNode, MESAgatePrimeNode);
            XFOO(MESAsourcePrmPrmSourcePrimePtr, MESAsourcePrmPrmSourcePrimeBinding, MESAsourcePrmPrmNode, MESAsourcePrimeNode);
            XFOO(MESAsourcePrimeSourcePrmPrmPtr, MESAsourcePrimeSourcePrmPrmBinding, MESAsourcePrimeNode, MESAsourcePrmPrmNode);
            XFOO(MESAsourcePrmPrmGatePrimePtr, MESAsourcePrmPrmGatePrimeBinding, MESAsourcePrmPrmNode, MESAgatePrimeNode);
            XFOO(MESAgatePrimeSourcePrmPrmPtr, MESAgatePrimeSourcePrmPrmBinding, MESAgatePrimeNode, MESAsourcePrmPrmNode);
            XFOO(MESAdrainPrmPrmDrainPrimePtr, MESAdrainPrmPrmDrainPrimeBinding, MESAdrainPrmPrmNode, MESAdrainPrimeNode);
            XFOO(MESAdrainPrimeDrainPrmPrmPtr, MESAdrainPrimeDrainPrmPrmBinding, MESAdrainPrimeNode, MESAdrainPrmPrmNode);
            XFOO(MESAdrainPrmPrmGatePrimePtr, MESAdrainPrmPrmGatePrimeBinding, MESAdrainPrmPrmNode, MESAgatePrimeNode);
            XFOO(MESAgatePrimeDrainPrmPrmPtr, MESAgatePrimeDrainPrmPrmBinding, MESAgatePrimeNode, MESAdrainPrmPrmNode);
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
            BFOO(MESAdrainDrainPtr, MESAdrainDrainBinding, MESAdrainNode, MESAdrainNode);
            BFOO(MESAdrainPrimeDrainPrimePtr, MESAdrainPrimeDrainPrimeBinding, MESAdrainPrimeNode, MESAdrainPrimeNode);
            BFOO(MESAdrainPrmPrmDrainPrmPrmPtr, MESAdrainPrmPrmDrainPrmPrmBinding, MESAdrainPrmPrmNode, MESAdrainPrmPrmNode);
            BFOO(MESAgateGatePtr, MESAgateGateBinding, MESAgateNode, MESAgateNode);
            BFOO(MESAgatePrimeGatePrimePtr, MESAgatePrimeGatePrimeBinding, MESAgatePrimeNode, MESAgatePrimeNode);
            BFOO(MESAsourceSourcePtr, MESAsourceSourceBinding, MESAsourceNode, MESAsourceNode);
            BFOO(MESAsourcePrimeSourcePrimePtr, MESAsourcePrimeSourcePrimeBinding, MESAsourcePrimeNode, MESAsourcePrimeNode);
            BFOO(MESAsourcePrmPrmSourcePrmPrmPtr, MESAsourcePrmPrmSourcePrmPrmBinding, MESAsourcePrmPrmNode, MESAsourcePrmPrmNode);
            BFOO(MESAdrainDrainPrimePtr, MESAdrainDrainPrimeBinding, MESAdrainNode, MESAdrainPrimeNode);
            BFOO(MESAdrainPrimeDrainPtr, MESAdrainPrimeDrainBinding, MESAdrainPrimeNode, MESAdrainNode);
            BFOO(MESAgatePrimeDrainPrimePtr, MESAgatePrimeDrainPrimeBinding, MESAgatePrimeNode, MESAdrainPrimeNode);
            BFOO(MESAdrainPrimeGatePrimePtr, MESAdrainPrimeGatePrimeBinding, MESAdrainPrimeNode, MESAgatePrimeNode);
            BFOO(MESAgatePrimeSourcePrimePtr, MESAgatePrimeSourcePrimeBinding, MESAgatePrimeNode, MESAsourcePrimeNode);
            BFOO(MESAsourcePrimeGatePrimePtr, MESAsourcePrimeGatePrimeBinding, MESAsourcePrimeNode, MESAgatePrimeNode);
            BFOO(MESAsourceSourcePrimePtr, MESAsourceSourcePrimeBinding, MESAsourceNode, MESAsourcePrimeNode);
            BFOO(MESAsourcePrimeSourcePtr, MESAsourcePrimeSourceBinding, MESAsourcePrimeNode, MESAsourceNode);
            BFOO(MESAdrainPrimeSourcePrimePtr, MESAdrainPrimeSourcePrimeBinding, MESAdrainPrimeNode, MESAsourcePrimeNode);
            BFOO(MESAsourcePrimeDrainPrimePtr, MESAsourcePrimeDrainPrimeBinding, MESAsourcePrimeNode, MESAdrainPrimeNode);
            BFOO(MESAgatePrimeGatePtr, MESAgatePrimeGateBinding, MESAgatePrimeNode, MESAgateNode);
            BFOO(MESAgateGatePrimePtr, MESAgateGatePrimeBinding, MESAgateNode, MESAgatePrimeNode);
            BFOO(MESAsourcePrmPrmSourcePrimePtr, MESAsourcePrmPrmSourcePrimeBinding, MESAsourcePrmPrmNode, MESAsourcePrimeNode);
            BFOO(MESAsourcePrimeSourcePrmPrmPtr, MESAsourcePrimeSourcePrmPrmBinding, MESAsourcePrimeNode, MESAsourcePrmPrmNode);
            BFOO(MESAsourcePrmPrmGatePrimePtr, MESAsourcePrmPrmGatePrimeBinding, MESAsourcePrmPrmNode, MESAgatePrimeNode);
            BFOO(MESAgatePrimeSourcePrmPrmPtr, MESAgatePrimeSourcePrmPrmBinding, MESAgatePrimeNode, MESAsourcePrmPrmNode);
            BFOO(MESAdrainPrmPrmDrainPrimePtr, MESAdrainPrmPrmDrainPrimeBinding, MESAdrainPrmPrmNode, MESAdrainPrimeNode);
            BFOO(MESAdrainPrimeDrainPrmPrmPtr, MESAdrainPrimeDrainPrmPrmBinding, MESAdrainPrimeNode, MESAdrainPrmPrmNode);
            BFOO(MESAdrainPrmPrmGatePrimePtr, MESAdrainPrmPrmGatePrimeBinding, MESAdrainPrmPrmNode, MESAgatePrimeNode);
            BFOO(MESAgatePrimeDrainPrmPrmPtr, MESAgatePrimeDrainPrmPrmBinding, MESAgatePrimeNode, MESAdrainPrmPrmNode);
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
            CFOO(MESAdrainDrainPtr, MESAdrainDrainBinding, MESAdrainNode, MESAdrainNode);
            CFOO(MESAdrainPrimeDrainPrimePtr, MESAdrainPrimeDrainPrimeBinding, MESAdrainPrimeNode, MESAdrainPrimeNode);
            CFOO(MESAdrainPrmPrmDrainPrmPrmPtr, MESAdrainPrmPrmDrainPrmPrmBinding, MESAdrainPrmPrmNode, MESAdrainPrmPrmNode);
            CFOO(MESAgateGatePtr, MESAgateGateBinding, MESAgateNode, MESAgateNode);
            CFOO(MESAgatePrimeGatePrimePtr, MESAgatePrimeGatePrimeBinding, MESAgatePrimeNode, MESAgatePrimeNode);
            CFOO(MESAsourceSourcePtr, MESAsourceSourceBinding, MESAsourceNode, MESAsourceNode);
            CFOO(MESAsourcePrimeSourcePrimePtr, MESAsourcePrimeSourcePrimeBinding, MESAsourcePrimeNode, MESAsourcePrimeNode);
            CFOO(MESAsourcePrmPrmSourcePrmPrmPtr, MESAsourcePrmPrmSourcePrmPrmBinding, MESAsourcePrmPrmNode, MESAsourcePrmPrmNode);
            CFOO(MESAdrainDrainPrimePtr, MESAdrainDrainPrimeBinding, MESAdrainNode, MESAdrainPrimeNode);
            CFOO(MESAdrainPrimeDrainPtr, MESAdrainPrimeDrainBinding, MESAdrainPrimeNode, MESAdrainNode);
            CFOO(MESAgatePrimeDrainPrimePtr, MESAgatePrimeDrainPrimeBinding, MESAgatePrimeNode, MESAdrainPrimeNode);
            CFOO(MESAdrainPrimeGatePrimePtr, MESAdrainPrimeGatePrimeBinding, MESAdrainPrimeNode, MESAgatePrimeNode);
            CFOO(MESAgatePrimeSourcePrimePtr, MESAgatePrimeSourcePrimeBinding, MESAgatePrimeNode, MESAsourcePrimeNode);
            CFOO(MESAsourcePrimeGatePrimePtr, MESAsourcePrimeGatePrimeBinding, MESAsourcePrimeNode, MESAgatePrimeNode);
            CFOO(MESAsourceSourcePrimePtr, MESAsourceSourcePrimeBinding, MESAsourceNode, MESAsourcePrimeNode);
            CFOO(MESAsourcePrimeSourcePtr, MESAsourcePrimeSourceBinding, MESAsourcePrimeNode, MESAsourceNode);
            CFOO(MESAdrainPrimeSourcePrimePtr, MESAdrainPrimeSourcePrimeBinding, MESAdrainPrimeNode, MESAsourcePrimeNode);
            CFOO(MESAsourcePrimeDrainPrimePtr, MESAsourcePrimeDrainPrimeBinding, MESAsourcePrimeNode, MESAdrainPrimeNode);
            CFOO(MESAgatePrimeGatePtr, MESAgatePrimeGateBinding, MESAgatePrimeNode, MESAgateNode);
            CFOO(MESAgateGatePrimePtr, MESAgateGatePrimeBinding, MESAgateNode, MESAgatePrimeNode);
            CFOO(MESAsourcePrmPrmSourcePrimePtr, MESAsourcePrmPrmSourcePrimeBinding, MESAsourcePrmPrmNode, MESAsourcePrimeNode);
            CFOO(MESAsourcePrimeSourcePrmPrmPtr, MESAsourcePrimeSourcePrmPrmBinding, MESAsourcePrimeNode, MESAsourcePrmPrmNode);
            CFOO(MESAsourcePrmPrmGatePrimePtr, MESAsourcePrmPrmGatePrimeBinding, MESAsourcePrmPrmNode, MESAgatePrimeNode);
            CFOO(MESAgatePrimeSourcePrmPrmPtr, MESAgatePrimeSourcePrmPrmBinding, MESAgatePrimeNode, MESAsourcePrmPrmNode);
            CFOO(MESAdrainPrmPrmDrainPrimePtr, MESAdrainPrmPrmDrainPrimeBinding, MESAdrainPrmPrmNode, MESAdrainPrimeNode);
            CFOO(MESAdrainPrimeDrainPrmPrmPtr, MESAdrainPrimeDrainPrmPrmBinding, MESAdrainPrimeNode, MESAdrainPrmPrmNode);
            CFOO(MESAdrainPrmPrmGatePrimePtr, MESAdrainPrmPrmGatePrimeBinding, MESAdrainPrmPrmNode, MESAgatePrimeNode);
            CFOO(MESAgatePrimeDrainPrmPrmPtr, MESAgatePrimeDrainPrmPrmBinding, MESAgatePrimeNode, MESAdrainPrmPrmNode);
        }
    }

    return (OK) ;
}
