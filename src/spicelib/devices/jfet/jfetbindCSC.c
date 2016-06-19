/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "jfetdefs.h"
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
            XFOO(JFETdrainDrainPrimePtr, JFETdrainDrainPrimeBinding, JFETdrainNode, JFETdrainPrimeNode);
            XFOO(JFETgateDrainPrimePtr, JFETgateDrainPrimeBinding, JFETgateNode, JFETdrainPrimeNode);
            XFOO(JFETgateSourcePrimePtr, JFETgateSourcePrimeBinding, JFETgateNode, JFETsourcePrimeNode);
            XFOO(JFETsourceSourcePrimePtr, JFETsourceSourcePrimeBinding, JFETsourceNode, JFETsourcePrimeNode);
            XFOO(JFETdrainPrimeDrainPtr, JFETdrainPrimeDrainBinding, JFETdrainPrimeNode, JFETdrainNode);
            XFOO(JFETdrainPrimeGatePtr, JFETdrainPrimeGateBinding, JFETdrainPrimeNode, JFETgateNode);
            XFOO(JFETdrainPrimeSourcePrimePtr, JFETdrainPrimeSourcePrimeBinding, JFETdrainPrimeNode, JFETsourcePrimeNode);
            XFOO(JFETsourcePrimeGatePtr, JFETsourcePrimeGateBinding, JFETsourcePrimeNode, JFETgateNode);
            XFOO(JFETsourcePrimeSourcePtr, JFETsourcePrimeSourceBinding, JFETsourcePrimeNode, JFETsourceNode);
            XFOO(JFETsourcePrimeDrainPrimePtr, JFETsourcePrimeDrainPrimeBinding, JFETsourcePrimeNode, JFETdrainPrimeNode);
            XFOO(JFETdrainDrainPtr, JFETdrainDrainBinding, JFETdrainNode, JFETdrainNode);
            XFOO(JFETgateGatePtr, JFETgateGateBinding, JFETgateNode, JFETgateNode);
            XFOO(JFETsourceSourcePtr, JFETsourceSourceBinding, JFETsourceNode, JFETsourceNode);
            XFOO(JFETdrainPrimeDrainPrimePtr, JFETdrainPrimeDrainPrimeBinding, JFETdrainPrimeNode, JFETdrainPrimeNode);
            XFOO(JFETsourcePrimeSourcePrimePtr, JFETsourcePrimeSourcePrimeBinding, JFETsourcePrimeNode, JFETsourcePrimeNode);
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
            BFOO(JFETdrainDrainPrimePtr, JFETdrainDrainPrimeBinding, JFETdrainNode, JFETdrainPrimeNode);
            BFOO(JFETgateDrainPrimePtr, JFETgateDrainPrimeBinding, JFETgateNode, JFETdrainPrimeNode);
            BFOO(JFETgateSourcePrimePtr, JFETgateSourcePrimeBinding, JFETgateNode, JFETsourcePrimeNode);
            BFOO(JFETsourceSourcePrimePtr, JFETsourceSourcePrimeBinding, JFETsourceNode, JFETsourcePrimeNode);
            BFOO(JFETdrainPrimeDrainPtr, JFETdrainPrimeDrainBinding, JFETdrainPrimeNode, JFETdrainNode);
            BFOO(JFETdrainPrimeGatePtr, JFETdrainPrimeGateBinding, JFETdrainPrimeNode, JFETgateNode);
            BFOO(JFETdrainPrimeSourcePrimePtr, JFETdrainPrimeSourcePrimeBinding, JFETdrainPrimeNode, JFETsourcePrimeNode);
            BFOO(JFETsourcePrimeGatePtr, JFETsourcePrimeGateBinding, JFETsourcePrimeNode, JFETgateNode);
            BFOO(JFETsourcePrimeSourcePtr, JFETsourcePrimeSourceBinding, JFETsourcePrimeNode, JFETsourceNode);
            BFOO(JFETsourcePrimeDrainPrimePtr, JFETsourcePrimeDrainPrimeBinding, JFETsourcePrimeNode, JFETdrainPrimeNode);
            BFOO(JFETdrainDrainPtr, JFETdrainDrainBinding, JFETdrainNode, JFETdrainNode);
            BFOO(JFETgateGatePtr, JFETgateGateBinding, JFETgateNode, JFETgateNode);
            BFOO(JFETsourceSourcePtr, JFETsourceSourceBinding, JFETsourceNode, JFETsourceNode);
            BFOO(JFETdrainPrimeDrainPrimePtr, JFETdrainPrimeDrainPrimeBinding, JFETdrainPrimeNode, JFETdrainPrimeNode);
            BFOO(JFETsourcePrimeSourcePrimePtr, JFETsourcePrimeSourcePrimeBinding, JFETsourcePrimeNode, JFETsourcePrimeNode);
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
            CFOO(JFETdrainDrainPrimePtr, JFETdrainDrainPrimeBinding, JFETdrainNode, JFETdrainPrimeNode);
            CFOO(JFETgateDrainPrimePtr, JFETgateDrainPrimeBinding, JFETgateNode, JFETdrainPrimeNode);
            CFOO(JFETgateSourcePrimePtr, JFETgateSourcePrimeBinding, JFETgateNode, JFETsourcePrimeNode);
            CFOO(JFETsourceSourcePrimePtr, JFETsourceSourcePrimeBinding, JFETsourceNode, JFETsourcePrimeNode);
            CFOO(JFETdrainPrimeDrainPtr, JFETdrainPrimeDrainBinding, JFETdrainPrimeNode, JFETdrainNode);
            CFOO(JFETdrainPrimeGatePtr, JFETdrainPrimeGateBinding, JFETdrainPrimeNode, JFETgateNode);
            CFOO(JFETdrainPrimeSourcePrimePtr, JFETdrainPrimeSourcePrimeBinding, JFETdrainPrimeNode, JFETsourcePrimeNode);
            CFOO(JFETsourcePrimeGatePtr, JFETsourcePrimeGateBinding, JFETsourcePrimeNode, JFETgateNode);
            CFOO(JFETsourcePrimeSourcePtr, JFETsourcePrimeSourceBinding, JFETsourcePrimeNode, JFETsourceNode);
            CFOO(JFETsourcePrimeDrainPrimePtr, JFETsourcePrimeDrainPrimeBinding, JFETsourcePrimeNode, JFETdrainPrimeNode);
            CFOO(JFETdrainDrainPtr, JFETdrainDrainBinding, JFETdrainNode, JFETdrainNode);
            CFOO(JFETgateGatePtr, JFETgateGateBinding, JFETgateNode, JFETgateNode);
            CFOO(JFETsourceSourcePtr, JFETsourceSourceBinding, JFETsourceNode, JFETsourceNode);
            CFOO(JFETdrainPrimeDrainPrimePtr, JFETdrainPrimeDrainPrimeBinding, JFETdrainPrimeNode, JFETdrainPrimeNode);
            CFOO(JFETsourcePrimeSourcePrimePtr, JFETsourcePrimeSourcePrimeBinding, JFETsourcePrimeNode, JFETsourcePrimeNode);
        }
    }

    return (OK) ;
}
