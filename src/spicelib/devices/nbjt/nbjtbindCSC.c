/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "nbjtdefs.h"
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
            if ((here-> NBJTcolNode != 0) && (here-> NBJTcolNode != 0))
            {
                i = here->NBJTcolColPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTcolColBinding = matched ;
                here->NBJTcolColPtr = matched->CSC ;
            }

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTbaseNode != 0))
            {
                i = here->NBJTbaseBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTbaseBaseBinding = matched ;
                here->NBJTbaseBasePtr = matched->CSC ;
            }

            if ((here-> NBJTemitNode != 0) && (here-> NBJTemitNode != 0))
            {
                i = here->NBJTemitEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTemitEmitBinding = matched ;
                here->NBJTemitEmitPtr = matched->CSC ;
            }

            if ((here-> NBJTcolNode != 0) && (here-> NBJTbaseNode != 0))
            {
                i = here->NBJTcolBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTcolBaseBinding = matched ;
                here->NBJTcolBasePtr = matched->CSC ;
            }

            if ((here-> NBJTcolNode != 0) && (here-> NBJTemitNode != 0))
            {
                i = here->NBJTcolEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTcolEmitBinding = matched ;
                here->NBJTcolEmitPtr = matched->CSC ;
            }

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTcolNode != 0))
            {
                i = here->NBJTbaseColPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTbaseColBinding = matched ;
                here->NBJTbaseColPtr = matched->CSC ;
            }

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTemitNode != 0))
            {
                i = here->NBJTbaseEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTbaseEmitBinding = matched ;
                here->NBJTbaseEmitPtr = matched->CSC ;
            }

            if ((here-> NBJTemitNode != 0) && (here-> NBJTcolNode != 0))
            {
                i = here->NBJTemitColPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTemitColBinding = matched ;
                here->NBJTemitColPtr = matched->CSC ;
            }

            if ((here-> NBJTemitNode != 0) && (here-> NBJTbaseNode != 0))
            {
                i = here->NBJTemitBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NBJTemitBaseBinding = matched ;
                here->NBJTemitBasePtr = matched->CSC ;
            }

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
            if ((here-> NBJTcolNode != 0) && (here-> NBJTcolNode != 0))
                here->NBJTcolColPtr = here->NBJTcolColBinding->CSC_Complex ;

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTbaseNode != 0))
                here->NBJTbaseBasePtr = here->NBJTbaseBaseBinding->CSC_Complex ;

            if ((here-> NBJTemitNode != 0) && (here-> NBJTemitNode != 0))
                here->NBJTemitEmitPtr = here->NBJTemitEmitBinding->CSC_Complex ;

            if ((here-> NBJTcolNode != 0) && (here-> NBJTbaseNode != 0))
                here->NBJTcolBasePtr = here->NBJTcolBaseBinding->CSC_Complex ;

            if ((here-> NBJTcolNode != 0) && (here-> NBJTemitNode != 0))
                here->NBJTcolEmitPtr = here->NBJTcolEmitBinding->CSC_Complex ;

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTcolNode != 0))
                here->NBJTbaseColPtr = here->NBJTbaseColBinding->CSC_Complex ;

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTemitNode != 0))
                here->NBJTbaseEmitPtr = here->NBJTbaseEmitBinding->CSC_Complex ;

            if ((here-> NBJTemitNode != 0) && (here-> NBJTcolNode != 0))
                here->NBJTemitColPtr = here->NBJTemitColBinding->CSC_Complex ;

            if ((here-> NBJTemitNode != 0) && (here-> NBJTbaseNode != 0))
                here->NBJTemitBasePtr = here->NBJTemitBaseBinding->CSC_Complex ;

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
            if ((here-> NBJTcolNode != 0) && (here-> NBJTcolNode != 0))
                here->NBJTcolColPtr = here->NBJTcolColBinding->CSC ;

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTbaseNode != 0))
                here->NBJTbaseBasePtr = here->NBJTbaseBaseBinding->CSC ;

            if ((here-> NBJTemitNode != 0) && (here-> NBJTemitNode != 0))
                here->NBJTemitEmitPtr = here->NBJTemitEmitBinding->CSC ;

            if ((here-> NBJTcolNode != 0) && (here-> NBJTbaseNode != 0))
                here->NBJTcolBasePtr = here->NBJTcolBaseBinding->CSC ;

            if ((here-> NBJTcolNode != 0) && (here-> NBJTemitNode != 0))
                here->NBJTcolEmitPtr = here->NBJTcolEmitBinding->CSC ;

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTcolNode != 0))
                here->NBJTbaseColPtr = here->NBJTbaseColBinding->CSC ;

            if ((here-> NBJTbaseNode != 0) && (here-> NBJTemitNode != 0))
                here->NBJTbaseEmitPtr = here->NBJTbaseEmitBinding->CSC ;

            if ((here-> NBJTemitNode != 0) && (here-> NBJTcolNode != 0))
                here->NBJTemitColPtr = here->NBJTemitColBinding->CSC ;

            if ((here-> NBJTemitNode != 0) && (here-> NBJTbaseNode != 0))
                here->NBJTemitBasePtr = here->NBJTemitBaseBinding->CSC ;

        }
    }

    return (OK) ;
}
