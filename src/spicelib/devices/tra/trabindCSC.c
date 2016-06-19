/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "tradefs.h"
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
TRAbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    TRAmodel *model = (TRAmodel *)inModel ;
    TRAinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the TRA models */
    for ( ; model != NULL ; model = model->TRAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TRAinstances ; here != NULL ; here = here->TRAnextInstance)
        {
            XFOO(TRAibr1Ibr2Ptr, TRAibr1Ibr2Binding, TRAbrEq1, TRAbrEq2);
            XFOO(TRAibr1Int1Ptr, TRAibr1Int1Binding, TRAbrEq1, TRAintNode1);
            XFOO(TRAibr1Neg1Ptr, TRAibr1Neg1Binding, TRAbrEq1, TRAnegNode1);
            XFOO(TRAibr1Neg2Ptr, TRAibr1Neg2Binding, TRAbrEq1, TRAnegNode2);
            XFOO(TRAibr1Pos2Ptr, TRAibr1Pos2Binding, TRAbrEq1, TRAposNode2);
            XFOO(TRAibr2Ibr1Ptr, TRAibr2Ibr1Binding, TRAbrEq2, TRAbrEq1);
            XFOO(TRAibr2Int2Ptr, TRAibr2Int2Binding, TRAbrEq2, TRAintNode2);
            XFOO(TRAibr2Neg1Ptr, TRAibr2Neg1Binding, TRAbrEq2, TRAnegNode1);
            XFOO(TRAibr2Neg2Ptr, TRAibr2Neg2Binding, TRAbrEq2, TRAnegNode2);
            XFOO(TRAibr2Pos1Ptr, TRAibr2Pos1Binding, TRAbrEq2, TRAposNode1);
            XFOO(TRAint1Ibr1Ptr, TRAint1Ibr1Binding, TRAintNode1, TRAbrEq1);
            XFOO(TRAint1Int1Ptr, TRAint1Int1Binding, TRAintNode1, TRAintNode1);
            XFOO(TRAint1Pos1Ptr, TRAint1Pos1Binding, TRAintNode1, TRAposNode1);
            XFOO(TRAint2Ibr2Ptr, TRAint2Ibr2Binding, TRAintNode2, TRAbrEq2);
            XFOO(TRAint2Int2Ptr, TRAint2Int2Binding, TRAintNode2, TRAintNode2);
            XFOO(TRAint2Pos2Ptr, TRAint2Pos2Binding, TRAintNode2, TRAposNode2);
            XFOO(TRAneg1Ibr1Ptr, TRAneg1Ibr1Binding, TRAnegNode1, TRAbrEq1);
            XFOO(TRAneg2Ibr2Ptr, TRAneg2Ibr2Binding, TRAnegNode2, TRAbrEq2);
            XFOO(TRApos1Int1Ptr, TRApos1Int1Binding, TRAposNode1, TRAintNode1);
            XFOO(TRApos1Pos1Ptr, TRApos1Pos1Binding, TRAposNode1, TRAposNode1);
            XFOO(TRApos2Int2Ptr, TRApos2Int2Binding, TRAposNode2, TRAintNode2);
            XFOO(TRApos2Pos2Ptr, TRApos2Pos2Binding, TRAposNode2, TRAposNode2);
        }
    }

    return (OK) ;
}

int
TRAbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    TRAmodel *model = (TRAmodel *)inModel ;
    TRAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the TRA models */
    for ( ; model != NULL ; model = model->TRAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TRAinstances ; here != NULL ; here = here->TRAnextInstance)
        {
            BFOO(TRAibr1Ibr2Ptr, TRAibr1Ibr2Binding, TRAbrEq1, TRAbrEq2);
            BFOO(TRAibr1Int1Ptr, TRAibr1Int1Binding, TRAbrEq1, TRAintNode1);
            BFOO(TRAibr1Neg1Ptr, TRAibr1Neg1Binding, TRAbrEq1, TRAnegNode1);
            BFOO(TRAibr1Neg2Ptr, TRAibr1Neg2Binding, TRAbrEq1, TRAnegNode2);
            BFOO(TRAibr1Pos2Ptr, TRAibr1Pos2Binding, TRAbrEq1, TRAposNode2);
            BFOO(TRAibr2Ibr1Ptr, TRAibr2Ibr1Binding, TRAbrEq2, TRAbrEq1);
            BFOO(TRAibr2Int2Ptr, TRAibr2Int2Binding, TRAbrEq2, TRAintNode2);
            BFOO(TRAibr2Neg1Ptr, TRAibr2Neg1Binding, TRAbrEq2, TRAnegNode1);
            BFOO(TRAibr2Neg2Ptr, TRAibr2Neg2Binding, TRAbrEq2, TRAnegNode2);
            BFOO(TRAibr2Pos1Ptr, TRAibr2Pos1Binding, TRAbrEq2, TRAposNode1);
            BFOO(TRAint1Ibr1Ptr, TRAint1Ibr1Binding, TRAintNode1, TRAbrEq1);
            BFOO(TRAint1Int1Ptr, TRAint1Int1Binding, TRAintNode1, TRAintNode1);
            BFOO(TRAint1Pos1Ptr, TRAint1Pos1Binding, TRAintNode1, TRAposNode1);
            BFOO(TRAint2Ibr2Ptr, TRAint2Ibr2Binding, TRAintNode2, TRAbrEq2);
            BFOO(TRAint2Int2Ptr, TRAint2Int2Binding, TRAintNode2, TRAintNode2);
            BFOO(TRAint2Pos2Ptr, TRAint2Pos2Binding, TRAintNode2, TRAposNode2);
            BFOO(TRAneg1Ibr1Ptr, TRAneg1Ibr1Binding, TRAnegNode1, TRAbrEq1);
            BFOO(TRAneg2Ibr2Ptr, TRAneg2Ibr2Binding, TRAnegNode2, TRAbrEq2);
            BFOO(TRApos1Int1Ptr, TRApos1Int1Binding, TRAposNode1, TRAintNode1);
            BFOO(TRApos1Pos1Ptr, TRApos1Pos1Binding, TRAposNode1, TRAposNode1);
            BFOO(TRApos2Int2Ptr, TRApos2Int2Binding, TRAposNode2, TRAintNode2);
            BFOO(TRApos2Pos2Ptr, TRApos2Pos2Binding, TRAposNode2, TRAposNode2);
        }
    }

    return (OK) ;
}

int
TRAbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    TRAmodel *model = (TRAmodel *)inModel ;
    TRAinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the TRA models */
    for ( ; model != NULL ; model = model->TRAnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->TRAinstances ; here != NULL ; here = here->TRAnextInstance)
        {
            CFOO(TRAibr1Ibr2Ptr, TRAibr1Ibr2Binding, TRAbrEq1, TRAbrEq2);
            CFOO(TRAibr1Int1Ptr, TRAibr1Int1Binding, TRAbrEq1, TRAintNode1);
            CFOO(TRAibr1Neg1Ptr, TRAibr1Neg1Binding, TRAbrEq1, TRAnegNode1);
            CFOO(TRAibr1Neg2Ptr, TRAibr1Neg2Binding, TRAbrEq1, TRAnegNode2);
            CFOO(TRAibr1Pos2Ptr, TRAibr1Pos2Binding, TRAbrEq1, TRAposNode2);
            CFOO(TRAibr2Ibr1Ptr, TRAibr2Ibr1Binding, TRAbrEq2, TRAbrEq1);
            CFOO(TRAibr2Int2Ptr, TRAibr2Int2Binding, TRAbrEq2, TRAintNode2);
            CFOO(TRAibr2Neg1Ptr, TRAibr2Neg1Binding, TRAbrEq2, TRAnegNode1);
            CFOO(TRAibr2Neg2Ptr, TRAibr2Neg2Binding, TRAbrEq2, TRAnegNode2);
            CFOO(TRAibr2Pos1Ptr, TRAibr2Pos1Binding, TRAbrEq2, TRAposNode1);
            CFOO(TRAint1Ibr1Ptr, TRAint1Ibr1Binding, TRAintNode1, TRAbrEq1);
            CFOO(TRAint1Int1Ptr, TRAint1Int1Binding, TRAintNode1, TRAintNode1);
            CFOO(TRAint1Pos1Ptr, TRAint1Pos1Binding, TRAintNode1, TRAposNode1);
            CFOO(TRAint2Ibr2Ptr, TRAint2Ibr2Binding, TRAintNode2, TRAbrEq2);
            CFOO(TRAint2Int2Ptr, TRAint2Int2Binding, TRAintNode2, TRAintNode2);
            CFOO(TRAint2Pos2Ptr, TRAint2Pos2Binding, TRAintNode2, TRAposNode2);
            CFOO(TRAneg1Ibr1Ptr, TRAneg1Ibr1Binding, TRAnegNode1, TRAbrEq1);
            CFOO(TRAneg2Ibr2Ptr, TRAneg2Ibr2Binding, TRAnegNode2, TRAbrEq2);
            CFOO(TRApos1Int1Ptr, TRApos1Int1Binding, TRAposNode1, TRAintNode1);
            CFOO(TRApos1Pos1Ptr, TRApos1Pos1Binding, TRAposNode1, TRAposNode1);
            CFOO(TRApos2Int2Ptr, TRApos2Int2Binding, TRAposNode2, TRAintNode2);
            CFOO(TRApos2Pos2Ptr, TRApos2Pos2Binding, TRAposNode2, TRAposNode2);
        }
    }

    return (OK) ;
}
