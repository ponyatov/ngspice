/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vcvsdefs.h"
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
VCVSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    VCVSmodel *model = (VCVSmodel *)inModel ;
    VCVSinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the VCVS models */
    for ( ; model != NULL ; model = model->VCVSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VCVSinstances ; here != NULL ; here = here->VCVSnextInstance)
        {
            XFOO(VCVSposIbrPtr, VCVSposIbrBinding, VCVSposNode, VCVSbranch);
            XFOO(VCVSnegIbrPtr, VCVSnegIbrBinding, VCVSnegNode, VCVSbranch);
            XFOO(VCVSibrNegPtr, VCVSibrNegBinding, VCVSbranch, VCVSnegNode);
            XFOO(VCVSibrPosPtr, VCVSibrPosBinding, VCVSbranch, VCVSposNode);
            XFOO(VCVSibrContPosPtr, VCVSibrContPosBinding, VCVSbranch, VCVScontPosNode);
            XFOO(VCVSibrContNegPtr, VCVSibrContNegBinding, VCVSbranch, VCVScontNegNode);
        }
    }

    return (OK) ;
}

int
VCVSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    VCVSmodel *model = (VCVSmodel *)inModel ;
    VCVSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VCVS models */
    for ( ; model != NULL ; model = model->VCVSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VCVSinstances ; here != NULL ; here = here->VCVSnextInstance)
        {
            BFOO(VCVSposIbrPtr, VCVSposIbrBinding, VCVSposNode, VCVSbranch);
            BFOO(VCVSnegIbrPtr, VCVSnegIbrBinding, VCVSnegNode, VCVSbranch);
            BFOO(VCVSibrNegPtr, VCVSibrNegBinding, VCVSbranch, VCVSnegNode);
            BFOO(VCVSibrPosPtr, VCVSibrPosBinding, VCVSbranch, VCVSposNode);
            BFOO(VCVSibrContPosPtr, VCVSibrContPosBinding, VCVSbranch, VCVScontPosNode);
            BFOO(VCVSibrContNegPtr, VCVSibrContNegBinding, VCVSbranch, VCVScontNegNode);
        }
    }

    return (OK) ;
}

int
VCVSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    VCVSmodel *model = (VCVSmodel *)inModel ;
    VCVSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VCVS models */
    for ( ; model != NULL ; model = model->VCVSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VCVSinstances ; here != NULL ; here = here->VCVSnextInstance)
        {
            CFOO(VCVSposIbrPtr, VCVSposIbrBinding, VCVSposNode, VCVSbranch);
            CFOO(VCVSnegIbrPtr, VCVSnegIbrBinding, VCVSnegNode, VCVSbranch);
            CFOO(VCVSibrNegPtr, VCVSibrNegBinding, VCVSbranch, VCVSnegNode);
            CFOO(VCVSibrPosPtr, VCVSibrPosBinding, VCVSbranch, VCVSposNode);
            CFOO(VCVSibrContPosPtr, VCVSibrContPosBinding, VCVSbranch, VCVScontPosNode);
            CFOO(VCVSibrContNegPtr, VCVSibrContNegBinding, VCVSbranch, VCVScontNegNode);
        }
    }

    return (OK) ;
}
