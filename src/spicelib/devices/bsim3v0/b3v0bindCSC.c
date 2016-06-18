/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim3v0def.h"
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
BSIM3v0bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v0model *model = (BSIM3v0model *)inModel ;
    BSIM3v0instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM3v0 models */
    for ( ; model != NULL ; model = model->BSIM3v0nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v0instances ; here != NULL ; here = here->BSIM3v0nextInstance)
        {
            if ((here-> BSIM3v0dNode != 0) && (here-> BSIM3v0dNode != 0))
            {
                i = here->BSIM3v0DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DdBinding = matched ;
                here->BSIM3v0DdPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0gNode != 0))
            {
                i = here->BSIM3v0GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0GgBinding = matched ;
                here->BSIM3v0GgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNode != 0) && (here-> BSIM3v0sNode != 0))
            {
                i = here->BSIM3v0SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SsBinding = matched ;
                here->BSIM3v0SsPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0bNode != 0))
            {
                i = here->BSIM3v0BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0BbBinding = matched ;
                here->BSIM3v0BbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0dNodePrime != 0))
            {
                i = here->BSIM3v0DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DPdpBinding = matched ;
                here->BSIM3v0DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0sNodePrime != 0))
            {
                i = here->BSIM3v0SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SPspBinding = matched ;
                here->BSIM3v0SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNode != 0) && (here-> BSIM3v0dNodePrime != 0))
            {
                i = here->BSIM3v0DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DdpBinding = matched ;
                here->BSIM3v0DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0bNode != 0))
            {
                i = here->BSIM3v0GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0GbBinding = matched ;
                here->BSIM3v0GbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0dNodePrime != 0))
            {
                i = here->BSIM3v0GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0GdpBinding = matched ;
                here->BSIM3v0GdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0sNodePrime != 0))
            {
                i = here->BSIM3v0GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0GspBinding = matched ;
                here->BSIM3v0GspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNode != 0) && (here-> BSIM3v0sNodePrime != 0))
            {
                i = here->BSIM3v0SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SspBinding = matched ;
                here->BSIM3v0SspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0dNodePrime != 0))
            {
                i = here->BSIM3v0BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0BdpBinding = matched ;
                here->BSIM3v0BdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0sNodePrime != 0))
            {
                i = here->BSIM3v0BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0BspBinding = matched ;
                here->BSIM3v0BspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0sNodePrime != 0))
            {
                i = here->BSIM3v0DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DPspBinding = matched ;
                here->BSIM3v0DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0dNode != 0))
            {
                i = here->BSIM3v0DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DPdBinding = matched ;
                here->BSIM3v0DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0gNode != 0))
            {
                i = here->BSIM3v0BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0BgBinding = matched ;
                here->BSIM3v0BgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0gNode != 0))
            {
                i = here->BSIM3v0DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DPgBinding = matched ;
                here->BSIM3v0DPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0gNode != 0))
            {
                i = here->BSIM3v0SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SPgBinding = matched ;
                here->BSIM3v0SPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0sNode != 0))
            {
                i = here->BSIM3v0SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SPsBinding = matched ;
                here->BSIM3v0SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0bNode != 0))
            {
                i = here->BSIM3v0DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DPbBinding = matched ;
                here->BSIM3v0DPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0bNode != 0))
            {
                i = here->BSIM3v0SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SPbBinding = matched ;
                here->BSIM3v0SPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0dNodePrime != 0))
            {
                i = here->BSIM3v0SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SPdpBinding = matched ;
                here->BSIM3v0SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0qNode != 0))
            {
                i = here->BSIM3v0QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0QqBinding = matched ;
                here->BSIM3v0QqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0dNodePrime != 0))
            {
                i = here->BSIM3v0QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0QdpBinding = matched ;
                here->BSIM3v0QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0sNodePrime != 0))
            {
                i = here->BSIM3v0QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0QspBinding = matched ;
                here->BSIM3v0QspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0gNode != 0))
            {
                i = here->BSIM3v0QgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0QgBinding = matched ;
                here->BSIM3v0QgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0bNode != 0))
            {
                i = here->BSIM3v0QbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0QbBinding = matched ;
                here->BSIM3v0QbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0qNode != 0))
            {
                i = here->BSIM3v0DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0DPqBinding = matched ;
                here->BSIM3v0DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0qNode != 0))
            {
                i = here->BSIM3v0SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0SPqBinding = matched ;
                here->BSIM3v0SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0qNode != 0))
            {
                i = here->BSIM3v0GqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0GqBinding = matched ;
                here->BSIM3v0GqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0qNode != 0))
            {
                i = here->BSIM3v0BqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v0BqBinding = matched ;
                here->BSIM3v0BqPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
BSIM3v0bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v0model *model = (BSIM3v0model *)inModel ;
    BSIM3v0instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3v0 models */
    for ( ; model != NULL ; model = model->BSIM3v0nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v0instances ; here != NULL ; here = here->BSIM3v0nextInstance)
        {
            if ((here-> BSIM3v0dNode != 0) && (here-> BSIM3v0dNode != 0))
                here->BSIM3v0DdPtr = here->BSIM3v0DdBinding->CSC_Complex ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0GgPtr = here->BSIM3v0GgBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNode != 0) && (here-> BSIM3v0sNode != 0))
                here->BSIM3v0SsPtr = here->BSIM3v0SsBinding->CSC_Complex ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0BbPtr = here->BSIM3v0BbBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0DPdpPtr = here->BSIM3v0DPdpBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0SPspPtr = here->BSIM3v0SPspBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0DdpPtr = here->BSIM3v0DdpBinding->CSC_Complex ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0GbPtr = here->BSIM3v0GbBinding->CSC_Complex ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0GdpPtr = here->BSIM3v0GdpBinding->CSC_Complex ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0GspPtr = here->BSIM3v0GspBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0SspPtr = here->BSIM3v0SspBinding->CSC_Complex ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0BdpPtr = here->BSIM3v0BdpBinding->CSC_Complex ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0BspPtr = here->BSIM3v0BspBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0DPspPtr = here->BSIM3v0DPspBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0dNode != 0))
                here->BSIM3v0DPdPtr = here->BSIM3v0DPdBinding->CSC_Complex ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0BgPtr = here->BSIM3v0BgBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0DPgPtr = here->BSIM3v0DPgBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0SPgPtr = here->BSIM3v0SPgBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0sNode != 0))
                here->BSIM3v0SPsPtr = here->BSIM3v0SPsBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0DPbPtr = here->BSIM3v0DPbBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0SPbPtr = here->BSIM3v0SPbBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0SPdpPtr = here->BSIM3v0SPdpBinding->CSC_Complex ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0QqPtr = here->BSIM3v0QqBinding->CSC_Complex ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0QdpPtr = here->BSIM3v0QdpBinding->CSC_Complex ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0QspPtr = here->BSIM3v0QspBinding->CSC_Complex ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0QgPtr = here->BSIM3v0QgBinding->CSC_Complex ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0QbPtr = here->BSIM3v0QbBinding->CSC_Complex ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0DPqPtr = here->BSIM3v0DPqBinding->CSC_Complex ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0SPqPtr = here->BSIM3v0SPqBinding->CSC_Complex ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0GqPtr = here->BSIM3v0GqBinding->CSC_Complex ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0BqPtr = here->BSIM3v0BqBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
BSIM3v0bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v0model *model = (BSIM3v0model *)inModel ;
    BSIM3v0instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3v0 models */
    for ( ; model != NULL ; model = model->BSIM3v0nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v0instances ; here != NULL ; here = here->BSIM3v0nextInstance)
        {
            if ((here-> BSIM3v0dNode != 0) && (here-> BSIM3v0dNode != 0))
                here->BSIM3v0DdPtr = here->BSIM3v0DdBinding->CSC ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0GgPtr = here->BSIM3v0GgBinding->CSC ;

            if ((here-> BSIM3v0sNode != 0) && (here-> BSIM3v0sNode != 0))
                here->BSIM3v0SsPtr = here->BSIM3v0SsBinding->CSC ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0BbPtr = here->BSIM3v0BbBinding->CSC ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0DPdpPtr = here->BSIM3v0DPdpBinding->CSC ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0SPspPtr = here->BSIM3v0SPspBinding->CSC ;

            if ((here-> BSIM3v0dNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0DdpPtr = here->BSIM3v0DdpBinding->CSC ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0GbPtr = here->BSIM3v0GbBinding->CSC ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0GdpPtr = here->BSIM3v0GdpBinding->CSC ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0GspPtr = here->BSIM3v0GspBinding->CSC ;

            if ((here-> BSIM3v0sNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0SspPtr = here->BSIM3v0SspBinding->CSC ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0BdpPtr = here->BSIM3v0BdpBinding->CSC ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0BspPtr = here->BSIM3v0BspBinding->CSC ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0DPspPtr = here->BSIM3v0DPspBinding->CSC ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0dNode != 0))
                here->BSIM3v0DPdPtr = here->BSIM3v0DPdBinding->CSC ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0BgPtr = here->BSIM3v0BgBinding->CSC ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0DPgPtr = here->BSIM3v0DPgBinding->CSC ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0SPgPtr = here->BSIM3v0SPgBinding->CSC ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0sNode != 0))
                here->BSIM3v0SPsPtr = here->BSIM3v0SPsBinding->CSC ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0DPbPtr = here->BSIM3v0DPbBinding->CSC ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0SPbPtr = here->BSIM3v0SPbBinding->CSC ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0SPdpPtr = here->BSIM3v0SPdpBinding->CSC ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0QqPtr = here->BSIM3v0QqBinding->CSC ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0dNodePrime != 0))
                here->BSIM3v0QdpPtr = here->BSIM3v0QdpBinding->CSC ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0sNodePrime != 0))
                here->BSIM3v0QspPtr = here->BSIM3v0QspBinding->CSC ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0gNode != 0))
                here->BSIM3v0QgPtr = here->BSIM3v0QgBinding->CSC ;

            if ((here-> BSIM3v0qNode != 0) && (here-> BSIM3v0bNode != 0))
                here->BSIM3v0QbPtr = here->BSIM3v0QbBinding->CSC ;

            if ((here-> BSIM3v0dNodePrime != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0DPqPtr = here->BSIM3v0DPqBinding->CSC ;

            if ((here-> BSIM3v0sNodePrime != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0SPqPtr = here->BSIM3v0SPqBinding->CSC ;

            if ((here-> BSIM3v0gNode != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0GqPtr = here->BSIM3v0GqBinding->CSC ;

            if ((here-> BSIM3v0bNode != 0) && (here-> BSIM3v0qNode != 0))
                here->BSIM3v0BqPtr = here->BSIM3v0BqBinding->CSC ;

        }
    }

    return (OK) ;
}
