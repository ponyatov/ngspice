/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "txldefs.h"
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
TXLbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    TXLmodel *model = (TXLmodel *)inModel ;
    TXLinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the TXL models */
    for ( ; model != NULL ; model = model->TXLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TXLinstances ; here != NULL ; here = here->TXLnextInstance)
        {
            if ((here-> TXLposNode != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLposPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLposPosBinding = matched ;
                here->TXLposPosPtr = matched->CSC ;
            }

            if ((here-> TXLposNode != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLposNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLposNegBinding = matched ;
                here->TXLposNegPtr = matched->CSC ;
            }

            if ((here-> TXLnegNode != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLnegPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLnegPosBinding = matched ;
                here->TXLnegPosPtr = matched->CSC ;
            }

            if ((here-> TXLnegNode != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLnegNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLnegNegBinding = matched ;
                here->TXLnegNegPtr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLibr1PosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1PosBinding = matched ;
                here->TXLibr1PosPtr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLibr2NegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2NegBinding = matched ;
                here->TXLibr2NegPtr = matched->CSC ;
            }

            if ((here-> TXLnegNode != 0) && (here-> TXLibr2 != 0))
            {
                i = here->TXLnegIbr2Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLnegIbr2Binding = matched ;
                here->TXLnegIbr2Ptr = matched->CSC ;
            }

            if ((here-> TXLposNode != 0) && (here-> TXLibr1 != 0))
            {
                i = here->TXLposIbr1Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLposIbr1Binding = matched ;
                here->TXLposIbr1Ptr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLibr1 != 0))
            {
                i = here->TXLibr1Ibr1Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1Ibr1Binding = matched ;
                here->TXLibr1Ibr1Ptr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLibr2 != 0))
            {
                i = here->TXLibr2Ibr2Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2Ibr2Binding = matched ;
                here->TXLibr2Ibr2Ptr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLibr1NegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1NegBinding = matched ;
                here->TXLibr1NegPtr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLibr2PosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2PosBinding = matched ;
                here->TXLibr2PosPtr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLibr2 != 0))
            {
                i = here->TXLibr1Ibr2Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1Ibr2Binding = matched ;
                here->TXLibr1Ibr2Ptr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLibr1 != 0))
            {
                i = here->TXLibr2Ibr1Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2Ibr1Binding = matched ;
                here->TXLibr2Ibr1Ptr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
TXLbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    TXLmodel *model = (TXLmodel *)inModel ;
    TXLinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the TXL models */
    for ( ; model != NULL ; model = model->TXLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TXLinstances ; here != NULL ; here = here->TXLnextInstance)
        {
            if ((here-> TXLposNode != 0) && (here-> TXLposNode != 0))
                here->TXLposPosPtr = here->TXLposPosBinding->CSC_Complex ;

            if ((here-> TXLposNode != 0) && (here-> TXLnegNode != 0))
                here->TXLposNegPtr = here->TXLposNegBinding->CSC_Complex ;

            if ((here-> TXLnegNode != 0) && (here-> TXLposNode != 0))
                here->TXLnegPosPtr = here->TXLnegPosBinding->CSC_Complex ;

            if ((here-> TXLnegNode != 0) && (here-> TXLnegNode != 0))
                here->TXLnegNegPtr = here->TXLnegNegBinding->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLposNode != 0))
                here->TXLibr1PosPtr = here->TXLibr1PosBinding->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr2NegPtr = here->TXLibr2NegBinding->CSC_Complex ;

            if ((here-> TXLnegNode != 0) && (here-> TXLibr2 != 0))
                here->TXLnegIbr2Ptr = here->TXLnegIbr2Binding->CSC_Complex ;

            if ((here-> TXLposNode != 0) && (here-> TXLibr1 != 0))
                here->TXLposIbr1Ptr = here->TXLposIbr1Binding->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr1Ibr1Ptr = here->TXLibr1Ibr1Binding->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr2Ibr2Ptr = here->TXLibr2Ibr2Binding->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr1NegPtr = here->TXLibr1NegBinding->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLposNode != 0))
                here->TXLibr2PosPtr = here->TXLibr2PosBinding->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr1Ibr2Ptr = here->TXLibr1Ibr2Binding->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr2Ibr1Ptr = here->TXLibr2Ibr1Binding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
TXLbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    TXLmodel *model = (TXLmodel *)inModel ;
    TXLinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the TXL models */
    for ( ; model != NULL ; model = model->TXLnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TXLinstances ; here != NULL ; here = here->TXLnextInstance)
        {
            if ((here-> TXLposNode != 0) && (here-> TXLposNode != 0))
                here->TXLposPosPtr = here->TXLposPosBinding->CSC ;

            if ((here-> TXLposNode != 0) && (here-> TXLnegNode != 0))
                here->TXLposNegPtr = here->TXLposNegBinding->CSC ;

            if ((here-> TXLnegNode != 0) && (here-> TXLposNode != 0))
                here->TXLnegPosPtr = here->TXLnegPosBinding->CSC ;

            if ((here-> TXLnegNode != 0) && (here-> TXLnegNode != 0))
                here->TXLnegNegPtr = here->TXLnegNegBinding->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLposNode != 0))
                here->TXLibr1PosPtr = here->TXLibr1PosBinding->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr2NegPtr = here->TXLibr2NegBinding->CSC ;

            if ((here-> TXLnegNode != 0) && (here-> TXLibr2 != 0))
                here->TXLnegIbr2Ptr = here->TXLnegIbr2Binding->CSC ;

            if ((here-> TXLposNode != 0) && (here-> TXLibr1 != 0))
                here->TXLposIbr1Ptr = here->TXLposIbr1Binding->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr1Ibr1Ptr = here->TXLibr1Ibr1Binding->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr2Ibr2Ptr = here->TXLibr2Ibr2Binding->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr1NegPtr = here->TXLibr1NegBinding->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLposNode != 0))
                here->TXLibr2PosPtr = here->TXLibr2PosBinding->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr1Ibr2Ptr = here->TXLibr1Ibr2Binding->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr2Ibr1Ptr = here->TXLibr2Ibr1Binding->CSC ;

        }
    }

    return (OK) ;
}
