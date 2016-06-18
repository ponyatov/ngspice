/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
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
INDbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    INDmodel *model = (INDmodel *)inModel ;
    INDinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the IND models */
    for ( ; model != NULL ; model = model->INDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->INDinstances ; here != NULL ; here = here->INDnextInstance)
        {
            if ((here->INDposNode != 0) && (here->INDbrEq != 0))
            {
                i = here->INDposIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->INDposIbrptrStructPtr = matched ;
                here->INDposIbrPtr = matched->CSC ;
            }

            if ((here->INDnegNode != 0) && (here->INDbrEq != 0))
            {
                i = here->INDnegIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->INDnegIbrptrStructPtr = matched ;
                here->INDnegIbrPtr = matched->CSC ;
            }

            if ((here->INDbrEq != 0) && (here->INDnegNode != 0))
            {
                i = here->INDibrNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->INDibrNegptrStructPtr = matched ;
                here->INDibrNegPtr = matched->CSC ;
            }

            if ((here->INDbrEq != 0) && (here->INDposNode != 0))
            {
                i = here->INDibrPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->INDibrPosptrStructPtr = matched ;
                here->INDibrPosPtr = matched->CSC ;
            }

            if ((here->INDbrEq != 0) && (here->INDbrEq != 0))
            {
                i = here->INDibrIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->INDibrIbrptrStructPtr = matched ;
                here->INDibrIbrPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
INDbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    INDmodel *model = (INDmodel *)inModel ;
    INDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the IND models */
    for ( ; model != NULL ; model = model->INDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->INDinstances ; here != NULL ; here = here->INDnextInstance)
        {
            if ((here->INDposNode != 0) && (here->INDbrEq != 0))
                here->INDposIbrPtr = here->INDposIbrptrStructPtr->CSC_Complex ;

            if ((here->INDnegNode != 0) && (here->INDbrEq != 0))
                here->INDnegIbrPtr = here->INDnegIbrptrStructPtr->CSC_Complex ;

            if ((here->INDbrEq != 0) && (here->INDnegNode != 0))
                here->INDibrNegPtr = here->INDibrNegptrStructPtr->CSC_Complex ;

            if ((here->INDbrEq != 0) && (here->INDposNode != 0))
                here->INDibrPosPtr = here->INDibrPosptrStructPtr->CSC_Complex ;

            if ((here->INDbrEq != 0) && (here->INDbrEq != 0))
                here->INDibrIbrPtr = here->INDibrIbrptrStructPtr->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
INDbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    INDmodel *model = (INDmodel *)inModel ;
    INDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the IND models */
    for ( ; model != NULL ; model = model->INDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->INDinstances ; here != NULL ; here = here->INDnextInstance)
        {
            if ((here->INDposNode != 0) && (here->INDbrEq != 0))
                here->INDposIbrPtr = here->INDposIbrptrStructPtr->CSC ;

            if ((here->INDnegNode != 0) && (here->INDbrEq != 0))
                here->INDnegIbrPtr = here->INDnegIbrptrStructPtr->CSC ;

            if ((here->INDbrEq != 0) && (here->INDnegNode != 0))
                here->INDibrNegPtr = here->INDibrNegptrStructPtr->CSC ;

            if ((here->INDbrEq != 0) && (here->INDposNode != 0))
                here->INDibrPosPtr = here->INDibrPosptrStructPtr->CSC ;

            if ((here->INDbrEq != 0) && (here->INDbrEq != 0))
                here->INDibrIbrPtr = here->INDibrIbrptrStructPtr->CSC ;

        }
    }

    return (OK) ;
}
