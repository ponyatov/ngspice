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
            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2bNodePrime != 0))
            {
                i = here->HSM2DPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DPbpBinding = matched ;
                here->HSM2DPbpPtr = matched->CSC ;
            }

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2bNodePrime != 0))
            {
                i = here->HSM2SPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SPbpBinding = matched ;
                here->HSM2SPbpPtr = matched->CSC ;
            }

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2bNodePrime != 0))
            {
                i = here->HSM2GPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2GPbpBinding = matched ;
                here->HSM2GPbpPtr = matched->CSC ;
            }

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2dNodePrime != 0))
            {
                i = here->HSM2BPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2BPdpBinding = matched ;
                here->HSM2BPdpPtr = matched->CSC ;
            }

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2sNodePrime != 0))
            {
                i = here->HSM2BPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2BPspBinding = matched ;
                here->HSM2BPspPtr = matched->CSC ;
            }

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2gNodePrime != 0))
            {
                i = here->HSM2BPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2BPgpBinding = matched ;
                here->HSM2BPgpPtr = matched->CSC ;
            }

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2bNodePrime != 0))
            {
                i = here->HSM2BPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2BPbpBinding = matched ;
                here->HSM2BPbpPtr = matched->CSC ;
            }

            if ((here-> HSM2dNode != 0) && (here-> HSM2dNode != 0))
            {
                i = here->HSM2DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DdBinding = matched ;
                here->HSM2DdPtr = matched->CSC ;
            }

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2gNodePrime != 0))
            {
                i = here->HSM2GPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2GPgpBinding = matched ;
                here->HSM2GPgpPtr = matched->CSC ;
            }

            if ((here-> HSM2sNode != 0) && (here-> HSM2sNode != 0))
            {
                i = here->HSM2SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SsBinding = matched ;
                here->HSM2SsPtr = matched->CSC ;
            }

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dNodePrime != 0))
            {
                i = here->HSM2DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DPdpBinding = matched ;
                here->HSM2DPdpPtr = matched->CSC ;
            }

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sNodePrime != 0))
            {
                i = here->HSM2SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SPspBinding = matched ;
                here->HSM2SPspPtr = matched->CSC ;
            }

            if ((here-> HSM2dNode != 0) && (here-> HSM2dNodePrime != 0))
            {
                i = here->HSM2DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DdpBinding = matched ;
                here->HSM2DdpPtr = matched->CSC ;
            }

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2dNodePrime != 0))
            {
                i = here->HSM2GPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2GPdpBinding = matched ;
                here->HSM2GPdpPtr = matched->CSC ;
            }

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2sNodePrime != 0))
            {
                i = here->HSM2GPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2GPspBinding = matched ;
                here->HSM2GPspPtr = matched->CSC ;
            }

            if ((here-> HSM2sNode != 0) && (here-> HSM2sNodePrime != 0))
            {
                i = here->HSM2SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SspBinding = matched ;
                here->HSM2SspPtr = matched->CSC ;
            }

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2sNodePrime != 0))
            {
                i = here->HSM2DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DPspBinding = matched ;
                here->HSM2DPspPtr = matched->CSC ;
            }

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dNode != 0))
            {
                i = here->HSM2DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DPdBinding = matched ;
                here->HSM2DPdPtr = matched->CSC ;
            }

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2gNodePrime != 0))
            {
                i = here->HSM2DPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2DPgpBinding = matched ;
                here->HSM2DPgpPtr = matched->CSC ;
            }

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2gNodePrime != 0))
            {
                i = here->HSM2SPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SPgpBinding = matched ;
                here->HSM2SPgpPtr = matched->CSC ;
            }

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sNode != 0))
            {
                i = here->HSM2SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SPsBinding = matched ;
                here->HSM2SPsPtr = matched->CSC ;
            }

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2dNodePrime != 0))
            {
                i = here->HSM2SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSM2SPdpBinding = matched ;
                here->HSM2SPdpPtr = matched->CSC ;
            }

            if (here->HSM2_corg == 1)
            {
                if ((here-> HSM2gNode != 0) && (here-> HSM2gNode != 0))
                {
                    i = here->HSM2GgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2GgBinding = matched ;
                    here->HSM2GgPtr = matched->CSC ;
                }

                if ((here-> HSM2gNode != 0) && (here-> HSM2gNodePrime != 0))
                {
                    i = here->HSM2GgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2GgpBinding = matched ;
                    here->HSM2GgpPtr = matched->CSC ;
                }

                if ((here-> HSM2gNodePrime != 0) && (here-> HSM2gNode != 0))
                {
                    i = here->HSM2GPgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2GPgBinding = matched ;
                    here->HSM2GPgPtr = matched->CSC ;
                }

                if ((here-> HSM2gNode != 0) && (here-> HSM2dNodePrime != 0))
                {
                    i = here->HSM2GdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2GdpBinding = matched ;
                    here->HSM2GdpPtr = matched->CSC ;
                }

                if ((here-> HSM2gNode != 0) && (here-> HSM2sNodePrime != 0))
                {
                    i = here->HSM2GspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2GspBinding = matched ;
                    here->HSM2GspPtr = matched->CSC ;
                }

                if ((here-> HSM2gNode != 0) && (here-> HSM2bNodePrime != 0))
                {
                    i = here->HSM2GbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2GbpBinding = matched ;
                    here->HSM2GbpPtr = matched->CSC ;
                }

            }
            if (here->HSM2_corbnet == 1)
            {
                if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dbNode != 0))
                {
                    i = here->HSM2DPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2DPdbBinding = matched ;
                    here->HSM2DPdbPtr = matched->CSC ;
                }

                if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sbNode != 0))
                {
                    i = here->HSM2SPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2SPsbBinding = matched ;
                    here->HSM2SPsbPtr = matched->CSC ;
                }

                if ((here-> HSM2dbNode != 0) && (here-> HSM2dNodePrime != 0))
                {
                    i = here->HSM2DBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2DBdpBinding = matched ;
                    here->HSM2DBdpPtr = matched->CSC ;
                }

                if ((here-> HSM2dbNode != 0) && (here-> HSM2dbNode != 0))
                {
                    i = here->HSM2DBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2DBdbBinding = matched ;
                    here->HSM2DBdbPtr = matched->CSC ;
                }

                if ((here-> HSM2dbNode != 0) && (here-> HSM2bNodePrime != 0))
                {
                    i = here->HSM2DBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2DBbpBinding = matched ;
                    here->HSM2DBbpPtr = matched->CSC ;
                }

                if ((here-> HSM2dbNode != 0) && (here-> HSM2bNode != 0))
                {
                    i = here->HSM2DBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2DBbBinding = matched ;
                    here->HSM2DBbPtr = matched->CSC ;
                }

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2dbNode != 0))
                {
                    i = here->HSM2BPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BPdbBinding = matched ;
                    here->HSM2BPdbPtr = matched->CSC ;
                }

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2bNode != 0))
                {
                    i = here->HSM2BPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BPbBinding = matched ;
                    here->HSM2BPbPtr = matched->CSC ;
                }

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2sbNode != 0))
                {
                    i = here->HSM2BPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BPsbBinding = matched ;
                    here->HSM2BPsbPtr = matched->CSC ;
                }

                if ((here-> HSM2sbNode != 0) && (here-> HSM2sNodePrime != 0))
                {
                    i = here->HSM2SBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2SBspBinding = matched ;
                    here->HSM2SBspPtr = matched->CSC ;
                }

                if ((here-> HSM2sbNode != 0) && (here-> HSM2bNodePrime != 0))
                {
                    i = here->HSM2SBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2SBbpBinding = matched ;
                    here->HSM2SBbpPtr = matched->CSC ;
                }

                if ((here-> HSM2sbNode != 0) && (here-> HSM2bNode != 0))
                {
                    i = here->HSM2SBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2SBbBinding = matched ;
                    here->HSM2SBbPtr = matched->CSC ;
                }

                if ((here-> HSM2sbNode != 0) && (here-> HSM2sbNode != 0))
                {
                    i = here->HSM2SBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2SBsbBinding = matched ;
                    here->HSM2SBsbPtr = matched->CSC ;
                }

                if ((here-> HSM2bNode != 0) && (here-> HSM2dbNode != 0))
                {
                    i = here->HSM2BdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BdbBinding = matched ;
                    here->HSM2BdbPtr = matched->CSC ;
                }

                if ((here-> HSM2bNode != 0) && (here-> HSM2bNodePrime != 0))
                {
                    i = here->HSM2BbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BbpBinding = matched ;
                    here->HSM2BbpPtr = matched->CSC ;
                }

                if ((here-> HSM2bNode != 0) && (here-> HSM2sbNode != 0))
                {
                    i = here->HSM2BsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BsbBinding = matched ;
                    here->HSM2BsbPtr = matched->CSC ;
                }

                if ((here-> HSM2bNode != 0) && (here-> HSM2bNode != 0))
                {
                    i = here->HSM2BbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSM2BbBinding = matched ;
                    here->HSM2BbPtr = matched->CSC ;
                }

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
            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2DPbpPtr = here->HSM2DPbpBinding->CSC_Complex ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2SPbpPtr = here->HSM2SPbpBinding->CSC_Complex ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2GPbpPtr = here->HSM2GPbpBinding->CSC_Complex ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2BPdpPtr = here->HSM2BPdpBinding->CSC_Complex ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2BPspPtr = here->HSM2BPspBinding->CSC_Complex ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2BPgpPtr = here->HSM2BPgpBinding->CSC_Complex ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2BPbpPtr = here->HSM2BPbpBinding->CSC_Complex ;

            if ((here-> HSM2dNode != 0) && (here-> HSM2dNode != 0))
                here->HSM2DdPtr = here->HSM2DdBinding->CSC_Complex ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2GPgpPtr = here->HSM2GPgpBinding->CSC_Complex ;

            if ((here-> HSM2sNode != 0) && (here-> HSM2sNode != 0))
                here->HSM2SsPtr = here->HSM2SsBinding->CSC_Complex ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2DPdpPtr = here->HSM2DPdpBinding->CSC_Complex ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2SPspPtr = here->HSM2SPspBinding->CSC_Complex ;

            if ((here-> HSM2dNode != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2DdpPtr = here->HSM2DdpBinding->CSC_Complex ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2GPdpPtr = here->HSM2GPdpBinding->CSC_Complex ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2GPspPtr = here->HSM2GPspBinding->CSC_Complex ;

            if ((here-> HSM2sNode != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2SspPtr = here->HSM2SspBinding->CSC_Complex ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2DPspPtr = here->HSM2DPspBinding->CSC_Complex ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dNode != 0))
                here->HSM2DPdPtr = here->HSM2DPdBinding->CSC_Complex ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2DPgpPtr = here->HSM2DPgpBinding->CSC_Complex ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2SPgpPtr = here->HSM2SPgpBinding->CSC_Complex ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sNode != 0))
                here->HSM2SPsPtr = here->HSM2SPsBinding->CSC_Complex ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2SPdpPtr = here->HSM2SPdpBinding->CSC_Complex ;

            if (here->HSM2_corg == 1)
            {
                if ((here-> HSM2gNode != 0) && (here-> HSM2gNode != 0))
                    here->HSM2GgPtr = here->HSM2GgBinding->CSC_Complex ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2gNodePrime != 0))
                    here->HSM2GgpPtr = here->HSM2GgpBinding->CSC_Complex ;

                if ((here-> HSM2gNodePrime != 0) && (here-> HSM2gNode != 0))
                    here->HSM2GPgPtr = here->HSM2GPgBinding->CSC_Complex ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2dNodePrime != 0))
                    here->HSM2GdpPtr = here->HSM2GdpBinding->CSC_Complex ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2sNodePrime != 0))
                    here->HSM2GspPtr = here->HSM2GspBinding->CSC_Complex ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2GbpPtr = here->HSM2GbpBinding->CSC_Complex ;

            }
            if (here->HSM2_corbnet == 1)
            {
                if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2DPdbPtr = here->HSM2DPdbBinding->CSC_Complex ;

                if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2SPsbPtr = here->HSM2SPsbBinding->CSC_Complex ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2dNodePrime != 0))
                    here->HSM2DBdpPtr = here->HSM2DBdpBinding->CSC_Complex ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2DBdbPtr = here->HSM2DBdbBinding->CSC_Complex ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2DBbpPtr = here->HSM2DBbpBinding->CSC_Complex ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2bNode != 0))
                    here->HSM2DBbPtr = here->HSM2DBbBinding->CSC_Complex ;

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2BPdbPtr = here->HSM2BPdbBinding->CSC_Complex ;

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2bNode != 0))
                    here->HSM2BPbPtr = here->HSM2BPbBinding->CSC_Complex ;

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2BPsbPtr = here->HSM2BPsbBinding->CSC_Complex ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2sNodePrime != 0))
                    here->HSM2SBspPtr = here->HSM2SBspBinding->CSC_Complex ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2SBbpPtr = here->HSM2SBbpBinding->CSC_Complex ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2bNode != 0))
                    here->HSM2SBbPtr = here->HSM2SBbBinding->CSC_Complex ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2SBsbPtr = here->HSM2SBsbBinding->CSC_Complex ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2BdbPtr = here->HSM2BdbBinding->CSC_Complex ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2BbpPtr = here->HSM2BbpBinding->CSC_Complex ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2BsbPtr = here->HSM2BsbBinding->CSC_Complex ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2bNode != 0))
                    here->HSM2BbPtr = here->HSM2BbBinding->CSC_Complex ;

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
            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2DPbpPtr = here->HSM2DPbpBinding->CSC ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2SPbpPtr = here->HSM2SPbpBinding->CSC ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2GPbpPtr = here->HSM2GPbpBinding->CSC ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2BPdpPtr = here->HSM2BPdpBinding->CSC ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2BPspPtr = here->HSM2BPspBinding->CSC ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2BPgpPtr = here->HSM2BPgpBinding->CSC ;

            if ((here-> HSM2bNodePrime != 0) && (here-> HSM2bNodePrime != 0))
                here->HSM2BPbpPtr = here->HSM2BPbpBinding->CSC ;

            if ((here-> HSM2dNode != 0) && (here-> HSM2dNode != 0))
                here->HSM2DdPtr = here->HSM2DdBinding->CSC ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2GPgpPtr = here->HSM2GPgpBinding->CSC ;

            if ((here-> HSM2sNode != 0) && (here-> HSM2sNode != 0))
                here->HSM2SsPtr = here->HSM2SsBinding->CSC ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2DPdpPtr = here->HSM2DPdpBinding->CSC ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2SPspPtr = here->HSM2SPspBinding->CSC ;

            if ((here-> HSM2dNode != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2DdpPtr = here->HSM2DdpBinding->CSC ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2GPdpPtr = here->HSM2GPdpBinding->CSC ;

            if ((here-> HSM2gNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2GPspPtr = here->HSM2GPspBinding->CSC ;

            if ((here-> HSM2sNode != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2SspPtr = here->HSM2SspBinding->CSC ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2sNodePrime != 0))
                here->HSM2DPspPtr = here->HSM2DPspBinding->CSC ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dNode != 0))
                here->HSM2DPdPtr = here->HSM2DPdBinding->CSC ;

            if ((here-> HSM2dNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2DPgpPtr = here->HSM2DPgpBinding->CSC ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2gNodePrime != 0))
                here->HSM2SPgpPtr = here->HSM2SPgpBinding->CSC ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sNode != 0))
                here->HSM2SPsPtr = here->HSM2SPsBinding->CSC ;

            if ((here-> HSM2sNodePrime != 0) && (here-> HSM2dNodePrime != 0))
                here->HSM2SPdpPtr = here->HSM2SPdpBinding->CSC ;

            if (here->HSM2_corg == 1)
            {
                if ((here-> HSM2gNode != 0) && (here-> HSM2gNode != 0))
                    here->HSM2GgPtr = here->HSM2GgBinding->CSC ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2gNodePrime != 0))
                    here->HSM2GgpPtr = here->HSM2GgpBinding->CSC ;

                if ((here-> HSM2gNodePrime != 0) && (here-> HSM2gNode != 0))
                    here->HSM2GPgPtr = here->HSM2GPgBinding->CSC ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2dNodePrime != 0))
                    here->HSM2GdpPtr = here->HSM2GdpBinding->CSC ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2sNodePrime != 0))
                    here->HSM2GspPtr = here->HSM2GspBinding->CSC ;

                if ((here-> HSM2gNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2GbpPtr = here->HSM2GbpBinding->CSC ;

            }
            if (here->HSM2_corbnet == 1)
            {
                if ((here-> HSM2dNodePrime != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2DPdbPtr = here->HSM2DPdbBinding->CSC ;

                if ((here-> HSM2sNodePrime != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2SPsbPtr = here->HSM2SPsbBinding->CSC ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2dNodePrime != 0))
                    here->HSM2DBdpPtr = here->HSM2DBdpBinding->CSC ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2DBdbPtr = here->HSM2DBdbBinding->CSC ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2DBbpPtr = here->HSM2DBbpBinding->CSC ;

                if ((here-> HSM2dbNode != 0) && (here-> HSM2bNode != 0))
                    here->HSM2DBbPtr = here->HSM2DBbBinding->CSC ;

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2BPdbPtr = here->HSM2BPdbBinding->CSC ;

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2bNode != 0))
                    here->HSM2BPbPtr = here->HSM2BPbBinding->CSC ;

                if ((here-> HSM2bNodePrime != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2BPsbPtr = here->HSM2BPsbBinding->CSC ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2sNodePrime != 0))
                    here->HSM2SBspPtr = here->HSM2SBspBinding->CSC ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2SBbpPtr = here->HSM2SBbpBinding->CSC ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2bNode != 0))
                    here->HSM2SBbPtr = here->HSM2SBbBinding->CSC ;

                if ((here-> HSM2sbNode != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2SBsbPtr = here->HSM2SBsbBinding->CSC ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2dbNode != 0))
                    here->HSM2BdbPtr = here->HSM2BdbBinding->CSC ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2bNodePrime != 0))
                    here->HSM2BbpPtr = here->HSM2BbpBinding->CSC ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2sbNode != 0))
                    here->HSM2BsbPtr = here->HSM2BsbBinding->CSC ;

                if ((here-> HSM2bNode != 0) && (here-> HSM2bNode != 0))
                    here->HSM2BbPtr = here->HSM2BbBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
