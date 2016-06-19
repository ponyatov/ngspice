/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "resdefs.h"
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
RESbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    RESmodel *model = (RESmodel *)inModel ;
    RESinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the RES models */
    for ( ; model != NULL ; model = model->RESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->RESinstances ; here != NULL ; here = here->RESnextInstance)
        {
            if ((here-> RESposNode != 0) && (here-> RESposNode != 0))
            {
                i = here->RESposPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->RESposPosBinding = matched ;
                here->RESposPosPtr = matched->CSC ;
            }

            if ((here-> RESnegNode != 0) && (here-> RESnegNode != 0))
            {
                i = here->RESnegNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->RESnegNegBinding = matched ;
                here->RESnegNegPtr = matched->CSC ;
            }

            if ((here-> RESposNode != 0) && (here-> RESnegNode != 0))
            {
                i = here->RESposNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->RESposNegBinding = matched ;
                here->RESposNegPtr = matched->CSC ;
            }

            if ((here-> RESnegNode != 0) && (here-> RESposNode != 0))
            {
                i = here->RESnegPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->RESnegPosBinding = matched ;
                here->RESnegPosPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
RESbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    RESmodel *model = (RESmodel *)inModel ;
    RESinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the RES models */
    for ( ; model != NULL ; model = model->RESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->RESinstances ; here != NULL ; here = here->RESnextInstance)
        {
            if ((here-> RESposNode != 0) && (here-> RESposNode != 0))
                here->RESposPosPtr = here->RESposPosBinding->CSC_Complex ;

            if ((here-> RESnegNode != 0) && (here-> RESnegNode != 0))
                here->RESnegNegPtr = here->RESnegNegBinding->CSC_Complex ;

            if ((here-> RESposNode != 0) && (here-> RESnegNode != 0))
                here->RESposNegPtr = here->RESposNegBinding->CSC_Complex ;

            if ((here-> RESnegNode != 0) && (here-> RESposNode != 0))
                here->RESnegPosPtr = here->RESnegPosBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
RESbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    RESmodel *model = (RESmodel *)inModel ;
    RESinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the RES models */
    for ( ; model != NULL ; model = model->RESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->RESinstances ; here != NULL ; here = here->RESnextInstance)
        {
            if ((here-> RESposNode != 0) && (here-> RESposNode != 0))
                here->RESposPosPtr = here->RESposPosBinding->CSC ;

            if ((here-> RESnegNode != 0) && (here-> RESnegNode != 0))
                here->RESnegNegPtr = here->RESnegNegBinding->CSC ;

            if ((here-> RESposNode != 0) && (here-> RESnegNode != 0))
                here->RESposNegPtr = here->RESposNegBinding->CSC ;

            if ((here-> RESnegNode != 0) && (here-> RESposNode != 0))
                here->RESnegPosPtr = here->RESnegPosBinding->CSC ;

        }
    }

    return (OK) ;
}
