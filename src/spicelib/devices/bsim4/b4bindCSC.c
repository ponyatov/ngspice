/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim4def.h"
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
BSIM4bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4model *model = (BSIM4model *)inModel ;
    BSIM4instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM4 models */
    for ( ; model != NULL ; model = model->BSIM4nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4instances ; here != NULL ; here = here->BSIM4nextInstance)
        {
            XFOO(BSIM4DPbpPtr, BSIM4DPbpBinding, BSIM4dNodePrime, BSIM4bNodePrime);
            XFOO(BSIM4GPbpPtr, BSIM4GPbpBinding, BSIM4gNodePrime, BSIM4bNodePrime);
            XFOO(BSIM4SPbpPtr, BSIM4SPbpBinding, BSIM4sNodePrime, BSIM4bNodePrime);
            XFOO(BSIM4BPdpPtr, BSIM4BPdpBinding, BSIM4bNodePrime, BSIM4dNodePrime);
            XFOO(BSIM4BPgpPtr, BSIM4BPgpBinding, BSIM4bNodePrime, BSIM4gNodePrime);
            XFOO(BSIM4BPspPtr, BSIM4BPspBinding, BSIM4bNodePrime, BSIM4sNodePrime);
            XFOO(BSIM4BPbpPtr, BSIM4BPbpBinding, BSIM4bNodePrime, BSIM4bNodePrime);
            XFOO(BSIM4DdPtr, BSIM4DdBinding, BSIM4dNode, BSIM4dNode);
            XFOO(BSIM4GPgpPtr, BSIM4GPgpBinding, BSIM4gNodePrime, BSIM4gNodePrime);
            XFOO(BSIM4SsPtr, BSIM4SsBinding, BSIM4sNode, BSIM4sNode);
            XFOO(BSIM4DPdpPtr, BSIM4DPdpBinding, BSIM4dNodePrime, BSIM4dNodePrime);
            XFOO(BSIM4SPspPtr, BSIM4SPspBinding, BSIM4sNodePrime, BSIM4sNodePrime);
            XFOO(BSIM4DdpPtr, BSIM4DdpBinding, BSIM4dNode, BSIM4dNodePrime);
            XFOO(BSIM4GPdpPtr, BSIM4GPdpBinding, BSIM4gNodePrime, BSIM4dNodePrime);
            XFOO(BSIM4GPspPtr, BSIM4GPspBinding, BSIM4gNodePrime, BSIM4sNodePrime);
            XFOO(BSIM4SspPtr, BSIM4SspBinding, BSIM4sNode, BSIM4sNodePrime);
            XFOO(BSIM4DPspPtr, BSIM4DPspBinding, BSIM4dNodePrime, BSIM4sNodePrime);
            XFOO(BSIM4DPdPtr, BSIM4DPdBinding, BSIM4dNodePrime, BSIM4dNode);
            XFOO(BSIM4DPgpPtr, BSIM4DPgpBinding, BSIM4dNodePrime, BSIM4gNodePrime);
            XFOO(BSIM4SPgpPtr, BSIM4SPgpBinding, BSIM4sNodePrime, BSIM4gNodePrime);
            XFOO(BSIM4SPsPtr, BSIM4SPsBinding, BSIM4sNodePrime, BSIM4sNode);
            XFOO(BSIM4SPdpPtr, BSIM4SPdpBinding, BSIM4sNodePrime, BSIM4dNodePrime);
            XFOO(BSIM4QqPtr, BSIM4QqBinding, BSIM4qNode, BSIM4qNode);
            XFOO(BSIM4QbpPtr, BSIM4QbpBinding, BSIM4qNode, BSIM4bNodePrime);
            XFOO(BSIM4QdpPtr, BSIM4QdpBinding, BSIM4qNode, BSIM4dNodePrime);
            XFOO(BSIM4QspPtr, BSIM4QspBinding, BSIM4qNode, BSIM4sNodePrime);
            XFOO(BSIM4QgpPtr, BSIM4QgpBinding, BSIM4qNode, BSIM4gNodePrime);
            XFOO(BSIM4DPqPtr, BSIM4DPqBinding, BSIM4dNodePrime, BSIM4qNode);
            XFOO(BSIM4SPqPtr, BSIM4SPqBinding, BSIM4sNodePrime, BSIM4qNode);
            XFOO(BSIM4GPqPtr, BSIM4GPqBinding, BSIM4gNodePrime, BSIM4qNode);
            if (here->BSIM4rgateMod != 0)
            {
                XFOO(BSIM4GEgePtr, BSIM4GEgeBinding, BSIM4gNodeExt, BSIM4gNodeExt);
                XFOO(BSIM4GEgpPtr, BSIM4GEgpBinding, BSIM4gNodeExt, BSIM4gNodePrime);
                XFOO(BSIM4GPgePtr, BSIM4GPgeBinding, BSIM4gNodePrime, BSIM4gNodeExt);
                XFOO(BSIM4GEdpPtr, BSIM4GEdpBinding, BSIM4gNodeExt, BSIM4dNodePrime);
                XFOO(BSIM4GEspPtr, BSIM4GEspBinding, BSIM4gNodeExt, BSIM4sNodePrime);
                XFOO(BSIM4GEbpPtr, BSIM4GEbpBinding, BSIM4gNodeExt, BSIM4bNodePrime);
                XFOO(BSIM4GMdpPtr, BSIM4GMdpBinding, BSIM4gNodeMid, BSIM4dNodePrime);
                XFOO(BSIM4GMgpPtr, BSIM4GMgpBinding, BSIM4gNodeMid, BSIM4gNodePrime);
                XFOO(BSIM4GMgmPtr, BSIM4GMgmBinding, BSIM4gNodeMid, BSIM4gNodeMid);
                XFOO(BSIM4GMgePtr, BSIM4GMgeBinding, BSIM4gNodeMid, BSIM4gNodeExt);
                XFOO(BSIM4GMspPtr, BSIM4GMspBinding, BSIM4gNodeMid, BSIM4sNodePrime);
                XFOO(BSIM4GMbpPtr, BSIM4GMbpBinding, BSIM4gNodeMid, BSIM4bNodePrime);
                XFOO(BSIM4DPgmPtr, BSIM4DPgmBinding, BSIM4dNodePrime, BSIM4gNodeMid);
                XFOO(BSIM4GPgmPtr, BSIM4GPgmBinding, BSIM4gNodePrime, BSIM4gNodeMid);
                XFOO(BSIM4GEgmPtr, BSIM4GEgmBinding, BSIM4gNodeExt, BSIM4gNodeMid);
                XFOO(BSIM4SPgmPtr, BSIM4SPgmBinding, BSIM4sNodePrime, BSIM4gNodeMid);
                XFOO(BSIM4BPgmPtr, BSIM4BPgmBinding, BSIM4bNodePrime, BSIM4gNodeMid);
            }
            if ((here->BSIM4rbodyMod == 1) || (here->BSIM4rbodyMod == 2))
            {
                XFOO(BSIM4DPdbPtr, BSIM4DPdbBinding, BSIM4dNodePrime, BSIM4dbNode);
                XFOO(BSIM4SPsbPtr, BSIM4SPsbBinding, BSIM4sNodePrime, BSIM4sbNode);
                XFOO(BSIM4DBdpPtr, BSIM4DBdpBinding, BSIM4dbNode, BSIM4dNodePrime);
                XFOO(BSIM4DBdbPtr, BSIM4DBdbBinding, BSIM4dbNode, BSIM4dbNode);
                XFOO(BSIM4DBbpPtr, BSIM4DBbpBinding, BSIM4dbNode, BSIM4bNodePrime);
                XFOO(BSIM4DBbPtr, BSIM4DBbBinding, BSIM4dbNode, BSIM4bNode);
                XFOO(BSIM4BPdbPtr, BSIM4BPdbBinding, BSIM4bNodePrime, BSIM4dbNode);
                XFOO(BSIM4BPbPtr, BSIM4BPbBinding, BSIM4bNodePrime, BSIM4bNode);
                XFOO(BSIM4BPsbPtr, BSIM4BPsbBinding, BSIM4bNodePrime, BSIM4sbNode);
                XFOO(BSIM4SBspPtr, BSIM4SBspBinding, BSIM4sbNode, BSIM4sNodePrime);
                XFOO(BSIM4SBbpPtr, BSIM4SBbpBinding, BSIM4sbNode, BSIM4bNodePrime);
                XFOO(BSIM4SBbPtr, BSIM4SBbBinding, BSIM4sbNode, BSIM4bNode);
                XFOO(BSIM4SBsbPtr, BSIM4SBsbBinding, BSIM4sbNode, BSIM4sbNode);
                XFOO(BSIM4BdbPtr, BSIM4BdbBinding, BSIM4bNode, BSIM4dbNode);
                XFOO(BSIM4BbpPtr, BSIM4BbpBinding, BSIM4bNode, BSIM4bNodePrime);
                XFOO(BSIM4BsbPtr, BSIM4BsbBinding, BSIM4bNode, BSIM4sbNode);
                XFOO(BSIM4BbPtr, BSIM4BbBinding, BSIM4bNode, BSIM4bNode);
            }
            if (model->BSIM4rdsMod)
            {
                XFOO(BSIM4DgpPtr, BSIM4DgpBinding, BSIM4dNode, BSIM4gNodePrime);
                XFOO(BSIM4DspPtr, BSIM4DspBinding, BSIM4dNode, BSIM4sNodePrime);
                XFOO(BSIM4DbpPtr, BSIM4DbpBinding, BSIM4dNode, BSIM4bNodePrime);
                XFOO(BSIM4SdpPtr, BSIM4SdpBinding, BSIM4sNode, BSIM4dNodePrime);
                XFOO(BSIM4SgpPtr, BSIM4SgpBinding, BSIM4sNode, BSIM4gNodePrime);
                XFOO(BSIM4SbpPtr, BSIM4SbpBinding, BSIM4sNode, BSIM4bNodePrime);
            }
        }
    }

    return (OK) ;
}

int
BSIM4bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4model *model = (BSIM4model *)inModel ;
    BSIM4instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4 models */
    for ( ; model != NULL ; model = model->BSIM4nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4instances ; here != NULL ; here = here->BSIM4nextInstance)
        {
            BFOO(BSIM4DPbpPtr, BSIM4DPbpBinding, BSIM4dNodePrime, BSIM4bNodePrime);
            BFOO(BSIM4GPbpPtr, BSIM4GPbpBinding, BSIM4gNodePrime, BSIM4bNodePrime);
            BFOO(BSIM4SPbpPtr, BSIM4SPbpBinding, BSIM4sNodePrime, BSIM4bNodePrime);
            BFOO(BSIM4BPdpPtr, BSIM4BPdpBinding, BSIM4bNodePrime, BSIM4dNodePrime);
            BFOO(BSIM4BPgpPtr, BSIM4BPgpBinding, BSIM4bNodePrime, BSIM4gNodePrime);
            BFOO(BSIM4BPspPtr, BSIM4BPspBinding, BSIM4bNodePrime, BSIM4sNodePrime);
            BFOO(BSIM4BPbpPtr, BSIM4BPbpBinding, BSIM4bNodePrime, BSIM4bNodePrime);
            BFOO(BSIM4DdPtr, BSIM4DdBinding, BSIM4dNode, BSIM4dNode);
            BFOO(BSIM4GPgpPtr, BSIM4GPgpBinding, BSIM4gNodePrime, BSIM4gNodePrime);
            BFOO(BSIM4SsPtr, BSIM4SsBinding, BSIM4sNode, BSIM4sNode);
            BFOO(BSIM4DPdpPtr, BSIM4DPdpBinding, BSIM4dNodePrime, BSIM4dNodePrime);
            BFOO(BSIM4SPspPtr, BSIM4SPspBinding, BSIM4sNodePrime, BSIM4sNodePrime);
            BFOO(BSIM4DdpPtr, BSIM4DdpBinding, BSIM4dNode, BSIM4dNodePrime);
            BFOO(BSIM4GPdpPtr, BSIM4GPdpBinding, BSIM4gNodePrime, BSIM4dNodePrime);
            BFOO(BSIM4GPspPtr, BSIM4GPspBinding, BSIM4gNodePrime, BSIM4sNodePrime);
            BFOO(BSIM4SspPtr, BSIM4SspBinding, BSIM4sNode, BSIM4sNodePrime);
            BFOO(BSIM4DPspPtr, BSIM4DPspBinding, BSIM4dNodePrime, BSIM4sNodePrime);
            BFOO(BSIM4DPdPtr, BSIM4DPdBinding, BSIM4dNodePrime, BSIM4dNode);
            BFOO(BSIM4DPgpPtr, BSIM4DPgpBinding, BSIM4dNodePrime, BSIM4gNodePrime);
            BFOO(BSIM4SPgpPtr, BSIM4SPgpBinding, BSIM4sNodePrime, BSIM4gNodePrime);
            BFOO(BSIM4SPsPtr, BSIM4SPsBinding, BSIM4sNodePrime, BSIM4sNode);
            BFOO(BSIM4SPdpPtr, BSIM4SPdpBinding, BSIM4sNodePrime, BSIM4dNodePrime);
            BFOO(BSIM4QqPtr, BSIM4QqBinding, BSIM4qNode, BSIM4qNode);
            BFOO(BSIM4QbpPtr, BSIM4QbpBinding, BSIM4qNode, BSIM4bNodePrime);
            BFOO(BSIM4QdpPtr, BSIM4QdpBinding, BSIM4qNode, BSIM4dNodePrime);
            BFOO(BSIM4QspPtr, BSIM4QspBinding, BSIM4qNode, BSIM4sNodePrime);
            BFOO(BSIM4QgpPtr, BSIM4QgpBinding, BSIM4qNode, BSIM4gNodePrime);
            BFOO(BSIM4DPqPtr, BSIM4DPqBinding, BSIM4dNodePrime, BSIM4qNode);
            BFOO(BSIM4SPqPtr, BSIM4SPqBinding, BSIM4sNodePrime, BSIM4qNode);
            BFOO(BSIM4GPqPtr, BSIM4GPqBinding, BSIM4gNodePrime, BSIM4qNode);
            if (here->BSIM4rgateMod != 0)
            {
                BFOO(BSIM4GEgePtr, BSIM4GEgeBinding, BSIM4gNodeExt, BSIM4gNodeExt);
                BFOO(BSIM4GEgpPtr, BSIM4GEgpBinding, BSIM4gNodeExt, BSIM4gNodePrime);
                BFOO(BSIM4GPgePtr, BSIM4GPgeBinding, BSIM4gNodePrime, BSIM4gNodeExt);
                BFOO(BSIM4GEdpPtr, BSIM4GEdpBinding, BSIM4gNodeExt, BSIM4dNodePrime);
                BFOO(BSIM4GEspPtr, BSIM4GEspBinding, BSIM4gNodeExt, BSIM4sNodePrime);
                BFOO(BSIM4GEbpPtr, BSIM4GEbpBinding, BSIM4gNodeExt, BSIM4bNodePrime);
                BFOO(BSIM4GMdpPtr, BSIM4GMdpBinding, BSIM4gNodeMid, BSIM4dNodePrime);
                BFOO(BSIM4GMgpPtr, BSIM4GMgpBinding, BSIM4gNodeMid, BSIM4gNodePrime);
                BFOO(BSIM4GMgmPtr, BSIM4GMgmBinding, BSIM4gNodeMid, BSIM4gNodeMid);
                BFOO(BSIM4GMgePtr, BSIM4GMgeBinding, BSIM4gNodeMid, BSIM4gNodeExt);
                BFOO(BSIM4GMspPtr, BSIM4GMspBinding, BSIM4gNodeMid, BSIM4sNodePrime);
                BFOO(BSIM4GMbpPtr, BSIM4GMbpBinding, BSIM4gNodeMid, BSIM4bNodePrime);
                BFOO(BSIM4DPgmPtr, BSIM4DPgmBinding, BSIM4dNodePrime, BSIM4gNodeMid);
                BFOO(BSIM4GPgmPtr, BSIM4GPgmBinding, BSIM4gNodePrime, BSIM4gNodeMid);
                BFOO(BSIM4GEgmPtr, BSIM4GEgmBinding, BSIM4gNodeExt, BSIM4gNodeMid);
                BFOO(BSIM4SPgmPtr, BSIM4SPgmBinding, BSIM4sNodePrime, BSIM4gNodeMid);
                BFOO(BSIM4BPgmPtr, BSIM4BPgmBinding, BSIM4bNodePrime, BSIM4gNodeMid);
            }
            if ((here->BSIM4rbodyMod == 1) || (here->BSIM4rbodyMod == 2))
            {
                BFOO(BSIM4DPdbPtr, BSIM4DPdbBinding, BSIM4dNodePrime, BSIM4dbNode);
                BFOO(BSIM4SPsbPtr, BSIM4SPsbBinding, BSIM4sNodePrime, BSIM4sbNode);
                BFOO(BSIM4DBdpPtr, BSIM4DBdpBinding, BSIM4dbNode, BSIM4dNodePrime);
                BFOO(BSIM4DBdbPtr, BSIM4DBdbBinding, BSIM4dbNode, BSIM4dbNode);
                BFOO(BSIM4DBbpPtr, BSIM4DBbpBinding, BSIM4dbNode, BSIM4bNodePrime);
                BFOO(BSIM4DBbPtr, BSIM4DBbBinding, BSIM4dbNode, BSIM4bNode);
                BFOO(BSIM4BPdbPtr, BSIM4BPdbBinding, BSIM4bNodePrime, BSIM4dbNode);
                BFOO(BSIM4BPbPtr, BSIM4BPbBinding, BSIM4bNodePrime, BSIM4bNode);
                BFOO(BSIM4BPsbPtr, BSIM4BPsbBinding, BSIM4bNodePrime, BSIM4sbNode);
                BFOO(BSIM4SBspPtr, BSIM4SBspBinding, BSIM4sbNode, BSIM4sNodePrime);
                BFOO(BSIM4SBbpPtr, BSIM4SBbpBinding, BSIM4sbNode, BSIM4bNodePrime);
                BFOO(BSIM4SBbPtr, BSIM4SBbBinding, BSIM4sbNode, BSIM4bNode);
                BFOO(BSIM4SBsbPtr, BSIM4SBsbBinding, BSIM4sbNode, BSIM4sbNode);
                BFOO(BSIM4BdbPtr, BSIM4BdbBinding, BSIM4bNode, BSIM4dbNode);
                BFOO(BSIM4BbpPtr, BSIM4BbpBinding, BSIM4bNode, BSIM4bNodePrime);
                BFOO(BSIM4BsbPtr, BSIM4BsbBinding, BSIM4bNode, BSIM4sbNode);
                BFOO(BSIM4BbPtr, BSIM4BbBinding, BSIM4bNode, BSIM4bNode);
            }
            if (model->BSIM4rdsMod)
            {
                BFOO(BSIM4DgpPtr, BSIM4DgpBinding, BSIM4dNode, BSIM4gNodePrime);
                BFOO(BSIM4DspPtr, BSIM4DspBinding, BSIM4dNode, BSIM4sNodePrime);
                BFOO(BSIM4DbpPtr, BSIM4DbpBinding, BSIM4dNode, BSIM4bNodePrime);
                BFOO(BSIM4SdpPtr, BSIM4SdpBinding, BSIM4sNode, BSIM4dNodePrime);
                BFOO(BSIM4SgpPtr, BSIM4SgpBinding, BSIM4sNode, BSIM4gNodePrime);
                BFOO(BSIM4SbpPtr, BSIM4SbpBinding, BSIM4sNode, BSIM4bNodePrime);
            }
        }
    }

    return (OK) ;
}

int
BSIM4bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4model *model = (BSIM4model *)inModel ;
    BSIM4instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4 models */
    for ( ; model != NULL ; model = model->BSIM4nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4instances ; here != NULL ; here = here->BSIM4nextInstance)
        {
            CFOO(BSIM4DPbpPtr, BSIM4DPbpBinding, BSIM4dNodePrime, BSIM4bNodePrime);
            CFOO(BSIM4GPbpPtr, BSIM4GPbpBinding, BSIM4gNodePrime, BSIM4bNodePrime);
            CFOO(BSIM4SPbpPtr, BSIM4SPbpBinding, BSIM4sNodePrime, BSIM4bNodePrime);
            CFOO(BSIM4BPdpPtr, BSIM4BPdpBinding, BSIM4bNodePrime, BSIM4dNodePrime);
            CFOO(BSIM4BPgpPtr, BSIM4BPgpBinding, BSIM4bNodePrime, BSIM4gNodePrime);
            CFOO(BSIM4BPspPtr, BSIM4BPspBinding, BSIM4bNodePrime, BSIM4sNodePrime);
            CFOO(BSIM4BPbpPtr, BSIM4BPbpBinding, BSIM4bNodePrime, BSIM4bNodePrime);
            CFOO(BSIM4DdPtr, BSIM4DdBinding, BSIM4dNode, BSIM4dNode);
            CFOO(BSIM4GPgpPtr, BSIM4GPgpBinding, BSIM4gNodePrime, BSIM4gNodePrime);
            CFOO(BSIM4SsPtr, BSIM4SsBinding, BSIM4sNode, BSIM4sNode);
            CFOO(BSIM4DPdpPtr, BSIM4DPdpBinding, BSIM4dNodePrime, BSIM4dNodePrime);
            CFOO(BSIM4SPspPtr, BSIM4SPspBinding, BSIM4sNodePrime, BSIM4sNodePrime);
            CFOO(BSIM4DdpPtr, BSIM4DdpBinding, BSIM4dNode, BSIM4dNodePrime);
            CFOO(BSIM4GPdpPtr, BSIM4GPdpBinding, BSIM4gNodePrime, BSIM4dNodePrime);
            CFOO(BSIM4GPspPtr, BSIM4GPspBinding, BSIM4gNodePrime, BSIM4sNodePrime);
            CFOO(BSIM4SspPtr, BSIM4SspBinding, BSIM4sNode, BSIM4sNodePrime);
            CFOO(BSIM4DPspPtr, BSIM4DPspBinding, BSIM4dNodePrime, BSIM4sNodePrime);
            CFOO(BSIM4DPdPtr, BSIM4DPdBinding, BSIM4dNodePrime, BSIM4dNode);
            CFOO(BSIM4DPgpPtr, BSIM4DPgpBinding, BSIM4dNodePrime, BSIM4gNodePrime);
            CFOO(BSIM4SPgpPtr, BSIM4SPgpBinding, BSIM4sNodePrime, BSIM4gNodePrime);
            CFOO(BSIM4SPsPtr, BSIM4SPsBinding, BSIM4sNodePrime, BSIM4sNode);
            CFOO(BSIM4SPdpPtr, BSIM4SPdpBinding, BSIM4sNodePrime, BSIM4dNodePrime);
            CFOO(BSIM4QqPtr, BSIM4QqBinding, BSIM4qNode, BSIM4qNode);
            CFOO(BSIM4QbpPtr, BSIM4QbpBinding, BSIM4qNode, BSIM4bNodePrime);
            CFOO(BSIM4QdpPtr, BSIM4QdpBinding, BSIM4qNode, BSIM4dNodePrime);
            CFOO(BSIM4QspPtr, BSIM4QspBinding, BSIM4qNode, BSIM4sNodePrime);
            CFOO(BSIM4QgpPtr, BSIM4QgpBinding, BSIM4qNode, BSIM4gNodePrime);
            CFOO(BSIM4DPqPtr, BSIM4DPqBinding, BSIM4dNodePrime, BSIM4qNode);
            CFOO(BSIM4SPqPtr, BSIM4SPqBinding, BSIM4sNodePrime, BSIM4qNode);
            CFOO(BSIM4GPqPtr, BSIM4GPqBinding, BSIM4gNodePrime, BSIM4qNode);
            if (here->BSIM4rgateMod != 0)
            {
                CFOO(BSIM4GEgePtr, BSIM4GEgeBinding, BSIM4gNodeExt, BSIM4gNodeExt);
                CFOO(BSIM4GEgpPtr, BSIM4GEgpBinding, BSIM4gNodeExt, BSIM4gNodePrime);
                CFOO(BSIM4GPgePtr, BSIM4GPgeBinding, BSIM4gNodePrime, BSIM4gNodeExt);
                CFOO(BSIM4GEdpPtr, BSIM4GEdpBinding, BSIM4gNodeExt, BSIM4dNodePrime);
                CFOO(BSIM4GEspPtr, BSIM4GEspBinding, BSIM4gNodeExt, BSIM4sNodePrime);
                CFOO(BSIM4GEbpPtr, BSIM4GEbpBinding, BSIM4gNodeExt, BSIM4bNodePrime);
                CFOO(BSIM4GMdpPtr, BSIM4GMdpBinding, BSIM4gNodeMid, BSIM4dNodePrime);
                CFOO(BSIM4GMgpPtr, BSIM4GMgpBinding, BSIM4gNodeMid, BSIM4gNodePrime);
                CFOO(BSIM4GMgmPtr, BSIM4GMgmBinding, BSIM4gNodeMid, BSIM4gNodeMid);
                CFOO(BSIM4GMgePtr, BSIM4GMgeBinding, BSIM4gNodeMid, BSIM4gNodeExt);
                CFOO(BSIM4GMspPtr, BSIM4GMspBinding, BSIM4gNodeMid, BSIM4sNodePrime);
                CFOO(BSIM4GMbpPtr, BSIM4GMbpBinding, BSIM4gNodeMid, BSIM4bNodePrime);
                CFOO(BSIM4DPgmPtr, BSIM4DPgmBinding, BSIM4dNodePrime, BSIM4gNodeMid);
                CFOO(BSIM4GPgmPtr, BSIM4GPgmBinding, BSIM4gNodePrime, BSIM4gNodeMid);
                CFOO(BSIM4GEgmPtr, BSIM4GEgmBinding, BSIM4gNodeExt, BSIM4gNodeMid);
                CFOO(BSIM4SPgmPtr, BSIM4SPgmBinding, BSIM4sNodePrime, BSIM4gNodeMid);
                CFOO(BSIM4BPgmPtr, BSIM4BPgmBinding, BSIM4bNodePrime, BSIM4gNodeMid);
            }
            if ((here->BSIM4rbodyMod == 1) || (here->BSIM4rbodyMod == 2))
            {
                CFOO(BSIM4DPdbPtr, BSIM4DPdbBinding, BSIM4dNodePrime, BSIM4dbNode);
                CFOO(BSIM4SPsbPtr, BSIM4SPsbBinding, BSIM4sNodePrime, BSIM4sbNode);
                CFOO(BSIM4DBdpPtr, BSIM4DBdpBinding, BSIM4dbNode, BSIM4dNodePrime);
                CFOO(BSIM4DBdbPtr, BSIM4DBdbBinding, BSIM4dbNode, BSIM4dbNode);
                CFOO(BSIM4DBbpPtr, BSIM4DBbpBinding, BSIM4dbNode, BSIM4bNodePrime);
                CFOO(BSIM4DBbPtr, BSIM4DBbBinding, BSIM4dbNode, BSIM4bNode);
                CFOO(BSIM4BPdbPtr, BSIM4BPdbBinding, BSIM4bNodePrime, BSIM4dbNode);
                CFOO(BSIM4BPbPtr, BSIM4BPbBinding, BSIM4bNodePrime, BSIM4bNode);
                CFOO(BSIM4BPsbPtr, BSIM4BPsbBinding, BSIM4bNodePrime, BSIM4sbNode);
                CFOO(BSIM4SBspPtr, BSIM4SBspBinding, BSIM4sbNode, BSIM4sNodePrime);
                CFOO(BSIM4SBbpPtr, BSIM4SBbpBinding, BSIM4sbNode, BSIM4bNodePrime);
                CFOO(BSIM4SBbPtr, BSIM4SBbBinding, BSIM4sbNode, BSIM4bNode);
                CFOO(BSIM4SBsbPtr, BSIM4SBsbBinding, BSIM4sbNode, BSIM4sbNode);
                CFOO(BSIM4BdbPtr, BSIM4BdbBinding, BSIM4bNode, BSIM4dbNode);
                CFOO(BSIM4BbpPtr, BSIM4BbpBinding, BSIM4bNode, BSIM4bNodePrime);
                CFOO(BSIM4BsbPtr, BSIM4BsbBinding, BSIM4bNode, BSIM4sbNode);
                CFOO(BSIM4BbPtr, BSIM4BbBinding, BSIM4bNode, BSIM4bNode);
            }
            if (model->BSIM4rdsMod)
            {
                CFOO(BSIM4DgpPtr, BSIM4DgpBinding, BSIM4dNode, BSIM4gNodePrime);
                CFOO(BSIM4DspPtr, BSIM4DspBinding, BSIM4dNode, BSIM4sNodePrime);
                CFOO(BSIM4DbpPtr, BSIM4DbpBinding, BSIM4dNode, BSIM4bNodePrime);
                CFOO(BSIM4SdpPtr, BSIM4SdpBinding, BSIM4sNode, BSIM4dNodePrime);
                CFOO(BSIM4SgpPtr, BSIM4SgpBinding, BSIM4sNode, BSIM4gNodePrime);
                CFOO(BSIM4SbpPtr, BSIM4SbpBinding, BSIM4sNode, BSIM4bNodePrime);
            }
        }
    }

    return (OK) ;
}
