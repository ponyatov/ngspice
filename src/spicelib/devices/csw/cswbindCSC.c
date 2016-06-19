/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "cswdefs.h"
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
CSWbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CSWmodel *model = (CSWmodel *)inModel ;
    CSWinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the CSW models */
    for ( ; model != NULL ; model = model->CSWnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CSWinstances ; here != NULL ; here = here->CSWnextInstance)
        {
            XFOO(CSWposPosPtr, CSWposPosBinding, CSWposNode, CSWposNode);
            XFOO(CSWposNegPtr, CSWposNegBinding, CSWposNode, CSWnegNode);
            XFOO(CSWnegPosPtr, CSWnegPosBinding, CSWnegNode, CSWposNode);
            XFOO(CSWnegNegPtr, CSWnegNegBinding, CSWnegNode, CSWnegNode);
        }
    }

    return (OK) ;
}

int
CSWbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CSWmodel *model = (CSWmodel *)inModel ;
    CSWinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CSW models */
    for ( ; model != NULL ; model = model->CSWnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CSWinstances ; here != NULL ; here = here->CSWnextInstance)
        {
            BFOO(CSWposPosPtr, CSWposPosBinding, CSWposNode, CSWposNode);
            BFOO(CSWposNegPtr, CSWposNegBinding, CSWposNode, CSWnegNode);
            BFOO(CSWnegPosPtr, CSWnegPosBinding, CSWnegNode, CSWposNode);
            BFOO(CSWnegNegPtr, CSWnegNegBinding, CSWnegNode, CSWnegNode);
        }
    }

    return (OK) ;
}

int
CSWbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CSWmodel *model = (CSWmodel *)inModel ;
    CSWinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CSW models */
    for ( ; model != NULL ; model = model->CSWnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->CSWinstances ; here != NULL ; here = here->CSWnextInstance)
        {
            CFOO(CSWposPosPtr, CSWposPosBinding, CSWposNode, CSWposNode);
            CFOO(CSWposNegPtr, CSWposNegBinding, CSWposNode, CSWnegNode);
            CFOO(CSWnegPosPtr, CSWnegPosBinding, CSWnegNode, CSWposNode);
            CFOO(CSWnegNegPtr, CSWnegNegBinding, CSWnegNode, CSWnegNode);
        }
    }

    return (OK) ;
}
