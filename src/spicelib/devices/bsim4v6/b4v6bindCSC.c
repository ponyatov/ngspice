/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim4v6def.h"
#include "ngspice/sperror.h"

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
            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
            {
                i = here->BSIM4v6DPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DPbpBinding = matched ;
                here->BSIM4v6DPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
            {
                i = here->BSIM4v6GPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6GPbpBinding = matched ;
                here->BSIM4v6GPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
            {
                i = here->BSIM4v6SPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SPbpBinding = matched ;
                here->BSIM4v6SPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
            {
                i = here->BSIM4v6BPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6BPdpBinding = matched ;
                here->BSIM4v6BPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
            {
                i = here->BSIM4v6BPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6BPgpBinding = matched ;
                here->BSIM4v6BPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
            {
                i = here->BSIM4v6BPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6BPspBinding = matched ;
                here->BSIM4v6BPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
            {
                i = here->BSIM4v6BPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6BPbpBinding = matched ;
                here->BSIM4v6BPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6dNode != 0))
            {
                i = here->BSIM4v6DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DdBinding = matched ;
                here->BSIM4v6DdPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
            {
                i = here->BSIM4v6GPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6GPgpBinding = matched ;
                here->BSIM4v6GPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6sNode != 0))
            {
                i = here->BSIM4v6SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SsBinding = matched ;
                here->BSIM4v6SsPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
            {
                i = here->BSIM4v6DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DPdpBinding = matched ;
                here->BSIM4v6DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
            {
                i = here->BSIM4v6SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SPspBinding = matched ;
                here->BSIM4v6SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6dNodePrime != 0))
            {
                i = here->BSIM4v6DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DdpBinding = matched ;
                here->BSIM4v6DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
            {
                i = here->BSIM4v6GPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6GPdpBinding = matched ;
                here->BSIM4v6GPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
            {
                i = here->BSIM4v6GPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6GPspBinding = matched ;
                here->BSIM4v6GPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6sNodePrime != 0))
            {
                i = here->BSIM4v6SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SspBinding = matched ;
                here->BSIM4v6SspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
            {
                i = here->BSIM4v6DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DPspBinding = matched ;
                here->BSIM4v6DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dNode != 0))
            {
                i = here->BSIM4v6DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DPdBinding = matched ;
                here->BSIM4v6DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
            {
                i = here->BSIM4v6DPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DPgpBinding = matched ;
                here->BSIM4v6DPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
            {
                i = here->BSIM4v6SPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SPgpBinding = matched ;
                here->BSIM4v6SPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sNode != 0))
            {
                i = here->BSIM4v6SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SPsBinding = matched ;
                here->BSIM4v6SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
            {
                i = here->BSIM4v6SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SPdpBinding = matched ;
                here->BSIM4v6SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6qNode != 0))
            {
                i = here->BSIM4v6QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6QqBinding = matched ;
                here->BSIM4v6QqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6bNodePrime != 0))
            {
                i = here->BSIM4v6QbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6QbpBinding = matched ;
                here->BSIM4v6QbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6dNodePrime != 0))
            {
                i = here->BSIM4v6QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6QdpBinding = matched ;
                here->BSIM4v6QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6sNodePrime != 0))
            {
                i = here->BSIM4v6QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6QspBinding = matched ;
                here->BSIM4v6QspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6gNodePrime != 0))
            {
                i = here->BSIM4v6QgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6QgpBinding = matched ;
                here->BSIM4v6QgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6qNode != 0))
            {
                i = here->BSIM4v6DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6DPqBinding = matched ;
                here->BSIM4v6DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6qNode != 0))
            {
                i = here->BSIM4v6SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6SPqBinding = matched ;
                here->BSIM4v6SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6qNode != 0))
            {
                i = here->BSIM4v6GPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v6GPqBinding = matched ;
                here->BSIM4v6GPqPtr = matched->CSC ;
            }

            if (here->BSIM4v6rgateMod != 0)
            {
                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodeExt != 0))
                {
                    i = here->BSIM4v6GEgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GEgeBinding = matched ;
                    here->BSIM4v6GEgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodePrime != 0))
                {
                    i = here->BSIM4v6GEgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GEgpBinding = matched ;
                    here->BSIM4v6GEgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodeExt != 0))
                {
                    i = here->BSIM4v6GPgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GPgeBinding = matched ;
                    here->BSIM4v6GPgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6dNodePrime != 0))
                {
                    i = here->BSIM4v6GEdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GEdpBinding = matched ;
                    here->BSIM4v6GEdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6sNodePrime != 0))
                {
                    i = here->BSIM4v6GEspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GEspBinding = matched ;
                    here->BSIM4v6GEspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6GEbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GEbpBinding = matched ;
                    here->BSIM4v6GEbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6dNodePrime != 0))
                {
                    i = here->BSIM4v6GMdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GMdpBinding = matched ;
                    here->BSIM4v6GMdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodePrime != 0))
                {
                    i = here->BSIM4v6GMgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GMgpBinding = matched ;
                    here->BSIM4v6GMgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodeMid != 0))
                {
                    i = here->BSIM4v6GMgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GMgmBinding = matched ;
                    here->BSIM4v6GMgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodeExt != 0))
                {
                    i = here->BSIM4v6GMgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GMgeBinding = matched ;
                    here->BSIM4v6GMgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6sNodePrime != 0))
                {
                    i = here->BSIM4v6GMspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GMspBinding = matched ;
                    here->BSIM4v6GMspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6GMbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GMbpBinding = matched ;
                    here->BSIM4v6GMbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                {
                    i = here->BSIM4v6DPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DPgmBinding = matched ;
                    here->BSIM4v6DPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                {
                    i = here->BSIM4v6GPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GPgmBinding = matched ;
                    here->BSIM4v6GPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodeMid != 0))
                {
                    i = here->BSIM4v6GEgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6GEgmBinding = matched ;
                    here->BSIM4v6GEgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                {
                    i = here->BSIM4v6SPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SPgmBinding = matched ;
                    here->BSIM4v6SPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                {
                    i = here->BSIM4v6BPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BPgmBinding = matched ;
                    here->BSIM4v6BPgmPtr = matched->CSC ;
                }

            }
            if ((here->BSIM4v6rbodyMod == 1) || (here->BSIM4v6rbodyMod == 2))
            {
                if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dbNode != 0))
                {
                    i = here->BSIM4v6DPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DPdbBinding = matched ;
                    here->BSIM4v6DPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sbNode != 0))
                {
                    i = here->BSIM4v6SPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SPsbBinding = matched ;
                    here->BSIM4v6SPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                {
                    i = here->BSIM4v6DBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DBdpBinding = matched ;
                    here->BSIM4v6DBdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6dbNode != 0))
                {
                    i = here->BSIM4v6DBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DBdbBinding = matched ;
                    here->BSIM4v6DBdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6DBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DBbpBinding = matched ;
                    here->BSIM4v6DBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6bNode != 0))
                {
                    i = here->BSIM4v6DBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DBbBinding = matched ;
                    here->BSIM4v6DBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6dbNode != 0))
                {
                    i = here->BSIM4v6BPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BPdbBinding = matched ;
                    here->BSIM4v6BPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6bNode != 0))
                {
                    i = here->BSIM4v6BPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BPbBinding = matched ;
                    here->BSIM4v6BPbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6sbNode != 0))
                {
                    i = here->BSIM4v6BPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BPsbBinding = matched ;
                    here->BSIM4v6BPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                {
                    i = here->BSIM4v6SBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SBspBinding = matched ;
                    here->BSIM4v6SBspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6SBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SBbpBinding = matched ;
                    here->BSIM4v6SBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6bNode != 0))
                {
                    i = here->BSIM4v6SBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SBbBinding = matched ;
                    here->BSIM4v6SBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6sbNode != 0))
                {
                    i = here->BSIM4v6SBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SBsbBinding = matched ;
                    here->BSIM4v6SBsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6dbNode != 0))
                {
                    i = here->BSIM4v6BdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BdbBinding = matched ;
                    here->BSIM4v6BdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6BbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BbpBinding = matched ;
                    here->BSIM4v6BbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6sbNode != 0))
                {
                    i = here->BSIM4v6BsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BsbBinding = matched ;
                    here->BSIM4v6BsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6bNode != 0))
                {
                    i = here->BSIM4v6BbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6BbBinding = matched ;
                    here->BSIM4v6BbPtr = matched->CSC ;
                }

            }
            if (model->BSIM4v6rdsMod)
            {
                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                {
                    i = here->BSIM4v6DgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DgpBinding = matched ;
                    here->BSIM4v6DgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                {
                    i = here->BSIM4v6DspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DspBinding = matched ;
                    here->BSIM4v6DspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6DbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6DbpBinding = matched ;
                    here->BSIM4v6DbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                {
                    i = here->BSIM4v6SdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SdpBinding = matched ;
                    here->BSIM4v6SdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                {
                    i = here->BSIM4v6SgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SgpBinding = matched ;
                    here->BSIM4v6SgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                {
                    i = here->BSIM4v6SbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v6SbpBinding = matched ;
                    here->BSIM4v6SbpPtr = matched->CSC ;
                }

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
            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6DPbpPtr = here->BSIM4v6DPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6GPbpPtr = here->BSIM4v6GPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6SPbpPtr = here->BSIM4v6SPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6BPdpPtr = here->BSIM4v6BPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6BPgpPtr = here->BSIM4v6BPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6BPspPtr = here->BSIM4v6BPspBinding->CSC_Complex ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6BPbpPtr = here->BSIM4v6BPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6dNode != 0))
                here->BSIM4v6DdPtr = here->BSIM4v6DdBinding->CSC_Complex ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6GPgpPtr = here->BSIM4v6GPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6sNode != 0))
                here->BSIM4v6SsPtr = here->BSIM4v6SsBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6DPdpPtr = here->BSIM4v6DPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6SPspPtr = here->BSIM4v6SPspBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6DdpPtr = here->BSIM4v6DdpBinding->CSC_Complex ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6GPdpPtr = here->BSIM4v6GPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6GPspPtr = here->BSIM4v6GPspBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6SspPtr = here->BSIM4v6SspBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6DPspPtr = here->BSIM4v6DPspBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dNode != 0))
                here->BSIM4v6DPdPtr = here->BSIM4v6DPdBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6DPgpPtr = here->BSIM4v6DPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6SPgpPtr = here->BSIM4v6SPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sNode != 0))
                here->BSIM4v6SPsPtr = here->BSIM4v6SPsBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6SPdpPtr = here->BSIM4v6SPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6QqPtr = here->BSIM4v6QqBinding->CSC_Complex ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6QbpPtr = here->BSIM4v6QbpBinding->CSC_Complex ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6QdpPtr = here->BSIM4v6QdpBinding->CSC_Complex ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6QspPtr = here->BSIM4v6QspBinding->CSC_Complex ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6QgpPtr = here->BSIM4v6QgpBinding->CSC_Complex ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6DPqPtr = here->BSIM4v6DPqBinding->CSC_Complex ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6SPqPtr = here->BSIM4v6SPqBinding->CSC_Complex ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6GPqPtr = here->BSIM4v6GPqBinding->CSC_Complex ;

            if (here->BSIM4v6rgateMod != 0)
            {
                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodeExt != 0))
                    here->BSIM4v6GEgePtr = here->BSIM4v6GEgeBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6GEgpPtr = here->BSIM4v6GEgpBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodeExt != 0))
                    here->BSIM4v6GPgePtr = here->BSIM4v6GPgeBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6GEdpPtr = here->BSIM4v6GEdpBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6GEspPtr = here->BSIM4v6GEspBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6GEbpPtr = here->BSIM4v6GEbpBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6GMdpPtr = here->BSIM4v6GMdpBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6GMgpPtr = here->BSIM4v6GMgpBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6GMgmPtr = here->BSIM4v6GMgmBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodeExt != 0))
                    here->BSIM4v6GMgePtr = here->BSIM4v6GMgeBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6GMspPtr = here->BSIM4v6GMspBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6GMbpPtr = here->BSIM4v6GMbpBinding->CSC_Complex ;

                if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6DPgmPtr = here->BSIM4v6DPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6GPgmPtr = here->BSIM4v6GPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6GEgmPtr = here->BSIM4v6GEgmBinding->CSC_Complex ;

                if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6SPgmPtr = here->BSIM4v6SPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6BPgmPtr = here->BSIM4v6BPgmBinding->CSC_Complex ;

            }
            if ((here->BSIM4v6rbodyMod == 1) || (here->BSIM4v6rbodyMod == 2))
            {
                if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6DPdbPtr = here->BSIM4v6DPdbBinding->CSC_Complex ;

                if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6SPsbPtr = here->BSIM4v6SPsbBinding->CSC_Complex ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6DBdpPtr = here->BSIM4v6DBdpBinding->CSC_Complex ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6DBdbPtr = here->BSIM4v6DBdbBinding->CSC_Complex ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6DBbpPtr = here->BSIM4v6DBbpBinding->CSC_Complex ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6DBbPtr = here->BSIM4v6DBbBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6BPdbPtr = here->BSIM4v6BPdbBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6BPbPtr = here->BSIM4v6BPbBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6BPsbPtr = here->BSIM4v6BPsbBinding->CSC_Complex ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6SBspPtr = here->BSIM4v6SBspBinding->CSC_Complex ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6SBbpPtr = here->BSIM4v6SBbpBinding->CSC_Complex ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6SBbPtr = here->BSIM4v6SBbBinding->CSC_Complex ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6SBsbPtr = here->BSIM4v6SBsbBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6BdbPtr = here->BSIM4v6BdbBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6BbpPtr = here->BSIM4v6BbpBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6BsbPtr = here->BSIM4v6BsbBinding->CSC_Complex ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6BbPtr = here->BSIM4v6BbBinding->CSC_Complex ;

            }
            if (model->BSIM4v6rdsMod)
            {
                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6DgpPtr = here->BSIM4v6DgpBinding->CSC_Complex ;

                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6DspPtr = here->BSIM4v6DspBinding->CSC_Complex ;

                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6DbpPtr = here->BSIM4v6DbpBinding->CSC_Complex ;

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6SdpPtr = here->BSIM4v6SdpBinding->CSC_Complex ;

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6SgpPtr = here->BSIM4v6SgpBinding->CSC_Complex ;

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6SbpPtr = here->BSIM4v6SbpBinding->CSC_Complex ;

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
            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6DPbpPtr = here->BSIM4v6DPbpBinding->CSC ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6GPbpPtr = here->BSIM4v6GPbpBinding->CSC ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6SPbpPtr = here->BSIM4v6SPbpBinding->CSC ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6BPdpPtr = here->BSIM4v6BPdpBinding->CSC ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6BPgpPtr = here->BSIM4v6BPgpBinding->CSC ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6BPspPtr = here->BSIM4v6BPspBinding->CSC ;

            if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6BPbpPtr = here->BSIM4v6BPbpBinding->CSC ;

            if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6dNode != 0))
                here->BSIM4v6DdPtr = here->BSIM4v6DdBinding->CSC ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6GPgpPtr = here->BSIM4v6GPgpBinding->CSC ;

            if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6sNode != 0))
                here->BSIM4v6SsPtr = here->BSIM4v6SsBinding->CSC ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6DPdpPtr = here->BSIM4v6DPdpBinding->CSC ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6SPspPtr = here->BSIM4v6SPspBinding->CSC ;

            if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6DdpPtr = here->BSIM4v6DdpBinding->CSC ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6GPdpPtr = here->BSIM4v6GPdpBinding->CSC ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6GPspPtr = here->BSIM4v6GPspBinding->CSC ;

            if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6SspPtr = here->BSIM4v6SspBinding->CSC ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6DPspPtr = here->BSIM4v6DPspBinding->CSC ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dNode != 0))
                here->BSIM4v6DPdPtr = here->BSIM4v6DPdBinding->CSC ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6DPgpPtr = here->BSIM4v6DPgpBinding->CSC ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6SPgpPtr = here->BSIM4v6SPgpBinding->CSC ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sNode != 0))
                here->BSIM4v6SPsPtr = here->BSIM4v6SPsBinding->CSC ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6SPdpPtr = here->BSIM4v6SPdpBinding->CSC ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6QqPtr = here->BSIM4v6QqBinding->CSC ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                here->BSIM4v6QbpPtr = here->BSIM4v6QbpBinding->CSC ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                here->BSIM4v6QdpPtr = here->BSIM4v6QdpBinding->CSC ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                here->BSIM4v6QspPtr = here->BSIM4v6QspBinding->CSC ;

            if ((here-> BSIM4v6qNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                here->BSIM4v6QgpPtr = here->BSIM4v6QgpBinding->CSC ;

            if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6DPqPtr = here->BSIM4v6DPqBinding->CSC ;

            if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6SPqPtr = here->BSIM4v6SPqBinding->CSC ;

            if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6qNode != 0))
                here->BSIM4v6GPqPtr = here->BSIM4v6GPqBinding->CSC ;

            if (here->BSIM4v6rgateMod != 0)
            {
                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodeExt != 0))
                    here->BSIM4v6GEgePtr = here->BSIM4v6GEgeBinding->CSC ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6GEgpPtr = here->BSIM4v6GEgpBinding->CSC ;

                if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodeExt != 0))
                    here->BSIM4v6GPgePtr = here->BSIM4v6GPgeBinding->CSC ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6GEdpPtr = here->BSIM4v6GEdpBinding->CSC ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6GEspPtr = here->BSIM4v6GEspBinding->CSC ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6GEbpPtr = here->BSIM4v6GEbpBinding->CSC ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6GMdpPtr = here->BSIM4v6GMdpBinding->CSC ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6GMgpPtr = here->BSIM4v6GMgpBinding->CSC ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6GMgmPtr = here->BSIM4v6GMgmBinding->CSC ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6gNodeExt != 0))
                    here->BSIM4v6GMgePtr = here->BSIM4v6GMgeBinding->CSC ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6GMspPtr = here->BSIM4v6GMspBinding->CSC ;

                if ((here-> BSIM4v6gNodeMid != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6GMbpPtr = here->BSIM4v6GMbpBinding->CSC ;

                if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6DPgmPtr = here->BSIM4v6DPgmBinding->CSC ;

                if ((here-> BSIM4v6gNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6GPgmPtr = here->BSIM4v6GPgmBinding->CSC ;

                if ((here-> BSIM4v6gNodeExt != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6GEgmPtr = here->BSIM4v6GEgmBinding->CSC ;

                if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6SPgmPtr = here->BSIM4v6SPgmBinding->CSC ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6gNodeMid != 0))
                    here->BSIM4v6BPgmPtr = here->BSIM4v6BPgmBinding->CSC ;

            }
            if ((here->BSIM4v6rbodyMod == 1) || (here->BSIM4v6rbodyMod == 2))
            {
                if ((here-> BSIM4v6dNodePrime != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6DPdbPtr = here->BSIM4v6DPdbBinding->CSC ;

                if ((here-> BSIM4v6sNodePrime != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6SPsbPtr = here->BSIM4v6SPsbBinding->CSC ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6DBdpPtr = here->BSIM4v6DBdpBinding->CSC ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6DBdbPtr = here->BSIM4v6DBdbBinding->CSC ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6DBbpPtr = here->BSIM4v6DBbpBinding->CSC ;

                if ((here-> BSIM4v6dbNode != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6DBbPtr = here->BSIM4v6DBbBinding->CSC ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6BPdbPtr = here->BSIM4v6BPdbBinding->CSC ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6BPbPtr = here->BSIM4v6BPbBinding->CSC ;

                if ((here-> BSIM4v6bNodePrime != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6BPsbPtr = here->BSIM4v6BPsbBinding->CSC ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6SBspPtr = here->BSIM4v6SBspBinding->CSC ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6SBbpPtr = here->BSIM4v6SBbpBinding->CSC ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6SBbPtr = here->BSIM4v6SBbBinding->CSC ;

                if ((here-> BSIM4v6sbNode != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6SBsbPtr = here->BSIM4v6SBsbBinding->CSC ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6dbNode != 0))
                    here->BSIM4v6BdbPtr = here->BSIM4v6BdbBinding->CSC ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6BbpPtr = here->BSIM4v6BbpBinding->CSC ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6sbNode != 0))
                    here->BSIM4v6BsbPtr = here->BSIM4v6BsbBinding->CSC ;

                if ((here-> BSIM4v6bNode != 0) && (here-> BSIM4v6bNode != 0))
                    here->BSIM4v6BbPtr = here->BSIM4v6BbBinding->CSC ;

            }
            if (model->BSIM4v6rdsMod)
            {
                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6DgpPtr = here->BSIM4v6DgpBinding->CSC ;

                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6sNodePrime != 0))
                    here->BSIM4v6DspPtr = here->BSIM4v6DspBinding->CSC ;

                if ((here-> BSIM4v6dNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6DbpPtr = here->BSIM4v6DbpBinding->CSC ;

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6dNodePrime != 0))
                    here->BSIM4v6SdpPtr = here->BSIM4v6SdpBinding->CSC ;

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6gNodePrime != 0))
                    here->BSIM4v6SgpPtr = here->BSIM4v6SgpBinding->CSC ;

                if ((here-> BSIM4v6sNode != 0) && (here-> BSIM4v6bNodePrime != 0))
                    here->BSIM4v6SbpPtr = here->BSIM4v6SbpBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
