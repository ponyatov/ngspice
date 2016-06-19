/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "swdefs.h"
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
SWbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    SWmodel *model = (SWmodel *)inModel ;
    SWinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the SW models */
    for ( ; model != NULL ; model = model->SWnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->SWinstances ; here != NULL ; here = here->SWnextInstance)
        {
            XFOO(SWposPosPtr, SWposPosBinding, SWposNode, SWposNode);
            XFOO(SWposNegPtr, SWposNegBinding, SWposNode, SWnegNode);
            XFOO(SWnegPosPtr, SWnegPosBinding, SWnegNode, SWposNode);
            XFOO(SWnegNegPtr, SWnegNegBinding, SWnegNode, SWnegNode);
        }
    }

    return (OK) ;
}

int
SWbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    SWmodel *model = (SWmodel *)inModel ;
    SWinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the SW models */
    for ( ; model != NULL ; model = model->SWnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->SWinstances ; here != NULL ; here = here->SWnextInstance)
        {
            BFOO(SWposPosPtr, SWposPosBinding, SWposNode, SWposNode);
            BFOO(SWposNegPtr, SWposNegBinding, SWposNode, SWnegNode);
            BFOO(SWnegPosPtr, SWnegPosBinding, SWnegNode, SWposNode);
            BFOO(SWnegNegPtr, SWnegNegBinding, SWnegNode, SWnegNode);
        }
    }

    return (OK) ;
}

int
SWbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    SWmodel *model = (SWmodel *)inModel ;
    SWinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the SW models */
    for ( ; model != NULL ; model = model->SWnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->SWinstances ; here != NULL ; here = here->SWnextInstance)
        {
            CFOO(SWposPosPtr, SWposPosBinding, SWposNode, SWposNode);
            CFOO(SWposNegPtr, SWposNegBinding, SWposNode, SWnegNode);
            CFOO(SWnegPosPtr, SWnegPosBinding, SWnegNode, SWposNode);
            CFOO(SWnegNegPtr, SWnegNegBinding, SWnegNode, SWnegNode);
        }
    }

    return (OK) ;
}
