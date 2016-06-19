/**********
Author: 2012 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos6defs.h"
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
MOS6bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS6model *model = (MOS6model *)inModel ;
    MOS6instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS6 models */
    for ( ; model != NULL ; model = model->MOS6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS6instances ; here != NULL ; here = here->MOS6nextInstance)
        {
            if ((here->MOS6dNode != 0) && (here->MOS6dNode != 0))
            {
                i = here->MOS6DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DdBinding = matched ;
                here->MOS6DdPtr = matched->CSC ;
            }

            if ((here->MOS6gNode != 0) && (here->MOS6gNode != 0))
            {
                i = here->MOS6GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6GgBinding = matched ;
                here->MOS6GgPtr = matched->CSC ;
            }

            if ((here->MOS6sNode != 0) && (here->MOS6sNode != 0))
            {
                i = here->MOS6SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SsBinding = matched ;
                here->MOS6SsPtr = matched->CSC ;
            }

            if ((here->MOS6bNode != 0) && (here->MOS6bNode != 0))
            {
                i = here->MOS6BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6BbBinding = matched ;
                here->MOS6BbPtr = matched->CSC ;
            }

            if ((here->MOS6dNodePrime != 0) && (here->MOS6dNodePrime != 0))
            {
                i = here->MOS6DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DPdpBinding = matched ;
                here->MOS6DPdpPtr = matched->CSC ;
            }

            if ((here->MOS6sNodePrime != 0) && (here->MOS6sNodePrime != 0))
            {
                i = here->MOS6SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SPspBinding = matched ;
                here->MOS6SPspPtr = matched->CSC ;
            }

            if ((here->MOS6dNode != 0) && (here->MOS6dNodePrime != 0))
            {
                i = here->MOS6DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DdpBinding = matched ;
                here->MOS6DdpPtr = matched->CSC ;
            }

            if ((here->MOS6gNode != 0) && (here->MOS6bNode != 0))
            {
                i = here->MOS6GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6GbBinding = matched ;
                here->MOS6GbPtr = matched->CSC ;
            }

            if ((here->MOS6gNode != 0) && (here->MOS6dNodePrime != 0))
            {
                i = here->MOS6GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6GdpBinding = matched ;
                here->MOS6GdpPtr = matched->CSC ;
            }

            if ((here->MOS6gNode != 0) && (here->MOS6sNodePrime != 0))
            {
                i = here->MOS6GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6GspBinding = matched ;
                here->MOS6GspPtr = matched->CSC ;
            }

            if ((here->MOS6sNode != 0) && (here->MOS6sNodePrime != 0))
            {
                i = here->MOS6SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SspBinding = matched ;
                here->MOS6SspPtr = matched->CSC ;
            }

            if ((here->MOS6bNode != 0) && (here->MOS6dNodePrime != 0))
            {
                i = here->MOS6BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6BdpBinding = matched ;
                here->MOS6BdpPtr = matched->CSC ;
            }

            if ((here->MOS6bNode != 0) && (here->MOS6sNodePrime != 0))
            {
                i = here->MOS6BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6BspBinding = matched ;
                here->MOS6BspPtr = matched->CSC ;
            }

            if ((here->MOS6dNodePrime != 0) && (here->MOS6sNodePrime != 0))
            {
                i = here->MOS6DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DPspBinding = matched ;
                here->MOS6DPspPtr = matched->CSC ;
            }

            if ((here->MOS6dNodePrime != 0) && (here->MOS6dNode != 0))
            {
                i = here->MOS6DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DPdBinding = matched ;
                here->MOS6DPdPtr = matched->CSC ;
            }

            if ((here->MOS6bNode != 0) && (here->MOS6gNode != 0))
            {
                i = here->MOS6BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6BgBinding = matched ;
                here->MOS6BgPtr = matched->CSC ;
            }

            if ((here->MOS6dNodePrime != 0) && (here->MOS6gNode != 0))
            {
                i = here->MOS6DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DPgBinding = matched ;
                here->MOS6DPgPtr = matched->CSC ;
            }

            if ((here->MOS6sNodePrime != 0) && (here->MOS6gNode != 0))
            {
                i = here->MOS6SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SPgBinding = matched ;
                here->MOS6SPgPtr = matched->CSC ;
            }

            if ((here->MOS6sNodePrime != 0) && (here->MOS6sNode != 0))
            {
                i = here->MOS6SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SPsBinding = matched ;
                here->MOS6SPsPtr = matched->CSC ;
            }

            if ((here->MOS6dNodePrime != 0) && (here->MOS6bNode != 0))
            {
                i = here->MOS6DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6DPbBinding = matched ;
                here->MOS6DPbPtr = matched->CSC ;
            }

            if ((here->MOS6sNodePrime != 0) && (here->MOS6bNode != 0))
            {
                i = here->MOS6SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SPbBinding = matched ;
                here->MOS6SPbPtr = matched->CSC ;
            }

            if ((here->MOS6sNodePrime != 0) && (here->MOS6dNodePrime != 0))
            {
                i = here->MOS6SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS6SPdpBinding = matched ;
                here->MOS6SPdpPtr = matched->CSC ;
            }
        }
    }

    return (OK) ;
}

int
MOS6bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS6model *model = (MOS6model *)inModel ;
    MOS6instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS6 models */
    for ( ; model != NULL ; model = model->MOS6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS6instances ; here != NULL ; here = here->MOS6nextInstance)
        {
            if ((here->MOS6dNode != 0) && (here->MOS6dNode != 0))
                here->MOS6DdPtr = here->MOS6DdBinding->CSC_Complex ;

            if ((here->MOS6gNode != 0) && (here->MOS6gNode != 0))
                here->MOS6GgPtr = here->MOS6GgBinding->CSC_Complex ;

            if ((here->MOS6sNode != 0) && (here->MOS6sNode != 0))
                here->MOS6SsPtr = here->MOS6SsBinding->CSC_Complex ;

            if ((here->MOS6bNode != 0) && (here->MOS6bNode != 0))
                here->MOS6BbPtr = here->MOS6BbBinding->CSC_Complex ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6DPdpPtr = here->MOS6DPdpBinding->CSC_Complex ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6SPspPtr = here->MOS6SPspBinding->CSC_Complex ;

            if ((here->MOS6dNode != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6DdpPtr = here->MOS6DdpBinding->CSC_Complex ;

            if ((here->MOS6gNode != 0) && (here->MOS6bNode != 0))
                here->MOS6GbPtr = here->MOS6GbBinding->CSC_Complex ;

            if ((here->MOS6gNode != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6GdpPtr = here->MOS6GdpBinding->CSC_Complex ;

            if ((here->MOS6gNode != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6GspPtr = here->MOS6GspBinding->CSC_Complex ;

            if ((here->MOS6sNode != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6SspPtr = here->MOS6SspBinding->CSC_Complex ;

            if ((here->MOS6bNode != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6BdpPtr = here->MOS6BdpBinding->CSC_Complex ;

            if ((here->MOS6bNode != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6BspPtr = here->MOS6BspBinding->CSC_Complex ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6DPspPtr = here->MOS6DPspBinding->CSC_Complex ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6dNode != 0))
                here->MOS6DPdPtr = here->MOS6DPdBinding->CSC_Complex ;

            if ((here->MOS6bNode != 0) && (here->MOS6gNode != 0))
                here->MOS6BgPtr = here->MOS6BgBinding->CSC_Complex ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6gNode != 0))
                here->MOS6DPgPtr = here->MOS6DPgBinding->CSC_Complex ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6gNode != 0))
                here->MOS6SPgPtr = here->MOS6SPgBinding->CSC_Complex ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6sNode != 0))
                here->MOS6SPsPtr = here->MOS6SPsBinding->CSC_Complex ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6bNode != 0))
                here->MOS6DPbPtr = here->MOS6DPbBinding->CSC_Complex ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6bNode != 0))
                here->MOS6SPbPtr = here->MOS6SPbBinding->CSC_Complex ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6SPdpPtr = here->MOS6SPdpBinding->CSC_Complex ;
        }
    }

    return (OK) ;
}

int
MOS6bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS6model *model = (MOS6model *)inModel ;
    MOS6instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS6 models */
    for ( ; model != NULL ; model = model->MOS6nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS6instances ; here != NULL ; here = here->MOS6nextInstance)
        {
            if ((here->MOS6dNode != 0) && (here->MOS6dNode != 0))
                here->MOS6DdPtr = here->MOS6DdBinding->CSC ;

            if ((here->MOS6gNode != 0) && (here->MOS6gNode != 0))
                here->MOS6GgPtr = here->MOS6GgBinding->CSC ;

            if ((here->MOS6sNode != 0) && (here->MOS6sNode != 0))
                here->MOS6SsPtr = here->MOS6SsBinding->CSC ;

            if ((here->MOS6bNode != 0) && (here->MOS6bNode != 0))
                here->MOS6BbPtr = here->MOS6BbBinding->CSC ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6DPdpPtr = here->MOS6DPdpBinding->CSC ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6SPspPtr = here->MOS6SPspBinding->CSC ;

            if ((here->MOS6dNode != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6DdpPtr = here->MOS6DdpBinding->CSC ;

            if ((here->MOS6gNode != 0) && (here->MOS6bNode != 0))
                here->MOS6GbPtr = here->MOS6GbBinding->CSC ;

            if ((here->MOS6gNode != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6GdpPtr = here->MOS6GdpBinding->CSC ;

            if ((here->MOS6gNode != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6GspPtr = here->MOS6GspBinding->CSC ;

            if ((here->MOS6sNode != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6SspPtr = here->MOS6SspBinding->CSC ;

            if ((here->MOS6bNode != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6BdpPtr = here->MOS6BdpBinding->CSC ;

            if ((here->MOS6bNode != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6BspPtr = here->MOS6BspBinding->CSC ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6sNodePrime != 0))
                here->MOS6DPspPtr = here->MOS6DPspBinding->CSC ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6dNode != 0))
                here->MOS6DPdPtr = here->MOS6DPdBinding->CSC ;

            if ((here->MOS6bNode != 0) && (here->MOS6gNode != 0))
                here->MOS6BgPtr = here->MOS6BgBinding->CSC ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6gNode != 0))
                here->MOS6DPgPtr = here->MOS6DPgBinding->CSC ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6gNode != 0))
                here->MOS6SPgPtr = here->MOS6SPgBinding->CSC ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6sNode != 0))
                here->MOS6SPsPtr = here->MOS6SPsBinding->CSC ;

            if ((here->MOS6dNodePrime != 0) && (here->MOS6bNode != 0))
                here->MOS6DPbPtr = here->MOS6DPbBinding->CSC ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6bNode != 0))
                here->MOS6SPbPtr = here->MOS6SPbBinding->CSC ;

            if ((here->MOS6sNodePrime != 0) && (here->MOS6dNodePrime != 0))
                here->MOS6SPdpPtr = here->MOS6SPdpBinding->CSC ;
        }
    }

    return (OK) ;
}
