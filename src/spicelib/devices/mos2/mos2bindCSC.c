/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos2defs.h"
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
MOS2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS2model *model = (MOS2model *)inModel ;
    MOS2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS2 models */
    for ( ; model != NULL ; model = model->MOS2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS2instances ; here != NULL ; here = here->MOS2nextInstance)
        {
            XFOO(MOS2DdPtr, MOS2DdBinding, MOS2dNode, MOS2dNode);
            XFOO(MOS2GgPtr, MOS2GgBinding, MOS2gNode, MOS2gNode);
            XFOO(MOS2SsPtr, MOS2SsBinding, MOS2sNode, MOS2sNode);
            XFOO(MOS2BbPtr, MOS2BbBinding, MOS2bNode, MOS2bNode);
            XFOO(MOS2DPdpPtr, MOS2DPdpBinding, MOS2dNodePrime, MOS2dNodePrime);
            XFOO(MOS2SPspPtr, MOS2SPspBinding, MOS2sNodePrime, MOS2sNodePrime);
            XFOO(MOS2DdpPtr, MOS2DdpBinding, MOS2dNode, MOS2dNodePrime);
            XFOO(MOS2GbPtr, MOS2GbBinding, MOS2gNode, MOS2bNode);
            XFOO(MOS2GdpPtr, MOS2GdpBinding, MOS2gNode, MOS2dNodePrime);
            XFOO(MOS2GspPtr, MOS2GspBinding, MOS2gNode, MOS2sNodePrime);
            XFOO(MOS2SspPtr, MOS2SspBinding, MOS2sNode, MOS2sNodePrime);
            XFOO(MOS2BdpPtr, MOS2BdpBinding, MOS2bNode, MOS2dNodePrime);
            XFOO(MOS2BspPtr, MOS2BspBinding, MOS2bNode, MOS2sNodePrime);
            XFOO(MOS2DPspPtr, MOS2DPspBinding, MOS2dNodePrime, MOS2sNodePrime);
            XFOO(MOS2DPdPtr, MOS2DPdBinding, MOS2dNodePrime, MOS2dNode);
            XFOO(MOS2BgPtr, MOS2BgBinding, MOS2bNode, MOS2gNode);
            XFOO(MOS2DPgPtr, MOS2DPgBinding, MOS2dNodePrime, MOS2gNode);
            XFOO(MOS2SPgPtr, MOS2SPgBinding, MOS2sNodePrime, MOS2gNode);
            XFOO(MOS2SPsPtr, MOS2SPsBinding, MOS2sNodePrime, MOS2sNode);
            XFOO(MOS2DPbPtr, MOS2DPbBinding, MOS2dNodePrime, MOS2bNode);
            XFOO(MOS2SPbPtr, MOS2SPbBinding, MOS2sNodePrime, MOS2bNode);
            XFOO(MOS2SPdpPtr, MOS2SPdpBinding, MOS2sNodePrime, MOS2dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS2model *model = (MOS2model *)inModel ;
    MOS2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS2 models */
    for ( ; model != NULL ; model = model->MOS2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS2instances ; here != NULL ; here = here->MOS2nextInstance)
        {
            BFOO(MOS2DdPtr, MOS2DdBinding, MOS2dNode, MOS2dNode);
            BFOO(MOS2GgPtr, MOS2GgBinding, MOS2gNode, MOS2gNode);
            BFOO(MOS2SsPtr, MOS2SsBinding, MOS2sNode, MOS2sNode);
            BFOO(MOS2BbPtr, MOS2BbBinding, MOS2bNode, MOS2bNode);
            BFOO(MOS2DPdpPtr, MOS2DPdpBinding, MOS2dNodePrime, MOS2dNodePrime);
            BFOO(MOS2SPspPtr, MOS2SPspBinding, MOS2sNodePrime, MOS2sNodePrime);
            BFOO(MOS2DdpPtr, MOS2DdpBinding, MOS2dNode, MOS2dNodePrime);
            BFOO(MOS2GbPtr, MOS2GbBinding, MOS2gNode, MOS2bNode);
            BFOO(MOS2GdpPtr, MOS2GdpBinding, MOS2gNode, MOS2dNodePrime);
            BFOO(MOS2GspPtr, MOS2GspBinding, MOS2gNode, MOS2sNodePrime);
            BFOO(MOS2SspPtr, MOS2SspBinding, MOS2sNode, MOS2sNodePrime);
            BFOO(MOS2BdpPtr, MOS2BdpBinding, MOS2bNode, MOS2dNodePrime);
            BFOO(MOS2BspPtr, MOS2BspBinding, MOS2bNode, MOS2sNodePrime);
            BFOO(MOS2DPspPtr, MOS2DPspBinding, MOS2dNodePrime, MOS2sNodePrime);
            BFOO(MOS2DPdPtr, MOS2DPdBinding, MOS2dNodePrime, MOS2dNode);
            BFOO(MOS2BgPtr, MOS2BgBinding, MOS2bNode, MOS2gNode);
            BFOO(MOS2DPgPtr, MOS2DPgBinding, MOS2dNodePrime, MOS2gNode);
            BFOO(MOS2SPgPtr, MOS2SPgBinding, MOS2sNodePrime, MOS2gNode);
            BFOO(MOS2SPsPtr, MOS2SPsBinding, MOS2sNodePrime, MOS2sNode);
            BFOO(MOS2DPbPtr, MOS2DPbBinding, MOS2dNodePrime, MOS2bNode);
            BFOO(MOS2SPbPtr, MOS2SPbBinding, MOS2sNodePrime, MOS2bNode);
            BFOO(MOS2SPdpPtr, MOS2SPdpBinding, MOS2sNodePrime, MOS2dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS2model *model = (MOS2model *)inModel ;
    MOS2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS2 models */
    for ( ; model != NULL ; model = model->MOS2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS2instances ; here != NULL ; here = here->MOS2nextInstance)
        {
            CFOO(MOS2DdPtr, MOS2DdBinding, MOS2dNode, MOS2dNode);
            CFOO(MOS2GgPtr, MOS2GgBinding, MOS2gNode, MOS2gNode);
            CFOO(MOS2SsPtr, MOS2SsBinding, MOS2sNode, MOS2sNode);
            CFOO(MOS2BbPtr, MOS2BbBinding, MOS2bNode, MOS2bNode);
            CFOO(MOS2DPdpPtr, MOS2DPdpBinding, MOS2dNodePrime, MOS2dNodePrime);
            CFOO(MOS2SPspPtr, MOS2SPspBinding, MOS2sNodePrime, MOS2sNodePrime);
            CFOO(MOS2DdpPtr, MOS2DdpBinding, MOS2dNode, MOS2dNodePrime);
            CFOO(MOS2GbPtr, MOS2GbBinding, MOS2gNode, MOS2bNode);
            CFOO(MOS2GdpPtr, MOS2GdpBinding, MOS2gNode, MOS2dNodePrime);
            CFOO(MOS2GspPtr, MOS2GspBinding, MOS2gNode, MOS2sNodePrime);
            CFOO(MOS2SspPtr, MOS2SspBinding, MOS2sNode, MOS2sNodePrime);
            CFOO(MOS2BdpPtr, MOS2BdpBinding, MOS2bNode, MOS2dNodePrime);
            CFOO(MOS2BspPtr, MOS2BspBinding, MOS2bNode, MOS2sNodePrime);
            CFOO(MOS2DPspPtr, MOS2DPspBinding, MOS2dNodePrime, MOS2sNodePrime);
            CFOO(MOS2DPdPtr, MOS2DPdBinding, MOS2dNodePrime, MOS2dNode);
            CFOO(MOS2BgPtr, MOS2BgBinding, MOS2bNode, MOS2gNode);
            CFOO(MOS2DPgPtr, MOS2DPgBinding, MOS2dNodePrime, MOS2gNode);
            CFOO(MOS2SPgPtr, MOS2SPgBinding, MOS2sNodePrime, MOS2gNode);
            CFOO(MOS2SPsPtr, MOS2SPsBinding, MOS2sNodePrime, MOS2sNode);
            CFOO(MOS2DPbPtr, MOS2DPbBinding, MOS2dNodePrime, MOS2bNode);
            CFOO(MOS2SPbPtr, MOS2SPbBinding, MOS2sNodePrime, MOS2bNode);
            CFOO(MOS2SPdpPtr, MOS2SPdpBinding, MOS2sNodePrime, MOS2dNodePrime);
        }
    }

    return (OK) ;
}
