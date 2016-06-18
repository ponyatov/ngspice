/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "capdefs.h"
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
CAPbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = model->CAPnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CAPinstances ; here != NULL ; here = here->CAPnextInstance)
        {
            if ((here->CAPposNode != 0) && (here->CAPposNode != 0))
            {
                i = here->CAPposPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CAPposPosBinding = matched ;
                here->CAPposPosPtr = matched->CSC ;
            }

            if ((here->CAPnegNode != 0) && (here->CAPnegNode != 0))
            {
                i = here->CAPnegNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CAPnegNegBinding = matched ;
                here->CAPnegNegPtr = matched->CSC ;
            }

            if ((here->CAPposNode != 0) && (here->CAPnegNode != 0))
            {
                i = here->CAPposNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CAPposNegBinding = matched ;
                here->CAPposNegPtr = matched->CSC ;
            }

            if ((here->CAPnegNode != 0) && (here->CAPposNode != 0))
            {
                i = here->CAPnegPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CAPnegPosBinding = matched ;
                here->CAPnegPosPtr = matched->CSC ;
            }
        }
    }

    return (OK) ;
}

int
CAPbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = model->CAPnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CAPinstances ; here != NULL ; here = here->CAPnextInstance)
        {
            if ((here->CAPposNode != 0) && (here->CAPposNode != 0))
                here->CAPposPosPtr = here->CAPposPosBinding->CSC_Complex ;

            if ((here->CAPnegNode != 0) && (here->CAPnegNode != 0))
                here->CAPnegNegPtr = here->CAPnegNegBinding->CSC_Complex ;

            if ((here->CAPposNode != 0) && (here->CAPnegNode != 0))
                here->CAPposNegPtr = here->CAPposNegBinding->CSC_Complex ;

            if ((here->CAPnegNode != 0) && (here->CAPposNode != 0))
                here->CAPnegPosPtr = here->CAPnegPosBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
CAPbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = model->CAPnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CAPinstances ; here != NULL ; here = here->CAPnextInstance)
        {
            if ((here->CAPposNode != 0) && (here->CAPposNode != 0))
                here->CAPposPosPtr = here->CAPposPosBinding->CSC ;

            if ((here->CAPnegNode != 0) && (here->CAPnegNode != 0))
                here->CAPnegNegPtr = here->CAPnegNegBinding->CSC ;

            if ((here->CAPposNode != 0) && (here->CAPnegNode != 0))
                here->CAPposNegPtr = here->CAPposNegBinding->CSC ;

            if ((here->CAPnegNode != 0) && (here->CAPposNode != 0))
                here->CAPnegPosPtr = here->CAPnegPosBinding->CSC ;

        }
    }

    return (OK) ;
}
