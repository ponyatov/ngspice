/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "numosdef.h"
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
NUMOSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMOSmodel *model = (NUMOSmodel *)inModel ;
    NUMOSinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the NUMOS models */
    for ( ; model != NULL ; model = model->NUMOSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMOSinstances ; here != NULL ; here = here->NUMOSnextInstance)
        {
            XFOO(NUMOSdrainDrainPtr, NUMOSdrainDrainBinding, NUMOSdrainNode, NUMOSdrainNode);
            XFOO(NUMOSdrainSourcePtr, NUMOSdrainSourceBinding, NUMOSdrainNode, NUMOSsourceNode);
            XFOO(NUMOSdrainGatePtr, NUMOSdrainGateBinding, NUMOSdrainNode, NUMOSgateNode);
            XFOO(NUMOSdrainBulkPtr, NUMOSdrainBulkBinding, NUMOSdrainNode, NUMOSbulkNode);
            XFOO(NUMOSsourceDrainPtr, NUMOSsourceDrainBinding, NUMOSsourceNode, NUMOSdrainNode);
            XFOO(NUMOSsourceSourcePtr, NUMOSsourceSourceBinding, NUMOSsourceNode, NUMOSsourceNode);
            XFOO(NUMOSsourceGatePtr, NUMOSsourceGateBinding, NUMOSsourceNode, NUMOSgateNode);
            XFOO(NUMOSsourceBulkPtr, NUMOSsourceBulkBinding, NUMOSsourceNode, NUMOSbulkNode);
            XFOO(NUMOSgateDrainPtr, NUMOSgateDrainBinding, NUMOSgateNode, NUMOSdrainNode);
            XFOO(NUMOSgateSourcePtr, NUMOSgateSourceBinding, NUMOSgateNode, NUMOSsourceNode);
            XFOO(NUMOSgateGatePtr, NUMOSgateGateBinding, NUMOSgateNode, NUMOSgateNode);
            XFOO(NUMOSgateBulkPtr, NUMOSgateBulkBinding, NUMOSgateNode, NUMOSbulkNode);
            XFOO(NUMOSbulkDrainPtr, NUMOSbulkDrainBinding, NUMOSbulkNode, NUMOSdrainNode);
            XFOO(NUMOSbulkSourcePtr, NUMOSbulkSourceBinding, NUMOSbulkNode, NUMOSsourceNode);
            XFOO(NUMOSbulkGatePtr, NUMOSbulkGateBinding, NUMOSbulkNode, NUMOSgateNode);
            XFOO(NUMOSbulkBulkPtr, NUMOSbulkBulkBinding, NUMOSbulkNode, NUMOSbulkNode);
        }
    }

    return (OK) ;
}

int
NUMOSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMOSmodel *model = (NUMOSmodel *)inModel ;
    NUMOSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMOS models */
    for ( ; model != NULL ; model = model->NUMOSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMOSinstances ; here != NULL ; here = here->NUMOSnextInstance)
        {
            BFOO(NUMOSdrainDrainPtr, NUMOSdrainDrainBinding, NUMOSdrainNode, NUMOSdrainNode);
            BFOO(NUMOSdrainSourcePtr, NUMOSdrainSourceBinding, NUMOSdrainNode, NUMOSsourceNode);
            BFOO(NUMOSdrainGatePtr, NUMOSdrainGateBinding, NUMOSdrainNode, NUMOSgateNode);
            BFOO(NUMOSdrainBulkPtr, NUMOSdrainBulkBinding, NUMOSdrainNode, NUMOSbulkNode);
            BFOO(NUMOSsourceDrainPtr, NUMOSsourceDrainBinding, NUMOSsourceNode, NUMOSdrainNode);
            BFOO(NUMOSsourceSourcePtr, NUMOSsourceSourceBinding, NUMOSsourceNode, NUMOSsourceNode);
            BFOO(NUMOSsourceGatePtr, NUMOSsourceGateBinding, NUMOSsourceNode, NUMOSgateNode);
            BFOO(NUMOSsourceBulkPtr, NUMOSsourceBulkBinding, NUMOSsourceNode, NUMOSbulkNode);
            BFOO(NUMOSgateDrainPtr, NUMOSgateDrainBinding, NUMOSgateNode, NUMOSdrainNode);
            BFOO(NUMOSgateSourcePtr, NUMOSgateSourceBinding, NUMOSgateNode, NUMOSsourceNode);
            BFOO(NUMOSgateGatePtr, NUMOSgateGateBinding, NUMOSgateNode, NUMOSgateNode);
            BFOO(NUMOSgateBulkPtr, NUMOSgateBulkBinding, NUMOSgateNode, NUMOSbulkNode);
            BFOO(NUMOSbulkDrainPtr, NUMOSbulkDrainBinding, NUMOSbulkNode, NUMOSdrainNode);
            BFOO(NUMOSbulkSourcePtr, NUMOSbulkSourceBinding, NUMOSbulkNode, NUMOSsourceNode);
            BFOO(NUMOSbulkGatePtr, NUMOSbulkGateBinding, NUMOSbulkNode, NUMOSgateNode);
            BFOO(NUMOSbulkBulkPtr, NUMOSbulkBulkBinding, NUMOSbulkNode, NUMOSbulkNode);
        }
    }

    return (OK) ;
}

int
NUMOSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMOSmodel *model = (NUMOSmodel *)inModel ;
    NUMOSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMOS models */
    for ( ; model != NULL ; model = model->NUMOSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMOSinstances ; here != NULL ; here = here->NUMOSnextInstance)
        {
            CFOO(NUMOSdrainDrainPtr, NUMOSdrainDrainBinding, NUMOSdrainNode, NUMOSdrainNode);
            CFOO(NUMOSdrainSourcePtr, NUMOSdrainSourceBinding, NUMOSdrainNode, NUMOSsourceNode);
            CFOO(NUMOSdrainGatePtr, NUMOSdrainGateBinding, NUMOSdrainNode, NUMOSgateNode);
            CFOO(NUMOSdrainBulkPtr, NUMOSdrainBulkBinding, NUMOSdrainNode, NUMOSbulkNode);
            CFOO(NUMOSsourceDrainPtr, NUMOSsourceDrainBinding, NUMOSsourceNode, NUMOSdrainNode);
            CFOO(NUMOSsourceSourcePtr, NUMOSsourceSourceBinding, NUMOSsourceNode, NUMOSsourceNode);
            CFOO(NUMOSsourceGatePtr, NUMOSsourceGateBinding, NUMOSsourceNode, NUMOSgateNode);
            CFOO(NUMOSsourceBulkPtr, NUMOSsourceBulkBinding, NUMOSsourceNode, NUMOSbulkNode);
            CFOO(NUMOSgateDrainPtr, NUMOSgateDrainBinding, NUMOSgateNode, NUMOSdrainNode);
            CFOO(NUMOSgateSourcePtr, NUMOSgateSourceBinding, NUMOSgateNode, NUMOSsourceNode);
            CFOO(NUMOSgateGatePtr, NUMOSgateGateBinding, NUMOSgateNode, NUMOSgateNode);
            CFOO(NUMOSgateBulkPtr, NUMOSgateBulkBinding, NUMOSgateNode, NUMOSbulkNode);
            CFOO(NUMOSbulkDrainPtr, NUMOSbulkDrainBinding, NUMOSbulkNode, NUMOSdrainNode);
            CFOO(NUMOSbulkSourcePtr, NUMOSbulkSourceBinding, NUMOSbulkNode, NUMOSsourceNode);
            CFOO(NUMOSbulkGatePtr, NUMOSbulkGateBinding, NUMOSbulkNode, NUMOSgateNode);
            CFOO(NUMOSbulkBulkPtr, NUMOSbulkBulkBinding, NUMOSbulkNode, NUMOSbulkNode);
        }
    }

    return (OK) ;
}
