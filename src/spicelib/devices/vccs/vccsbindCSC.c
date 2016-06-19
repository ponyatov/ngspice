/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vccsdefs.h"
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
VCCSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    VCCSmodel *model = (VCCSmodel *)inModel ;
    VCCSinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the VCCS models */
    for ( ; model != NULL ; model = model->VCCSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VCCSinstances ; here != NULL ; here = here->VCCSnextInstance)
        {
            XFOO(VCCSposContPosPtr, VCCSposContPosBinding, VCCSposNode, VCCScontPosNode);
            XFOO(VCCSposContNegPtr, VCCSposContNegBinding, VCCSposNode, VCCScontNegNode);
            XFOO(VCCSnegContPosPtr, VCCSnegContPosBinding, VCCSnegNode, VCCScontPosNode);
            XFOO(VCCSnegContNegPtr, VCCSnegContNegBinding, VCCSnegNode, VCCScontNegNode);
        }
    }

    return (OK) ;
}

int
VCCSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    VCCSmodel *model = (VCCSmodel *)inModel ;
    VCCSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VCCS models */
    for ( ; model != NULL ; model = model->VCCSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VCCSinstances ; here != NULL ; here = here->VCCSnextInstance)
        {
            BFOO(VCCSposContPosPtr, VCCSposContPosBinding, VCCSposNode, VCCScontPosNode);
            BFOO(VCCSposContNegPtr, VCCSposContNegBinding, VCCSposNode, VCCScontNegNode);
            BFOO(VCCSnegContPosPtr, VCCSnegContPosBinding, VCCSnegNode, VCCScontPosNode);
            BFOO(VCCSnegContNegPtr, VCCSnegContNegBinding, VCCSnegNode, VCCScontNegNode);
        }
    }

    return (OK) ;
}

int
VCCSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    VCCSmodel *model = (VCCSmodel *)inModel ;
    VCCSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VCCS models */
    for ( ; model != NULL ; model = model->VCCSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VCCSinstances ; here != NULL ; here = here->VCCSnextInstance)
        {
            CFOO(VCCSposContPosPtr, VCCSposContPosBinding, VCCSposNode, VCCScontPosNode);
            CFOO(VCCSposContNegPtr, VCCSposContNegBinding, VCCSposNode, VCCScontNegNode);
            CFOO(VCCSnegContPosPtr, VCCSnegContPosBinding, VCCSnegNode, VCCScontPosNode);
            CFOO(VCCSnegContNegPtr, VCCSnegContNegBinding, VCCSnegNode, VCCScontNegNode);
        }
    }

    return (OK) ;
}
