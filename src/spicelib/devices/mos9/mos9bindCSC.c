/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "mos9defs.h"
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
MOS9bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS9model *model = (MOS9model *)inModel ;
    MOS9instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the MOS9 models */
    for ( ; model != NULL ; model = model->MOS9nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS9instances ; here != NULL ; here = here->MOS9nextInstance)
        {
            if ((here-> MOS9dNode != 0) && (here-> MOS9dNode != 0))
            {
                i = here->MOS9DdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DdBinding = matched ;
                here->MOS9DdPtr = matched->CSC ;
            }

            if ((here-> MOS9gNode != 0) && (here-> MOS9gNode != 0))
            {
                i = here->MOS9GgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9GgBinding = matched ;
                here->MOS9GgPtr = matched->CSC ;
            }

            if ((here-> MOS9sNode != 0) && (here-> MOS9sNode != 0))
            {
                i = here->MOS9SsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SsBinding = matched ;
                here->MOS9SsPtr = matched->CSC ;
            }

            if ((here-> MOS9bNode != 0) && (here-> MOS9bNode != 0))
            {
                i = here->MOS9BbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9BbBinding = matched ;
                here->MOS9BbPtr = matched->CSC ;
            }

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9dNodePrime != 0))
            {
                i = here->MOS9DPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DPdpBinding = matched ;
                here->MOS9DPdpPtr = matched->CSC ;
            }

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9sNodePrime != 0))
            {
                i = here->MOS9SPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SPspBinding = matched ;
                here->MOS9SPspPtr = matched->CSC ;
            }

            if ((here-> MOS9dNode != 0) && (here-> MOS9dNodePrime != 0))
            {
                i = here->MOS9DdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DdpBinding = matched ;
                here->MOS9DdpPtr = matched->CSC ;
            }

            if ((here-> MOS9gNode != 0) && (here-> MOS9bNode != 0))
            {
                i = here->MOS9GbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9GbBinding = matched ;
                here->MOS9GbPtr = matched->CSC ;
            }

            if ((here-> MOS9gNode != 0) && (here-> MOS9dNodePrime != 0))
            {
                i = here->MOS9GdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9GdpBinding = matched ;
                here->MOS9GdpPtr = matched->CSC ;
            }

            if ((here-> MOS9gNode != 0) && (here-> MOS9sNodePrime != 0))
            {
                i = here->MOS9GspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9GspBinding = matched ;
                here->MOS9GspPtr = matched->CSC ;
            }

            if ((here-> MOS9sNode != 0) && (here-> MOS9sNodePrime != 0))
            {
                i = here->MOS9SspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SspBinding = matched ;
                here->MOS9SspPtr = matched->CSC ;
            }

            if ((here-> MOS9bNode != 0) && (here-> MOS9dNodePrime != 0))
            {
                i = here->MOS9BdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9BdpBinding = matched ;
                here->MOS9BdpPtr = matched->CSC ;
            }

            if ((here-> MOS9bNode != 0) && (here-> MOS9sNodePrime != 0))
            {
                i = here->MOS9BspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9BspBinding = matched ;
                here->MOS9BspPtr = matched->CSC ;
            }

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9sNodePrime != 0))
            {
                i = here->MOS9DPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DPspBinding = matched ;
                here->MOS9DPspPtr = matched->CSC ;
            }

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9dNode != 0))
            {
                i = here->MOS9DPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DPdBinding = matched ;
                here->MOS9DPdPtr = matched->CSC ;
            }

            if ((here-> MOS9bNode != 0) && (here-> MOS9gNode != 0))
            {
                i = here->MOS9BgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9BgBinding = matched ;
                here->MOS9BgPtr = matched->CSC ;
            }

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9gNode != 0))
            {
                i = here->MOS9DPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DPgBinding = matched ;
                here->MOS9DPgPtr = matched->CSC ;
            }

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9gNode != 0))
            {
                i = here->MOS9SPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SPgBinding = matched ;
                here->MOS9SPgPtr = matched->CSC ;
            }

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9sNode != 0))
            {
                i = here->MOS9SPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SPsBinding = matched ;
                here->MOS9SPsPtr = matched->CSC ;
            }

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9bNode != 0))
            {
                i = here->MOS9DPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9DPbBinding = matched ;
                here->MOS9DPbPtr = matched->CSC ;
            }

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9bNode != 0))
            {
                i = here->MOS9SPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SPbBinding = matched ;
                here->MOS9SPbPtr = matched->CSC ;
            }

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9dNodePrime != 0))
            {
                i = here->MOS9SPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->MOS9SPdpBinding = matched ;
                here->MOS9SPdpPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
MOS9bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS9model *model = (MOS9model *)inModel ;
    MOS9instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS9 models */
    for ( ; model != NULL ; model = model->MOS9nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS9instances ; here != NULL ; here = here->MOS9nextInstance)
        {
            if ((here-> MOS9dNode != 0) && (here-> MOS9dNode != 0))
                here->MOS9DdPtr = here->MOS9DdBinding->CSC_Complex ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9gNode != 0))
                here->MOS9GgPtr = here->MOS9GgBinding->CSC_Complex ;

            if ((here-> MOS9sNode != 0) && (here-> MOS9sNode != 0))
                here->MOS9SsPtr = here->MOS9SsBinding->CSC_Complex ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9bNode != 0))
                here->MOS9BbPtr = here->MOS9BbBinding->CSC_Complex ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9DPdpPtr = here->MOS9DPdpBinding->CSC_Complex ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9SPspPtr = here->MOS9SPspBinding->CSC_Complex ;

            if ((here-> MOS9dNode != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9DdpPtr = here->MOS9DdpBinding->CSC_Complex ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9bNode != 0))
                here->MOS9GbPtr = here->MOS9GbBinding->CSC_Complex ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9GdpPtr = here->MOS9GdpBinding->CSC_Complex ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9GspPtr = here->MOS9GspBinding->CSC_Complex ;

            if ((here-> MOS9sNode != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9SspPtr = here->MOS9SspBinding->CSC_Complex ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9BdpPtr = here->MOS9BdpBinding->CSC_Complex ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9BspPtr = here->MOS9BspBinding->CSC_Complex ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9DPspPtr = here->MOS9DPspBinding->CSC_Complex ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9dNode != 0))
                here->MOS9DPdPtr = here->MOS9DPdBinding->CSC_Complex ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9gNode != 0))
                here->MOS9BgPtr = here->MOS9BgBinding->CSC_Complex ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9gNode != 0))
                here->MOS9DPgPtr = here->MOS9DPgBinding->CSC_Complex ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9gNode != 0))
                here->MOS9SPgPtr = here->MOS9SPgBinding->CSC_Complex ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9sNode != 0))
                here->MOS9SPsPtr = here->MOS9SPsBinding->CSC_Complex ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9bNode != 0))
                here->MOS9DPbPtr = here->MOS9DPbBinding->CSC_Complex ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9bNode != 0))
                here->MOS9SPbPtr = here->MOS9SPbBinding->CSC_Complex ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9SPdpPtr = here->MOS9SPdpBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
MOS9bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MOS9model *model = (MOS9model *)inModel ;
    MOS9instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MOS9 models */
    for ( ; model != NULL ; model = model->MOS9nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->MOS9instances ; here != NULL ; here = here->MOS9nextInstance)
        {
            if ((here-> MOS9dNode != 0) && (here-> MOS9dNode != 0))
                here->MOS9DdPtr = here->MOS9DdBinding->CSC ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9gNode != 0))
                here->MOS9GgPtr = here->MOS9GgBinding->CSC ;

            if ((here-> MOS9sNode != 0) && (here-> MOS9sNode != 0))
                here->MOS9SsPtr = here->MOS9SsBinding->CSC ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9bNode != 0))
                here->MOS9BbPtr = here->MOS9BbBinding->CSC ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9DPdpPtr = here->MOS9DPdpBinding->CSC ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9SPspPtr = here->MOS9SPspBinding->CSC ;

            if ((here-> MOS9dNode != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9DdpPtr = here->MOS9DdpBinding->CSC ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9bNode != 0))
                here->MOS9GbPtr = here->MOS9GbBinding->CSC ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9GdpPtr = here->MOS9GdpBinding->CSC ;

            if ((here-> MOS9gNode != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9GspPtr = here->MOS9GspBinding->CSC ;

            if ((here-> MOS9sNode != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9SspPtr = here->MOS9SspBinding->CSC ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9BdpPtr = here->MOS9BdpBinding->CSC ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9BspPtr = here->MOS9BspBinding->CSC ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9sNodePrime != 0))
                here->MOS9DPspPtr = here->MOS9DPspBinding->CSC ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9dNode != 0))
                here->MOS9DPdPtr = here->MOS9DPdBinding->CSC ;

            if ((here-> MOS9bNode != 0) && (here-> MOS9gNode != 0))
                here->MOS9BgPtr = here->MOS9BgBinding->CSC ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9gNode != 0))
                here->MOS9DPgPtr = here->MOS9DPgBinding->CSC ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9gNode != 0))
                here->MOS9SPgPtr = here->MOS9SPgBinding->CSC ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9sNode != 0))
                here->MOS9SPsPtr = here->MOS9SPsBinding->CSC ;

            if ((here-> MOS9dNodePrime != 0) && (here-> MOS9bNode != 0))
                here->MOS9DPbPtr = here->MOS9DPbBinding->CSC ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9bNode != 0))
                here->MOS9SPbPtr = here->MOS9SPbBinding->CSC ;

            if ((here-> MOS9sNodePrime != 0) && (here-> MOS9dNodePrime != 0))
                here->MOS9SPdpPtr = here->MOS9SPdpBinding->CSC ;

        }
    }

    return (OK) ;
}
