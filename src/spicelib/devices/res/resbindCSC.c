/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "resdefs.h"
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
RESbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    RESmodel *model = (RESmodel *)inModel ;
    RESinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the RES models */
    for ( ; model != NULL ; model = model->RESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->RESinstances ; here != NULL ; here = here->RESnextInstance)
        {
            XFOO(RESposPosPtr, RESposPosBinding, RESposNode, RESposNode);
            XFOO(RESnegNegPtr, RESnegNegBinding, RESnegNode, RESnegNode);
            XFOO(RESposNegPtr, RESposNegBinding, RESposNode, RESnegNode);
            XFOO(RESnegPosPtr, RESnegPosBinding, RESnegNode, RESposNode);
        }
    }

    return (OK) ;
}

int
RESbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    RESmodel *model = (RESmodel *)inModel ;
    RESinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the RES models */
    for ( ; model != NULL ; model = model->RESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->RESinstances ; here != NULL ; here = here->RESnextInstance)
        {
            BFOO(RESposPosPtr, RESposPosBinding, RESposNode, RESposNode);
            BFOO(RESnegNegPtr, RESnegNegBinding, RESnegNode, RESnegNode);
            BFOO(RESposNegPtr, RESposNegBinding, RESposNode, RESnegNode);
            BFOO(RESnegPosPtr, RESnegPosBinding, RESnegNode, RESposNode);
        }
    }

    return (OK) ;
}

int
RESbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    RESmodel *model = (RESmodel *)inModel ;
    RESinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the RES models */
    for ( ; model != NULL ; model = model->RESnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->RESinstances ; here != NULL ; here = here->RESnextInstance)
        {
            CFOO(RESposPosPtr, RESposPosBinding, RESposNode, RESposNode);
            CFOO(RESnegNegPtr, RESnegNegBinding, RESnegNode, RESnegNode);
            CFOO(RESposNegPtr, RESposNegBinding, RESposNode, RESnegNode);
            CFOO(RESnegPosPtr, RESnegPosBinding, RESnegNode, RESposNode);
        }
    }

    return (OK) ;
}
