/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "nbjtdefs.h"
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
NBJTbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJTmodel *model = (NBJTmodel *)inModel ;
    NBJTinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the NBJT models */
    for ( ; model != NULL ; model = model->NBJTnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NBJTinstances ; here != NULL ; here = here->NBJTnextInstance)
        {
            XFOO(NBJTcolColPtr, NBJTcolColBinding, NBJTcolNode, NBJTcolNode);
            XFOO(NBJTbaseBasePtr, NBJTbaseBaseBinding, NBJTbaseNode, NBJTbaseNode);
            XFOO(NBJTemitEmitPtr, NBJTemitEmitBinding, NBJTemitNode, NBJTemitNode);
            XFOO(NBJTcolBasePtr, NBJTcolBaseBinding, NBJTcolNode, NBJTbaseNode);
            XFOO(NBJTcolEmitPtr, NBJTcolEmitBinding, NBJTcolNode, NBJTemitNode);
            XFOO(NBJTbaseColPtr, NBJTbaseColBinding, NBJTbaseNode, NBJTcolNode);
            XFOO(NBJTbaseEmitPtr, NBJTbaseEmitBinding, NBJTbaseNode, NBJTemitNode);
            XFOO(NBJTemitColPtr, NBJTemitColBinding, NBJTemitNode, NBJTcolNode);
            XFOO(NBJTemitBasePtr, NBJTemitBaseBinding, NBJTemitNode, NBJTbaseNode);
        }
    }

    return (OK) ;
}

int
NBJTbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJTmodel *model = (NBJTmodel *)inModel ;
    NBJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NBJT models */
    for ( ; model != NULL ; model = model->NBJTnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NBJTinstances ; here != NULL ; here = here->NBJTnextInstance)
        {
            BFOO(NBJTcolColPtr, NBJTcolColBinding, NBJTcolNode, NBJTcolNode);
            BFOO(NBJTbaseBasePtr, NBJTbaseBaseBinding, NBJTbaseNode, NBJTbaseNode);
            BFOO(NBJTemitEmitPtr, NBJTemitEmitBinding, NBJTemitNode, NBJTemitNode);
            BFOO(NBJTcolBasePtr, NBJTcolBaseBinding, NBJTcolNode, NBJTbaseNode);
            BFOO(NBJTcolEmitPtr, NBJTcolEmitBinding, NBJTcolNode, NBJTemitNode);
            BFOO(NBJTbaseColPtr, NBJTbaseColBinding, NBJTbaseNode, NBJTcolNode);
            BFOO(NBJTbaseEmitPtr, NBJTbaseEmitBinding, NBJTbaseNode, NBJTemitNode);
            BFOO(NBJTemitColPtr, NBJTemitColBinding, NBJTemitNode, NBJTcolNode);
            BFOO(NBJTemitBasePtr, NBJTemitBaseBinding, NBJTemitNode, NBJTbaseNode);
        }
    }

    return (OK) ;
}

int
NBJTbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJTmodel *model = (NBJTmodel *)inModel ;
    NBJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NBJT models */
    for ( ; model != NULL ; model = model->NBJTnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NBJTinstances ; here != NULL ; here = here->NBJTnextInstance)
        {
            CFOO(NBJTcolColPtr, NBJTcolColBinding, NBJTcolNode, NBJTcolNode);
            CFOO(NBJTbaseBasePtr, NBJTbaseBaseBinding, NBJTbaseNode, NBJTbaseNode);
            CFOO(NBJTemitEmitPtr, NBJTemitEmitBinding, NBJTemitNode, NBJTemitNode);
            CFOO(NBJTcolBasePtr, NBJTcolBaseBinding, NBJTcolNode, NBJTbaseNode);
            CFOO(NBJTcolEmitPtr, NBJTcolEmitBinding, NBJTcolNode, NBJTemitNode);
            CFOO(NBJTbaseColPtr, NBJTbaseColBinding, NBJTbaseNode, NBJTcolNode);
            CFOO(NBJTbaseEmitPtr, NBJTbaseEmitBinding, NBJTbaseNode, NBJTemitNode);
            CFOO(NBJTemitColPtr, NBJTemitColBinding, NBJTemitNode, NBJTcolNode);
            CFOO(NBJTemitBasePtr, NBJTemitBaseBinding, NBJTemitNode, NBJTbaseNode);
        }
    }

    return (OK) ;
}
