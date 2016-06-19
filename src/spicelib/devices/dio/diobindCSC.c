/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "diodefs.h"
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
DIObindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    DIOmodel *model = (DIOmodel *)inModel ;
    DIOinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the DIO models */
    for ( ; model != NULL ; model = model->DIOnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->DIOinstances ; here != NULL ; here = here->DIOnextInstance)
        {
            XFOO(DIOposPosPrimePtr, DIOposPosPrimeBinding, DIOposNode, DIOposPrimeNode);
            XFOO(DIOnegPosPrimePtr, DIOnegPosPrimeBinding, DIOnegNode, DIOposPrimeNode);
            XFOO(DIOposPrimePosPtr, DIOposPrimePosBinding, DIOposPrimeNode, DIOposNode);
            XFOO(DIOposPrimeNegPtr, DIOposPrimeNegBinding, DIOposPrimeNode, DIOnegNode);
            XFOO(DIOposPosPtr, DIOposPosBinding, DIOposNode, DIOposNode);
            XFOO(DIOnegNegPtr, DIOnegNegBinding, DIOnegNode, DIOnegNode);
            XFOO(DIOposPrimePosPrimePtr, DIOposPrimePosPrimeBinding, DIOposPrimeNode, DIOposPrimeNode);
        }
    }

    return (OK) ;
}

int
DIObindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    DIOmodel *model = (DIOmodel *)inModel ;
    DIOinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the DIO models */
    for ( ; model != NULL ; model = model->DIOnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->DIOinstances ; here != NULL ; here = here->DIOnextInstance)
        {
            BFOO(DIOposPosPrimePtr, DIOposPosPrimeBinding, DIOposNode, DIOposPrimeNode);
            BFOO(DIOnegPosPrimePtr, DIOnegPosPrimeBinding, DIOnegNode, DIOposPrimeNode);
            BFOO(DIOposPrimePosPtr, DIOposPrimePosBinding, DIOposPrimeNode, DIOposNode);
            BFOO(DIOposPrimeNegPtr, DIOposPrimeNegBinding, DIOposPrimeNode, DIOnegNode);
            BFOO(DIOposPosPtr, DIOposPosBinding, DIOposNode, DIOposNode);
            BFOO(DIOnegNegPtr, DIOnegNegBinding, DIOnegNode, DIOnegNode);
            BFOO(DIOposPrimePosPrimePtr, DIOposPrimePosPrimeBinding, DIOposPrimeNode, DIOposPrimeNode);
        }
    }

    return (OK) ;
}

int
DIObindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    DIOmodel *model = (DIOmodel *)inModel ;
    DIOinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the DIO models */
    for ( ; model != NULL ; model = model->DIOnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->DIOinstances ; here != NULL ; here = here->DIOnextInstance)
        {
            CFOO(DIOposPosPrimePtr, DIOposPosPrimeBinding, DIOposNode, DIOposPrimeNode);
            CFOO(DIOnegPosPrimePtr, DIOnegPosPrimeBinding, DIOnegNode, DIOposPrimeNode);
            CFOO(DIOposPrimePosPtr, DIOposPrimePosBinding, DIOposPrimeNode, DIOposNode);
            CFOO(DIOposPrimeNegPtr, DIOposPrimeNegBinding, DIOposPrimeNode, DIOnegNode);
            CFOO(DIOposPosPtr, DIOposPosBinding, DIOposNode, DIOposNode);
            CFOO(DIOnegNegPtr, DIOnegNegBinding, DIOnegNode, DIOnegNode);
            CFOO(DIOposPrimePosPrimePtr, DIOposPrimePosPrimeBinding, DIOposPrimeNode, DIOposPrimeNode);
        }
    }

    return (OK) ;
}
