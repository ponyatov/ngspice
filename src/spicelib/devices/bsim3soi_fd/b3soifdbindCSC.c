/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b3soifddef.h"
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
B3SOIFDbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIFDmodel *model = (B3SOIFDmodel *)inModel ;
    B3SOIFDinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B3SOIFD models */
    for ( ; model != NULL ; model = model->B3SOIFDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIFDinstances ; here != NULL ; here = here->B3SOIFDnextInstance)
        {
            if ((model->B3SOIFDshMod == 1) && (here->B3SOIFDrth0 != 0.0))
            {
                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDtempNode != 0))
                {
                    i = here->B3SOIFDTemptempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDTemptempBinding = matched ;
                    here->B3SOIFDTemptempPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                {
                    i = here->B3SOIFDTempdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDTempdpBinding = matched ;
                    here->B3SOIFDTempdpPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                {
                    i = here->B3SOIFDTempspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDTempspBinding = matched ;
                    here->B3SOIFDTempspPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDgNode != 0))
                {
                    i = here->B3SOIFDTempgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDTempgBinding = matched ;
                    here->B3SOIFDTempgPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDbNode != 0))
                {
                    i = here->B3SOIFDTempbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDTempbBinding = matched ;
                    here->B3SOIFDTempbPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDeNode != 0))
                {
                    i = here->B3SOIFDTempePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDTempeBinding = matched ;
                    here->B3SOIFDTempePtr = matched->CSC ;
                }

                if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDtempNode != 0))
                {
                    i = here->B3SOIFDGtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDGtempBinding = matched ;
                    here->B3SOIFDGtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDtempNode != 0))
                {
                    i = here->B3SOIFDDPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDDPtempBinding = matched ;
                    here->B3SOIFDDPtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDtempNode != 0))
                {
                    i = here->B3SOIFDSPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDSPtempBinding = matched ;
                    here->B3SOIFDSPtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDtempNode != 0))
                {
                    i = here->B3SOIFDEtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDEtempBinding = matched ;
                    here->B3SOIFDEtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDbNode != 0) && (here-> B3SOIFDtempNode != 0))
                {
                    i = here->B3SOIFDBtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDBtempBinding = matched ;
                    here->B3SOIFDBtempPtr = matched->CSC ;
                }

                if (here->B3SOIFDbodyMod == 1)
                {
                    if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDtempNode != 0))
                    {
                        i = here->B3SOIFDPtempPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B3SOIFDPtempBinding = matched ;
                        here->B3SOIFDPtempPtr = matched->CSC ;
                    }

                }
            }
            if (here->B3SOIFDbodyMod == 2)
            {
            }
            else if (here->B3SOIFDbodyMod == 1)
            {
                if ((here-> B3SOIFDbNode != 0) && (here-> B3SOIFDpNode != 0))
                {
                    i = here->B3SOIFDBpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDBpBinding = matched ;
                    here->B3SOIFDBpPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDbNode != 0))
                {
                    i = here->B3SOIFDPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDPbBinding = matched ;
                    here->B3SOIFDPbPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDpNode != 0))
                {
                    i = here->B3SOIFDPpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDPpBinding = matched ;
                    here->B3SOIFDPpPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDgNode != 0))
                {
                    i = here->B3SOIFDPgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDPgBinding = matched ;
                    here->B3SOIFDPgPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                {
                    i = here->B3SOIFDPdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDPdpBinding = matched ;
                    here->B3SOIFDPdpPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                {
                    i = here->B3SOIFDPspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDPspBinding = matched ;
                    here->B3SOIFDPspPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDeNode != 0))
                {
                    i = here->B3SOIFDPePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDPeBinding = matched ;
                    here->B3SOIFDPePtr = matched->CSC ;
                }

            }
            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDgNode != 0))
            {
                i = here->B3SOIFDEgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDEgBinding = matched ;
                here->B3SOIFDEgPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDdNodePrime != 0))
            {
                i = here->B3SOIFDEdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDEdpBinding = matched ;
                here->B3SOIFDEdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDsNodePrime != 0))
            {
                i = here->B3SOIFDEspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDEspBinding = matched ;
                here->B3SOIFDEspPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDeNode != 0))
            {
                i = here->B3SOIFDGePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDGeBinding = matched ;
                here->B3SOIFDGePtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDeNode != 0))
            {
                i = here->B3SOIFDDPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDPeBinding = matched ;
                here->B3SOIFDDPePtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDeNode != 0))
            {
                i = here->B3SOIFDSPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSPeBinding = matched ;
                here->B3SOIFDSPePtr = matched->CSC ;
            }

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDbNode != 0))
            {
                i = here->B3SOIFDEbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDEbBinding = matched ;
                here->B3SOIFDEbPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDeNode != 0))
            {
                i = here->B3SOIFDEePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDEeBinding = matched ;
                here->B3SOIFDEePtr = matched->CSC ;
            }

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDgNode != 0))
            {
                i = here->B3SOIFDGgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDGgBinding = matched ;
                here->B3SOIFDGgPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDdNodePrime != 0))
            {
                i = here->B3SOIFDGdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDGdpBinding = matched ;
                here->B3SOIFDGdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDsNodePrime != 0))
            {
                i = here->B3SOIFDGspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDGspBinding = matched ;
                here->B3SOIFDGspPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDgNode != 0))
            {
                i = here->B3SOIFDDPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDPgBinding = matched ;
                here->B3SOIFDDPgPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDdNodePrime != 0))
            {
                i = here->B3SOIFDDPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDPdpBinding = matched ;
                here->B3SOIFDDPdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDsNodePrime != 0))
            {
                i = here->B3SOIFDDPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDPspBinding = matched ;
                here->B3SOIFDDPspPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDdNode != 0))
            {
                i = here->B3SOIFDDPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDPdBinding = matched ;
                here->B3SOIFDDPdPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDgNode != 0))
            {
                i = here->B3SOIFDSPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSPgBinding = matched ;
                here->B3SOIFDSPgPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDdNodePrime != 0))
            {
                i = here->B3SOIFDSPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSPdpBinding = matched ;
                here->B3SOIFDSPdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDsNodePrime != 0))
            {
                i = here->B3SOIFDSPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSPspBinding = matched ;
                here->B3SOIFDSPspPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDsNode != 0))
            {
                i = here->B3SOIFDSPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSPsBinding = matched ;
                here->B3SOIFDSPsPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNode != 0) && (here-> B3SOIFDdNode != 0))
            {
                i = here->B3SOIFDDdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDdBinding = matched ;
                here->B3SOIFDDdPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDdNode != 0) && (here-> B3SOIFDdNodePrime != 0))
            {
                i = here->B3SOIFDDdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDDdpBinding = matched ;
                here->B3SOIFDDdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNode != 0) && (here-> B3SOIFDsNode != 0))
            {
                i = here->B3SOIFDSsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSsBinding = matched ;
                here->B3SOIFDSsPtr = matched->CSC ;
            }

            if ((here-> B3SOIFDsNode != 0) && (here-> B3SOIFDsNodePrime != 0))
            {
                i = here->B3SOIFDSspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIFDSspBinding = matched ;
                here->B3SOIFDSspPtr = matched->CSC ;
            }

            if ((here->B3SOIFDdebugMod > 1) || (here->B3SOIFDdebugMod == -1))
            {
                if ((here-> B3SOIFDvbsNode != 0) && (here-> B3SOIFDvbsNode != 0))
                {
                    i = here->B3SOIFDVbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVbsBinding = matched ;
                    here->B3SOIFDVbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDidsNode != 0) && (here-> B3SOIFDidsNode != 0))
                {
                    i = here->B3SOIFDIdsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIdsBinding = matched ;
                    here->B3SOIFDIdsPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDicNode != 0) && (here-> B3SOIFDicNode != 0))
                {
                    i = here->B3SOIFDIcPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIcBinding = matched ;
                    here->B3SOIFDIcPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDibsNode != 0) && (here-> B3SOIFDibsNode != 0))
                {
                    i = here->B3SOIFDIbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIbsBinding = matched ;
                    here->B3SOIFDIbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDibdNode != 0) && (here-> B3SOIFDibdNode != 0))
                {
                    i = here->B3SOIFDIbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIbdBinding = matched ;
                    here->B3SOIFDIbdPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDiiiNode != 0) && (here-> B3SOIFDiiiNode != 0))
                {
                    i = here->B3SOIFDIiiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIiiBinding = matched ;
                    here->B3SOIFDIiiPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDigidlNode != 0) && (here-> B3SOIFDigidlNode != 0))
                {
                    i = here->B3SOIFDIgidlPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIgidlBinding = matched ;
                    here->B3SOIFDIgidlPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDitunNode != 0) && (here-> B3SOIFDitunNode != 0))
                {
                    i = here->B3SOIFDItunPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDItunBinding = matched ;
                    here->B3SOIFDItunPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDibpNode != 0) && (here-> B3SOIFDibpNode != 0))
                {
                    i = here->B3SOIFDIbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDIbpBinding = matched ;
                    here->B3SOIFDIbpPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDabeffNode != 0) && (here-> B3SOIFDabeffNode != 0))
                {
                    i = here->B3SOIFDAbeffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDAbeffBinding = matched ;
                    here->B3SOIFDAbeffPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvbs0effNode != 0) && (here-> B3SOIFDvbs0effNode != 0))
                {
                    i = here->B3SOIFDVbs0effPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVbs0effBinding = matched ;
                    here->B3SOIFDVbs0effPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvbseffNode != 0) && (here-> B3SOIFDvbseffNode != 0))
                {
                    i = here->B3SOIFDVbseffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVbseffBinding = matched ;
                    here->B3SOIFDVbseffPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDxcNode != 0) && (here-> B3SOIFDxcNode != 0))
                {
                    i = here->B3SOIFDXcPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDXcBinding = matched ;
                    here->B3SOIFDXcPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDcbbNode != 0) && (here-> B3SOIFDcbbNode != 0))
                {
                    i = here->B3SOIFDCbbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDCbbBinding = matched ;
                    here->B3SOIFDCbbPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDcbdNode != 0) && (here-> B3SOIFDcbdNode != 0))
                {
                    i = here->B3SOIFDCbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDCbdBinding = matched ;
                    here->B3SOIFDCbdPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDcbgNode != 0) && (here-> B3SOIFDcbgNode != 0))
                {
                    i = here->B3SOIFDCbgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDCbgBinding = matched ;
                    here->B3SOIFDCbgPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqbNode != 0) && (here-> B3SOIFDqbNode != 0))
                {
                    i = here->B3SOIFDqbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDqbBinding = matched ;
                    here->B3SOIFDqbPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqbfNode != 0) && (here-> B3SOIFDqbfNode != 0))
                {
                    i = here->B3SOIFDQbfPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQbfBinding = matched ;
                    here->B3SOIFDQbfPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqjsNode != 0) && (here-> B3SOIFDqjsNode != 0))
                {
                    i = here->B3SOIFDQjsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQjsBinding = matched ;
                    here->B3SOIFDQjsPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqjdNode != 0) && (here-> B3SOIFDqjdNode != 0))
                {
                    i = here->B3SOIFDQjdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQjdBinding = matched ;
                    here->B3SOIFDQjdPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDgmNode != 0) && (here-> B3SOIFDgmNode != 0))
                {
                    i = here->B3SOIFDGmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDGmBinding = matched ;
                    here->B3SOIFDGmPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDgmbsNode != 0) && (here-> B3SOIFDgmbsNode != 0))
                {
                    i = here->B3SOIFDGmbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDGmbsBinding = matched ;
                    here->B3SOIFDGmbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDgdsNode != 0) && (here-> B3SOIFDgdsNode != 0))
                {
                    i = here->B3SOIFDGdsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDGdsBinding = matched ;
                    here->B3SOIFDGdsPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDgmeNode != 0) && (here-> B3SOIFDgmeNode != 0))
                {
                    i = here->B3SOIFDGmePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDGmeBinding = matched ;
                    here->B3SOIFDGmePtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvbs0teffNode != 0) && (here-> B3SOIFDvbs0teffNode != 0))
                {
                    i = here->B3SOIFDVbs0teffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVbs0teffBinding = matched ;
                    here->B3SOIFDVbs0teffPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvthNode != 0) && (here-> B3SOIFDvthNode != 0))
                {
                    i = here->B3SOIFDVthPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVthBinding = matched ;
                    here->B3SOIFDVthPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvgsteffNode != 0) && (here-> B3SOIFDvgsteffNode != 0))
                {
                    i = here->B3SOIFDVgsteffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVgsteffBinding = matched ;
                    here->B3SOIFDVgsteffPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDxcsatNode != 0) && (here-> B3SOIFDxcsatNode != 0))
                {
                    i = here->B3SOIFDXcsatPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDXcsatBinding = matched ;
                    here->B3SOIFDXcsatPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvcscvNode != 0) && (here-> B3SOIFDvcscvNode != 0))
                {
                    i = here->B3SOIFDVcscvPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVcscvBinding = matched ;
                    here->B3SOIFDVcscvPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDvdscvNode != 0) && (here-> B3SOIFDvdscvNode != 0))
                {
                    i = here->B3SOIFDVdscvPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDVdscvBinding = matched ;
                    here->B3SOIFDVdscvPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDcbeNode != 0) && (here-> B3SOIFDcbeNode != 0))
                {
                    i = here->B3SOIFDCbePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDCbeBinding = matched ;
                    here->B3SOIFDCbePtr = matched->CSC ;
                }

                if ((here-> B3SOIFDdum1Node != 0) && (here-> B3SOIFDdum1Node != 0))
                {
                    i = here->B3SOIFDDum1Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDDum1Binding = matched ;
                    here->B3SOIFDDum1Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDdum2Node != 0) && (here-> B3SOIFDdum2Node != 0))
                {
                    i = here->B3SOIFDDum2Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDDum2Binding = matched ;
                    here->B3SOIFDDum2Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDdum3Node != 0) && (here-> B3SOIFDdum3Node != 0))
                {
                    i = here->B3SOIFDDum3Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDDum3Binding = matched ;
                    here->B3SOIFDDum3Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDdum4Node != 0) && (here-> B3SOIFDdum4Node != 0))
                {
                    i = here->B3SOIFDDum4Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDDum4Binding = matched ;
                    here->B3SOIFDDum4Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDdum5Node != 0) && (here-> B3SOIFDdum5Node != 0))
                {
                    i = here->B3SOIFDDum5Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDDum5Binding = matched ;
                    here->B3SOIFDDum5Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDqaccNode != 0) && (here-> B3SOIFDqaccNode != 0))
                {
                    i = here->B3SOIFDQaccPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQaccBinding = matched ;
                    here->B3SOIFDQaccPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqsub0Node != 0) && (here-> B3SOIFDqsub0Node != 0))
                {
                    i = here->B3SOIFDQsub0Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQsub0Binding = matched ;
                    here->B3SOIFDQsub0Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDqsubs1Node != 0) && (here-> B3SOIFDqsubs1Node != 0))
                {
                    i = here->B3SOIFDQsubs1Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQsubs1Binding = matched ;
                    here->B3SOIFDQsubs1Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDqsubs2Node != 0) && (here-> B3SOIFDqsubs2Node != 0))
                {
                    i = here->B3SOIFDQsubs2Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDQsubs2Binding = matched ;
                    here->B3SOIFDQsubs2Ptr = matched->CSC ;
                }

                if ((here-> B3SOIFDqeNode != 0) && (here-> B3SOIFDqeNode != 0))
                {
                    i = here->B3SOIFDqePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDqeBinding = matched ;
                    here->B3SOIFDqePtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqdNode != 0) && (here-> B3SOIFDqdNode != 0))
                {
                    i = here->B3SOIFDqdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDqdBinding = matched ;
                    here->B3SOIFDqdPtr = matched->CSC ;
                }

                if ((here-> B3SOIFDqgNode != 0) && (here-> B3SOIFDqgNode != 0))
                {
                    i = here->B3SOIFDqgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIFDqgBinding = matched ;
                    here->B3SOIFDqgPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
B3SOIFDbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIFDmodel *model = (B3SOIFDmodel *)inModel ;
    B3SOIFDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B3SOIFD models */
    for ( ; model != NULL ; model = model->B3SOIFDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIFDinstances ; here != NULL ; here = here->B3SOIFDnextInstance)
        {
            if ((model->B3SOIFDshMod == 1) && (here->B3SOIFDrth0 != 0.0))
            {
                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDTemptempPtr = here->B3SOIFDTemptempBinding->CSC_Complex ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                    here->B3SOIFDTempdpPtr = here->B3SOIFDTempdpBinding->CSC_Complex ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                    here->B3SOIFDTempspPtr = here->B3SOIFDTempspBinding->CSC_Complex ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDgNode != 0))
                    here->B3SOIFDTempgPtr = here->B3SOIFDTempgBinding->CSC_Complex ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDbNode != 0))
                    here->B3SOIFDTempbPtr = here->B3SOIFDTempbBinding->CSC_Complex ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDeNode != 0))
                    here->B3SOIFDTempePtr = here->B3SOIFDTempeBinding->CSC_Complex ;

                if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDGtempPtr = here->B3SOIFDGtempBinding->CSC_Complex ;

                if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDDPtempPtr = here->B3SOIFDDPtempBinding->CSC_Complex ;

                if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDSPtempPtr = here->B3SOIFDSPtempBinding->CSC_Complex ;

                if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDEtempPtr = here->B3SOIFDEtempBinding->CSC_Complex ;

                if ((here-> B3SOIFDbNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDBtempPtr = here->B3SOIFDBtempBinding->CSC_Complex ;

                if (here->B3SOIFDbodyMod == 1)
                {
                    if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDtempNode != 0))
                        here->B3SOIFDPtempPtr = here->B3SOIFDPtempBinding->CSC_Complex ;

                }
            }
            if (here->B3SOIFDbodyMod == 2)
            {
            }
            else if (here->B3SOIFDbodyMod == 1)
            {
                if ((here-> B3SOIFDbNode != 0) && (here-> B3SOIFDpNode != 0))
                    here->B3SOIFDBpPtr = here->B3SOIFDBpBinding->CSC_Complex ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDbNode != 0))
                    here->B3SOIFDPbPtr = here->B3SOIFDPbBinding->CSC_Complex ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDpNode != 0))
                    here->B3SOIFDPpPtr = here->B3SOIFDPpBinding->CSC_Complex ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDgNode != 0))
                    here->B3SOIFDPgPtr = here->B3SOIFDPgBinding->CSC_Complex ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                    here->B3SOIFDPdpPtr = here->B3SOIFDPdpBinding->CSC_Complex ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                    here->B3SOIFDPspPtr = here->B3SOIFDPspBinding->CSC_Complex ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDeNode != 0))
                    here->B3SOIFDPePtr = here->B3SOIFDPeBinding->CSC_Complex ;

            }
            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDEgPtr = here->B3SOIFDEgBinding->CSC_Complex ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDEdpPtr = here->B3SOIFDEdpBinding->CSC_Complex ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDEspPtr = here->B3SOIFDEspBinding->CSC_Complex ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDGePtr = here->B3SOIFDGeBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDDPePtr = here->B3SOIFDDPeBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDSPePtr = here->B3SOIFDSPeBinding->CSC_Complex ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDbNode != 0))
                here->B3SOIFDEbPtr = here->B3SOIFDEbBinding->CSC_Complex ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDEePtr = here->B3SOIFDEeBinding->CSC_Complex ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDGgPtr = here->B3SOIFDGgBinding->CSC_Complex ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDGdpPtr = here->B3SOIFDGdpBinding->CSC_Complex ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDGspPtr = here->B3SOIFDGspBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDDPgPtr = here->B3SOIFDDPgBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDDPdpPtr = here->B3SOIFDDPdpBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDDPspPtr = here->B3SOIFDDPspBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDdNode != 0))
                here->B3SOIFDDPdPtr = here->B3SOIFDDPdBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDSPgPtr = here->B3SOIFDSPgBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDSPdpPtr = here->B3SOIFDSPdpBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDSPspPtr = here->B3SOIFDSPspBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDsNode != 0))
                here->B3SOIFDSPsPtr = here->B3SOIFDSPsBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNode != 0) && (here-> B3SOIFDdNode != 0))
                here->B3SOIFDDdPtr = here->B3SOIFDDdBinding->CSC_Complex ;

            if ((here-> B3SOIFDdNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDDdpPtr = here->B3SOIFDDdpBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNode != 0) && (here-> B3SOIFDsNode != 0))
                here->B3SOIFDSsPtr = here->B3SOIFDSsBinding->CSC_Complex ;

            if ((here-> B3SOIFDsNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDSspPtr = here->B3SOIFDSspBinding->CSC_Complex ;

            if ((here->B3SOIFDdebugMod > 1) || (here->B3SOIFDdebugMod == -1))
            {
                if ((here-> B3SOIFDvbsNode != 0) && (here-> B3SOIFDvbsNode != 0))
                    here->B3SOIFDVbsPtr = here->B3SOIFDVbsBinding->CSC_Complex ;

                if ((here-> B3SOIFDidsNode != 0) && (here-> B3SOIFDidsNode != 0))
                    here->B3SOIFDIdsPtr = here->B3SOIFDIdsBinding->CSC_Complex ;

                if ((here-> B3SOIFDicNode != 0) && (here-> B3SOIFDicNode != 0))
                    here->B3SOIFDIcPtr = here->B3SOIFDIcBinding->CSC_Complex ;

                if ((here-> B3SOIFDibsNode != 0) && (here-> B3SOIFDibsNode != 0))
                    here->B3SOIFDIbsPtr = here->B3SOIFDIbsBinding->CSC_Complex ;

                if ((here-> B3SOIFDibdNode != 0) && (here-> B3SOIFDibdNode != 0))
                    here->B3SOIFDIbdPtr = here->B3SOIFDIbdBinding->CSC_Complex ;

                if ((here-> B3SOIFDiiiNode != 0) && (here-> B3SOIFDiiiNode != 0))
                    here->B3SOIFDIiiPtr = here->B3SOIFDIiiBinding->CSC_Complex ;

                if ((here-> B3SOIFDigidlNode != 0) && (here-> B3SOIFDigidlNode != 0))
                    here->B3SOIFDIgidlPtr = here->B3SOIFDIgidlBinding->CSC_Complex ;

                if ((here-> B3SOIFDitunNode != 0) && (here-> B3SOIFDitunNode != 0))
                    here->B3SOIFDItunPtr = here->B3SOIFDItunBinding->CSC_Complex ;

                if ((here-> B3SOIFDibpNode != 0) && (here-> B3SOIFDibpNode != 0))
                    here->B3SOIFDIbpPtr = here->B3SOIFDIbpBinding->CSC_Complex ;

                if ((here-> B3SOIFDabeffNode != 0) && (here-> B3SOIFDabeffNode != 0))
                    here->B3SOIFDAbeffPtr = here->B3SOIFDAbeffBinding->CSC_Complex ;

                if ((here-> B3SOIFDvbs0effNode != 0) && (here-> B3SOIFDvbs0effNode != 0))
                    here->B3SOIFDVbs0effPtr = here->B3SOIFDVbs0effBinding->CSC_Complex ;

                if ((here-> B3SOIFDvbseffNode != 0) && (here-> B3SOIFDvbseffNode != 0))
                    here->B3SOIFDVbseffPtr = here->B3SOIFDVbseffBinding->CSC_Complex ;

                if ((here-> B3SOIFDxcNode != 0) && (here-> B3SOIFDxcNode != 0))
                    here->B3SOIFDXcPtr = here->B3SOIFDXcBinding->CSC_Complex ;

                if ((here-> B3SOIFDcbbNode != 0) && (here-> B3SOIFDcbbNode != 0))
                    here->B3SOIFDCbbPtr = here->B3SOIFDCbbBinding->CSC_Complex ;

                if ((here-> B3SOIFDcbdNode != 0) && (here-> B3SOIFDcbdNode != 0))
                    here->B3SOIFDCbdPtr = here->B3SOIFDCbdBinding->CSC_Complex ;

                if ((here-> B3SOIFDcbgNode != 0) && (here-> B3SOIFDcbgNode != 0))
                    here->B3SOIFDCbgPtr = here->B3SOIFDCbgBinding->CSC_Complex ;

                if ((here-> B3SOIFDqbNode != 0) && (here-> B3SOIFDqbNode != 0))
                    here->B3SOIFDqbPtr = here->B3SOIFDqbBinding->CSC_Complex ;

                if ((here-> B3SOIFDqbfNode != 0) && (here-> B3SOIFDqbfNode != 0))
                    here->B3SOIFDQbfPtr = here->B3SOIFDQbfBinding->CSC_Complex ;

                if ((here-> B3SOIFDqjsNode != 0) && (here-> B3SOIFDqjsNode != 0))
                    here->B3SOIFDQjsPtr = here->B3SOIFDQjsBinding->CSC_Complex ;

                if ((here-> B3SOIFDqjdNode != 0) && (here-> B3SOIFDqjdNode != 0))
                    here->B3SOIFDQjdPtr = here->B3SOIFDQjdBinding->CSC_Complex ;

                if ((here-> B3SOIFDgmNode != 0) && (here-> B3SOIFDgmNode != 0))
                    here->B3SOIFDGmPtr = here->B3SOIFDGmBinding->CSC_Complex ;

                if ((here-> B3SOIFDgmbsNode != 0) && (here-> B3SOIFDgmbsNode != 0))
                    here->B3SOIFDGmbsPtr = here->B3SOIFDGmbsBinding->CSC_Complex ;

                if ((here-> B3SOIFDgdsNode != 0) && (here-> B3SOIFDgdsNode != 0))
                    here->B3SOIFDGdsPtr = here->B3SOIFDGdsBinding->CSC_Complex ;

                if ((here-> B3SOIFDgmeNode != 0) && (here-> B3SOIFDgmeNode != 0))
                    here->B3SOIFDGmePtr = here->B3SOIFDGmeBinding->CSC_Complex ;

                if ((here-> B3SOIFDvbs0teffNode != 0) && (here-> B3SOIFDvbs0teffNode != 0))
                    here->B3SOIFDVbs0teffPtr = here->B3SOIFDVbs0teffBinding->CSC_Complex ;

                if ((here-> B3SOIFDvthNode != 0) && (here-> B3SOIFDvthNode != 0))
                    here->B3SOIFDVthPtr = here->B3SOIFDVthBinding->CSC_Complex ;

                if ((here-> B3SOIFDvgsteffNode != 0) && (here-> B3SOIFDvgsteffNode != 0))
                    here->B3SOIFDVgsteffPtr = here->B3SOIFDVgsteffBinding->CSC_Complex ;

                if ((here-> B3SOIFDxcsatNode != 0) && (here-> B3SOIFDxcsatNode != 0))
                    here->B3SOIFDXcsatPtr = here->B3SOIFDXcsatBinding->CSC_Complex ;

                if ((here-> B3SOIFDvcscvNode != 0) && (here-> B3SOIFDvcscvNode != 0))
                    here->B3SOIFDVcscvPtr = here->B3SOIFDVcscvBinding->CSC_Complex ;

                if ((here-> B3SOIFDvdscvNode != 0) && (here-> B3SOIFDvdscvNode != 0))
                    here->B3SOIFDVdscvPtr = here->B3SOIFDVdscvBinding->CSC_Complex ;

                if ((here-> B3SOIFDcbeNode != 0) && (here-> B3SOIFDcbeNode != 0))
                    here->B3SOIFDCbePtr = here->B3SOIFDCbeBinding->CSC_Complex ;

                if ((here-> B3SOIFDdum1Node != 0) && (here-> B3SOIFDdum1Node != 0))
                    here->B3SOIFDDum1Ptr = here->B3SOIFDDum1Binding->CSC_Complex ;

                if ((here-> B3SOIFDdum2Node != 0) && (here-> B3SOIFDdum2Node != 0))
                    here->B3SOIFDDum2Ptr = here->B3SOIFDDum2Binding->CSC_Complex ;

                if ((here-> B3SOIFDdum3Node != 0) && (here-> B3SOIFDdum3Node != 0))
                    here->B3SOIFDDum3Ptr = here->B3SOIFDDum3Binding->CSC_Complex ;

                if ((here-> B3SOIFDdum4Node != 0) && (here-> B3SOIFDdum4Node != 0))
                    here->B3SOIFDDum4Ptr = here->B3SOIFDDum4Binding->CSC_Complex ;

                if ((here-> B3SOIFDdum5Node != 0) && (here-> B3SOIFDdum5Node != 0))
                    here->B3SOIFDDum5Ptr = here->B3SOIFDDum5Binding->CSC_Complex ;

                if ((here-> B3SOIFDqaccNode != 0) && (here-> B3SOIFDqaccNode != 0))
                    here->B3SOIFDQaccPtr = here->B3SOIFDQaccBinding->CSC_Complex ;

                if ((here-> B3SOIFDqsub0Node != 0) && (here-> B3SOIFDqsub0Node != 0))
                    here->B3SOIFDQsub0Ptr = here->B3SOIFDQsub0Binding->CSC_Complex ;

                if ((here-> B3SOIFDqsubs1Node != 0) && (here-> B3SOIFDqsubs1Node != 0))
                    here->B3SOIFDQsubs1Ptr = here->B3SOIFDQsubs1Binding->CSC_Complex ;

                if ((here-> B3SOIFDqsubs2Node != 0) && (here-> B3SOIFDqsubs2Node != 0))
                    here->B3SOIFDQsubs2Ptr = here->B3SOIFDQsubs2Binding->CSC_Complex ;

                if ((here-> B3SOIFDqeNode != 0) && (here-> B3SOIFDqeNode != 0))
                    here->B3SOIFDqePtr = here->B3SOIFDqeBinding->CSC_Complex ;

                if ((here-> B3SOIFDqdNode != 0) && (here-> B3SOIFDqdNode != 0))
                    here->B3SOIFDqdPtr = here->B3SOIFDqdBinding->CSC_Complex ;

                if ((here-> B3SOIFDqgNode != 0) && (here-> B3SOIFDqgNode != 0))
                    here->B3SOIFDqgPtr = here->B3SOIFDqgBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
B3SOIFDbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIFDmodel *model = (B3SOIFDmodel *)inModel ;
    B3SOIFDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B3SOIFD models */
    for ( ; model != NULL ; model = model->B3SOIFDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIFDinstances ; here != NULL ; here = here->B3SOIFDnextInstance)
        {
            if ((model->B3SOIFDshMod == 1) && (here->B3SOIFDrth0 != 0.0))
            {
                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDTemptempPtr = here->B3SOIFDTemptempBinding->CSC ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                    here->B3SOIFDTempdpPtr = here->B3SOIFDTempdpBinding->CSC ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                    here->B3SOIFDTempspPtr = here->B3SOIFDTempspBinding->CSC ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDgNode != 0))
                    here->B3SOIFDTempgPtr = here->B3SOIFDTempgBinding->CSC ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDbNode != 0))
                    here->B3SOIFDTempbPtr = here->B3SOIFDTempbBinding->CSC ;

                if ((here-> B3SOIFDtempNode != 0) && (here-> B3SOIFDeNode != 0))
                    here->B3SOIFDTempePtr = here->B3SOIFDTempeBinding->CSC ;

                if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDGtempPtr = here->B3SOIFDGtempBinding->CSC ;

                if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDDPtempPtr = here->B3SOIFDDPtempBinding->CSC ;

                if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDSPtempPtr = here->B3SOIFDSPtempBinding->CSC ;

                if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDEtempPtr = here->B3SOIFDEtempBinding->CSC ;

                if ((here-> B3SOIFDbNode != 0) && (here-> B3SOIFDtempNode != 0))
                    here->B3SOIFDBtempPtr = here->B3SOIFDBtempBinding->CSC ;

                if (here->B3SOIFDbodyMod == 1)
                {
                    if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDtempNode != 0))
                        here->B3SOIFDPtempPtr = here->B3SOIFDPtempBinding->CSC ;

                }
            }
            if (here->B3SOIFDbodyMod == 2)
            {
            }
            else if (here->B3SOIFDbodyMod == 1)
            {
                if ((here-> B3SOIFDbNode != 0) && (here-> B3SOIFDpNode != 0))
                    here->B3SOIFDBpPtr = here->B3SOIFDBpBinding->CSC ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDbNode != 0))
                    here->B3SOIFDPbPtr = here->B3SOIFDPbBinding->CSC ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDpNode != 0))
                    here->B3SOIFDPpPtr = here->B3SOIFDPpBinding->CSC ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDgNode != 0))
                    here->B3SOIFDPgPtr = here->B3SOIFDPgBinding->CSC ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                    here->B3SOIFDPdpPtr = here->B3SOIFDPdpBinding->CSC ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                    here->B3SOIFDPspPtr = here->B3SOIFDPspBinding->CSC ;

                if ((here-> B3SOIFDpNode != 0) && (here-> B3SOIFDeNode != 0))
                    here->B3SOIFDPePtr = here->B3SOIFDPeBinding->CSC ;

            }
            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDEgPtr = here->B3SOIFDEgBinding->CSC ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDEdpPtr = here->B3SOIFDEdpBinding->CSC ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDEspPtr = here->B3SOIFDEspBinding->CSC ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDGePtr = here->B3SOIFDGeBinding->CSC ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDDPePtr = here->B3SOIFDDPeBinding->CSC ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDSPePtr = here->B3SOIFDSPeBinding->CSC ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDbNode != 0))
                here->B3SOIFDEbPtr = here->B3SOIFDEbBinding->CSC ;

            if ((here-> B3SOIFDeNode != 0) && (here-> B3SOIFDeNode != 0))
                here->B3SOIFDEePtr = here->B3SOIFDEeBinding->CSC ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDGgPtr = here->B3SOIFDGgBinding->CSC ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDGdpPtr = here->B3SOIFDGdpBinding->CSC ;

            if ((here-> B3SOIFDgNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDGspPtr = here->B3SOIFDGspBinding->CSC ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDDPgPtr = here->B3SOIFDDPgBinding->CSC ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDDPdpPtr = here->B3SOIFDDPdpBinding->CSC ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDDPspPtr = here->B3SOIFDDPspBinding->CSC ;

            if ((here-> B3SOIFDdNodePrime != 0) && (here-> B3SOIFDdNode != 0))
                here->B3SOIFDDPdPtr = here->B3SOIFDDPdBinding->CSC ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDgNode != 0))
                here->B3SOIFDSPgPtr = here->B3SOIFDSPgBinding->CSC ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDSPdpPtr = here->B3SOIFDSPdpBinding->CSC ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDSPspPtr = here->B3SOIFDSPspBinding->CSC ;

            if ((here-> B3SOIFDsNodePrime != 0) && (here-> B3SOIFDsNode != 0))
                here->B3SOIFDSPsPtr = here->B3SOIFDSPsBinding->CSC ;

            if ((here-> B3SOIFDdNode != 0) && (here-> B3SOIFDdNode != 0))
                here->B3SOIFDDdPtr = here->B3SOIFDDdBinding->CSC ;

            if ((here-> B3SOIFDdNode != 0) && (here-> B3SOIFDdNodePrime != 0))
                here->B3SOIFDDdpPtr = here->B3SOIFDDdpBinding->CSC ;

            if ((here-> B3SOIFDsNode != 0) && (here-> B3SOIFDsNode != 0))
                here->B3SOIFDSsPtr = here->B3SOIFDSsBinding->CSC ;

            if ((here-> B3SOIFDsNode != 0) && (here-> B3SOIFDsNodePrime != 0))
                here->B3SOIFDSspPtr = here->B3SOIFDSspBinding->CSC ;

            if ((here->B3SOIFDdebugMod > 1) || (here->B3SOIFDdebugMod == -1))
            {
                if ((here-> B3SOIFDvbsNode != 0) && (here-> B3SOIFDvbsNode != 0))
                    here->B3SOIFDVbsPtr = here->B3SOIFDVbsBinding->CSC ;

                if ((here-> B3SOIFDidsNode != 0) && (here-> B3SOIFDidsNode != 0))
                    here->B3SOIFDIdsPtr = here->B3SOIFDIdsBinding->CSC ;

                if ((here-> B3SOIFDicNode != 0) && (here-> B3SOIFDicNode != 0))
                    here->B3SOIFDIcPtr = here->B3SOIFDIcBinding->CSC ;

                if ((here-> B3SOIFDibsNode != 0) && (here-> B3SOIFDibsNode != 0))
                    here->B3SOIFDIbsPtr = here->B3SOIFDIbsBinding->CSC ;

                if ((here-> B3SOIFDibdNode != 0) && (here-> B3SOIFDibdNode != 0))
                    here->B3SOIFDIbdPtr = here->B3SOIFDIbdBinding->CSC ;

                if ((here-> B3SOIFDiiiNode != 0) && (here-> B3SOIFDiiiNode != 0))
                    here->B3SOIFDIiiPtr = here->B3SOIFDIiiBinding->CSC ;

                if ((here-> B3SOIFDigidlNode != 0) && (here-> B3SOIFDigidlNode != 0))
                    here->B3SOIFDIgidlPtr = here->B3SOIFDIgidlBinding->CSC ;

                if ((here-> B3SOIFDitunNode != 0) && (here-> B3SOIFDitunNode != 0))
                    here->B3SOIFDItunPtr = here->B3SOIFDItunBinding->CSC ;

                if ((here-> B3SOIFDibpNode != 0) && (here-> B3SOIFDibpNode != 0))
                    here->B3SOIFDIbpPtr = here->B3SOIFDIbpBinding->CSC ;

                if ((here-> B3SOIFDabeffNode != 0) && (here-> B3SOIFDabeffNode != 0))
                    here->B3SOIFDAbeffPtr = here->B3SOIFDAbeffBinding->CSC ;

                if ((here-> B3SOIFDvbs0effNode != 0) && (here-> B3SOIFDvbs0effNode != 0))
                    here->B3SOIFDVbs0effPtr = here->B3SOIFDVbs0effBinding->CSC ;

                if ((here-> B3SOIFDvbseffNode != 0) && (here-> B3SOIFDvbseffNode != 0))
                    here->B3SOIFDVbseffPtr = here->B3SOIFDVbseffBinding->CSC ;

                if ((here-> B3SOIFDxcNode != 0) && (here-> B3SOIFDxcNode != 0))
                    here->B3SOIFDXcPtr = here->B3SOIFDXcBinding->CSC ;

                if ((here-> B3SOIFDcbbNode != 0) && (here-> B3SOIFDcbbNode != 0))
                    here->B3SOIFDCbbPtr = here->B3SOIFDCbbBinding->CSC ;

                if ((here-> B3SOIFDcbdNode != 0) && (here-> B3SOIFDcbdNode != 0))
                    here->B3SOIFDCbdPtr = here->B3SOIFDCbdBinding->CSC ;

                if ((here-> B3SOIFDcbgNode != 0) && (here-> B3SOIFDcbgNode != 0))
                    here->B3SOIFDCbgPtr = here->B3SOIFDCbgBinding->CSC ;

                if ((here-> B3SOIFDqbNode != 0) && (here-> B3SOIFDqbNode != 0))
                    here->B3SOIFDqbPtr = here->B3SOIFDqbBinding->CSC ;

                if ((here-> B3SOIFDqbfNode != 0) && (here-> B3SOIFDqbfNode != 0))
                    here->B3SOIFDQbfPtr = here->B3SOIFDQbfBinding->CSC ;

                if ((here-> B3SOIFDqjsNode != 0) && (here-> B3SOIFDqjsNode != 0))
                    here->B3SOIFDQjsPtr = here->B3SOIFDQjsBinding->CSC ;

                if ((here-> B3SOIFDqjdNode != 0) && (here-> B3SOIFDqjdNode != 0))
                    here->B3SOIFDQjdPtr = here->B3SOIFDQjdBinding->CSC ;

                if ((here-> B3SOIFDgmNode != 0) && (here-> B3SOIFDgmNode != 0))
                    here->B3SOIFDGmPtr = here->B3SOIFDGmBinding->CSC ;

                if ((here-> B3SOIFDgmbsNode != 0) && (here-> B3SOIFDgmbsNode != 0))
                    here->B3SOIFDGmbsPtr = here->B3SOIFDGmbsBinding->CSC ;

                if ((here-> B3SOIFDgdsNode != 0) && (here-> B3SOIFDgdsNode != 0))
                    here->B3SOIFDGdsPtr = here->B3SOIFDGdsBinding->CSC ;

                if ((here-> B3SOIFDgmeNode != 0) && (here-> B3SOIFDgmeNode != 0))
                    here->B3SOIFDGmePtr = here->B3SOIFDGmeBinding->CSC ;

                if ((here-> B3SOIFDvbs0teffNode != 0) && (here-> B3SOIFDvbs0teffNode != 0))
                    here->B3SOIFDVbs0teffPtr = here->B3SOIFDVbs0teffBinding->CSC ;

                if ((here-> B3SOIFDvthNode != 0) && (here-> B3SOIFDvthNode != 0))
                    here->B3SOIFDVthPtr = here->B3SOIFDVthBinding->CSC ;

                if ((here-> B3SOIFDvgsteffNode != 0) && (here-> B3SOIFDvgsteffNode != 0))
                    here->B3SOIFDVgsteffPtr = here->B3SOIFDVgsteffBinding->CSC ;

                if ((here-> B3SOIFDxcsatNode != 0) && (here-> B3SOIFDxcsatNode != 0))
                    here->B3SOIFDXcsatPtr = here->B3SOIFDXcsatBinding->CSC ;

                if ((here-> B3SOIFDvcscvNode != 0) && (here-> B3SOIFDvcscvNode != 0))
                    here->B3SOIFDVcscvPtr = here->B3SOIFDVcscvBinding->CSC ;

                if ((here-> B3SOIFDvdscvNode != 0) && (here-> B3SOIFDvdscvNode != 0))
                    here->B3SOIFDVdscvPtr = here->B3SOIFDVdscvBinding->CSC ;

                if ((here-> B3SOIFDcbeNode != 0) && (here-> B3SOIFDcbeNode != 0))
                    here->B3SOIFDCbePtr = here->B3SOIFDCbeBinding->CSC ;

                if ((here-> B3SOIFDdum1Node != 0) && (here-> B3SOIFDdum1Node != 0))
                    here->B3SOIFDDum1Ptr = here->B3SOIFDDum1Binding->CSC ;

                if ((here-> B3SOIFDdum2Node != 0) && (here-> B3SOIFDdum2Node != 0))
                    here->B3SOIFDDum2Ptr = here->B3SOIFDDum2Binding->CSC ;

                if ((here-> B3SOIFDdum3Node != 0) && (here-> B3SOIFDdum3Node != 0))
                    here->B3SOIFDDum3Ptr = here->B3SOIFDDum3Binding->CSC ;

                if ((here-> B3SOIFDdum4Node != 0) && (here-> B3SOIFDdum4Node != 0))
                    here->B3SOIFDDum4Ptr = here->B3SOIFDDum4Binding->CSC ;

                if ((here-> B3SOIFDdum5Node != 0) && (here-> B3SOIFDdum5Node != 0))
                    here->B3SOIFDDum5Ptr = here->B3SOIFDDum5Binding->CSC ;

                if ((here-> B3SOIFDqaccNode != 0) && (here-> B3SOIFDqaccNode != 0))
                    here->B3SOIFDQaccPtr = here->B3SOIFDQaccBinding->CSC ;

                if ((here-> B3SOIFDqsub0Node != 0) && (here-> B3SOIFDqsub0Node != 0))
                    here->B3SOIFDQsub0Ptr = here->B3SOIFDQsub0Binding->CSC ;

                if ((here-> B3SOIFDqsubs1Node != 0) && (here-> B3SOIFDqsubs1Node != 0))
                    here->B3SOIFDQsubs1Ptr = here->B3SOIFDQsubs1Binding->CSC ;

                if ((here-> B3SOIFDqsubs2Node != 0) && (here-> B3SOIFDqsubs2Node != 0))
                    here->B3SOIFDQsubs2Ptr = here->B3SOIFDQsubs2Binding->CSC ;

                if ((here-> B3SOIFDqeNode != 0) && (here-> B3SOIFDqeNode != 0))
                    here->B3SOIFDqePtr = here->B3SOIFDqeBinding->CSC ;

                if ((here-> B3SOIFDqdNode != 0) && (here-> B3SOIFDqdNode != 0))
                    here->B3SOIFDqdPtr = here->B3SOIFDqdBinding->CSC ;

                if ((here-> B3SOIFDqgNode != 0) && (here-> B3SOIFDqgNode != 0))
                    here->B3SOIFDqgPtr = here->B3SOIFDqgBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
