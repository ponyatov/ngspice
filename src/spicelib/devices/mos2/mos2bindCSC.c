/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos2defs.h"
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
MOS2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS2model *model = (MOS2model *)inModel ;
    MOS2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS2 models */
    for ( ; model != NULL ; model = model->MOS2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS2instances ; here != NULL ; here = here->MOS2nextInstance)
        {
            if ((here-> MOS2dNode != 0) && (here-> MOS2dNode != 0))
            {
                i = here->MOS2DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DdBinding = matched ;
                here->MOS2DdPtr = matched->CSC ;
            }

            if ((here-> MOS2gNode != 0) && (here-> MOS2gNode != 0))
            {
                i = here->MOS2GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2GgBinding = matched ;
                here->MOS2GgPtr = matched->CSC ;
            }

            if ((here-> MOS2sNode != 0) && (here-> MOS2sNode != 0))
            {
                i = here->MOS2SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SsBinding = matched ;
                here->MOS2SsPtr = matched->CSC ;
            }

            if ((here-> MOS2bNode != 0) && (here-> MOS2bNode != 0))
            {
                i = here->MOS2BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2BbBinding = matched ;
                here->MOS2BbPtr = matched->CSC ;
            }

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2dNodePrime != 0))
            {
                i = here->MOS2DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DPdpBinding = matched ;
                here->MOS2DPdpPtr = matched->CSC ;
            }

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2sNodePrime != 0))
            {
                i = here->MOS2SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SPspBinding = matched ;
                here->MOS2SPspPtr = matched->CSC ;
            }

            if ((here-> MOS2dNode != 0) && (here-> MOS2dNodePrime != 0))
            {
                i = here->MOS2DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DdpBinding = matched ;
                here->MOS2DdpPtr = matched->CSC ;
            }

            if ((here-> MOS2gNode != 0) && (here-> MOS2bNode != 0))
            {
                i = here->MOS2GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2GbBinding = matched ;
                here->MOS2GbPtr = matched->CSC ;
            }

            if ((here-> MOS2gNode != 0) && (here-> MOS2dNodePrime != 0))
            {
                i = here->MOS2GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2GdpBinding = matched ;
                here->MOS2GdpPtr = matched->CSC ;
            }

            if ((here-> MOS2gNode != 0) && (here-> MOS2sNodePrime != 0))
            {
                i = here->MOS2GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2GspBinding = matched ;
                here->MOS2GspPtr = matched->CSC ;
            }

            if ((here-> MOS2sNode != 0) && (here-> MOS2sNodePrime != 0))
            {
                i = here->MOS2SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SspBinding = matched ;
                here->MOS2SspPtr = matched->CSC ;
            }

            if ((here-> MOS2bNode != 0) && (here-> MOS2dNodePrime != 0))
            {
                i = here->MOS2BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2BdpBinding = matched ;
                here->MOS2BdpPtr = matched->CSC ;
            }

            if ((here-> MOS2bNode != 0) && (here-> MOS2sNodePrime != 0))
            {
                i = here->MOS2BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2BspBinding = matched ;
                here->MOS2BspPtr = matched->CSC ;
            }

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2sNodePrime != 0))
            {
                i = here->MOS2DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DPspBinding = matched ;
                here->MOS2DPspPtr = matched->CSC ;
            }

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2dNode != 0))
            {
                i = here->MOS2DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DPdBinding = matched ;
                here->MOS2DPdPtr = matched->CSC ;
            }

            if ((here-> MOS2bNode != 0) && (here-> MOS2gNode != 0))
            {
                i = here->MOS2BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2BgBinding = matched ;
                here->MOS2BgPtr = matched->CSC ;
            }

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2gNode != 0))
            {
                i = here->MOS2DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DPgBinding = matched ;
                here->MOS2DPgPtr = matched->CSC ;
            }

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2gNode != 0))
            {
                i = here->MOS2SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SPgBinding = matched ;
                here->MOS2SPgPtr = matched->CSC ;
            }

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2sNode != 0))
            {
                i = here->MOS2SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SPsBinding = matched ;
                here->MOS2SPsPtr = matched->CSC ;
            }

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2bNode != 0))
            {
                i = here->MOS2DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2DPbBinding = matched ;
                here->MOS2DPbPtr = matched->CSC ;
            }

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2bNode != 0))
            {
                i = here->MOS2SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SPbBinding = matched ;
                here->MOS2SPbPtr = matched->CSC ;
            }

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2dNodePrime != 0))
            {
                i = here->MOS2SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS2SPdpBinding = matched ;
                here->MOS2SPdpPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
MOS2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS2model *model = (MOS2model *)inModel ;
    MOS2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS2 models */
    for ( ; model != NULL ; model = model->MOS2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS2instances ; here != NULL ; here = here->MOS2nextInstance)
        {
            if ((here-> MOS2dNode != 0) && (here-> MOS2dNode != 0))
                here->MOS2DdPtr = here->MOS2DdBinding->CSC_Complex ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2gNode != 0))
                here->MOS2GgPtr = here->MOS2GgBinding->CSC_Complex ;

            if ((here-> MOS2sNode != 0) && (here-> MOS2sNode != 0))
                here->MOS2SsPtr = here->MOS2SsBinding->CSC_Complex ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2bNode != 0))
                here->MOS2BbPtr = here->MOS2BbBinding->CSC_Complex ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2DPdpPtr = here->MOS2DPdpBinding->CSC_Complex ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2SPspPtr = here->MOS2SPspBinding->CSC_Complex ;

            if ((here-> MOS2dNode != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2DdpPtr = here->MOS2DdpBinding->CSC_Complex ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2bNode != 0))
                here->MOS2GbPtr = here->MOS2GbBinding->CSC_Complex ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2GdpPtr = here->MOS2GdpBinding->CSC_Complex ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2GspPtr = here->MOS2GspBinding->CSC_Complex ;

            if ((here-> MOS2sNode != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2SspPtr = here->MOS2SspBinding->CSC_Complex ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2BdpPtr = here->MOS2BdpBinding->CSC_Complex ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2BspPtr = here->MOS2BspBinding->CSC_Complex ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2DPspPtr = here->MOS2DPspBinding->CSC_Complex ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2dNode != 0))
                here->MOS2DPdPtr = here->MOS2DPdBinding->CSC_Complex ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2gNode != 0))
                here->MOS2BgPtr = here->MOS2BgBinding->CSC_Complex ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2gNode != 0))
                here->MOS2DPgPtr = here->MOS2DPgBinding->CSC_Complex ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2gNode != 0))
                here->MOS2SPgPtr = here->MOS2SPgBinding->CSC_Complex ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2sNode != 0))
                here->MOS2SPsPtr = here->MOS2SPsBinding->CSC_Complex ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2bNode != 0))
                here->MOS2DPbPtr = here->MOS2DPbBinding->CSC_Complex ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2bNode != 0))
                here->MOS2SPbPtr = here->MOS2SPbBinding->CSC_Complex ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2SPdpPtr = here->MOS2SPdpBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
MOS2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS2model *model = (MOS2model *)inModel ;
    MOS2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS2 models */
    for ( ; model != NULL ; model = model->MOS2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS2instances ; here != NULL ; here = here->MOS2nextInstance)
        {
            if ((here-> MOS2dNode != 0) && (here-> MOS2dNode != 0))
                here->MOS2DdPtr = here->MOS2DdBinding->CSC ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2gNode != 0))
                here->MOS2GgPtr = here->MOS2GgBinding->CSC ;

            if ((here-> MOS2sNode != 0) && (here-> MOS2sNode != 0))
                here->MOS2SsPtr = here->MOS2SsBinding->CSC ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2bNode != 0))
                here->MOS2BbPtr = here->MOS2BbBinding->CSC ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2DPdpPtr = here->MOS2DPdpBinding->CSC ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2SPspPtr = here->MOS2SPspBinding->CSC ;

            if ((here-> MOS2dNode != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2DdpPtr = here->MOS2DdpBinding->CSC ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2bNode != 0))
                here->MOS2GbPtr = here->MOS2GbBinding->CSC ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2GdpPtr = here->MOS2GdpBinding->CSC ;

            if ((here-> MOS2gNode != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2GspPtr = here->MOS2GspBinding->CSC ;

            if ((here-> MOS2sNode != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2SspPtr = here->MOS2SspBinding->CSC ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2BdpPtr = here->MOS2BdpBinding->CSC ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2BspPtr = here->MOS2BspBinding->CSC ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2sNodePrime != 0))
                here->MOS2DPspPtr = here->MOS2DPspBinding->CSC ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2dNode != 0))
                here->MOS2DPdPtr = here->MOS2DPdBinding->CSC ;

            if ((here-> MOS2bNode != 0) && (here-> MOS2gNode != 0))
                here->MOS2BgPtr = here->MOS2BgBinding->CSC ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2gNode != 0))
                here->MOS2DPgPtr = here->MOS2DPgBinding->CSC ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2gNode != 0))
                here->MOS2SPgPtr = here->MOS2SPgBinding->CSC ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2sNode != 0))
                here->MOS2SPsPtr = here->MOS2SPsBinding->CSC ;

            if ((here-> MOS2dNodePrime != 0) && (here-> MOS2bNode != 0))
                here->MOS2DPbPtr = here->MOS2DPbBinding->CSC ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2bNode != 0))
                here->MOS2SPbPtr = here->MOS2SPbBinding->CSC ;

            if ((here-> MOS2sNodePrime != 0) && (here-> MOS2dNodePrime != 0))
                here->MOS2SPdpPtr = here->MOS2SPdpBinding->CSC ;

        }
    }

    return (OK) ;
}
