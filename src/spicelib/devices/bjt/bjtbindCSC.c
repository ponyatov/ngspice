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
            XFOO(BJTcolColPrimePtr, BJTcolColPrimeBinding, BJTcolNode, BJTcolPrimeNode);
            XFOO(BJTbaseBasePrimePtr, BJTbaseBasePrimeBinding, BJTbaseNode, BJTbasePrimeNode);
            XFOO(BJTemitEmitPrimePtr, BJTemitEmitPrimeBinding, BJTemitNode, BJTemitPrimeNode);
            XFOO(BJTcolPrimeColPtr, BJTcolPrimeColBinding, BJTcolPrimeNode, BJTcolNode);
            XFOO(BJTcolPrimeBasePrimePtr, BJTcolPrimeBasePrimeBinding, BJTcolPrimeNode, BJTbasePrimeNode);
            XFOO(BJTcolPrimeEmitPrimePtr, BJTcolPrimeEmitPrimeBinding, BJTcolPrimeNode, BJTemitPrimeNode);
            XFOO(BJTbasePrimeBasePtr, BJTbasePrimeBaseBinding, BJTbasePrimeNode, BJTbaseNode);
            XFOO(BJTbasePrimeColPrimePtr, BJTbasePrimeColPrimeBinding, BJTbasePrimeNode, BJTcolPrimeNode);
            XFOO(BJTbasePrimeEmitPrimePtr, BJTbasePrimeEmitPrimeBinding, BJTbasePrimeNode, BJTemitPrimeNode);
            XFOO(BJTemitPrimeEmitPtr, BJTemitPrimeEmitBinding, BJTemitPrimeNode, BJTemitNode);
            XFOO(BJTemitPrimeColPrimePtr, BJTemitPrimeColPrimeBinding, BJTemitPrimeNode, BJTcolPrimeNode);
            XFOO(BJTemitPrimeBasePrimePtr, BJTemitPrimeBasePrimeBinding, BJTemitPrimeNode, BJTbasePrimeNode);
            XFOO(BJTcolColPtr, BJTcolColBinding, BJTcolNode, BJTcolNode);
            XFOO(BJTbaseBasePtr, BJTbaseBaseBinding, BJTbaseNode, BJTbaseNode);
            XFOO(BJTemitEmitPtr, BJTemitEmitBinding, BJTemitNode, BJTemitNode);
            XFOO(BJTcolPrimeColPrimePtr, BJTcolPrimeColPrimeBinding, BJTcolPrimeNode, BJTcolPrimeNode);
            XFOO(BJTbasePrimeBasePrimePtr, BJTbasePrimeBasePrimeBinding, BJTbasePrimeNode, BJTbasePrimeNode);
            XFOO(BJTemitPrimeEmitPrimePtr, BJTemitPrimeEmitPrimeBinding, BJTemitPrimeNode, BJTemitPrimeNode);
            XFOO(BJTsubstSubstPtr, BJTsubstSubstBinding, BJTsubstNode, BJTsubstNode);
            XFOO(BJTsubstConSubstPtr, BJTsubstConSubstBinding, BJTsubstConNode, BJTsubstNode);
            XFOO(BJTsubstSubstConPtr, BJTsubstSubstConBinding, BJTsubstNode, BJTsubstConNode);
            XFOO(BJTbaseColPrimePtr, BJTbaseColPrimeBinding, BJTbaseNode, BJTcolPrimeNode);
            XFOO(BJTcolPrimeBasePtr, BJTcolPrimeBaseBinding, BJTcolPrimeNode, BJTbaseNode);
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
            BFOO(BJTcolColPrimePtr, BJTcolColPrimeBinding, BJTcolNode, BJTcolPrimeNode);
            BFOO(BJTbaseBasePrimePtr, BJTbaseBasePrimeBinding, BJTbaseNode, BJTbasePrimeNode);
            BFOO(BJTemitEmitPrimePtr, BJTemitEmitPrimeBinding, BJTemitNode, BJTemitPrimeNode);
            BFOO(BJTcolPrimeColPtr, BJTcolPrimeColBinding, BJTcolPrimeNode, BJTcolNode);
            BFOO(BJTcolPrimeBasePrimePtr, BJTcolPrimeBasePrimeBinding, BJTcolPrimeNode, BJTbasePrimeNode);
            BFOO(BJTcolPrimeEmitPrimePtr, BJTcolPrimeEmitPrimeBinding, BJTcolPrimeNode, BJTemitPrimeNode);
            BFOO(BJTbasePrimeBasePtr, BJTbasePrimeBaseBinding, BJTbasePrimeNode, BJTbaseNode);
            BFOO(BJTbasePrimeColPrimePtr, BJTbasePrimeColPrimeBinding, BJTbasePrimeNode, BJTcolPrimeNode);
            BFOO(BJTbasePrimeEmitPrimePtr, BJTbasePrimeEmitPrimeBinding, BJTbasePrimeNode, BJTemitPrimeNode);
            BFOO(BJTemitPrimeEmitPtr, BJTemitPrimeEmitBinding, BJTemitPrimeNode, BJTemitNode);
            BFOO(BJTemitPrimeColPrimePtr, BJTemitPrimeColPrimeBinding, BJTemitPrimeNode, BJTcolPrimeNode);
            BFOO(BJTemitPrimeBasePrimePtr, BJTemitPrimeBasePrimeBinding, BJTemitPrimeNode, BJTbasePrimeNode);
            BFOO(BJTcolColPtr, BJTcolColBinding, BJTcolNode, BJTcolNode);
            BFOO(BJTbaseBasePtr, BJTbaseBaseBinding, BJTbaseNode, BJTbaseNode);
            BFOO(BJTemitEmitPtr, BJTemitEmitBinding, BJTemitNode, BJTemitNode);
            BFOO(BJTcolPrimeColPrimePtr, BJTcolPrimeColPrimeBinding, BJTcolPrimeNode, BJTcolPrimeNode);
            BFOO(BJTbasePrimeBasePrimePtr, BJTbasePrimeBasePrimeBinding, BJTbasePrimeNode, BJTbasePrimeNode);
            BFOO(BJTemitPrimeEmitPrimePtr, BJTemitPrimeEmitPrimeBinding, BJTemitPrimeNode, BJTemitPrimeNode);
            BFOO(BJTsubstSubstPtr, BJTsubstSubstBinding, BJTsubstNode, BJTsubstNode);
            BFOO(BJTsubstConSubstPtr, BJTsubstConSubstBinding, BJTsubstConNode, BJTsubstNode);
            BFOO(BJTsubstSubstConPtr, BJTsubstSubstConBinding, BJTsubstNode, BJTsubstConNode);
            BFOO(BJTbaseColPrimePtr, BJTbaseColPrimeBinding, BJTbaseNode, BJTcolPrimeNode);
            BFOO(BJTcolPrimeBasePtr, BJTcolPrimeBaseBinding, BJTcolPrimeNode, BJTbaseNode);
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
            CFOO(BJTcolColPrimePtr, BJTcolColPrimeBinding, BJTcolNode, BJTcolPrimeNode);
            CFOO(BJTbaseBasePrimePtr, BJTbaseBasePrimeBinding, BJTbaseNode, BJTbasePrimeNode);
            CFOO(BJTemitEmitPrimePtr, BJTemitEmitPrimeBinding, BJTemitNode, BJTemitPrimeNode);
            CFOO(BJTcolPrimeColPtr, BJTcolPrimeColBinding, BJTcolPrimeNode, BJTcolNode);
            CFOO(BJTcolPrimeBasePrimePtr, BJTcolPrimeBasePrimeBinding, BJTcolPrimeNode, BJTbasePrimeNode);
            CFOO(BJTcolPrimeEmitPrimePtr, BJTcolPrimeEmitPrimeBinding, BJTcolPrimeNode, BJTemitPrimeNode);
            CFOO(BJTbasePrimeBasePtr, BJTbasePrimeBaseBinding, BJTbasePrimeNode, BJTbaseNode);
            CFOO(BJTbasePrimeColPrimePtr, BJTbasePrimeColPrimeBinding, BJTbasePrimeNode, BJTcolPrimeNode);
            CFOO(BJTbasePrimeEmitPrimePtr, BJTbasePrimeEmitPrimeBinding, BJTbasePrimeNode, BJTemitPrimeNode);
            CFOO(BJTemitPrimeEmitPtr, BJTemitPrimeEmitBinding, BJTemitPrimeNode, BJTemitNode);
            CFOO(BJTemitPrimeColPrimePtr, BJTemitPrimeColPrimeBinding, BJTemitPrimeNode, BJTcolPrimeNode);
            CFOO(BJTemitPrimeBasePrimePtr, BJTemitPrimeBasePrimeBinding, BJTemitPrimeNode, BJTbasePrimeNode);
            CFOO(BJTcolColPtr, BJTcolColBinding, BJTcolNode, BJTcolNode);
            CFOO(BJTbaseBasePtr, BJTbaseBaseBinding, BJTbaseNode, BJTbaseNode);
            CFOO(BJTemitEmitPtr, BJTemitEmitBinding, BJTemitNode, BJTemitNode);
            CFOO(BJTcolPrimeColPrimePtr, BJTcolPrimeColPrimeBinding, BJTcolPrimeNode, BJTcolPrimeNode);
            CFOO(BJTbasePrimeBasePrimePtr, BJTbasePrimeBasePrimeBinding, BJTbasePrimeNode, BJTbasePrimeNode);
            CFOO(BJTemitPrimeEmitPrimePtr, BJTemitPrimeEmitPrimeBinding, BJTemitPrimeNode, BJTemitPrimeNode);
            CFOO(BJTsubstSubstPtr, BJTsubstSubstBinding, BJTsubstNode, BJTsubstNode);
            CFOO(BJTsubstConSubstPtr, BJTsubstConSubstBinding, BJTsubstConNode, BJTsubstNode);
            CFOO(BJTsubstSubstConPtr, BJTsubstSubstConBinding, BJTsubstNode, BJTsubstConNode);
            CFOO(BJTbaseColPrimePtr, BJTbaseColPrimeBinding, BJTbaseNode, BJTcolPrimeNode);
            CFOO(BJTcolPrimeBasePtr, BJTcolPrimeBaseBinding, BJTcolPrimeNode, BJTbaseNode);
        }
    }

    return (OK) ;
}
