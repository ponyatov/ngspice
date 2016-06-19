/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim4v6def.h"
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
BSIM4v6bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v6model *model = (BSIM4v6model *)inModel ;
    BSIM4v6instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM4v6 models */
    for ( ; model != NULL ; model = model->BSIM4v6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v6instances ; here != NULL ; here = here->BSIM4v6nextInstance)
        {
            XFOO(BSIM4v6DPbpPtr, BSIM4v6DPbpBinding, BSIM4v6dNodePrime, BSIM4v6bNodePrime);
            XFOO(BSIM4v6GPbpPtr, BSIM4v6GPbpBinding, BSIM4v6gNodePrime, BSIM4v6bNodePrime);
            XFOO(BSIM4v6SPbpPtr, BSIM4v6SPbpBinding, BSIM4v6sNodePrime, BSIM4v6bNodePrime);
            XFOO(BSIM4v6BPdpPtr, BSIM4v6BPdpBinding, BSIM4v6bNodePrime, BSIM4v6dNodePrime);
            XFOO(BSIM4v6BPgpPtr, BSIM4v6BPgpBinding, BSIM4v6bNodePrime, BSIM4v6gNodePrime);
            XFOO(BSIM4v6BPspPtr, BSIM4v6BPspBinding, BSIM4v6bNodePrime, BSIM4v6sNodePrime);
            XFOO(BSIM4v6BPbpPtr, BSIM4v6BPbpBinding, BSIM4v6bNodePrime, BSIM4v6bNodePrime);
            XFOO(BSIM4v6DdPtr, BSIM4v6DdBinding, BSIM4v6dNode, BSIM4v6dNode);
            XFOO(BSIM4v6GPgpPtr, BSIM4v6GPgpBinding, BSIM4v6gNodePrime, BSIM4v6gNodePrime);
            XFOO(BSIM4v6SsPtr, BSIM4v6SsBinding, BSIM4v6sNode, BSIM4v6sNode);
            XFOO(BSIM4v6DPdpPtr, BSIM4v6DPdpBinding, BSIM4v6dNodePrime, BSIM4v6dNodePrime);
            XFOO(BSIM4v6SPspPtr, BSIM4v6SPspBinding, BSIM4v6sNodePrime, BSIM4v6sNodePrime);
            XFOO(BSIM4v6DdpPtr, BSIM4v6DdpBinding, BSIM4v6dNode, BSIM4v6dNodePrime);
            XFOO(BSIM4v6GPdpPtr, BSIM4v6GPdpBinding, BSIM4v6gNodePrime, BSIM4v6dNodePrime);
            XFOO(BSIM4v6GPspPtr, BSIM4v6GPspBinding, BSIM4v6gNodePrime, BSIM4v6sNodePrime);
            XFOO(BSIM4v6SspPtr, BSIM4v6SspBinding, BSIM4v6sNode, BSIM4v6sNodePrime);
            XFOO(BSIM4v6DPspPtr, BSIM4v6DPspBinding, BSIM4v6dNodePrime, BSIM4v6sNodePrime);
            XFOO(BSIM4v6DPdPtr, BSIM4v6DPdBinding, BSIM4v6dNodePrime, BSIM4v6dNode);
            XFOO(BSIM4v6DPgpPtr, BSIM4v6DPgpBinding, BSIM4v6dNodePrime, BSIM4v6gNodePrime);
            XFOO(BSIM4v6SPgpPtr, BSIM4v6SPgpBinding, BSIM4v6sNodePrime, BSIM4v6gNodePrime);
            XFOO(BSIM4v6SPsPtr, BSIM4v6SPsBinding, BSIM4v6sNodePrime, BSIM4v6sNode);
            XFOO(BSIM4v6SPdpPtr, BSIM4v6SPdpBinding, BSIM4v6sNodePrime, BSIM4v6dNodePrime);
            XFOO(BSIM4v6QqPtr, BSIM4v6QqBinding, BSIM4v6qNode, BSIM4v6qNode);
            XFOO(BSIM4v6QbpPtr, BSIM4v6QbpBinding, BSIM4v6qNode, BSIM4v6bNodePrime);
            XFOO(BSIM4v6QdpPtr, BSIM4v6QdpBinding, BSIM4v6qNode, BSIM4v6dNodePrime);
            XFOO(BSIM4v6QspPtr, BSIM4v6QspBinding, BSIM4v6qNode, BSIM4v6sNodePrime);
            XFOO(BSIM4v6QgpPtr, BSIM4v6QgpBinding, BSIM4v6qNode, BSIM4v6gNodePrime);
            XFOO(BSIM4v6DPqPtr, BSIM4v6DPqBinding, BSIM4v6dNodePrime, BSIM4v6qNode);
            XFOO(BSIM4v6SPqPtr, BSIM4v6SPqBinding, BSIM4v6sNodePrime, BSIM4v6qNode);
            XFOO(BSIM4v6GPqPtr, BSIM4v6GPqBinding, BSIM4v6gNodePrime, BSIM4v6qNode);
            if (here->BSIM4v6rgateMod != 0)
            {
                XFOO(BSIM4v6GEgePtr, BSIM4v6GEgeBinding, BSIM4v6gNodeExt, BSIM4v6gNodeExt);
                XFOO(BSIM4v6GEgpPtr, BSIM4v6GEgpBinding, BSIM4v6gNodeExt, BSIM4v6gNodePrime);
                XFOO(BSIM4v6GPgePtr, BSIM4v6GPgeBinding, BSIM4v6gNodePrime, BSIM4v6gNodeExt);
                XFOO(BSIM4v6GEdpPtr, BSIM4v6GEdpBinding, BSIM4v6gNodeExt, BSIM4v6dNodePrime);
                XFOO(BSIM4v6GEspPtr, BSIM4v6GEspBinding, BSIM4v6gNodeExt, BSIM4v6sNodePrime);
                XFOO(BSIM4v6GEbpPtr, BSIM4v6GEbpBinding, BSIM4v6gNodeExt, BSIM4v6bNodePrime);
                XFOO(BSIM4v6GMdpPtr, BSIM4v6GMdpBinding, BSIM4v6gNodeMid, BSIM4v6dNodePrime);
                XFOO(BSIM4v6GMgpPtr, BSIM4v6GMgpBinding, BSIM4v6gNodeMid, BSIM4v6gNodePrime);
                XFOO(BSIM4v6GMgmPtr, BSIM4v6GMgmBinding, BSIM4v6gNodeMid, BSIM4v6gNodeMid);
                XFOO(BSIM4v6GMgePtr, BSIM4v6GMgeBinding, BSIM4v6gNodeMid, BSIM4v6gNodeExt);
                XFOO(BSIM4v6GMspPtr, BSIM4v6GMspBinding, BSIM4v6gNodeMid, BSIM4v6sNodePrime);
                XFOO(BSIM4v6GMbpPtr, BSIM4v6GMbpBinding, BSIM4v6gNodeMid, BSIM4v6bNodePrime);
                XFOO(BSIM4v6DPgmPtr, BSIM4v6DPgmBinding, BSIM4v6dNodePrime, BSIM4v6gNodeMid);
                XFOO(BSIM4v6GPgmPtr, BSIM4v6GPgmBinding, BSIM4v6gNodePrime, BSIM4v6gNodeMid);
                XFOO(BSIM4v6GEgmPtr, BSIM4v6GEgmBinding, BSIM4v6gNodeExt, BSIM4v6gNodeMid);
                XFOO(BSIM4v6SPgmPtr, BSIM4v6SPgmBinding, BSIM4v6sNodePrime, BSIM4v6gNodeMid);
                XFOO(BSIM4v6BPgmPtr, BSIM4v6BPgmBinding, BSIM4v6bNodePrime, BSIM4v6gNodeMid);
            }
            if ((here->BSIM4v6rbodyMod == 1) || (here->BSIM4v6rbodyMod == 2))
            {
                XFOO(BSIM4v6DPdbPtr, BSIM4v6DPdbBinding, BSIM4v6dNodePrime, BSIM4v6dbNode);
                XFOO(BSIM4v6SPsbPtr, BSIM4v6SPsbBinding, BSIM4v6sNodePrime, BSIM4v6sbNode);
                XFOO(BSIM4v6DBdpPtr, BSIM4v6DBdpBinding, BSIM4v6dbNode, BSIM4v6dNodePrime);
                XFOO(BSIM4v6DBdbPtr, BSIM4v6DBdbBinding, BSIM4v6dbNode, BSIM4v6dbNode);
                XFOO(BSIM4v6DBbpPtr, BSIM4v6DBbpBinding, BSIM4v6dbNode, BSIM4v6bNodePrime);
                XFOO(BSIM4v6DBbPtr, BSIM4v6DBbBinding, BSIM4v6dbNode, BSIM4v6bNode);
                XFOO(BSIM4v6BPdbPtr, BSIM4v6BPdbBinding, BSIM4v6bNodePrime, BSIM4v6dbNode);
                XFOO(BSIM4v6BPbPtr, BSIM4v6BPbBinding, BSIM4v6bNodePrime, BSIM4v6bNode);
                XFOO(BSIM4v6BPsbPtr, BSIM4v6BPsbBinding, BSIM4v6bNodePrime, BSIM4v6sbNode);
                XFOO(BSIM4v6SBspPtr, BSIM4v6SBspBinding, BSIM4v6sbNode, BSIM4v6sNodePrime);
                XFOO(BSIM4v6SBbpPtr, BSIM4v6SBbpBinding, BSIM4v6sbNode, BSIM4v6bNodePrime);
                XFOO(BSIM4v6SBbPtr, BSIM4v6SBbBinding, BSIM4v6sbNode, BSIM4v6bNode);
                XFOO(BSIM4v6SBsbPtr, BSIM4v6SBsbBinding, BSIM4v6sbNode, BSIM4v6sbNode);
                XFOO(BSIM4v6BdbPtr, BSIM4v6BdbBinding, BSIM4v6bNode, BSIM4v6dbNode);
                XFOO(BSIM4v6BbpPtr, BSIM4v6BbpBinding, BSIM4v6bNode, BSIM4v6bNodePrime);
                XFOO(BSIM4v6BsbPtr, BSIM4v6BsbBinding, BSIM4v6bNode, BSIM4v6sbNode);
                XFOO(BSIM4v6BbPtr, BSIM4v6BbBinding, BSIM4v6bNode, BSIM4v6bNode);
            }
            if (model->BSIM4v6rdsMod)
            {
                XFOO(BSIM4v6DgpPtr, BSIM4v6DgpBinding, BSIM4v6dNode, BSIM4v6gNodePrime);
                XFOO(BSIM4v6DspPtr, BSIM4v6DspBinding, BSIM4v6dNode, BSIM4v6sNodePrime);
                XFOO(BSIM4v6DbpPtr, BSIM4v6DbpBinding, BSIM4v6dNode, BSIM4v6bNodePrime);
                XFOO(BSIM4v6SdpPtr, BSIM4v6SdpBinding, BSIM4v6sNode, BSIM4v6dNodePrime);
                XFOO(BSIM4v6SgpPtr, BSIM4v6SgpBinding, BSIM4v6sNode, BSIM4v6gNodePrime);
                XFOO(BSIM4v6SbpPtr, BSIM4v6SbpBinding, BSIM4v6sNode, BSIM4v6bNodePrime);
            }
        }
    }

    return (OK) ;
}

int
BSIM4v6bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v6model *model = (BSIM4v6model *)inModel ;
    BSIM4v6instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4v6 models */
    for ( ; model != NULL ; model = model->BSIM4v6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v6instances ; here != NULL ; here = here->BSIM4v6nextInstance)
        {
            BFOO(BSIM4v6DPbpPtr, BSIM4v6DPbpBinding, BSIM4v6dNodePrime, BSIM4v6bNodePrime);
            BFOO(BSIM4v6GPbpPtr, BSIM4v6GPbpBinding, BSIM4v6gNodePrime, BSIM4v6bNodePrime);
            BFOO(BSIM4v6SPbpPtr, BSIM4v6SPbpBinding, BSIM4v6sNodePrime, BSIM4v6bNodePrime);
            BFOO(BSIM4v6BPdpPtr, BSIM4v6BPdpBinding, BSIM4v6bNodePrime, BSIM4v6dNodePrime);
            BFOO(BSIM4v6BPgpPtr, BSIM4v6BPgpBinding, BSIM4v6bNodePrime, BSIM4v6gNodePrime);
            BFOO(BSIM4v6BPspPtr, BSIM4v6BPspBinding, BSIM4v6bNodePrime, BSIM4v6sNodePrime);
            BFOO(BSIM4v6BPbpPtr, BSIM4v6BPbpBinding, BSIM4v6bNodePrime, BSIM4v6bNodePrime);
            BFOO(BSIM4v6DdPtr, BSIM4v6DdBinding, BSIM4v6dNode, BSIM4v6dNode);
            BFOO(BSIM4v6GPgpPtr, BSIM4v6GPgpBinding, BSIM4v6gNodePrime, BSIM4v6gNodePrime);
            BFOO(BSIM4v6SsPtr, BSIM4v6SsBinding, BSIM4v6sNode, BSIM4v6sNode);
            BFOO(BSIM4v6DPdpPtr, BSIM4v6DPdpBinding, BSIM4v6dNodePrime, BSIM4v6dNodePrime);
            BFOO(BSIM4v6SPspPtr, BSIM4v6SPspBinding, BSIM4v6sNodePrime, BSIM4v6sNodePrime);
            BFOO(BSIM4v6DdpPtr, BSIM4v6DdpBinding, BSIM4v6dNode, BSIM4v6dNodePrime);
            BFOO(BSIM4v6GPdpPtr, BSIM4v6GPdpBinding, BSIM4v6gNodePrime, BSIM4v6dNodePrime);
            BFOO(BSIM4v6GPspPtr, BSIM4v6GPspBinding, BSIM4v6gNodePrime, BSIM4v6sNodePrime);
            BFOO(BSIM4v6SspPtr, BSIM4v6SspBinding, BSIM4v6sNode, BSIM4v6sNodePrime);
            BFOO(BSIM4v6DPspPtr, BSIM4v6DPspBinding, BSIM4v6dNodePrime, BSIM4v6sNodePrime);
            BFOO(BSIM4v6DPdPtr, BSIM4v6DPdBinding, BSIM4v6dNodePrime, BSIM4v6dNode);
            BFOO(BSIM4v6DPgpPtr, BSIM4v6DPgpBinding, BSIM4v6dNodePrime, BSIM4v6gNodePrime);
            BFOO(BSIM4v6SPgpPtr, BSIM4v6SPgpBinding, BSIM4v6sNodePrime, BSIM4v6gNodePrime);
            BFOO(BSIM4v6SPsPtr, BSIM4v6SPsBinding, BSIM4v6sNodePrime, BSIM4v6sNode);
            BFOO(BSIM4v6SPdpPtr, BSIM4v6SPdpBinding, BSIM4v6sNodePrime, BSIM4v6dNodePrime);
            BFOO(BSIM4v6QqPtr, BSIM4v6QqBinding, BSIM4v6qNode, BSIM4v6qNode);
            BFOO(BSIM4v6QbpPtr, BSIM4v6QbpBinding, BSIM4v6qNode, BSIM4v6bNodePrime);
            BFOO(BSIM4v6QdpPtr, BSIM4v6QdpBinding, BSIM4v6qNode, BSIM4v6dNodePrime);
            BFOO(BSIM4v6QspPtr, BSIM4v6QspBinding, BSIM4v6qNode, BSIM4v6sNodePrime);
            BFOO(BSIM4v6QgpPtr, BSIM4v6QgpBinding, BSIM4v6qNode, BSIM4v6gNodePrime);
            BFOO(BSIM4v6DPqPtr, BSIM4v6DPqBinding, BSIM4v6dNodePrime, BSIM4v6qNode);
            BFOO(BSIM4v6SPqPtr, BSIM4v6SPqBinding, BSIM4v6sNodePrime, BSIM4v6qNode);
            BFOO(BSIM4v6GPqPtr, BSIM4v6GPqBinding, BSIM4v6gNodePrime, BSIM4v6qNode);
            if (here->BSIM4v6rgateMod != 0)
            {
                BFOO(BSIM4v6GEgePtr, BSIM4v6GEgeBinding, BSIM4v6gNodeExt, BSIM4v6gNodeExt);
                BFOO(BSIM4v6GEgpPtr, BSIM4v6GEgpBinding, BSIM4v6gNodeExt, BSIM4v6gNodePrime);
                BFOO(BSIM4v6GPgePtr, BSIM4v6GPgeBinding, BSIM4v6gNodePrime, BSIM4v6gNodeExt);
                BFOO(BSIM4v6GEdpPtr, BSIM4v6GEdpBinding, BSIM4v6gNodeExt, BSIM4v6dNodePrime);
                BFOO(BSIM4v6GEspPtr, BSIM4v6GEspBinding, BSIM4v6gNodeExt, BSIM4v6sNodePrime);
                BFOO(BSIM4v6GEbpPtr, BSIM4v6GEbpBinding, BSIM4v6gNodeExt, BSIM4v6bNodePrime);
                BFOO(BSIM4v6GMdpPtr, BSIM4v6GMdpBinding, BSIM4v6gNodeMid, BSIM4v6dNodePrime);
                BFOO(BSIM4v6GMgpPtr, BSIM4v6GMgpBinding, BSIM4v6gNodeMid, BSIM4v6gNodePrime);
                BFOO(BSIM4v6GMgmPtr, BSIM4v6GMgmBinding, BSIM4v6gNodeMid, BSIM4v6gNodeMid);
                BFOO(BSIM4v6GMgePtr, BSIM4v6GMgeBinding, BSIM4v6gNodeMid, BSIM4v6gNodeExt);
                BFOO(BSIM4v6GMspPtr, BSIM4v6GMspBinding, BSIM4v6gNodeMid, BSIM4v6sNodePrime);
                BFOO(BSIM4v6GMbpPtr, BSIM4v6GMbpBinding, BSIM4v6gNodeMid, BSIM4v6bNodePrime);
                BFOO(BSIM4v6DPgmPtr, BSIM4v6DPgmBinding, BSIM4v6dNodePrime, BSIM4v6gNodeMid);
                BFOO(BSIM4v6GPgmPtr, BSIM4v6GPgmBinding, BSIM4v6gNodePrime, BSIM4v6gNodeMid);
                BFOO(BSIM4v6GEgmPtr, BSIM4v6GEgmBinding, BSIM4v6gNodeExt, BSIM4v6gNodeMid);
                BFOO(BSIM4v6SPgmPtr, BSIM4v6SPgmBinding, BSIM4v6sNodePrime, BSIM4v6gNodeMid);
                BFOO(BSIM4v6BPgmPtr, BSIM4v6BPgmBinding, BSIM4v6bNodePrime, BSIM4v6gNodeMid);
            }
            if ((here->BSIM4v6rbodyMod == 1) || (here->BSIM4v6rbodyMod == 2))
            {
                BFOO(BSIM4v6DPdbPtr, BSIM4v6DPdbBinding, BSIM4v6dNodePrime, BSIM4v6dbNode);
                BFOO(BSIM4v6SPsbPtr, BSIM4v6SPsbBinding, BSIM4v6sNodePrime, BSIM4v6sbNode);
                BFOO(BSIM4v6DBdpPtr, BSIM4v6DBdpBinding, BSIM4v6dbNode, BSIM4v6dNodePrime);
                BFOO(BSIM4v6DBdbPtr, BSIM4v6DBdbBinding, BSIM4v6dbNode, BSIM4v6dbNode);
                BFOO(BSIM4v6DBbpPtr, BSIM4v6DBbpBinding, BSIM4v6dbNode, BSIM4v6bNodePrime);
                BFOO(BSIM4v6DBbPtr, BSIM4v6DBbBinding, BSIM4v6dbNode, BSIM4v6bNode);
                BFOO(BSIM4v6BPdbPtr, BSIM4v6BPdbBinding, BSIM4v6bNodePrime, BSIM4v6dbNode);
                BFOO(BSIM4v6BPbPtr, BSIM4v6BPbBinding, BSIM4v6bNodePrime, BSIM4v6bNode);
                BFOO(BSIM4v6BPsbPtr, BSIM4v6BPsbBinding, BSIM4v6bNodePrime, BSIM4v6sbNode);
                BFOO(BSIM4v6SBspPtr, BSIM4v6SBspBinding, BSIM4v6sbNode, BSIM4v6sNodePrime);
                BFOO(BSIM4v6SBbpPtr, BSIM4v6SBbpBinding, BSIM4v6sbNode, BSIM4v6bNodePrime);
                BFOO(BSIM4v6SBbPtr, BSIM4v6SBbBinding, BSIM4v6sbNode, BSIM4v6bNode);
                BFOO(BSIM4v6SBsbPtr, BSIM4v6SBsbBinding, BSIM4v6sbNode, BSIM4v6sbNode);
                BFOO(BSIM4v6BdbPtr, BSIM4v6BdbBinding, BSIM4v6bNode, BSIM4v6dbNode);
                BFOO(BSIM4v6BbpPtr, BSIM4v6BbpBinding, BSIM4v6bNode, BSIM4v6bNodePrime);
                BFOO(BSIM4v6BsbPtr, BSIM4v6BsbBinding, BSIM4v6bNode, BSIM4v6sbNode);
                BFOO(BSIM4v6BbPtr, BSIM4v6BbBinding, BSIM4v6bNode, BSIM4v6bNode);
            }
            if (model->BSIM4v6rdsMod)
            {
                BFOO(BSIM4v6DgpPtr, BSIM4v6DgpBinding, BSIM4v6dNode, BSIM4v6gNodePrime);
                BFOO(BSIM4v6DspPtr, BSIM4v6DspBinding, BSIM4v6dNode, BSIM4v6sNodePrime);
                BFOO(BSIM4v6DbpPtr, BSIM4v6DbpBinding, BSIM4v6dNode, BSIM4v6bNodePrime);
                BFOO(BSIM4v6SdpPtr, BSIM4v6SdpBinding, BSIM4v6sNode, BSIM4v6dNodePrime);
                BFOO(BSIM4v6SgpPtr, BSIM4v6SgpBinding, BSIM4v6sNode, BSIM4v6gNodePrime);
                BFOO(BSIM4v6SbpPtr, BSIM4v6SbpBinding, BSIM4v6sNode, BSIM4v6bNodePrime);
            }
        }
    }

    return (OK) ;
}

int
BSIM4v6bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v6model *model = (BSIM4v6model *)inModel ;
    BSIM4v6instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4v6 models */
    for ( ; model != NULL ; model = model->BSIM4v6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v6instances ; here != NULL ; here = here->BSIM4v6nextInstance)
        {
            CFOO(BSIM4v6DPbpPtr, BSIM4v6DPbpBinding, BSIM4v6dNodePrime, BSIM4v6bNodePrime);
            CFOO(BSIM4v6GPbpPtr, BSIM4v6GPbpBinding, BSIM4v6gNodePrime, BSIM4v6bNodePrime);
            CFOO(BSIM4v6SPbpPtr, BSIM4v6SPbpBinding, BSIM4v6sNodePrime, BSIM4v6bNodePrime);
            CFOO(BSIM4v6BPdpPtr, BSIM4v6BPdpBinding, BSIM4v6bNodePrime, BSIM4v6dNodePrime);
            CFOO(BSIM4v6BPgpPtr, BSIM4v6BPgpBinding, BSIM4v6bNodePrime, BSIM4v6gNodePrime);
            CFOO(BSIM4v6BPspPtr, BSIM4v6BPspBinding, BSIM4v6bNodePrime, BSIM4v6sNodePrime);
            CFOO(BSIM4v6BPbpPtr, BSIM4v6BPbpBinding, BSIM4v6bNodePrime, BSIM4v6bNodePrime);
            CFOO(BSIM4v6DdPtr, BSIM4v6DdBinding, BSIM4v6dNode, BSIM4v6dNode);
            CFOO(BSIM4v6GPgpPtr, BSIM4v6GPgpBinding, BSIM4v6gNodePrime, BSIM4v6gNodePrime);
            CFOO(BSIM4v6SsPtr, BSIM4v6SsBinding, BSIM4v6sNode, BSIM4v6sNode);
            CFOO(BSIM4v6DPdpPtr, BSIM4v6DPdpBinding, BSIM4v6dNodePrime, BSIM4v6dNodePrime);
            CFOO(BSIM4v6SPspPtr, BSIM4v6SPspBinding, BSIM4v6sNodePrime, BSIM4v6sNodePrime);
            CFOO(BSIM4v6DdpPtr, BSIM4v6DdpBinding, BSIM4v6dNode, BSIM4v6dNodePrime);
            CFOO(BSIM4v6GPdpPtr, BSIM4v6GPdpBinding, BSIM4v6gNodePrime, BSIM4v6dNodePrime);
            CFOO(BSIM4v6GPspPtr, BSIM4v6GPspBinding, BSIM4v6gNodePrime, BSIM4v6sNodePrime);
            CFOO(BSIM4v6SspPtr, BSIM4v6SspBinding, BSIM4v6sNode, BSIM4v6sNodePrime);
            CFOO(BSIM4v6DPspPtr, BSIM4v6DPspBinding, BSIM4v6dNodePrime, BSIM4v6sNodePrime);
            CFOO(BSIM4v6DPdPtr, BSIM4v6DPdBinding, BSIM4v6dNodePrime, BSIM4v6dNode);
            CFOO(BSIM4v6DPgpPtr, BSIM4v6DPgpBinding, BSIM4v6dNodePrime, BSIM4v6gNodePrime);
            CFOO(BSIM4v6SPgpPtr, BSIM4v6SPgpBinding, BSIM4v6sNodePrime, BSIM4v6gNodePrime);
            CFOO(BSIM4v6SPsPtr, BSIM4v6SPsBinding, BSIM4v6sNodePrime, BSIM4v6sNode);
            CFOO(BSIM4v6SPdpPtr, BSIM4v6SPdpBinding, BSIM4v6sNodePrime, BSIM4v6dNodePrime);
            CFOO(BSIM4v6QqPtr, BSIM4v6QqBinding, BSIM4v6qNode, BSIM4v6qNode);
            CFOO(BSIM4v6QbpPtr, BSIM4v6QbpBinding, BSIM4v6qNode, BSIM4v6bNodePrime);
            CFOO(BSIM4v6QdpPtr, BSIM4v6QdpBinding, BSIM4v6qNode, BSIM4v6dNodePrime);
            CFOO(BSIM4v6QspPtr, BSIM4v6QspBinding, BSIM4v6qNode, BSIM4v6sNodePrime);
            CFOO(BSIM4v6QgpPtr, BSIM4v6QgpBinding, BSIM4v6qNode, BSIM4v6gNodePrime);
            CFOO(BSIM4v6DPqPtr, BSIM4v6DPqBinding, BSIM4v6dNodePrime, BSIM4v6qNode);
            CFOO(BSIM4v6SPqPtr, BSIM4v6SPqBinding, BSIM4v6sNodePrime, BSIM4v6qNode);
            CFOO(BSIM4v6GPqPtr, BSIM4v6GPqBinding, BSIM4v6gNodePrime, BSIM4v6qNode);
            if (here->BSIM4v6rgateMod != 0)
            {
                CFOO(BSIM4v6GEgePtr, BSIM4v6GEgeBinding, BSIM4v6gNodeExt, BSIM4v6gNodeExt);
                CFOO(BSIM4v6GEgpPtr, BSIM4v6GEgpBinding, BSIM4v6gNodeExt, BSIM4v6gNodePrime);
                CFOO(BSIM4v6GPgePtr, BSIM4v6GPgeBinding, BSIM4v6gNodePrime, BSIM4v6gNodeExt);
                CFOO(BSIM4v6GEdpPtr, BSIM4v6GEdpBinding, BSIM4v6gNodeExt, BSIM4v6dNodePrime);
                CFOO(BSIM4v6GEspPtr, BSIM4v6GEspBinding, BSIM4v6gNodeExt, BSIM4v6sNodePrime);
                CFOO(BSIM4v6GEbpPtr, BSIM4v6GEbpBinding, BSIM4v6gNodeExt, BSIM4v6bNodePrime);
                CFOO(BSIM4v6GMdpPtr, BSIM4v6GMdpBinding, BSIM4v6gNodeMid, BSIM4v6dNodePrime);
                CFOO(BSIM4v6GMgpPtr, BSIM4v6GMgpBinding, BSIM4v6gNodeMid, BSIM4v6gNodePrime);
                CFOO(BSIM4v6GMgmPtr, BSIM4v6GMgmBinding, BSIM4v6gNodeMid, BSIM4v6gNodeMid);
                CFOO(BSIM4v6GMgePtr, BSIM4v6GMgeBinding, BSIM4v6gNodeMid, BSIM4v6gNodeExt);
                CFOO(BSIM4v6GMspPtr, BSIM4v6GMspBinding, BSIM4v6gNodeMid, BSIM4v6sNodePrime);
                CFOO(BSIM4v6GMbpPtr, BSIM4v6GMbpBinding, BSIM4v6gNodeMid, BSIM4v6bNodePrime);
                CFOO(BSIM4v6DPgmPtr, BSIM4v6DPgmBinding, BSIM4v6dNodePrime, BSIM4v6gNodeMid);
                CFOO(BSIM4v6GPgmPtr, BSIM4v6GPgmBinding, BSIM4v6gNodePrime, BSIM4v6gNodeMid);
                CFOO(BSIM4v6GEgmPtr, BSIM4v6GEgmBinding, BSIM4v6gNodeExt, BSIM4v6gNodeMid);
                CFOO(BSIM4v6SPgmPtr, BSIM4v6SPgmBinding, BSIM4v6sNodePrime, BSIM4v6gNodeMid);
                CFOO(BSIM4v6BPgmPtr, BSIM4v6BPgmBinding, BSIM4v6bNodePrime, BSIM4v6gNodeMid);
            }
            if ((here->BSIM4v6rbodyMod == 1) || (here->BSIM4v6rbodyMod == 2))
            {
                CFOO(BSIM4v6DPdbPtr, BSIM4v6DPdbBinding, BSIM4v6dNodePrime, BSIM4v6dbNode);
                CFOO(BSIM4v6SPsbPtr, BSIM4v6SPsbBinding, BSIM4v6sNodePrime, BSIM4v6sbNode);
                CFOO(BSIM4v6DBdpPtr, BSIM4v6DBdpBinding, BSIM4v6dbNode, BSIM4v6dNodePrime);
                CFOO(BSIM4v6DBdbPtr, BSIM4v6DBdbBinding, BSIM4v6dbNode, BSIM4v6dbNode);
                CFOO(BSIM4v6DBbpPtr, BSIM4v6DBbpBinding, BSIM4v6dbNode, BSIM4v6bNodePrime);
                CFOO(BSIM4v6DBbPtr, BSIM4v6DBbBinding, BSIM4v6dbNode, BSIM4v6bNode);
                CFOO(BSIM4v6BPdbPtr, BSIM4v6BPdbBinding, BSIM4v6bNodePrime, BSIM4v6dbNode);
                CFOO(BSIM4v6BPbPtr, BSIM4v6BPbBinding, BSIM4v6bNodePrime, BSIM4v6bNode);
                CFOO(BSIM4v6BPsbPtr, BSIM4v6BPsbBinding, BSIM4v6bNodePrime, BSIM4v6sbNode);
                CFOO(BSIM4v6SBspPtr, BSIM4v6SBspBinding, BSIM4v6sbNode, BSIM4v6sNodePrime);
                CFOO(BSIM4v6SBbpPtr, BSIM4v6SBbpBinding, BSIM4v6sbNode, BSIM4v6bNodePrime);
                CFOO(BSIM4v6SBbPtr, BSIM4v6SBbBinding, BSIM4v6sbNode, BSIM4v6bNode);
                CFOO(BSIM4v6SBsbPtr, BSIM4v6SBsbBinding, BSIM4v6sbNode, BSIM4v6sbNode);
                CFOO(BSIM4v6BdbPtr, BSIM4v6BdbBinding, BSIM4v6bNode, BSIM4v6dbNode);
                CFOO(BSIM4v6BbpPtr, BSIM4v6BbpBinding, BSIM4v6bNode, BSIM4v6bNodePrime);
                CFOO(BSIM4v6BsbPtr, BSIM4v6BsbBinding, BSIM4v6bNode, BSIM4v6sbNode);
                CFOO(BSIM4v6BbPtr, BSIM4v6BbBinding, BSIM4v6bNode, BSIM4v6bNode);
            }
            if (model->BSIM4v6rdsMod)
            {
                CFOO(BSIM4v6DgpPtr, BSIM4v6DgpBinding, BSIM4v6dNode, BSIM4v6gNodePrime);
                CFOO(BSIM4v6DspPtr, BSIM4v6DspBinding, BSIM4v6dNode, BSIM4v6sNodePrime);
                CFOO(BSIM4v6DbpPtr, BSIM4v6DbpBinding, BSIM4v6dNode, BSIM4v6bNodePrime);
                CFOO(BSIM4v6SdpPtr, BSIM4v6SdpBinding, BSIM4v6sNode, BSIM4v6dNodePrime);
                CFOO(BSIM4v6SgpPtr, BSIM4v6SgpBinding, BSIM4v6sNode, BSIM4v6gNodePrime);
                CFOO(BSIM4v6SbpPtr, BSIM4v6SbpBinding, BSIM4v6sNode, BSIM4v6bNodePrime);
            }
        }
    }

    return (OK) ;
}
