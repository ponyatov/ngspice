/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim4def.h"
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
            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
            {
                i = here->BSIM4DPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DPbpBinding = matched ;
                here->BSIM4DPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
            {
                i = here->BSIM4GPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4GPbpBinding = matched ;
                here->BSIM4GPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
            {
                i = here->BSIM4SPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SPbpBinding = matched ;
                here->BSIM4SPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
            {
                i = here->BSIM4BPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4BPdpBinding = matched ;
                here->BSIM4BPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
            {
                i = here->BSIM4BPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4BPgpBinding = matched ;
                here->BSIM4BPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
            {
                i = here->BSIM4BPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4BPspBinding = matched ;
                here->BSIM4BPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
            {
                i = here->BSIM4BPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4BPbpBinding = matched ;
                here->BSIM4BPbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNode != 0) && (here-> BSIM4dNode != 0))
            {
                i = here->BSIM4DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DdBinding = matched ;
                here->BSIM4DdPtr = matched->CSC ;
            }

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
            {
                i = here->BSIM4GPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4GPgpBinding = matched ;
                here->BSIM4GPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNode != 0) && (here-> BSIM4sNode != 0))
            {
                i = here->BSIM4SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SsBinding = matched ;
                here->BSIM4SsPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
            {
                i = here->BSIM4DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DPdpBinding = matched ;
                here->BSIM4DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
            {
                i = here->BSIM4SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SPspBinding = matched ;
                here->BSIM4SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNode != 0) && (here-> BSIM4dNodePrime != 0))
            {
                i = here->BSIM4DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DdpBinding = matched ;
                here->BSIM4DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
            {
                i = here->BSIM4GPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4GPdpBinding = matched ;
                here->BSIM4GPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
            {
                i = here->BSIM4GPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4GPspBinding = matched ;
                here->BSIM4GPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNode != 0) && (here-> BSIM4sNodePrime != 0))
            {
                i = here->BSIM4SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SspBinding = matched ;
                here->BSIM4SspPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
            {
                i = here->BSIM4DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DPspBinding = matched ;
                here->BSIM4DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dNode != 0))
            {
                i = here->BSIM4DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DPdBinding = matched ;
                here->BSIM4DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
            {
                i = here->BSIM4DPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DPgpBinding = matched ;
                here->BSIM4DPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
            {
                i = here->BSIM4SPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SPgpBinding = matched ;
                here->BSIM4SPgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sNode != 0))
            {
                i = here->BSIM4SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SPsBinding = matched ;
                here->BSIM4SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
            {
                i = here->BSIM4SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SPdpBinding = matched ;
                here->BSIM4SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4qNode != 0))
            {
                i = here->BSIM4QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4QqBinding = matched ;
                here->BSIM4QqPtr = matched->CSC ;
            }

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4bNodePrime != 0))
            {
                i = here->BSIM4QbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4QbpBinding = matched ;
                here->BSIM4QbpPtr = matched->CSC ;
            }

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4dNodePrime != 0))
            {
                i = here->BSIM4QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4QdpBinding = matched ;
                here->BSIM4QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4sNodePrime != 0))
            {
                i = here->BSIM4QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4QspBinding = matched ;
                here->BSIM4QspPtr = matched->CSC ;
            }

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4gNodePrime != 0))
            {
                i = here->BSIM4QgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4QgpBinding = matched ;
                here->BSIM4QgpPtr = matched->CSC ;
            }

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4qNode != 0))
            {
                i = here->BSIM4DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4DPqBinding = matched ;
                here->BSIM4DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4qNode != 0))
            {
                i = here->BSIM4SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4SPqBinding = matched ;
                here->BSIM4SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4qNode != 0))
            {
                i = here->BSIM4GPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM4GPqBinding = matched ;
                here->BSIM4GPqPtr = matched->CSC ;
            }

            if (here->BSIM4rgateMod != 0)
            {
                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodeExt != 0))
                {
                    i = here->BSIM4GEgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GEgeBinding = matched ;
                    here->BSIM4GEgePtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodePrime != 0))
                {
                    i = here->BSIM4GEgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GEgpBinding = matched ;
                    here->BSIM4GEgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodeExt != 0))
                {
                    i = here->BSIM4GPgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GPgeBinding = matched ;
                    here->BSIM4GPgePtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4dNodePrime != 0))
                {
                    i = here->BSIM4GEdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GEdpBinding = matched ;
                    here->BSIM4GEdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4sNodePrime != 0))
                {
                    i = here->BSIM4GEspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GEspBinding = matched ;
                    here->BSIM4GEspPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4GEbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GEbpBinding = matched ;
                    here->BSIM4GEbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4dNodePrime != 0))
                {
                    i = here->BSIM4GMdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GMdpBinding = matched ;
                    here->BSIM4GMdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodePrime != 0))
                {
                    i = here->BSIM4GMgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GMgpBinding = matched ;
                    here->BSIM4GMgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodeMid != 0))
                {
                    i = here->BSIM4GMgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GMgmBinding = matched ;
                    here->BSIM4GMgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodeExt != 0))
                {
                    i = here->BSIM4GMgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GMgeBinding = matched ;
                    here->BSIM4GMgePtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4sNodePrime != 0))
                {
                    i = here->BSIM4GMspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GMspBinding = matched ;
                    here->BSIM4GMspPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4GMbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GMbpBinding = matched ;
                    here->BSIM4GMbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                {
                    i = here->BSIM4DPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DPgmBinding = matched ;
                    here->BSIM4DPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                {
                    i = here->BSIM4GPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GPgmBinding = matched ;
                    here->BSIM4GPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodeMid != 0))
                {
                    i = here->BSIM4GEgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4GEgmBinding = matched ;
                    here->BSIM4GEgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                {
                    i = here->BSIM4SPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SPgmBinding = matched ;
                    here->BSIM4SPgmPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                {
                    i = here->BSIM4BPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BPgmBinding = matched ;
                    here->BSIM4BPgmPtr = matched->CSC ;
                }

            }
            if ((here->BSIM4rbodyMod == 1) || (here->BSIM4rbodyMod == 2))
            {
                if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dbNode != 0))
                {
                    i = here->BSIM4DPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DPdbBinding = matched ;
                    here->BSIM4DPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sbNode != 0))
                {
                    i = here->BSIM4SPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SPsbBinding = matched ;
                    here->BSIM4SPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4dNodePrime != 0))
                {
                    i = here->BSIM4DBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DBdpBinding = matched ;
                    here->BSIM4DBdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4dbNode != 0))
                {
                    i = here->BSIM4DBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DBdbBinding = matched ;
                    here->BSIM4DBdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4DBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DBbpBinding = matched ;
                    here->BSIM4DBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4bNode != 0))
                {
                    i = here->BSIM4DBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DBbBinding = matched ;
                    here->BSIM4DBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4dbNode != 0))
                {
                    i = here->BSIM4BPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BPdbBinding = matched ;
                    here->BSIM4BPdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4bNode != 0))
                {
                    i = here->BSIM4BPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BPbBinding = matched ;
                    here->BSIM4BPbPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4sbNode != 0))
                {
                    i = here->BSIM4BPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BPsbBinding = matched ;
                    here->BSIM4BPsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4sNodePrime != 0))
                {
                    i = here->BSIM4SBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SBspBinding = matched ;
                    here->BSIM4SBspPtr = matched->CSC ;
                }

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4SBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SBbpBinding = matched ;
                    here->BSIM4SBbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4bNode != 0))
                {
                    i = here->BSIM4SBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SBbBinding = matched ;
                    here->BSIM4SBbPtr = matched->CSC ;
                }

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4sbNode != 0))
                {
                    i = here->BSIM4SBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SBsbBinding = matched ;
                    here->BSIM4SBsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4dbNode != 0))
                {
                    i = here->BSIM4BdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BdbBinding = matched ;
                    here->BSIM4BdbPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4BbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BbpBinding = matched ;
                    here->BSIM4BbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4sbNode != 0))
                {
                    i = here->BSIM4BsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BsbBinding = matched ;
                    here->BSIM4BsbPtr = matched->CSC ;
                }

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4bNode != 0))
                {
                    i = here->BSIM4BbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4BbBinding = matched ;
                    here->BSIM4BbPtr = matched->CSC ;
                }

            }
            if (model->BSIM4rdsMod)
            {
                if ((here-> BSIM4dNode != 0) && (here-> BSIM4gNodePrime != 0))
                {
                    i = here->BSIM4DgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DgpBinding = matched ;
                    here->BSIM4DgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4dNode != 0) && (here-> BSIM4sNodePrime != 0))
                {
                    i = here->BSIM4DspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DspBinding = matched ;
                    here->BSIM4DspPtr = matched->CSC ;
                }

                if ((here-> BSIM4dNode != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4DbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4DbpBinding = matched ;
                    here->BSIM4DbpPtr = matched->CSC ;
                }

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4dNodePrime != 0))
                {
                    i = here->BSIM4SdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SdpBinding = matched ;
                    here->BSIM4SdpPtr = matched->CSC ;
                }

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4gNodePrime != 0))
                {
                    i = here->BSIM4SgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SgpBinding = matched ;
                    here->BSIM4SgpPtr = matched->CSC ;
                }

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4bNodePrime != 0))
                {
                    i = here->BSIM4SbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->BSIM4SbpBinding = matched ;
                    here->BSIM4SbpPtr = matched->CSC ;
                }

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
            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4DPbpPtr = here->BSIM4DPbpBinding->CSC_Complex ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4GPbpPtr = here->BSIM4GPbpBinding->CSC_Complex ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4SPbpPtr = here->BSIM4SPbpBinding->CSC_Complex ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4BPdpPtr = here->BSIM4BPdpBinding->CSC_Complex ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4BPgpPtr = here->BSIM4BPgpBinding->CSC_Complex ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4BPspPtr = here->BSIM4BPspBinding->CSC_Complex ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4BPbpPtr = here->BSIM4BPbpBinding->CSC_Complex ;

            if ((here-> BSIM4dNode != 0) && (here-> BSIM4dNode != 0))
                here->BSIM4DdPtr = here->BSIM4DdBinding->CSC_Complex ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4GPgpPtr = here->BSIM4GPgpBinding->CSC_Complex ;

            if ((here-> BSIM4sNode != 0) && (here-> BSIM4sNode != 0))
                here->BSIM4SsPtr = here->BSIM4SsBinding->CSC_Complex ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4DPdpPtr = here->BSIM4DPdpBinding->CSC_Complex ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4SPspPtr = here->BSIM4SPspBinding->CSC_Complex ;

            if ((here-> BSIM4dNode != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4DdpPtr = here->BSIM4DdpBinding->CSC_Complex ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4GPdpPtr = here->BSIM4GPdpBinding->CSC_Complex ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4GPspPtr = here->BSIM4GPspBinding->CSC_Complex ;

            if ((here-> BSIM4sNode != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4SspPtr = here->BSIM4SspBinding->CSC_Complex ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4DPspPtr = here->BSIM4DPspBinding->CSC_Complex ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dNode != 0))
                here->BSIM4DPdPtr = here->BSIM4DPdBinding->CSC_Complex ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4DPgpPtr = here->BSIM4DPgpBinding->CSC_Complex ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4SPgpPtr = here->BSIM4SPgpBinding->CSC_Complex ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sNode != 0))
                here->BSIM4SPsPtr = here->BSIM4SPsBinding->CSC_Complex ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4SPdpPtr = here->BSIM4SPdpBinding->CSC_Complex ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4QqPtr = here->BSIM4QqBinding->CSC_Complex ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4QbpPtr = here->BSIM4QbpBinding->CSC_Complex ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4QdpPtr = here->BSIM4QdpBinding->CSC_Complex ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4QspPtr = here->BSIM4QspBinding->CSC_Complex ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4QgpPtr = here->BSIM4QgpBinding->CSC_Complex ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4DPqPtr = here->BSIM4DPqBinding->CSC_Complex ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4SPqPtr = here->BSIM4SPqBinding->CSC_Complex ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4GPqPtr = here->BSIM4GPqBinding->CSC_Complex ;

            if (here->BSIM4rgateMod != 0)
            {
                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodeExt != 0))
                    here->BSIM4GEgePtr = here->BSIM4GEgeBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4GEgpPtr = here->BSIM4GEgpBinding->CSC_Complex ;

                if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodeExt != 0))
                    here->BSIM4GPgePtr = here->BSIM4GPgeBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4GEdpPtr = here->BSIM4GEdpBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4GEspPtr = here->BSIM4GEspBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4GEbpPtr = here->BSIM4GEbpBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4GMdpPtr = here->BSIM4GMdpBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4GMgpPtr = here->BSIM4GMgpBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4GMgmPtr = here->BSIM4GMgmBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodeExt != 0))
                    here->BSIM4GMgePtr = here->BSIM4GMgeBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4GMspPtr = here->BSIM4GMspBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4GMbpPtr = here->BSIM4GMbpBinding->CSC_Complex ;

                if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4DPgmPtr = here->BSIM4DPgmBinding->CSC_Complex ;

                if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4GPgmPtr = here->BSIM4GPgmBinding->CSC_Complex ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4GEgmPtr = here->BSIM4GEgmBinding->CSC_Complex ;

                if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4SPgmPtr = here->BSIM4SPgmBinding->CSC_Complex ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4BPgmPtr = here->BSIM4BPgmBinding->CSC_Complex ;

            }
            if ((here->BSIM4rbodyMod == 1) || (here->BSIM4rbodyMod == 2))
            {
                if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4DPdbPtr = here->BSIM4DPdbBinding->CSC_Complex ;

                if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4SPsbPtr = here->BSIM4SPsbBinding->CSC_Complex ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4DBdpPtr = here->BSIM4DBdpBinding->CSC_Complex ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4DBdbPtr = here->BSIM4DBdbBinding->CSC_Complex ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4DBbpPtr = here->BSIM4DBbpBinding->CSC_Complex ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4DBbPtr = here->BSIM4DBbBinding->CSC_Complex ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4BPdbPtr = here->BSIM4BPdbBinding->CSC_Complex ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4BPbPtr = here->BSIM4BPbBinding->CSC_Complex ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4BPsbPtr = here->BSIM4BPsbBinding->CSC_Complex ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4SBspPtr = here->BSIM4SBspBinding->CSC_Complex ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4SBbpPtr = here->BSIM4SBbpBinding->CSC_Complex ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4SBbPtr = here->BSIM4SBbBinding->CSC_Complex ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4SBsbPtr = here->BSIM4SBsbBinding->CSC_Complex ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4BdbPtr = here->BSIM4BdbBinding->CSC_Complex ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4BbpPtr = here->BSIM4BbpBinding->CSC_Complex ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4BsbPtr = here->BSIM4BsbBinding->CSC_Complex ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4BbPtr = here->BSIM4BbBinding->CSC_Complex ;

            }
            if (model->BSIM4rdsMod)
            {
                if ((here-> BSIM4dNode != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4DgpPtr = here->BSIM4DgpBinding->CSC_Complex ;

                if ((here-> BSIM4dNode != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4DspPtr = here->BSIM4DspBinding->CSC_Complex ;

                if ((here-> BSIM4dNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4DbpPtr = here->BSIM4DbpBinding->CSC_Complex ;

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4SdpPtr = here->BSIM4SdpBinding->CSC_Complex ;

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4SgpPtr = here->BSIM4SgpBinding->CSC_Complex ;

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4SbpPtr = here->BSIM4SbpBinding->CSC_Complex ;

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
            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4DPbpPtr = here->BSIM4DPbpBinding->CSC ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4GPbpPtr = here->BSIM4GPbpBinding->CSC ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4SPbpPtr = here->BSIM4SPbpBinding->CSC ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4BPdpPtr = here->BSIM4BPdpBinding->CSC ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4BPgpPtr = here->BSIM4BPgpBinding->CSC ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4BPspPtr = here->BSIM4BPspBinding->CSC ;

            if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4BPbpPtr = here->BSIM4BPbpBinding->CSC ;

            if ((here-> BSIM4dNode != 0) && (here-> BSIM4dNode != 0))
                here->BSIM4DdPtr = here->BSIM4DdBinding->CSC ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4GPgpPtr = here->BSIM4GPgpBinding->CSC ;

            if ((here-> BSIM4sNode != 0) && (here-> BSIM4sNode != 0))
                here->BSIM4SsPtr = here->BSIM4SsBinding->CSC ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4DPdpPtr = here->BSIM4DPdpBinding->CSC ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4SPspPtr = here->BSIM4SPspBinding->CSC ;

            if ((here-> BSIM4dNode != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4DdpPtr = here->BSIM4DdpBinding->CSC ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4GPdpPtr = here->BSIM4GPdpBinding->CSC ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4GPspPtr = here->BSIM4GPspBinding->CSC ;

            if ((here-> BSIM4sNode != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4SspPtr = here->BSIM4SspBinding->CSC ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4DPspPtr = here->BSIM4DPspBinding->CSC ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dNode != 0))
                here->BSIM4DPdPtr = here->BSIM4DPdBinding->CSC ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4DPgpPtr = here->BSIM4DPgpBinding->CSC ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4SPgpPtr = here->BSIM4SPgpBinding->CSC ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sNode != 0))
                here->BSIM4SPsPtr = here->BSIM4SPsBinding->CSC ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4SPdpPtr = here->BSIM4SPdpBinding->CSC ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4QqPtr = here->BSIM4QqBinding->CSC ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4bNodePrime != 0))
                here->BSIM4QbpPtr = here->BSIM4QbpBinding->CSC ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4dNodePrime != 0))
                here->BSIM4QdpPtr = here->BSIM4QdpBinding->CSC ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4sNodePrime != 0))
                here->BSIM4QspPtr = here->BSIM4QspBinding->CSC ;

            if ((here-> BSIM4qNode != 0) && (here-> BSIM4gNodePrime != 0))
                here->BSIM4QgpPtr = here->BSIM4QgpBinding->CSC ;

            if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4DPqPtr = here->BSIM4DPqBinding->CSC ;

            if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4SPqPtr = here->BSIM4SPqBinding->CSC ;

            if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4qNode != 0))
                here->BSIM4GPqPtr = here->BSIM4GPqBinding->CSC ;

            if (here->BSIM4rgateMod != 0)
            {
                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodeExt != 0))
                    here->BSIM4GEgePtr = here->BSIM4GEgeBinding->CSC ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4GEgpPtr = here->BSIM4GEgpBinding->CSC ;

                if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodeExt != 0))
                    here->BSIM4GPgePtr = here->BSIM4GPgeBinding->CSC ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4GEdpPtr = here->BSIM4GEdpBinding->CSC ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4GEspPtr = here->BSIM4GEspBinding->CSC ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4GEbpPtr = here->BSIM4GEbpBinding->CSC ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4GMdpPtr = here->BSIM4GMdpBinding->CSC ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4GMgpPtr = here->BSIM4GMgpBinding->CSC ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4GMgmPtr = here->BSIM4GMgmBinding->CSC ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4gNodeExt != 0))
                    here->BSIM4GMgePtr = here->BSIM4GMgeBinding->CSC ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4GMspPtr = here->BSIM4GMspBinding->CSC ;

                if ((here-> BSIM4gNodeMid != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4GMbpPtr = here->BSIM4GMbpBinding->CSC ;

                if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4DPgmPtr = here->BSIM4DPgmBinding->CSC ;

                if ((here-> BSIM4gNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4GPgmPtr = here->BSIM4GPgmBinding->CSC ;

                if ((here-> BSIM4gNodeExt != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4GEgmPtr = here->BSIM4GEgmBinding->CSC ;

                if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4SPgmPtr = here->BSIM4SPgmBinding->CSC ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4gNodeMid != 0))
                    here->BSIM4BPgmPtr = here->BSIM4BPgmBinding->CSC ;

            }
            if ((here->BSIM4rbodyMod == 1) || (here->BSIM4rbodyMod == 2))
            {
                if ((here-> BSIM4dNodePrime != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4DPdbPtr = here->BSIM4DPdbBinding->CSC ;

                if ((here-> BSIM4sNodePrime != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4SPsbPtr = here->BSIM4SPsbBinding->CSC ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4DBdpPtr = here->BSIM4DBdpBinding->CSC ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4DBdbPtr = here->BSIM4DBdbBinding->CSC ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4DBbpPtr = here->BSIM4DBbpBinding->CSC ;

                if ((here-> BSIM4dbNode != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4DBbPtr = here->BSIM4DBbBinding->CSC ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4BPdbPtr = here->BSIM4BPdbBinding->CSC ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4BPbPtr = here->BSIM4BPbBinding->CSC ;

                if ((here-> BSIM4bNodePrime != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4BPsbPtr = here->BSIM4BPsbBinding->CSC ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4SBspPtr = here->BSIM4SBspBinding->CSC ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4SBbpPtr = here->BSIM4SBbpBinding->CSC ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4SBbPtr = here->BSIM4SBbBinding->CSC ;

                if ((here-> BSIM4sbNode != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4SBsbPtr = here->BSIM4SBsbBinding->CSC ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4dbNode != 0))
                    here->BSIM4BdbPtr = here->BSIM4BdbBinding->CSC ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4BbpPtr = here->BSIM4BbpBinding->CSC ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4sbNode != 0))
                    here->BSIM4BsbPtr = here->BSIM4BsbBinding->CSC ;

                if ((here-> BSIM4bNode != 0) && (here-> BSIM4bNode != 0))
                    here->BSIM4BbPtr = here->BSIM4BbBinding->CSC ;

            }
            if (model->BSIM4rdsMod)
            {
                if ((here-> BSIM4dNode != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4DgpPtr = here->BSIM4DgpBinding->CSC ;

                if ((here-> BSIM4dNode != 0) && (here-> BSIM4sNodePrime != 0))
                    here->BSIM4DspPtr = here->BSIM4DspBinding->CSC ;

                if ((here-> BSIM4dNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4DbpPtr = here->BSIM4DbpBinding->CSC ;

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4dNodePrime != 0))
                    here->BSIM4SdpPtr = here->BSIM4SdpBinding->CSC ;

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4gNodePrime != 0))
                    here->BSIM4SgpPtr = here->BSIM4SgpBinding->CSC ;

                if ((here-> BSIM4sNode != 0) && (here-> BSIM4bNodePrime != 0))
                    here->BSIM4SbpPtr = here->BSIM4SbpBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
