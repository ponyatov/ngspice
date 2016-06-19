/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos3defs.h"
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
MOS3bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS3model *model = (MOS3model *)inModel ;
    MOS3instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS3 models */
    for ( ; model != NULL ; model = model->MOS3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS3instances ; here != NULL ; here = here->MOS3nextInstance)
        {
            XFOO(MOS3DdPtr, MOS3DdBinding, MOS3dNode, MOS3dNode);
            XFOO(MOS3GgPtr, MOS3GgBinding, MOS3gNode, MOS3gNode);
            XFOO(MOS3SsPtr, MOS3SsBinding, MOS3sNode, MOS3sNode);
            XFOO(MOS3BbPtr, MOS3BbBinding, MOS3bNode, MOS3bNode);
            XFOO(MOS3DPdpPtr, MOS3DPdpBinding, MOS3dNodePrime, MOS3dNodePrime);
            XFOO(MOS3SPspPtr, MOS3SPspBinding, MOS3sNodePrime, MOS3sNodePrime);
            XFOO(MOS3DdpPtr, MOS3DdpBinding, MOS3dNode, MOS3dNodePrime);
            XFOO(MOS3GbPtr, MOS3GbBinding, MOS3gNode, MOS3bNode);
            XFOO(MOS3GdpPtr, MOS3GdpBinding, MOS3gNode, MOS3dNodePrime);
            XFOO(MOS3GspPtr, MOS3GspBinding, MOS3gNode, MOS3sNodePrime);
            XFOO(MOS3SspPtr, MOS3SspBinding, MOS3sNode, MOS3sNodePrime);
            XFOO(MOS3BdpPtr, MOS3BdpBinding, MOS3bNode, MOS3dNodePrime);
            XFOO(MOS3BspPtr, MOS3BspBinding, MOS3bNode, MOS3sNodePrime);
            XFOO(MOS3DPspPtr, MOS3DPspBinding, MOS3dNodePrime, MOS3sNodePrime);
            XFOO(MOS3DPdPtr, MOS3DPdBinding, MOS3dNodePrime, MOS3dNode);
            XFOO(MOS3BgPtr, MOS3BgBinding, MOS3bNode, MOS3gNode);
            XFOO(MOS3DPgPtr, MOS3DPgBinding, MOS3dNodePrime, MOS3gNode);
            XFOO(MOS3SPgPtr, MOS3SPgBinding, MOS3sNodePrime, MOS3gNode);
            XFOO(MOS3SPsPtr, MOS3SPsBinding, MOS3sNodePrime, MOS3sNode);
            XFOO(MOS3DPbPtr, MOS3DPbBinding, MOS3dNodePrime, MOS3bNode);
            XFOO(MOS3SPbPtr, MOS3SPbBinding, MOS3sNodePrime, MOS3bNode);
            XFOO(MOS3SPdpPtr, MOS3SPdpBinding, MOS3sNodePrime, MOS3dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS3bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS3model *model = (MOS3model *)inModel ;
    MOS3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS3 models */
    for ( ; model != NULL ; model = model->MOS3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS3instances ; here != NULL ; here = here->MOS3nextInstance)
        {
            BFOO(MOS3DdPtr, MOS3DdBinding, MOS3dNode, MOS3dNode);
            BFOO(MOS3GgPtr, MOS3GgBinding, MOS3gNode, MOS3gNode);
            BFOO(MOS3SsPtr, MOS3SsBinding, MOS3sNode, MOS3sNode);
            BFOO(MOS3BbPtr, MOS3BbBinding, MOS3bNode, MOS3bNode);
            BFOO(MOS3DPdpPtr, MOS3DPdpBinding, MOS3dNodePrime, MOS3dNodePrime);
            BFOO(MOS3SPspPtr, MOS3SPspBinding, MOS3sNodePrime, MOS3sNodePrime);
            BFOO(MOS3DdpPtr, MOS3DdpBinding, MOS3dNode, MOS3dNodePrime);
            BFOO(MOS3GbPtr, MOS3GbBinding, MOS3gNode, MOS3bNode);
            BFOO(MOS3GdpPtr, MOS3GdpBinding, MOS3gNode, MOS3dNodePrime);
            BFOO(MOS3GspPtr, MOS3GspBinding, MOS3gNode, MOS3sNodePrime);
            BFOO(MOS3SspPtr, MOS3SspBinding, MOS3sNode, MOS3sNodePrime);
            BFOO(MOS3BdpPtr, MOS3BdpBinding, MOS3bNode, MOS3dNodePrime);
            BFOO(MOS3BspPtr, MOS3BspBinding, MOS3bNode, MOS3sNodePrime);
            BFOO(MOS3DPspPtr, MOS3DPspBinding, MOS3dNodePrime, MOS3sNodePrime);
            BFOO(MOS3DPdPtr, MOS3DPdBinding, MOS3dNodePrime, MOS3dNode);
            BFOO(MOS3BgPtr, MOS3BgBinding, MOS3bNode, MOS3gNode);
            BFOO(MOS3DPgPtr, MOS3DPgBinding, MOS3dNodePrime, MOS3gNode);
            BFOO(MOS3SPgPtr, MOS3SPgBinding, MOS3sNodePrime, MOS3gNode);
            BFOO(MOS3SPsPtr, MOS3SPsBinding, MOS3sNodePrime, MOS3sNode);
            BFOO(MOS3DPbPtr, MOS3DPbBinding, MOS3dNodePrime, MOS3bNode);
            BFOO(MOS3SPbPtr, MOS3SPbBinding, MOS3sNodePrime, MOS3bNode);
            BFOO(MOS3SPdpPtr, MOS3SPdpBinding, MOS3sNodePrime, MOS3dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS3bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS3model *model = (MOS3model *)inModel ;
    MOS3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS3 models */
    for ( ; model != NULL ; model = model->MOS3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS3instances ; here != NULL ; here = here->MOS3nextInstance)
        {
            CFOO(MOS3DdPtr, MOS3DdBinding, MOS3dNode, MOS3dNode);
            CFOO(MOS3GgPtr, MOS3GgBinding, MOS3gNode, MOS3gNode);
            CFOO(MOS3SsPtr, MOS3SsBinding, MOS3sNode, MOS3sNode);
            CFOO(MOS3BbPtr, MOS3BbBinding, MOS3bNode, MOS3bNode);
            CFOO(MOS3DPdpPtr, MOS3DPdpBinding, MOS3dNodePrime, MOS3dNodePrime);
            CFOO(MOS3SPspPtr, MOS3SPspBinding, MOS3sNodePrime, MOS3sNodePrime);
            CFOO(MOS3DdpPtr, MOS3DdpBinding, MOS3dNode, MOS3dNodePrime);
            CFOO(MOS3GbPtr, MOS3GbBinding, MOS3gNode, MOS3bNode);
            CFOO(MOS3GdpPtr, MOS3GdpBinding, MOS3gNode, MOS3dNodePrime);
            CFOO(MOS3GspPtr, MOS3GspBinding, MOS3gNode, MOS3sNodePrime);
            CFOO(MOS3SspPtr, MOS3SspBinding, MOS3sNode, MOS3sNodePrime);
            CFOO(MOS3BdpPtr, MOS3BdpBinding, MOS3bNode, MOS3dNodePrime);
            CFOO(MOS3BspPtr, MOS3BspBinding, MOS3bNode, MOS3sNodePrime);
            CFOO(MOS3DPspPtr, MOS3DPspBinding, MOS3dNodePrime, MOS3sNodePrime);
            CFOO(MOS3DPdPtr, MOS3DPdBinding, MOS3dNodePrime, MOS3dNode);
            CFOO(MOS3BgPtr, MOS3BgBinding, MOS3bNode, MOS3gNode);
            CFOO(MOS3DPgPtr, MOS3DPgBinding, MOS3dNodePrime, MOS3gNode);
            CFOO(MOS3SPgPtr, MOS3SPgBinding, MOS3sNodePrime, MOS3gNode);
            CFOO(MOS3SPsPtr, MOS3SPsBinding, MOS3sNodePrime, MOS3sNode);
            CFOO(MOS3DPbPtr, MOS3DPbBinding, MOS3dNodePrime, MOS3bNode);
            CFOO(MOS3SPbPtr, MOS3SPbBinding, MOS3sNodePrime, MOS3bNode);
            CFOO(MOS3SPdpPtr, MOS3SPdpBinding, MOS3sNodePrime, MOS3dNodePrime);
        }
    }

    return (OK) ;
}
