/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim1def.h"
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
B1bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B1model *model = (B1model *)inModel ;
    B1instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B1 models */
    for ( ; model != NULL ; model = model->B1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B1instances ; here != NULL ; here = here->B1nextInstance)
        {
            XFOO(B1DdPtr, B1DdBinding, B1dNode, B1dNode);
            XFOO(B1GgPtr, B1GgBinding, B1gNode, B1gNode);
            XFOO(B1SsPtr, B1SsBinding, B1sNode, B1sNode);
            XFOO(B1BbPtr, B1BbBinding, B1bNode, B1bNode);
            XFOO(B1DPdpPtr, B1DPdpBinding, B1dNodePrime, B1dNodePrime);
            XFOO(B1SPspPtr, B1SPspBinding, B1sNodePrime, B1sNodePrime);
            XFOO(B1DdpPtr, B1DdpBinding, B1dNode, B1dNodePrime);
            XFOO(B1GbPtr, B1GbBinding, B1gNode, B1bNode);
            XFOO(B1GdpPtr, B1GdpBinding, B1gNode, B1dNodePrime);
            XFOO(B1GspPtr, B1GspBinding, B1gNode, B1sNodePrime);
            XFOO(B1SspPtr, B1SspBinding, B1sNode, B1sNodePrime);
            XFOO(B1BdpPtr, B1BdpBinding, B1bNode, B1dNodePrime);
            XFOO(B1BspPtr, B1BspBinding, B1bNode, B1sNodePrime);
            XFOO(B1DPspPtr, B1DPspBinding, B1dNodePrime, B1sNodePrime);
            XFOO(B1DPdPtr, B1DPdBinding, B1dNodePrime, B1dNode);
            XFOO(B1BgPtr, B1BgBinding, B1bNode, B1gNode);
            XFOO(B1DPgPtr, B1DPgBinding, B1dNodePrime, B1gNode);
            XFOO(B1SPgPtr, B1SPgBinding, B1sNodePrime, B1gNode);
            XFOO(B1SPsPtr, B1SPsBinding, B1sNodePrime, B1sNode);
            XFOO(B1DPbPtr, B1DPbBinding, B1dNodePrime, B1bNode);
            XFOO(B1SPbPtr, B1SPbBinding, B1sNodePrime, B1bNode);
            XFOO(B1SPdpPtr, B1SPdpBinding, B1sNodePrime, B1dNodePrime);
        }
    }

    return (OK) ;
}

int
B1bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B1model *model = (B1model *)inModel ;
    B1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B1 models */
    for ( ; model != NULL ; model = model->B1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B1instances ; here != NULL ; here = here->B1nextInstance)
        {
            BFOO(B1DdPtr, B1DdBinding, B1dNode, B1dNode);
            BFOO(B1GgPtr, B1GgBinding, B1gNode, B1gNode);
            BFOO(B1SsPtr, B1SsBinding, B1sNode, B1sNode);
            BFOO(B1BbPtr, B1BbBinding, B1bNode, B1bNode);
            BFOO(B1DPdpPtr, B1DPdpBinding, B1dNodePrime, B1dNodePrime);
            BFOO(B1SPspPtr, B1SPspBinding, B1sNodePrime, B1sNodePrime);
            BFOO(B1DdpPtr, B1DdpBinding, B1dNode, B1dNodePrime);
            BFOO(B1GbPtr, B1GbBinding, B1gNode, B1bNode);
            BFOO(B1GdpPtr, B1GdpBinding, B1gNode, B1dNodePrime);
            BFOO(B1GspPtr, B1GspBinding, B1gNode, B1sNodePrime);
            BFOO(B1SspPtr, B1SspBinding, B1sNode, B1sNodePrime);
            BFOO(B1BdpPtr, B1BdpBinding, B1bNode, B1dNodePrime);
            BFOO(B1BspPtr, B1BspBinding, B1bNode, B1sNodePrime);
            BFOO(B1DPspPtr, B1DPspBinding, B1dNodePrime, B1sNodePrime);
            BFOO(B1DPdPtr, B1DPdBinding, B1dNodePrime, B1dNode);
            BFOO(B1BgPtr, B1BgBinding, B1bNode, B1gNode);
            BFOO(B1DPgPtr, B1DPgBinding, B1dNodePrime, B1gNode);
            BFOO(B1SPgPtr, B1SPgBinding, B1sNodePrime, B1gNode);
            BFOO(B1SPsPtr, B1SPsBinding, B1sNodePrime, B1sNode);
            BFOO(B1DPbPtr, B1DPbBinding, B1dNodePrime, B1bNode);
            BFOO(B1SPbPtr, B1SPbBinding, B1sNodePrime, B1bNode);
            BFOO(B1SPdpPtr, B1SPdpBinding, B1sNodePrime, B1dNodePrime);
        }
    }

    return (OK) ;
}

int
B1bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B1model *model = (B1model *)inModel ;
    B1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B1 models */
    for ( ; model != NULL ; model = model->B1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B1instances ; here != NULL ; here = here->B1nextInstance)
        {
            CFOO(B1DdPtr, B1DdBinding, B1dNode, B1dNode);
            CFOO(B1GgPtr, B1GgBinding, B1gNode, B1gNode);
            CFOO(B1SsPtr, B1SsBinding, B1sNode, B1sNode);
            CFOO(B1BbPtr, B1BbBinding, B1bNode, B1bNode);
            CFOO(B1DPdpPtr, B1DPdpBinding, B1dNodePrime, B1dNodePrime);
            CFOO(B1SPspPtr, B1SPspBinding, B1sNodePrime, B1sNodePrime);
            CFOO(B1DdpPtr, B1DdpBinding, B1dNode, B1dNodePrime);
            CFOO(B1GbPtr, B1GbBinding, B1gNode, B1bNode);
            CFOO(B1GdpPtr, B1GdpBinding, B1gNode, B1dNodePrime);
            CFOO(B1GspPtr, B1GspBinding, B1gNode, B1sNodePrime);
            CFOO(B1SspPtr, B1SspBinding, B1sNode, B1sNodePrime);
            CFOO(B1BdpPtr, B1BdpBinding, B1bNode, B1dNodePrime);
            CFOO(B1BspPtr, B1BspBinding, B1bNode, B1sNodePrime);
            CFOO(B1DPspPtr, B1DPspBinding, B1dNodePrime, B1sNodePrime);
            CFOO(B1DPdPtr, B1DPdBinding, B1dNodePrime, B1dNode);
            CFOO(B1BgPtr, B1BgBinding, B1bNode, B1gNode);
            CFOO(B1DPgPtr, B1DPgBinding, B1dNodePrime, B1gNode);
            CFOO(B1SPgPtr, B1SPgBinding, B1sNodePrime, B1gNode);
            CFOO(B1SPsPtr, B1SPsBinding, B1sNodePrime, B1sNode);
            CFOO(B1DPbPtr, B1DPbBinding, B1dNodePrime, B1bNode);
            CFOO(B1SPbPtr, B1SPbBinding, B1sNodePrime, B1bNode);
            CFOO(B1SPdpPtr, B1SPdpBinding, B1sNodePrime, B1dNodePrime);
        }
    }

    return (OK) ;
}
