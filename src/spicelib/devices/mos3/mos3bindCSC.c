/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos3defs.h"
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
MOS3bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS3model *model = (MOS3model *)inModel ;
    MOS3instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS3 models */
    for ( ; model != NULL ; model = model->MOS3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS3instances ; here != NULL ; here = here->MOS3nextInstance)
        {
            if ((here-> MOS3dNode != 0) && (here-> MOS3dNode != 0))
            {
                i = here->MOS3DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DdBinding = matched ;
                here->MOS3DdPtr = matched->CSC ;
            }

            if ((here-> MOS3gNode != 0) && (here-> MOS3gNode != 0))
            {
                i = here->MOS3GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3GgBinding = matched ;
                here->MOS3GgPtr = matched->CSC ;
            }

            if ((here-> MOS3sNode != 0) && (here-> MOS3sNode != 0))
            {
                i = here->MOS3SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SsBinding = matched ;
                here->MOS3SsPtr = matched->CSC ;
            }

            if ((here-> MOS3bNode != 0) && (here-> MOS3bNode != 0))
            {
                i = here->MOS3BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3BbBinding = matched ;
                here->MOS3BbPtr = matched->CSC ;
            }

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3dNodePrime != 0))
            {
                i = here->MOS3DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DPdpBinding = matched ;
                here->MOS3DPdpPtr = matched->CSC ;
            }

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3sNodePrime != 0))
            {
                i = here->MOS3SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SPspBinding = matched ;
                here->MOS3SPspPtr = matched->CSC ;
            }

            if ((here-> MOS3dNode != 0) && (here-> MOS3dNodePrime != 0))
            {
                i = here->MOS3DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DdpBinding = matched ;
                here->MOS3DdpPtr = matched->CSC ;
            }

            if ((here-> MOS3gNode != 0) && (here-> MOS3bNode != 0))
            {
                i = here->MOS3GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3GbBinding = matched ;
                here->MOS3GbPtr = matched->CSC ;
            }

            if ((here-> MOS3gNode != 0) && (here-> MOS3dNodePrime != 0))
            {
                i = here->MOS3GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3GdpBinding = matched ;
                here->MOS3GdpPtr = matched->CSC ;
            }

            if ((here-> MOS3gNode != 0) && (here-> MOS3sNodePrime != 0))
            {
                i = here->MOS3GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3GspBinding = matched ;
                here->MOS3GspPtr = matched->CSC ;
            }

            if ((here-> MOS3sNode != 0) && (here-> MOS3sNodePrime != 0))
            {
                i = here->MOS3SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SspBinding = matched ;
                here->MOS3SspPtr = matched->CSC ;
            }

            if ((here-> MOS3bNode != 0) && (here-> MOS3dNodePrime != 0))
            {
                i = here->MOS3BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3BdpBinding = matched ;
                here->MOS3BdpPtr = matched->CSC ;
            }

            if ((here-> MOS3bNode != 0) && (here-> MOS3sNodePrime != 0))
            {
                i = here->MOS3BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3BspBinding = matched ;
                here->MOS3BspPtr = matched->CSC ;
            }

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3sNodePrime != 0))
            {
                i = here->MOS3DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DPspBinding = matched ;
                here->MOS3DPspPtr = matched->CSC ;
            }

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3dNode != 0))
            {
                i = here->MOS3DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DPdBinding = matched ;
                here->MOS3DPdPtr = matched->CSC ;
            }

            if ((here-> MOS3bNode != 0) && (here-> MOS3gNode != 0))
            {
                i = here->MOS3BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3BgBinding = matched ;
                here->MOS3BgPtr = matched->CSC ;
            }

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3gNode != 0))
            {
                i = here->MOS3DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DPgBinding = matched ;
                here->MOS3DPgPtr = matched->CSC ;
            }

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3gNode != 0))
            {
                i = here->MOS3SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SPgBinding = matched ;
                here->MOS3SPgPtr = matched->CSC ;
            }

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3sNode != 0))
            {
                i = here->MOS3SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SPsBinding = matched ;
                here->MOS3SPsPtr = matched->CSC ;
            }

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3bNode != 0))
            {
                i = here->MOS3DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3DPbBinding = matched ;
                here->MOS3DPbPtr = matched->CSC ;
            }

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3bNode != 0))
            {
                i = here->MOS3SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SPbBinding = matched ;
                here->MOS3SPbPtr = matched->CSC ;
            }

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3dNodePrime != 0))
            {
                i = here->MOS3SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS3SPdpBinding = matched ;
                here->MOS3SPdpPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
MOS3bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS3model *model = (MOS3model *)inModel ;
    MOS3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS3 models */
    for ( ; model != NULL ; model = model->MOS3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS3instances ; here != NULL ; here = here->MOS3nextInstance)
        {
            if ((here-> MOS3dNode != 0) && (here-> MOS3dNode != 0))
                here->MOS3DdPtr = here->MOS3DdBinding->CSC_Complex ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3gNode != 0))
                here->MOS3GgPtr = here->MOS3GgBinding->CSC_Complex ;

            if ((here-> MOS3sNode != 0) && (here-> MOS3sNode != 0))
                here->MOS3SsPtr = here->MOS3SsBinding->CSC_Complex ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3bNode != 0))
                here->MOS3BbPtr = here->MOS3BbBinding->CSC_Complex ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3DPdpPtr = here->MOS3DPdpBinding->CSC_Complex ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3SPspPtr = here->MOS3SPspBinding->CSC_Complex ;

            if ((here-> MOS3dNode != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3DdpPtr = here->MOS3DdpBinding->CSC_Complex ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3bNode != 0))
                here->MOS3GbPtr = here->MOS3GbBinding->CSC_Complex ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3GdpPtr = here->MOS3GdpBinding->CSC_Complex ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3GspPtr = here->MOS3GspBinding->CSC_Complex ;

            if ((here-> MOS3sNode != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3SspPtr = here->MOS3SspBinding->CSC_Complex ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3BdpPtr = here->MOS3BdpBinding->CSC_Complex ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3BspPtr = here->MOS3BspBinding->CSC_Complex ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3DPspPtr = here->MOS3DPspBinding->CSC_Complex ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3dNode != 0))
                here->MOS3DPdPtr = here->MOS3DPdBinding->CSC_Complex ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3gNode != 0))
                here->MOS3BgPtr = here->MOS3BgBinding->CSC_Complex ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3gNode != 0))
                here->MOS3DPgPtr = here->MOS3DPgBinding->CSC_Complex ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3gNode != 0))
                here->MOS3SPgPtr = here->MOS3SPgBinding->CSC_Complex ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3sNode != 0))
                here->MOS3SPsPtr = here->MOS3SPsBinding->CSC_Complex ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3bNode != 0))
                here->MOS3DPbPtr = here->MOS3DPbBinding->CSC_Complex ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3bNode != 0))
                here->MOS3SPbPtr = here->MOS3SPbBinding->CSC_Complex ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3SPdpPtr = here->MOS3SPdpBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
MOS3bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS3model *model = (MOS3model *)inModel ;
    MOS3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS3 models */
    for ( ; model != NULL ; model = model->MOS3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS3instances ; here != NULL ; here = here->MOS3nextInstance)
        {
            if ((here-> MOS3dNode != 0) && (here-> MOS3dNode != 0))
                here->MOS3DdPtr = here->MOS3DdBinding->CSC ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3gNode != 0))
                here->MOS3GgPtr = here->MOS3GgBinding->CSC ;

            if ((here-> MOS3sNode != 0) && (here-> MOS3sNode != 0))
                here->MOS3SsPtr = here->MOS3SsBinding->CSC ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3bNode != 0))
                here->MOS3BbPtr = here->MOS3BbBinding->CSC ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3DPdpPtr = here->MOS3DPdpBinding->CSC ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3SPspPtr = here->MOS3SPspBinding->CSC ;

            if ((here-> MOS3dNode != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3DdpPtr = here->MOS3DdpBinding->CSC ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3bNode != 0))
                here->MOS3GbPtr = here->MOS3GbBinding->CSC ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3GdpPtr = here->MOS3GdpBinding->CSC ;

            if ((here-> MOS3gNode != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3GspPtr = here->MOS3GspBinding->CSC ;

            if ((here-> MOS3sNode != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3SspPtr = here->MOS3SspBinding->CSC ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3BdpPtr = here->MOS3BdpBinding->CSC ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3BspPtr = here->MOS3BspBinding->CSC ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3sNodePrime != 0))
                here->MOS3DPspPtr = here->MOS3DPspBinding->CSC ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3dNode != 0))
                here->MOS3DPdPtr = here->MOS3DPdBinding->CSC ;

            if ((here-> MOS3bNode != 0) && (here-> MOS3gNode != 0))
                here->MOS3BgPtr = here->MOS3BgBinding->CSC ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3gNode != 0))
                here->MOS3DPgPtr = here->MOS3DPgBinding->CSC ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3gNode != 0))
                here->MOS3SPgPtr = here->MOS3SPgBinding->CSC ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3sNode != 0))
                here->MOS3SPsPtr = here->MOS3SPsBinding->CSC ;

            if ((here-> MOS3dNodePrime != 0) && (here-> MOS3bNode != 0))
                here->MOS3DPbPtr = here->MOS3DPbBinding->CSC ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3bNode != 0))
                here->MOS3SPbPtr = here->MOS3SPbBinding->CSC ;

            if ((here-> MOS3sNodePrime != 0) && (here-> MOS3dNodePrime != 0))
                here->MOS3SPdpPtr = here->MOS3SPdpBinding->CSC ;

        }
    }

    return (OK) ;
}
