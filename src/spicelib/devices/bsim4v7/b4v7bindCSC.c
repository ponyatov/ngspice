/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim4v7def.h"
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
BSIM4v7bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v7model *model = (BSIM4v7model *)inModel ;
    BSIM4v7instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM4v7 models */
    for ( ; model != NULL ; model = model->BSIM4v7nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v7instances ; here != NULL ; here = here->BSIM4v7nextInstance)
        {
            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
            {
                i = here->BSIM4v7DPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DPbpBinding = matched ;
                here->BSIM4v7DPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
            {
                i = here->BSIM4v7GPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7GPbpBinding = matched ;
                here->BSIM4v7GPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
            {
                i = here->BSIM4v7SPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SPbpBinding = matched ;
                here->BSIM4v7SPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
            {
                i = here->BSIM4v7BPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7BPdpBinding = matched ;
                here->BSIM4v7BPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
            {
                i = here->BSIM4v7BPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7BPgpBinding = matched ;
                here->BSIM4v7BPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
            {
                i = here->BSIM4v7BPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7BPspBinding = matched ;
                here->BSIM4v7BPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
            {
                i = here->BSIM4v7BPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7BPbpBinding = matched ;
                here->BSIM4v7BPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7dNode != 0))
            {
                i = here->BSIM4v7DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DdBinding = matched ;
                here->BSIM4v7DdPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
            {
                i = here->BSIM4v7GPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7GPgpBinding = matched ;
                here->BSIM4v7GPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7sNode != 0))
            {
                i = here->BSIM4v7SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SsBinding = matched ;
                here->BSIM4v7SsPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
            {
                i = here->BSIM4v7DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DPdpBinding = matched ;
                here->BSIM4v7DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
            {
                i = here->BSIM4v7SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SPspBinding = matched ;
                here->BSIM4v7SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7dNodePrime != 0))
            {
                i = here->BSIM4v7DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DdpBinding = matched ;
                here->BSIM4v7DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
            {
                i = here->BSIM4v7GPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7GPdpBinding = matched ;
                here->BSIM4v7GPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
            {
                i = here->BSIM4v7GPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7GPspBinding = matched ;
                here->BSIM4v7GPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7sNodePrime != 0))
            {
                i = here->BSIM4v7SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SspBinding = matched ;
                here->BSIM4v7SspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
            {
                i = here->BSIM4v7DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DPspBinding = matched ;
                here->BSIM4v7DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dNode != 0))
            {
                i = here->BSIM4v7DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DPdBinding = matched ;
                here->BSIM4v7DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
            {
                i = here->BSIM4v7DPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DPgpBinding = matched ;
                here->BSIM4v7DPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
            {
                i = here->BSIM4v7SPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SPgpBinding = matched ;
                here->BSIM4v7SPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sNode != 0))
            {
                i = here->BSIM4v7SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SPsBinding = matched ;
                here->BSIM4v7SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
            {
                i = here->BSIM4v7SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SPdpBinding = matched ;
                here->BSIM4v7SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7qNode != 0))
            {
                i = here->BSIM4v7QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7QqBinding = matched ;
                here->BSIM4v7QqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7bNodePrime != 0))
            {
                i = here->BSIM4v7QbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7QbpBinding = matched ;
                here->BSIM4v7QbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7dNodePrime != 0))
            {
                i = here->BSIM4v7QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7QdpBinding = matched ;
                here->BSIM4v7QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7sNodePrime != 0))
            {
                i = here->BSIM4v7QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7QspBinding = matched ;
                here->BSIM4v7QspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7gNodePrime != 0))
            {
                i = here->BSIM4v7QgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7QgpBinding = matched ;
                here->BSIM4v7QgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7qNode != 0))
            {
                i = here->BSIM4v7DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7DPqBinding = matched ;
                here->BSIM4v7DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7qNode != 0))
            {
                i = here->BSIM4v7SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7SPqBinding = matched ;
                here->BSIM4v7SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7qNode != 0))
            {
                i = here->BSIM4v7GPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v7GPqBinding = matched ;
                here->BSIM4v7GPqPtr = matched->CSC ;
            }

            if (here->BSIM4v7rgateMod != 0)
            {
                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodeExt != 0))
                {
                    i = here->BSIM4v7GEgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GEgeBinding = matched ;
                    here->BSIM4v7GEgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodePrime != 0))
                {
                    i = here->BSIM4v7GEgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GEgpBinding = matched ;
                    here->BSIM4v7GEgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodeExt != 0))
                {
                    i = here->BSIM4v7GPgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GPgeBinding = matched ;
                    here->BSIM4v7GPgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7dNodePrime != 0))
                {
                    i = here->BSIM4v7GEdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GEdpBinding = matched ;
                    here->BSIM4v7GEdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7sNodePrime != 0))
                {
                    i = here->BSIM4v7GEspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GEspBinding = matched ;
                    here->BSIM4v7GEspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7GEbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GEbpBinding = matched ;
                    here->BSIM4v7GEbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7dNodePrime != 0))
                {
                    i = here->BSIM4v7GMdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GMdpBinding = matched ;
                    here->BSIM4v7GMdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodePrime != 0))
                {
                    i = here->BSIM4v7GMgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GMgpBinding = matched ;
                    here->BSIM4v7GMgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodeMid != 0))
                {
                    i = here->BSIM4v7GMgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GMgmBinding = matched ;
                    here->BSIM4v7GMgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodeExt != 0))
                {
                    i = here->BSIM4v7GMgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GMgeBinding = matched ;
                    here->BSIM4v7GMgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7sNodePrime != 0))
                {
                    i = here->BSIM4v7GMspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GMspBinding = matched ;
                    here->BSIM4v7GMspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7GMbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GMbpBinding = matched ;
                    here->BSIM4v7GMbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                {
                    i = here->BSIM4v7DPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DPgmBinding = matched ;
                    here->BSIM4v7DPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                {
                    i = here->BSIM4v7GPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GPgmBinding = matched ;
                    here->BSIM4v7GPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodeMid != 0))
                {
                    i = here->BSIM4v7GEgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7GEgmBinding = matched ;
                    here->BSIM4v7GEgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                {
                    i = here->BSIM4v7SPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SPgmBinding = matched ;
                    here->BSIM4v7SPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                {
                    i = here->BSIM4v7BPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BPgmBinding = matched ;
                    here->BSIM4v7BPgmPtr = matched->CSC ;
                }

            }
            if ((here->BSIM4v7rbodyMod == 1) || (here->BSIM4v7rbodyMod == 2))
            {
                if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dbNode != 0))
                {
                    i = here->BSIM4v7DPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DPdbBinding = matched ;
                    here->BSIM4v7DPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sbNode != 0))
                {
                    i = here->BSIM4v7SPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SPsbBinding = matched ;
                    here->BSIM4v7SPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                {
                    i = here->BSIM4v7DBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DBdpBinding = matched ;
                    here->BSIM4v7DBdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7dbNode != 0))
                {
                    i = here->BSIM4v7DBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DBdbBinding = matched ;
                    here->BSIM4v7DBdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7DBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DBbpBinding = matched ;
                    here->BSIM4v7DBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7bNode != 0))
                {
                    i = here->BSIM4v7DBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DBbBinding = matched ;
                    here->BSIM4v7DBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7dbNode != 0))
                {
                    i = here->BSIM4v7BPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BPdbBinding = matched ;
                    here->BSIM4v7BPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7bNode != 0))
                {
                    i = here->BSIM4v7BPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BPbBinding = matched ;
                    here->BSIM4v7BPbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7sbNode != 0))
                {
                    i = here->BSIM4v7BPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BPsbBinding = matched ;
                    here->BSIM4v7BPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                {
                    i = here->BSIM4v7SBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SBspBinding = matched ;
                    here->BSIM4v7SBspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7SBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SBbpBinding = matched ;
                    here->BSIM4v7SBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7bNode != 0))
                {
                    i = here->BSIM4v7SBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SBbBinding = matched ;
                    here->BSIM4v7SBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7sbNode != 0))
                {
                    i = here->BSIM4v7SBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SBsbBinding = matched ;
                    here->BSIM4v7SBsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7dbNode != 0))
                {
                    i = here->BSIM4v7BdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BdbBinding = matched ;
                    here->BSIM4v7BdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7BbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BbpBinding = matched ;
                    here->BSIM4v7BbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7sbNode != 0))
                {
                    i = here->BSIM4v7BsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BsbBinding = matched ;
                    here->BSIM4v7BsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7bNode != 0))
                {
                    i = here->BSIM4v7BbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7BbBinding = matched ;
                    here->BSIM4v7BbPtr = matched->CSC ;
                }

            }
            if (model->BSIM4v7rdsMod)
            {
                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                {
                    i = here->BSIM4v7DgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DgpBinding = matched ;
                    here->BSIM4v7DgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                {
                    i = here->BSIM4v7DspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DspBinding = matched ;
                    here->BSIM4v7DspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7DbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7DbpBinding = matched ;
                    here->BSIM4v7DbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                {
                    i = here->BSIM4v7SdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SdpBinding = matched ;
                    here->BSIM4v7SdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                {
                    i = here->BSIM4v7SgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SgpBinding = matched ;
                    here->BSIM4v7SgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                {
                    i = here->BSIM4v7SbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v7SbpBinding = matched ;
                    here->BSIM4v7SbpPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
BSIM4v7bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v7model *model = (BSIM4v7model *)inModel ;
    BSIM4v7instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4v7 models */
    for ( ; model != NULL ; model = model->BSIM4v7nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v7instances ; here != NULL ; here = here->BSIM4v7nextInstance)
        {
            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7DPbpPtr = here->BSIM4v7DPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7GPbpPtr = here->BSIM4v7GPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7SPbpPtr = here->BSIM4v7SPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7BPdpPtr = here->BSIM4v7BPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7BPgpPtr = here->BSIM4v7BPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7BPspPtr = here->BSIM4v7BPspBinding->CSC_Complex ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7BPbpPtr = here->BSIM4v7BPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7dNode != 0))
                here->BSIM4v7DdPtr = here->BSIM4v7DdBinding->CSC_Complex ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7GPgpPtr = here->BSIM4v7GPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7sNode != 0))
                here->BSIM4v7SsPtr = here->BSIM4v7SsBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7DPdpPtr = here->BSIM4v7DPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7SPspPtr = here->BSIM4v7SPspBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7DdpPtr = here->BSIM4v7DdpBinding->CSC_Complex ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7GPdpPtr = here->BSIM4v7GPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7GPspPtr = here->BSIM4v7GPspBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7SspPtr = here->BSIM4v7SspBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7DPspPtr = here->BSIM4v7DPspBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dNode != 0))
                here->BSIM4v7DPdPtr = here->BSIM4v7DPdBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7DPgpPtr = here->BSIM4v7DPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7SPgpPtr = here->BSIM4v7SPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sNode != 0))
                here->BSIM4v7SPsPtr = here->BSIM4v7SPsBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7SPdpPtr = here->BSIM4v7SPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7QqPtr = here->BSIM4v7QqBinding->CSC_Complex ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7QbpPtr = here->BSIM4v7QbpBinding->CSC_Complex ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7QdpPtr = here->BSIM4v7QdpBinding->CSC_Complex ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7QspPtr = here->BSIM4v7QspBinding->CSC_Complex ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7QgpPtr = here->BSIM4v7QgpBinding->CSC_Complex ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7DPqPtr = here->BSIM4v7DPqBinding->CSC_Complex ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7SPqPtr = here->BSIM4v7SPqBinding->CSC_Complex ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7GPqPtr = here->BSIM4v7GPqBinding->CSC_Complex ;

            if (here->BSIM4v7rgateMod != 0)
            {
                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodeExt != 0))
                    here->BSIM4v7GEgePtr = here->BSIM4v7GEgeBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7GEgpPtr = here->BSIM4v7GEgpBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodeExt != 0))
                    here->BSIM4v7GPgePtr = here->BSIM4v7GPgeBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7GEdpPtr = here->BSIM4v7GEdpBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7GEspPtr = here->BSIM4v7GEspBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7GEbpPtr = here->BSIM4v7GEbpBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7GMdpPtr = here->BSIM4v7GMdpBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7GMgpPtr = here->BSIM4v7GMgpBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7GMgmPtr = here->BSIM4v7GMgmBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodeExt != 0))
                    here->BSIM4v7GMgePtr = here->BSIM4v7GMgeBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7GMspPtr = here->BSIM4v7GMspBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7GMbpPtr = here->BSIM4v7GMbpBinding->CSC_Complex ;

                if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7DPgmPtr = here->BSIM4v7DPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7GPgmPtr = here->BSIM4v7GPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7GEgmPtr = here->BSIM4v7GEgmBinding->CSC_Complex ;

                if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7SPgmPtr = here->BSIM4v7SPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7BPgmPtr = here->BSIM4v7BPgmBinding->CSC_Complex ;

            }
            if ((here->BSIM4v7rbodyMod == 1) || (here->BSIM4v7rbodyMod == 2))
            {
                if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7DPdbPtr = here->BSIM4v7DPdbBinding->CSC_Complex ;

                if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7SPsbPtr = here->BSIM4v7SPsbBinding->CSC_Complex ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7DBdpPtr = here->BSIM4v7DBdpBinding->CSC_Complex ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7DBdbPtr = here->BSIM4v7DBdbBinding->CSC_Complex ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7DBbpPtr = here->BSIM4v7DBbpBinding->CSC_Complex ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7DBbPtr = here->BSIM4v7DBbBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7BPdbPtr = here->BSIM4v7BPdbBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7BPbPtr = here->BSIM4v7BPbBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7BPsbPtr = here->BSIM4v7BPsbBinding->CSC_Complex ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7SBspPtr = here->BSIM4v7SBspBinding->CSC_Complex ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7SBbpPtr = here->BSIM4v7SBbpBinding->CSC_Complex ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7SBbPtr = here->BSIM4v7SBbBinding->CSC_Complex ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7SBsbPtr = here->BSIM4v7SBsbBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7BdbPtr = here->BSIM4v7BdbBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7BbpPtr = here->BSIM4v7BbpBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7BsbPtr = here->BSIM4v7BsbBinding->CSC_Complex ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7BbPtr = here->BSIM4v7BbBinding->CSC_Complex ;

            }
            if (model->BSIM4v7rdsMod)
            {
                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7DgpPtr = here->BSIM4v7DgpBinding->CSC_Complex ;

                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7DspPtr = here->BSIM4v7DspBinding->CSC_Complex ;

                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7DbpPtr = here->BSIM4v7DbpBinding->CSC_Complex ;

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7SdpPtr = here->BSIM4v7SdpBinding->CSC_Complex ;

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7SgpPtr = here->BSIM4v7SgpBinding->CSC_Complex ;

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7SbpPtr = here->BSIM4v7SbpBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
BSIM4v7bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v7model *model = (BSIM4v7model *)inModel ;
    BSIM4v7instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4v7 models */
    for ( ; model != NULL ; model = model->BSIM4v7nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v7instances ; here != NULL ; here = here->BSIM4v7nextInstance)
        {
            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7DPbpPtr = here->BSIM4v7DPbpBinding->CSC ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7GPbpPtr = here->BSIM4v7GPbpBinding->CSC ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7SPbpPtr = here->BSIM4v7SPbpBinding->CSC ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7BPdpPtr = here->BSIM4v7BPdpBinding->CSC ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7BPgpPtr = here->BSIM4v7BPgpBinding->CSC ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7BPspPtr = here->BSIM4v7BPspBinding->CSC ;

            if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7BPbpPtr = here->BSIM4v7BPbpBinding->CSC ;

            if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7dNode != 0))
                here->BSIM4v7DdPtr = here->BSIM4v7DdBinding->CSC ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7GPgpPtr = here->BSIM4v7GPgpBinding->CSC ;

            if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7sNode != 0))
                here->BSIM4v7SsPtr = here->BSIM4v7SsBinding->CSC ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7DPdpPtr = here->BSIM4v7DPdpBinding->CSC ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7SPspPtr = here->BSIM4v7SPspBinding->CSC ;

            if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7DdpPtr = here->BSIM4v7DdpBinding->CSC ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7GPdpPtr = here->BSIM4v7GPdpBinding->CSC ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7GPspPtr = here->BSIM4v7GPspBinding->CSC ;

            if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7SspPtr = here->BSIM4v7SspBinding->CSC ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7DPspPtr = here->BSIM4v7DPspBinding->CSC ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dNode != 0))
                here->BSIM4v7DPdPtr = here->BSIM4v7DPdBinding->CSC ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7DPgpPtr = here->BSIM4v7DPgpBinding->CSC ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7SPgpPtr = here->BSIM4v7SPgpBinding->CSC ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sNode != 0))
                here->BSIM4v7SPsPtr = here->BSIM4v7SPsBinding->CSC ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7SPdpPtr = here->BSIM4v7SPdpBinding->CSC ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7QqPtr = here->BSIM4v7QqBinding->CSC ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                here->BSIM4v7QbpPtr = here->BSIM4v7QbpBinding->CSC ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                here->BSIM4v7QdpPtr = here->BSIM4v7QdpBinding->CSC ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                here->BSIM4v7QspPtr = here->BSIM4v7QspBinding->CSC ;

            if ((here-> BSIM4v7qNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                here->BSIM4v7QgpPtr = here->BSIM4v7QgpBinding->CSC ;

            if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7DPqPtr = here->BSIM4v7DPqBinding->CSC ;

            if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7SPqPtr = here->BSIM4v7SPqBinding->CSC ;

            if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7qNode != 0))
                here->BSIM4v7GPqPtr = here->BSIM4v7GPqBinding->CSC ;

            if (here->BSIM4v7rgateMod != 0)
            {
                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodeExt != 0))
                    here->BSIM4v7GEgePtr = here->BSIM4v7GEgeBinding->CSC ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7GEgpPtr = here->BSIM4v7GEgpBinding->CSC ;

                if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodeExt != 0))
                    here->BSIM4v7GPgePtr = here->BSIM4v7GPgeBinding->CSC ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7GEdpPtr = here->BSIM4v7GEdpBinding->CSC ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7GEspPtr = here->BSIM4v7GEspBinding->CSC ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7GEbpPtr = here->BSIM4v7GEbpBinding->CSC ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7GMdpPtr = here->BSIM4v7GMdpBinding->CSC ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7GMgpPtr = here->BSIM4v7GMgpBinding->CSC ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7GMgmPtr = here->BSIM4v7GMgmBinding->CSC ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7gNodeExt != 0))
                    here->BSIM4v7GMgePtr = here->BSIM4v7GMgeBinding->CSC ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7GMspPtr = here->BSIM4v7GMspBinding->CSC ;

                if ((here-> BSIM4v7gNodeMid != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7GMbpPtr = here->BSIM4v7GMbpBinding->CSC ;

                if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7DPgmPtr = here->BSIM4v7DPgmBinding->CSC ;

                if ((here-> BSIM4v7gNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7GPgmPtr = here->BSIM4v7GPgmBinding->CSC ;

                if ((here-> BSIM4v7gNodeExt != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7GEgmPtr = here->BSIM4v7GEgmBinding->CSC ;

                if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7SPgmPtr = here->BSIM4v7SPgmBinding->CSC ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7gNodeMid != 0))
                    here->BSIM4v7BPgmPtr = here->BSIM4v7BPgmBinding->CSC ;

            }
            if ((here->BSIM4v7rbodyMod == 1) || (here->BSIM4v7rbodyMod == 2))
            {
                if ((here-> BSIM4v7dNodePrime != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7DPdbPtr = here->BSIM4v7DPdbBinding->CSC ;

                if ((here-> BSIM4v7sNodePrime != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7SPsbPtr = here->BSIM4v7SPsbBinding->CSC ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7DBdpPtr = here->BSIM4v7DBdpBinding->CSC ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7DBdbPtr = here->BSIM4v7DBdbBinding->CSC ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7DBbpPtr = here->BSIM4v7DBbpBinding->CSC ;

                if ((here-> BSIM4v7dbNode != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7DBbPtr = here->BSIM4v7DBbBinding->CSC ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7BPdbPtr = here->BSIM4v7BPdbBinding->CSC ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7BPbPtr = here->BSIM4v7BPbBinding->CSC ;

                if ((here-> BSIM4v7bNodePrime != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7BPsbPtr = here->BSIM4v7BPsbBinding->CSC ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7SBspPtr = here->BSIM4v7SBspBinding->CSC ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7SBbpPtr = here->BSIM4v7SBbpBinding->CSC ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7SBbPtr = here->BSIM4v7SBbBinding->CSC ;

                if ((here-> BSIM4v7sbNode != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7SBsbPtr = here->BSIM4v7SBsbBinding->CSC ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7dbNode != 0))
                    here->BSIM4v7BdbPtr = here->BSIM4v7BdbBinding->CSC ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7BbpPtr = here->BSIM4v7BbpBinding->CSC ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7sbNode != 0))
                    here->BSIM4v7BsbPtr = here->BSIM4v7BsbBinding->CSC ;

                if ((here-> BSIM4v7bNode != 0) && (here-> BSIM4v7bNode != 0))
                    here->BSIM4v7BbPtr = here->BSIM4v7BbBinding->CSC ;

            }
            if (model->BSIM4v7rdsMod)
            {
                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7DgpPtr = here->BSIM4v7DgpBinding->CSC ;

                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7sNodePrime != 0))
                    here->BSIM4v7DspPtr = here->BSIM4v7DspBinding->CSC ;

                if ((here-> BSIM4v7dNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7DbpPtr = here->BSIM4v7DbpBinding->CSC ;

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7dNodePrime != 0))
                    here->BSIM4v7SdpPtr = here->BSIM4v7SdpBinding->CSC ;

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7gNodePrime != 0))
                    here->BSIM4v7SgpPtr = here->BSIM4v7SgpBinding->CSC ;

                if ((here-> BSIM4v7sNode != 0) && (here-> BSIM4v7bNodePrime != 0))
                    here->BSIM4v7SbpPtr = here->BSIM4v7SbpBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
