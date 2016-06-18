/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bjtdefs.h"
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
BJTbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BJTmodel *model = (BJTmodel *)inModel ;
    BJTinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the BJT models */
    for ( ; model != NULL ; model = model->BJTnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BJTinstances ; here != NULL ; here = here->BJTnextInstance)
        {
            if ((here->BJTcolNode != 0) && (here->BJTcolPrimeNode != 0))
            {
                i = here->BJTcolColPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolColPrimeBinding = matched ;
                here->BJTcolColPrimePtr = matched->CSC ;
            }

            if ((here->BJTbaseNode != 0) && (here->BJTbasePrimeNode != 0))
            {
                i = here->BJTbaseBasePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbaseBasePrimeBinding = matched ;
                here->BJTbaseBasePrimePtr = matched->CSC ;
            }

            if ((here->BJTemitNode != 0) && (here->BJTemitPrimeNode != 0))
            {
                i = here->BJTemitEmitPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTemitEmitPrimeBinding = matched ;
                here->BJTemitEmitPrimePtr = matched->CSC ;
            }

            if ((here->BJTcolPrimeNode != 0) && (here->BJTcolNode != 0))
            {
                i = here->BJTcolPrimeColPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolPrimeColBinding = matched ;
                here->BJTcolPrimeColPtr = matched->CSC ;
            }

            if ((here->BJTcolPrimeNode != 0) && (here->BJTbasePrimeNode != 0))
            {
                i = here->BJTcolPrimeBasePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolPrimeBasePrimeBinding = matched ;
                here->BJTcolPrimeBasePrimePtr = matched->CSC ;
            }

            if ((here->BJTcolPrimeNode != 0) && (here->BJTemitPrimeNode != 0))
            {
                i = here->BJTcolPrimeEmitPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolPrimeEmitPrimeBinding = matched ;
                here->BJTcolPrimeEmitPrimePtr = matched->CSC ;
            }

            if ((here->BJTbasePrimeNode != 0) && (here->BJTbaseNode != 0))
            {
                i = here->BJTbasePrimeBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbasePrimeBaseBinding = matched ;
                here->BJTbasePrimeBasePtr = matched->CSC ;
            }

            if ((here->BJTbasePrimeNode != 0) && (here->BJTcolPrimeNode != 0))
            {
                i = here->BJTbasePrimeColPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbasePrimeColPrimeBinding = matched ;
                here->BJTbasePrimeColPrimePtr = matched->CSC ;
            }

            if ((here->BJTbasePrimeNode != 0) && (here->BJTemitPrimeNode != 0))
            {
                i = here->BJTbasePrimeEmitPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbasePrimeEmitPrimeBinding = matched ;
                here->BJTbasePrimeEmitPrimePtr = matched->CSC ;
            }

            if ((here->BJTemitPrimeNode != 0) && (here->BJTemitNode != 0))
            {
                i = here->BJTemitPrimeEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTemitPrimeEmitBinding = matched ;
                here->BJTemitPrimeEmitPtr = matched->CSC ;
            }

            if ((here->BJTemitPrimeNode != 0) && (here->BJTcolPrimeNode != 0))
            {
                i = here->BJTemitPrimeColPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTemitPrimeColPrimeBinding = matched ;
                here->BJTemitPrimeColPrimePtr = matched->CSC ;
            }

            if ((here->BJTemitPrimeNode != 0) && (here->BJTbasePrimeNode != 0))
            {
                i = here->BJTemitPrimeBasePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTemitPrimeBasePrimeBinding = matched ;
                here->BJTemitPrimeBasePrimePtr = matched->CSC ;
            }

            if ((here->BJTcolNode != 0) && (here->BJTcolNode != 0))
            {
                i = here->BJTcolColPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolColBinding = matched ;
                here->BJTcolColPtr = matched->CSC ;
            }

            if ((here->BJTbaseNode != 0) && (here->BJTbaseNode != 0))
            {
                i = here->BJTbaseBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbaseBaseBinding = matched ;
                here->BJTbaseBasePtr = matched->CSC ;
            }

            if ((here->BJTemitNode != 0) && (here->BJTemitNode != 0))
            {
                i = here->BJTemitEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTemitEmitBinding = matched ;
                here->BJTemitEmitPtr = matched->CSC ;
            }

            if ((here->BJTcolPrimeNode != 0) && (here->BJTcolPrimeNode != 0))
            {
                i = here->BJTcolPrimeColPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolPrimeColPrimeBinding = matched ;
                here->BJTcolPrimeColPrimePtr = matched->CSC ;
            }

            if ((here->BJTbasePrimeNode != 0) && (here->BJTbasePrimeNode != 0))
            {
                i = here->BJTbasePrimeBasePrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbasePrimeBasePrimeBinding = matched ;
                here->BJTbasePrimeBasePrimePtr = matched->CSC ;
            }

            if ((here->BJTemitPrimeNode != 0) && (here->BJTemitPrimeNode != 0))
            {
                i = here->BJTemitPrimeEmitPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTemitPrimeEmitPrimeBinding = matched ;
                here->BJTemitPrimeEmitPrimePtr = matched->CSC ;
            }

            if ((here->BJTsubstNode != 0) && (here->BJTsubstNode != 0))
            {
                i = here->BJTsubstSubstPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTsubstSubstBinding = matched ;
                here->BJTsubstSubstPtr = matched->CSC ;
            }

            if ((here->BJTsubstConNode != 0) && (here->BJTsubstNode != 0))
            {
                i = here->BJTsubstConSubstPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTsubstConSubstBinding = matched ;
                here->BJTsubstConSubstPtr = matched->CSC ;
            }

            if ((here->BJTsubstNode != 0) && (here->BJTsubstConNode != 0))
            {
                i = here->BJTsubstSubstConPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTsubstSubstConBinding = matched ;
                here->BJTsubstSubstConPtr = matched->CSC ;
            }

            if ((here->BJTbaseNode != 0) && (here->BJTcolPrimeNode != 0))
            {
                i = here->BJTbaseColPrimePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTbaseColPrimeBinding = matched ;
                here->BJTbaseColPrimePtr = matched->CSC ;
            }

            if ((here->BJTcolPrimeNode != 0) && (here->BJTbaseNode != 0))
            {
                i = here->BJTcolPrimeBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->BJTcolPrimeBaseBinding = matched ;
                here->BJTcolPrimeBasePtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
BJTbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BJTmodel *model = (BJTmodel *)inModel ;
    BJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BJT models */
    for ( ; model != NULL ; model = model->BJTnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BJTinstances ; here != NULL ; here = here->BJTnextInstance)
        {
            if ((here->BJTcolNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTcolColPrimePtr = here->BJTcolColPrimeBinding->CSC_Complex ;

            if ((here->BJTbaseNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTbaseBasePrimePtr = here->BJTbaseBasePrimeBinding->CSC_Complex ;

            if ((here->BJTemitNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTemitEmitPrimePtr = here->BJTemitEmitPrimeBinding->CSC_Complex ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTcolNode != 0))
                here->BJTcolPrimeColPtr = here->BJTcolPrimeColBinding->CSC_Complex ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTcolPrimeBasePrimePtr = here->BJTcolPrimeBasePrimeBinding->CSC_Complex ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTcolPrimeEmitPrimePtr = here->BJTcolPrimeEmitPrimeBinding->CSC_Complex ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTbaseNode != 0))
                here->BJTbasePrimeBasePtr = here->BJTbasePrimeBaseBinding->CSC_Complex ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTbasePrimeColPrimePtr = here->BJTbasePrimeColPrimeBinding->CSC_Complex ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTbasePrimeEmitPrimePtr = here->BJTbasePrimeEmitPrimeBinding->CSC_Complex ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTemitNode != 0))
                here->BJTemitPrimeEmitPtr = here->BJTemitPrimeEmitBinding->CSC_Complex ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTemitPrimeColPrimePtr = here->BJTemitPrimeColPrimeBinding->CSC_Complex ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTemitPrimeBasePrimePtr = here->BJTemitPrimeBasePrimeBinding->CSC_Complex ;

            if ((here->BJTcolNode != 0) && (here->BJTcolNode != 0))
                here->BJTcolColPtr = here->BJTcolColBinding->CSC_Complex ;

            if ((here->BJTbaseNode != 0) && (here->BJTbaseNode != 0))
                here->BJTbaseBasePtr = here->BJTbaseBaseBinding->CSC_Complex ;

            if ((here->BJTemitNode != 0) && (here->BJTemitNode != 0))
                here->BJTemitEmitPtr = here->BJTemitEmitBinding->CSC_Complex ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTcolPrimeColPrimePtr = here->BJTcolPrimeColPrimeBinding->CSC_Complex ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTbasePrimeBasePrimePtr = here->BJTbasePrimeBasePrimeBinding->CSC_Complex ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTemitPrimeEmitPrimePtr = here->BJTemitPrimeEmitPrimeBinding->CSC_Complex ;

            if ((here->BJTsubstNode != 0) && (here->BJTsubstNode != 0))
                here->BJTsubstSubstPtr = here->BJTsubstSubstBinding->CSC_Complex ;

            if ((here->BJTsubstConNode != 0) && (here->BJTsubstNode != 0))
                here->BJTsubstConSubstPtr = here->BJTsubstConSubstBinding->CSC_Complex ;

            if ((here->BJTsubstNode != 0) && (here->BJTsubstConNode != 0))
                here->BJTsubstSubstConPtr = here->BJTsubstSubstConBinding->CSC_Complex ;

            if ((here->BJTbaseNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTbaseColPrimePtr = here->BJTbaseColPrimeBinding->CSC_Complex ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTbaseNode != 0))
                here->BJTcolPrimeBasePtr = here->BJTcolPrimeBaseBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
BJTbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BJTmodel *model = (BJTmodel *)inModel ;
    BJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BJT models */
    for ( ; model != NULL ; model = model->BJTnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->BJTinstances ; here != NULL ; here = here->BJTnextInstance)
        {
            if ((here->BJTcolNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTcolColPrimePtr = here->BJTcolColPrimeBinding->CSC ;

            if ((here->BJTbaseNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTbaseBasePrimePtr = here->BJTbaseBasePrimeBinding->CSC ;

            if ((here->BJTemitNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTemitEmitPrimePtr = here->BJTemitEmitPrimeBinding->CSC ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTcolNode != 0))
                here->BJTcolPrimeColPtr = here->BJTcolPrimeColBinding->CSC ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTcolPrimeBasePrimePtr = here->BJTcolPrimeBasePrimeBinding->CSC ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTcolPrimeEmitPrimePtr = here->BJTcolPrimeEmitPrimeBinding->CSC ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTbaseNode != 0))
                here->BJTbasePrimeBasePtr = here->BJTbasePrimeBaseBinding->CSC ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTbasePrimeColPrimePtr = here->BJTbasePrimeColPrimeBinding->CSC ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTbasePrimeEmitPrimePtr = here->BJTbasePrimeEmitPrimeBinding->CSC ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTemitNode != 0))
                here->BJTemitPrimeEmitPtr = here->BJTemitPrimeEmitBinding->CSC ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTemitPrimeColPrimePtr = here->BJTemitPrimeColPrimeBinding->CSC ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTemitPrimeBasePrimePtr = here->BJTemitPrimeBasePrimeBinding->CSC ;

            if ((here->BJTcolNode != 0) && (here->BJTcolNode != 0))
                here->BJTcolColPtr = here->BJTcolColBinding->CSC ;

            if ((here->BJTbaseNode != 0) && (here->BJTbaseNode != 0))
                here->BJTbaseBasePtr = here->BJTbaseBaseBinding->CSC ;

            if ((here->BJTemitNode != 0) && (here->BJTemitNode != 0))
                here->BJTemitEmitPtr = here->BJTemitEmitBinding->CSC ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTcolPrimeColPrimePtr = here->BJTcolPrimeColPrimeBinding->CSC ;

            if ((here->BJTbasePrimeNode != 0) && (here->BJTbasePrimeNode != 0))
                here->BJTbasePrimeBasePrimePtr = here->BJTbasePrimeBasePrimeBinding->CSC ;

            if ((here->BJTemitPrimeNode != 0) && (here->BJTemitPrimeNode != 0))
                here->BJTemitPrimeEmitPrimePtr = here->BJTemitPrimeEmitPrimeBinding->CSC ;

            if ((here->BJTsubstNode != 0) && (here->BJTsubstNode != 0))
                here->BJTsubstSubstPtr = here->BJTsubstSubstBinding->CSC ;

            if ((here->BJTsubstConNode != 0) && (here->BJTsubstNode != 0))
                here->BJTsubstConSubstPtr = here->BJTsubstConSubstBinding->CSC ;

            if ((here->BJTsubstNode != 0) && (here->BJTsubstConNode != 0))
                here->BJTsubstSubstConPtr = here->BJTsubstSubstConBinding->CSC ;

            if ((here->BJTbaseNode != 0) && (here->BJTcolPrimeNode != 0))
                here->BJTbaseColPrimePtr = here->BJTbaseColPrimeBinding->CSC ;

            if ((here->BJTcolPrimeNode != 0) && (here->BJTbaseNode != 0))
                here->BJTcolPrimeBasePtr = here->BJTcolPrimeBaseBinding->CSC ;

        }
    }

    return (OK) ;
}
