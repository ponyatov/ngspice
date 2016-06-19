/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "ccvsdefs.h"
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
CCVSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CCVSmodel *model = (CCVSmodel *)inModel ;
    CCVSinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the CCVS models */
    for ( ; model != NULL ; model = model->CCVSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CCVSinstances ; here != NULL ; here = here->CCVSnextInstance)
        {
            XFOO(CCVSposIbrPtr, CCVSposIbrBinding, CCVSposNode, CCVSbranch);
            XFOO(CCVSnegIbrPtr, CCVSnegIbrBinding, CCVSnegNode, CCVSbranch);
            XFOO(CCVSibrNegPtr, CCVSibrNegBinding, CCVSbranch, CCVSnegNode);
            XFOO(CCVSibrPosPtr, CCVSibrPosBinding, CCVSbranch, CCVSposNode);
            XFOO(CCVSibrContBrPtr, CCVSibrContBrBinding, CCVSbranch, CCVScontBranch);
        }
    }

    return (OK) ;
}

int
CCVSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CCVSmodel *model = (CCVSmodel *)inModel ;
    CCVSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CCVS models */
    for ( ; model != NULL ; model = model->CCVSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CCVSinstances ; here != NULL ; here = here->CCVSnextInstance)
        {
            BFOO(CCVSposIbrPtr, CCVSposIbrBinding, CCVSposNode, CCVSbranch);
            BFOO(CCVSnegIbrPtr, CCVSnegIbrBinding, CCVSnegNode, CCVSbranch);
            BFOO(CCVSibrNegPtr, CCVSibrNegBinding, CCVSbranch, CCVSnegNode);
            BFOO(CCVSibrPosPtr, CCVSibrPosBinding, CCVSbranch, CCVSposNode);
            BFOO(CCVSibrContBrPtr, CCVSibrContBrBinding, CCVSbranch, CCVScontBranch);
        }
    }

    return (OK) ;
}

int
CCVSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CCVSmodel *model = (CCVSmodel *)inModel ;
    CCVSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CCVS models */
    for ( ; model != NULL ; model = model->CCVSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CCVSinstances ; here != NULL ; here = here->CCVSnextInstance)
        {
            CFOO(CCVSposIbrPtr, CCVSposIbrBinding, CCVSposNode, CCVSbranch);
            CFOO(CCVSnegIbrPtr, CCVSnegIbrBinding, CCVSnegNode, CCVSbranch);
            CFOO(CCVSibrNegPtr, CCVSibrNegBinding, CCVSbranch, CCVSnegNode);
            CFOO(CCVSibrPosPtr, CCVSibrPosBinding, CCVSbranch, CCVSposNode);
            CFOO(CCVSibrContBrPtr, CCVSibrContBrBinding, CCVSbranch, CCVScontBranch);
        }
    }

    return (OK) ;
}
