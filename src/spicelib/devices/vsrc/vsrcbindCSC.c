/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vsrcdefs.h"
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
VSRCbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    VSRCmodel *model = (VSRCmodel *)inModel ;
    VSRCinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the VSRC models */
    for ( ; model != NULL ; model = model->VSRCnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VSRCinstances ; here != NULL ; here = here->VSRCnextInstance)
        {
            if ((here-> VSRCposNode != 0) && (here-> VSRCbranch != 0))
            {
                i = here->VSRCposIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VSRCposIbrptrStructPtr = matched ;
                here->VSRCposIbrPtr = matched->CSC ;
            }

            if ((here-> VSRCnegNode != 0) && (here-> VSRCbranch != 0))
            {
                i = here->VSRCnegIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VSRCnegIbrptrStructPtr = matched ;
                here->VSRCnegIbrPtr = matched->CSC ;
            }

            if ((here-> VSRCbranch != 0) && (here-> VSRCnegNode != 0))
            {
                i = here->VSRCibrNegPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VSRCibrNegptrStructPtr = matched ;
                here->VSRCibrNegPtr = matched->CSC ;
            }

            if ((here-> VSRCbranch != 0) && (here-> VSRCposNode != 0))
            {
                i = here->VSRCibrPosPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VSRCibrPosptrStructPtr = matched ;
                here->VSRCibrPosPtr = matched->CSC ;
            }

            /* Pole-Zero Analysis */
            if ((here-> VSRCbranch != 0) && (here-> VSRCbranch != 0))
            {
                i = here->VSRCibrIbrPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VSRCibrIbrptrStructPtr = matched ;
                if (matched != NULL)
                {
                    here->VSRCibrIbrPtr = matched->CSC ;
                }
            }
        }
    }

    return (OK) ;
}

int
VSRCbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    VSRCmodel *model = (VSRCmodel *)inModel ;
    VSRCinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VSRC models */
    for ( ; model != NULL ; model = model->VSRCnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VSRCinstances ; here != NULL ; here = here->VSRCnextInstance)
        {
            if ((here-> VSRCposNode != 0) && (here-> VSRCbranch != 0))
                here->VSRCposIbrPtr = here->VSRCposIbrptrStructPtr->CSC_Complex ;

            if ((here-> VSRCnegNode != 0) && (here-> VSRCbranch != 0))
                here->VSRCnegIbrPtr = here->VSRCnegIbrptrStructPtr->CSC_Complex ;

            if ((here-> VSRCbranch != 0) && (here-> VSRCnegNode != 0))
                here->VSRCibrNegPtr = here->VSRCibrNegptrStructPtr->CSC_Complex ;

            if ((here-> VSRCbranch != 0) && (here-> VSRCposNode != 0))
                here->VSRCibrPosPtr = here->VSRCibrPosptrStructPtr->CSC_Complex ;

            /* Pole-Zero Analysis */
            if ((here-> VSRCbranch != 0) && (here-> VSRCbranch != 0))
            {
                if (here->VSRCibrIbrptrStructPtr != NULL)
                {
                    here->VSRCibrIbrPtr = here->VSRCibrIbrptrStructPtr->CSC_Complex ;
                }
            }
        }
    }

    return (OK) ;
}

int
VSRCbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    VSRCmodel *model = (VSRCmodel *)inModel ;
    VSRCinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VSRC models */
    for ( ; model != NULL ; model = model->VSRCnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VSRCinstances ; here != NULL ; here = here->VSRCnextInstance)
        {
            if ((here-> VSRCposNode != 0) && (here-> VSRCbranch != 0))
                here->VSRCposIbrPtr = here->VSRCposIbrptrStructPtr->CSC ;

            if ((here-> VSRCnegNode != 0) && (here-> VSRCbranch != 0))
                here->VSRCnegIbrPtr = here->VSRCnegIbrptrStructPtr->CSC ;

            if ((here-> VSRCbranch != 0) && (here-> VSRCnegNode != 0))
                here->VSRCibrNegPtr = here->VSRCibrNegptrStructPtr->CSC ;

            if ((here-> VSRCbranch != 0) && (here-> VSRCposNode != 0))
                here->VSRCibrPosPtr = here->VSRCibrPosptrStructPtr->CSC ;

            /* Pole-Zero Analysis */
            if ((here-> VSRCbranch != 0) && (here-> VSRCbranch != 0))
            {
                if (here->VSRCibrIbrptrStructPtr != NULL)
                {
                    here->VSRCibrIbrPtr = here->VSRCibrIbrptrStructPtr->CSC ;
                }
            }
        }
    }

    return (OK) ;
}
