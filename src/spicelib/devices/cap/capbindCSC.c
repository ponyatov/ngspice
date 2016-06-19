/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "capdefs.h"
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
CAPbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = model->CAPnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CAPinstances ; here != NULL ; here = here->CAPnextInstance)
        {
            XFOO(CAPposPosPtr, CAPposPosBinding, CAPposNode, CAPposNode);
            XFOO(CAPnegNegPtr, CAPnegNegBinding, CAPnegNode, CAPnegNode);
            XFOO(CAPposNegPtr, CAPposNegBinding, CAPposNode, CAPnegNode);
            XFOO(CAPnegPosPtr, CAPnegPosBinding, CAPnegNode, CAPposNode);
        }
    }

    return (OK) ;
}

int
CAPbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = model->CAPnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CAPinstances ; here != NULL ; here = here->CAPnextInstance)
        {
            BFOO(CAPposPosPtr, CAPposPosBinding, CAPposNode, CAPposNode);
            BFOO(CAPnegNegPtr, CAPnegNegBinding, CAPnegNode, CAPnegNode);
            BFOO(CAPposNegPtr, CAPposNegBinding, CAPposNode, CAPnegNode);
            BFOO(CAPnegPosPtr, CAPnegPosBinding, CAPnegNode, CAPposNode);
        }
    }

    return (OK) ;
}

int
CAPbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = model->CAPnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CAPinstances ; here != NULL ; here = here->CAPnextInstance)
        {
            CFOO(CAPposPosPtr, CAPposPosBinding, CAPposNode, CAPposNode);
            CFOO(CAPnegNegPtr, CAPnegNegBinding, CAPnegNode, CAPnegNode);
            CFOO(CAPposNegPtr, CAPposNegBinding, CAPposNode, CAPnegNode);
            CFOO(CAPnegPosPtr, CAPnegPosBinding, CAPnegNode, CAPposNode);
        }
    }

    return (OK) ;
}
