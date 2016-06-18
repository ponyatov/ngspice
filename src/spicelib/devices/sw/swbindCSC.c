/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "swdefs.h"
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
            if ((here-> SWposNode != 0) && (here-> SWposNode != 0))
            {
                i = here->SWposPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SWposPosptrStructPtr = matched ;
                here->SWposPosPtr = matched->CSC ;
            }

            if ((here-> SWposNode != 0) && (here-> SWnegNode != 0))
            {
                i = here->SWposNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SWposNegptrStructPtr = matched ;
                here->SWposNegPtr = matched->CSC ;
            }

            if ((here-> SWnegNode != 0) && (here-> SWposNode != 0))
            {
                i = here->SWnegPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SWnegPosptrStructPtr = matched ;
                here->SWnegPosPtr = matched->CSC ;
            }

            if ((here-> SWnegNode != 0) && (here-> SWnegNode != 0))
            {
                i = here->SWnegNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SWnegNegptrStructPtr = matched ;
                here->SWnegNegPtr = matched->CSC ;
            }

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
            if ((here-> SWposNode != 0) && (here-> SWposNode != 0))
                here->SWposPosPtr = here->SWposPosptrStructPtr->CSC_Complex ;

            if ((here-> SWposNode != 0) && (here-> SWnegNode != 0))
                here->SWposNegPtr = here->SWposNegptrStructPtr->CSC_Complex ;

            if ((here-> SWnegNode != 0) && (here-> SWposNode != 0))
                here->SWnegPosPtr = here->SWnegPosptrStructPtr->CSC_Complex ;

            if ((here-> SWnegNode != 0) && (here-> SWnegNode != 0))
                here->SWnegNegPtr = here->SWnegNegptrStructPtr->CSC_Complex ;

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
            if ((here-> SWposNode != 0) && (here-> SWposNode != 0))
                here->SWposPosPtr = here->SWposPosptrStructPtr->CSC ;

            if ((here-> SWposNode != 0) && (here-> SWnegNode != 0))
                here->SWposNegPtr = here->SWposNegptrStructPtr->CSC ;

            if ((here-> SWnegNode != 0) && (here-> SWposNode != 0))
                here->SWnegPosPtr = here->SWnegPosptrStructPtr->CSC ;

            if ((here-> SWnegNode != 0) && (here-> SWnegNode != 0))
                here->SWnegNegPtr = here->SWnegNegptrStructPtr->CSC ;

        }
    }

    return (OK) ;
}
