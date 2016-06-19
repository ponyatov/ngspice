/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "numd2def.h"
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
NUMD2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMD2model *model = (NUMD2model *)inModel ;
    NUMD2instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the NUMD2 models */
    for ( ; model != NULL ; model = model->NUMD2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMD2instances ; here != NULL ; here = here->NUMD2nextInstance)
        {
            if ((here-> NUMD2posNode != 0) && (here-> NUMD2posNode != 0))
            {
                i = here->NUMD2posPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMD2posPosBinding = matched ;
                here->NUMD2posPosPtr = matched->CSC ;
            }

            if ((here-> NUMD2negNode != 0) && (here-> NUMD2negNode != 0))
            {
                i = here->NUMD2negNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMD2negNegBinding = matched ;
                here->NUMD2negNegPtr = matched->CSC ;
            }

            if ((here-> NUMD2negNode != 0) && (here-> NUMD2posNode != 0))
            {
                i = here->NUMD2negPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMD2negPosBinding = matched ;
                here->NUMD2negPosPtr = matched->CSC ;
            }

            if ((here-> NUMD2posNode != 0) && (here-> NUMD2negNode != 0))
            {
                i = here->NUMD2posNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMD2posNegBinding = matched ;
                here->NUMD2posNegPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
NUMD2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMD2model *model = (NUMD2model *)inModel ;
    NUMD2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMD2 models */
    for ( ; model != NULL ; model = model->NUMD2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMD2instances ; here != NULL ; here = here->NUMD2nextInstance)
        {
            if ((here-> NUMD2posNode != 0) && (here-> NUMD2posNode != 0))
                here->NUMD2posPosPtr = here->NUMD2posPosBinding->CSC_Complex ;

            if ((here-> NUMD2negNode != 0) && (here-> NUMD2negNode != 0))
                here->NUMD2negNegPtr = here->NUMD2negNegBinding->CSC_Complex ;

            if ((here-> NUMD2negNode != 0) && (here-> NUMD2posNode != 0))
                here->NUMD2negPosPtr = here->NUMD2negPosBinding->CSC_Complex ;

            if ((here-> NUMD2posNode != 0) && (here-> NUMD2negNode != 0))
                here->NUMD2posNegPtr = here->NUMD2posNegBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
NUMD2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMD2model *model = (NUMD2model *)inModel ;
    NUMD2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMD2 models */
    for ( ; model != NULL ; model = model->NUMD2nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMD2instances ; here != NULL ; here = here->NUMD2nextInstance)
        {
            if ((here-> NUMD2posNode != 0) && (here-> NUMD2posNode != 0))
                here->NUMD2posPosPtr = here->NUMD2posPosBinding->CSC ;

            if ((here-> NUMD2negNode != 0) && (here-> NUMD2negNode != 0))
                here->NUMD2negNegPtr = here->NUMD2negNegBinding->CSC ;

            if ((here-> NUMD2negNode != 0) && (here-> NUMD2posNode != 0))
                here->NUMD2negPosPtr = here->NUMD2negPosBinding->CSC ;

            if ((here-> NUMD2posNode != 0) && (here-> NUMD2negNode != 0))
                here->NUMD2posNegPtr = here->NUMD2posNegBinding->CSC ;

        }
    }

    return (OK) ;
}
