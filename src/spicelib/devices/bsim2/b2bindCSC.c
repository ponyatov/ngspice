/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bsim2def.h"
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
B2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B2model *model = (B2model *)inModel ;
    B2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B2 models */
    for ( ; model != NULL ; model = model->B2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B2instances ; here != NULL ; here = here->B2nextInstance)
        {
            if ((here-> B2dNode != 0) && (here-> B2dNode != 0))
            {
                i = here->B2DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DdBinding = matched ;
                here->B2DdPtr = matched->CSC ;
            }

            if ((here-> B2gNode != 0) && (here-> B2gNode != 0))
            {
                i = here->B2GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2GgBinding = matched ;
                here->B2GgPtr = matched->CSC ;
            }

            if ((here-> B2sNode != 0) && (here-> B2sNode != 0))
            {
                i = here->B2SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SsBinding = matched ;
                here->B2SsPtr = matched->CSC ;
            }

            if ((here-> B2bNode != 0) && (here-> B2bNode != 0))
            {
                i = here->B2BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2BbBinding = matched ;
                here->B2BbPtr = matched->CSC ;
            }

            if ((here-> B2dNodePrime != 0) && (here-> B2dNodePrime != 0))
            {
                i = here->B2DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DPdpBinding = matched ;
                here->B2DPdpPtr = matched->CSC ;
            }

            if ((here-> B2sNodePrime != 0) && (here-> B2sNodePrime != 0))
            {
                i = here->B2SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SPspBinding = matched ;
                here->B2SPspPtr = matched->CSC ;
            }

            if ((here-> B2dNode != 0) && (here-> B2dNodePrime != 0))
            {
                i = here->B2DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DdpBinding = matched ;
                here->B2DdpPtr = matched->CSC ;
            }

            if ((here-> B2gNode != 0) && (here-> B2bNode != 0))
            {
                i = here->B2GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2GbBinding = matched ;
                here->B2GbPtr = matched->CSC ;
            }

            if ((here-> B2gNode != 0) && (here-> B2dNodePrime != 0))
            {
                i = here->B2GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2GdpBinding = matched ;
                here->B2GdpPtr = matched->CSC ;
            }

            if ((here-> B2gNode != 0) && (here-> B2sNodePrime != 0))
            {
                i = here->B2GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2GspBinding = matched ;
                here->B2GspPtr = matched->CSC ;
            }

            if ((here-> B2sNode != 0) && (here-> B2sNodePrime != 0))
            {
                i = here->B2SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SspBinding = matched ;
                here->B2SspPtr = matched->CSC ;
            }

            if ((here-> B2bNode != 0) && (here-> B2dNodePrime != 0))
            {
                i = here->B2BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2BdpBinding = matched ;
                here->B2BdpPtr = matched->CSC ;
            }

            if ((here-> B2bNode != 0) && (here-> B2sNodePrime != 0))
            {
                i = here->B2BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2BspBinding = matched ;
                here->B2BspPtr = matched->CSC ;
            }

            if ((here-> B2dNodePrime != 0) && (here-> B2sNodePrime != 0))
            {
                i = here->B2DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DPspBinding = matched ;
                here->B2DPspPtr = matched->CSC ;
            }

            if ((here-> B2dNodePrime != 0) && (here-> B2dNode != 0))
            {
                i = here->B2DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DPdBinding = matched ;
                here->B2DPdPtr = matched->CSC ;
            }

            if ((here-> B2bNode != 0) && (here-> B2gNode != 0))
            {
                i = here->B2BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2BgBinding = matched ;
                here->B2BgPtr = matched->CSC ;
            }

            if ((here-> B2dNodePrime != 0) && (here-> B2gNode != 0))
            {
                i = here->B2DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DPgBinding = matched ;
                here->B2DPgPtr = matched->CSC ;
            }

            if ((here-> B2sNodePrime != 0) && (here-> B2gNode != 0))
            {
                i = here->B2SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SPgBinding = matched ;
                here->B2SPgPtr = matched->CSC ;
            }

            if ((here-> B2sNodePrime != 0) && (here-> B2sNode != 0))
            {
                i = here->B2SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SPsBinding = matched ;
                here->B2SPsPtr = matched->CSC ;
            }

            if ((here-> B2dNodePrime != 0) && (here-> B2bNode != 0))
            {
                i = here->B2DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2DPbBinding = matched ;
                here->B2DPbPtr = matched->CSC ;
            }

            if ((here-> B2sNodePrime != 0) && (here-> B2bNode != 0))
            {
                i = here->B2SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SPbBinding = matched ;
                here->B2SPbPtr = matched->CSC ;
            }

            if ((here-> B2sNodePrime != 0) && (here-> B2dNodePrime != 0))
            {
                i = here->B2SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B2SPdpBinding = matched ;
                here->B2SPdpPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
B2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B2model *model = (B2model *)inModel ;
    B2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B2 models */
    for ( ; model != NULL ; model = model->B2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B2instances ; here != NULL ; here = here->B2nextInstance)
        {
            if ((here-> B2dNode != 0) && (here-> B2dNode != 0))
                here->B2DdPtr = here->B2DdBinding->CSC_Complex ;

            if ((here-> B2gNode != 0) && (here-> B2gNode != 0))
                here->B2GgPtr = here->B2GgBinding->CSC_Complex ;

            if ((here-> B2sNode != 0) && (here-> B2sNode != 0))
                here->B2SsPtr = here->B2SsBinding->CSC_Complex ;

            if ((here-> B2bNode != 0) && (here-> B2bNode != 0))
                here->B2BbPtr = here->B2BbBinding->CSC_Complex ;

            if ((here-> B2dNodePrime != 0) && (here-> B2dNodePrime != 0))
                here->B2DPdpPtr = here->B2DPdpBinding->CSC_Complex ;

            if ((here-> B2sNodePrime != 0) && (here-> B2sNodePrime != 0))
                here->B2SPspPtr = here->B2SPspBinding->CSC_Complex ;

            if ((here-> B2dNode != 0) && (here-> B2dNodePrime != 0))
                here->B2DdpPtr = here->B2DdpBinding->CSC_Complex ;

            if ((here-> B2gNode != 0) && (here-> B2bNode != 0))
                here->B2GbPtr = here->B2GbBinding->CSC_Complex ;

            if ((here-> B2gNode != 0) && (here-> B2dNodePrime != 0))
                here->B2GdpPtr = here->B2GdpBinding->CSC_Complex ;

            if ((here-> B2gNode != 0) && (here-> B2sNodePrime != 0))
                here->B2GspPtr = here->B2GspBinding->CSC_Complex ;

            if ((here-> B2sNode != 0) && (here-> B2sNodePrime != 0))
                here->B2SspPtr = here->B2SspBinding->CSC_Complex ;

            if ((here-> B2bNode != 0) && (here-> B2dNodePrime != 0))
                here->B2BdpPtr = here->B2BdpBinding->CSC_Complex ;

            if ((here-> B2bNode != 0) && (here-> B2sNodePrime != 0))
                here->B2BspPtr = here->B2BspBinding->CSC_Complex ;

            if ((here-> B2dNodePrime != 0) && (here-> B2sNodePrime != 0))
                here->B2DPspPtr = here->B2DPspBinding->CSC_Complex ;

            if ((here-> B2dNodePrime != 0) && (here-> B2dNode != 0))
                here->B2DPdPtr = here->B2DPdBinding->CSC_Complex ;

            if ((here-> B2bNode != 0) && (here-> B2gNode != 0))
                here->B2BgPtr = here->B2BgBinding->CSC_Complex ;

            if ((here-> B2dNodePrime != 0) && (here-> B2gNode != 0))
                here->B2DPgPtr = here->B2DPgBinding->CSC_Complex ;

            if ((here-> B2sNodePrime != 0) && (here-> B2gNode != 0))
                here->B2SPgPtr = here->B2SPgBinding->CSC_Complex ;

            if ((here-> B2sNodePrime != 0) && (here-> B2sNode != 0))
                here->B2SPsPtr = here->B2SPsBinding->CSC_Complex ;

            if ((here-> B2dNodePrime != 0) && (here-> B2bNode != 0))
                here->B2DPbPtr = here->B2DPbBinding->CSC_Complex ;

            if ((here-> B2sNodePrime != 0) && (here-> B2bNode != 0))
                here->B2SPbPtr = here->B2SPbBinding->CSC_Complex ;

            if ((here-> B2sNodePrime != 0) && (here-> B2dNodePrime != 0))
                here->B2SPdpPtr = here->B2SPdpBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
B2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B2model *model = (B2model *)inModel ;
    B2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B2 models */
    for ( ; model != NULL ; model = model->B2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B2instances ; here != NULL ; here = here->B2nextInstance)
        {
            if ((here-> B2dNode != 0) && (here-> B2dNode != 0))
                here->B2DdPtr = here->B2DdBinding->CSC ;

            if ((here-> B2gNode != 0) && (here-> B2gNode != 0))
                here->B2GgPtr = here->B2GgBinding->CSC ;

            if ((here-> B2sNode != 0) && (here-> B2sNode != 0))
                here->B2SsPtr = here->B2SsBinding->CSC ;

            if ((here-> B2bNode != 0) && (here-> B2bNode != 0))
                here->B2BbPtr = here->B2BbBinding->CSC ;

            if ((here-> B2dNodePrime != 0) && (here-> B2dNodePrime != 0))
                here->B2DPdpPtr = here->B2DPdpBinding->CSC ;

            if ((here-> B2sNodePrime != 0) && (here-> B2sNodePrime != 0))
                here->B2SPspPtr = here->B2SPspBinding->CSC ;

            if ((here-> B2dNode != 0) && (here-> B2dNodePrime != 0))
                here->B2DdpPtr = here->B2DdpBinding->CSC ;

            if ((here-> B2gNode != 0) && (here-> B2bNode != 0))
                here->B2GbPtr = here->B2GbBinding->CSC ;

            if ((here-> B2gNode != 0) && (here-> B2dNodePrime != 0))
                here->B2GdpPtr = here->B2GdpBinding->CSC ;

            if ((here-> B2gNode != 0) && (here-> B2sNodePrime != 0))
                here->B2GspPtr = here->B2GspBinding->CSC ;

            if ((here-> B2sNode != 0) && (here-> B2sNodePrime != 0))
                here->B2SspPtr = here->B2SspBinding->CSC ;

            if ((here-> B2bNode != 0) && (here-> B2dNodePrime != 0))
                here->B2BdpPtr = here->B2BdpBinding->CSC ;

            if ((here-> B2bNode != 0) && (here-> B2sNodePrime != 0))
                here->B2BspPtr = here->B2BspBinding->CSC ;

            if ((here-> B2dNodePrime != 0) && (here-> B2sNodePrime != 0))
                here->B2DPspPtr = here->B2DPspBinding->CSC ;

            if ((here-> B2dNodePrime != 0) && (here-> B2dNode != 0))
                here->B2DPdPtr = here->B2DPdBinding->CSC ;

            if ((here-> B2bNode != 0) && (here-> B2gNode != 0))
                here->B2BgPtr = here->B2BgBinding->CSC ;

            if ((here-> B2dNodePrime != 0) && (here-> B2gNode != 0))
                here->B2DPgPtr = here->B2DPgBinding->CSC ;

            if ((here-> B2sNodePrime != 0) && (here-> B2gNode != 0))
                here->B2SPgPtr = here->B2SPgBinding->CSC ;

            if ((here-> B2sNodePrime != 0) && (here-> B2sNode != 0))
                here->B2SPsPtr = here->B2SPsBinding->CSC ;

            if ((here-> B2dNodePrime != 0) && (here-> B2bNode != 0))
                here->B2DPbPtr = here->B2DPbBinding->CSC ;

            if ((here-> B2sNodePrime != 0) && (here-> B2bNode != 0))
                here->B2SPbPtr = here->B2SPbBinding->CSC ;

            if ((here-> B2sNodePrime != 0) && (here-> B2dNodePrime != 0))
                here->B2SPdpPtr = here->B2SPdpBinding->CSC ;

        }
    }

    return (OK) ;
}
