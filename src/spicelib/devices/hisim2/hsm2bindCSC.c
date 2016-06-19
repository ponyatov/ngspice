/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "hsm2def.h"
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
HSM2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    HSM2model *model = (HSM2model *)inModel ;
    HSM2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the HSM2 models */
    for ( ; model != NULL ; model = model->HSM2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HSM2instances ; here != NULL ; here = here->HSM2nextInstance)
        {
            XFOO(HSM2DPbpPtr, HSM2DPbpBinding, HSM2dNodePrime, HSM2bNodePrime);
            XFOO(HSM2SPbpPtr, HSM2SPbpBinding, HSM2sNodePrime, HSM2bNodePrime);
            XFOO(HSM2GPbpPtr, HSM2GPbpBinding, HSM2gNodePrime, HSM2bNodePrime);
            XFOO(HSM2BPdpPtr, HSM2BPdpBinding, HSM2bNodePrime, HSM2dNodePrime);
            XFOO(HSM2BPspPtr, HSM2BPspBinding, HSM2bNodePrime, HSM2sNodePrime);
            XFOO(HSM2BPgpPtr, HSM2BPgpBinding, HSM2bNodePrime, HSM2gNodePrime);
            XFOO(HSM2BPbpPtr, HSM2BPbpBinding, HSM2bNodePrime, HSM2bNodePrime);
            XFOO(HSM2DdPtr, HSM2DdBinding, HSM2dNode, HSM2dNode);
            XFOO(HSM2GPgpPtr, HSM2GPgpBinding, HSM2gNodePrime, HSM2gNodePrime);
            XFOO(HSM2SsPtr, HSM2SsBinding, HSM2sNode, HSM2sNode);
            XFOO(HSM2DPdpPtr, HSM2DPdpBinding, HSM2dNodePrime, HSM2dNodePrime);
            XFOO(HSM2SPspPtr, HSM2SPspBinding, HSM2sNodePrime, HSM2sNodePrime);
            XFOO(HSM2DdpPtr, HSM2DdpBinding, HSM2dNode, HSM2dNodePrime);
            XFOO(HSM2GPdpPtr, HSM2GPdpBinding, HSM2gNodePrime, HSM2dNodePrime);
            XFOO(HSM2GPspPtr, HSM2GPspBinding, HSM2gNodePrime, HSM2sNodePrime);
            XFOO(HSM2SspPtr, HSM2SspBinding, HSM2sNode, HSM2sNodePrime);
            XFOO(HSM2DPspPtr, HSM2DPspBinding, HSM2dNodePrime, HSM2sNodePrime);
            XFOO(HSM2DPdPtr, HSM2DPdBinding, HSM2dNodePrime, HSM2dNode);
            XFOO(HSM2DPgpPtr, HSM2DPgpBinding, HSM2dNodePrime, HSM2gNodePrime);
            XFOO(HSM2SPgpPtr, HSM2SPgpBinding, HSM2sNodePrime, HSM2gNodePrime);
            XFOO(HSM2SPsPtr, HSM2SPsBinding, HSM2sNodePrime, HSM2sNode);
            XFOO(HSM2SPdpPtr, HSM2SPdpBinding, HSM2sNodePrime, HSM2dNodePrime);
            if (here->HSM2_corg == 1)
            {
                XFOO(HSM2GgPtr, HSM2GgBinding, HSM2gNode, HSM2gNode);
                XFOO(HSM2GgpPtr, HSM2GgpBinding, HSM2gNode, HSM2gNodePrime);
                XFOO(HSM2GPgPtr, HSM2GPgBinding, HSM2gNodePrime, HSM2gNode);
                XFOO(HSM2GdpPtr, HSM2GdpBinding, HSM2gNode, HSM2dNodePrime);
                XFOO(HSM2GspPtr, HSM2GspBinding, HSM2gNode, HSM2sNodePrime);
                XFOO(HSM2GbpPtr, HSM2GbpBinding, HSM2gNode, HSM2bNodePrime);
            }
            if (here->HSM2_corbnet == 1)
            {
                XFOO(HSM2DPdbPtr, HSM2DPdbBinding, HSM2dNodePrime, HSM2dbNode);
                XFOO(HSM2SPsbPtr, HSM2SPsbBinding, HSM2sNodePrime, HSM2sbNode);
                XFOO(HSM2DBdpPtr, HSM2DBdpBinding, HSM2dbNode, HSM2dNodePrime);
                XFOO(HSM2DBdbPtr, HSM2DBdbBinding, HSM2dbNode, HSM2dbNode);
                XFOO(HSM2DBbpPtr, HSM2DBbpBinding, HSM2dbNode, HSM2bNodePrime);
                XFOO(HSM2DBbPtr, HSM2DBbBinding, HSM2dbNode, HSM2bNode);
                XFOO(HSM2BPdbPtr, HSM2BPdbBinding, HSM2bNodePrime, HSM2dbNode);
                XFOO(HSM2BPbPtr, HSM2BPbBinding, HSM2bNodePrime, HSM2bNode);
                XFOO(HSM2BPsbPtr, HSM2BPsbBinding, HSM2bNodePrime, HSM2sbNode);
                XFOO(HSM2SBspPtr, HSM2SBspBinding, HSM2sbNode, HSM2sNodePrime);
                XFOO(HSM2SBbpPtr, HSM2SBbpBinding, HSM2sbNode, HSM2bNodePrime);
                XFOO(HSM2SBbPtr, HSM2SBbBinding, HSM2sbNode, HSM2bNode);
                XFOO(HSM2SBsbPtr, HSM2SBsbBinding, HSM2sbNode, HSM2sbNode);
                XFOO(HSM2BdbPtr, HSM2BdbBinding, HSM2bNode, HSM2dbNode);
                XFOO(HSM2BbpPtr, HSM2BbpBinding, HSM2bNode, HSM2bNodePrime);
                XFOO(HSM2BsbPtr, HSM2BsbBinding, HSM2bNode, HSM2sbNode);
                XFOO(HSM2BbPtr, HSM2BbBinding, HSM2bNode, HSM2bNode);
            }
        }
    }

    return (OK) ;
}

int
HSM2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    HSM2model *model = (HSM2model *)inModel ;
    HSM2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HSM2 models */
    for ( ; model != NULL ; model = model->HSM2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HSM2instances ; here != NULL ; here = here->HSM2nextInstance)
        {
            BFOO(HSM2DPbpPtr, HSM2DPbpBinding, HSM2dNodePrime, HSM2bNodePrime);
            BFOO(HSM2SPbpPtr, HSM2SPbpBinding, HSM2sNodePrime, HSM2bNodePrime);
            BFOO(HSM2GPbpPtr, HSM2GPbpBinding, HSM2gNodePrime, HSM2bNodePrime);
            BFOO(HSM2BPdpPtr, HSM2BPdpBinding, HSM2bNodePrime, HSM2dNodePrime);
            BFOO(HSM2BPspPtr, HSM2BPspBinding, HSM2bNodePrime, HSM2sNodePrime);
            BFOO(HSM2BPgpPtr, HSM2BPgpBinding, HSM2bNodePrime, HSM2gNodePrime);
            BFOO(HSM2BPbpPtr, HSM2BPbpBinding, HSM2bNodePrime, HSM2bNodePrime);
            BFOO(HSM2DdPtr, HSM2DdBinding, HSM2dNode, HSM2dNode);
            BFOO(HSM2GPgpPtr, HSM2GPgpBinding, HSM2gNodePrime, HSM2gNodePrime);
            BFOO(HSM2SsPtr, HSM2SsBinding, HSM2sNode, HSM2sNode);
            BFOO(HSM2DPdpPtr, HSM2DPdpBinding, HSM2dNodePrime, HSM2dNodePrime);
            BFOO(HSM2SPspPtr, HSM2SPspBinding, HSM2sNodePrime, HSM2sNodePrime);
            BFOO(HSM2DdpPtr, HSM2DdpBinding, HSM2dNode, HSM2dNodePrime);
            BFOO(HSM2GPdpPtr, HSM2GPdpBinding, HSM2gNodePrime, HSM2dNodePrime);
            BFOO(HSM2GPspPtr, HSM2GPspBinding, HSM2gNodePrime, HSM2sNodePrime);
            BFOO(HSM2SspPtr, HSM2SspBinding, HSM2sNode, HSM2sNodePrime);
            BFOO(HSM2DPspPtr, HSM2DPspBinding, HSM2dNodePrime, HSM2sNodePrime);
            BFOO(HSM2DPdPtr, HSM2DPdBinding, HSM2dNodePrime, HSM2dNode);
            BFOO(HSM2DPgpPtr, HSM2DPgpBinding, HSM2dNodePrime, HSM2gNodePrime);
            BFOO(HSM2SPgpPtr, HSM2SPgpBinding, HSM2sNodePrime, HSM2gNodePrime);
            BFOO(HSM2SPsPtr, HSM2SPsBinding, HSM2sNodePrime, HSM2sNode);
            BFOO(HSM2SPdpPtr, HSM2SPdpBinding, HSM2sNodePrime, HSM2dNodePrime);
            if (here->HSM2_corg == 1)
            {
                BFOO(HSM2GgPtr, HSM2GgBinding, HSM2gNode, HSM2gNode);
                BFOO(HSM2GgpPtr, HSM2GgpBinding, HSM2gNode, HSM2gNodePrime);
                BFOO(HSM2GPgPtr, HSM2GPgBinding, HSM2gNodePrime, HSM2gNode);
                BFOO(HSM2GdpPtr, HSM2GdpBinding, HSM2gNode, HSM2dNodePrime);
                BFOO(HSM2GspPtr, HSM2GspBinding, HSM2gNode, HSM2sNodePrime);
                BFOO(HSM2GbpPtr, HSM2GbpBinding, HSM2gNode, HSM2bNodePrime);
            }
            if (here->HSM2_corbnet == 1)
            {
                BFOO(HSM2DPdbPtr, HSM2DPdbBinding, HSM2dNodePrime, HSM2dbNode);
                BFOO(HSM2SPsbPtr, HSM2SPsbBinding, HSM2sNodePrime, HSM2sbNode);
                BFOO(HSM2DBdpPtr, HSM2DBdpBinding, HSM2dbNode, HSM2dNodePrime);
                BFOO(HSM2DBdbPtr, HSM2DBdbBinding, HSM2dbNode, HSM2dbNode);
                BFOO(HSM2DBbpPtr, HSM2DBbpBinding, HSM2dbNode, HSM2bNodePrime);
                BFOO(HSM2DBbPtr, HSM2DBbBinding, HSM2dbNode, HSM2bNode);
                BFOO(HSM2BPdbPtr, HSM2BPdbBinding, HSM2bNodePrime, HSM2dbNode);
                BFOO(HSM2BPbPtr, HSM2BPbBinding, HSM2bNodePrime, HSM2bNode);
                BFOO(HSM2BPsbPtr, HSM2BPsbBinding, HSM2bNodePrime, HSM2sbNode);
                BFOO(HSM2SBspPtr, HSM2SBspBinding, HSM2sbNode, HSM2sNodePrime);
                BFOO(HSM2SBbpPtr, HSM2SBbpBinding, HSM2sbNode, HSM2bNodePrime);
                BFOO(HSM2SBbPtr, HSM2SBbBinding, HSM2sbNode, HSM2bNode);
                BFOO(HSM2SBsbPtr, HSM2SBsbBinding, HSM2sbNode, HSM2sbNode);
                BFOO(HSM2BdbPtr, HSM2BdbBinding, HSM2bNode, HSM2dbNode);
                BFOO(HSM2BbpPtr, HSM2BbpBinding, HSM2bNode, HSM2bNodePrime);
                BFOO(HSM2BsbPtr, HSM2BsbBinding, HSM2bNode, HSM2sbNode);
                BFOO(HSM2BbPtr, HSM2BbBinding, HSM2bNode, HSM2bNode);
            }
        }
    }

    return (OK) ;
}

int
HSM2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    HSM2model *model = (HSM2model *)inModel ;
    HSM2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HSM2 models */
    for ( ; model != NULL ; model = model->HSM2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HSM2instances ; here != NULL ; here = here->HSM2nextInstance)
        {
            CFOO(HSM2DPbpPtr, HSM2DPbpBinding, HSM2dNodePrime, HSM2bNodePrime);
            CFOO(HSM2SPbpPtr, HSM2SPbpBinding, HSM2sNodePrime, HSM2bNodePrime);
            CFOO(HSM2GPbpPtr, HSM2GPbpBinding, HSM2gNodePrime, HSM2bNodePrime);
            CFOO(HSM2BPdpPtr, HSM2BPdpBinding, HSM2bNodePrime, HSM2dNodePrime);
            CFOO(HSM2BPspPtr, HSM2BPspBinding, HSM2bNodePrime, HSM2sNodePrime);
            CFOO(HSM2BPgpPtr, HSM2BPgpBinding, HSM2bNodePrime, HSM2gNodePrime);
            CFOO(HSM2BPbpPtr, HSM2BPbpBinding, HSM2bNodePrime, HSM2bNodePrime);
            CFOO(HSM2DdPtr, HSM2DdBinding, HSM2dNode, HSM2dNode);
            CFOO(HSM2GPgpPtr, HSM2GPgpBinding, HSM2gNodePrime, HSM2gNodePrime);
            CFOO(HSM2SsPtr, HSM2SsBinding, HSM2sNode, HSM2sNode);
            CFOO(HSM2DPdpPtr, HSM2DPdpBinding, HSM2dNodePrime, HSM2dNodePrime);
            CFOO(HSM2SPspPtr, HSM2SPspBinding, HSM2sNodePrime, HSM2sNodePrime);
            CFOO(HSM2DdpPtr, HSM2DdpBinding, HSM2dNode, HSM2dNodePrime);
            CFOO(HSM2GPdpPtr, HSM2GPdpBinding, HSM2gNodePrime, HSM2dNodePrime);
            CFOO(HSM2GPspPtr, HSM2GPspBinding, HSM2gNodePrime, HSM2sNodePrime);
            CFOO(HSM2SspPtr, HSM2SspBinding, HSM2sNode, HSM2sNodePrime);
            CFOO(HSM2DPspPtr, HSM2DPspBinding, HSM2dNodePrime, HSM2sNodePrime);
            CFOO(HSM2DPdPtr, HSM2DPdBinding, HSM2dNodePrime, HSM2dNode);
            CFOO(HSM2DPgpPtr, HSM2DPgpBinding, HSM2dNodePrime, HSM2gNodePrime);
            CFOO(HSM2SPgpPtr, HSM2SPgpBinding, HSM2sNodePrime, HSM2gNodePrime);
            CFOO(HSM2SPsPtr, HSM2SPsBinding, HSM2sNodePrime, HSM2sNode);
            CFOO(HSM2SPdpPtr, HSM2SPdpBinding, HSM2sNodePrime, HSM2dNodePrime);
            if (here->HSM2_corg == 1)
            {
                CFOO(HSM2GgPtr, HSM2GgBinding, HSM2gNode, HSM2gNode);
                CFOO(HSM2GgpPtr, HSM2GgpBinding, HSM2gNode, HSM2gNodePrime);
                CFOO(HSM2GPgPtr, HSM2GPgBinding, HSM2gNodePrime, HSM2gNode);
                CFOO(HSM2GdpPtr, HSM2GdpBinding, HSM2gNode, HSM2dNodePrime);
                CFOO(HSM2GspPtr, HSM2GspBinding, HSM2gNode, HSM2sNodePrime);
                CFOO(HSM2GbpPtr, HSM2GbpBinding, HSM2gNode, HSM2bNodePrime);
            }
            if (here->HSM2_corbnet == 1)
            {
                CFOO(HSM2DPdbPtr, HSM2DPdbBinding, HSM2dNodePrime, HSM2dbNode);
                CFOO(HSM2SPsbPtr, HSM2SPsbBinding, HSM2sNodePrime, HSM2sbNode);
                CFOO(HSM2DBdpPtr, HSM2DBdpBinding, HSM2dbNode, HSM2dNodePrime);
                CFOO(HSM2DBdbPtr, HSM2DBdbBinding, HSM2dbNode, HSM2dbNode);
                CFOO(HSM2DBbpPtr, HSM2DBbpBinding, HSM2dbNode, HSM2bNodePrime);
                CFOO(HSM2DBbPtr, HSM2DBbBinding, HSM2dbNode, HSM2bNode);
                CFOO(HSM2BPdbPtr, HSM2BPdbBinding, HSM2bNodePrime, HSM2dbNode);
                CFOO(HSM2BPbPtr, HSM2BPbBinding, HSM2bNodePrime, HSM2bNode);
                CFOO(HSM2BPsbPtr, HSM2BPsbBinding, HSM2bNodePrime, HSM2sbNode);
                CFOO(HSM2SBspPtr, HSM2SBspBinding, HSM2sbNode, HSM2sNodePrime);
                CFOO(HSM2SBbpPtr, HSM2SBbpBinding, HSM2sbNode, HSM2bNodePrime);
                CFOO(HSM2SBbPtr, HSM2SBbBinding, HSM2sbNode, HSM2bNode);
                CFOO(HSM2SBsbPtr, HSM2SBsbBinding, HSM2sbNode, HSM2sbNode);
                CFOO(HSM2BdbPtr, HSM2BdbBinding, HSM2bNode, HSM2dbNode);
                CFOO(HSM2BbpPtr, HSM2BbpBinding, HSM2bNode, HSM2bNodePrime);
                CFOO(HSM2BsbPtr, HSM2BsbBinding, HSM2bNode, HSM2sbNode);
                CFOO(HSM2BbPtr, HSM2BbBinding, HSM2bNode, HSM2bNode);
            }
        }
    }

    return (OK) ;
}
