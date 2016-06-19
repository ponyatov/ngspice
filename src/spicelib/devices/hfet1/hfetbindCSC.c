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
            XFOO(HFETAdrainDrainPrimePtr, HFETAdrainDrainPrimeBinding, HFETAdrainNode, HFETAdrainPrimeNode);
            XFOO(HFETAgatePrimeDrainPrimePtr, HFETAgatePrimeDrainPrimeBinding, HFETAgatePrimeNode, HFETAdrainPrimeNode);
            XFOO(HFETAgatePrimeSourcePrimePtr, HFETAgatePrimeSourcePrimeBinding, HFETAgatePrimeNode, HFETAsourcePrimeNode);
            XFOO(HFETAsourceSourcePrimePtr, HFETAsourceSourcePrimeBinding, HFETAsourceNode, HFETAsourcePrimeNode);
            XFOO(HFETAdrainPrimeDrainPtr, HFETAdrainPrimeDrainBinding, HFETAdrainPrimeNode, HFETAdrainNode);
            XFOO(HFETAdrainPrimeGatePrimePtr, HFETAdrainPrimeGatePrimeBinding, HFETAdrainPrimeNode, HFETAgatePrimeNode);
            XFOO(HFETAdrainPrimeSourcePrimePtr, HFETAdrainPrimeSourcePrimeBinding, HFETAdrainPrimeNode, HFETAsourcePrimeNode);
            XFOO(HFETAsourcePrimeGatePrimePtr, HFETAsourcePrimeGatePrimeBinding, HFETAsourcePrimeNode, HFETAgatePrimeNode);
            XFOO(HFETAsourcePrimeSourcePtr, HFETAsourcePrimeSourceBinding, HFETAsourcePrimeNode, HFETAsourceNode);
            XFOO(HFETAsourcePrimeDrainPrimePtr, HFETAsourcePrimeDrainPrimeBinding, HFETAsourcePrimeNode, HFETAdrainPrimeNode);
            XFOO(HFETAdrainDrainPtr, HFETAdrainDrainBinding, HFETAdrainNode, HFETAdrainNode);
            XFOO(HFETAgatePrimeGatePrimePtr, HFETAgatePrimeGatePrimeBinding, HFETAgatePrimeNode, HFETAgatePrimeNode);
            XFOO(HFETAsourceSourcePtr, HFETAsourceSourceBinding, HFETAsourceNode, HFETAsourceNode);
            XFOO(HFETAdrainPrimeDrainPrimePtr, HFETAdrainPrimeDrainPrimeBinding, HFETAdrainPrimeNode, HFETAdrainPrimeNode);
            XFOO(HFETAsourcePrimeSourcePrimePtr, HFETAsourcePrimeSourcePrimeBinding, HFETAsourcePrimeNode, HFETAsourcePrimeNode);
            XFOO(HFETAdrainPrimeDrainPrmPrmPtr, HFETAdrainPrimeDrainPrmPrmBinding, HFETAdrainPrimeNode, HFETAdrainPrmPrmNode);
            XFOO(HFETAdrainPrmPrmDrainPrimePtr, HFETAdrainPrmPrmDrainPrimeBinding, HFETAdrainPrmPrmNode, HFETAdrainPrimeNode);
            XFOO(HFETAdrainPrmPrmGatePrimePtr, HFETAdrainPrmPrmGatePrimeBinding, HFETAdrainPrmPrmNode, HFETAgatePrimeNode);
            XFOO(HFETAgatePrimeDrainPrmPrmPtr, HFETAgatePrimeDrainPrmPrmBinding, HFETAgatePrimeNode, HFETAdrainPrmPrmNode);
            XFOO(HFETAdrainPrmPrmDrainPrmPrmPtr, HFETAdrainPrmPrmDrainPrmPrmBinding, HFETAdrainPrmPrmNode, HFETAdrainPrmPrmNode);
            XFOO(HFETAsourcePrimeSourcePrmPrmPtr, HFETAsourcePrimeSourcePrmPrmBinding, HFETAsourcePrimeNode, HFETAsourcePrmPrmNode);
            XFOO(HFETAsourcePrmPrmSourcePrimePtr, HFETAsourcePrmPrmSourcePrimeBinding, HFETAsourcePrmPrmNode, HFETAsourcePrimeNode);
            XFOO(HFETAsourcePrmPrmGatePrimePtr, HFETAsourcePrmPrmGatePrimeBinding, HFETAsourcePrmPrmNode, HFETAgatePrimeNode);
            XFOO(HFETAgatePrimeSourcePrmPrmPtr, HFETAgatePrimeSourcePrmPrmBinding, HFETAgatePrimeNode, HFETAsourcePrmPrmNode);
            XFOO(HFETAsourcePrmPrmSourcePrmPrmPtr, HFETAsourcePrmPrmSourcePrmPrmBinding, HFETAsourcePrmPrmNode, HFETAsourcePrmPrmNode);
            XFOO(HFETAgateGatePtr, HFETAgateGateBinding, HFETAgateNode, HFETAgateNode);
            XFOO(HFETAgateGatePrimePtr, HFETAgateGatePrimeBinding, HFETAgateNode, HFETAgatePrimeNode);
            XFOO(HFETAgatePrimeGatePtr, HFETAgatePrimeGateBinding, HFETAgatePrimeNode, HFETAgateNode);
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
            BFOO(HFETAdrainDrainPrimePtr, HFETAdrainDrainPrimeBinding, HFETAdrainNode, HFETAdrainPrimeNode);
            BFOO(HFETAgatePrimeDrainPrimePtr, HFETAgatePrimeDrainPrimeBinding, HFETAgatePrimeNode, HFETAdrainPrimeNode);
            BFOO(HFETAgatePrimeSourcePrimePtr, HFETAgatePrimeSourcePrimeBinding, HFETAgatePrimeNode, HFETAsourcePrimeNode);
            BFOO(HFETAsourceSourcePrimePtr, HFETAsourceSourcePrimeBinding, HFETAsourceNode, HFETAsourcePrimeNode);
            BFOO(HFETAdrainPrimeDrainPtr, HFETAdrainPrimeDrainBinding, HFETAdrainPrimeNode, HFETAdrainNode);
            BFOO(HFETAdrainPrimeGatePrimePtr, HFETAdrainPrimeGatePrimeBinding, HFETAdrainPrimeNode, HFETAgatePrimeNode);
            BFOO(HFETAdrainPrimeSourcePrimePtr, HFETAdrainPrimeSourcePrimeBinding, HFETAdrainPrimeNode, HFETAsourcePrimeNode);
            BFOO(HFETAsourcePrimeGatePrimePtr, HFETAsourcePrimeGatePrimeBinding, HFETAsourcePrimeNode, HFETAgatePrimeNode);
            BFOO(HFETAsourcePrimeSourcePtr, HFETAsourcePrimeSourceBinding, HFETAsourcePrimeNode, HFETAsourceNode);
            BFOO(HFETAsourcePrimeDrainPrimePtr, HFETAsourcePrimeDrainPrimeBinding, HFETAsourcePrimeNode, HFETAdrainPrimeNode);
            BFOO(HFETAdrainDrainPtr, HFETAdrainDrainBinding, HFETAdrainNode, HFETAdrainNode);
            BFOO(HFETAgatePrimeGatePrimePtr, HFETAgatePrimeGatePrimeBinding, HFETAgatePrimeNode, HFETAgatePrimeNode);
            BFOO(HFETAsourceSourcePtr, HFETAsourceSourceBinding, HFETAsourceNode, HFETAsourceNode);
            BFOO(HFETAdrainPrimeDrainPrimePtr, HFETAdrainPrimeDrainPrimeBinding, HFETAdrainPrimeNode, HFETAdrainPrimeNode);
            BFOO(HFETAsourcePrimeSourcePrimePtr, HFETAsourcePrimeSourcePrimeBinding, HFETAsourcePrimeNode, HFETAsourcePrimeNode);
            BFOO(HFETAdrainPrimeDrainPrmPrmPtr, HFETAdrainPrimeDrainPrmPrmBinding, HFETAdrainPrimeNode, HFETAdrainPrmPrmNode);
            BFOO(HFETAdrainPrmPrmDrainPrimePtr, HFETAdrainPrmPrmDrainPrimeBinding, HFETAdrainPrmPrmNode, HFETAdrainPrimeNode);
            BFOO(HFETAdrainPrmPrmGatePrimePtr, HFETAdrainPrmPrmGatePrimeBinding, HFETAdrainPrmPrmNode, HFETAgatePrimeNode);
            BFOO(HFETAgatePrimeDrainPrmPrmPtr, HFETAgatePrimeDrainPrmPrmBinding, HFETAgatePrimeNode, HFETAdrainPrmPrmNode);
            BFOO(HFETAdrainPrmPrmDrainPrmPrmPtr, HFETAdrainPrmPrmDrainPrmPrmBinding, HFETAdrainPrmPrmNode, HFETAdrainPrmPrmNode);
            BFOO(HFETAsourcePrimeSourcePrmPrmPtr, HFETAsourcePrimeSourcePrmPrmBinding, HFETAsourcePrimeNode, HFETAsourcePrmPrmNode);
            BFOO(HFETAsourcePrmPrmSourcePrimePtr, HFETAsourcePrmPrmSourcePrimeBinding, HFETAsourcePrmPrmNode, HFETAsourcePrimeNode);
            BFOO(HFETAsourcePrmPrmGatePrimePtr, HFETAsourcePrmPrmGatePrimeBinding, HFETAsourcePrmPrmNode, HFETAgatePrimeNode);
            BFOO(HFETAgatePrimeSourcePrmPrmPtr, HFETAgatePrimeSourcePrmPrmBinding, HFETAgatePrimeNode, HFETAsourcePrmPrmNode);
            BFOO(HFETAsourcePrmPrmSourcePrmPrmPtr, HFETAsourcePrmPrmSourcePrmPrmBinding, HFETAsourcePrmPrmNode, HFETAsourcePrmPrmNode);
            BFOO(HFETAgateGatePtr, HFETAgateGateBinding, HFETAgateNode, HFETAgateNode);
            BFOO(HFETAgateGatePrimePtr, HFETAgateGatePrimeBinding, HFETAgateNode, HFETAgatePrimeNode);
            BFOO(HFETAgatePrimeGatePtr, HFETAgatePrimeGateBinding, HFETAgatePrimeNode, HFETAgateNode);
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
            CFOO(HFETAdrainDrainPrimePtr, HFETAdrainDrainPrimeBinding, HFETAdrainNode, HFETAdrainPrimeNode);
            CFOO(HFETAgatePrimeDrainPrimePtr, HFETAgatePrimeDrainPrimeBinding, HFETAgatePrimeNode, HFETAdrainPrimeNode);
            CFOO(HFETAgatePrimeSourcePrimePtr, HFETAgatePrimeSourcePrimeBinding, HFETAgatePrimeNode, HFETAsourcePrimeNode);
            CFOO(HFETAsourceSourcePrimePtr, HFETAsourceSourcePrimeBinding, HFETAsourceNode, HFETAsourcePrimeNode);
            CFOO(HFETAdrainPrimeDrainPtr, HFETAdrainPrimeDrainBinding, HFETAdrainPrimeNode, HFETAdrainNode);
            CFOO(HFETAdrainPrimeGatePrimePtr, HFETAdrainPrimeGatePrimeBinding, HFETAdrainPrimeNode, HFETAgatePrimeNode);
            CFOO(HFETAdrainPrimeSourcePrimePtr, HFETAdrainPrimeSourcePrimeBinding, HFETAdrainPrimeNode, HFETAsourcePrimeNode);
            CFOO(HFETAsourcePrimeGatePrimePtr, HFETAsourcePrimeGatePrimeBinding, HFETAsourcePrimeNode, HFETAgatePrimeNode);
            CFOO(HFETAsourcePrimeSourcePtr, HFETAsourcePrimeSourceBinding, HFETAsourcePrimeNode, HFETAsourceNode);
            CFOO(HFETAsourcePrimeDrainPrimePtr, HFETAsourcePrimeDrainPrimeBinding, HFETAsourcePrimeNode, HFETAdrainPrimeNode);
            CFOO(HFETAdrainDrainPtr, HFETAdrainDrainBinding, HFETAdrainNode, HFETAdrainNode);
            CFOO(HFETAgatePrimeGatePrimePtr, HFETAgatePrimeGatePrimeBinding, HFETAgatePrimeNode, HFETAgatePrimeNode);
            CFOO(HFETAsourceSourcePtr, HFETAsourceSourceBinding, HFETAsourceNode, HFETAsourceNode);
            CFOO(HFETAdrainPrimeDrainPrimePtr, HFETAdrainPrimeDrainPrimeBinding, HFETAdrainPrimeNode, HFETAdrainPrimeNode);
            CFOO(HFETAsourcePrimeSourcePrimePtr, HFETAsourcePrimeSourcePrimeBinding, HFETAsourcePrimeNode, HFETAsourcePrimeNode);
            CFOO(HFETAdrainPrimeDrainPrmPrmPtr, HFETAdrainPrimeDrainPrmPrmBinding, HFETAdrainPrimeNode, HFETAdrainPrmPrmNode);
            CFOO(HFETAdrainPrmPrmDrainPrimePtr, HFETAdrainPrmPrmDrainPrimeBinding, HFETAdrainPrmPrmNode, HFETAdrainPrimeNode);
            CFOO(HFETAdrainPrmPrmGatePrimePtr, HFETAdrainPrmPrmGatePrimeBinding, HFETAdrainPrmPrmNode, HFETAgatePrimeNode);
            CFOO(HFETAgatePrimeDrainPrmPrmPtr, HFETAgatePrimeDrainPrmPrmBinding, HFETAgatePrimeNode, HFETAdrainPrmPrmNode);
            CFOO(HFETAdrainPrmPrmDrainPrmPrmPtr, HFETAdrainPrmPrmDrainPrmPrmBinding, HFETAdrainPrmPrmNode, HFETAdrainPrmPrmNode);
            CFOO(HFETAsourcePrimeSourcePrmPrmPtr, HFETAsourcePrimeSourcePrmPrmBinding, HFETAsourcePrimeNode, HFETAsourcePrmPrmNode);
            CFOO(HFETAsourcePrmPrmSourcePrimePtr, HFETAsourcePrmPrmSourcePrimeBinding, HFETAsourcePrmPrmNode, HFETAsourcePrimeNode);
            CFOO(HFETAsourcePrmPrmGatePrimePtr, HFETAsourcePrmPrmGatePrimeBinding, HFETAsourcePrmPrmNode, HFETAgatePrimeNode);
            CFOO(HFETAgatePrimeSourcePrmPrmPtr, HFETAgatePrimeSourcePrmPrmBinding, HFETAgatePrimeNode, HFETAsourcePrmPrmNode);
            CFOO(HFETAsourcePrmPrmSourcePrmPrmPtr, HFETAsourcePrmPrmSourcePrmPrmBinding, HFETAsourcePrmPrmNode, HFETAsourcePrmPrmNode);
            CFOO(HFETAgateGatePtr, HFETAgateGateBinding, HFETAgateNode, HFETAgateNode);
            CFOO(HFETAgateGatePrimePtr, HFETAgateGatePrimeBinding, HFETAgateNode, HFETAgatePrimeNode);
            CFOO(HFETAgatePrimeGatePtr, HFETAgatePrimeGateBinding, HFETAgatePrimeNode, HFETAgateNode);
        }
    }

    return (OK) ;
}
