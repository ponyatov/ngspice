/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim3def.h"
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
BSIM3bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3model *model = (BSIM3model *)inModel ;
    BSIM3instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM3 models */
    for ( ; model != NULL ; model = model->BSIM3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3instances ; here != NULL ; here = here->BSIM3nextInstance)
        {
            XFOO(BSIM3DdPtr, BSIM3DdBinding, BSIM3dNode, BSIM3dNode);
            XFOO(BSIM3GgPtr, BSIM3GgBinding, BSIM3gNode, BSIM3gNode);
            XFOO(BSIM3SsPtr, BSIM3SsBinding, BSIM3sNode, BSIM3sNode);
            XFOO(BSIM3BbPtr, BSIM3BbBinding, BSIM3bNode, BSIM3bNode);
            XFOO(BSIM3DPdpPtr, BSIM3DPdpBinding, BSIM3dNodePrime, BSIM3dNodePrime);
            XFOO(BSIM3SPspPtr, BSIM3SPspBinding, BSIM3sNodePrime, BSIM3sNodePrime);
            XFOO(BSIM3DdpPtr, BSIM3DdpBinding, BSIM3dNode, BSIM3dNodePrime);
            XFOO(BSIM3GbPtr, BSIM3GbBinding, BSIM3gNode, BSIM3bNode);
            XFOO(BSIM3GdpPtr, BSIM3GdpBinding, BSIM3gNode, BSIM3dNodePrime);
            XFOO(BSIM3GspPtr, BSIM3GspBinding, BSIM3gNode, BSIM3sNodePrime);
            XFOO(BSIM3SspPtr, BSIM3SspBinding, BSIM3sNode, BSIM3sNodePrime);
            XFOO(BSIM3BdpPtr, BSIM3BdpBinding, BSIM3bNode, BSIM3dNodePrime);
            XFOO(BSIM3BspPtr, BSIM3BspBinding, BSIM3bNode, BSIM3sNodePrime);
            XFOO(BSIM3DPspPtr, BSIM3DPspBinding, BSIM3dNodePrime, BSIM3sNodePrime);
            XFOO(BSIM3DPdPtr, BSIM3DPdBinding, BSIM3dNodePrime, BSIM3dNode);
            XFOO(BSIM3BgPtr, BSIM3BgBinding, BSIM3bNode, BSIM3gNode);
            XFOO(BSIM3DPgPtr, BSIM3DPgBinding, BSIM3dNodePrime, BSIM3gNode);
            XFOO(BSIM3SPgPtr, BSIM3SPgBinding, BSIM3sNodePrime, BSIM3gNode);
            XFOO(BSIM3SPsPtr, BSIM3SPsBinding, BSIM3sNodePrime, BSIM3sNode);
            XFOO(BSIM3DPbPtr, BSIM3DPbBinding, BSIM3dNodePrime, BSIM3bNode);
            XFOO(BSIM3SPbPtr, BSIM3SPbBinding, BSIM3sNodePrime, BSIM3bNode);
            XFOO(BSIM3SPdpPtr, BSIM3SPdpBinding, BSIM3sNodePrime, BSIM3dNodePrime);
            XFOO(BSIM3QqPtr, BSIM3QqBinding, BSIM3qNode, BSIM3qNode);
            XFOO(BSIM3QdpPtr, BSIM3QdpBinding, BSIM3qNode, BSIM3dNodePrime);
            XFOO(BSIM3QgPtr, BSIM3QgBinding, BSIM3qNode, BSIM3gNode);
            XFOO(BSIM3QspPtr, BSIM3QspBinding, BSIM3qNode, BSIM3sNodePrime);
            XFOO(BSIM3QbPtr, BSIM3QbBinding, BSIM3qNode, BSIM3bNode);
            XFOO(BSIM3DPqPtr, BSIM3DPqBinding, BSIM3dNodePrime, BSIM3qNode);
            XFOO(BSIM3GqPtr, BSIM3GqBinding, BSIM3gNode, BSIM3qNode);
            XFOO(BSIM3SPqPtr, BSIM3SPqBinding, BSIM3sNodePrime, BSIM3qNode);
            XFOO(BSIM3BqPtr, BSIM3BqBinding, BSIM3bNode, BSIM3qNode);
        }
    }

    return (OK) ;
}

int
BSIM3bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3model *model = (BSIM3model *)inModel ;
    BSIM3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3 models */
    for ( ; model != NULL ; model = model->BSIM3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3instances ; here != NULL ; here = here->BSIM3nextInstance)
        {
            BFOO(BSIM3DdPtr, BSIM3DdBinding, BSIM3dNode, BSIM3dNode);
            BFOO(BSIM3GgPtr, BSIM3GgBinding, BSIM3gNode, BSIM3gNode);
            BFOO(BSIM3SsPtr, BSIM3SsBinding, BSIM3sNode, BSIM3sNode);
            BFOO(BSIM3BbPtr, BSIM3BbBinding, BSIM3bNode, BSIM3bNode);
            BFOO(BSIM3DPdpPtr, BSIM3DPdpBinding, BSIM3dNodePrime, BSIM3dNodePrime);
            BFOO(BSIM3SPspPtr, BSIM3SPspBinding, BSIM3sNodePrime, BSIM3sNodePrime);
            BFOO(BSIM3DdpPtr, BSIM3DdpBinding, BSIM3dNode, BSIM3dNodePrime);
            BFOO(BSIM3GbPtr, BSIM3GbBinding, BSIM3gNode, BSIM3bNode);
            BFOO(BSIM3GdpPtr, BSIM3GdpBinding, BSIM3gNode, BSIM3dNodePrime);
            BFOO(BSIM3GspPtr, BSIM3GspBinding, BSIM3gNode, BSIM3sNodePrime);
            BFOO(BSIM3SspPtr, BSIM3SspBinding, BSIM3sNode, BSIM3sNodePrime);
            BFOO(BSIM3BdpPtr, BSIM3BdpBinding, BSIM3bNode, BSIM3dNodePrime);
            BFOO(BSIM3BspPtr, BSIM3BspBinding, BSIM3bNode, BSIM3sNodePrime);
            BFOO(BSIM3DPspPtr, BSIM3DPspBinding, BSIM3dNodePrime, BSIM3sNodePrime);
            BFOO(BSIM3DPdPtr, BSIM3DPdBinding, BSIM3dNodePrime, BSIM3dNode);
            BFOO(BSIM3BgPtr, BSIM3BgBinding, BSIM3bNode, BSIM3gNode);
            BFOO(BSIM3DPgPtr, BSIM3DPgBinding, BSIM3dNodePrime, BSIM3gNode);
            BFOO(BSIM3SPgPtr, BSIM3SPgBinding, BSIM3sNodePrime, BSIM3gNode);
            BFOO(BSIM3SPsPtr, BSIM3SPsBinding, BSIM3sNodePrime, BSIM3sNode);
            BFOO(BSIM3DPbPtr, BSIM3DPbBinding, BSIM3dNodePrime, BSIM3bNode);
            BFOO(BSIM3SPbPtr, BSIM3SPbBinding, BSIM3sNodePrime, BSIM3bNode);
            BFOO(BSIM3SPdpPtr, BSIM3SPdpBinding, BSIM3sNodePrime, BSIM3dNodePrime);
            BFOO(BSIM3QqPtr, BSIM3QqBinding, BSIM3qNode, BSIM3qNode);
            BFOO(BSIM3QdpPtr, BSIM3QdpBinding, BSIM3qNode, BSIM3dNodePrime);
            BFOO(BSIM3QgPtr, BSIM3QgBinding, BSIM3qNode, BSIM3gNode);
            BFOO(BSIM3QspPtr, BSIM3QspBinding, BSIM3qNode, BSIM3sNodePrime);
            BFOO(BSIM3QbPtr, BSIM3QbBinding, BSIM3qNode, BSIM3bNode);
            BFOO(BSIM3DPqPtr, BSIM3DPqBinding, BSIM3dNodePrime, BSIM3qNode);
            BFOO(BSIM3GqPtr, BSIM3GqBinding, BSIM3gNode, BSIM3qNode);
            BFOO(BSIM3SPqPtr, BSIM3SPqBinding, BSIM3sNodePrime, BSIM3qNode);
            BFOO(BSIM3BqPtr, BSIM3BqBinding, BSIM3bNode, BSIM3qNode);
        }
    }

    return (OK) ;
}

int
BSIM3bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3model *model = (BSIM3model *)inModel ;
    BSIM3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3 models */
    for ( ; model != NULL ; model = model->BSIM3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3instances ; here != NULL ; here = here->BSIM3nextInstance)
        {
            CFOO(BSIM3DdPtr, BSIM3DdBinding, BSIM3dNode, BSIM3dNode);
            CFOO(BSIM3GgPtr, BSIM3GgBinding, BSIM3gNode, BSIM3gNode);
            CFOO(BSIM3SsPtr, BSIM3SsBinding, BSIM3sNode, BSIM3sNode);
            CFOO(BSIM3BbPtr, BSIM3BbBinding, BSIM3bNode, BSIM3bNode);
            CFOO(BSIM3DPdpPtr, BSIM3DPdpBinding, BSIM3dNodePrime, BSIM3dNodePrime);
            CFOO(BSIM3SPspPtr, BSIM3SPspBinding, BSIM3sNodePrime, BSIM3sNodePrime);
            CFOO(BSIM3DdpPtr, BSIM3DdpBinding, BSIM3dNode, BSIM3dNodePrime);
            CFOO(BSIM3GbPtr, BSIM3GbBinding, BSIM3gNode, BSIM3bNode);
            CFOO(BSIM3GdpPtr, BSIM3GdpBinding, BSIM3gNode, BSIM3dNodePrime);
            CFOO(BSIM3GspPtr, BSIM3GspBinding, BSIM3gNode, BSIM3sNodePrime);
            CFOO(BSIM3SspPtr, BSIM3SspBinding, BSIM3sNode, BSIM3sNodePrime);
            CFOO(BSIM3BdpPtr, BSIM3BdpBinding, BSIM3bNode, BSIM3dNodePrime);
            CFOO(BSIM3BspPtr, BSIM3BspBinding, BSIM3bNode, BSIM3sNodePrime);
            CFOO(BSIM3DPspPtr, BSIM3DPspBinding, BSIM3dNodePrime, BSIM3sNodePrime);
            CFOO(BSIM3DPdPtr, BSIM3DPdBinding, BSIM3dNodePrime, BSIM3dNode);
            CFOO(BSIM3BgPtr, BSIM3BgBinding, BSIM3bNode, BSIM3gNode);
            CFOO(BSIM3DPgPtr, BSIM3DPgBinding, BSIM3dNodePrime, BSIM3gNode);
            CFOO(BSIM3SPgPtr, BSIM3SPgBinding, BSIM3sNodePrime, BSIM3gNode);
            CFOO(BSIM3SPsPtr, BSIM3SPsBinding, BSIM3sNodePrime, BSIM3sNode);
            CFOO(BSIM3DPbPtr, BSIM3DPbBinding, BSIM3dNodePrime, BSIM3bNode);
            CFOO(BSIM3SPbPtr, BSIM3SPbBinding, BSIM3sNodePrime, BSIM3bNode);
            CFOO(BSIM3SPdpPtr, BSIM3SPdpBinding, BSIM3sNodePrime, BSIM3dNodePrime);
            CFOO(BSIM3QqPtr, BSIM3QqBinding, BSIM3qNode, BSIM3qNode);
            CFOO(BSIM3QdpPtr, BSIM3QdpBinding, BSIM3qNode, BSIM3dNodePrime);
            CFOO(BSIM3QgPtr, BSIM3QgBinding, BSIM3qNode, BSIM3gNode);
            CFOO(BSIM3QspPtr, BSIM3QspBinding, BSIM3qNode, BSIM3sNodePrime);
            CFOO(BSIM3QbPtr, BSIM3QbBinding, BSIM3qNode, BSIM3bNode);
            CFOO(BSIM3DPqPtr, BSIM3DPqBinding, BSIM3dNodePrime, BSIM3qNode);
            CFOO(BSIM3GqPtr, BSIM3GqBinding, BSIM3gNode, BSIM3qNode);
            CFOO(BSIM3SPqPtr, BSIM3SPqBinding, BSIM3sNodePrime, BSIM3qNode);
            CFOO(BSIM3BqPtr, BSIM3BqBinding, BSIM3bNode, BSIM3qNode);
        }
    }

    return (OK) ;
}
