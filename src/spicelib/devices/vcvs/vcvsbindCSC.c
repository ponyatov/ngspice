/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vcvsdefs.h"
#include "ngspice/sperror.h"

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
            if ((here-> VCVSposNode != 0) && (here-> VCVSbranch != 0))
            {
                i = here->VCVSposIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSposIbrBinding = matched ;
                here->VCVSposIbrPtr = matched->CSC ;
            }

            if ((here-> VCVSnegNode != 0) && (here-> VCVSbranch != 0))
            {
                i = here->VCVSnegIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSnegIbrBinding = matched ;
                here->VCVSnegIbrPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVSnegNode != 0))
            {
                i = here->VCVSibrNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrNegBinding = matched ;
                here->VCVSibrNegPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVSposNode != 0))
            {
                i = here->VCVSibrPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrPosBinding = matched ;
                here->VCVSibrPosPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVScontPosNode != 0))
            {
                i = here->VCVSibrContPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrContPosBinding = matched ;
                here->VCVSibrContPosPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVScontNegNode != 0))
            {
                i = here->VCVSibrContNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrContNegBinding = matched ;
                here->VCVSibrContNegPtr = matched->CSC ;
            }

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
            if ((here-> VCVSposNode != 0) && (here-> VCVSbranch != 0))
                here->VCVSposIbrPtr = here->VCVSposIbrBinding->CSC_Complex ;

            if ((here-> VCVSnegNode != 0) && (here-> VCVSbranch != 0))
                here->VCVSnegIbrPtr = here->VCVSnegIbrBinding->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSnegNode != 0))
                here->VCVSibrNegPtr = here->VCVSibrNegBinding->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSposNode != 0))
                here->VCVSibrPosPtr = here->VCVSibrPosBinding->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontPosNode != 0))
                here->VCVSibrContPosPtr = here->VCVSibrContPosBinding->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontNegNode != 0))
                here->VCVSibrContNegPtr = here->VCVSibrContNegBinding->CSC_Complex ;

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
            if ((here-> VCVSposNode != 0) && (here-> VCVSbranch != 0))
                here->VCVSposIbrPtr = here->VCVSposIbrBinding->CSC ;

            if ((here-> VCVSnegNode != 0) && (here-> VCVSbranch != 0))
                here->VCVSnegIbrPtr = here->VCVSnegIbrBinding->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSnegNode != 0))
                here->VCVSibrNegPtr = here->VCVSibrNegBinding->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSposNode != 0))
                here->VCVSibrPosPtr = here->VCVSibrPosBinding->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontPosNode != 0))
                here->VCVSibrContPosPtr = here->VCVSibrContPosBinding->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontNegNode != 0))
                here->VCVSibrContNegPtr = here->VCVSibrContNegBinding->CSC ;

        }
    }

    return (OK) ;
}
