/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "ltradefs.h"
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
LTRAbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    LTRAmodel *model = (LTRAmodel *)inModel ;
    LTRAinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the LTRA models */
    for ( ; model != NULL ; model = model->LTRAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->LTRAinstances ; here != NULL ; here = here->LTRAnextInstance)
        {
            XFOO(LTRAibr1Pos1Ptr, LTRAibr1Pos1Binding, LTRAbrEq1, LTRAposNode1);
            XFOO(LTRAibr1Neg1Ptr, LTRAibr1Neg1Binding, LTRAbrEq1, LTRAnegNode1);
            XFOO(LTRAibr1Pos2Ptr, LTRAibr1Pos2Binding, LTRAbrEq1, LTRAposNode2);
            XFOO(LTRAibr1Neg2Ptr, LTRAibr1Neg2Binding, LTRAbrEq1, LTRAnegNode2);
            XFOO(LTRAibr1Ibr1Ptr, LTRAibr1Ibr1Binding, LTRAbrEq1, LTRAbrEq1);
            XFOO(LTRAibr1Ibr2Ptr, LTRAibr1Ibr2Binding, LTRAbrEq1, LTRAbrEq2);
            XFOO(LTRAibr2Pos1Ptr, LTRAibr2Pos1Binding, LTRAbrEq2, LTRAposNode1);
            XFOO(LTRAibr2Neg1Ptr, LTRAibr2Neg1Binding, LTRAbrEq2, LTRAnegNode1);
            XFOO(LTRAibr2Pos2Ptr, LTRAibr2Pos2Binding, LTRAbrEq2, LTRAposNode2);
            XFOO(LTRAibr2Neg2Ptr, LTRAibr2Neg2Binding, LTRAbrEq2, LTRAnegNode2);
            XFOO(LTRAibr2Ibr1Ptr, LTRAibr2Ibr1Binding, LTRAbrEq2, LTRAbrEq1);
            XFOO(LTRAibr2Ibr2Ptr, LTRAibr2Ibr2Binding, LTRAbrEq2, LTRAbrEq2);
            XFOO(LTRApos1Ibr1Ptr, LTRApos1Ibr1Binding, LTRAposNode1, LTRAbrEq1);
            XFOO(LTRAneg1Ibr1Ptr, LTRAneg1Ibr1Binding, LTRAnegNode1, LTRAbrEq1);
            XFOO(LTRApos2Ibr2Ptr, LTRApos2Ibr2Binding, LTRAposNode2, LTRAbrEq2);
            XFOO(LTRAneg2Ibr2Ptr, LTRAneg2Ibr2Binding, LTRAnegNode2, LTRAbrEq2);
            XFOO(LTRApos1Pos1Ptr, LTRApos1Pos1Binding, LTRAposNode1, LTRAposNode1);
            XFOO(LTRAneg1Neg1Ptr, LTRAneg1Neg1Binding, LTRAnegNode1, LTRAnegNode1);
            XFOO(LTRApos2Pos2Ptr, LTRApos2Pos2Binding, LTRAposNode2, LTRAposNode2);
            XFOO(LTRAneg2Neg2Ptr, LTRAneg2Neg2Binding, LTRAnegNode2, LTRAnegNode2);
        }
    }

    return (OK) ;
}

int
LTRAbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    LTRAmodel *model = (LTRAmodel *)inModel ;
    LTRAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the LTRA models */
    for ( ; model != NULL ; model = model->LTRAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->LTRAinstances ; here != NULL ; here = here->LTRAnextInstance)
        {
            BFOO(LTRAibr1Pos1Ptr, LTRAibr1Pos1Binding, LTRAbrEq1, LTRAposNode1);
            BFOO(LTRAibr1Neg1Ptr, LTRAibr1Neg1Binding, LTRAbrEq1, LTRAnegNode1);
            BFOO(LTRAibr1Pos2Ptr, LTRAibr1Pos2Binding, LTRAbrEq1, LTRAposNode2);
            BFOO(LTRAibr1Neg2Ptr, LTRAibr1Neg2Binding, LTRAbrEq1, LTRAnegNode2);
            BFOO(LTRAibr1Ibr1Ptr, LTRAibr1Ibr1Binding, LTRAbrEq1, LTRAbrEq1);
            BFOO(LTRAibr1Ibr2Ptr, LTRAibr1Ibr2Binding, LTRAbrEq1, LTRAbrEq2);
            BFOO(LTRAibr2Pos1Ptr, LTRAibr2Pos1Binding, LTRAbrEq2, LTRAposNode1);
            BFOO(LTRAibr2Neg1Ptr, LTRAibr2Neg1Binding, LTRAbrEq2, LTRAnegNode1);
            BFOO(LTRAibr2Pos2Ptr, LTRAibr2Pos2Binding, LTRAbrEq2, LTRAposNode2);
            BFOO(LTRAibr2Neg2Ptr, LTRAibr2Neg2Binding, LTRAbrEq2, LTRAnegNode2);
            BFOO(LTRAibr2Ibr1Ptr, LTRAibr2Ibr1Binding, LTRAbrEq2, LTRAbrEq1);
            BFOO(LTRAibr2Ibr2Ptr, LTRAibr2Ibr2Binding, LTRAbrEq2, LTRAbrEq2);
            BFOO(LTRApos1Ibr1Ptr, LTRApos1Ibr1Binding, LTRAposNode1, LTRAbrEq1);
            BFOO(LTRAneg1Ibr1Ptr, LTRAneg1Ibr1Binding, LTRAnegNode1, LTRAbrEq1);
            BFOO(LTRApos2Ibr2Ptr, LTRApos2Ibr2Binding, LTRAposNode2, LTRAbrEq2);
            BFOO(LTRAneg2Ibr2Ptr, LTRAneg2Ibr2Binding, LTRAnegNode2, LTRAbrEq2);
            BFOO(LTRApos1Pos1Ptr, LTRApos1Pos1Binding, LTRAposNode1, LTRAposNode1);
            BFOO(LTRAneg1Neg1Ptr, LTRAneg1Neg1Binding, LTRAnegNode1, LTRAnegNode1);
            BFOO(LTRApos2Pos2Ptr, LTRApos2Pos2Binding, LTRAposNode2, LTRAposNode2);
            BFOO(LTRAneg2Neg2Ptr, LTRAneg2Neg2Binding, LTRAnegNode2, LTRAnegNode2);
        }
    }

    return (OK) ;
}

int
LTRAbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    LTRAmodel *model = (LTRAmodel *)inModel ;
    LTRAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the LTRA models */
    for ( ; model != NULL ; model = model->LTRAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->LTRAinstances ; here != NULL ; here = here->LTRAnextInstance)
        {
            CFOO(LTRAibr1Pos1Ptr, LTRAibr1Pos1Binding, LTRAbrEq1, LTRAposNode1);
            CFOO(LTRAibr1Neg1Ptr, LTRAibr1Neg1Binding, LTRAbrEq1, LTRAnegNode1);
            CFOO(LTRAibr1Pos2Ptr, LTRAibr1Pos2Binding, LTRAbrEq1, LTRAposNode2);
            CFOO(LTRAibr1Neg2Ptr, LTRAibr1Neg2Binding, LTRAbrEq1, LTRAnegNode2);
            CFOO(LTRAibr1Ibr1Ptr, LTRAibr1Ibr1Binding, LTRAbrEq1, LTRAbrEq1);
            CFOO(LTRAibr1Ibr2Ptr, LTRAibr1Ibr2Binding, LTRAbrEq1, LTRAbrEq2);
            CFOO(LTRAibr2Pos1Ptr, LTRAibr2Pos1Binding, LTRAbrEq2, LTRAposNode1);
            CFOO(LTRAibr2Neg1Ptr, LTRAibr2Neg1Binding, LTRAbrEq2, LTRAnegNode1);
            CFOO(LTRAibr2Pos2Ptr, LTRAibr2Pos2Binding, LTRAbrEq2, LTRAposNode2);
            CFOO(LTRAibr2Neg2Ptr, LTRAibr2Neg2Binding, LTRAbrEq2, LTRAnegNode2);
            CFOO(LTRAibr2Ibr1Ptr, LTRAibr2Ibr1Binding, LTRAbrEq2, LTRAbrEq1);
            CFOO(LTRAibr2Ibr2Ptr, LTRAibr2Ibr2Binding, LTRAbrEq2, LTRAbrEq2);
            CFOO(LTRApos1Ibr1Ptr, LTRApos1Ibr1Binding, LTRAposNode1, LTRAbrEq1);
            CFOO(LTRAneg1Ibr1Ptr, LTRAneg1Ibr1Binding, LTRAnegNode1, LTRAbrEq1);
            CFOO(LTRApos2Ibr2Ptr, LTRApos2Ibr2Binding, LTRAposNode2, LTRAbrEq2);
            CFOO(LTRAneg2Ibr2Ptr, LTRAneg2Ibr2Binding, LTRAnegNode2, LTRAbrEq2);
            CFOO(LTRApos1Pos1Ptr, LTRApos1Pos1Binding, LTRAposNode1, LTRAposNode1);
            CFOO(LTRAneg1Neg1Ptr, LTRAneg1Neg1Binding, LTRAnegNode1, LTRAnegNode1);
            CFOO(LTRApos2Pos2Ptr, LTRApos2Pos2Binding, LTRAposNode2, LTRAposNode2);
            CFOO(LTRAneg2Neg2Ptr, LTRAneg2Neg2Binding, LTRAnegNode2, LTRAnegNode2);
        }
    }

    return (OK) ;
}
