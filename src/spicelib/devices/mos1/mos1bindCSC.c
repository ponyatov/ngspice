/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos1defs.h"
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
MOS1bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS1model *model = (MOS1model *)inModel ;
    MOS1instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS1 models */
    for ( ; model != NULL ; model = model->MOS1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS1instances ; here != NULL ; here = here->MOS1nextInstance)
        {
            XFOO(MOS1DdPtr, MOS1DdBinding, MOS1dNode, MOS1dNode);
            XFOO(MOS1GgPtr, MOS1GgBinding, MOS1gNode, MOS1gNode);
            XFOO(MOS1SsPtr, MOS1SsBinding, MOS1sNode, MOS1sNode);
            XFOO(MOS1BbPtr, MOS1BbBinding, MOS1bNode, MOS1bNode);
            XFOO(MOS1DPdpPtr, MOS1DPdpBinding, MOS1dNodePrime, MOS1dNodePrime);
            XFOO(MOS1SPspPtr, MOS1SPspBinding, MOS1sNodePrime, MOS1sNodePrime);
            XFOO(MOS1DdpPtr, MOS1DdpBinding, MOS1dNode, MOS1dNodePrime);
            XFOO(MOS1GbPtr, MOS1GbBinding, MOS1gNode, MOS1bNode);
            XFOO(MOS1GdpPtr, MOS1GdpBinding, MOS1gNode, MOS1dNodePrime);
            XFOO(MOS1GspPtr, MOS1GspBinding, MOS1gNode, MOS1sNodePrime);
            XFOO(MOS1SspPtr, MOS1SspBinding, MOS1sNode, MOS1sNodePrime);
            XFOO(MOS1BdpPtr, MOS1BdpBinding, MOS1bNode, MOS1dNodePrime);
            XFOO(MOS1BspPtr, MOS1BspBinding, MOS1bNode, MOS1sNodePrime);
            XFOO(MOS1DPspPtr, MOS1DPspBinding, MOS1dNodePrime, MOS1sNodePrime);
            XFOO(MOS1DPdPtr, MOS1DPdBinding, MOS1dNodePrime, MOS1dNode);
            XFOO(MOS1BgPtr, MOS1BgBinding, MOS1bNode, MOS1gNode);
            XFOO(MOS1DPgPtr, MOS1DPgBinding, MOS1dNodePrime, MOS1gNode);
            XFOO(MOS1SPgPtr, MOS1SPgBinding, MOS1sNodePrime, MOS1gNode);
            XFOO(MOS1SPsPtr, MOS1SPsBinding, MOS1sNodePrime, MOS1sNode);
            XFOO(MOS1DPbPtr, MOS1DPbBinding, MOS1dNodePrime, MOS1bNode);
            XFOO(MOS1SPbPtr, MOS1SPbBinding, MOS1sNodePrime, MOS1bNode);
            XFOO(MOS1SPdpPtr, MOS1SPdpBinding, MOS1sNodePrime, MOS1dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS1bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS1model *model = (MOS1model *)inModel ;
    MOS1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS1 models */
    for ( ; model != NULL ; model = model->MOS1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS1instances ; here != NULL ; here = here->MOS1nextInstance)
        {
            BFOO(MOS1DdPtr, MOS1DdBinding, MOS1dNode, MOS1dNode);
            BFOO(MOS1GgPtr, MOS1GgBinding, MOS1gNode, MOS1gNode);
            BFOO(MOS1SsPtr, MOS1SsBinding, MOS1sNode, MOS1sNode);
            BFOO(MOS1BbPtr, MOS1BbBinding, MOS1bNode, MOS1bNode);
            BFOO(MOS1DPdpPtr, MOS1DPdpBinding, MOS1dNodePrime, MOS1dNodePrime);
            BFOO(MOS1SPspPtr, MOS1SPspBinding, MOS1sNodePrime, MOS1sNodePrime);
            BFOO(MOS1DdpPtr, MOS1DdpBinding, MOS1dNode, MOS1dNodePrime);
            BFOO(MOS1GbPtr, MOS1GbBinding, MOS1gNode, MOS1bNode);
            BFOO(MOS1GdpPtr, MOS1GdpBinding, MOS1gNode, MOS1dNodePrime);
            BFOO(MOS1GspPtr, MOS1GspBinding, MOS1gNode, MOS1sNodePrime);
            BFOO(MOS1SspPtr, MOS1SspBinding, MOS1sNode, MOS1sNodePrime);
            BFOO(MOS1BdpPtr, MOS1BdpBinding, MOS1bNode, MOS1dNodePrime);
            BFOO(MOS1BspPtr, MOS1BspBinding, MOS1bNode, MOS1sNodePrime);
            BFOO(MOS1DPspPtr, MOS1DPspBinding, MOS1dNodePrime, MOS1sNodePrime);
            BFOO(MOS1DPdPtr, MOS1DPdBinding, MOS1dNodePrime, MOS1dNode);
            BFOO(MOS1BgPtr, MOS1BgBinding, MOS1bNode, MOS1gNode);
            BFOO(MOS1DPgPtr, MOS1DPgBinding, MOS1dNodePrime, MOS1gNode);
            BFOO(MOS1SPgPtr, MOS1SPgBinding, MOS1sNodePrime, MOS1gNode);
            BFOO(MOS1SPsPtr, MOS1SPsBinding, MOS1sNodePrime, MOS1sNode);
            BFOO(MOS1DPbPtr, MOS1DPbBinding, MOS1dNodePrime, MOS1bNode);
            BFOO(MOS1SPbPtr, MOS1SPbBinding, MOS1sNodePrime, MOS1bNode);
            BFOO(MOS1SPdpPtr, MOS1SPdpBinding, MOS1sNodePrime, MOS1dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS1bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS1model *model = (MOS1model *)inModel ;
    MOS1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS1 models */
    for ( ; model != NULL ; model = model->MOS1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS1instances ; here != NULL ; here = here->MOS1nextInstance)
        {
            CFOO(MOS1DdPtr, MOS1DdBinding, MOS1dNode, MOS1dNode);
            CFOO(MOS1GgPtr, MOS1GgBinding, MOS1gNode, MOS1gNode);
            CFOO(MOS1SsPtr, MOS1SsBinding, MOS1sNode, MOS1sNode);
            CFOO(MOS1BbPtr, MOS1BbBinding, MOS1bNode, MOS1bNode);
            CFOO(MOS1DPdpPtr, MOS1DPdpBinding, MOS1dNodePrime, MOS1dNodePrime);
            CFOO(MOS1SPspPtr, MOS1SPspBinding, MOS1sNodePrime, MOS1sNodePrime);
            CFOO(MOS1DdpPtr, MOS1DdpBinding, MOS1dNode, MOS1dNodePrime);
            CFOO(MOS1GbPtr, MOS1GbBinding, MOS1gNode, MOS1bNode);
            CFOO(MOS1GdpPtr, MOS1GdpBinding, MOS1gNode, MOS1dNodePrime);
            CFOO(MOS1GspPtr, MOS1GspBinding, MOS1gNode, MOS1sNodePrime);
            CFOO(MOS1SspPtr, MOS1SspBinding, MOS1sNode, MOS1sNodePrime);
            CFOO(MOS1BdpPtr, MOS1BdpBinding, MOS1bNode, MOS1dNodePrime);
            CFOO(MOS1BspPtr, MOS1BspBinding, MOS1bNode, MOS1sNodePrime);
            CFOO(MOS1DPspPtr, MOS1DPspBinding, MOS1dNodePrime, MOS1sNodePrime);
            CFOO(MOS1DPdPtr, MOS1DPdBinding, MOS1dNodePrime, MOS1dNode);
            CFOO(MOS1BgPtr, MOS1BgBinding, MOS1bNode, MOS1gNode);
            CFOO(MOS1DPgPtr, MOS1DPgBinding, MOS1dNodePrime, MOS1gNode);
            CFOO(MOS1SPgPtr, MOS1SPgBinding, MOS1sNodePrime, MOS1gNode);
            CFOO(MOS1SPsPtr, MOS1SPsBinding, MOS1sNodePrime, MOS1sNode);
            CFOO(MOS1DPbPtr, MOS1DPbBinding, MOS1dNodePrime, MOS1bNode);
            CFOO(MOS1SPbPtr, MOS1SPbBinding, MOS1sNodePrime, MOS1bNode);
            CFOO(MOS1SPdpPtr, MOS1SPdpBinding, MOS1sNodePrime, MOS1dNodePrime);
        }
    }

    return (OK) ;
}
