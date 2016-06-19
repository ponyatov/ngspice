/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim1def.h"
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
B1bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B1model *model = (B1model *)inModel ;
    B1instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B1 models */
    for ( ; model != NULL ; model = model->B1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B1instances ; here != NULL ; here = here->B1nextInstance)
        {
            if ((here-> B1dNode != 0) && (here-> B1dNode != 0))
            {
                i = here->B1DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DdBinding = matched ;
                here->B1DdPtr = matched->CSC ;
            }

            if ((here-> B1gNode != 0) && (here-> B1gNode != 0))
            {
                i = here->B1GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1GgBinding = matched ;
                here->B1GgPtr = matched->CSC ;
            }

            if ((here-> B1sNode != 0) && (here-> B1sNode != 0))
            {
                i = here->B1SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SsBinding = matched ;
                here->B1SsPtr = matched->CSC ;
            }

            if ((here-> B1bNode != 0) && (here-> B1bNode != 0))
            {
                i = here->B1BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1BbBinding = matched ;
                here->B1BbPtr = matched->CSC ;
            }

            if ((here-> B1dNodePrime != 0) && (here-> B1dNodePrime != 0))
            {
                i = here->B1DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DPdpBinding = matched ;
                here->B1DPdpPtr = matched->CSC ;
            }

            if ((here-> B1sNodePrime != 0) && (here-> B1sNodePrime != 0))
            {
                i = here->B1SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SPspBinding = matched ;
                here->B1SPspPtr = matched->CSC ;
            }

            if ((here-> B1dNode != 0) && (here-> B1dNodePrime != 0))
            {
                i = here->B1DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DdpBinding = matched ;
                here->B1DdpPtr = matched->CSC ;
            }

            if ((here-> B1gNode != 0) && (here-> B1bNode != 0))
            {
                i = here->B1GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1GbBinding = matched ;
                here->B1GbPtr = matched->CSC ;
            }

            if ((here-> B1gNode != 0) && (here-> B1dNodePrime != 0))
            {
                i = here->B1GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1GdpBinding = matched ;
                here->B1GdpPtr = matched->CSC ;
            }

            if ((here-> B1gNode != 0) && (here-> B1sNodePrime != 0))
            {
                i = here->B1GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1GspBinding = matched ;
                here->B1GspPtr = matched->CSC ;
            }

            if ((here-> B1sNode != 0) && (here-> B1sNodePrime != 0))
            {
                i = here->B1SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SspBinding = matched ;
                here->B1SspPtr = matched->CSC ;
            }

            if ((here-> B1bNode != 0) && (here-> B1dNodePrime != 0))
            {
                i = here->B1BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1BdpBinding = matched ;
                here->B1BdpPtr = matched->CSC ;
            }

            if ((here-> B1bNode != 0) && (here-> B1sNodePrime != 0))
            {
                i = here->B1BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1BspBinding = matched ;
                here->B1BspPtr = matched->CSC ;
            }

            if ((here-> B1dNodePrime != 0) && (here-> B1sNodePrime != 0))
            {
                i = here->B1DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DPspBinding = matched ;
                here->B1DPspPtr = matched->CSC ;
            }

            if ((here-> B1dNodePrime != 0) && (here-> B1dNode != 0))
            {
                i = here->B1DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DPdBinding = matched ;
                here->B1DPdPtr = matched->CSC ;
            }

            if ((here-> B1bNode != 0) && (here-> B1gNode != 0))
            {
                i = here->B1BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1BgBinding = matched ;
                here->B1BgPtr = matched->CSC ;
            }

            if ((here-> B1dNodePrime != 0) && (here-> B1gNode != 0))
            {
                i = here->B1DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DPgBinding = matched ;
                here->B1DPgPtr = matched->CSC ;
            }

            if ((here-> B1sNodePrime != 0) && (here-> B1gNode != 0))
            {
                i = here->B1SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SPgBinding = matched ;
                here->B1SPgPtr = matched->CSC ;
            }

            if ((here-> B1sNodePrime != 0) && (here-> B1sNode != 0))
            {
                i = here->B1SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SPsBinding = matched ;
                here->B1SPsPtr = matched->CSC ;
            }

            if ((here-> B1dNodePrime != 0) && (here-> B1bNode != 0))
            {
                i = here->B1DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1DPbBinding = matched ;
                here->B1DPbPtr = matched->CSC ;
            }

            if ((here-> B1sNodePrime != 0) && (here-> B1bNode != 0))
            {
                i = here->B1SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SPbBinding = matched ;
                here->B1SPbPtr = matched->CSC ;
            }

            if ((here-> B1sNodePrime != 0) && (here-> B1dNodePrime != 0))
            {
                i = here->B1SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B1SPdpBinding = matched ;
                here->B1SPdpPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
B1bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B1model *model = (B1model *)inModel ;
    B1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B1 models */
    for ( ; model != NULL ; model = model->B1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B1instances ; here != NULL ; here = here->B1nextInstance)
        {
            if ((here-> B1dNode != 0) && (here-> B1dNode != 0))
                here->B1DdPtr = here->B1DdBinding->CSC_Complex ;

            if ((here-> B1gNode != 0) && (here-> B1gNode != 0))
                here->B1GgPtr = here->B1GgBinding->CSC_Complex ;

            if ((here-> B1sNode != 0) && (here-> B1sNode != 0))
                here->B1SsPtr = here->B1SsBinding->CSC_Complex ;

            if ((here-> B1bNode != 0) && (here-> B1bNode != 0))
                here->B1BbPtr = here->B1BbBinding->CSC_Complex ;

            if ((here-> B1dNodePrime != 0) && (here-> B1dNodePrime != 0))
                here->B1DPdpPtr = here->B1DPdpBinding->CSC_Complex ;

            if ((here-> B1sNodePrime != 0) && (here-> B1sNodePrime != 0))
                here->B1SPspPtr = here->B1SPspBinding->CSC_Complex ;

            if ((here-> B1dNode != 0) && (here-> B1dNodePrime != 0))
                here->B1DdpPtr = here->B1DdpBinding->CSC_Complex ;

            if ((here-> B1gNode != 0) && (here-> B1bNode != 0))
                here->B1GbPtr = here->B1GbBinding->CSC_Complex ;

            if ((here-> B1gNode != 0) && (here-> B1dNodePrime != 0))
                here->B1GdpPtr = here->B1GdpBinding->CSC_Complex ;

            if ((here-> B1gNode != 0) && (here-> B1sNodePrime != 0))
                here->B1GspPtr = here->B1GspBinding->CSC_Complex ;

            if ((here-> B1sNode != 0) && (here-> B1sNodePrime != 0))
                here->B1SspPtr = here->B1SspBinding->CSC_Complex ;

            if ((here-> B1bNode != 0) && (here-> B1dNodePrime != 0))
                here->B1BdpPtr = here->B1BdpBinding->CSC_Complex ;

            if ((here-> B1bNode != 0) && (here-> B1sNodePrime != 0))
                here->B1BspPtr = here->B1BspBinding->CSC_Complex ;

            if ((here-> B1dNodePrime != 0) && (here-> B1sNodePrime != 0))
                here->B1DPspPtr = here->B1DPspBinding->CSC_Complex ;

            if ((here-> B1dNodePrime != 0) && (here-> B1dNode != 0))
                here->B1DPdPtr = here->B1DPdBinding->CSC_Complex ;

            if ((here-> B1bNode != 0) && (here-> B1gNode != 0))
                here->B1BgPtr = here->B1BgBinding->CSC_Complex ;

            if ((here-> B1dNodePrime != 0) && (here-> B1gNode != 0))
                here->B1DPgPtr = here->B1DPgBinding->CSC_Complex ;

            if ((here-> B1sNodePrime != 0) && (here-> B1gNode != 0))
                here->B1SPgPtr = here->B1SPgBinding->CSC_Complex ;

            if ((here-> B1sNodePrime != 0) && (here-> B1sNode != 0))
                here->B1SPsPtr = here->B1SPsBinding->CSC_Complex ;

            if ((here-> B1dNodePrime != 0) && (here-> B1bNode != 0))
                here->B1DPbPtr = here->B1DPbBinding->CSC_Complex ;

            if ((here-> B1sNodePrime != 0) && (here-> B1bNode != 0))
                here->B1SPbPtr = here->B1SPbBinding->CSC_Complex ;

            if ((here-> B1sNodePrime != 0) && (here-> B1dNodePrime != 0))
                here->B1SPdpPtr = here->B1SPdpBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
B1bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B1model *model = (B1model *)inModel ;
    B1instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B1 models */
    for ( ; model != NULL ; model = model->B1nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B1instances ; here != NULL ; here = here->B1nextInstance)
        {
            if ((here-> B1dNode != 0) && (here-> B1dNode != 0))
                here->B1DdPtr = here->B1DdBinding->CSC ;

            if ((here-> B1gNode != 0) && (here-> B1gNode != 0))
                here->B1GgPtr = here->B1GgBinding->CSC ;

            if ((here-> B1sNode != 0) && (here-> B1sNode != 0))
                here->B1SsPtr = here->B1SsBinding->CSC ;

            if ((here-> B1bNode != 0) && (here-> B1bNode != 0))
                here->B1BbPtr = here->B1BbBinding->CSC ;

            if ((here-> B1dNodePrime != 0) && (here-> B1dNodePrime != 0))
                here->B1DPdpPtr = here->B1DPdpBinding->CSC ;

            if ((here-> B1sNodePrime != 0) && (here-> B1sNodePrime != 0))
                here->B1SPspPtr = here->B1SPspBinding->CSC ;

            if ((here-> B1dNode != 0) && (here-> B1dNodePrime != 0))
                here->B1DdpPtr = here->B1DdpBinding->CSC ;

            if ((here-> B1gNode != 0) && (here-> B1bNode != 0))
                here->B1GbPtr = here->B1GbBinding->CSC ;

            if ((here-> B1gNode != 0) && (here-> B1dNodePrime != 0))
                here->B1GdpPtr = here->B1GdpBinding->CSC ;

            if ((here-> B1gNode != 0) && (here-> B1sNodePrime != 0))
                here->B1GspPtr = here->B1GspBinding->CSC ;

            if ((here-> B1sNode != 0) && (here-> B1sNodePrime != 0))
                here->B1SspPtr = here->B1SspBinding->CSC ;

            if ((here-> B1bNode != 0) && (here-> B1dNodePrime != 0))
                here->B1BdpPtr = here->B1BdpBinding->CSC ;

            if ((here-> B1bNode != 0) && (here-> B1sNodePrime != 0))
                here->B1BspPtr = here->B1BspBinding->CSC ;

            if ((here-> B1dNodePrime != 0) && (here-> B1sNodePrime != 0))
                here->B1DPspPtr = here->B1DPspBinding->CSC ;

            if ((here-> B1dNodePrime != 0) && (here-> B1dNode != 0))
                here->B1DPdPtr = here->B1DPdBinding->CSC ;

            if ((here-> B1bNode != 0) && (here-> B1gNode != 0))
                here->B1BgPtr = here->B1BgBinding->CSC ;

            if ((here-> B1dNodePrime != 0) && (here-> B1gNode != 0))
                here->B1DPgPtr = here->B1DPgBinding->CSC ;

            if ((here-> B1sNodePrime != 0) && (here-> B1gNode != 0))
                here->B1SPgPtr = here->B1SPgBinding->CSC ;

            if ((here-> B1sNodePrime != 0) && (here-> B1sNode != 0))
                here->B1SPsPtr = here->B1SPsBinding->CSC ;

            if ((here-> B1dNodePrime != 0) && (here-> B1bNode != 0))
                here->B1DPbPtr = here->B1DPbBinding->CSC ;

            if ((here-> B1sNodePrime != 0) && (here-> B1bNode != 0))
                here->B1SPbPtr = here->B1SPbBinding->CSC ;

            if ((here-> B1sNodePrime != 0) && (here-> B1dNodePrime != 0))
                here->B1SPdpPtr = here->B1SPdpBinding->CSC ;

        }
    }

    return (OK) ;
}
