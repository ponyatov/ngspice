/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "numddefs.h"
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
NUMDbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMDmodel *model = (NUMDmodel *)inModel ;
    NUMDinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the NUMD models */
    for ( ; model != NULL ; model = model->NUMDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMDinstances ; here != NULL ; here = here->NUMDnextInstance)
        {
            XFOO(NUMDposPosPtr, NUMDposPosBinding, NUMDposNode, NUMDposNode);
            XFOO(NUMDnegNegPtr, NUMDnegNegBinding, NUMDnegNode, NUMDnegNode);
            XFOO(NUMDnegPosPtr, NUMDnegPosBinding, NUMDnegNode, NUMDposNode);
            XFOO(NUMDposNegPtr, NUMDposNegBinding, NUMDposNode, NUMDnegNode);
        }
    }

    return (OK) ;
}

int
NUMDbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMDmodel *model = (NUMDmodel *)inModel ;
    NUMDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMD models */
    for ( ; model != NULL ; model = model->NUMDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMDinstances ; here != NULL ; here = here->NUMDnextInstance)
        {
            BFOO(NUMDposPosPtr, NUMDposPosBinding, NUMDposNode, NUMDposNode);
            BFOO(NUMDnegNegPtr, NUMDnegNegBinding, NUMDnegNode, NUMDnegNode);
            BFOO(NUMDnegPosPtr, NUMDnegPosBinding, NUMDnegNode, NUMDposNode);
            BFOO(NUMDposNegPtr, NUMDposNegBinding, NUMDposNode, NUMDnegNode);
        }
    }

    return (OK) ;
}

int
NUMDbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMDmodel *model = (NUMDmodel *)inModel ;
    NUMDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMD models */
    for ( ; model != NULL ; model = model->NUMDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMDinstances ; here != NULL ; here = here->NUMDnextInstance)
        {
            CFOO(NUMDposPosPtr, NUMDposPosBinding, NUMDposNode, NUMDposNode);
            CFOO(NUMDnegNegPtr, NUMDnegNegBinding, NUMDnegNode, NUMDnegNode);
            CFOO(NUMDnegPosPtr, NUMDnegPosBinding, NUMDnegNode, NUMDposNode);
            CFOO(NUMDposNegPtr, NUMDposNegBinding, NUMDposNode, NUMDnegNode);
        }
    }

    return (OK) ;
}
