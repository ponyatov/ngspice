/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b3soidddef.h"
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
B3SOIDDbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIDDmodel *model = (B3SOIDDmodel *)inModel ;
    B3SOIDDinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B3SOIDD models */
    for ( ; model != NULL ; model = model->B3SOIDDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIDDinstances ; here != NULL ; here = here->B3SOIDDnextInstance)
        {
            if ((model->B3SOIDDshMod == 1) && (here->B3SOIDDrth0 != 0.0))
            {
                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDtempNode != 0))
                {
                    i = here->B3SOIDDTemptempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDTemptempBinding = matched ;
                    here->B3SOIDDTemptempPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                {
                    i = here->B3SOIDDTempdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDTempdpBinding = matched ;
                    here->B3SOIDDTempdpPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                {
                    i = here->B3SOIDDTempspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDTempspBinding = matched ;
                    here->B3SOIDDTempspPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDgNode != 0))
                {
                    i = here->B3SOIDDTempgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDTempgBinding = matched ;
                    here->B3SOIDDTempgPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDbNode != 0))
                {
                    i = here->B3SOIDDTempbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDTempbBinding = matched ;
                    here->B3SOIDDTempbPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDeNode != 0))
                {
                    i = here->B3SOIDDTempePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDTempeBinding = matched ;
                    here->B3SOIDDTempePtr = matched->CSC ;
                }

                if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDtempNode != 0))
                {
                    i = here->B3SOIDDGtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDGtempBinding = matched ;
                    here->B3SOIDDGtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDtempNode != 0))
                {
                    i = here->B3SOIDDDPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDDPtempBinding = matched ;
                    here->B3SOIDDDPtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDtempNode != 0))
                {
                    i = here->B3SOIDDSPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDSPtempBinding = matched ;
                    here->B3SOIDDSPtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDtempNode != 0))
                {
                    i = here->B3SOIDDEtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDEtempBinding = matched ;
                    here->B3SOIDDEtempPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDtempNode != 0))
                {
                    i = here->B3SOIDDBtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDBtempBinding = matched ;
                    here->B3SOIDDBtempPtr = matched->CSC ;
                }

                if (here->B3SOIDDbodyMod == 1)
                {
                    if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDtempNode != 0))
                    {
                        i = here->B3SOIDDPtempPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B3SOIDDPtempBinding = matched ;
                        here->B3SOIDDPtempPtr = matched->CSC ;
                    }

                }
            }
            if (here->B3SOIDDbodyMod == 2)
            {
            }
            else if (here->B3SOIDDbodyMod == 1)
            {
                if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDpNode != 0))
                {
                    i = here->B3SOIDDBpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDBpBinding = matched ;
                    here->B3SOIDDBpPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDbNode != 0))
                {
                    i = here->B3SOIDDPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDPbBinding = matched ;
                    here->B3SOIDDPbPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDpNode != 0))
                {
                    i = here->B3SOIDDPpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDPpBinding = matched ;
                    here->B3SOIDDPpPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDgNode != 0))
                {
                    i = here->B3SOIDDPgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDPgBinding = matched ;
                    here->B3SOIDDPgPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                {
                    i = here->B3SOIDDPdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDPdpBinding = matched ;
                    here->B3SOIDDPdpPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                {
                    i = here->B3SOIDDPspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDPspBinding = matched ;
                    here->B3SOIDDPspPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDeNode != 0))
                {
                    i = here->B3SOIDDPePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDPeBinding = matched ;
                    here->B3SOIDDPePtr = matched->CSC ;
                }

            }
            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDgNode != 0))
            {
                i = here->B3SOIDDEgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDEgBinding = matched ;
                here->B3SOIDDEgPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDdNodePrime != 0))
            {
                i = here->B3SOIDDEdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDEdpBinding = matched ;
                here->B3SOIDDEdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDsNodePrime != 0))
            {
                i = here->B3SOIDDEspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDEspBinding = matched ;
                here->B3SOIDDEspPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDeNode != 0))
            {
                i = here->B3SOIDDGePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDGeBinding = matched ;
                here->B3SOIDDGePtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDeNode != 0))
            {
                i = here->B3SOIDDDPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDPeBinding = matched ;
                here->B3SOIDDDPePtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDeNode != 0))
            {
                i = here->B3SOIDDSPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSPeBinding = matched ;
                here->B3SOIDDSPePtr = matched->CSC ;
            }

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDbNode != 0))
            {
                i = here->B3SOIDDEbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDEbBinding = matched ;
                here->B3SOIDDEbPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDbNode != 0))
            {
                i = here->B3SOIDDGbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDGbBinding = matched ;
                here->B3SOIDDGbPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDbNode != 0))
            {
                i = here->B3SOIDDDPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDPbBinding = matched ;
                here->B3SOIDDDPbPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDbNode != 0))
            {
                i = here->B3SOIDDSPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSPbBinding = matched ;
                here->B3SOIDDSPbPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDeNode != 0))
            {
                i = here->B3SOIDDBePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDBeBinding = matched ;
                here->B3SOIDDBePtr = matched->CSC ;
            }

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDgNode != 0))
            {
                i = here->B3SOIDDBgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDBgBinding = matched ;
                here->B3SOIDDBgPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDdNodePrime != 0))
            {
                i = here->B3SOIDDBdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDBdpBinding = matched ;
                here->B3SOIDDBdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDsNodePrime != 0))
            {
                i = here->B3SOIDDBspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDBspBinding = matched ;
                here->B3SOIDDBspPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDbNode != 0))
            {
                i = here->B3SOIDDBbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDBbBinding = matched ;
                here->B3SOIDDBbPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDeNode != 0))
            {
                i = here->B3SOIDDEePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDEeBinding = matched ;
                here->B3SOIDDEePtr = matched->CSC ;
            }

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDgNode != 0))
            {
                i = here->B3SOIDDGgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDGgBinding = matched ;
                here->B3SOIDDGgPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDdNodePrime != 0))
            {
                i = here->B3SOIDDGdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDGdpBinding = matched ;
                here->B3SOIDDGdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDsNodePrime != 0))
            {
                i = here->B3SOIDDGspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDGspBinding = matched ;
                here->B3SOIDDGspPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDgNode != 0))
            {
                i = here->B3SOIDDDPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDPgBinding = matched ;
                here->B3SOIDDDPgPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDdNodePrime != 0))
            {
                i = here->B3SOIDDDPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDPdpBinding = matched ;
                here->B3SOIDDDPdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDsNodePrime != 0))
            {
                i = here->B3SOIDDDPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDPspBinding = matched ;
                here->B3SOIDDDPspPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDdNode != 0))
            {
                i = here->B3SOIDDDPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDPdBinding = matched ;
                here->B3SOIDDDPdPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDgNode != 0))
            {
                i = here->B3SOIDDSPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSPgBinding = matched ;
                here->B3SOIDDSPgPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDdNodePrime != 0))
            {
                i = here->B3SOIDDSPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSPdpBinding = matched ;
                here->B3SOIDDSPdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDsNodePrime != 0))
            {
                i = here->B3SOIDDSPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSPspBinding = matched ;
                here->B3SOIDDSPspPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDsNode != 0))
            {
                i = here->B3SOIDDSPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSPsBinding = matched ;
                here->B3SOIDDSPsPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNode != 0) && (here-> B3SOIDDdNode != 0))
            {
                i = here->B3SOIDDDdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDdBinding = matched ;
                here->B3SOIDDDdPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDdNode != 0) && (here-> B3SOIDDdNodePrime != 0))
            {
                i = here->B3SOIDDDdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDDdpBinding = matched ;
                here->B3SOIDDDdpPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNode != 0) && (here-> B3SOIDDsNode != 0))
            {
                i = here->B3SOIDDSsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSsBinding = matched ;
                here->B3SOIDDSsPtr = matched->CSC ;
            }

            if ((here-> B3SOIDDsNode != 0) && (here-> B3SOIDDsNodePrime != 0))
            {
                i = here->B3SOIDDSspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B3SOIDDSspBinding = matched ;
                here->B3SOIDDSspPtr = matched->CSC ;
            }

            if ((here->B3SOIDDdebugMod > 1) || (here->B3SOIDDdebugMod == -1))
            {
                if ((here-> B3SOIDDvbsNode != 0) && (here-> B3SOIDDvbsNode != 0))
                {
                    i = here->B3SOIDDVbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVbsBinding = matched ;
                    here->B3SOIDDVbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDidsNode != 0) && (here-> B3SOIDDidsNode != 0))
                {
                    i = here->B3SOIDDIdsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIdsBinding = matched ;
                    here->B3SOIDDIdsPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDicNode != 0) && (here-> B3SOIDDicNode != 0))
                {
                    i = here->B3SOIDDIcPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIcBinding = matched ;
                    here->B3SOIDDIcPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDibsNode != 0) && (here-> B3SOIDDibsNode != 0))
                {
                    i = here->B3SOIDDIbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIbsBinding = matched ;
                    here->B3SOIDDIbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDibdNode != 0) && (here-> B3SOIDDibdNode != 0))
                {
                    i = here->B3SOIDDIbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIbdBinding = matched ;
                    here->B3SOIDDIbdPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDiiiNode != 0) && (here-> B3SOIDDiiiNode != 0))
                {
                    i = here->B3SOIDDIiiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIiiBinding = matched ;
                    here->B3SOIDDIiiPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDigidlNode != 0) && (here-> B3SOIDDigidlNode != 0))
                {
                    i = here->B3SOIDDIgidlPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIgidlBinding = matched ;
                    here->B3SOIDDIgidlPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDitunNode != 0) && (here-> B3SOIDDitunNode != 0))
                {
                    i = here->B3SOIDDItunPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDItunBinding = matched ;
                    here->B3SOIDDItunPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDibpNode != 0) && (here-> B3SOIDDibpNode != 0))
                {
                    i = here->B3SOIDDIbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDIbpBinding = matched ;
                    here->B3SOIDDIbpPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDabeffNode != 0) && (here-> B3SOIDDabeffNode != 0))
                {
                    i = here->B3SOIDDAbeffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDAbeffBinding = matched ;
                    here->B3SOIDDAbeffPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvbs0effNode != 0) && (here-> B3SOIDDvbs0effNode != 0))
                {
                    i = here->B3SOIDDVbs0effPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVbs0effBinding = matched ;
                    here->B3SOIDDVbs0effPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvbseffNode != 0) && (here-> B3SOIDDvbseffNode != 0))
                {
                    i = here->B3SOIDDVbseffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVbseffBinding = matched ;
                    here->B3SOIDDVbseffPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDxcNode != 0) && (here-> B3SOIDDxcNode != 0))
                {
                    i = here->B3SOIDDXcPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDXcBinding = matched ;
                    here->B3SOIDDXcPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDcbbNode != 0) && (here-> B3SOIDDcbbNode != 0))
                {
                    i = here->B3SOIDDCbbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDCbbBinding = matched ;
                    here->B3SOIDDCbbPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDcbdNode != 0) && (here-> B3SOIDDcbdNode != 0))
                {
                    i = here->B3SOIDDCbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDCbdBinding = matched ;
                    here->B3SOIDDCbdPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDcbgNode != 0) && (here-> B3SOIDDcbgNode != 0))
                {
                    i = here->B3SOIDDCbgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDCbgBinding = matched ;
                    here->B3SOIDDCbgPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqbNode != 0) && (here-> B3SOIDDqbNode != 0))
                {
                    i = here->B3SOIDDqbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDqbBinding = matched ;
                    here->B3SOIDDqbPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqbfNode != 0) && (here-> B3SOIDDqbfNode != 0))
                {
                    i = here->B3SOIDDQbfPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQbfBinding = matched ;
                    here->B3SOIDDQbfPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqjsNode != 0) && (here-> B3SOIDDqjsNode != 0))
                {
                    i = here->B3SOIDDQjsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQjsBinding = matched ;
                    here->B3SOIDDQjsPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqjdNode != 0) && (here-> B3SOIDDqjdNode != 0))
                {
                    i = here->B3SOIDDQjdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQjdBinding = matched ;
                    here->B3SOIDDQjdPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDgmNode != 0) && (here-> B3SOIDDgmNode != 0))
                {
                    i = here->B3SOIDDGmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDGmBinding = matched ;
                    here->B3SOIDDGmPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDgmbsNode != 0) && (here-> B3SOIDDgmbsNode != 0))
                {
                    i = here->B3SOIDDGmbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDGmbsBinding = matched ;
                    here->B3SOIDDGmbsPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDgdsNode != 0) && (here-> B3SOIDDgdsNode != 0))
                {
                    i = here->B3SOIDDGdsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDGdsBinding = matched ;
                    here->B3SOIDDGdsPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDgmeNode != 0) && (here-> B3SOIDDgmeNode != 0))
                {
                    i = here->B3SOIDDGmePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDGmeBinding = matched ;
                    here->B3SOIDDGmePtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvbs0teffNode != 0) && (here-> B3SOIDDvbs0teffNode != 0))
                {
                    i = here->B3SOIDDVbs0teffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVbs0teffBinding = matched ;
                    here->B3SOIDDVbs0teffPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvthNode != 0) && (here-> B3SOIDDvthNode != 0))
                {
                    i = here->B3SOIDDVthPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVthBinding = matched ;
                    here->B3SOIDDVthPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvgsteffNode != 0) && (here-> B3SOIDDvgsteffNode != 0))
                {
                    i = here->B3SOIDDVgsteffPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVgsteffBinding = matched ;
                    here->B3SOIDDVgsteffPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDxcsatNode != 0) && (here-> B3SOIDDxcsatNode != 0))
                {
                    i = here->B3SOIDDXcsatPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDXcsatBinding = matched ;
                    here->B3SOIDDXcsatPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvcscvNode != 0) && (here-> B3SOIDDvcscvNode != 0))
                {
                    i = here->B3SOIDDVcscvPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVcscvBinding = matched ;
                    here->B3SOIDDVcscvPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDvdscvNode != 0) && (here-> B3SOIDDvdscvNode != 0))
                {
                    i = here->B3SOIDDVdscvPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDVdscvBinding = matched ;
                    here->B3SOIDDVdscvPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDcbeNode != 0) && (here-> B3SOIDDcbeNode != 0))
                {
                    i = here->B3SOIDDCbePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDCbeBinding = matched ;
                    here->B3SOIDDCbePtr = matched->CSC ;
                }

                if ((here-> B3SOIDDdum1Node != 0) && (here-> B3SOIDDdum1Node != 0))
                {
                    i = here->B3SOIDDDum1Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDDum1Binding = matched ;
                    here->B3SOIDDDum1Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDdum2Node != 0) && (here-> B3SOIDDdum2Node != 0))
                {
                    i = here->B3SOIDDDum2Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDDum2Binding = matched ;
                    here->B3SOIDDDum2Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDdum3Node != 0) && (here-> B3SOIDDdum3Node != 0))
                {
                    i = here->B3SOIDDDum3Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDDum3Binding = matched ;
                    here->B3SOIDDDum3Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDdum4Node != 0) && (here-> B3SOIDDdum4Node != 0))
                {
                    i = here->B3SOIDDDum4Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDDum4Binding = matched ;
                    here->B3SOIDDDum4Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDdum5Node != 0) && (here-> B3SOIDDdum5Node != 0))
                {
                    i = here->B3SOIDDDum5Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDDum5Binding = matched ;
                    here->B3SOIDDDum5Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDqaccNode != 0) && (here-> B3SOIDDqaccNode != 0))
                {
                    i = here->B3SOIDDQaccPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQaccBinding = matched ;
                    here->B3SOIDDQaccPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqsub0Node != 0) && (here-> B3SOIDDqsub0Node != 0))
                {
                    i = here->B3SOIDDQsub0Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQsub0Binding = matched ;
                    here->B3SOIDDQsub0Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDqsubs1Node != 0) && (here-> B3SOIDDqsubs1Node != 0))
                {
                    i = here->B3SOIDDQsubs1Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQsubs1Binding = matched ;
                    here->B3SOIDDQsubs1Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDqsubs2Node != 0) && (here-> B3SOIDDqsubs2Node != 0))
                {
                    i = here->B3SOIDDQsubs2Ptr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDQsubs2Binding = matched ;
                    here->B3SOIDDQsubs2Ptr = matched->CSC ;
                }

                if ((here-> B3SOIDDqeNode != 0) && (here-> B3SOIDDqeNode != 0))
                {
                    i = here->B3SOIDDqePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDqeBinding = matched ;
                    here->B3SOIDDqePtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqdNode != 0) && (here-> B3SOIDDqdNode != 0))
                {
                    i = here->B3SOIDDqdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDqdBinding = matched ;
                    here->B3SOIDDqdPtr = matched->CSC ;
                }

                if ((here-> B3SOIDDqgNode != 0) && (here-> B3SOIDDqgNode != 0))
                {
                    i = here->B3SOIDDqgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B3SOIDDqgBinding = matched ;
                    here->B3SOIDDqgPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
B3SOIDDbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIDDmodel *model = (B3SOIDDmodel *)inModel ;
    B3SOIDDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B3SOIDD models */
    for ( ; model != NULL ; model = model->B3SOIDDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIDDinstances ; here != NULL ; here = here->B3SOIDDnextInstance)
        {
            if ((model->B3SOIDDshMod == 1) && (here->B3SOIDDrth0 != 0.0))
            {
                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDTemptempPtr = here->B3SOIDDTemptempBinding->CSC_Complex ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                    here->B3SOIDDTempdpPtr = here->B3SOIDDTempdpBinding->CSC_Complex ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                    here->B3SOIDDTempspPtr = here->B3SOIDDTempspBinding->CSC_Complex ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDgNode != 0))
                    here->B3SOIDDTempgPtr = here->B3SOIDDTempgBinding->CSC_Complex ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDbNode != 0))
                    here->B3SOIDDTempbPtr = here->B3SOIDDTempbBinding->CSC_Complex ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDeNode != 0))
                    here->B3SOIDDTempePtr = here->B3SOIDDTempeBinding->CSC_Complex ;

                if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDGtempPtr = here->B3SOIDDGtempBinding->CSC_Complex ;

                if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDDPtempPtr = here->B3SOIDDDPtempBinding->CSC_Complex ;

                if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDSPtempPtr = here->B3SOIDDSPtempBinding->CSC_Complex ;

                if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDEtempPtr = here->B3SOIDDEtempBinding->CSC_Complex ;

                if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDBtempPtr = here->B3SOIDDBtempBinding->CSC_Complex ;

                if (here->B3SOIDDbodyMod == 1)
                {
                    if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDtempNode != 0))
                        here->B3SOIDDPtempPtr = here->B3SOIDDPtempBinding->CSC_Complex ;

                }
            }
            if (here->B3SOIDDbodyMod == 2)
            {
            }
            else if (here->B3SOIDDbodyMod == 1)
            {
                if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDpNode != 0))
                    here->B3SOIDDBpPtr = here->B3SOIDDBpBinding->CSC_Complex ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDbNode != 0))
                    here->B3SOIDDPbPtr = here->B3SOIDDPbBinding->CSC_Complex ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDpNode != 0))
                    here->B3SOIDDPpPtr = here->B3SOIDDPpBinding->CSC_Complex ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDgNode != 0))
                    here->B3SOIDDPgPtr = here->B3SOIDDPgBinding->CSC_Complex ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                    here->B3SOIDDPdpPtr = here->B3SOIDDPdpBinding->CSC_Complex ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                    here->B3SOIDDPspPtr = here->B3SOIDDPspBinding->CSC_Complex ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDeNode != 0))
                    here->B3SOIDDPePtr = here->B3SOIDDPeBinding->CSC_Complex ;

            }
            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDEgPtr = here->B3SOIDDEgBinding->CSC_Complex ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDEdpPtr = here->B3SOIDDEdpBinding->CSC_Complex ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDEspPtr = here->B3SOIDDEspBinding->CSC_Complex ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDGePtr = here->B3SOIDDGeBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDDPePtr = here->B3SOIDDDPeBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDSPePtr = here->B3SOIDDSPeBinding->CSC_Complex ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDEbPtr = here->B3SOIDDEbBinding->CSC_Complex ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDGbPtr = here->B3SOIDDGbBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDDPbPtr = here->B3SOIDDDPbBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDSPbPtr = here->B3SOIDDSPbBinding->CSC_Complex ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDBePtr = here->B3SOIDDBeBinding->CSC_Complex ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDBgPtr = here->B3SOIDDBgBinding->CSC_Complex ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDBdpPtr = here->B3SOIDDBdpBinding->CSC_Complex ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDBspPtr = here->B3SOIDDBspBinding->CSC_Complex ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDBbPtr = here->B3SOIDDBbBinding->CSC_Complex ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDEePtr = here->B3SOIDDEeBinding->CSC_Complex ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDGgPtr = here->B3SOIDDGgBinding->CSC_Complex ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDGdpPtr = here->B3SOIDDGdpBinding->CSC_Complex ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDGspPtr = here->B3SOIDDGspBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDDPgPtr = here->B3SOIDDDPgBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDDPdpPtr = here->B3SOIDDDPdpBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDDPspPtr = here->B3SOIDDDPspBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDdNode != 0))
                here->B3SOIDDDPdPtr = here->B3SOIDDDPdBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDSPgPtr = here->B3SOIDDSPgBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDSPdpPtr = here->B3SOIDDSPdpBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDSPspPtr = here->B3SOIDDSPspBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDsNode != 0))
                here->B3SOIDDSPsPtr = here->B3SOIDDSPsBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNode != 0) && (here-> B3SOIDDdNode != 0))
                here->B3SOIDDDdPtr = here->B3SOIDDDdBinding->CSC_Complex ;

            if ((here-> B3SOIDDdNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDDdpPtr = here->B3SOIDDDdpBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNode != 0) && (here-> B3SOIDDsNode != 0))
                here->B3SOIDDSsPtr = here->B3SOIDDSsBinding->CSC_Complex ;

            if ((here-> B3SOIDDsNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDSspPtr = here->B3SOIDDSspBinding->CSC_Complex ;

            if ((here->B3SOIDDdebugMod > 1) || (here->B3SOIDDdebugMod == -1))
            {
                if ((here-> B3SOIDDvbsNode != 0) && (here-> B3SOIDDvbsNode != 0))
                    here->B3SOIDDVbsPtr = here->B3SOIDDVbsBinding->CSC_Complex ;

                if ((here-> B3SOIDDidsNode != 0) && (here-> B3SOIDDidsNode != 0))
                    here->B3SOIDDIdsPtr = here->B3SOIDDIdsBinding->CSC_Complex ;

                if ((here-> B3SOIDDicNode != 0) && (here-> B3SOIDDicNode != 0))
                    here->B3SOIDDIcPtr = here->B3SOIDDIcBinding->CSC_Complex ;

                if ((here-> B3SOIDDibsNode != 0) && (here-> B3SOIDDibsNode != 0))
                    here->B3SOIDDIbsPtr = here->B3SOIDDIbsBinding->CSC_Complex ;

                if ((here-> B3SOIDDibdNode != 0) && (here-> B3SOIDDibdNode != 0))
                    here->B3SOIDDIbdPtr = here->B3SOIDDIbdBinding->CSC_Complex ;

                if ((here-> B3SOIDDiiiNode != 0) && (here-> B3SOIDDiiiNode != 0))
                    here->B3SOIDDIiiPtr = here->B3SOIDDIiiBinding->CSC_Complex ;

                if ((here-> B3SOIDDigidlNode != 0) && (here-> B3SOIDDigidlNode != 0))
                    here->B3SOIDDIgidlPtr = here->B3SOIDDIgidlBinding->CSC_Complex ;

                if ((here-> B3SOIDDitunNode != 0) && (here-> B3SOIDDitunNode != 0))
                    here->B3SOIDDItunPtr = here->B3SOIDDItunBinding->CSC_Complex ;

                if ((here-> B3SOIDDibpNode != 0) && (here-> B3SOIDDibpNode != 0))
                    here->B3SOIDDIbpPtr = here->B3SOIDDIbpBinding->CSC_Complex ;

                if ((here-> B3SOIDDabeffNode != 0) && (here-> B3SOIDDabeffNode != 0))
                    here->B3SOIDDAbeffPtr = here->B3SOIDDAbeffBinding->CSC_Complex ;

                if ((here-> B3SOIDDvbs0effNode != 0) && (here-> B3SOIDDvbs0effNode != 0))
                    here->B3SOIDDVbs0effPtr = here->B3SOIDDVbs0effBinding->CSC_Complex ;

                if ((here-> B3SOIDDvbseffNode != 0) && (here-> B3SOIDDvbseffNode != 0))
                    here->B3SOIDDVbseffPtr = here->B3SOIDDVbseffBinding->CSC_Complex ;

                if ((here-> B3SOIDDxcNode != 0) && (here-> B3SOIDDxcNode != 0))
                    here->B3SOIDDXcPtr = here->B3SOIDDXcBinding->CSC_Complex ;

                if ((here-> B3SOIDDcbbNode != 0) && (here-> B3SOIDDcbbNode != 0))
                    here->B3SOIDDCbbPtr = here->B3SOIDDCbbBinding->CSC_Complex ;

                if ((here-> B3SOIDDcbdNode != 0) && (here-> B3SOIDDcbdNode != 0))
                    here->B3SOIDDCbdPtr = here->B3SOIDDCbdBinding->CSC_Complex ;

                if ((here-> B3SOIDDcbgNode != 0) && (here-> B3SOIDDcbgNode != 0))
                    here->B3SOIDDCbgPtr = here->B3SOIDDCbgBinding->CSC_Complex ;

                if ((here-> B3SOIDDqbNode != 0) && (here-> B3SOIDDqbNode != 0))
                    here->B3SOIDDqbPtr = here->B3SOIDDqbBinding->CSC_Complex ;

                if ((here-> B3SOIDDqbfNode != 0) && (here-> B3SOIDDqbfNode != 0))
                    here->B3SOIDDQbfPtr = here->B3SOIDDQbfBinding->CSC_Complex ;

                if ((here-> B3SOIDDqjsNode != 0) && (here-> B3SOIDDqjsNode != 0))
                    here->B3SOIDDQjsPtr = here->B3SOIDDQjsBinding->CSC_Complex ;

                if ((here-> B3SOIDDqjdNode != 0) && (here-> B3SOIDDqjdNode != 0))
                    here->B3SOIDDQjdPtr = here->B3SOIDDQjdBinding->CSC_Complex ;

                if ((here-> B3SOIDDgmNode != 0) && (here-> B3SOIDDgmNode != 0))
                    here->B3SOIDDGmPtr = here->B3SOIDDGmBinding->CSC_Complex ;

                if ((here-> B3SOIDDgmbsNode != 0) && (here-> B3SOIDDgmbsNode != 0))
                    here->B3SOIDDGmbsPtr = here->B3SOIDDGmbsBinding->CSC_Complex ;

                if ((here-> B3SOIDDgdsNode != 0) && (here-> B3SOIDDgdsNode != 0))
                    here->B3SOIDDGdsPtr = here->B3SOIDDGdsBinding->CSC_Complex ;

                if ((here-> B3SOIDDgmeNode != 0) && (here-> B3SOIDDgmeNode != 0))
                    here->B3SOIDDGmePtr = here->B3SOIDDGmeBinding->CSC_Complex ;

                if ((here-> B3SOIDDvbs0teffNode != 0) && (here-> B3SOIDDvbs0teffNode != 0))
                    here->B3SOIDDVbs0teffPtr = here->B3SOIDDVbs0teffBinding->CSC_Complex ;

                if ((here-> B3SOIDDvthNode != 0) && (here-> B3SOIDDvthNode != 0))
                    here->B3SOIDDVthPtr = here->B3SOIDDVthBinding->CSC_Complex ;

                if ((here-> B3SOIDDvgsteffNode != 0) && (here-> B3SOIDDvgsteffNode != 0))
                    here->B3SOIDDVgsteffPtr = here->B3SOIDDVgsteffBinding->CSC_Complex ;

                if ((here-> B3SOIDDxcsatNode != 0) && (here-> B3SOIDDxcsatNode != 0))
                    here->B3SOIDDXcsatPtr = here->B3SOIDDXcsatBinding->CSC_Complex ;

                if ((here-> B3SOIDDvcscvNode != 0) && (here-> B3SOIDDvcscvNode != 0))
                    here->B3SOIDDVcscvPtr = here->B3SOIDDVcscvBinding->CSC_Complex ;

                if ((here-> B3SOIDDvdscvNode != 0) && (here-> B3SOIDDvdscvNode != 0))
                    here->B3SOIDDVdscvPtr = here->B3SOIDDVdscvBinding->CSC_Complex ;

                if ((here-> B3SOIDDcbeNode != 0) && (here-> B3SOIDDcbeNode != 0))
                    here->B3SOIDDCbePtr = here->B3SOIDDCbeBinding->CSC_Complex ;

                if ((here-> B3SOIDDdum1Node != 0) && (here-> B3SOIDDdum1Node != 0))
                    here->B3SOIDDDum1Ptr = here->B3SOIDDDum1Binding->CSC_Complex ;

                if ((here-> B3SOIDDdum2Node != 0) && (here-> B3SOIDDdum2Node != 0))
                    here->B3SOIDDDum2Ptr = here->B3SOIDDDum2Binding->CSC_Complex ;

                if ((here-> B3SOIDDdum3Node != 0) && (here-> B3SOIDDdum3Node != 0))
                    here->B3SOIDDDum3Ptr = here->B3SOIDDDum3Binding->CSC_Complex ;

                if ((here-> B3SOIDDdum4Node != 0) && (here-> B3SOIDDdum4Node != 0))
                    here->B3SOIDDDum4Ptr = here->B3SOIDDDum4Binding->CSC_Complex ;

                if ((here-> B3SOIDDdum5Node != 0) && (here-> B3SOIDDdum5Node != 0))
                    here->B3SOIDDDum5Ptr = here->B3SOIDDDum5Binding->CSC_Complex ;

                if ((here-> B3SOIDDqaccNode != 0) && (here-> B3SOIDDqaccNode != 0))
                    here->B3SOIDDQaccPtr = here->B3SOIDDQaccBinding->CSC_Complex ;

                if ((here-> B3SOIDDqsub0Node != 0) && (here-> B3SOIDDqsub0Node != 0))
                    here->B3SOIDDQsub0Ptr = here->B3SOIDDQsub0Binding->CSC_Complex ;

                if ((here-> B3SOIDDqsubs1Node != 0) && (here-> B3SOIDDqsubs1Node != 0))
                    here->B3SOIDDQsubs1Ptr = here->B3SOIDDQsubs1Binding->CSC_Complex ;

                if ((here-> B3SOIDDqsubs2Node != 0) && (here-> B3SOIDDqsubs2Node != 0))
                    here->B3SOIDDQsubs2Ptr = here->B3SOIDDQsubs2Binding->CSC_Complex ;

                if ((here-> B3SOIDDqeNode != 0) && (here-> B3SOIDDqeNode != 0))
                    here->B3SOIDDqePtr = here->B3SOIDDqeBinding->CSC_Complex ;

                if ((here-> B3SOIDDqdNode != 0) && (here-> B3SOIDDqdNode != 0))
                    here->B3SOIDDqdPtr = here->B3SOIDDqdBinding->CSC_Complex ;

                if ((here-> B3SOIDDqgNode != 0) && (here-> B3SOIDDqgNode != 0))
                    here->B3SOIDDqgPtr = here->B3SOIDDqgBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
B3SOIDDbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B3SOIDDmodel *model = (B3SOIDDmodel *)inModel ;
    B3SOIDDinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B3SOIDD models */
    for ( ; model != NULL ; model = model->B3SOIDDnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B3SOIDDinstances ; here != NULL ; here = here->B3SOIDDnextInstance)
        {
            if ((model->B3SOIDDshMod == 1) && (here->B3SOIDDrth0 != 0.0))
            {
                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDTemptempPtr = here->B3SOIDDTemptempBinding->CSC ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                    here->B3SOIDDTempdpPtr = here->B3SOIDDTempdpBinding->CSC ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                    here->B3SOIDDTempspPtr = here->B3SOIDDTempspBinding->CSC ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDgNode != 0))
                    here->B3SOIDDTempgPtr = here->B3SOIDDTempgBinding->CSC ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDbNode != 0))
                    here->B3SOIDDTempbPtr = here->B3SOIDDTempbBinding->CSC ;

                if ((here-> B3SOIDDtempNode != 0) && (here-> B3SOIDDeNode != 0))
                    here->B3SOIDDTempePtr = here->B3SOIDDTempeBinding->CSC ;

                if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDGtempPtr = here->B3SOIDDGtempBinding->CSC ;

                if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDDPtempPtr = here->B3SOIDDDPtempBinding->CSC ;

                if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDSPtempPtr = here->B3SOIDDSPtempBinding->CSC ;

                if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDEtempPtr = here->B3SOIDDEtempBinding->CSC ;

                if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDtempNode != 0))
                    here->B3SOIDDBtempPtr = here->B3SOIDDBtempBinding->CSC ;

                if (here->B3SOIDDbodyMod == 1)
                {
                    if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDtempNode != 0))
                        here->B3SOIDDPtempPtr = here->B3SOIDDPtempBinding->CSC ;

                }
            }
            if (here->B3SOIDDbodyMod == 2)
            {
            }
            else if (here->B3SOIDDbodyMod == 1)
            {
                if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDpNode != 0))
                    here->B3SOIDDBpPtr = here->B3SOIDDBpBinding->CSC ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDbNode != 0))
                    here->B3SOIDDPbPtr = here->B3SOIDDPbBinding->CSC ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDpNode != 0))
                    here->B3SOIDDPpPtr = here->B3SOIDDPpBinding->CSC ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDgNode != 0))
                    here->B3SOIDDPgPtr = here->B3SOIDDPgBinding->CSC ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                    here->B3SOIDDPdpPtr = here->B3SOIDDPdpBinding->CSC ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                    here->B3SOIDDPspPtr = here->B3SOIDDPspBinding->CSC ;

                if ((here-> B3SOIDDpNode != 0) && (here-> B3SOIDDeNode != 0))
                    here->B3SOIDDPePtr = here->B3SOIDDPeBinding->CSC ;

            }
            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDEgPtr = here->B3SOIDDEgBinding->CSC ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDEdpPtr = here->B3SOIDDEdpBinding->CSC ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDEspPtr = here->B3SOIDDEspBinding->CSC ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDGePtr = here->B3SOIDDGeBinding->CSC ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDDPePtr = here->B3SOIDDDPeBinding->CSC ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDSPePtr = here->B3SOIDDSPeBinding->CSC ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDEbPtr = here->B3SOIDDEbBinding->CSC ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDGbPtr = here->B3SOIDDGbBinding->CSC ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDDPbPtr = here->B3SOIDDDPbBinding->CSC ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDSPbPtr = here->B3SOIDDSPbBinding->CSC ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDBePtr = here->B3SOIDDBeBinding->CSC ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDBgPtr = here->B3SOIDDBgBinding->CSC ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDBdpPtr = here->B3SOIDDBdpBinding->CSC ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDBspPtr = here->B3SOIDDBspBinding->CSC ;

            if ((here-> B3SOIDDbNode != 0) && (here-> B3SOIDDbNode != 0))
                here->B3SOIDDBbPtr = here->B3SOIDDBbBinding->CSC ;

            if ((here-> B3SOIDDeNode != 0) && (here-> B3SOIDDeNode != 0))
                here->B3SOIDDEePtr = here->B3SOIDDEeBinding->CSC ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDGgPtr = here->B3SOIDDGgBinding->CSC ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDGdpPtr = here->B3SOIDDGdpBinding->CSC ;

            if ((here-> B3SOIDDgNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDGspPtr = here->B3SOIDDGspBinding->CSC ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDDPgPtr = here->B3SOIDDDPgBinding->CSC ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDDPdpPtr = here->B3SOIDDDPdpBinding->CSC ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDDPspPtr = here->B3SOIDDDPspBinding->CSC ;

            if ((here-> B3SOIDDdNodePrime != 0) && (here-> B3SOIDDdNode != 0))
                here->B3SOIDDDPdPtr = here->B3SOIDDDPdBinding->CSC ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDgNode != 0))
                here->B3SOIDDSPgPtr = here->B3SOIDDSPgBinding->CSC ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDSPdpPtr = here->B3SOIDDSPdpBinding->CSC ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDSPspPtr = here->B3SOIDDSPspBinding->CSC ;

            if ((here-> B3SOIDDsNodePrime != 0) && (here-> B3SOIDDsNode != 0))
                here->B3SOIDDSPsPtr = here->B3SOIDDSPsBinding->CSC ;

            if ((here-> B3SOIDDdNode != 0) && (here-> B3SOIDDdNode != 0))
                here->B3SOIDDDdPtr = here->B3SOIDDDdBinding->CSC ;

            if ((here-> B3SOIDDdNode != 0) && (here-> B3SOIDDdNodePrime != 0))
                here->B3SOIDDDdpPtr = here->B3SOIDDDdpBinding->CSC ;

            if ((here-> B3SOIDDsNode != 0) && (here-> B3SOIDDsNode != 0))
                here->B3SOIDDSsPtr = here->B3SOIDDSsBinding->CSC ;

            if ((here-> B3SOIDDsNode != 0) && (here-> B3SOIDDsNodePrime != 0))
                here->B3SOIDDSspPtr = here->B3SOIDDSspBinding->CSC ;

            if ((here->B3SOIDDdebugMod > 1) || (here->B3SOIDDdebugMod == -1))
            {
                if ((here-> B3SOIDDvbsNode != 0) && (here-> B3SOIDDvbsNode != 0))
                    here->B3SOIDDVbsPtr = here->B3SOIDDVbsBinding->CSC ;

                if ((here-> B3SOIDDidsNode != 0) && (here-> B3SOIDDidsNode != 0))
                    here->B3SOIDDIdsPtr = here->B3SOIDDIdsBinding->CSC ;

                if ((here-> B3SOIDDicNode != 0) && (here-> B3SOIDDicNode != 0))
                    here->B3SOIDDIcPtr = here->B3SOIDDIcBinding->CSC ;

                if ((here-> B3SOIDDibsNode != 0) && (here-> B3SOIDDibsNode != 0))
                    here->B3SOIDDIbsPtr = here->B3SOIDDIbsBinding->CSC ;

                if ((here-> B3SOIDDibdNode != 0) && (here-> B3SOIDDibdNode != 0))
                    here->B3SOIDDIbdPtr = here->B3SOIDDIbdBinding->CSC ;

                if ((here-> B3SOIDDiiiNode != 0) && (here-> B3SOIDDiiiNode != 0))
                    here->B3SOIDDIiiPtr = here->B3SOIDDIiiBinding->CSC ;

                if ((here-> B3SOIDDigidlNode != 0) && (here-> B3SOIDDigidlNode != 0))
                    here->B3SOIDDIgidlPtr = here->B3SOIDDIgidlBinding->CSC ;

                if ((here-> B3SOIDDitunNode != 0) && (here-> B3SOIDDitunNode != 0))
                    here->B3SOIDDItunPtr = here->B3SOIDDItunBinding->CSC ;

                if ((here-> B3SOIDDibpNode != 0) && (here-> B3SOIDDibpNode != 0))
                    here->B3SOIDDIbpPtr = here->B3SOIDDIbpBinding->CSC ;

                if ((here-> B3SOIDDabeffNode != 0) && (here-> B3SOIDDabeffNode != 0))
                    here->B3SOIDDAbeffPtr = here->B3SOIDDAbeffBinding->CSC ;

                if ((here-> B3SOIDDvbs0effNode != 0) && (here-> B3SOIDDvbs0effNode != 0))
                    here->B3SOIDDVbs0effPtr = here->B3SOIDDVbs0effBinding->CSC ;

                if ((here-> B3SOIDDvbseffNode != 0) && (here-> B3SOIDDvbseffNode != 0))
                    here->B3SOIDDVbseffPtr = here->B3SOIDDVbseffBinding->CSC ;

                if ((here-> B3SOIDDxcNode != 0) && (here-> B3SOIDDxcNode != 0))
                    here->B3SOIDDXcPtr = here->B3SOIDDXcBinding->CSC ;

                if ((here-> B3SOIDDcbbNode != 0) && (here-> B3SOIDDcbbNode != 0))
                    here->B3SOIDDCbbPtr = here->B3SOIDDCbbBinding->CSC ;

                if ((here-> B3SOIDDcbdNode != 0) && (here-> B3SOIDDcbdNode != 0))
                    here->B3SOIDDCbdPtr = here->B3SOIDDCbdBinding->CSC ;

                if ((here-> B3SOIDDcbgNode != 0) && (here-> B3SOIDDcbgNode != 0))
                    here->B3SOIDDCbgPtr = here->B3SOIDDCbgBinding->CSC ;

                if ((here-> B3SOIDDqbNode != 0) && (here-> B3SOIDDqbNode != 0))
                    here->B3SOIDDqbPtr = here->B3SOIDDqbBinding->CSC ;

                if ((here-> B3SOIDDqbfNode != 0) && (here-> B3SOIDDqbfNode != 0))
                    here->B3SOIDDQbfPtr = here->B3SOIDDQbfBinding->CSC ;

                if ((here-> B3SOIDDqjsNode != 0) && (here-> B3SOIDDqjsNode != 0))
                    here->B3SOIDDQjsPtr = here->B3SOIDDQjsBinding->CSC ;

                if ((here-> B3SOIDDqjdNode != 0) && (here-> B3SOIDDqjdNode != 0))
                    here->B3SOIDDQjdPtr = here->B3SOIDDQjdBinding->CSC ;

                if ((here-> B3SOIDDgmNode != 0) && (here-> B3SOIDDgmNode != 0))
                    here->B3SOIDDGmPtr = here->B3SOIDDGmBinding->CSC ;

                if ((here-> B3SOIDDgmbsNode != 0) && (here-> B3SOIDDgmbsNode != 0))
                    here->B3SOIDDGmbsPtr = here->B3SOIDDGmbsBinding->CSC ;

                if ((here-> B3SOIDDgdsNode != 0) && (here-> B3SOIDDgdsNode != 0))
                    here->B3SOIDDGdsPtr = here->B3SOIDDGdsBinding->CSC ;

                if ((here-> B3SOIDDgmeNode != 0) && (here-> B3SOIDDgmeNode != 0))
                    here->B3SOIDDGmePtr = here->B3SOIDDGmeBinding->CSC ;

                if ((here-> B3SOIDDvbs0teffNode != 0) && (here-> B3SOIDDvbs0teffNode != 0))
                    here->B3SOIDDVbs0teffPtr = here->B3SOIDDVbs0teffBinding->CSC ;

                if ((here-> B3SOIDDvthNode != 0) && (here-> B3SOIDDvthNode != 0))
                    here->B3SOIDDVthPtr = here->B3SOIDDVthBinding->CSC ;

                if ((here-> B3SOIDDvgsteffNode != 0) && (here-> B3SOIDDvgsteffNode != 0))
                    here->B3SOIDDVgsteffPtr = here->B3SOIDDVgsteffBinding->CSC ;

                if ((here-> B3SOIDDxcsatNode != 0) && (here-> B3SOIDDxcsatNode != 0))
                    here->B3SOIDDXcsatPtr = here->B3SOIDDXcsatBinding->CSC ;

                if ((here-> B3SOIDDvcscvNode != 0) && (here-> B3SOIDDvcscvNode != 0))
                    here->B3SOIDDVcscvPtr = here->B3SOIDDVcscvBinding->CSC ;

                if ((here-> B3SOIDDvdscvNode != 0) && (here-> B3SOIDDvdscvNode != 0))
                    here->B3SOIDDVdscvPtr = here->B3SOIDDVdscvBinding->CSC ;

                if ((here-> B3SOIDDcbeNode != 0) && (here-> B3SOIDDcbeNode != 0))
                    here->B3SOIDDCbePtr = here->B3SOIDDCbeBinding->CSC ;

                if ((here-> B3SOIDDdum1Node != 0) && (here-> B3SOIDDdum1Node != 0))
                    here->B3SOIDDDum1Ptr = here->B3SOIDDDum1Binding->CSC ;

                if ((here-> B3SOIDDdum2Node != 0) && (here-> B3SOIDDdum2Node != 0))
                    here->B3SOIDDDum2Ptr = here->B3SOIDDDum2Binding->CSC ;

                if ((here-> B3SOIDDdum3Node != 0) && (here-> B3SOIDDdum3Node != 0))
                    here->B3SOIDDDum3Ptr = here->B3SOIDDDum3Binding->CSC ;

                if ((here-> B3SOIDDdum4Node != 0) && (here-> B3SOIDDdum4Node != 0))
                    here->B3SOIDDDum4Ptr = here->B3SOIDDDum4Binding->CSC ;

                if ((here-> B3SOIDDdum5Node != 0) && (here-> B3SOIDDdum5Node != 0))
                    here->B3SOIDDDum5Ptr = here->B3SOIDDDum5Binding->CSC ;

                if ((here-> B3SOIDDqaccNode != 0) && (here-> B3SOIDDqaccNode != 0))
                    here->B3SOIDDQaccPtr = here->B3SOIDDQaccBinding->CSC ;

                if ((here-> B3SOIDDqsub0Node != 0) && (here-> B3SOIDDqsub0Node != 0))
                    here->B3SOIDDQsub0Ptr = here->B3SOIDDQsub0Binding->CSC ;

                if ((here-> B3SOIDDqsubs1Node != 0) && (here-> B3SOIDDqsubs1Node != 0))
                    here->B3SOIDDQsubs1Ptr = here->B3SOIDDQsubs1Binding->CSC ;

                if ((here-> B3SOIDDqsubs2Node != 0) && (here-> B3SOIDDqsubs2Node != 0))
                    here->B3SOIDDQsubs2Ptr = here->B3SOIDDQsubs2Binding->CSC ;

                if ((here-> B3SOIDDqeNode != 0) && (here-> B3SOIDDqeNode != 0))
                    here->B3SOIDDqePtr = here->B3SOIDDqeBinding->CSC ;

                if ((here-> B3SOIDDqdNode != 0) && (here-> B3SOIDDqdNode != 0))
                    here->B3SOIDDqdPtr = here->B3SOIDDqdBinding->CSC ;

                if ((here-> B3SOIDDqgNode != 0) && (here-> B3SOIDDqgNode != 0))
                    here->B3SOIDDqgPtr = here->B3SOIDDqgBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
