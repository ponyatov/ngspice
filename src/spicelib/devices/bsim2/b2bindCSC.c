/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim2def.h"
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
B2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B2model *model = (B2model *)inModel ;
    B2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B2 models */
    for ( ; model != NULL ; model = model->B2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B2instances ; here != NULL ; here = here->B2nextInstance)
        {
            XFOO(B2DdPtr, B2DdBinding, B2dNode, B2dNode);
            XFOO(B2GgPtr, B2GgBinding, B2gNode, B2gNode);
            XFOO(B2SsPtr, B2SsBinding, B2sNode, B2sNode);
            XFOO(B2BbPtr, B2BbBinding, B2bNode, B2bNode);
            XFOO(B2DPdpPtr, B2DPdpBinding, B2dNodePrime, B2dNodePrime);
            XFOO(B2SPspPtr, B2SPspBinding, B2sNodePrime, B2sNodePrime);
            XFOO(B2DdpPtr, B2DdpBinding, B2dNode, B2dNodePrime);
            XFOO(B2GbPtr, B2GbBinding, B2gNode, B2bNode);
            XFOO(B2GdpPtr, B2GdpBinding, B2gNode, B2dNodePrime);
            XFOO(B2GspPtr, B2GspBinding, B2gNode, B2sNodePrime);
            XFOO(B2SspPtr, B2SspBinding, B2sNode, B2sNodePrime);
            XFOO(B2BdpPtr, B2BdpBinding, B2bNode, B2dNodePrime);
            XFOO(B2BspPtr, B2BspBinding, B2bNode, B2sNodePrime);
            XFOO(B2DPspPtr, B2DPspBinding, B2dNodePrime, B2sNodePrime);
            XFOO(B2DPdPtr, B2DPdBinding, B2dNodePrime, B2dNode);
            XFOO(B2BgPtr, B2BgBinding, B2bNode, B2gNode);
            XFOO(B2DPgPtr, B2DPgBinding, B2dNodePrime, B2gNode);
            XFOO(B2SPgPtr, B2SPgBinding, B2sNodePrime, B2gNode);
            XFOO(B2SPsPtr, B2SPsBinding, B2sNodePrime, B2sNode);
            XFOO(B2DPbPtr, B2DPbBinding, B2dNodePrime, B2bNode);
            XFOO(B2SPbPtr, B2SPbBinding, B2sNodePrime, B2bNode);
            XFOO(B2SPdpPtr, B2SPdpBinding, B2sNodePrime, B2dNodePrime);
        }
    }

    return (OK) ;
}

int
B2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B2model *model = (B2model *)inModel ;
    B2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B2 models */
    for ( ; model != NULL ; model = model->B2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B2instances ; here != NULL ; here = here->B2nextInstance)
        {
            BFOO(B2DdPtr, B2DdBinding, B2dNode, B2dNode);
            BFOO(B2GgPtr, B2GgBinding, B2gNode, B2gNode);
            BFOO(B2SsPtr, B2SsBinding, B2sNode, B2sNode);
            BFOO(B2BbPtr, B2BbBinding, B2bNode, B2bNode);
            BFOO(B2DPdpPtr, B2DPdpBinding, B2dNodePrime, B2dNodePrime);
            BFOO(B2SPspPtr, B2SPspBinding, B2sNodePrime, B2sNodePrime);
            BFOO(B2DdpPtr, B2DdpBinding, B2dNode, B2dNodePrime);
            BFOO(B2GbPtr, B2GbBinding, B2gNode, B2bNode);
            BFOO(B2GdpPtr, B2GdpBinding, B2gNode, B2dNodePrime);
            BFOO(B2GspPtr, B2GspBinding, B2gNode, B2sNodePrime);
            BFOO(B2SspPtr, B2SspBinding, B2sNode, B2sNodePrime);
            BFOO(B2BdpPtr, B2BdpBinding, B2bNode, B2dNodePrime);
            BFOO(B2BspPtr, B2BspBinding, B2bNode, B2sNodePrime);
            BFOO(B2DPspPtr, B2DPspBinding, B2dNodePrime, B2sNodePrime);
            BFOO(B2DPdPtr, B2DPdBinding, B2dNodePrime, B2dNode);
            BFOO(B2BgPtr, B2BgBinding, B2bNode, B2gNode);
            BFOO(B2DPgPtr, B2DPgBinding, B2dNodePrime, B2gNode);
            BFOO(B2SPgPtr, B2SPgBinding, B2sNodePrime, B2gNode);
            BFOO(B2SPsPtr, B2SPsBinding, B2sNodePrime, B2sNode);
            BFOO(B2DPbPtr, B2DPbBinding, B2dNodePrime, B2bNode);
            BFOO(B2SPbPtr, B2SPbBinding, B2sNodePrime, B2bNode);
            BFOO(B2SPdpPtr, B2SPdpBinding, B2sNodePrime, B2dNodePrime);
        }
    }

    return (OK) ;
}

int
B2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B2model *model = (B2model *)inModel ;
    B2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B2 models */
    for ( ; model != NULL ; model = model->B2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B2instances ; here != NULL ; here = here->B2nextInstance)
        {
            CFOO(B2DdPtr, B2DdBinding, B2dNode, B2dNode);
            CFOO(B2GgPtr, B2GgBinding, B2gNode, B2gNode);
            CFOO(B2SsPtr, B2SsBinding, B2sNode, B2sNode);
            CFOO(B2BbPtr, B2BbBinding, B2bNode, B2bNode);
            CFOO(B2DPdpPtr, B2DPdpBinding, B2dNodePrime, B2dNodePrime);
            CFOO(B2SPspPtr, B2SPspBinding, B2sNodePrime, B2sNodePrime);
            CFOO(B2DdpPtr, B2DdpBinding, B2dNode, B2dNodePrime);
            CFOO(B2GbPtr, B2GbBinding, B2gNode, B2bNode);
            CFOO(B2GdpPtr, B2GdpBinding, B2gNode, B2dNodePrime);
            CFOO(B2GspPtr, B2GspBinding, B2gNode, B2sNodePrime);
            CFOO(B2SspPtr, B2SspBinding, B2sNode, B2sNodePrime);
            CFOO(B2BdpPtr, B2BdpBinding, B2bNode, B2dNodePrime);
            CFOO(B2BspPtr, B2BspBinding, B2bNode, B2sNodePrime);
            CFOO(B2DPspPtr, B2DPspBinding, B2dNodePrime, B2sNodePrime);
            CFOO(B2DPdPtr, B2DPdBinding, B2dNodePrime, B2dNode);
            CFOO(B2BgPtr, B2BgBinding, B2bNode, B2gNode);
            CFOO(B2DPgPtr, B2DPgBinding, B2dNodePrime, B2gNode);
            CFOO(B2SPgPtr, B2SPgBinding, B2sNodePrime, B2gNode);
            CFOO(B2SPsPtr, B2SPsBinding, B2sNodePrime, B2sNode);
            CFOO(B2DPbPtr, B2DPbBinding, B2dNodePrime, B2bNode);
            CFOO(B2SPbPtr, B2SPbBinding, B2sNodePrime, B2bNode);
            CFOO(B2SPdpPtr, B2SPdpBinding, B2sNodePrime, B2dNodePrime);
        }
    }

    return (OK) ;
}
