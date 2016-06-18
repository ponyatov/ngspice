/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos1defs.h"
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
MOS1bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS1model *model = (MOS1model *)inModel ;
    MOS1instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS1 models */
    for ( ; model != NULL ; model = model->MOS1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS1instances ; here != NULL ; here = here->MOS1nextInstance)
        {
            if ((here->MOS1dNode != 0) && (here->MOS1dNode != 0))
            {
                i = here->MOS1DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DdBinding = matched ;
                here->MOS1DdPtr = matched->CSC ;
            }

            if ((here->MOS1gNode != 0) && (here->MOS1gNode != 0))
            {
                i = here->MOS1GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1GgBinding = matched ;
                here->MOS1GgPtr = matched->CSC ;
            }

            if ((here->MOS1sNode != 0) && (here->MOS1sNode != 0))
            {
                i = here->MOS1SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SsBinding = matched ;
                here->MOS1SsPtr = matched->CSC ;
            }

            if ((here->MOS1bNode != 0) && (here->MOS1bNode != 0))
            {
                i = here->MOS1BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1BbBinding = matched ;
                here->MOS1BbPtr = matched->CSC ;
            }

            if ((here->MOS1dNodePrime != 0) && (here->MOS1dNodePrime != 0))
            {
                i = here->MOS1DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DPdpBinding = matched ;
                here->MOS1DPdpPtr = matched->CSC ;
            }

            if ((here->MOS1sNodePrime != 0) && (here->MOS1sNodePrime != 0))
            {
                i = here->MOS1SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SPspBinding = matched ;
                here->MOS1SPspPtr = matched->CSC ;
            }

            if ((here->MOS1dNode != 0) && (here->MOS1dNodePrime != 0))
            {
                i = here->MOS1DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DdpBinding = matched ;
                here->MOS1DdpPtr = matched->CSC ;
            }

            if ((here->MOS1gNode != 0) && (here->MOS1bNode != 0))
            {
                i = here->MOS1GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1GbBinding = matched ;
                here->MOS1GbPtr = matched->CSC ;
            }

            if ((here->MOS1gNode != 0) && (here->MOS1dNodePrime != 0))
            {
                i = here->MOS1GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1GdpBinding = matched ;
                here->MOS1GdpPtr = matched->CSC ;
            }

            if ((here->MOS1gNode != 0) && (here->MOS1sNodePrime != 0))
            {
                i = here->MOS1GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1GspBinding = matched ;
                here->MOS1GspPtr = matched->CSC ;
            }

            if ((here->MOS1sNode != 0) && (here->MOS1sNodePrime != 0))
            {
                i = here->MOS1SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SspBinding = matched ;
                here->MOS1SspPtr = matched->CSC ;
            }

            if ((here->MOS1bNode != 0) && (here->MOS1dNodePrime != 0))
            {
                i = here->MOS1BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1BdpBinding = matched ;
                here->MOS1BdpPtr = matched->CSC ;
            }

            if ((here->MOS1bNode != 0) && (here->MOS1sNodePrime != 0))
            {
                i = here->MOS1BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1BspBinding = matched ;
                here->MOS1BspPtr = matched->CSC ;
            }

            if ((here->MOS1dNodePrime != 0) && (here->MOS1sNodePrime != 0))
            {
                i = here->MOS1DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DPspBinding = matched ;
                here->MOS1DPspPtr = matched->CSC ;
            }

            if ((here->MOS1dNodePrime != 0) && (here->MOS1dNode != 0))
            {
                i = here->MOS1DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DPdBinding = matched ;
                here->MOS1DPdPtr = matched->CSC ;
            }

            if ((here->MOS1bNode != 0) && (here->MOS1gNode != 0))
            {
                i = here->MOS1BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1BgBinding = matched ;
                here->MOS1BgPtr = matched->CSC ;
            }

            if ((here->MOS1dNodePrime != 0) && (here->MOS1gNode != 0))
            {
                i = here->MOS1DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DPgBinding = matched ;
                here->MOS1DPgPtr = matched->CSC ;
            }

            if ((here->MOS1sNodePrime != 0) && (here->MOS1gNode != 0))
            {
                i = here->MOS1SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SPgBinding = matched ;
                here->MOS1SPgPtr = matched->CSC ;
            }

            if ((here->MOS1sNodePrime != 0) && (here->MOS1sNode != 0))
            {
                i = here->MOS1SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SPsBinding = matched ;
                here->MOS1SPsPtr = matched->CSC ;
            }

            if ((here->MOS1dNodePrime != 0) && (here->MOS1bNode != 0))
            {
                i = here->MOS1DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1DPbBinding = matched ;
                here->MOS1DPbPtr = matched->CSC ;
            }

            if ((here->MOS1sNodePrime != 0) && (here->MOS1bNode != 0))
            {
                i = here->MOS1SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SPbBinding = matched ;
                here->MOS1SPbPtr = matched->CSC ;
            }

            if ((here->MOS1sNodePrime != 0) && (here->MOS1dNodePrime != 0))
            {
                i = here->MOS1SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS1SPdpBinding = matched ;
                here->MOS1SPdpPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
MOS1bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS1model *model = (MOS1model *)inModel ;
    MOS1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS1 models */
    for ( ; model != NULL ; model = model->MOS1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS1instances ; here != NULL ; here = here->MOS1nextInstance)
        {
            if ((here->MOS1dNode != 0) && (here->MOS1dNode != 0))
                here->MOS1DdPtr = here->MOS1DdBinding->CSC_Complex ;

            if ((here->MOS1gNode != 0) && (here->MOS1gNode != 0))
                here->MOS1GgPtr = here->MOS1GgBinding->CSC_Complex ;

            if ((here->MOS1sNode != 0) && (here->MOS1sNode != 0))
                here->MOS1SsPtr = here->MOS1SsBinding->CSC_Complex ;

            if ((here->MOS1bNode != 0) && (here->MOS1bNode != 0))
                here->MOS1BbPtr = here->MOS1BbBinding->CSC_Complex ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1DPdpPtr = here->MOS1DPdpBinding->CSC_Complex ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1SPspPtr = here->MOS1SPspBinding->CSC_Complex ;

            if ((here->MOS1dNode != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1DdpPtr = here->MOS1DdpBinding->CSC_Complex ;

            if ((here->MOS1gNode != 0) && (here->MOS1bNode != 0))
                here->MOS1GbPtr = here->MOS1GbBinding->CSC_Complex ;

            if ((here->MOS1gNode != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1GdpPtr = here->MOS1GdpBinding->CSC_Complex ;

            if ((here->MOS1gNode != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1GspPtr = here->MOS1GspBinding->CSC_Complex ;

            if ((here->MOS1sNode != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1SspPtr = here->MOS1SspBinding->CSC_Complex ;

            if ((here->MOS1bNode != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1BdpPtr = here->MOS1BdpBinding->CSC_Complex ;

            if ((here->MOS1bNode != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1BspPtr = here->MOS1BspBinding->CSC_Complex ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1DPspPtr = here->MOS1DPspBinding->CSC_Complex ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1dNode != 0))
                here->MOS1DPdPtr = here->MOS1DPdBinding->CSC_Complex ;

            if ((here->MOS1bNode != 0) && (here->MOS1gNode != 0))
                here->MOS1BgPtr = here->MOS1BgBinding->CSC_Complex ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1gNode != 0))
                here->MOS1DPgPtr = here->MOS1DPgBinding->CSC_Complex ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1gNode != 0))
                here->MOS1SPgPtr = here->MOS1SPgBinding->CSC_Complex ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1sNode != 0))
                here->MOS1SPsPtr = here->MOS1SPsBinding->CSC_Complex ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1bNode != 0))
                here->MOS1DPbPtr = here->MOS1DPbBinding->CSC_Complex ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1bNode != 0))
                here->MOS1SPbPtr = here->MOS1SPbBinding->CSC_Complex ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1SPdpPtr = here->MOS1SPdpBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
MOS1bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS1model *model = (MOS1model *)inModel ;
    MOS1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS1 models */
    for ( ; model != NULL ; model = model->MOS1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS1instances ; here != NULL ; here = here->MOS1nextInstance)
        {
            if ((here->MOS1dNode != 0) && (here->MOS1dNode != 0))
                here->MOS1DdPtr = here->MOS1DdBinding->CSC ;

            if ((here->MOS1gNode != 0) && (here->MOS1gNode != 0))
                here->MOS1GgPtr = here->MOS1GgBinding->CSC ;

            if ((here->MOS1sNode != 0) && (here->MOS1sNode != 0))
                here->MOS1SsPtr = here->MOS1SsBinding->CSC ;

            if ((here->MOS1bNode != 0) && (here->MOS1bNode != 0))
                here->MOS1BbPtr = here->MOS1BbBinding->CSC ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1DPdpPtr = here->MOS1DPdpBinding->CSC ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1SPspPtr = here->MOS1SPspBinding->CSC ;

            if ((here->MOS1dNode != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1DdpPtr = here->MOS1DdpBinding->CSC ;

            if ((here->MOS1gNode != 0) && (here->MOS1bNode != 0))
                here->MOS1GbPtr = here->MOS1GbBinding->CSC ;

            if ((here->MOS1gNode != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1GdpPtr = here->MOS1GdpBinding->CSC ;

            if ((here->MOS1gNode != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1GspPtr = here->MOS1GspBinding->CSC ;

            if ((here->MOS1sNode != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1SspPtr = here->MOS1SspBinding->CSC ;

            if ((here->MOS1bNode != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1BdpPtr = here->MOS1BdpBinding->CSC ;

            if ((here->MOS1bNode != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1BspPtr = here->MOS1BspBinding->CSC ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1sNodePrime != 0))
                here->MOS1DPspPtr = here->MOS1DPspBinding->CSC ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1dNode != 0))
                here->MOS1DPdPtr = here->MOS1DPdBinding->CSC ;

            if ((here->MOS1bNode != 0) && (here->MOS1gNode != 0))
                here->MOS1BgPtr = here->MOS1BgBinding->CSC ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1gNode != 0))
                here->MOS1DPgPtr = here->MOS1DPgBinding->CSC ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1gNode != 0))
                here->MOS1SPgPtr = here->MOS1SPgBinding->CSC ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1sNode != 0))
                here->MOS1SPsPtr = here->MOS1SPsBinding->CSC ;

            if ((here->MOS1dNodePrime != 0) && (here->MOS1bNode != 0))
                here->MOS1DPbPtr = here->MOS1DPbBinding->CSC ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1bNode != 0))
                here->MOS1SPbPtr = here->MOS1SPbBinding->CSC ;

            if ((here->MOS1sNodePrime != 0) && (here->MOS1dNodePrime != 0))
                here->MOS1SPdpPtr = here->MOS1SPdpBinding->CSC ;

        }
    }

    return (OK) ;
}
