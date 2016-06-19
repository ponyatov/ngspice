/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "cswdefs.h"
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
            if ((here-> CSWposNode != 0) && (here-> CSWposNode != 0))
            {
                i = here->CSWposPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CSWposPosBinding = matched ;
                here->CSWposPosPtr = matched->CSC ;
            }

            if ((here-> CSWposNode != 0) && (here-> CSWnegNode != 0))
            {
                i = here->CSWposNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CSWposNegBinding = matched ;
                here->CSWposNegPtr = matched->CSC ;
            }

            if ((here-> CSWnegNode != 0) && (here-> CSWposNode != 0))
            {
                i = here->CSWnegPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CSWnegPosBinding = matched ;
                here->CSWnegPosPtr = matched->CSC ;
            }

            if ((here-> CSWnegNode != 0) && (here-> CSWnegNode != 0))
            {
                i = here->CSWnegNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->CSWnegNegBinding = matched ;
                here->CSWnegNegPtr = matched->CSC ;
            }

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
            if ((here-> CSWposNode != 0) && (here-> CSWposNode != 0))
                here->CSWposPosPtr = here->CSWposPosBinding->CSC_Complex ;

            if ((here-> CSWposNode != 0) && (here-> CSWnegNode != 0))
                here->CSWposNegPtr = here->CSWposNegBinding->CSC_Complex ;

            if ((here-> CSWnegNode != 0) && (here-> CSWposNode != 0))
                here->CSWnegPosPtr = here->CSWnegPosBinding->CSC_Complex ;

            if ((here-> CSWnegNode != 0) && (here-> CSWnegNode != 0))
                here->CSWnegNegPtr = here->CSWnegNegBinding->CSC_Complex ;

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
            if ((here-> CSWposNode != 0) && (here-> CSWposNode != 0))
                here->CSWposPosPtr = here->CSWposPosBinding->CSC ;

            if ((here-> CSWposNode != 0) && (here-> CSWnegNode != 0))
                here->CSWposNegPtr = here->CSWposNegBinding->CSC ;

            if ((here-> CSWnegNode != 0) && (here-> CSWposNode != 0))
                here->CSWnegPosPtr = here->CSWnegPosBinding->CSC ;

            if ((here-> CSWnegNode != 0) && (here-> CSWnegNode != 0))
                here->CSWnegNegPtr = here->CSWnegNegBinding->CSC ;

        }
    }

    return (OK) ;
}
