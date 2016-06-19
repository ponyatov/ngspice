/**********
Author: 2012 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos6defs.h"
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
MOS6bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS6model *model = (MOS6model *)inModel ;
    MOS6instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS6 models */
    for ( ; model != NULL ; model = model->MOS6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS6instances ; here != NULL ; here = here->MOS6nextInstance)
        {
            XFOO(MOS6DdPtr, MOS6DdBinding, MOS6dNode, MOS6dNode);
            XFOO(MOS6GgPtr, MOS6GgBinding, MOS6gNode, MOS6gNode);
            XFOO(MOS6SsPtr, MOS6SsBinding, MOS6sNode, MOS6sNode);
            XFOO(MOS6BbPtr, MOS6BbBinding, MOS6bNode, MOS6bNode);
            XFOO(MOS6DPdpPtr, MOS6DPdpBinding, MOS6dNodePrime, MOS6dNodePrime);
            XFOO(MOS6SPspPtr, MOS6SPspBinding, MOS6sNodePrime, MOS6sNodePrime);
            XFOO(MOS6DdpPtr, MOS6DdpBinding, MOS6dNode, MOS6dNodePrime);
            XFOO(MOS6GbPtr, MOS6GbBinding, MOS6gNode, MOS6bNode);
            XFOO(MOS6GdpPtr, MOS6GdpBinding, MOS6gNode, MOS6dNodePrime);
            XFOO(MOS6GspPtr, MOS6GspBinding, MOS6gNode, MOS6sNodePrime);
            XFOO(MOS6SspPtr, MOS6SspBinding, MOS6sNode, MOS6sNodePrime);
            XFOO(MOS6BdpPtr, MOS6BdpBinding, MOS6bNode, MOS6dNodePrime);
            XFOO(MOS6BspPtr, MOS6BspBinding, MOS6bNode, MOS6sNodePrime);
            XFOO(MOS6DPspPtr, MOS6DPspBinding, MOS6dNodePrime, MOS6sNodePrime);
            XFOO(MOS6DPdPtr, MOS6DPdBinding, MOS6dNodePrime, MOS6dNode);
            XFOO(MOS6BgPtr, MOS6BgBinding, MOS6bNode, MOS6gNode);
            XFOO(MOS6DPgPtr, MOS6DPgBinding, MOS6dNodePrime, MOS6gNode);
            XFOO(MOS6SPgPtr, MOS6SPgBinding, MOS6sNodePrime, MOS6gNode);
            XFOO(MOS6SPsPtr, MOS6SPsBinding, MOS6sNodePrime, MOS6sNode);
            XFOO(MOS6DPbPtr, MOS6DPbBinding, MOS6dNodePrime, MOS6bNode);
            XFOO(MOS6SPbPtr, MOS6SPbBinding, MOS6sNodePrime, MOS6bNode);
            XFOO(MOS6SPdpPtr, MOS6SPdpBinding, MOS6sNodePrime, MOS6dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS6bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS6model *model = (MOS6model *)inModel ;
    MOS6instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS6 models */
    for ( ; model != NULL ; model = model->MOS6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS6instances ; here != NULL ; here = here->MOS6nextInstance)
        {
            BFOO(MOS6DdPtr, MOS6DdBinding, MOS6dNode, MOS6dNode);
            BFOO(MOS6GgPtr, MOS6GgBinding, MOS6gNode, MOS6gNode);
            BFOO(MOS6SsPtr, MOS6SsBinding, MOS6sNode, MOS6sNode);
            BFOO(MOS6BbPtr, MOS6BbBinding, MOS6bNode, MOS6bNode);
            BFOO(MOS6DPdpPtr, MOS6DPdpBinding, MOS6dNodePrime, MOS6dNodePrime);
            BFOO(MOS6SPspPtr, MOS6SPspBinding, MOS6sNodePrime, MOS6sNodePrime);
            BFOO(MOS6DdpPtr, MOS6DdpBinding, MOS6dNode, MOS6dNodePrime);
            BFOO(MOS6GbPtr, MOS6GbBinding, MOS6gNode, MOS6bNode);
            BFOO(MOS6GdpPtr, MOS6GdpBinding, MOS6gNode, MOS6dNodePrime);
            BFOO(MOS6GspPtr, MOS6GspBinding, MOS6gNode, MOS6sNodePrime);
            BFOO(MOS6SspPtr, MOS6SspBinding, MOS6sNode, MOS6sNodePrime);
            BFOO(MOS6BdpPtr, MOS6BdpBinding, MOS6bNode, MOS6dNodePrime);
            BFOO(MOS6BspPtr, MOS6BspBinding, MOS6bNode, MOS6sNodePrime);
            BFOO(MOS6DPspPtr, MOS6DPspBinding, MOS6dNodePrime, MOS6sNodePrime);
            BFOO(MOS6DPdPtr, MOS6DPdBinding, MOS6dNodePrime, MOS6dNode);
            BFOO(MOS6BgPtr, MOS6BgBinding, MOS6bNode, MOS6gNode);
            BFOO(MOS6DPgPtr, MOS6DPgBinding, MOS6dNodePrime, MOS6gNode);
            BFOO(MOS6SPgPtr, MOS6SPgBinding, MOS6sNodePrime, MOS6gNode);
            BFOO(MOS6SPsPtr, MOS6SPsBinding, MOS6sNodePrime, MOS6sNode);
            BFOO(MOS6DPbPtr, MOS6DPbBinding, MOS6dNodePrime, MOS6bNode);
            BFOO(MOS6SPbPtr, MOS6SPbBinding, MOS6sNodePrime, MOS6bNode);
            BFOO(MOS6SPdpPtr, MOS6SPdpBinding, MOS6sNodePrime, MOS6dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS6bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS6model *model = (MOS6model *)inModel ;
    MOS6instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS6 models */
    for ( ; model != NULL ; model = model->MOS6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS6instances ; here != NULL ; here = here->MOS6nextInstance)
        {
            CFOO(MOS6DdPtr, MOS6DdBinding, MOS6dNode, MOS6dNode);
            CFOO(MOS6GgPtr, MOS6GgBinding, MOS6gNode, MOS6gNode);
            CFOO(MOS6SsPtr, MOS6SsBinding, MOS6sNode, MOS6sNode);
            CFOO(MOS6BbPtr, MOS6BbBinding, MOS6bNode, MOS6bNode);
            CFOO(MOS6DPdpPtr, MOS6DPdpBinding, MOS6dNodePrime, MOS6dNodePrime);
            CFOO(MOS6SPspPtr, MOS6SPspBinding, MOS6sNodePrime, MOS6sNodePrime);
            CFOO(MOS6DdpPtr, MOS6DdpBinding, MOS6dNode, MOS6dNodePrime);
            CFOO(MOS6GbPtr, MOS6GbBinding, MOS6gNode, MOS6bNode);
            CFOO(MOS6GdpPtr, MOS6GdpBinding, MOS6gNode, MOS6dNodePrime);
            CFOO(MOS6GspPtr, MOS6GspBinding, MOS6gNode, MOS6sNodePrime);
            CFOO(MOS6SspPtr, MOS6SspBinding, MOS6sNode, MOS6sNodePrime);
            CFOO(MOS6BdpPtr, MOS6BdpBinding, MOS6bNode, MOS6dNodePrime);
            CFOO(MOS6BspPtr, MOS6BspBinding, MOS6bNode, MOS6sNodePrime);
            CFOO(MOS6DPspPtr, MOS6DPspBinding, MOS6dNodePrime, MOS6sNodePrime);
            CFOO(MOS6DPdPtr, MOS6DPdBinding, MOS6dNodePrime, MOS6dNode);
            CFOO(MOS6BgPtr, MOS6BgBinding, MOS6bNode, MOS6gNode);
            CFOO(MOS6DPgPtr, MOS6DPgBinding, MOS6dNodePrime, MOS6gNode);
            CFOO(MOS6SPgPtr, MOS6SPgBinding, MOS6sNodePrime, MOS6gNode);
            CFOO(MOS6SPsPtr, MOS6SPsBinding, MOS6sNodePrime, MOS6sNode);
            CFOO(MOS6DPbPtr, MOS6DPbBinding, MOS6dNodePrime, MOS6bNode);
            CFOO(MOS6SPbPtr, MOS6SPbBinding, MOS6sNodePrime, MOS6bNode);
            CFOO(MOS6SPdpPtr, MOS6SPdpBinding, MOS6sNodePrime, MOS6dNodePrime);
        }
    }

    return (OK) ;
}
