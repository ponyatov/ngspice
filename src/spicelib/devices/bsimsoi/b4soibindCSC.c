/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b4soidef.h"
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
B4SOIbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    B4SOImodel *model = (B4SOImodel *)inModel ;
    B4SOIinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the B4SOI models */
    for ( ; model != NULL ; model = model->B4SOInextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B4SOIinstances ; here != NULL ; here = here->B4SOInextInstance)
        {
            if ((model->B4SOIshMod == 1) && (here->B4SOIrth0 != 0.0))
            {
                if ((here-> B4SOItempNode != 0) && (here-> B4SOItempNode != 0))
                {
                    i = here->B4SOITemptempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOITemptempBinding = matched ;
                    here->B4SOITemptempPtr = matched->CSC ;
                }

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIdNodePrime != 0))
                {
                    i = here->B4SOITempdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOITempdpBinding = matched ;
                    here->B4SOITempdpPtr = matched->CSC ;
                }

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIsNodePrime != 0))
                {
                    i = here->B4SOITempspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOITempspBinding = matched ;
                    here->B4SOITempspPtr = matched->CSC ;
                }

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOITempgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOITempgBinding = matched ;
                    here->B4SOITempgPtr = matched->CSC ;
                }

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOITempbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOITempbBinding = matched ;
                    here->B4SOITempbPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNode != 0) && (here-> B4SOItempNode != 0))
                {
                    i = here->B4SOIGtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGtempBinding = matched ;
                    here->B4SOIGtempPtr = matched->CSC ;
                }

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOItempNode != 0))
                {
                    i = here->B4SOIDPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDPtempBinding = matched ;
                    here->B4SOIDPtempPtr = matched->CSC ;
                }

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOItempNode != 0))
                {
                    i = here->B4SOISPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISPtempBinding = matched ;
                    here->B4SOISPtempPtr = matched->CSC ;
                }

                if ((here-> B4SOIeNode != 0) && (here-> B4SOItempNode != 0))
                {
                    i = here->B4SOIEtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIEtempBinding = matched ;
                    here->B4SOIEtempPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOItempNode != 0))
                {
                    i = here->B4SOIBtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBtempBinding = matched ;
                    here->B4SOIBtempPtr = matched->CSC ;
                }

                if (here->B4SOIbodyMod == 1)
                {
                    if ((here-> B4SOIpNode != 0) && (here-> B4SOItempNode != 0))
                    {
                        i = here->B4SOIPtempPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B4SOIPtempBinding = matched ;
                        here->B4SOIPtempPtr = matched->CSC ;
                    }

                }
                if (here->B4SOIsoiMod != 0)
                {
                    if ((here-> B4SOItempNode != 0) && (here-> B4SOIeNode != 0))
                    {
                        i = here->B4SOITempePtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B4SOITempeBinding = matched ;
                        here->B4SOITempePtr = matched->CSC ;
                    }

                }
            }
            if (here->B4SOIbodyMod == 2)
            {
            }
            else if (here->B4SOIbodyMod == 1)
            {
                if ((here-> B4SOIbNode != 0) && (here-> B4SOIpNode != 0))
                {
                    i = here->B4SOIBpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBpBinding = matched ;
                    here->B4SOIBpPtr = matched->CSC ;
                }

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOIPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIPbBinding = matched ;
                    here->B4SOIPbPtr = matched->CSC ;
                }

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIpNode != 0))
                {
                    i = here->B4SOIPpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIPpBinding = matched ;
                    here->B4SOIPpPtr = matched->CSC ;
                }

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOIPgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIPgBinding = matched ;
                    here->B4SOIPgPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIpNode != 0))
                {
                    i = here->B4SOIGpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGpBinding = matched ;
                    here->B4SOIGpPtr = matched->CSC ;
                }

            }
            if (here->B4SOIrgateMod != 0)
            {
                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNodeExt != 0))
                {
                    i = here->B4SOIGEgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGEgeBinding = matched ;
                    here->B4SOIGEgePtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOIGEgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGEgBinding = matched ;
                    here->B4SOIGEgPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNodeExt != 0))
                {
                    i = here->B4SOIGgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGgeBinding = matched ;
                    here->B4SOIGgePtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIdNodePrime != 0))
                {
                    i = here->B4SOIGEdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGEdpBinding = matched ;
                    here->B4SOIGEdpPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIsNodePrime != 0))
                {
                    i = here->B4SOIGEspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGEspBinding = matched ;
                    here->B4SOIGEspPtr = matched->CSC ;
                }

                if (here->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIbNode != 0))
                    {
                        i = here->B4SOIGEbPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B4SOIGEbBinding = matched ;
                        here->B4SOIGEbPtr = matched->CSC ;
                    }

                }
                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIdNodePrime != 0))
                {
                    i = here->B4SOIGMdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGMdpBinding = matched ;
                    here->B4SOIGMdpPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOIGMgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGMgBinding = matched ;
                    here->B4SOIGMgPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNodeMid != 0))
                {
                    i = here->B4SOIGMgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGMgmBinding = matched ;
                    here->B4SOIGMgmPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNodeExt != 0))
                {
                    i = here->B4SOIGMgePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGMgeBinding = matched ;
                    here->B4SOIGMgePtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIsNodePrime != 0))
                {
                    i = here->B4SOIGMspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGMspBinding = matched ;
                    here->B4SOIGMspPtr = matched->CSC ;
                }

                if (here->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIbNode != 0))
                    {
                        i = here->B4SOIGMbPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B4SOIGMbBinding = matched ;
                        here->B4SOIGMbPtr = matched->CSC ;
                    }

                }
                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIeNode != 0))
                {
                    i = here->B4SOIGMePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGMeBinding = matched ;
                    here->B4SOIGMePtr = matched->CSC ;
                }

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIgNodeMid != 0))
                {
                    i = here->B4SOIDPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDPgmBinding = matched ;
                    here->B4SOIDPgmPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNodeMid != 0))
                {
                    i = here->B4SOIGgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGgmBinding = matched ;
                    here->B4SOIGgmPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNodeMid != 0))
                {
                    i = here->B4SOIGEgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGEgmBinding = matched ;
                    here->B4SOIGEgmPtr = matched->CSC ;
                }

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIgNodeMid != 0))
                {
                    i = here->B4SOISPgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISPgmBinding = matched ;
                    here->B4SOISPgmPtr = matched->CSC ;
                }

                if ((here-> B4SOIeNode != 0) && (here-> B4SOIgNodeMid != 0))
                {
                    i = here->B4SOIEgmPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIEgmBinding = matched ;
                    here->B4SOIEgmPtr = matched->CSC ;
                }

            }
            if (here->B4SOIsoiMod != 2) /* v3.2 */
            {
                if ((here-> B4SOIeNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOIEbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIEbBinding = matched ;
                    here->B4SOIEbPtr = matched->CSC ;
                }

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOIGbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGbBinding = matched ;
                    here->B4SOIGbPtr = matched->CSC ;
                }

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOIDPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDPbBinding = matched ;
                    here->B4SOIDPbPtr = matched->CSC ;
                }

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOISPbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISPbBinding = matched ;
                    here->B4SOISPbPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIeNode != 0))
                {
                    i = here->B4SOIBePtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBeBinding = matched ;
                    here->B4SOIBePtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOIBgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBgBinding = matched ;
                    here->B4SOIBgPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIdNodePrime != 0))
                {
                    i = here->B4SOIBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBdpBinding = matched ;
                    here->B4SOIBdpPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIsNodePrime != 0))
                {
                    i = here->B4SOIBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBspBinding = matched ;
                    here->B4SOIBspPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOIBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBbBinding = matched ;
                    here->B4SOIBbPtr = matched->CSC ;
                }

            }
            if ((here-> B4SOIeNode != 0) && (here-> B4SOIgNode != 0))
            {
                i = here->B4SOIEgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIEgBinding = matched ;
                here->B4SOIEgPtr = matched->CSC ;
            }

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIdNodePrime != 0))
            {
                i = here->B4SOIEdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIEdpBinding = matched ;
                here->B4SOIEdpPtr = matched->CSC ;
            }

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIsNodePrime != 0))
            {
                i = here->B4SOIEspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIEspBinding = matched ;
                here->B4SOIEspPtr = matched->CSC ;
            }

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIeNode != 0))
            {
                i = here->B4SOIGePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIGeBinding = matched ;
                here->B4SOIGePtr = matched->CSC ;
            }

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIeNode != 0))
            {
                i = here->B4SOIDPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDPeBinding = matched ;
                here->B4SOIDPePtr = matched->CSC ;
            }

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIeNode != 0))
            {
                i = here->B4SOISPePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISPeBinding = matched ;
                here->B4SOISPePtr = matched->CSC ;
            }

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIeNode != 0))
            {
                i = here->B4SOIEePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIEeBinding = matched ;
                here->B4SOIEePtr = matched->CSC ;
            }

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNode != 0))
            {
                i = here->B4SOIGgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIGgBinding = matched ;
                here->B4SOIGgPtr = matched->CSC ;
            }

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIdNodePrime != 0))
            {
                i = here->B4SOIGdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIGdpBinding = matched ;
                here->B4SOIGdpPtr = matched->CSC ;
            }

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIsNodePrime != 0))
            {
                i = here->B4SOIGspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIGspBinding = matched ;
                here->B4SOIGspPtr = matched->CSC ;
            }

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIgNode != 0))
            {
                i = here->B4SOIDPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDPgBinding = matched ;
                here->B4SOIDPgPtr = matched->CSC ;
            }

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdNodePrime != 0))
            {
                i = here->B4SOIDPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDPdpBinding = matched ;
                here->B4SOIDPdpPtr = matched->CSC ;
            }

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIsNodePrime != 0))
            {
                i = here->B4SOIDPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDPspBinding = matched ;
                here->B4SOIDPspPtr = matched->CSC ;
            }

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdNode != 0))
            {
                i = here->B4SOIDPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDPdBinding = matched ;
                here->B4SOIDPdPtr = matched->CSC ;
            }

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIgNode != 0))
            {
                i = here->B4SOISPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISPgBinding = matched ;
                here->B4SOISPgPtr = matched->CSC ;
            }

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIdNodePrime != 0))
            {
                i = here->B4SOISPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISPdpBinding = matched ;
                here->B4SOISPdpPtr = matched->CSC ;
            }

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsNodePrime != 0))
            {
                i = here->B4SOISPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISPspBinding = matched ;
                here->B4SOISPspPtr = matched->CSC ;
            }

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsNode != 0))
            {
                i = here->B4SOISPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISPsBinding = matched ;
                here->B4SOISPsPtr = matched->CSC ;
            }

            if ((here-> B4SOIdNode != 0) && (here-> B4SOIdNode != 0))
            {
                i = here->B4SOIDdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDdBinding = matched ;
                here->B4SOIDdPtr = matched->CSC ;
            }

            if ((here-> B4SOIdNode != 0) && (here-> B4SOIdNodePrime != 0))
            {
                i = here->B4SOIDdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOIDdpBinding = matched ;
                here->B4SOIDdpPtr = matched->CSC ;
            }

            if ((here-> B4SOIsNode != 0) && (here-> B4SOIsNode != 0))
            {
                i = here->B4SOISsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISsBinding = matched ;
                here->B4SOISsPtr = matched->CSC ;
            }

            if ((here-> B4SOIsNode != 0) && (here-> B4SOIsNodePrime != 0))
            {
                i = here->B4SOISspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->B4SOISspBinding = matched ;
                here->B4SOISspPtr = matched->CSC ;
            }

            if (here->B4SOIrbodyMod == 1)
            {
                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdbNode != 0))
                {
                    i = here->B4SOIDPdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDPdbBinding = matched ;
                    here->B4SOIDPdbPtr = matched->CSC ;
                }

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsbNode != 0))
                {
                    i = here->B4SOISPsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISPsbBinding = matched ;
                    here->B4SOISPsbPtr = matched->CSC ;
                }

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIdNodePrime != 0))
                {
                    i = here->B4SOIDBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDBdpBinding = matched ;
                    here->B4SOIDBdpPtr = matched->CSC ;
                }

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIdbNode != 0))
                {
                    i = here->B4SOIDBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDBdbBinding = matched ;
                    here->B4SOIDBdbPtr = matched->CSC ;
                }

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOIDBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDBbBinding = matched ;
                    here->B4SOIDBbPtr = matched->CSC ;
                }

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIsNodePrime != 0))
                {
                    i = here->B4SOISBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISBspBinding = matched ;
                    here->B4SOISBspPtr = matched->CSC ;
                }

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIsbNode != 0))
                {
                    i = here->B4SOISBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISBsbBinding = matched ;
                    here->B4SOISBsbPtr = matched->CSC ;
                }

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIbNode != 0))
                {
                    i = here->B4SOISBbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISBbBinding = matched ;
                    here->B4SOISBbPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIdbNode != 0))
                {
                    i = here->B4SOIBdbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBdbBinding = matched ;
                    here->B4SOIBdbPtr = matched->CSC ;
                }

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIsbNode != 0))
                {
                    i = here->B4SOIBsbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIBsbBinding = matched ;
                    here->B4SOIBsbPtr = matched->CSC ;
                }

            }
            if (model->B4SOIrdsMod)
            {
                if ((here-> B4SOIdNode != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOIDgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDgBinding = matched ;
                    here->B4SOIDgPtr = matched->CSC ;
                }

                if ((here-> B4SOIdNode != 0) && (here-> B4SOIsNodePrime != 0))
                {
                    i = here->B4SOIDspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIDspBinding = matched ;
                    here->B4SOIDspPtr = matched->CSC ;
                }

                if ((here-> B4SOIsNode != 0) && (here-> B4SOIdNodePrime != 0))
                {
                    i = here->B4SOISdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISdpBinding = matched ;
                    here->B4SOISdpPtr = matched->CSC ;
                }

                if ((here-> B4SOIsNode != 0) && (here-> B4SOIgNode != 0))
                {
                    i = here->B4SOISgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOISgBinding = matched ;
                    here->B4SOISgPtr = matched->CSC ;
                }

                if (model->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIdNode != 0) && (here-> B4SOIbNode != 0))
                    {
                        i = here->B4SOIDbPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B4SOIDbBinding = matched ;
                        here->B4SOIDbPtr = matched->CSC ;
                    }

                    if ((here-> B4SOIsNode != 0) && (here-> B4SOIbNode != 0))
                    {
                        i = here->B4SOISbPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->B4SOISbBinding = matched ;
                        here->B4SOISbPtr = matched->CSC ;
                    }

                }
            }
            if (here->B4SOIdebugMod != 0)
            {
                if ((here-> B4SOIvbsNode != 0) && (here-> B4SOIvbsNode != 0))
                {
                    i = here->B4SOIVbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIVbsBinding = matched ;
                    here->B4SOIVbsPtr = matched->CSC ;
                }

                if ((here-> B4SOIidsNode != 0) && (here-> B4SOIidsNode != 0))
                {
                    i = here->B4SOIIdsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIdsBinding = matched ;
                    here->B4SOIIdsPtr = matched->CSC ;
                }

                if ((here-> B4SOIicNode != 0) && (here-> B4SOIicNode != 0))
                {
                    i = here->B4SOIIcPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIcBinding = matched ;
                    here->B4SOIIcPtr = matched->CSC ;
                }

                if ((here-> B4SOIibsNode != 0) && (here-> B4SOIibsNode != 0))
                {
                    i = here->B4SOIIbsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIbsBinding = matched ;
                    here->B4SOIIbsPtr = matched->CSC ;
                }

                if ((here-> B4SOIibdNode != 0) && (here-> B4SOIibdNode != 0))
                {
                    i = here->B4SOIIbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIbdBinding = matched ;
                    here->B4SOIIbdPtr = matched->CSC ;
                }

                if ((here-> B4SOIiiiNode != 0) && (here-> B4SOIiiiNode != 0))
                {
                    i = here->B4SOIIiiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIiiBinding = matched ;
                    here->B4SOIIiiPtr = matched->CSC ;
                }

                if ((here-> B4SOIigNode != 0) && (here-> B4SOIigNode != 0))
                {
                    i = here->B4SOIIgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIgBinding = matched ;
                    here->B4SOIIgPtr = matched->CSC ;
                }

                if ((here-> B4SOIgiggNode != 0) && (here-> B4SOIgiggNode != 0))
                {
                    i = here->B4SOIGiggPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGiggBinding = matched ;
                    here->B4SOIGiggPtr = matched->CSC ;
                }

                if ((here-> B4SOIgigdNode != 0) && (here-> B4SOIgigdNode != 0))
                {
                    i = here->B4SOIGigdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGigdBinding = matched ;
                    here->B4SOIGigdPtr = matched->CSC ;
                }

                if ((here-> B4SOIgigbNode != 0) && (here-> B4SOIgigbNode != 0))
                {
                    i = here->B4SOIGigbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIGigbBinding = matched ;
                    here->B4SOIGigbPtr = matched->CSC ;
                }

                if ((here-> B4SOIigidlNode != 0) && (here-> B4SOIigidlNode != 0))
                {
                    i = here->B4SOIIgidlPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIgidlBinding = matched ;
                    here->B4SOIIgidlPtr = matched->CSC ;
                }

                if ((here-> B4SOIitunNode != 0) && (here-> B4SOIitunNode != 0))
                {
                    i = here->B4SOIItunPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIItunBinding = matched ;
                    here->B4SOIItunPtr = matched->CSC ;
                }

                if ((here-> B4SOIibpNode != 0) && (here-> B4SOIibpNode != 0))
                {
                    i = here->B4SOIIbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIIbpBinding = matched ;
                    here->B4SOIIbpPtr = matched->CSC ;
                }

                if ((here-> B4SOIcbbNode != 0) && (here-> B4SOIcbbNode != 0))
                {
                    i = here->B4SOICbbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOICbbBinding = matched ;
                    here->B4SOICbbPtr = matched->CSC ;
                }

                if ((here-> B4SOIcbdNode != 0) && (here-> B4SOIcbdNode != 0))
                {
                    i = here->B4SOICbdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOICbdBinding = matched ;
                    here->B4SOICbdPtr = matched->CSC ;
                }

                if ((here-> B4SOIcbgNode != 0) && (here-> B4SOIcbgNode != 0))
                {
                    i = here->B4SOICbgPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOICbgBinding = matched ;
                    here->B4SOICbgPtr = matched->CSC ;
                }

                if ((here-> B4SOIqbfNode != 0) && (here-> B4SOIqbfNode != 0))
                {
                    i = here->B4SOIQbfPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIQbfBinding = matched ;
                    here->B4SOIQbfPtr = matched->CSC ;
                }

                if ((here-> B4SOIqjsNode != 0) && (here-> B4SOIqjsNode != 0))
                {
                    i = here->B4SOIQjsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIQjsBinding = matched ;
                    here->B4SOIQjsPtr = matched->CSC ;
                }

                if ((here-> B4SOIqjdNode != 0) && (here-> B4SOIqjdNode != 0))
                {
                    i = here->B4SOIQjdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->B4SOIQjdBinding = matched ;
                    here->B4SOIQjdPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
B4SOIbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    B4SOImodel *model = (B4SOImodel *)inModel ;
    B4SOIinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B4SOI models */
    for ( ; model != NULL ; model = model->B4SOInextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B4SOIinstances ; here != NULL ; here = here->B4SOInextInstance)
        {
            if ((model->B4SOIshMod == 1) && (here->B4SOIrth0 != 0.0))
            {
                if ((here-> B4SOItempNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOITemptempPtr = here->B4SOITemptempBinding->CSC_Complex ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOITempdpPtr = here->B4SOITempdpBinding->CSC_Complex ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOITempspPtr = here->B4SOITempspBinding->CSC_Complex ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOITempgPtr = here->B4SOITempgBinding->CSC_Complex ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOITempbPtr = here->B4SOITempbBinding->CSC_Complex ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIGtempPtr = here->B4SOIGtempBinding->CSC_Complex ;

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIDPtempPtr = here->B4SOIDPtempBinding->CSC_Complex ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOISPtempPtr = here->B4SOISPtempBinding->CSC_Complex ;

                if ((here-> B4SOIeNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIEtempPtr = here->B4SOIEtempBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIBtempPtr = here->B4SOIBtempBinding->CSC_Complex ;

                if (here->B4SOIbodyMod == 1)
                {
                    if ((here-> B4SOIpNode != 0) && (here-> B4SOItempNode != 0))
                        here->B4SOIPtempPtr = here->B4SOIPtempBinding->CSC_Complex ;

                }
                if (here->B4SOIsoiMod != 0)
                {
                    if ((here-> B4SOItempNode != 0) && (here-> B4SOIeNode != 0))
                        here->B4SOITempePtr = here->B4SOITempeBinding->CSC_Complex ;

                }
            }
            if (here->B4SOIbodyMod == 2)
            {
            }
            else if (here->B4SOIbodyMod == 1)
            {
                if ((here-> B4SOIbNode != 0) && (here-> B4SOIpNode != 0))
                    here->B4SOIBpPtr = here->B4SOIBpBinding->CSC_Complex ;

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIPbPtr = here->B4SOIPbBinding->CSC_Complex ;

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIpNode != 0))
                    here->B4SOIPpPtr = here->B4SOIPpBinding->CSC_Complex ;

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIPgPtr = here->B4SOIPgBinding->CSC_Complex ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIpNode != 0))
                    here->B4SOIGpPtr = here->B4SOIGpBinding->CSC_Complex ;

            }
            if (here->B4SOIrgateMod != 0)
            {
                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNodeExt != 0))
                    here->B4SOIGEgePtr = here->B4SOIGEgeBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIGEgPtr = here->B4SOIGEgBinding->CSC_Complex ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNodeExt != 0))
                    here->B4SOIGgePtr = here->B4SOIGgeBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIGEdpPtr = here->B4SOIGEdpBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIGEspPtr = here->B4SOIGEspBinding->CSC_Complex ;

                if (here->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOIGEbPtr = here->B4SOIGEbBinding->CSC_Complex ;

                }
                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIGMdpPtr = here->B4SOIGMdpBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIGMgPtr = here->B4SOIGMgBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIGMgmPtr = here->B4SOIGMgmBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNodeExt != 0))
                    here->B4SOIGMgePtr = here->B4SOIGMgeBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIGMspPtr = here->B4SOIGMspBinding->CSC_Complex ;

                if (here->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOIGMbPtr = here->B4SOIGMbBinding->CSC_Complex ;

                }
                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIeNode != 0))
                    here->B4SOIGMePtr = here->B4SOIGMeBinding->CSC_Complex ;

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIDPgmPtr = here->B4SOIDPgmBinding->CSC_Complex ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIGgmPtr = here->B4SOIGgmBinding->CSC_Complex ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIGEgmPtr = here->B4SOIGEgmBinding->CSC_Complex ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOISPgmPtr = here->B4SOISPgmBinding->CSC_Complex ;

                if ((here-> B4SOIeNode != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIEgmPtr = here->B4SOIEgmBinding->CSC_Complex ;

            }
            if (here->B4SOIsoiMod != 2) /* v3.2 */
            {
                if ((here-> B4SOIeNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIEbPtr = here->B4SOIEbBinding->CSC_Complex ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIGbPtr = here->B4SOIGbBinding->CSC_Complex ;

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIDPbPtr = here->B4SOIDPbBinding->CSC_Complex ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOISPbPtr = here->B4SOISPbBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIeNode != 0))
                    here->B4SOIBePtr = here->B4SOIBeBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIBgPtr = here->B4SOIBgBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIBdpPtr = here->B4SOIBdpBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIBspPtr = here->B4SOIBspBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIBbPtr = here->B4SOIBbBinding->CSC_Complex ;

            }
            if ((here-> B4SOIeNode != 0) && (here-> B4SOIgNode != 0))
                here->B4SOIEgPtr = here->B4SOIEgBinding->CSC_Complex ;

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIEdpPtr = here->B4SOIEdpBinding->CSC_Complex ;

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOIEspPtr = here->B4SOIEspBinding->CSC_Complex ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIeNode != 0))
                here->B4SOIGePtr = here->B4SOIGeBinding->CSC_Complex ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIeNode != 0))
                here->B4SOIDPePtr = here->B4SOIDPeBinding->CSC_Complex ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIeNode != 0))
                here->B4SOISPePtr = here->B4SOISPeBinding->CSC_Complex ;

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIeNode != 0))
                here->B4SOIEePtr = here->B4SOIEeBinding->CSC_Complex ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNode != 0))
                here->B4SOIGgPtr = here->B4SOIGgBinding->CSC_Complex ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIGdpPtr = here->B4SOIGdpBinding->CSC_Complex ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOIGspPtr = here->B4SOIGspBinding->CSC_Complex ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIgNode != 0))
                here->B4SOIDPgPtr = here->B4SOIDPgBinding->CSC_Complex ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIDPdpPtr = here->B4SOIDPdpBinding->CSC_Complex ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOIDPspPtr = here->B4SOIDPspBinding->CSC_Complex ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdNode != 0))
                here->B4SOIDPdPtr = here->B4SOIDPdBinding->CSC_Complex ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIgNode != 0))
                here->B4SOISPgPtr = here->B4SOISPgBinding->CSC_Complex ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOISPdpPtr = here->B4SOISPdpBinding->CSC_Complex ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOISPspPtr = here->B4SOISPspBinding->CSC_Complex ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsNode != 0))
                here->B4SOISPsPtr = here->B4SOISPsBinding->CSC_Complex ;

            if ((here-> B4SOIdNode != 0) && (here-> B4SOIdNode != 0))
                here->B4SOIDdPtr = here->B4SOIDdBinding->CSC_Complex ;

            if ((here-> B4SOIdNode != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIDdpPtr = here->B4SOIDdpBinding->CSC_Complex ;

            if ((here-> B4SOIsNode != 0) && (here-> B4SOIsNode != 0))
                here->B4SOISsPtr = here->B4SOISsBinding->CSC_Complex ;

            if ((here-> B4SOIsNode != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOISspPtr = here->B4SOISspBinding->CSC_Complex ;

            if (here->B4SOIrbodyMod == 1)
            {
                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdbNode != 0))
                    here->B4SOIDPdbPtr = here->B4SOIDPdbBinding->CSC_Complex ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsbNode != 0))
                    here->B4SOISPsbPtr = here->B4SOISPsbBinding->CSC_Complex ;

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIDBdpPtr = here->B4SOIDBdpBinding->CSC_Complex ;

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIdbNode != 0))
                    here->B4SOIDBdbPtr = here->B4SOIDBdbBinding->CSC_Complex ;

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIDBbPtr = here->B4SOIDBbBinding->CSC_Complex ;

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOISBspPtr = here->B4SOISBspBinding->CSC_Complex ;

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIsbNode != 0))
                    here->B4SOISBsbPtr = here->B4SOISBsbBinding->CSC_Complex ;

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOISBbPtr = here->B4SOISBbBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIdbNode != 0))
                    here->B4SOIBdbPtr = here->B4SOIBdbBinding->CSC_Complex ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIsbNode != 0))
                    here->B4SOIBsbPtr = here->B4SOIBsbBinding->CSC_Complex ;

            }
            if (model->B4SOIrdsMod)
            {
                if ((here-> B4SOIdNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIDgPtr = here->B4SOIDgBinding->CSC_Complex ;

                if ((here-> B4SOIdNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIDspPtr = here->B4SOIDspBinding->CSC_Complex ;

                if ((here-> B4SOIsNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOISdpPtr = here->B4SOISdpBinding->CSC_Complex ;

                if ((here-> B4SOIsNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOISgPtr = here->B4SOISgBinding->CSC_Complex ;

                if (model->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIdNode != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOIDbPtr = here->B4SOIDbBinding->CSC_Complex ;

                    if ((here-> B4SOIsNode != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOISbPtr = here->B4SOISbBinding->CSC_Complex ;

                }
            }
            if (here->B4SOIdebugMod != 0)
            {
                if ((here-> B4SOIvbsNode != 0) && (here-> B4SOIvbsNode != 0))
                    here->B4SOIVbsPtr = here->B4SOIVbsBinding->CSC_Complex ;

                if ((here-> B4SOIidsNode != 0) && (here-> B4SOIidsNode != 0))
                    here->B4SOIIdsPtr = here->B4SOIIdsBinding->CSC_Complex ;

                if ((here-> B4SOIicNode != 0) && (here-> B4SOIicNode != 0))
                    here->B4SOIIcPtr = here->B4SOIIcBinding->CSC_Complex ;

                if ((here-> B4SOIibsNode != 0) && (here-> B4SOIibsNode != 0))
                    here->B4SOIIbsPtr = here->B4SOIIbsBinding->CSC_Complex ;

                if ((here-> B4SOIibdNode != 0) && (here-> B4SOIibdNode != 0))
                    here->B4SOIIbdPtr = here->B4SOIIbdBinding->CSC_Complex ;

                if ((here-> B4SOIiiiNode != 0) && (here-> B4SOIiiiNode != 0))
                    here->B4SOIIiiPtr = here->B4SOIIiiBinding->CSC_Complex ;

                if ((here-> B4SOIigNode != 0) && (here-> B4SOIigNode != 0))
                    here->B4SOIIgPtr = here->B4SOIIgBinding->CSC_Complex ;

                if ((here-> B4SOIgiggNode != 0) && (here-> B4SOIgiggNode != 0))
                    here->B4SOIGiggPtr = here->B4SOIGiggBinding->CSC_Complex ;

                if ((here-> B4SOIgigdNode != 0) && (here-> B4SOIgigdNode != 0))
                    here->B4SOIGigdPtr = here->B4SOIGigdBinding->CSC_Complex ;

                if ((here-> B4SOIgigbNode != 0) && (here-> B4SOIgigbNode != 0))
                    here->B4SOIGigbPtr = here->B4SOIGigbBinding->CSC_Complex ;

                if ((here-> B4SOIigidlNode != 0) && (here-> B4SOIigidlNode != 0))
                    here->B4SOIIgidlPtr = here->B4SOIIgidlBinding->CSC_Complex ;

                if ((here-> B4SOIitunNode != 0) && (here-> B4SOIitunNode != 0))
                    here->B4SOIItunPtr = here->B4SOIItunBinding->CSC_Complex ;

                if ((here-> B4SOIibpNode != 0) && (here-> B4SOIibpNode != 0))
                    here->B4SOIIbpPtr = here->B4SOIIbpBinding->CSC_Complex ;

                if ((here-> B4SOIcbbNode != 0) && (here-> B4SOIcbbNode != 0))
                    here->B4SOICbbPtr = here->B4SOICbbBinding->CSC_Complex ;

                if ((here-> B4SOIcbdNode != 0) && (here-> B4SOIcbdNode != 0))
                    here->B4SOICbdPtr = here->B4SOICbdBinding->CSC_Complex ;

                if ((here-> B4SOIcbgNode != 0) && (here-> B4SOIcbgNode != 0))
                    here->B4SOICbgPtr = here->B4SOICbgBinding->CSC_Complex ;

                if ((here-> B4SOIqbfNode != 0) && (here-> B4SOIqbfNode != 0))
                    here->B4SOIQbfPtr = here->B4SOIQbfBinding->CSC_Complex ;

                if ((here-> B4SOIqjsNode != 0) && (here-> B4SOIqjsNode != 0))
                    here->B4SOIQjsPtr = here->B4SOIQjsBinding->CSC_Complex ;

                if ((here-> B4SOIqjdNode != 0) && (here-> B4SOIqjdNode != 0))
                    here->B4SOIQjdPtr = here->B4SOIQjdBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
B4SOIbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    B4SOImodel *model = (B4SOImodel *)inModel ;
    B4SOIinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the B4SOI models */
    for ( ; model != NULL ; model = model->B4SOInextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->B4SOIinstances ; here != NULL ; here = here->B4SOInextInstance)
        {
            if ((model->B4SOIshMod == 1) && (here->B4SOIrth0 != 0.0))
            {
                if ((here-> B4SOItempNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOITemptempPtr = here->B4SOITemptempBinding->CSC ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOITempdpPtr = here->B4SOITempdpBinding->CSC ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOITempspPtr = here->B4SOITempspBinding->CSC ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOITempgPtr = here->B4SOITempgBinding->CSC ;

                if ((here-> B4SOItempNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOITempbPtr = here->B4SOITempbBinding->CSC ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIGtempPtr = here->B4SOIGtempBinding->CSC ;

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIDPtempPtr = here->B4SOIDPtempBinding->CSC ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOISPtempPtr = here->B4SOISPtempBinding->CSC ;

                if ((here-> B4SOIeNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIEtempPtr = here->B4SOIEtempBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOItempNode != 0))
                    here->B4SOIBtempPtr = here->B4SOIBtempBinding->CSC ;

                if (here->B4SOIbodyMod == 1)
                {
                    if ((here-> B4SOIpNode != 0) && (here-> B4SOItempNode != 0))
                        here->B4SOIPtempPtr = here->B4SOIPtempBinding->CSC ;

                }
                if (here->B4SOIsoiMod != 0)
                {
                    if ((here-> B4SOItempNode != 0) && (here-> B4SOIeNode != 0))
                        here->B4SOITempePtr = here->B4SOITempeBinding->CSC ;

                }
            }
            if (here->B4SOIbodyMod == 2)
            {
            }
            else if (here->B4SOIbodyMod == 1)
            {
                if ((here-> B4SOIbNode != 0) && (here-> B4SOIpNode != 0))
                    here->B4SOIBpPtr = here->B4SOIBpBinding->CSC ;

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIPbPtr = here->B4SOIPbBinding->CSC ;

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIpNode != 0))
                    here->B4SOIPpPtr = here->B4SOIPpBinding->CSC ;

                if ((here-> B4SOIpNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIPgPtr = here->B4SOIPgBinding->CSC ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIpNode != 0))
                    here->B4SOIGpPtr = here->B4SOIGpBinding->CSC ;

            }
            if (here->B4SOIrgateMod != 0)
            {
                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNodeExt != 0))
                    here->B4SOIGEgePtr = here->B4SOIGEgeBinding->CSC ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIGEgPtr = here->B4SOIGEgBinding->CSC ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNodeExt != 0))
                    here->B4SOIGgePtr = here->B4SOIGgeBinding->CSC ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIGEdpPtr = here->B4SOIGEdpBinding->CSC ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIGEspPtr = here->B4SOIGEspBinding->CSC ;

                if (here->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOIGEbPtr = here->B4SOIGEbBinding->CSC ;

                }
                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIGMdpPtr = here->B4SOIGMdpBinding->CSC ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIGMgPtr = here->B4SOIGMgBinding->CSC ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIGMgmPtr = here->B4SOIGMgmBinding->CSC ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIgNodeExt != 0))
                    here->B4SOIGMgePtr = here->B4SOIGMgeBinding->CSC ;

                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIGMspPtr = here->B4SOIGMspBinding->CSC ;

                if (here->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOIGMbPtr = here->B4SOIGMbBinding->CSC ;

                }
                if ((here-> B4SOIgNodeMid != 0) && (here-> B4SOIeNode != 0))
                    here->B4SOIGMePtr = here->B4SOIGMeBinding->CSC ;

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIDPgmPtr = here->B4SOIDPgmBinding->CSC ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIGgmPtr = here->B4SOIGgmBinding->CSC ;

                if ((here-> B4SOIgNodeExt != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIGEgmPtr = here->B4SOIGEgmBinding->CSC ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOISPgmPtr = here->B4SOISPgmBinding->CSC ;

                if ((here-> B4SOIeNode != 0) && (here-> B4SOIgNodeMid != 0))
                    here->B4SOIEgmPtr = here->B4SOIEgmBinding->CSC ;

            }
            if (here->B4SOIsoiMod != 2) /* v3.2 */
            {
                if ((here-> B4SOIeNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIEbPtr = here->B4SOIEbBinding->CSC ;

                if ((here-> B4SOIgNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIGbPtr = here->B4SOIGbBinding->CSC ;

                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIDPbPtr = here->B4SOIDPbBinding->CSC ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOISPbPtr = here->B4SOISPbBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIeNode != 0))
                    here->B4SOIBePtr = here->B4SOIBeBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIBgPtr = here->B4SOIBgBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIBdpPtr = here->B4SOIBdpBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIBspPtr = here->B4SOIBspBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIBbPtr = here->B4SOIBbBinding->CSC ;

            }
            if ((here-> B4SOIeNode != 0) && (here-> B4SOIgNode != 0))
                here->B4SOIEgPtr = here->B4SOIEgBinding->CSC ;

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIEdpPtr = here->B4SOIEdpBinding->CSC ;

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOIEspPtr = here->B4SOIEspBinding->CSC ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIeNode != 0))
                here->B4SOIGePtr = here->B4SOIGeBinding->CSC ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIeNode != 0))
                here->B4SOIDPePtr = here->B4SOIDPeBinding->CSC ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIeNode != 0))
                here->B4SOISPePtr = here->B4SOISPeBinding->CSC ;

            if ((here-> B4SOIeNode != 0) && (here-> B4SOIeNode != 0))
                here->B4SOIEePtr = here->B4SOIEeBinding->CSC ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIgNode != 0))
                here->B4SOIGgPtr = here->B4SOIGgBinding->CSC ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIGdpPtr = here->B4SOIGdpBinding->CSC ;

            if ((here-> B4SOIgNode != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOIGspPtr = here->B4SOIGspBinding->CSC ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIgNode != 0))
                here->B4SOIDPgPtr = here->B4SOIDPgBinding->CSC ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIDPdpPtr = here->B4SOIDPdpBinding->CSC ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOIDPspPtr = here->B4SOIDPspBinding->CSC ;

            if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdNode != 0))
                here->B4SOIDPdPtr = here->B4SOIDPdBinding->CSC ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIgNode != 0))
                here->B4SOISPgPtr = here->B4SOISPgBinding->CSC ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOISPdpPtr = here->B4SOISPdpBinding->CSC ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOISPspPtr = here->B4SOISPspBinding->CSC ;

            if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsNode != 0))
                here->B4SOISPsPtr = here->B4SOISPsBinding->CSC ;

            if ((here-> B4SOIdNode != 0) && (here-> B4SOIdNode != 0))
                here->B4SOIDdPtr = here->B4SOIDdBinding->CSC ;

            if ((here-> B4SOIdNode != 0) && (here-> B4SOIdNodePrime != 0))
                here->B4SOIDdpPtr = here->B4SOIDdpBinding->CSC ;

            if ((here-> B4SOIsNode != 0) && (here-> B4SOIsNode != 0))
                here->B4SOISsPtr = here->B4SOISsBinding->CSC ;

            if ((here-> B4SOIsNode != 0) && (here-> B4SOIsNodePrime != 0))
                here->B4SOISspPtr = here->B4SOISspBinding->CSC ;

            if (here->B4SOIrbodyMod == 1)
            {
                if ((here-> B4SOIdNodePrime != 0) && (here-> B4SOIdbNode != 0))
                    here->B4SOIDPdbPtr = here->B4SOIDPdbBinding->CSC ;

                if ((here-> B4SOIsNodePrime != 0) && (here-> B4SOIsbNode != 0))
                    here->B4SOISPsbPtr = here->B4SOISPsbBinding->CSC ;

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOIDBdpPtr = here->B4SOIDBdpBinding->CSC ;

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIdbNode != 0))
                    here->B4SOIDBdbPtr = here->B4SOIDBdbBinding->CSC ;

                if ((here-> B4SOIdbNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOIDBbPtr = here->B4SOIDBbBinding->CSC ;

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOISBspPtr = here->B4SOISBspBinding->CSC ;

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIsbNode != 0))
                    here->B4SOISBsbPtr = here->B4SOISBsbBinding->CSC ;

                if ((here-> B4SOIsbNode != 0) && (here-> B4SOIbNode != 0))
                    here->B4SOISBbPtr = here->B4SOISBbBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIdbNode != 0))
                    here->B4SOIBdbPtr = here->B4SOIBdbBinding->CSC ;

                if ((here-> B4SOIbNode != 0) && (here-> B4SOIsbNode != 0))
                    here->B4SOIBsbPtr = here->B4SOIBsbBinding->CSC ;

            }
            if (model->B4SOIrdsMod)
            {
                if ((here-> B4SOIdNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOIDgPtr = here->B4SOIDgBinding->CSC ;

                if ((here-> B4SOIdNode != 0) && (here-> B4SOIsNodePrime != 0))
                    here->B4SOIDspPtr = here->B4SOIDspBinding->CSC ;

                if ((here-> B4SOIsNode != 0) && (here-> B4SOIdNodePrime != 0))
                    here->B4SOISdpPtr = here->B4SOISdpBinding->CSC ;

                if ((here-> B4SOIsNode != 0) && (here-> B4SOIgNode != 0))
                    here->B4SOISgPtr = here->B4SOISgBinding->CSC ;

                if (model->B4SOIsoiMod != 2)
                {
                    if ((here-> B4SOIdNode != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOIDbPtr = here->B4SOIDbBinding->CSC ;

                    if ((here-> B4SOIsNode != 0) && (here-> B4SOIbNode != 0))
                        here->B4SOISbPtr = here->B4SOISbBinding->CSC ;

                }
            }
            if (here->B4SOIdebugMod != 0)
            {
                if ((here-> B4SOIvbsNode != 0) && (here-> B4SOIvbsNode != 0))
                    here->B4SOIVbsPtr = here->B4SOIVbsBinding->CSC ;

                if ((here-> B4SOIidsNode != 0) && (here-> B4SOIidsNode != 0))
                    here->B4SOIIdsPtr = here->B4SOIIdsBinding->CSC ;

                if ((here-> B4SOIicNode != 0) && (here-> B4SOIicNode != 0))
                    here->B4SOIIcPtr = here->B4SOIIcBinding->CSC ;

                if ((here-> B4SOIibsNode != 0) && (here-> B4SOIibsNode != 0))
                    here->B4SOIIbsPtr = here->B4SOIIbsBinding->CSC ;

                if ((here-> B4SOIibdNode != 0) && (here-> B4SOIibdNode != 0))
                    here->B4SOIIbdPtr = here->B4SOIIbdBinding->CSC ;

                if ((here-> B4SOIiiiNode != 0) && (here-> B4SOIiiiNode != 0))
                    here->B4SOIIiiPtr = here->B4SOIIiiBinding->CSC ;

                if ((here-> B4SOIigNode != 0) && (here-> B4SOIigNode != 0))
                    here->B4SOIIgPtr = here->B4SOIIgBinding->CSC ;

                if ((here-> B4SOIgiggNode != 0) && (here-> B4SOIgiggNode != 0))
                    here->B4SOIGiggPtr = here->B4SOIGiggBinding->CSC ;

                if ((here-> B4SOIgigdNode != 0) && (here-> B4SOIgigdNode != 0))
                    here->B4SOIGigdPtr = here->B4SOIGigdBinding->CSC ;

                if ((here-> B4SOIgigbNode != 0) && (here-> B4SOIgigbNode != 0))
                    here->B4SOIGigbPtr = here->B4SOIGigbBinding->CSC ;

                if ((here-> B4SOIigidlNode != 0) && (here-> B4SOIigidlNode != 0))
                    here->B4SOIIgidlPtr = here->B4SOIIgidlBinding->CSC ;

                if ((here-> B4SOIitunNode != 0) && (here-> B4SOIitunNode != 0))
                    here->B4SOIItunPtr = here->B4SOIItunBinding->CSC ;

                if ((here-> B4SOIibpNode != 0) && (here-> B4SOIibpNode != 0))
                    here->B4SOIIbpPtr = here->B4SOIIbpBinding->CSC ;

                if ((here-> B4SOIcbbNode != 0) && (here-> B4SOIcbbNode != 0))
                    here->B4SOICbbPtr = here->B4SOICbbBinding->CSC ;

                if ((here-> B4SOIcbdNode != 0) && (here-> B4SOIcbdNode != 0))
                    here->B4SOICbdPtr = here->B4SOICbdBinding->CSC ;

                if ((here-> B4SOIcbgNode != 0) && (here-> B4SOIcbgNode != 0))
                    here->B4SOICbgPtr = here->B4SOICbgBinding->CSC ;

                if ((here-> B4SOIqbfNode != 0) && (here-> B4SOIqbfNode != 0))
                    here->B4SOIQbfPtr = here->B4SOIQbfBinding->CSC ;

                if ((here-> B4SOIqjsNode != 0) && (here-> B4SOIqjsNode != 0))
                    here->B4SOIQjsPtr = here->B4SOIQjsBinding->CSC ;

                if ((here-> B4SOIqjdNode != 0) && (here-> B4SOIqjdNode != 0))
                    here->B4SOIQjdPtr = here->B4SOIQjdBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
