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
                here->VCVSposIbrptrStructPtr = matched ;
                here->VCVSposIbrPtr = matched->CSC ;
            }

            if ((here-> VCVSnegNode != 0) && (here-> VCVSbranch != 0))
            {
                i = here->VCVSnegIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSnegIbrptrStructPtr = matched ;
                here->VCVSnegIbrPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVSnegNode != 0))
            {
                i = here->VCVSibrNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrNegptrStructPtr = matched ;
                here->VCVSibrNegPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVSposNode != 0))
            {
                i = here->VCVSibrPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrPosptrStructPtr = matched ;
                here->VCVSibrPosPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVScontPosNode != 0))
            {
                i = here->VCVSibrContPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrContPosptrStructPtr = matched ;
                here->VCVSibrContPosPtr = matched->CSC ;
            }

            if ((here-> VCVSbranch != 0) && (here-> VCVScontNegNode != 0))
            {
                i = here->VCVSibrContNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VCVSibrContNegptrStructPtr = matched ;
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
                here->VCVSposIbrPtr = here->VCVSposIbrptrStructPtr->CSC_Complex ;

            if ((here-> VCVSnegNode != 0) && (here-> VCVSbranch != 0))
                here->VCVSnegIbrPtr = here->VCVSnegIbrptrStructPtr->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSnegNode != 0))
                here->VCVSibrNegPtr = here->VCVSibrNegptrStructPtr->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSposNode != 0))
                here->VCVSibrPosPtr = here->VCVSibrPosptrStructPtr->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontPosNode != 0))
                here->VCVSibrContPosPtr = here->VCVSibrContPosptrStructPtr->CSC_Complex ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontNegNode != 0))
                here->VCVSibrContNegPtr = here->VCVSibrContNegptrStructPtr->CSC_Complex ;

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
                here->VCVSposIbrPtr = here->VCVSposIbrptrStructPtr->CSC ;

            if ((here-> VCVSnegNode != 0) && (here-> VCVSbranch != 0))
                here->VCVSnegIbrPtr = here->VCVSnegIbrptrStructPtr->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSnegNode != 0))
                here->VCVSibrNegPtr = here->VCVSibrNegptrStructPtr->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVSposNode != 0))
                here->VCVSibrPosPtr = here->VCVSibrPosptrStructPtr->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontPosNode != 0))
                here->VCVSibrContPosPtr = here->VCVSibrContPosptrStructPtr->CSC ;

            if ((here-> VCVSbranch != 0) && (here-> VCVScontNegNode != 0))
                here->VCVSibrContNegPtr = here->VCVSibrContNegptrStructPtr->CSC ;

        }
    }

    return (OK) ;
}
