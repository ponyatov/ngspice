/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim3v32def.h"
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
BSIM3v32bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v32model *model = (BSIM3v32model *)inModel ;
    BSIM3v32instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM3v32 models */
    for ( ; model != NULL ; model = model->BSIM3v32nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v32instances ; here != NULL ; here = here->BSIM3v32nextInstance)
        {
            if ((here-> BSIM3v32dNode != 0) && (here-> BSIM3v32dNode != 0))
            {
                i = here->BSIM3v32DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DdBinding = matched ;
                here->BSIM3v32DdPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32gNode != 0))
            {
                i = here->BSIM3v32GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32GgBinding = matched ;
                here->BSIM3v32GgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNode != 0) && (here-> BSIM3v32sNode != 0))
            {
                i = here->BSIM3v32SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SsBinding = matched ;
                here->BSIM3v32SsPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32bNode != 0))
            {
                i = here->BSIM3v32BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32BbBinding = matched ;
                here->BSIM3v32BbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32dNodePrime != 0))
            {
                i = here->BSIM3v32DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DPdpBinding = matched ;
                here->BSIM3v32DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32sNodePrime != 0))
            {
                i = here->BSIM3v32SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SPspBinding = matched ;
                here->BSIM3v32SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNode != 0) && (here-> BSIM3v32dNodePrime != 0))
            {
                i = here->BSIM3v32DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DdpBinding = matched ;
                here->BSIM3v32DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32bNode != 0))
            {
                i = here->BSIM3v32GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32GbBinding = matched ;
                here->BSIM3v32GbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32dNodePrime != 0))
            {
                i = here->BSIM3v32GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32GdpBinding = matched ;
                here->BSIM3v32GdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32sNodePrime != 0))
            {
                i = here->BSIM3v32GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32GspBinding = matched ;
                here->BSIM3v32GspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNode != 0) && (here-> BSIM3v32sNodePrime != 0))
            {
                i = here->BSIM3v32SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SspBinding = matched ;
                here->BSIM3v32SspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32dNodePrime != 0))
            {
                i = here->BSIM3v32BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32BdpBinding = matched ;
                here->BSIM3v32BdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32sNodePrime != 0))
            {
                i = here->BSIM3v32BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32BspBinding = matched ;
                here->BSIM3v32BspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32sNodePrime != 0))
            {
                i = here->BSIM3v32DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DPspBinding = matched ;
                here->BSIM3v32DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32dNode != 0))
            {
                i = here->BSIM3v32DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DPdBinding = matched ;
                here->BSIM3v32DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32gNode != 0))
            {
                i = here->BSIM3v32BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32BgBinding = matched ;
                here->BSIM3v32BgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32gNode != 0))
            {
                i = here->BSIM3v32DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DPgBinding = matched ;
                here->BSIM3v32DPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32gNode != 0))
            {
                i = here->BSIM3v32SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SPgBinding = matched ;
                here->BSIM3v32SPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32sNode != 0))
            {
                i = here->BSIM3v32SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SPsBinding = matched ;
                here->BSIM3v32SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32bNode != 0))
            {
                i = here->BSIM3v32DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DPbBinding = matched ;
                here->BSIM3v32DPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32bNode != 0))
            {
                i = here->BSIM3v32SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SPbBinding = matched ;
                here->BSIM3v32SPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32dNodePrime != 0))
            {
                i = here->BSIM3v32SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SPdpBinding = matched ;
                here->BSIM3v32SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32qNode != 0))
            {
                i = here->BSIM3v32QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32QqBinding = matched ;
                here->BSIM3v32QqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32dNodePrime != 0))
            {
                i = here->BSIM3v32QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32QdpBinding = matched ;
                here->BSIM3v32QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32sNodePrime != 0))
            {
                i = here->BSIM3v32QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32QspBinding = matched ;
                here->BSIM3v32QspPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32gNode != 0))
            {
                i = here->BSIM3v32QgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32QgBinding = matched ;
                here->BSIM3v32QgPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32bNode != 0))
            {
                i = here->BSIM3v32QbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32QbBinding = matched ;
                here->BSIM3v32QbPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32qNode != 0))
            {
                i = here->BSIM3v32DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32DPqBinding = matched ;
                here->BSIM3v32DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32qNode != 0))
            {
                i = here->BSIM3v32SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32SPqBinding = matched ;
                here->BSIM3v32SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32qNode != 0))
            {
                i = here->BSIM3v32GqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32GqBinding = matched ;
                here->BSIM3v32GqPtr = matched->CSC ;
            }

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32qNode != 0))
            {
                i = here->BSIM3v32BqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3v32BqBinding = matched ;
                here->BSIM3v32BqPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
BSIM3v32bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v32model *model = (BSIM3v32model *)inModel ;
    BSIM3v32instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3v32 models */
    for ( ; model != NULL ; model = model->BSIM3v32nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v32instances ; here != NULL ; here = here->BSIM3v32nextInstance)
        {
            if ((here-> BSIM3v32dNode != 0) && (here-> BSIM3v32dNode != 0))
                here->BSIM3v32DdPtr = here->BSIM3v32DdBinding->CSC_Complex ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32GgPtr = here->BSIM3v32GgBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNode != 0) && (here-> BSIM3v32sNode != 0))
                here->BSIM3v32SsPtr = here->BSIM3v32SsBinding->CSC_Complex ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32BbPtr = here->BSIM3v32BbBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32DPdpPtr = here->BSIM3v32DPdpBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32SPspPtr = here->BSIM3v32SPspBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32DdpPtr = here->BSIM3v32DdpBinding->CSC_Complex ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32GbPtr = here->BSIM3v32GbBinding->CSC_Complex ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32GdpPtr = here->BSIM3v32GdpBinding->CSC_Complex ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32GspPtr = here->BSIM3v32GspBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32SspPtr = here->BSIM3v32SspBinding->CSC_Complex ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32BdpPtr = here->BSIM3v32BdpBinding->CSC_Complex ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32BspPtr = here->BSIM3v32BspBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32DPspPtr = here->BSIM3v32DPspBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32dNode != 0))
                here->BSIM3v32DPdPtr = here->BSIM3v32DPdBinding->CSC_Complex ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32BgPtr = here->BSIM3v32BgBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32DPgPtr = here->BSIM3v32DPgBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32SPgPtr = here->BSIM3v32SPgBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32sNode != 0))
                here->BSIM3v32SPsPtr = here->BSIM3v32SPsBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32DPbPtr = here->BSIM3v32DPbBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32SPbPtr = here->BSIM3v32SPbBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32SPdpPtr = here->BSIM3v32SPdpBinding->CSC_Complex ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32QqPtr = here->BSIM3v32QqBinding->CSC_Complex ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32QdpPtr = here->BSIM3v32QdpBinding->CSC_Complex ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32QspPtr = here->BSIM3v32QspBinding->CSC_Complex ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32QgPtr = here->BSIM3v32QgBinding->CSC_Complex ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32QbPtr = here->BSIM3v32QbBinding->CSC_Complex ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32DPqPtr = here->BSIM3v32DPqBinding->CSC_Complex ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32SPqPtr = here->BSIM3v32SPqBinding->CSC_Complex ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32GqPtr = here->BSIM3v32GqBinding->CSC_Complex ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32BqPtr = here->BSIM3v32BqBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
BSIM3v32bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3v32model *model = (BSIM3v32model *)inModel ;
    BSIM3v32instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3v32 models */
    for ( ; model != NULL ; model = model->BSIM3v32nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3v32instances ; here != NULL ; here = here->BSIM3v32nextInstance)
        {
            if ((here-> BSIM3v32dNode != 0) && (here-> BSIM3v32dNode != 0))
                here->BSIM3v32DdPtr = here->BSIM3v32DdBinding->CSC ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32GgPtr = here->BSIM3v32GgBinding->CSC ;

            if ((here-> BSIM3v32sNode != 0) && (here-> BSIM3v32sNode != 0))
                here->BSIM3v32SsPtr = here->BSIM3v32SsBinding->CSC ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32BbPtr = here->BSIM3v32BbBinding->CSC ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32DPdpPtr = here->BSIM3v32DPdpBinding->CSC ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32SPspPtr = here->BSIM3v32SPspBinding->CSC ;

            if ((here-> BSIM3v32dNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32DdpPtr = here->BSIM3v32DdpBinding->CSC ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32GbPtr = here->BSIM3v32GbBinding->CSC ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32GdpPtr = here->BSIM3v32GdpBinding->CSC ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32GspPtr = here->BSIM3v32GspBinding->CSC ;

            if ((here-> BSIM3v32sNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32SspPtr = here->BSIM3v32SspBinding->CSC ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32BdpPtr = here->BSIM3v32BdpBinding->CSC ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32BspPtr = here->BSIM3v32BspBinding->CSC ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32DPspPtr = here->BSIM3v32DPspBinding->CSC ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32dNode != 0))
                here->BSIM3v32DPdPtr = here->BSIM3v32DPdBinding->CSC ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32BgPtr = here->BSIM3v32BgBinding->CSC ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32DPgPtr = here->BSIM3v32DPgBinding->CSC ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32SPgPtr = here->BSIM3v32SPgBinding->CSC ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32sNode != 0))
                here->BSIM3v32SPsPtr = here->BSIM3v32SPsBinding->CSC ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32DPbPtr = here->BSIM3v32DPbBinding->CSC ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32SPbPtr = here->BSIM3v32SPbBinding->CSC ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32SPdpPtr = here->BSIM3v32SPdpBinding->CSC ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32QqPtr = here->BSIM3v32QqBinding->CSC ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32dNodePrime != 0))
                here->BSIM3v32QdpPtr = here->BSIM3v32QdpBinding->CSC ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32sNodePrime != 0))
                here->BSIM3v32QspPtr = here->BSIM3v32QspBinding->CSC ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32gNode != 0))
                here->BSIM3v32QgPtr = here->BSIM3v32QgBinding->CSC ;

            if ((here-> BSIM3v32qNode != 0) && (here-> BSIM3v32bNode != 0))
                here->BSIM3v32QbPtr = here->BSIM3v32QbBinding->CSC ;

            if ((here-> BSIM3v32dNodePrime != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32DPqPtr = here->BSIM3v32DPqBinding->CSC ;

            if ((here-> BSIM3v32sNodePrime != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32SPqPtr = here->BSIM3v32SPqBinding->CSC ;

            if ((here-> BSIM3v32gNode != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32GqPtr = here->BSIM3v32GqBinding->CSC ;

            if ((here-> BSIM3v32bNode != 0) && (here-> BSIM3v32qNode != 0))
                here->BSIM3v32BqPtr = here->BSIM3v32BqBinding->CSC ;

        }
    }

    return (OK) ;
}
