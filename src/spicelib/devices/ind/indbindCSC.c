/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
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
            XFOO(INDposIbrPtr, INDposIbrBinding, INDposNode, INDbrEq);
            XFOO(INDnegIbrPtr, INDnegIbrBinding, INDnegNode, INDbrEq);
            XFOO(INDibrNegPtr, INDibrNegBinding, INDbrEq, INDnegNode);
            XFOO(INDibrPosPtr, INDibrPosBinding, INDbrEq, INDposNode);
            XFOO(INDibrIbrPtr, INDibrIbrBinding, INDbrEq, INDbrEq);
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
            BFOO(INDposIbrPtr, INDposIbrBinding, INDposNode, INDbrEq);
            BFOO(INDnegIbrPtr, INDnegIbrBinding, INDnegNode, INDbrEq);
            BFOO(INDibrNegPtr, INDibrNegBinding, INDbrEq, INDnegNode);
            BFOO(INDibrPosPtr, INDibrPosBinding, INDbrEq, INDposNode);
            BFOO(INDibrIbrPtr, INDibrIbrBinding, INDbrEq, INDbrEq);
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
            CFOO(INDposIbrPtr, INDposIbrBinding, INDposNode, INDbrEq);
            CFOO(INDnegIbrPtr, INDnegIbrBinding, INDnegNode, INDbrEq);
            CFOO(INDibrNegPtr, INDibrNegBinding, INDbrEq, INDnegNode);
            CFOO(INDibrPosPtr, INDibrPosBinding, INDbrEq, INDposNode);
            CFOO(INDibrIbrPtr, INDibrIbrBinding, INDbrEq, INDbrEq);
        }
    }

    return (OK) ;
}
