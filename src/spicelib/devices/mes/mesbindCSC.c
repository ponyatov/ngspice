/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mesdefs.h"
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
            XFOO(MESdrainDrainPrimePtr, MESdrainDrainPrimeBinding, MESdrainNode, MESdrainPrimeNode);
            XFOO(MESgateDrainPrimePtr, MESgateDrainPrimeBinding, MESgateNode, MESdrainPrimeNode);
            XFOO(MESgateSourcePrimePtr, MESgateSourcePrimeBinding, MESgateNode, MESsourcePrimeNode);
            XFOO(MESsourceSourcePrimePtr, MESsourceSourcePrimeBinding, MESsourceNode, MESsourcePrimeNode);
            XFOO(MESdrainPrimeDrainPtr, MESdrainPrimeDrainBinding, MESdrainPrimeNode, MESdrainNode);
            XFOO(MESdrainPrimeGatePtr, MESdrainPrimeGateBinding, MESdrainPrimeNode, MESgateNode);
            XFOO(MESdrainPrimeSourcePrimePtr, MESdrainPrimeSourcePrimeBinding, MESdrainPrimeNode, MESsourcePrimeNode);
            XFOO(MESsourcePrimeGatePtr, MESsourcePrimeGateBinding, MESsourcePrimeNode, MESgateNode);
            XFOO(MESsourcePrimeSourcePtr, MESsourcePrimeSourceBinding, MESsourcePrimeNode, MESsourceNode);
            XFOO(MESsourcePrimeDrainPrimePtr, MESsourcePrimeDrainPrimeBinding, MESsourcePrimeNode, MESdrainPrimeNode);
            XFOO(MESdrainDrainPtr, MESdrainDrainBinding, MESdrainNode, MESdrainNode);
            XFOO(MESgateGatePtr, MESgateGateBinding, MESgateNode, MESgateNode);
            XFOO(MESsourceSourcePtr, MESsourceSourceBinding, MESsourceNode, MESsourceNode);
            XFOO(MESdrainPrimeDrainPrimePtr, MESdrainPrimeDrainPrimeBinding, MESdrainPrimeNode, MESdrainPrimeNode);
            XFOO(MESsourcePrimeSourcePrimePtr, MESsourcePrimeSourcePrimeBinding, MESsourcePrimeNode, MESsourcePrimeNode);
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
            BFOO(MESdrainDrainPrimePtr, MESdrainDrainPrimeBinding, MESdrainNode, MESdrainPrimeNode);
            BFOO(MESgateDrainPrimePtr, MESgateDrainPrimeBinding, MESgateNode, MESdrainPrimeNode);
            BFOO(MESgateSourcePrimePtr, MESgateSourcePrimeBinding, MESgateNode, MESsourcePrimeNode);
            BFOO(MESsourceSourcePrimePtr, MESsourceSourcePrimeBinding, MESsourceNode, MESsourcePrimeNode);
            BFOO(MESdrainPrimeDrainPtr, MESdrainPrimeDrainBinding, MESdrainPrimeNode, MESdrainNode);
            BFOO(MESdrainPrimeGatePtr, MESdrainPrimeGateBinding, MESdrainPrimeNode, MESgateNode);
            BFOO(MESdrainPrimeSourcePrimePtr, MESdrainPrimeSourcePrimeBinding, MESdrainPrimeNode, MESsourcePrimeNode);
            BFOO(MESsourcePrimeGatePtr, MESsourcePrimeGateBinding, MESsourcePrimeNode, MESgateNode);
            BFOO(MESsourcePrimeSourcePtr, MESsourcePrimeSourceBinding, MESsourcePrimeNode, MESsourceNode);
            BFOO(MESsourcePrimeDrainPrimePtr, MESsourcePrimeDrainPrimeBinding, MESsourcePrimeNode, MESdrainPrimeNode);
            BFOO(MESdrainDrainPtr, MESdrainDrainBinding, MESdrainNode, MESdrainNode);
            BFOO(MESgateGatePtr, MESgateGateBinding, MESgateNode, MESgateNode);
            BFOO(MESsourceSourcePtr, MESsourceSourceBinding, MESsourceNode, MESsourceNode);
            BFOO(MESdrainPrimeDrainPrimePtr, MESdrainPrimeDrainPrimeBinding, MESdrainPrimeNode, MESdrainPrimeNode);
            BFOO(MESsourcePrimeSourcePrimePtr, MESsourcePrimeSourcePrimeBinding, MESsourcePrimeNode, MESsourcePrimeNode);
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
            CFOO(MESdrainDrainPrimePtr, MESdrainDrainPrimeBinding, MESdrainNode, MESdrainPrimeNode);
            CFOO(MESgateDrainPrimePtr, MESgateDrainPrimeBinding, MESgateNode, MESdrainPrimeNode);
            CFOO(MESgateSourcePrimePtr, MESgateSourcePrimeBinding, MESgateNode, MESsourcePrimeNode);
            CFOO(MESsourceSourcePrimePtr, MESsourceSourcePrimeBinding, MESsourceNode, MESsourcePrimeNode);
            CFOO(MESdrainPrimeDrainPtr, MESdrainPrimeDrainBinding, MESdrainPrimeNode, MESdrainNode);
            CFOO(MESdrainPrimeGatePtr, MESdrainPrimeGateBinding, MESdrainPrimeNode, MESgateNode);
            CFOO(MESdrainPrimeSourcePrimePtr, MESdrainPrimeSourcePrimeBinding, MESdrainPrimeNode, MESsourcePrimeNode);
            CFOO(MESsourcePrimeGatePtr, MESsourcePrimeGateBinding, MESsourcePrimeNode, MESgateNode);
            CFOO(MESsourcePrimeSourcePtr, MESsourcePrimeSourceBinding, MESsourcePrimeNode, MESsourceNode);
            CFOO(MESsourcePrimeDrainPrimePtr, MESsourcePrimeDrainPrimeBinding, MESsourcePrimeNode, MESdrainPrimeNode);
            CFOO(MESdrainDrainPtr, MESdrainDrainBinding, MESdrainNode, MESdrainNode);
            CFOO(MESgateGatePtr, MESgateGateBinding, MESgateNode, MESgateNode);
            CFOO(MESsourceSourcePtr, MESsourceSourceBinding, MESsourceNode, MESsourceNode);
            CFOO(MESdrainPrimeDrainPrimePtr, MESdrainPrimeDrainPrimeBinding, MESdrainPrimeNode, MESdrainPrimeNode);
            CFOO(MESsourcePrimeSourcePrimePtr, MESsourcePrimeSourcePrimeBinding, MESsourcePrimeNode, MESsourcePrimeNode);
        }
    }

    return (OK) ;
}
