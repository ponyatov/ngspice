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
            if ((here-> VCCSposNode != 0) && (here-> VCCScontPosNode != 0))
            {
                i = here->VCCSposContPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCCSposContPosBinding = matched ;
                here->VCCSposContPosPtr = matched->CSC ;
            }

            if ((here-> VCCSposNode != 0) && (here-> VCCScontNegNode != 0))
            {
                i = here->VCCSposContNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCCSposContNegBinding = matched ;
                here->VCCSposContNegPtr = matched->CSC ;
            }

            if ((here-> VCCSnegNode != 0) && (here-> VCCScontPosNode != 0))
            {
                i = here->VCCSnegContPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCCSnegContPosBinding = matched ;
                here->VCCSnegContPosPtr = matched->CSC ;
            }

            if ((here-> VCCSnegNode != 0) && (here-> VCCScontNegNode != 0))
            {
                i = here->VCCSnegContNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCCSnegContNegBinding = matched ;
                here->VCCSnegContNegPtr = matched->CSC ;
            }

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
            if ((here-> VCCSposNode != 0) && (here-> VCCScontPosNode != 0))
                here->VCCSposContPosPtr = here->VCCSposContPosBinding->CSC_Complex ;

            if ((here-> VCCSposNode != 0) && (here-> VCCScontNegNode != 0))
                here->VCCSposContNegPtr = here->VCCSposContNegBinding->CSC_Complex ;

            if ((here-> VCCSnegNode != 0) && (here-> VCCScontPosNode != 0))
                here->VCCSnegContPosPtr = here->VCCSnegContPosBinding->CSC_Complex ;

            if ((here-> VCCSnegNode != 0) && (here-> VCCScontNegNode != 0))
                here->VCCSnegContNegPtr = here->VCCSnegContNegBinding->CSC_Complex ;

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
            if ((here-> VCCSposNode != 0) && (here-> VCCScontPosNode != 0))
                here->VCCSposContPosPtr = here->VCCSposContPosBinding->CSC ;

            if ((here-> VCCSposNode != 0) && (here-> VCCScontNegNode != 0))
                here->VCCSposContNegPtr = here->VCCSposContNegBinding->CSC ;

            if ((here-> VCCSnegNode != 0) && (here-> VCCScontPosNode != 0))
                here->VCCSnegContPosPtr = here->VCCSnegContPosBinding->CSC ;

            if ((here-> VCCSnegNode != 0) && (here-> VCCScontNegNode != 0))
                here->VCCSnegContNegPtr = here->VCCSnegContNegBinding->CSC ;

        }
    }

    return (OK) ;
}
