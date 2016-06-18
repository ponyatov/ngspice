/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "numosdef.h"
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
NUMOSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMOSmodel *model = (NUMOSmodel *)inModel ;
    NUMOSinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the NUMOS models */
    for ( ; model != NULL ; model = model->NUMOSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMOSinstances ; here != NULL ; here = here->NUMOSnextInstance)
        {
            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSdrainNode != 0))
            {
                i = here->NUMOSdrainDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSdrainDrainBinding = matched ;
                here->NUMOSdrainDrainPtr = matched->CSC ;
            }

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSsourceNode != 0))
            {
                i = here->NUMOSdrainSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSdrainSourceBinding = matched ;
                here->NUMOSdrainSourcePtr = matched->CSC ;
            }

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSgateNode != 0))
            {
                i = here->NUMOSdrainGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSdrainGateBinding = matched ;
                here->NUMOSdrainGatePtr = matched->CSC ;
            }

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSbulkNode != 0))
            {
                i = here->NUMOSdrainBulkPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSdrainBulkBinding = matched ;
                here->NUMOSdrainBulkPtr = matched->CSC ;
            }

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSdrainNode != 0))
            {
                i = here->NUMOSsourceDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSsourceDrainBinding = matched ;
                here->NUMOSsourceDrainPtr = matched->CSC ;
            }

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSsourceNode != 0))
            {
                i = here->NUMOSsourceSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSsourceSourceBinding = matched ;
                here->NUMOSsourceSourcePtr = matched->CSC ;
            }

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSgateNode != 0))
            {
                i = here->NUMOSsourceGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSsourceGateBinding = matched ;
                here->NUMOSsourceGatePtr = matched->CSC ;
            }

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSbulkNode != 0))
            {
                i = here->NUMOSsourceBulkPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSsourceBulkBinding = matched ;
                here->NUMOSsourceBulkPtr = matched->CSC ;
            }

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSdrainNode != 0))
            {
                i = here->NUMOSgateDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSgateDrainBinding = matched ;
                here->NUMOSgateDrainPtr = matched->CSC ;
            }

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSsourceNode != 0))
            {
                i = here->NUMOSgateSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSgateSourceBinding = matched ;
                here->NUMOSgateSourcePtr = matched->CSC ;
            }

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSgateNode != 0))
            {
                i = here->NUMOSgateGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSgateGateBinding = matched ;
                here->NUMOSgateGatePtr = matched->CSC ;
            }

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSbulkNode != 0))
            {
                i = here->NUMOSgateBulkPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSgateBulkBinding = matched ;
                here->NUMOSgateBulkPtr = matched->CSC ;
            }

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSdrainNode != 0))
            {
                i = here->NUMOSbulkDrainPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSbulkDrainBinding = matched ;
                here->NUMOSbulkDrainPtr = matched->CSC ;
            }

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSsourceNode != 0))
            {
                i = here->NUMOSbulkSourcePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSbulkSourceBinding = matched ;
                here->NUMOSbulkSourcePtr = matched->CSC ;
            }

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSgateNode != 0))
            {
                i = here->NUMOSbulkGatePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSbulkGateBinding = matched ;
                here->NUMOSbulkGatePtr = matched->CSC ;
            }

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSbulkNode != 0))
            {
                i = here->NUMOSbulkBulkPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->NUMOSbulkBulkBinding = matched ;
                here->NUMOSbulkBulkPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
NUMOSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMOSmodel *model = (NUMOSmodel *)inModel ;
    NUMOSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMOS models */
    for ( ; model != NULL ; model = model->NUMOSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMOSinstances ; here != NULL ; here = here->NUMOSnextInstance)
        {
            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSdrainDrainPtr = here->NUMOSdrainDrainBinding->CSC_Complex ;

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSdrainSourcePtr = here->NUMOSdrainSourceBinding->CSC_Complex ;

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSdrainGatePtr = here->NUMOSdrainGateBinding->CSC_Complex ;

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSdrainBulkPtr = here->NUMOSdrainBulkBinding->CSC_Complex ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSsourceDrainPtr = here->NUMOSsourceDrainBinding->CSC_Complex ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSsourceSourcePtr = here->NUMOSsourceSourceBinding->CSC_Complex ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSsourceGatePtr = here->NUMOSsourceGateBinding->CSC_Complex ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSsourceBulkPtr = here->NUMOSsourceBulkBinding->CSC_Complex ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSgateDrainPtr = here->NUMOSgateDrainBinding->CSC_Complex ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSgateSourcePtr = here->NUMOSgateSourceBinding->CSC_Complex ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSgateGatePtr = here->NUMOSgateGateBinding->CSC_Complex ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSgateBulkPtr = here->NUMOSgateBulkBinding->CSC_Complex ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSbulkDrainPtr = here->NUMOSbulkDrainBinding->CSC_Complex ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSbulkSourcePtr = here->NUMOSbulkSourceBinding->CSC_Complex ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSbulkGatePtr = here->NUMOSbulkGateBinding->CSC_Complex ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSbulkBulkPtr = here->NUMOSbulkBulkBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
NUMOSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMOSmodel *model = (NUMOSmodel *)inModel ;
    NUMOSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMOS models */
    for ( ; model != NULL ; model = model->NUMOSnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->NUMOSinstances ; here != NULL ; here = here->NUMOSnextInstance)
        {
            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSdrainDrainPtr = here->NUMOSdrainDrainBinding->CSC ;

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSdrainSourcePtr = here->NUMOSdrainSourceBinding->CSC ;

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSdrainGatePtr = here->NUMOSdrainGateBinding->CSC ;

            if ((here-> NUMOSdrainNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSdrainBulkPtr = here->NUMOSdrainBulkBinding->CSC ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSsourceDrainPtr = here->NUMOSsourceDrainBinding->CSC ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSsourceSourcePtr = here->NUMOSsourceSourceBinding->CSC ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSsourceGatePtr = here->NUMOSsourceGateBinding->CSC ;

            if ((here-> NUMOSsourceNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSsourceBulkPtr = here->NUMOSsourceBulkBinding->CSC ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSgateDrainPtr = here->NUMOSgateDrainBinding->CSC ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSgateSourcePtr = here->NUMOSgateSourceBinding->CSC ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSgateGatePtr = here->NUMOSgateGateBinding->CSC ;

            if ((here-> NUMOSgateNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSgateBulkPtr = here->NUMOSgateBulkBinding->CSC ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSdrainNode != 0))
                here->NUMOSbulkDrainPtr = here->NUMOSbulkDrainBinding->CSC ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSsourceNode != 0))
                here->NUMOSbulkSourcePtr = here->NUMOSbulkSourceBinding->CSC ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSgateNode != 0))
                here->NUMOSbulkGatePtr = here->NUMOSbulkGateBinding->CSC ;

            if ((here-> NUMOSbulkNode != 0) && (here-> NUMOSbulkNode != 0))
                here->NUMOSbulkBulkPtr = here->NUMOSbulkBulkBinding->CSC ;

        }
    }

    return (OK) ;
}
