/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "txldefs.h"
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
                here->TXLposPosptrStructPtr = matched ;
                here->TXLposPosPtr = matched->CSC ;
            }

            if ((here-> TXLposNode != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLposNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLposNegptrStructPtr = matched ;
                here->TXLposNegPtr = matched->CSC ;
            }

            if ((here-> TXLnegNode != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLnegPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLnegPosptrStructPtr = matched ;
                here->TXLnegPosPtr = matched->CSC ;
            }

            if ((here-> TXLnegNode != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLnegNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLnegNegptrStructPtr = matched ;
                here->TXLnegNegPtr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLibr1PosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1PosptrStructPtr = matched ;
                here->TXLibr1PosPtr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLibr2NegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2NegptrStructPtr = matched ;
                here->TXLibr2NegPtr = matched->CSC ;
            }

            if ((here-> TXLnegNode != 0) && (here-> TXLibr2 != 0))
            {
                i = here->TXLnegIbr2Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLnegIbr2ptrStructPtr = matched ;
                here->TXLnegIbr2Ptr = matched->CSC ;
            }

            if ((here-> TXLposNode != 0) && (here-> TXLibr1 != 0))
            {
                i = here->TXLposIbr1Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLposIbr1ptrStructPtr = matched ;
                here->TXLposIbr1Ptr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLibr1 != 0))
            {
                i = here->TXLibr1Ibr1Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1Ibr1ptrStructPtr = matched ;
                here->TXLibr1Ibr1Ptr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLibr2 != 0))
            {
                i = here->TXLibr2Ibr2Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2Ibr2ptrStructPtr = matched ;
                here->TXLibr2Ibr2Ptr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLnegNode != 0))
            {
                i = here->TXLibr1NegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1NegptrStructPtr = matched ;
                here->TXLibr1NegPtr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLposNode != 0))
            {
                i = here->TXLibr2PosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2PosptrStructPtr = matched ;
                here->TXLibr2PosPtr = matched->CSC ;
            }

            if ((here-> TXLibr1 != 0) && (here-> TXLibr2 != 0))
            {
                i = here->TXLibr1Ibr2Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr1Ibr2ptrStructPtr = matched ;
                here->TXLibr1Ibr2Ptr = matched->CSC ;
            }

            if ((here-> TXLibr2 != 0) && (here-> TXLibr1 != 0))
            {
                i = here->TXLibr2Ibr1Ptr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->TXLibr2Ibr1ptrStructPtr = matched ;
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
                here->TXLposPosPtr = here->TXLposPosptrStructPtr->CSC_Complex ;

            if ((here-> TXLposNode != 0) && (here-> TXLnegNode != 0))
                here->TXLposNegPtr = here->TXLposNegptrStructPtr->CSC_Complex ;

            if ((here-> TXLnegNode != 0) && (here-> TXLposNode != 0))
                here->TXLnegPosPtr = here->TXLnegPosptrStructPtr->CSC_Complex ;

            if ((here-> TXLnegNode != 0) && (here-> TXLnegNode != 0))
                here->TXLnegNegPtr = here->TXLnegNegptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLposNode != 0))
                here->TXLibr1PosPtr = here->TXLibr1PosptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr2NegPtr = here->TXLibr2NegptrStructPtr->CSC_Complex ;

            if ((here-> TXLnegNode != 0) && (here-> TXLibr2 != 0))
                here->TXLnegIbr2Ptr = here->TXLnegIbr2ptrStructPtr->CSC_Complex ;

            if ((here-> TXLposNode != 0) && (here-> TXLibr1 != 0))
                here->TXLposIbr1Ptr = here->TXLposIbr1ptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr1Ibr1Ptr = here->TXLibr1Ibr1ptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr2Ibr2Ptr = here->TXLibr2Ibr2ptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr1NegPtr = here->TXLibr1NegptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLposNode != 0))
                here->TXLibr2PosPtr = here->TXLibr2PosptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr1Ibr2Ptr = here->TXLibr1Ibr2ptrStructPtr->CSC_Complex ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr2Ibr1Ptr = here->TXLibr2Ibr1ptrStructPtr->CSC_Complex ;

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
                here->TXLposPosPtr = here->TXLposPosptrStructPtr->CSC ;

            if ((here-> TXLposNode != 0) && (here-> TXLnegNode != 0))
                here->TXLposNegPtr = here->TXLposNegptrStructPtr->CSC ;

            if ((here-> TXLnegNode != 0) && (here-> TXLposNode != 0))
                here->TXLnegPosPtr = here->TXLnegPosptrStructPtr->CSC ;

            if ((here-> TXLnegNode != 0) && (here-> TXLnegNode != 0))
                here->TXLnegNegPtr = here->TXLnegNegptrStructPtr->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLposNode != 0))
                here->TXLibr1PosPtr = here->TXLibr1PosptrStructPtr->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr2NegPtr = here->TXLibr2NegptrStructPtr->CSC ;

            if ((here-> TXLnegNode != 0) && (here-> TXLibr2 != 0))
                here->TXLnegIbr2Ptr = here->TXLnegIbr2ptrStructPtr->CSC ;

            if ((here-> TXLposNode != 0) && (here-> TXLibr1 != 0))
                here->TXLposIbr1Ptr = here->TXLposIbr1ptrStructPtr->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr1Ibr1Ptr = here->TXLibr1Ibr1ptrStructPtr->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr2Ibr2Ptr = here->TXLibr2Ibr2ptrStructPtr->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLnegNode != 0))
                here->TXLibr1NegPtr = here->TXLibr1NegptrStructPtr->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLposNode != 0))
                here->TXLibr2PosPtr = here->TXLibr2PosptrStructPtr->CSC ;

            if ((here-> TXLibr1 != 0) && (here-> TXLibr2 != 0))
                here->TXLibr1Ibr2Ptr = here->TXLibr1Ibr2ptrStructPtr->CSC ;

            if ((here-> TXLibr2 != 0) && (here-> TXLibr1 != 0))
                here->TXLibr2Ibr1Ptr = here->TXLibr2Ibr1ptrStructPtr->CSC ;

        }
    }

    return (OK) ;
}
