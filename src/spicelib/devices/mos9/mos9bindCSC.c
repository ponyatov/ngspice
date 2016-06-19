/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos9defs.h"
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
MOS9bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS9model *model = (MOS9model *)inModel ;
    MOS9instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS9 models */
    for ( ; model != NULL ; model = model->MOS9nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS9instances ; here != NULL ; here = here->MOS9nextInstance)
        {
            XFOO(MOS9DdPtr, MOS9DdBinding, MOS9dNode, MOS9dNode);
            XFOO(MOS9GgPtr, MOS9GgBinding, MOS9gNode, MOS9gNode);
            XFOO(MOS9SsPtr, MOS9SsBinding, MOS9sNode, MOS9sNode);
            XFOO(MOS9BbPtr, MOS9BbBinding, MOS9bNode, MOS9bNode);
            XFOO(MOS9DPdpPtr, MOS9DPdpBinding, MOS9dNodePrime, MOS9dNodePrime);
            XFOO(MOS9SPspPtr, MOS9SPspBinding, MOS9sNodePrime, MOS9sNodePrime);
            XFOO(MOS9DdpPtr, MOS9DdpBinding, MOS9dNode, MOS9dNodePrime);
            XFOO(MOS9GbPtr, MOS9GbBinding, MOS9gNode, MOS9bNode);
            XFOO(MOS9GdpPtr, MOS9GdpBinding, MOS9gNode, MOS9dNodePrime);
            XFOO(MOS9GspPtr, MOS9GspBinding, MOS9gNode, MOS9sNodePrime);
            XFOO(MOS9SspPtr, MOS9SspBinding, MOS9sNode, MOS9sNodePrime);
            XFOO(MOS9BdpPtr, MOS9BdpBinding, MOS9bNode, MOS9dNodePrime);
            XFOO(MOS9BspPtr, MOS9BspBinding, MOS9bNode, MOS9sNodePrime);
            XFOO(MOS9DPspPtr, MOS9DPspBinding, MOS9dNodePrime, MOS9sNodePrime);
            XFOO(MOS9DPdPtr, MOS9DPdBinding, MOS9dNodePrime, MOS9dNode);
            XFOO(MOS9BgPtr, MOS9BgBinding, MOS9bNode, MOS9gNode);
            XFOO(MOS9DPgPtr, MOS9DPgBinding, MOS9dNodePrime, MOS9gNode);
            XFOO(MOS9SPgPtr, MOS9SPgBinding, MOS9sNodePrime, MOS9gNode);
            XFOO(MOS9SPsPtr, MOS9SPsBinding, MOS9sNodePrime, MOS9sNode);
            XFOO(MOS9DPbPtr, MOS9DPbBinding, MOS9dNodePrime, MOS9bNode);
            XFOO(MOS9SPbPtr, MOS9SPbBinding, MOS9sNodePrime, MOS9bNode);
            XFOO(MOS9SPdpPtr, MOS9SPdpBinding, MOS9sNodePrime, MOS9dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS9bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS9model *model = (MOS9model *)inModel ;
    MOS9instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS9 models */
    for ( ; model != NULL ; model = model->MOS9nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS9instances ; here != NULL ; here = here->MOS9nextInstance)
        {
            BFOO(MOS9DdPtr, MOS9DdBinding, MOS9dNode, MOS9dNode);
            BFOO(MOS9GgPtr, MOS9GgBinding, MOS9gNode, MOS9gNode);
            BFOO(MOS9SsPtr, MOS9SsBinding, MOS9sNode, MOS9sNode);
            BFOO(MOS9BbPtr, MOS9BbBinding, MOS9bNode, MOS9bNode);
            BFOO(MOS9DPdpPtr, MOS9DPdpBinding, MOS9dNodePrime, MOS9dNodePrime);
            BFOO(MOS9SPspPtr, MOS9SPspBinding, MOS9sNodePrime, MOS9sNodePrime);
            BFOO(MOS9DdpPtr, MOS9DdpBinding, MOS9dNode, MOS9dNodePrime);
            BFOO(MOS9GbPtr, MOS9GbBinding, MOS9gNode, MOS9bNode);
            BFOO(MOS9GdpPtr, MOS9GdpBinding, MOS9gNode, MOS9dNodePrime);
            BFOO(MOS9GspPtr, MOS9GspBinding, MOS9gNode, MOS9sNodePrime);
            BFOO(MOS9SspPtr, MOS9SspBinding, MOS9sNode, MOS9sNodePrime);
            BFOO(MOS9BdpPtr, MOS9BdpBinding, MOS9bNode, MOS9dNodePrime);
            BFOO(MOS9BspPtr, MOS9BspBinding, MOS9bNode, MOS9sNodePrime);
            BFOO(MOS9DPspPtr, MOS9DPspBinding, MOS9dNodePrime, MOS9sNodePrime);
            BFOO(MOS9DPdPtr, MOS9DPdBinding, MOS9dNodePrime, MOS9dNode);
            BFOO(MOS9BgPtr, MOS9BgBinding, MOS9bNode, MOS9gNode);
            BFOO(MOS9DPgPtr, MOS9DPgBinding, MOS9dNodePrime, MOS9gNode);
            BFOO(MOS9SPgPtr, MOS9SPgBinding, MOS9sNodePrime, MOS9gNode);
            BFOO(MOS9SPsPtr, MOS9SPsBinding, MOS9sNodePrime, MOS9sNode);
            BFOO(MOS9DPbPtr, MOS9DPbBinding, MOS9dNodePrime, MOS9bNode);
            BFOO(MOS9SPbPtr, MOS9SPbBinding, MOS9sNodePrime, MOS9bNode);
            BFOO(MOS9SPdpPtr, MOS9SPdpBinding, MOS9sNodePrime, MOS9dNodePrime);
        }
    }

    return (OK) ;
}

int
MOS9bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS9model *model = (MOS9model *)inModel ;
    MOS9instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS9 models */
    for ( ; model != NULL ; model = model->MOS9nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS9instances ; here != NULL ; here = here->MOS9nextInstance)
        {
            CFOO(MOS9DdPtr, MOS9DdBinding, MOS9dNode, MOS9dNode);
            CFOO(MOS9GgPtr, MOS9GgBinding, MOS9gNode, MOS9gNode);
            CFOO(MOS9SsPtr, MOS9SsBinding, MOS9sNode, MOS9sNode);
            CFOO(MOS9BbPtr, MOS9BbBinding, MOS9bNode, MOS9bNode);
            CFOO(MOS9DPdpPtr, MOS9DPdpBinding, MOS9dNodePrime, MOS9dNodePrime);
            CFOO(MOS9SPspPtr, MOS9SPspBinding, MOS9sNodePrime, MOS9sNodePrime);
            CFOO(MOS9DdpPtr, MOS9DdpBinding, MOS9dNode, MOS9dNodePrime);
            CFOO(MOS9GbPtr, MOS9GbBinding, MOS9gNode, MOS9bNode);
            CFOO(MOS9GdpPtr, MOS9GdpBinding, MOS9gNode, MOS9dNodePrime);
            CFOO(MOS9GspPtr, MOS9GspBinding, MOS9gNode, MOS9sNodePrime);
            CFOO(MOS9SspPtr, MOS9SspBinding, MOS9sNode, MOS9sNodePrime);
            CFOO(MOS9BdpPtr, MOS9BdpBinding, MOS9bNode, MOS9dNodePrime);
            CFOO(MOS9BspPtr, MOS9BspBinding, MOS9bNode, MOS9sNodePrime);
            CFOO(MOS9DPspPtr, MOS9DPspBinding, MOS9dNodePrime, MOS9sNodePrime);
            CFOO(MOS9DPdPtr, MOS9DPdBinding, MOS9dNodePrime, MOS9dNode);
            CFOO(MOS9BgPtr, MOS9BgBinding, MOS9bNode, MOS9gNode);
            CFOO(MOS9DPgPtr, MOS9DPgBinding, MOS9dNodePrime, MOS9gNode);
            CFOO(MOS9SPgPtr, MOS9SPgBinding, MOS9sNodePrime, MOS9gNode);
            CFOO(MOS9SPsPtr, MOS9SPsBinding, MOS9sNodePrime, MOS9sNode);
            CFOO(MOS9DPbPtr, MOS9DPbBinding, MOS9dNodePrime, MOS9bNode);
            CFOO(MOS9SPbPtr, MOS9SPbBinding, MOS9sNodePrime, MOS9bNode);
            CFOO(MOS9SPdpPtr, MOS9SPdpBinding, MOS9sNodePrime, MOS9dNodePrime);
        }
    }

    return (OK) ;
}
