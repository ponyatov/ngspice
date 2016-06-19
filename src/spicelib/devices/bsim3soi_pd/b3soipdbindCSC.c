/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b3soipddef.h"
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
B3SOIPDbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIPDmodel *model = (B3SOIPDmodel *)inModel ;
    B3SOIPDinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B3SOIPD models */
    for ( ; model != NULL ; model = model->B3SOIPDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIPDinstances ; here != NULL ; here = here->B3SOIPDnextInstance)
        {
            if ((model->B3SOIPDshMod == 1) && (here->B3SOIPDrth0 != 0.0))
            {
                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDtempNode != 0))
                {
                    i = here->B3SOIPDTemptempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDTemptempBinding = matched ;
                    here->B3SOIPDTemptempPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                {
                    i = here->B3SOIPDTempdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDTempdpBinding = matched ;
                    here->B3SOIPDTempdpPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                {
                    i = here->B3SOIPDTempspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDTempspBinding = matched ;
                    here->B3SOIPDTempspPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDgNode != 0))
                {
                    i = here->B3SOIPDTempgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDTempgBinding = matched ;
                    here->B3SOIPDTempgPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDbNode != 0))
                {
                    i = here->B3SOIPDTempbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDTempbBinding = matched ;
                    here->B3SOIPDTempbPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDtempNode != 0))
                {
                    i = here->B3SOIPDGtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDGtempBinding = matched ;
                    here->B3SOIPDGtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDtempNode != 0))
                {
                    i = here->B3SOIPDDPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDDPtempBinding = matched ;
                    here->B3SOIPDDPtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDtempNode != 0))
                {
                    i = here->B3SOIPDSPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDSPtempBinding = matched ;
                    here->B3SOIPDSPtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDtempNode != 0))
                {
                    i = here->B3SOIPDEtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDEtempBinding = matched ;
                    here->B3SOIPDEtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDtempNode != 0))
                {
                    i = here->B3SOIPDBtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDBtempBinding = matched ;
                    here->B3SOIPDBtempPtr = matched->CSC ;
                }

                if (here->B3SOIPDbodyMod == 1)
                {
                    if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDtempNode != 0))
                    {
                        i = here->B3SOIPDPtempPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B3SOIPDPtempBinding = matched ;
                        here->B3SOIPDPtempPtr = matched->CSC ;
                    }

                }
            }
            if (here->B3SOIPDbodyMod == 2)
            {
            }
            else if (here->B3SOIPDbodyMod == 1)
            {
                if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDpNode != 0))
                {
                    i = here->B3SOIPDBpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDBpBinding = matched ;
                    here->B3SOIPDBpPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDbNode != 0))
                {
                    i = here->B3SOIPDPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDPbBinding = matched ;
                    here->B3SOIPDPbPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDpNode != 0))
                {
                    i = here->B3SOIPDPpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDPpBinding = matched ;
                    here->B3SOIPDPpPtr = matched->CSC ;
                }

            }
            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDbNode != 0))
            {
                i = here->B3SOIPDEbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDEbBinding = matched ;
                here->B3SOIPDEbPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDbNode != 0))
            {
                i = here->B3SOIPDGbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDGbBinding = matched ;
                here->B3SOIPDGbPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDbNode != 0))
            {
                i = here->B3SOIPDDPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDPbBinding = matched ;
                here->B3SOIPDDPbPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDbNode != 0))
            {
                i = here->B3SOIPDSPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSPbBinding = matched ;
                here->B3SOIPDSPbPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDeNode != 0))
            {
                i = here->B3SOIPDBePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDBeBinding = matched ;
                here->B3SOIPDBePtr = matched->CSC ;
            }

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDgNode != 0))
            {
                i = here->B3SOIPDBgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDBgBinding = matched ;
                here->B3SOIPDBgPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDdNodePrime != 0))
            {
                i = here->B3SOIPDBdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDBdpBinding = matched ;
                here->B3SOIPDBdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDsNodePrime != 0))
            {
                i = here->B3SOIPDBspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDBspBinding = matched ;
                here->B3SOIPDBspPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDbNode != 0))
            {
                i = here->B3SOIPDBbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDBbBinding = matched ;
                here->B3SOIPDBbPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDgNode != 0))
            {
                i = here->B3SOIPDEgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDEgBinding = matched ;
                here->B3SOIPDEgPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDdNodePrime != 0))
            {
                i = here->B3SOIPDEdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDEdpBinding = matched ;
                here->B3SOIPDEdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDsNodePrime != 0))
            {
                i = here->B3SOIPDEspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDEspBinding = matched ;
                here->B3SOIPDEspPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDeNode != 0))
            {
                i = here->B3SOIPDGePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDGeBinding = matched ;
                here->B3SOIPDGePtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDeNode != 0))
            {
                i = here->B3SOIPDDPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDPeBinding = matched ;
                here->B3SOIPDDPePtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDeNode != 0))
            {
                i = here->B3SOIPDSPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSPeBinding = matched ;
                here->B3SOIPDSPePtr = matched->CSC ;
            }

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDeNode != 0))
            {
                i = here->B3SOIPDEePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDEeBinding = matched ;
                here->B3SOIPDEePtr = matched->CSC ;
            }

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDgNode != 0))
            {
                i = here->B3SOIPDGgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDGgBinding = matched ;
                here->B3SOIPDGgPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDdNodePrime != 0))
            {
                i = here->B3SOIPDGdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDGdpBinding = matched ;
                here->B3SOIPDGdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDsNodePrime != 0))
            {
                i = here->B3SOIPDGspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDGspBinding = matched ;
                here->B3SOIPDGspPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDgNode != 0))
            {
                i = here->B3SOIPDDPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDPgBinding = matched ;
                here->B3SOIPDDPgPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDdNodePrime != 0))
            {
                i = here->B3SOIPDDPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDPdpBinding = matched ;
                here->B3SOIPDDPdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDsNodePrime != 0))
            {
                i = here->B3SOIPDDPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDPspBinding = matched ;
                here->B3SOIPDDPspPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDdNode != 0))
            {
                i = here->B3SOIPDDPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDPdBinding = matched ;
                here->B3SOIPDDPdPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDgNode != 0))
            {
                i = here->B3SOIPDSPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSPgBinding = matched ;
                here->B3SOIPDSPgPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDdNodePrime != 0))
            {
                i = here->B3SOIPDSPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSPdpBinding = matched ;
                here->B3SOIPDSPdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDsNodePrime != 0))
            {
                i = here->B3SOIPDSPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSPspBinding = matched ;
                here->B3SOIPDSPspPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDsNode != 0))
            {
                i = here->B3SOIPDSPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSPsBinding = matched ;
                here->B3SOIPDSPsPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNode != 0) && (here-> B3SOIPDdNode != 0))
            {
                i = here->B3SOIPDDdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDdBinding = matched ;
                here->B3SOIPDDdPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDdNode != 0) && (here-> B3SOIPDdNodePrime != 0))
            {
                i = here->B3SOIPDDdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDDdpBinding = matched ;
                here->B3SOIPDDdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNode != 0) && (here-> B3SOIPDsNode != 0))
            {
                i = here->B3SOIPDSsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSsBinding = matched ;
                here->B3SOIPDSsPtr = matched->CSC ;
            }

            if ((here-> B3SOIPDsNode != 0) && (here-> B3SOIPDsNodePrime != 0))
            {
                i = here->B3SOIPDSspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIPDSspBinding = matched ;
                here->B3SOIPDSspPtr = matched->CSC ;
            }

            if (here->B3SOIPDdebugMod != 0)
            {
                if ((here-> B3SOIPDvbsNode != 0) && (here-> B3SOIPDvbsNode != 0))
                {
                    i = here->B3SOIPDVbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDVbsBinding = matched ;
                    here->B3SOIPDVbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDidsNode != 0) && (here-> B3SOIPDidsNode != 0))
                {
                    i = here->B3SOIPDIdsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIdsBinding = matched ;
                    here->B3SOIPDIdsPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDicNode != 0) && (here-> B3SOIPDicNode != 0))
                {
                    i = here->B3SOIPDIcPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIcBinding = matched ;
                    here->B3SOIPDIcPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDibsNode != 0) && (here-> B3SOIPDibsNode != 0))
                {
                    i = here->B3SOIPDIbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIbsBinding = matched ;
                    here->B3SOIPDIbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDibdNode != 0) && (here-> B3SOIPDibdNode != 0))
                {
                    i = here->B3SOIPDIbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIbdBinding = matched ;
                    here->B3SOIPDIbdPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDiiiNode != 0) && (here-> B3SOIPDiiiNode != 0))
                {
                    i = here->B3SOIPDIiiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIiiBinding = matched ;
                    here->B3SOIPDIiiPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDigNode != 0) && (here-> B3SOIPDigNode != 0))
                {
                    i = here->B3SOIPDIgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIgBinding = matched ;
                    here->B3SOIPDIgPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDgiggNode != 0) && (here-> B3SOIPDgiggNode != 0))
                {
                    i = here->B3SOIPDGiggPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDGiggBinding = matched ;
                    here->B3SOIPDGiggPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDgigdNode != 0) && (here-> B3SOIPDgigdNode != 0))
                {
                    i = here->B3SOIPDGigdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDGigdBinding = matched ;
                    here->B3SOIPDGigdPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDgigbNode != 0) && (here-> B3SOIPDgigbNode != 0))
                {
                    i = here->B3SOIPDGigbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDGigbBinding = matched ;
                    here->B3SOIPDGigbPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDigidlNode != 0) && (here-> B3SOIPDigidlNode != 0))
                {
                    i = here->B3SOIPDIgidlPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIgidlBinding = matched ;
                    here->B3SOIPDIgidlPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDitunNode != 0) && (here-> B3SOIPDitunNode != 0))
                {
                    i = here->B3SOIPDItunPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDItunBinding = matched ;
                    here->B3SOIPDItunPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDibpNode != 0) && (here-> B3SOIPDibpNode != 0))
                {
                    i = here->B3SOIPDIbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDIbpBinding = matched ;
                    here->B3SOIPDIbpPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDcbbNode != 0) && (here-> B3SOIPDcbbNode != 0))
                {
                    i = here->B3SOIPDCbbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDCbbBinding = matched ;
                    here->B3SOIPDCbbPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDcbdNode != 0) && (here-> B3SOIPDcbdNode != 0))
                {
                    i = here->B3SOIPDCbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDCbdBinding = matched ;
                    here->B3SOIPDCbdPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDcbgNode != 0) && (here-> B3SOIPDcbgNode != 0))
                {
                    i = here->B3SOIPDCbgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDCbgBinding = matched ;
                    here->B3SOIPDCbgPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDqbfNode != 0) && (here-> B3SOIPDqbfNode != 0))
                {
                    i = here->B3SOIPDQbfPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDQbfBinding = matched ;
                    here->B3SOIPDQbfPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDqjsNode != 0) && (here-> B3SOIPDqjsNode != 0))
                {
                    i = here->B3SOIPDQjsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDQjsBinding = matched ;
                    here->B3SOIPDQjsPtr = matched->CSC ;
                }

                if ((here-> B3SOIPDqjdNode != 0) && (here-> B3SOIPDqjdNode != 0))
                {
                    i = here->B3SOIPDQjdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIPDQjdBinding = matched ;
                    here->B3SOIPDQjdPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
B3SOIPDbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIPDmodel *model = (B3SOIPDmodel *)inModel ;
    B3SOIPDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B3SOIPD models */
    for ( ; model != NULL ; model = model->B3SOIPDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIPDinstances ; here != NULL ; here = here->B3SOIPDnextInstance)
        {
            if ((model->B3SOIPDshMod == 1) && (here->B3SOIPDrth0 != 0.0))
            {
                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDTemptempPtr = here->B3SOIPDTemptempBinding->CSC_Complex ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                    here->B3SOIPDTempdpPtr = here->B3SOIPDTempdpBinding->CSC_Complex ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                    here->B3SOIPDTempspPtr = here->B3SOIPDTempspBinding->CSC_Complex ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDgNode != 0))
                    here->B3SOIPDTempgPtr = here->B3SOIPDTempgBinding->CSC_Complex ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDbNode != 0))
                    here->B3SOIPDTempbPtr = here->B3SOIPDTempbBinding->CSC_Complex ;

                if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDGtempPtr = here->B3SOIPDGtempBinding->CSC_Complex ;

                if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDDPtempPtr = here->B3SOIPDDPtempBinding->CSC_Complex ;

                if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDSPtempPtr = here->B3SOIPDSPtempBinding->CSC_Complex ;

                if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDEtempPtr = here->B3SOIPDEtempBinding->CSC_Complex ;

                if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDBtempPtr = here->B3SOIPDBtempBinding->CSC_Complex ;

                if (here->B3SOIPDbodyMod == 1)
                {
                    if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDtempNode != 0))
                        here->B3SOIPDPtempPtr = here->B3SOIPDPtempBinding->CSC_Complex ;

                }
            }
            if (here->B3SOIPDbodyMod == 2)
            {
            }
            else if (here->B3SOIPDbodyMod == 1)
            {
                if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDpNode != 0))
                    here->B3SOIPDBpPtr = here->B3SOIPDBpBinding->CSC_Complex ;

                if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDbNode != 0))
                    here->B3SOIPDPbPtr = here->B3SOIPDPbBinding->CSC_Complex ;

                if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDpNode != 0))
                    here->B3SOIPDPpPtr = here->B3SOIPDPpBinding->CSC_Complex ;

            }
            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDEbPtr = here->B3SOIPDEbBinding->CSC_Complex ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDGbPtr = here->B3SOIPDGbBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDDPbPtr = here->B3SOIPDDPbBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDSPbPtr = here->B3SOIPDSPbBinding->CSC_Complex ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDBePtr = here->B3SOIPDBeBinding->CSC_Complex ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDBgPtr = here->B3SOIPDBgBinding->CSC_Complex ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDBdpPtr = here->B3SOIPDBdpBinding->CSC_Complex ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDBspPtr = here->B3SOIPDBspBinding->CSC_Complex ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDBbPtr = here->B3SOIPDBbBinding->CSC_Complex ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDEgPtr = here->B3SOIPDEgBinding->CSC_Complex ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDEdpPtr = here->B3SOIPDEdpBinding->CSC_Complex ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDEspPtr = here->B3SOIPDEspBinding->CSC_Complex ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDGePtr = here->B3SOIPDGeBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDDPePtr = here->B3SOIPDDPeBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDSPePtr = here->B3SOIPDSPeBinding->CSC_Complex ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDEePtr = here->B3SOIPDEeBinding->CSC_Complex ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDGgPtr = here->B3SOIPDGgBinding->CSC_Complex ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDGdpPtr = here->B3SOIPDGdpBinding->CSC_Complex ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDGspPtr = here->B3SOIPDGspBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDDPgPtr = here->B3SOIPDDPgBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDDPdpPtr = here->B3SOIPDDPdpBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDDPspPtr = here->B3SOIPDDPspBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDdNode != 0))
                here->B3SOIPDDPdPtr = here->B3SOIPDDPdBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDSPgPtr = here->B3SOIPDSPgBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDSPdpPtr = here->B3SOIPDSPdpBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDSPspPtr = here->B3SOIPDSPspBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDsNode != 0))
                here->B3SOIPDSPsPtr = here->B3SOIPDSPsBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNode != 0) && (here-> B3SOIPDdNode != 0))
                here->B3SOIPDDdPtr = here->B3SOIPDDdBinding->CSC_Complex ;

            if ((here-> B3SOIPDdNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDDdpPtr = here->B3SOIPDDdpBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNode != 0) && (here-> B3SOIPDsNode != 0))
                here->B3SOIPDSsPtr = here->B3SOIPDSsBinding->CSC_Complex ;

            if ((here-> B3SOIPDsNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDSspPtr = here->B3SOIPDSspBinding->CSC_Complex ;

            if (here->B3SOIPDdebugMod != 0)
            {
                if ((here-> B3SOIPDvbsNode != 0) && (here-> B3SOIPDvbsNode != 0))
                    here->B3SOIPDVbsPtr = here->B3SOIPDVbsBinding->CSC_Complex ;

                if ((here-> B3SOIPDidsNode != 0) && (here-> B3SOIPDidsNode != 0))
                    here->B3SOIPDIdsPtr = here->B3SOIPDIdsBinding->CSC_Complex ;

                if ((here-> B3SOIPDicNode != 0) && (here-> B3SOIPDicNode != 0))
                    here->B3SOIPDIcPtr = here->B3SOIPDIcBinding->CSC_Complex ;

                if ((here-> B3SOIPDibsNode != 0) && (here-> B3SOIPDibsNode != 0))
                    here->B3SOIPDIbsPtr = here->B3SOIPDIbsBinding->CSC_Complex ;

                if ((here-> B3SOIPDibdNode != 0) && (here-> B3SOIPDibdNode != 0))
                    here->B3SOIPDIbdPtr = here->B3SOIPDIbdBinding->CSC_Complex ;

                if ((here-> B3SOIPDiiiNode != 0) && (here-> B3SOIPDiiiNode != 0))
                    here->B3SOIPDIiiPtr = here->B3SOIPDIiiBinding->CSC_Complex ;

                if ((here-> B3SOIPDigNode != 0) && (here-> B3SOIPDigNode != 0))
                    here->B3SOIPDIgPtr = here->B3SOIPDIgBinding->CSC_Complex ;

                if ((here-> B3SOIPDgiggNode != 0) && (here-> B3SOIPDgiggNode != 0))
                    here->B3SOIPDGiggPtr = here->B3SOIPDGiggBinding->CSC_Complex ;

                if ((here-> B3SOIPDgigdNode != 0) && (here-> B3SOIPDgigdNode != 0))
                    here->B3SOIPDGigdPtr = here->B3SOIPDGigdBinding->CSC_Complex ;

                if ((here-> B3SOIPDgigbNode != 0) && (here-> B3SOIPDgigbNode != 0))
                    here->B3SOIPDGigbPtr = here->B3SOIPDGigbBinding->CSC_Complex ;

                if ((here-> B3SOIPDigidlNode != 0) && (here-> B3SOIPDigidlNode != 0))
                    here->B3SOIPDIgidlPtr = here->B3SOIPDIgidlBinding->CSC_Complex ;

                if ((here-> B3SOIPDitunNode != 0) && (here-> B3SOIPDitunNode != 0))
                    here->B3SOIPDItunPtr = here->B3SOIPDItunBinding->CSC_Complex ;

                if ((here-> B3SOIPDibpNode != 0) && (here-> B3SOIPDibpNode != 0))
                    here->B3SOIPDIbpPtr = here->B3SOIPDIbpBinding->CSC_Complex ;

                if ((here-> B3SOIPDcbbNode != 0) && (here-> B3SOIPDcbbNode != 0))
                    here->B3SOIPDCbbPtr = here->B3SOIPDCbbBinding->CSC_Complex ;

                if ((here-> B3SOIPDcbdNode != 0) && (here-> B3SOIPDcbdNode != 0))
                    here->B3SOIPDCbdPtr = here->B3SOIPDCbdBinding->CSC_Complex ;

                if ((here-> B3SOIPDcbgNode != 0) && (here-> B3SOIPDcbgNode != 0))
                    here->B3SOIPDCbgPtr = here->B3SOIPDCbgBinding->CSC_Complex ;

                if ((here-> B3SOIPDqbfNode != 0) && (here-> B3SOIPDqbfNode != 0))
                    here->B3SOIPDQbfPtr = here->B3SOIPDQbfBinding->CSC_Complex ;

                if ((here-> B3SOIPDqjsNode != 0) && (here-> B3SOIPDqjsNode != 0))
                    here->B3SOIPDQjsPtr = here->B3SOIPDQjsBinding->CSC_Complex ;

                if ((here-> B3SOIPDqjdNode != 0) && (here-> B3SOIPDqjdNode != 0))
                    here->B3SOIPDQjdPtr = here->B3SOIPDQjdBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
B3SOIPDbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIPDmodel *model = (B3SOIPDmodel *)inModel ;
    B3SOIPDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B3SOIPD models */
    for ( ; model != NULL ; model = model->B3SOIPDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIPDinstances ; here != NULL ; here = here->B3SOIPDnextInstance)
        {
            if ((model->B3SOIPDshMod == 1) && (here->B3SOIPDrth0 != 0.0))
            {
                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDTemptempPtr = here->B3SOIPDTemptempBinding->CSC ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                    here->B3SOIPDTempdpPtr = here->B3SOIPDTempdpBinding->CSC ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                    here->B3SOIPDTempspPtr = here->B3SOIPDTempspBinding->CSC ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDgNode != 0))
                    here->B3SOIPDTempgPtr = here->B3SOIPDTempgBinding->CSC ;

                if ((here-> B3SOIPDtempNode != 0) && (here-> B3SOIPDbNode != 0))
                    here->B3SOIPDTempbPtr = here->B3SOIPDTempbBinding->CSC ;

                if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDGtempPtr = here->B3SOIPDGtempBinding->CSC ;

                if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDDPtempPtr = here->B3SOIPDDPtempBinding->CSC ;

                if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDSPtempPtr = here->B3SOIPDSPtempBinding->CSC ;

                if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDEtempPtr = here->B3SOIPDEtempBinding->CSC ;

                if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDtempNode != 0))
                    here->B3SOIPDBtempPtr = here->B3SOIPDBtempBinding->CSC ;

                if (here->B3SOIPDbodyMod == 1)
                {
                    if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDtempNode != 0))
                        here->B3SOIPDPtempPtr = here->B3SOIPDPtempBinding->CSC ;

                }
            }
            if (here->B3SOIPDbodyMod == 2)
            {
            }
            else if (here->B3SOIPDbodyMod == 1)
            {
                if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDpNode != 0))
                    here->B3SOIPDBpPtr = here->B3SOIPDBpBinding->CSC ;

                if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDbNode != 0))
                    here->B3SOIPDPbPtr = here->B3SOIPDPbBinding->CSC ;

                if ((here-> B3SOIPDpNode != 0) && (here-> B3SOIPDpNode != 0))
                    here->B3SOIPDPpPtr = here->B3SOIPDPpBinding->CSC ;

            }
            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDEbPtr = here->B3SOIPDEbBinding->CSC ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDGbPtr = here->B3SOIPDGbBinding->CSC ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDDPbPtr = here->B3SOIPDDPbBinding->CSC ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDSPbPtr = here->B3SOIPDSPbBinding->CSC ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDBePtr = here->B3SOIPDBeBinding->CSC ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDBgPtr = here->B3SOIPDBgBinding->CSC ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDBdpPtr = here->B3SOIPDBdpBinding->CSC ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDBspPtr = here->B3SOIPDBspBinding->CSC ;

            if ((here-> B3SOIPDbNode != 0) && (here-> B3SOIPDbNode != 0))
                here->B3SOIPDBbPtr = here->B3SOIPDBbBinding->CSC ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDEgPtr = here->B3SOIPDEgBinding->CSC ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDEdpPtr = here->B3SOIPDEdpBinding->CSC ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDEspPtr = here->B3SOIPDEspBinding->CSC ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDGePtr = here->B3SOIPDGeBinding->CSC ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDDPePtr = here->B3SOIPDDPeBinding->CSC ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDSPePtr = here->B3SOIPDSPeBinding->CSC ;

            if ((here-> B3SOIPDeNode != 0) && (here-> B3SOIPDeNode != 0))
                here->B3SOIPDEePtr = here->B3SOIPDEeBinding->CSC ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDGgPtr = here->B3SOIPDGgBinding->CSC ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDGdpPtr = here->B3SOIPDGdpBinding->CSC ;

            if ((here-> B3SOIPDgNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDGspPtr = here->B3SOIPDGspBinding->CSC ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDDPgPtr = here->B3SOIPDDPgBinding->CSC ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDDPdpPtr = here->B3SOIPDDPdpBinding->CSC ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDDPspPtr = here->B3SOIPDDPspBinding->CSC ;

            if ((here-> B3SOIPDdNodePrime != 0) && (here-> B3SOIPDdNode != 0))
                here->B3SOIPDDPdPtr = here->B3SOIPDDPdBinding->CSC ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDgNode != 0))
                here->B3SOIPDSPgPtr = here->B3SOIPDSPgBinding->CSC ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDSPdpPtr = here->B3SOIPDSPdpBinding->CSC ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDSPspPtr = here->B3SOIPDSPspBinding->CSC ;

            if ((here-> B3SOIPDsNodePrime != 0) && (here-> B3SOIPDsNode != 0))
                here->B3SOIPDSPsPtr = here->B3SOIPDSPsBinding->CSC ;

            if ((here-> B3SOIPDdNode != 0) && (here-> B3SOIPDdNode != 0))
                here->B3SOIPDDdPtr = here->B3SOIPDDdBinding->CSC ;

            if ((here-> B3SOIPDdNode != 0) && (here-> B3SOIPDdNodePrime != 0))
                here->B3SOIPDDdpPtr = here->B3SOIPDDdpBinding->CSC ;

            if ((here-> B3SOIPDsNode != 0) && (here-> B3SOIPDsNode != 0))
                here->B3SOIPDSsPtr = here->B3SOIPDSsBinding->CSC ;

            if ((here-> B3SOIPDsNode != 0) && (here-> B3SOIPDsNodePrime != 0))
                here->B3SOIPDSspPtr = here->B3SOIPDSspBinding->CSC ;

            if (here->B3SOIPDdebugMod != 0)
            {
                if ((here-> B3SOIPDvbsNode != 0) && (here-> B3SOIPDvbsNode != 0))
                    here->B3SOIPDVbsPtr = here->B3SOIPDVbsBinding->CSC ;

                if ((here-> B3SOIPDidsNode != 0) && (here-> B3SOIPDidsNode != 0))
                    here->B3SOIPDIdsPtr = here->B3SOIPDIdsBinding->CSC ;

                if ((here-> B3SOIPDicNode != 0) && (here-> B3SOIPDicNode != 0))
                    here->B3SOIPDIcPtr = here->B3SOIPDIcBinding->CSC ;

                if ((here-> B3SOIPDibsNode != 0) && (here-> B3SOIPDibsNode != 0))
                    here->B3SOIPDIbsPtr = here->B3SOIPDIbsBinding->CSC ;

                if ((here-> B3SOIPDibdNode != 0) && (here-> B3SOIPDibdNode != 0))
                    here->B3SOIPDIbdPtr = here->B3SOIPDIbdBinding->CSC ;

                if ((here-> B3SOIPDiiiNode != 0) && (here-> B3SOIPDiiiNode != 0))
                    here->B3SOIPDIiiPtr = here->B3SOIPDIiiBinding->CSC ;

                if ((here-> B3SOIPDigNode != 0) && (here-> B3SOIPDigNode != 0))
                    here->B3SOIPDIgPtr = here->B3SOIPDIgBinding->CSC ;

                if ((here-> B3SOIPDgiggNode != 0) && (here-> B3SOIPDgiggNode != 0))
                    here->B3SOIPDGiggPtr = here->B3SOIPDGiggBinding->CSC ;

                if ((here-> B3SOIPDgigdNode != 0) && (here-> B3SOIPDgigdNode != 0))
                    here->B3SOIPDGigdPtr = here->B3SOIPDGigdBinding->CSC ;

                if ((here-> B3SOIPDgigbNode != 0) && (here-> B3SOIPDgigbNode != 0))
                    here->B3SOIPDGigbPtr = here->B3SOIPDGigbBinding->CSC ;

                if ((here-> B3SOIPDigidlNode != 0) && (here-> B3SOIPDigidlNode != 0))
                    here->B3SOIPDIgidlPtr = here->B3SOIPDIgidlBinding->CSC ;

                if ((here-> B3SOIPDitunNode != 0) && (here-> B3SOIPDitunNode != 0))
                    here->B3SOIPDItunPtr = here->B3SOIPDItunBinding->CSC ;

                if ((here-> B3SOIPDibpNode != 0) && (here-> B3SOIPDibpNode != 0))
                    here->B3SOIPDIbpPtr = here->B3SOIPDIbpBinding->CSC ;

                if ((here-> B3SOIPDcbbNode != 0) && (here-> B3SOIPDcbbNode != 0))
                    here->B3SOIPDCbbPtr = here->B3SOIPDCbbBinding->CSC ;

                if ((here-> B3SOIPDcbdNode != 0) && (here-> B3SOIPDcbdNode != 0))
                    here->B3SOIPDCbdPtr = here->B3SOIPDCbdBinding->CSC ;

                if ((here-> B3SOIPDcbgNode != 0) && (here-> B3SOIPDcbgNode != 0))
                    here->B3SOIPDCbgPtr = here->B3SOIPDCbgBinding->CSC ;

                if ((here-> B3SOIPDqbfNode != 0) && (here-> B3SOIPDqbfNode != 0))
                    here->B3SOIPDQbfPtr = here->B3SOIPDQbfBinding->CSC ;

                if ((here-> B3SOIPDqjsNode != 0) && (here-> B3SOIPDqjsNode != 0))
                    here->B3SOIPDQjsPtr = here->B3SOIPDQjsBinding->CSC ;

                if ((here-> B3SOIPDqjdNode != 0) && (here-> B3SOIPDqjdNode != 0))
                    here->B3SOIPDQjdPtr = here->B3SOIPDQjdBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
