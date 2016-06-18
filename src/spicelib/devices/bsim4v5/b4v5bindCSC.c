/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim4v5def.h"
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
BSIM4v5bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v5model *model = (BSIM4v5model *)inModel ;
    BSIM4v5instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM4v5 models */
    for ( ; model != NULL ; model = model->BSIM4v5nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v5instances ; here != NULL ; here = here->BSIM4v5nextInstance)
        {
            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
            {
                i = here->BSIM4v5DPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DPbpBinding = matched ;
                here->BSIM4v5DPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
            {
                i = here->BSIM4v5GPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5GPbpBinding = matched ;
                here->BSIM4v5GPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
            {
                i = here->BSIM4v5SPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SPbpBinding = matched ;
                here->BSIM4v5SPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
            {
                i = here->BSIM4v5BPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5BPdpBinding = matched ;
                here->BSIM4v5BPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
            {
                i = here->BSIM4v5BPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5BPgpBinding = matched ;
                here->BSIM4v5BPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
            {
                i = here->BSIM4v5BPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5BPspBinding = matched ;
                here->BSIM4v5BPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
            {
                i = here->BSIM4v5BPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5BPbpBinding = matched ;
                here->BSIM4v5BPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5dNode != 0))
            {
                i = here->BSIM4v5DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DdBinding = matched ;
                here->BSIM4v5DdPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
            {
                i = here->BSIM4v5GPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5GPgpBinding = matched ;
                here->BSIM4v5GPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5sNode != 0))
            {
                i = here->BSIM4v5SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SsBinding = matched ;
                here->BSIM4v5SsPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
            {
                i = here->BSIM4v5DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DPdpBinding = matched ;
                here->BSIM4v5DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
            {
                i = here->BSIM4v5SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SPspBinding = matched ;
                here->BSIM4v5SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5dNodePrime != 0))
            {
                i = here->BSIM4v5DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DdpBinding = matched ;
                here->BSIM4v5DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
            {
                i = here->BSIM4v5GPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5GPdpBinding = matched ;
                here->BSIM4v5GPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
            {
                i = here->BSIM4v5GPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5GPspBinding = matched ;
                here->BSIM4v5GPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5sNodePrime != 0))
            {
                i = here->BSIM4v5SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SspBinding = matched ;
                here->BSIM4v5SspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
            {
                i = here->BSIM4v5DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DPspBinding = matched ;
                here->BSIM4v5DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dNode != 0))
            {
                i = here->BSIM4v5DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DPdBinding = matched ;
                here->BSIM4v5DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
            {
                i = here->BSIM4v5DPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DPgpBinding = matched ;
                here->BSIM4v5DPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
            {
                i = here->BSIM4v5SPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SPgpBinding = matched ;
                here->BSIM4v5SPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sNode != 0))
            {
                i = here->BSIM4v5SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SPsBinding = matched ;
                here->BSIM4v5SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
            {
                i = here->BSIM4v5SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SPdpBinding = matched ;
                here->BSIM4v5SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5qNode != 0))
            {
                i = here->BSIM4v5QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5QqBinding = matched ;
                here->BSIM4v5QqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5bNodePrime != 0))
            {
                i = here->BSIM4v5QbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5QbpBinding = matched ;
                here->BSIM4v5QbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5dNodePrime != 0))
            {
                i = here->BSIM4v5QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5QdpBinding = matched ;
                here->BSIM4v5QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5sNodePrime != 0))
            {
                i = here->BSIM4v5QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5QspBinding = matched ;
                here->BSIM4v5QspPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5gNodePrime != 0))
            {
                i = here->BSIM4v5QgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5QgpBinding = matched ;
                here->BSIM4v5QgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5qNode != 0))
            {
                i = here->BSIM4v5DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5DPqBinding = matched ;
                here->BSIM4v5DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5qNode != 0))
            {
                i = here->BSIM4v5SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5SPqBinding = matched ;
                here->BSIM4v5SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5qNode != 0))
            {
                i = here->BSIM4v5GPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4v5GPqBinding = matched ;
                here->BSIM4v5GPqPtr = matched->CSC ;
            }

            if (here->BSIM4v5rgateMod != 0)
            {
                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodeExt != 0))
                {
                    i = here->BSIM4v5GEgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GEgeBinding = matched ;
                    here->BSIM4v5GEgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodePrime != 0))
                {
                    i = here->BSIM4v5GEgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GEgpBinding = matched ;
                    here->BSIM4v5GEgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodeExt != 0))
                {
                    i = here->BSIM4v5GPgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GPgeBinding = matched ;
                    here->BSIM4v5GPgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5dNodePrime != 0))
                {
                    i = here->BSIM4v5GEdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GEdpBinding = matched ;
                    here->BSIM4v5GEdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5sNodePrime != 0))
                {
                    i = here->BSIM4v5GEspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GEspBinding = matched ;
                    here->BSIM4v5GEspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5GEbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GEbpBinding = matched ;
                    here->BSIM4v5GEbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5dNodePrime != 0))
                {
                    i = here->BSIM4v5GMdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GMdpBinding = matched ;
                    here->BSIM4v5GMdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodePrime != 0))
                {
                    i = here->BSIM4v5GMgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GMgpBinding = matched ;
                    here->BSIM4v5GMgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodeMid != 0))
                {
                    i = here->BSIM4v5GMgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GMgmBinding = matched ;
                    here->BSIM4v5GMgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodeExt != 0))
                {
                    i = here->BSIM4v5GMgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GMgeBinding = matched ;
                    here->BSIM4v5GMgePtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5sNodePrime != 0))
                {
                    i = here->BSIM4v5GMspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GMspBinding = matched ;
                    here->BSIM4v5GMspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5GMbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GMbpBinding = matched ;
                    here->BSIM4v5GMbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                {
                    i = here->BSIM4v5DPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DPgmBinding = matched ;
                    here->BSIM4v5DPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                {
                    i = here->BSIM4v5GPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GPgmBinding = matched ;
                    here->BSIM4v5GPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodeMid != 0))
                {
                    i = here->BSIM4v5GEgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5GEgmBinding = matched ;
                    here->BSIM4v5GEgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                {
                    i = here->BSIM4v5SPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SPgmBinding = matched ;
                    here->BSIM4v5SPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                {
                    i = here->BSIM4v5BPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BPgmBinding = matched ;
                    here->BSIM4v5BPgmPtr = matched->CSC ;
                }

            }
            if ((here->BSIM4v5rbodyMod == 1) || (here->BSIM4v5rbodyMod == 2))
            {
                if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dbNode != 0))
                {
                    i = here->BSIM4v5DPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DPdbBinding = matched ;
                    here->BSIM4v5DPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sbNode != 0))
                {
                    i = here->BSIM4v5SPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SPsbBinding = matched ;
                    here->BSIM4v5SPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                {
                    i = here->BSIM4v5DBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DBdpBinding = matched ;
                    here->BSIM4v5DBdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5dbNode != 0))
                {
                    i = here->BSIM4v5DBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DBdbBinding = matched ;
                    here->BSIM4v5DBdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5DBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DBbpBinding = matched ;
                    here->BSIM4v5DBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5bNode != 0))
                {
                    i = here->BSIM4v5DBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DBbBinding = matched ;
                    here->BSIM4v5DBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5dbNode != 0))
                {
                    i = here->BSIM4v5BPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BPdbBinding = matched ;
                    here->BSIM4v5BPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5bNode != 0))
                {
                    i = here->BSIM4v5BPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BPbBinding = matched ;
                    here->BSIM4v5BPbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5sbNode != 0))
                {
                    i = here->BSIM4v5BPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BPsbBinding = matched ;
                    here->BSIM4v5BPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                {
                    i = here->BSIM4v5SBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SBspBinding = matched ;
                    here->BSIM4v5SBspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5SBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SBbpBinding = matched ;
                    here->BSIM4v5SBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5bNode != 0))
                {
                    i = here->BSIM4v5SBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SBbBinding = matched ;
                    here->BSIM4v5SBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5sbNode != 0))
                {
                    i = here->BSIM4v5SBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SBsbBinding = matched ;
                    here->BSIM4v5SBsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5dbNode != 0))
                {
                    i = here->BSIM4v5BdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BdbBinding = matched ;
                    here->BSIM4v5BdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5BbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BbpBinding = matched ;
                    here->BSIM4v5BbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5sbNode != 0))
                {
                    i = here->BSIM4v5BsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BsbBinding = matched ;
                    here->BSIM4v5BsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5bNode != 0))
                {
                    i = here->BSIM4v5BbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5BbBinding = matched ;
                    here->BSIM4v5BbPtr = matched->CSC ;
                }

            }
            if (model->BSIM4v5rdsMod)
            {
                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                {
                    i = here->BSIM4v5DgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DgpBinding = matched ;
                    here->BSIM4v5DgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                {
                    i = here->BSIM4v5DspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DspBinding = matched ;
                    here->BSIM4v5DspPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5DbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5DbpBinding = matched ;
                    here->BSIM4v5DbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                {
                    i = here->BSIM4v5SdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SdpBinding = matched ;
                    here->BSIM4v5SdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                {
                    i = here->BSIM4v5SgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SgpBinding = matched ;
                    here->BSIM4v5SgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                {
                    i = here->BSIM4v5SbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4v5SbpBinding = matched ;
                    here->BSIM4v5SbpPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
BSIM4v5bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v5model *model = (BSIM4v5model *)inModel ;
    BSIM4v5instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4v5 models */
    for ( ; model != NULL ; model = model->BSIM4v5nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v5instances ; here != NULL ; here = here->BSIM4v5nextInstance)
        {
            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5DPbpPtr = here->BSIM4v5DPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5GPbpPtr = here->BSIM4v5GPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5SPbpPtr = here->BSIM4v5SPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5BPdpPtr = here->BSIM4v5BPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5BPgpPtr = here->BSIM4v5BPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5BPspPtr = here->BSIM4v5BPspBinding->CSC_Complex ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5BPbpPtr = here->BSIM4v5BPbpBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5dNode != 0))
                here->BSIM4v5DdPtr = here->BSIM4v5DdBinding->CSC_Complex ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5GPgpPtr = here->BSIM4v5GPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5sNode != 0))
                here->BSIM4v5SsPtr = here->BSIM4v5SsBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5DPdpPtr = here->BSIM4v5DPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5SPspPtr = here->BSIM4v5SPspBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5DdpPtr = here->BSIM4v5DdpBinding->CSC_Complex ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5GPdpPtr = here->BSIM4v5GPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5GPspPtr = here->BSIM4v5GPspBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5SspPtr = here->BSIM4v5SspBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5DPspPtr = here->BSIM4v5DPspBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dNode != 0))
                here->BSIM4v5DPdPtr = here->BSIM4v5DPdBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5DPgpPtr = here->BSIM4v5DPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5SPgpPtr = here->BSIM4v5SPgpBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sNode != 0))
                here->BSIM4v5SPsPtr = here->BSIM4v5SPsBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5SPdpPtr = here->BSIM4v5SPdpBinding->CSC_Complex ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5QqPtr = here->BSIM4v5QqBinding->CSC_Complex ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5QbpPtr = here->BSIM4v5QbpBinding->CSC_Complex ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5QdpPtr = here->BSIM4v5QdpBinding->CSC_Complex ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5QspPtr = here->BSIM4v5QspBinding->CSC_Complex ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5QgpPtr = here->BSIM4v5QgpBinding->CSC_Complex ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5DPqPtr = here->BSIM4v5DPqBinding->CSC_Complex ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5SPqPtr = here->BSIM4v5SPqBinding->CSC_Complex ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5GPqPtr = here->BSIM4v5GPqBinding->CSC_Complex ;

            if (here->BSIM4v5rgateMod != 0)
            {
                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodeExt != 0))
                    here->BSIM4v5GEgePtr = here->BSIM4v5GEgeBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5GEgpPtr = here->BSIM4v5GEgpBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodeExt != 0))
                    here->BSIM4v5GPgePtr = here->BSIM4v5GPgeBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5GEdpPtr = here->BSIM4v5GEdpBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5GEspPtr = here->BSIM4v5GEspBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5GEbpPtr = here->BSIM4v5GEbpBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5GMdpPtr = here->BSIM4v5GMdpBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5GMgpPtr = here->BSIM4v5GMgpBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5GMgmPtr = here->BSIM4v5GMgmBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodeExt != 0))
                    here->BSIM4v5GMgePtr = here->BSIM4v5GMgeBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5GMspPtr = here->BSIM4v5GMspBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5GMbpPtr = here->BSIM4v5GMbpBinding->CSC_Complex ;

                if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5DPgmPtr = here->BSIM4v5DPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5GPgmPtr = here->BSIM4v5GPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5GEgmPtr = here->BSIM4v5GEgmBinding->CSC_Complex ;

                if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5SPgmPtr = here->BSIM4v5SPgmBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5BPgmPtr = here->BSIM4v5BPgmBinding->CSC_Complex ;

            }
            if ((here->BSIM4v5rbodyMod == 1) || (here->BSIM4v5rbodyMod == 2))
            {
                if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5DPdbPtr = here->BSIM4v5DPdbBinding->CSC_Complex ;

                if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5SPsbPtr = here->BSIM4v5SPsbBinding->CSC_Complex ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5DBdpPtr = here->BSIM4v5DBdpBinding->CSC_Complex ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5DBdbPtr = here->BSIM4v5DBdbBinding->CSC_Complex ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5DBbpPtr = here->BSIM4v5DBbpBinding->CSC_Complex ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5DBbPtr = here->BSIM4v5DBbBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5BPdbPtr = here->BSIM4v5BPdbBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5BPbPtr = here->BSIM4v5BPbBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5BPsbPtr = here->BSIM4v5BPsbBinding->CSC_Complex ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5SBspPtr = here->BSIM4v5SBspBinding->CSC_Complex ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5SBbpPtr = here->BSIM4v5SBbpBinding->CSC_Complex ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5SBbPtr = here->BSIM4v5SBbBinding->CSC_Complex ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5SBsbPtr = here->BSIM4v5SBsbBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5BdbPtr = here->BSIM4v5BdbBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5BbpPtr = here->BSIM4v5BbpBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5BsbPtr = here->BSIM4v5BsbBinding->CSC_Complex ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5BbPtr = here->BSIM4v5BbBinding->CSC_Complex ;

            }
            if (model->BSIM4v5rdsMod)
            {
                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5DgpPtr = here->BSIM4v5DgpBinding->CSC_Complex ;

                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5DspPtr = here->BSIM4v5DspBinding->CSC_Complex ;

                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5DbpPtr = here->BSIM4v5DbpBinding->CSC_Complex ;

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5SdpPtr = here->BSIM4v5SdpBinding->CSC_Complex ;

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5SgpPtr = here->BSIM4v5SgpBinding->CSC_Complex ;

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5SbpPtr = here->BSIM4v5SbpBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
BSIM4v5bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM4v5model *model = (BSIM4v5model *)inModel ;
    BSIM4v5instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM4v5 models */
    for ( ; model != NULL ; model = model->BSIM4v5nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM4v5instances ; here != NULL ; here = here->BSIM4v5nextInstance)
        {
            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5DPbpPtr = here->BSIM4v5DPbpBinding->CSC ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5GPbpPtr = here->BSIM4v5GPbpBinding->CSC ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5SPbpPtr = here->BSIM4v5SPbpBinding->CSC ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5BPdpPtr = here->BSIM4v5BPdpBinding->CSC ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5BPgpPtr = here->BSIM4v5BPgpBinding->CSC ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5BPspPtr = here->BSIM4v5BPspBinding->CSC ;

            if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5BPbpPtr = here->BSIM4v5BPbpBinding->CSC ;

            if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5dNode != 0))
                here->BSIM4v5DdPtr = here->BSIM4v5DdBinding->CSC ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5GPgpPtr = here->BSIM4v5GPgpBinding->CSC ;

            if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5sNode != 0))
                here->BSIM4v5SsPtr = here->BSIM4v5SsBinding->CSC ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5DPdpPtr = here->BSIM4v5DPdpBinding->CSC ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5SPspPtr = here->BSIM4v5SPspBinding->CSC ;

            if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5DdpPtr = here->BSIM4v5DdpBinding->CSC ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5GPdpPtr = here->BSIM4v5GPdpBinding->CSC ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5GPspPtr = here->BSIM4v5GPspBinding->CSC ;

            if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5SspPtr = here->BSIM4v5SspBinding->CSC ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5DPspPtr = here->BSIM4v5DPspBinding->CSC ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dNode != 0))
                here->BSIM4v5DPdPtr = here->BSIM4v5DPdBinding->CSC ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5DPgpPtr = here->BSIM4v5DPgpBinding->CSC ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5SPgpPtr = here->BSIM4v5SPgpBinding->CSC ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sNode != 0))
                here->BSIM4v5SPsPtr = here->BSIM4v5SPsBinding->CSC ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5SPdpPtr = here->BSIM4v5SPdpBinding->CSC ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5QqPtr = here->BSIM4v5QqBinding->CSC ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                here->BSIM4v5QbpPtr = here->BSIM4v5QbpBinding->CSC ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                here->BSIM4v5QdpPtr = here->BSIM4v5QdpBinding->CSC ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                here->BSIM4v5QspPtr = here->BSIM4v5QspBinding->CSC ;

            if ((here-> BSIM4v5qNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                here->BSIM4v5QgpPtr = here->BSIM4v5QgpBinding->CSC ;

            if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5DPqPtr = here->BSIM4v5DPqBinding->CSC ;

            if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5SPqPtr = here->BSIM4v5SPqBinding->CSC ;

            if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5qNode != 0))
                here->BSIM4v5GPqPtr = here->BSIM4v5GPqBinding->CSC ;

            if (here->BSIM4v5rgateMod != 0)
            {
                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodeExt != 0))
                    here->BSIM4v5GEgePtr = here->BSIM4v5GEgeBinding->CSC ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5GEgpPtr = here->BSIM4v5GEgpBinding->CSC ;

                if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodeExt != 0))
                    here->BSIM4v5GPgePtr = here->BSIM4v5GPgeBinding->CSC ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5GEdpPtr = here->BSIM4v5GEdpBinding->CSC ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5GEspPtr = here->BSIM4v5GEspBinding->CSC ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5GEbpPtr = here->BSIM4v5GEbpBinding->CSC ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5GMdpPtr = here->BSIM4v5GMdpBinding->CSC ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5GMgpPtr = here->BSIM4v5GMgpBinding->CSC ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5GMgmPtr = here->BSIM4v5GMgmBinding->CSC ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5gNodeExt != 0))
                    here->BSIM4v5GMgePtr = here->BSIM4v5GMgeBinding->CSC ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5GMspPtr = here->BSIM4v5GMspBinding->CSC ;

                if ((here-> BSIM4v5gNodeMid != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5GMbpPtr = here->BSIM4v5GMbpBinding->CSC ;

                if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5DPgmPtr = here->BSIM4v5DPgmBinding->CSC ;

                if ((here-> BSIM4v5gNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5GPgmPtr = here->BSIM4v5GPgmBinding->CSC ;

                if ((here-> BSIM4v5gNodeExt != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5GEgmPtr = here->BSIM4v5GEgmBinding->CSC ;

                if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5SPgmPtr = here->BSIM4v5SPgmBinding->CSC ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5gNodeMid != 0))
                    here->BSIM4v5BPgmPtr = here->BSIM4v5BPgmBinding->CSC ;

            }
            if ((here->BSIM4v5rbodyMod == 1) || (here->BSIM4v5rbodyMod == 2))
            {
                if ((here-> BSIM4v5dNodePrime != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5DPdbPtr = here->BSIM4v5DPdbBinding->CSC ;

                if ((here-> BSIM4v5sNodePrime != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5SPsbPtr = here->BSIM4v5SPsbBinding->CSC ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5DBdpPtr = here->BSIM4v5DBdpBinding->CSC ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5DBdbPtr = here->BSIM4v5DBdbBinding->CSC ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5DBbpPtr = here->BSIM4v5DBbpBinding->CSC ;

                if ((here-> BSIM4v5dbNode != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5DBbPtr = here->BSIM4v5DBbBinding->CSC ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5BPdbPtr = here->BSIM4v5BPdbBinding->CSC ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5BPbPtr = here->BSIM4v5BPbBinding->CSC ;

                if ((here-> BSIM4v5bNodePrime != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5BPsbPtr = here->BSIM4v5BPsbBinding->CSC ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5SBspPtr = here->BSIM4v5SBspBinding->CSC ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5SBbpPtr = here->BSIM4v5SBbpBinding->CSC ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5SBbPtr = here->BSIM4v5SBbBinding->CSC ;

                if ((here-> BSIM4v5sbNode != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5SBsbPtr = here->BSIM4v5SBsbBinding->CSC ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5dbNode != 0))
                    here->BSIM4v5BdbPtr = here->BSIM4v5BdbBinding->CSC ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5BbpPtr = here->BSIM4v5BbpBinding->CSC ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5sbNode != 0))
                    here->BSIM4v5BsbPtr = here->BSIM4v5BsbBinding->CSC ;

                if ((here-> BSIM4v5bNode != 0) && (here-> BSIM4v5bNode != 0))
                    here->BSIM4v5BbPtr = here->BSIM4v5BbBinding->CSC ;

            }
            if (model->BSIM4v5rdsMod)
            {
                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5DgpPtr = here->BSIM4v5DgpBinding->CSC ;

                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5sNodePrime != 0))
                    here->BSIM4v5DspPtr = here->BSIM4v5DspBinding->CSC ;

                if ((here-> BSIM4v5dNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5DbpPtr = here->BSIM4v5DbpBinding->CSC ;

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5dNodePrime != 0))
                    here->BSIM4v5SdpPtr = here->BSIM4v5SdpBinding->CSC ;

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5gNodePrime != 0))
                    here->BSIM4v5SgpPtr = here->BSIM4v5SgpBinding->CSC ;

                if ((here-> BSIM4v5sNode != 0) && (here-> BSIM4v5bNodePrime != 0))
                    here->BSIM4v5SbpPtr = here->BSIM4v5SbpBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
