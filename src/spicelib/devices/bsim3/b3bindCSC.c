/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim3def.h"
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
BSIM3bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3model *model = (BSIM3model *)inModel ;
    BSIM3instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BSIM3 models */
    for ( ; model != NULL ; model = model->BSIM3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3instances ; here != NULL ; here = here->BSIM3nextInstance)
        {
            if ((here-> BSIM3dNode != 0) && (here-> BSIM3dNode != 0))
            {
                i = here->BSIM3DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DdBinding = matched ;
                here->BSIM3DdPtr = matched->CSC ;
            }

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3gNode != 0))
            {
                i = here->BSIM3GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3GgBinding = matched ;
                here->BSIM3GgPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNode != 0) && (here-> BSIM3sNode != 0))
            {
                i = here->BSIM3SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SsBinding = matched ;
                here->BSIM3SsPtr = matched->CSC ;
            }

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3bNode != 0))
            {
                i = here->BSIM3BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3BbBinding = matched ;
                here->BSIM3BbPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3dNodePrime != 0))
            {
                i = here->BSIM3DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DPdpBinding = matched ;
                here->BSIM3DPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3sNodePrime != 0))
            {
                i = here->BSIM3SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SPspBinding = matched ;
                here->BSIM3SPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNode != 0) && (here-> BSIM3dNodePrime != 0))
            {
                i = here->BSIM3DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DdpBinding = matched ;
                here->BSIM3DdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3bNode != 0))
            {
                i = here->BSIM3GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3GbBinding = matched ;
                here->BSIM3GbPtr = matched->CSC ;
            }

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3dNodePrime != 0))
            {
                i = here->BSIM3GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3GdpBinding = matched ;
                here->BSIM3GdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3sNodePrime != 0))
            {
                i = here->BSIM3GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3GspBinding = matched ;
                here->BSIM3GspPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNode != 0) && (here-> BSIM3sNodePrime != 0))
            {
                i = here->BSIM3SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SspBinding = matched ;
                here->BSIM3SspPtr = matched->CSC ;
            }

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3dNodePrime != 0))
            {
                i = here->BSIM3BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3BdpBinding = matched ;
                here->BSIM3BdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3sNodePrime != 0))
            {
                i = here->BSIM3BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3BspBinding = matched ;
                here->BSIM3BspPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3sNodePrime != 0))
            {
                i = here->BSIM3DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DPspBinding = matched ;
                here->BSIM3DPspPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3dNode != 0))
            {
                i = here->BSIM3DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DPdBinding = matched ;
                here->BSIM3DPdPtr = matched->CSC ;
            }

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3gNode != 0))
            {
                i = here->BSIM3BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3BgBinding = matched ;
                here->BSIM3BgPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3gNode != 0))
            {
                i = here->BSIM3DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DPgBinding = matched ;
                here->BSIM3DPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3gNode != 0))
            {
                i = here->BSIM3SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SPgBinding = matched ;
                here->BSIM3SPgPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3sNode != 0))
            {
                i = here->BSIM3SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SPsBinding = matched ;
                here->BSIM3SPsPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3bNode != 0))
            {
                i = here->BSIM3DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DPbBinding = matched ;
                here->BSIM3DPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3bNode != 0))
            {
                i = here->BSIM3SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SPbBinding = matched ;
                here->BSIM3SPbPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3dNodePrime != 0))
            {
                i = here->BSIM3SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SPdpBinding = matched ;
                here->BSIM3SPdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3qNode != 0))
            {
                i = here->BSIM3QqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3QqBinding = matched ;
                here->BSIM3QqPtr = matched->CSC ;
            }

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3dNodePrime != 0))
            {
                i = here->BSIM3QdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3QdpBinding = matched ;
                here->BSIM3QdpPtr = matched->CSC ;
            }

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3gNode != 0))
            {
                i = here->BSIM3QgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3QgBinding = matched ;
                here->BSIM3QgPtr = matched->CSC ;
            }

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3sNodePrime != 0))
            {
                i = here->BSIM3QspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3QspBinding = matched ;
                here->BSIM3QspPtr = matched->CSC ;
            }

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3bNode != 0))
            {
                i = here->BSIM3QbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3QbBinding = matched ;
                here->BSIM3QbPtr = matched->CSC ;
            }

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3qNode != 0))
            {
                i = here->BSIM3DPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3DPqBinding = matched ;
                here->BSIM3DPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3qNode != 0))
            {
                i = here->BSIM3GqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3GqBinding = matched ;
                here->BSIM3GqPtr = matched->CSC ;
            }

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3qNode != 0))
            {
                i = here->BSIM3SPqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3SPqBinding = matched ;
                here->BSIM3SPqPtr = matched->CSC ;
            }

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3qNode != 0))
            {
                i = here->BSIM3BqPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BSIM3BqBinding = matched ;
                here->BSIM3BqPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
BSIM3bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3model *model = (BSIM3model *)inModel ;
    BSIM3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3 models */
    for ( ; model != NULL ; model = model->BSIM3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3instances ; here != NULL ; here = here->BSIM3nextInstance)
        {
            if ((here-> BSIM3dNode != 0) && (here-> BSIM3dNode != 0))
                here->BSIM3DdPtr = here->BSIM3DdBinding->CSC_Complex ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3GgPtr = here->BSIM3GgBinding->CSC_Complex ;

            if ((here-> BSIM3sNode != 0) && (here-> BSIM3sNode != 0))
                here->BSIM3SsPtr = here->BSIM3SsBinding->CSC_Complex ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3BbPtr = here->BSIM3BbBinding->CSC_Complex ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3DPdpPtr = here->BSIM3DPdpBinding->CSC_Complex ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3SPspPtr = here->BSIM3SPspBinding->CSC_Complex ;

            if ((here-> BSIM3dNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3DdpPtr = here->BSIM3DdpBinding->CSC_Complex ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3GbPtr = here->BSIM3GbBinding->CSC_Complex ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3GdpPtr = here->BSIM3GdpBinding->CSC_Complex ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3GspPtr = here->BSIM3GspBinding->CSC_Complex ;

            if ((here-> BSIM3sNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3SspPtr = here->BSIM3SspBinding->CSC_Complex ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3BdpPtr = here->BSIM3BdpBinding->CSC_Complex ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3BspPtr = here->BSIM3BspBinding->CSC_Complex ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3DPspPtr = here->BSIM3DPspBinding->CSC_Complex ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3dNode != 0))
                here->BSIM3DPdPtr = here->BSIM3DPdBinding->CSC_Complex ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3BgPtr = here->BSIM3BgBinding->CSC_Complex ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3DPgPtr = here->BSIM3DPgBinding->CSC_Complex ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3SPgPtr = here->BSIM3SPgBinding->CSC_Complex ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3sNode != 0))
                here->BSIM3SPsPtr = here->BSIM3SPsBinding->CSC_Complex ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3DPbPtr = here->BSIM3DPbBinding->CSC_Complex ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3SPbPtr = here->BSIM3SPbBinding->CSC_Complex ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3SPdpPtr = here->BSIM3SPdpBinding->CSC_Complex ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3QqPtr = here->BSIM3QqBinding->CSC_Complex ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3QdpPtr = here->BSIM3QdpBinding->CSC_Complex ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3QgPtr = here->BSIM3QgBinding->CSC_Complex ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3QspPtr = here->BSIM3QspBinding->CSC_Complex ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3QbPtr = here->BSIM3QbBinding->CSC_Complex ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3DPqPtr = here->BSIM3DPqBinding->CSC_Complex ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3GqPtr = here->BSIM3GqBinding->CSC_Complex ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3SPqPtr = here->BSIM3SPqBinding->CSC_Complex ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3BqPtr = here->BSIM3BqBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
BSIM3bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BSIM3model *model = (BSIM3model *)inModel ;
    BSIM3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BSIM3 models */
    for ( ; model != NULL ; model = model->BSIM3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BSIM3instances ; here != NULL ; here = here->BSIM3nextInstance)
        {
            if ((here-> BSIM3dNode != 0) && (here-> BSIM3dNode != 0))
                here->BSIM3DdPtr = here->BSIM3DdBinding->CSC ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3GgPtr = here->BSIM3GgBinding->CSC ;

            if ((here-> BSIM3sNode != 0) && (here-> BSIM3sNode != 0))
                here->BSIM3SsPtr = here->BSIM3SsBinding->CSC ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3BbPtr = here->BSIM3BbBinding->CSC ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3DPdpPtr = here->BSIM3DPdpBinding->CSC ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3SPspPtr = here->BSIM3SPspBinding->CSC ;

            if ((here-> BSIM3dNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3DdpPtr = here->BSIM3DdpBinding->CSC ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3GbPtr = here->BSIM3GbBinding->CSC ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3GdpPtr = here->BSIM3GdpBinding->CSC ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3GspPtr = here->BSIM3GspBinding->CSC ;

            if ((here-> BSIM3sNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3SspPtr = here->BSIM3SspBinding->CSC ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3BdpPtr = here->BSIM3BdpBinding->CSC ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3BspPtr = here->BSIM3BspBinding->CSC ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3DPspPtr = here->BSIM3DPspBinding->CSC ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3dNode != 0))
                here->BSIM3DPdPtr = here->BSIM3DPdBinding->CSC ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3BgPtr = here->BSIM3BgBinding->CSC ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3DPgPtr = here->BSIM3DPgBinding->CSC ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3SPgPtr = here->BSIM3SPgBinding->CSC ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3sNode != 0))
                here->BSIM3SPsPtr = here->BSIM3SPsBinding->CSC ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3DPbPtr = here->BSIM3DPbBinding->CSC ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3SPbPtr = here->BSIM3SPbBinding->CSC ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3SPdpPtr = here->BSIM3SPdpBinding->CSC ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3QqPtr = here->BSIM3QqBinding->CSC ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3dNodePrime != 0))
                here->BSIM3QdpPtr = here->BSIM3QdpBinding->CSC ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3gNode != 0))
                here->BSIM3QgPtr = here->BSIM3QgBinding->CSC ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3sNodePrime != 0))
                here->BSIM3QspPtr = here->BSIM3QspBinding->CSC ;

            if ((here-> BSIM3qNode != 0) && (here-> BSIM3bNode != 0))
                here->BSIM3QbPtr = here->BSIM3QbBinding->CSC ;

            if ((here-> BSIM3dNodePrime != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3DPqPtr = here->BSIM3DPqBinding->CSC ;

            if ((here-> BSIM3gNode != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3GqPtr = here->BSIM3GqBinding->CSC ;

            if ((here-> BSIM3sNodePrime != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3SPqPtr = here->BSIM3SPqBinding->CSC ;

            if ((here-> BSIM3bNode != 0) && (here-> BSIM3qNode != 0))
                here->BSIM3BqPtr = here->BSIM3BqBinding->CSC ;

        }
    }

    return (OK) ;
}
