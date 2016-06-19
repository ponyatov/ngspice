/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim3v1def.h"
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
BSIM3v1bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v1model *model = (BSIM3v1model *)inModel ;
    BSIM3v1instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM3v1 models */
    for ( ; model != NULL ; model = model->BSIM3v1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v1instances ; here != NULL ; here = here->BSIM3v1nextInstance)
        {
            if ((here-> BSIM3v1dNode != 0) && (here-> BSIM3v1dNode != 0))
            {
                i = here->BSIM3v1DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DdBinding = matched ;
                here->BSIM3v1DdPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1gNode != 0))
            {
                i = here->BSIM3v1GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1GgBinding = matched ;
                here->BSIM3v1GgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNode != 0) && (here-> BSIM3v1sNode != 0))
            {
                i = here->BSIM3v1SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SsBinding = matched ;
                here->BSIM3v1SsPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1bNode != 0))
            {
                i = here->BSIM3v1BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1BbBinding = matched ;
                here->BSIM3v1BbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1dNodePrime != 0))
            {
                i = here->BSIM3v1DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DPdpBinding = matched ;
                here->BSIM3v1DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1sNodePrime != 0))
            {
                i = here->BSIM3v1SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SPspBinding = matched ;
                here->BSIM3v1SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNode != 0) && (here-> BSIM3v1dNodePrime != 0))
            {
                i = here->BSIM3v1DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DdpBinding = matched ;
                here->BSIM3v1DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1bNode != 0))
            {
                i = here->BSIM3v1GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1GbBinding = matched ;
                here->BSIM3v1GbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1dNodePrime != 0))
            {
                i = here->BSIM3v1GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1GdpBinding = matched ;
                here->BSIM3v1GdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1sNodePrime != 0))
            {
                i = here->BSIM3v1GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1GspBinding = matched ;
                here->BSIM3v1GspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNode != 0) && (here-> BSIM3v1sNodePrime != 0))
            {
                i = here->BSIM3v1SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SspBinding = matched ;
                here->BSIM3v1SspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1dNodePrime != 0))
            {
                i = here->BSIM3v1BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1BdpBinding = matched ;
                here->BSIM3v1BdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1sNodePrime != 0))
            {
                i = here->BSIM3v1BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1BspBinding = matched ;
                here->BSIM3v1BspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1sNodePrime != 0))
            {
                i = here->BSIM3v1DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DPspBinding = matched ;
                here->BSIM3v1DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1dNode != 0))
            {
                i = here->BSIM3v1DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DPdBinding = matched ;
                here->BSIM3v1DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1gNode != 0))
            {
                i = here->BSIM3v1BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1BgBinding = matched ;
                here->BSIM3v1BgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1gNode != 0))
            {
                i = here->BSIM3v1DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DPgBinding = matched ;
                here->BSIM3v1DPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1gNode != 0))
            {
                i = here->BSIM3v1SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SPgBinding = matched ;
                here->BSIM3v1SPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1sNode != 0))
            {
                i = here->BSIM3v1SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SPsBinding = matched ;
                here->BSIM3v1SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1bNode != 0))
            {
                i = here->BSIM3v1DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DPbBinding = matched ;
                here->BSIM3v1DPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1bNode != 0))
            {
                i = here->BSIM3v1SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SPbBinding = matched ;
                here->BSIM3v1SPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1dNodePrime != 0))
            {
                i = here->BSIM3v1SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SPdpBinding = matched ;
                here->BSIM3v1SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1qNode != 0))
            {
                i = here->BSIM3v1QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1QqBinding = matched ;
                here->BSIM3v1QqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1dNodePrime != 0))
            {
                i = here->BSIM3v1QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1QdpBinding = matched ;
                here->BSIM3v1QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1sNodePrime != 0))
            {
                i = here->BSIM3v1QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1QspBinding = matched ;
                here->BSIM3v1QspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1gNode != 0))
            {
                i = here->BSIM3v1QgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1QgBinding = matched ;
                here->BSIM3v1QgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1bNode != 0))
            {
                i = here->BSIM3v1QbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1QbBinding = matched ;
                here->BSIM3v1QbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1qNode != 0))
            {
                i = here->BSIM3v1DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1DPqBinding = matched ;
                here->BSIM3v1DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1qNode != 0))
            {
                i = here->BSIM3v1SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1SPqBinding = matched ;
                here->BSIM3v1SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1qNode != 0))
            {
                i = here->BSIM3v1GqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1GqBinding = matched ;
                here->BSIM3v1GqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1qNode != 0))
            {
                i = here->BSIM3v1BqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v1BqBinding = matched ;
                here->BSIM3v1BqPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
BSIM3v1bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v1model *model = (BSIM3v1model *)inModel ;
    BSIM3v1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3v1 models */
    for ( ; model != NULL ; model = model->BSIM3v1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v1instances ; here != NULL ; here = here->BSIM3v1nextInstance)
        {
            if ((here-> BSIM3v1dNode != 0) && (here-> BSIM3v1dNode != 0))
                here->BSIM3v1DdPtr = here->BSIM3v1DdBinding->CSC_Complex ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1GgPtr = here->BSIM3v1GgBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNode != 0) && (here-> BSIM3v1sNode != 0))
                here->BSIM3v1SsPtr = here->BSIM3v1SsBinding->CSC_Complex ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1BbPtr = here->BSIM3v1BbBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1DPdpPtr = here->BSIM3v1DPdpBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1SPspPtr = here->BSIM3v1SPspBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1DdpPtr = here->BSIM3v1DdpBinding->CSC_Complex ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1GbPtr = here->BSIM3v1GbBinding->CSC_Complex ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1GdpPtr = here->BSIM3v1GdpBinding->CSC_Complex ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1GspPtr = here->BSIM3v1GspBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1SspPtr = here->BSIM3v1SspBinding->CSC_Complex ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1BdpPtr = here->BSIM3v1BdpBinding->CSC_Complex ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1BspPtr = here->BSIM3v1BspBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1DPspPtr = here->BSIM3v1DPspBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1dNode != 0))
                here->BSIM3v1DPdPtr = here->BSIM3v1DPdBinding->CSC_Complex ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1BgPtr = here->BSIM3v1BgBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1DPgPtr = here->BSIM3v1DPgBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1SPgPtr = here->BSIM3v1SPgBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1sNode != 0))
                here->BSIM3v1SPsPtr = here->BSIM3v1SPsBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1DPbPtr = here->BSIM3v1DPbBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1SPbPtr = here->BSIM3v1SPbBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1SPdpPtr = here->BSIM3v1SPdpBinding->CSC_Complex ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1QqPtr = here->BSIM3v1QqBinding->CSC_Complex ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1QdpPtr = here->BSIM3v1QdpBinding->CSC_Complex ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1QspPtr = here->BSIM3v1QspBinding->CSC_Complex ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1QgPtr = here->BSIM3v1QgBinding->CSC_Complex ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1QbPtr = here->BSIM3v1QbBinding->CSC_Complex ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1DPqPtr = here->BSIM3v1DPqBinding->CSC_Complex ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1SPqPtr = here->BSIM3v1SPqBinding->CSC_Complex ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1GqPtr = here->BSIM3v1GqBinding->CSC_Complex ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1BqPtr = here->BSIM3v1BqBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
BSIM3v1bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v1model *model = (BSIM3v1model *)inModel ;
    BSIM3v1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3v1 models */
    for ( ; model != NULL ; model = model->BSIM3v1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v1instances ; here != NULL ; here = here->BSIM3v1nextInstance)
        {
            if ((here-> BSIM3v1dNode != 0) && (here-> BSIM3v1dNode != 0))
                here->BSIM3v1DdPtr = here->BSIM3v1DdBinding->CSC ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1GgPtr = here->BSIM3v1GgBinding->CSC ;

            if ((here-> BSIM3v1sNode != 0) && (here-> BSIM3v1sNode != 0))
                here->BSIM3v1SsPtr = here->BSIM3v1SsBinding->CSC ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1BbPtr = here->BSIM3v1BbBinding->CSC ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1DPdpPtr = here->BSIM3v1DPdpBinding->CSC ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1SPspPtr = here->BSIM3v1SPspBinding->CSC ;

            if ((here-> BSIM3v1dNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1DdpPtr = here->BSIM3v1DdpBinding->CSC ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1GbPtr = here->BSIM3v1GbBinding->CSC ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1GdpPtr = here->BSIM3v1GdpBinding->CSC ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1GspPtr = here->BSIM3v1GspBinding->CSC ;

            if ((here-> BSIM3v1sNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1SspPtr = here->BSIM3v1SspBinding->CSC ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1BdpPtr = here->BSIM3v1BdpBinding->CSC ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1BspPtr = here->BSIM3v1BspBinding->CSC ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1DPspPtr = here->BSIM3v1DPspBinding->CSC ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1dNode != 0))
                here->BSIM3v1DPdPtr = here->BSIM3v1DPdBinding->CSC ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1BgPtr = here->BSIM3v1BgBinding->CSC ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1DPgPtr = here->BSIM3v1DPgBinding->CSC ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1SPgPtr = here->BSIM3v1SPgBinding->CSC ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1sNode != 0))
                here->BSIM3v1SPsPtr = here->BSIM3v1SPsBinding->CSC ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1DPbPtr = here->BSIM3v1DPbBinding->CSC ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1SPbPtr = here->BSIM3v1SPbBinding->CSC ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1SPdpPtr = here->BSIM3v1SPdpBinding->CSC ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1QqPtr = here->BSIM3v1QqBinding->CSC ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1dNodePrime != 0))
                here->BSIM3v1QdpPtr = here->BSIM3v1QdpBinding->CSC ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1sNodePrime != 0))
                here->BSIM3v1QspPtr = here->BSIM3v1QspBinding->CSC ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1gNode != 0))
                here->BSIM3v1QgPtr = here->BSIM3v1QgBinding->CSC ;

            if ((here-> BSIM3v1qNode != 0) && (here-> BSIM3v1bNode != 0))
                here->BSIM3v1QbPtr = here->BSIM3v1QbBinding->CSC ;

            if ((here-> BSIM3v1dNodePrime != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1DPqPtr = here->BSIM3v1DPqBinding->CSC ;

            if ((here-> BSIM3v1sNodePrime != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1SPqPtr = here->BSIM3v1SPqBinding->CSC ;

            if ((here-> BSIM3v1gNode != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1GqPtr = here->BSIM3v1GqBinding->CSC ;

            if ((here-> BSIM3v1bNode != 0) && (here-> BSIM3v1qNode != 0))
                here->BSIM3v1BqPtr = here->BSIM3v1BqBinding->CSC ;

        }
    }

    return (OK) ;
}
