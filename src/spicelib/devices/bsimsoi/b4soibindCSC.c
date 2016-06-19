/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b4soidef.h"
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
                XFOO(B4SOITemptempPtr, B4SOITemptempBinding, B4SOItempNode, B4SOItempNode);
                XFOO(B4SOITempdpPtr, B4SOITempdpBinding, B4SOItempNode, B4SOIdNodePrime);
                XFOO(B4SOITempspPtr, B4SOITempspBinding, B4SOItempNode, B4SOIsNodePrime);
                XFOO(B4SOITempgPtr, B4SOITempgBinding, B4SOItempNode, B4SOIgNode);
                XFOO(B4SOITempbPtr, B4SOITempbBinding, B4SOItempNode, B4SOIbNode);
                XFOO(B4SOIGtempPtr, B4SOIGtempBinding, B4SOIgNode, B4SOItempNode);
                XFOO(B4SOIDPtempPtr, B4SOIDPtempBinding, B4SOIdNodePrime, B4SOItempNode);
                XFOO(B4SOISPtempPtr, B4SOISPtempBinding, B4SOIsNodePrime, B4SOItempNode);
                XFOO(B4SOIEtempPtr, B4SOIEtempBinding, B4SOIeNode, B4SOItempNode);
                XFOO(B4SOIBtempPtr, B4SOIBtempBinding, B4SOIbNode, B4SOItempNode);
                if (here->B4SOIbodyMod == 1)
                {
                    XFOO(B4SOIPtempPtr, B4SOIPtempBinding, B4SOIpNode, B4SOItempNode);
                }
                if (here->B4SOIsoiMod != 0)
                {
                    XFOO(B4SOITempePtr, B4SOITempeBinding, B4SOItempNode, B4SOIeNode);
                }
            }
            if (here->B4SOIbodyMod == 2)
            {
            }
            else if (here->B4SOIbodyMod == 1)
            {
                XFOO(B4SOIBpPtr, B4SOIBpBinding, B4SOIbNode, B4SOIpNode);
                XFOO(B4SOIPbPtr, B4SOIPbBinding, B4SOIpNode, B4SOIbNode);
                XFOO(B4SOIPpPtr, B4SOIPpBinding, B4SOIpNode, B4SOIpNode);
                XFOO(B4SOIPgPtr, B4SOIPgBinding, B4SOIpNode, B4SOIgNode);
                XFOO(B4SOIGpPtr, B4SOIGpBinding, B4SOIgNode, B4SOIpNode);
            }
            if (here->B4SOIrgateMod != 0)
            {
                XFOO(B4SOIGEgePtr, B4SOIGEgeBinding, B4SOIgNodeExt, B4SOIgNodeExt);
                XFOO(B4SOIGEgPtr, B4SOIGEgBinding, B4SOIgNodeExt, B4SOIgNode);
                XFOO(B4SOIGgePtr, B4SOIGgeBinding, B4SOIgNode, B4SOIgNodeExt);
                XFOO(B4SOIGEdpPtr, B4SOIGEdpBinding, B4SOIgNodeExt, B4SOIdNodePrime);
                XFOO(B4SOIGEspPtr, B4SOIGEspBinding, B4SOIgNodeExt, B4SOIsNodePrime);
                if (here->B4SOIsoiMod != 2)
                {
                    XFOO(B4SOIGEbPtr, B4SOIGEbBinding, B4SOIgNodeExt, B4SOIbNode);
                }
                XFOO(B4SOIGMdpPtr, B4SOIGMdpBinding, B4SOIgNodeMid, B4SOIdNodePrime);
                XFOO(B4SOIGMgPtr, B4SOIGMgBinding, B4SOIgNodeMid, B4SOIgNode);
                XFOO(B4SOIGMgmPtr, B4SOIGMgmBinding, B4SOIgNodeMid, B4SOIgNodeMid);
                XFOO(B4SOIGMgePtr, B4SOIGMgeBinding, B4SOIgNodeMid, B4SOIgNodeExt);
                XFOO(B4SOIGMspPtr, B4SOIGMspBinding, B4SOIgNodeMid, B4SOIsNodePrime);
                if (here->B4SOIsoiMod != 2)
                {
                    XFOO(B4SOIGMbPtr, B4SOIGMbBinding, B4SOIgNodeMid, B4SOIbNode);
                }
                XFOO(B4SOIGMePtr, B4SOIGMeBinding, B4SOIgNodeMid, B4SOIeNode);
                XFOO(B4SOIDPgmPtr, B4SOIDPgmBinding, B4SOIdNodePrime, B4SOIgNodeMid);
                XFOO(B4SOIGgmPtr, B4SOIGgmBinding, B4SOIgNode, B4SOIgNodeMid);
                XFOO(B4SOIGEgmPtr, B4SOIGEgmBinding, B4SOIgNodeExt, B4SOIgNodeMid);
                XFOO(B4SOISPgmPtr, B4SOISPgmBinding, B4SOIsNodePrime, B4SOIgNodeMid);
                XFOO(B4SOIEgmPtr, B4SOIEgmBinding, B4SOIeNode, B4SOIgNodeMid);
            }
            if (here->B4SOIsoiMod != 2) /* v3.2 */
            {
                XFOO(B4SOIEbPtr, B4SOIEbBinding, B4SOIeNode, B4SOIbNode);
                XFOO(B4SOIGbPtr, B4SOIGbBinding, B4SOIgNode, B4SOIbNode);
                XFOO(B4SOIDPbPtr, B4SOIDPbBinding, B4SOIdNodePrime, B4SOIbNode);
                XFOO(B4SOISPbPtr, B4SOISPbBinding, B4SOIsNodePrime, B4SOIbNode);
                XFOO(B4SOIBePtr, B4SOIBeBinding, B4SOIbNode, B4SOIeNode);
                XFOO(B4SOIBgPtr, B4SOIBgBinding, B4SOIbNode, B4SOIgNode);
                XFOO(B4SOIBdpPtr, B4SOIBdpBinding, B4SOIbNode, B4SOIdNodePrime);
                XFOO(B4SOIBspPtr, B4SOIBspBinding, B4SOIbNode, B4SOIsNodePrime);
                XFOO(B4SOIBbPtr, B4SOIBbBinding, B4SOIbNode, B4SOIbNode);
            }
            XFOO(B4SOIEgPtr, B4SOIEgBinding, B4SOIeNode, B4SOIgNode);
            XFOO(B4SOIEdpPtr, B4SOIEdpBinding, B4SOIeNode, B4SOIdNodePrime);
            XFOO(B4SOIEspPtr, B4SOIEspBinding, B4SOIeNode, B4SOIsNodePrime);
            XFOO(B4SOIGePtr, B4SOIGeBinding, B4SOIgNode, B4SOIeNode);
            XFOO(B4SOIDPePtr, B4SOIDPeBinding, B4SOIdNodePrime, B4SOIeNode);
            XFOO(B4SOISPePtr, B4SOISPeBinding, B4SOIsNodePrime, B4SOIeNode);
            XFOO(B4SOIEePtr, B4SOIEeBinding, B4SOIeNode, B4SOIeNode);
            XFOO(B4SOIGgPtr, B4SOIGgBinding, B4SOIgNode, B4SOIgNode);
            XFOO(B4SOIGdpPtr, B4SOIGdpBinding, B4SOIgNode, B4SOIdNodePrime);
            XFOO(B4SOIGspPtr, B4SOIGspBinding, B4SOIgNode, B4SOIsNodePrime);
            XFOO(B4SOIDPgPtr, B4SOIDPgBinding, B4SOIdNodePrime, B4SOIgNode);
            XFOO(B4SOIDPdpPtr, B4SOIDPdpBinding, B4SOIdNodePrime, B4SOIdNodePrime);
            XFOO(B4SOIDPspPtr, B4SOIDPspBinding, B4SOIdNodePrime, B4SOIsNodePrime);
            XFOO(B4SOIDPdPtr, B4SOIDPdBinding, B4SOIdNodePrime, B4SOIdNode);
            XFOO(B4SOISPgPtr, B4SOISPgBinding, B4SOIsNodePrime, B4SOIgNode);
            XFOO(B4SOISPdpPtr, B4SOISPdpBinding, B4SOIsNodePrime, B4SOIdNodePrime);
            XFOO(B4SOISPspPtr, B4SOISPspBinding, B4SOIsNodePrime, B4SOIsNodePrime);
            XFOO(B4SOISPsPtr, B4SOISPsBinding, B4SOIsNodePrime, B4SOIsNode);
            XFOO(B4SOIDdPtr, B4SOIDdBinding, B4SOIdNode, B4SOIdNode);
            XFOO(B4SOIDdpPtr, B4SOIDdpBinding, B4SOIdNode, B4SOIdNodePrime);
            XFOO(B4SOISsPtr, B4SOISsBinding, B4SOIsNode, B4SOIsNode);
            XFOO(B4SOISspPtr, B4SOISspBinding, B4SOIsNode, B4SOIsNodePrime);
            if (here->B4SOIrbodyMod == 1)
            {
                XFOO(B4SOIDPdbPtr, B4SOIDPdbBinding, B4SOIdNodePrime, B4SOIdbNode);
                XFOO(B4SOISPsbPtr, B4SOISPsbBinding, B4SOIsNodePrime, B4SOIsbNode);
                XFOO(B4SOIDBdpPtr, B4SOIDBdpBinding, B4SOIdbNode, B4SOIdNodePrime);
                XFOO(B4SOIDBdbPtr, B4SOIDBdbBinding, B4SOIdbNode, B4SOIdbNode);
                XFOO(B4SOIDBbPtr, B4SOIDBbBinding, B4SOIdbNode, B4SOIbNode);
                XFOO(B4SOISBspPtr, B4SOISBspBinding, B4SOIsbNode, B4SOIsNodePrime);
                XFOO(B4SOISBsbPtr, B4SOISBsbBinding, B4SOIsbNode, B4SOIsbNode);
                XFOO(B4SOISBbPtr, B4SOISBbBinding, B4SOIsbNode, B4SOIbNode);
                XFOO(B4SOIBdbPtr, B4SOIBdbBinding, B4SOIbNode, B4SOIdbNode);
                XFOO(B4SOIBsbPtr, B4SOIBsbBinding, B4SOIbNode, B4SOIsbNode);
            }
            if (model->B4SOIrdsMod)
            {
                XFOO(B4SOIDgPtr, B4SOIDgBinding, B4SOIdNode, B4SOIgNode);
                XFOO(B4SOIDspPtr, B4SOIDspBinding, B4SOIdNode, B4SOIsNodePrime);
                XFOO(B4SOISdpPtr, B4SOISdpBinding, B4SOIsNode, B4SOIdNodePrime);
                XFOO(B4SOISgPtr, B4SOISgBinding, B4SOIsNode, B4SOIgNode);
                if (model->B4SOIsoiMod != 2)
                {
                    XFOO(B4SOIDbPtr, B4SOIDbBinding, B4SOIdNode, B4SOIbNode);
                    XFOO(B4SOISbPtr, B4SOISbBinding, B4SOIsNode, B4SOIbNode);
                }
            }
            if (here->B4SOIdebugMod != 0)
            {
                XFOO(B4SOIVbsPtr, B4SOIVbsBinding, B4SOIvbsNode, B4SOIvbsNode);
                XFOO(B4SOIIdsPtr, B4SOIIdsBinding, B4SOIidsNode, B4SOIidsNode);
                XFOO(B4SOIIcPtr, B4SOIIcBinding, B4SOIicNode, B4SOIicNode);
                XFOO(B4SOIIbsPtr, B4SOIIbsBinding, B4SOIibsNode, B4SOIibsNode);
                XFOO(B4SOIIbdPtr, B4SOIIbdBinding, B4SOIibdNode, B4SOIibdNode);
                XFOO(B4SOIIiiPtr, B4SOIIiiBinding, B4SOIiiiNode, B4SOIiiiNode);
                XFOO(B4SOIIgPtr, B4SOIIgBinding, B4SOIigNode, B4SOIigNode);
                XFOO(B4SOIGiggPtr, B4SOIGiggBinding, B4SOIgiggNode, B4SOIgiggNode);
                XFOO(B4SOIGigdPtr, B4SOIGigdBinding, B4SOIgigdNode, B4SOIgigdNode);
                XFOO(B4SOIGigbPtr, B4SOIGigbBinding, B4SOIgigbNode, B4SOIgigbNode);
                XFOO(B4SOIIgidlPtr, B4SOIIgidlBinding, B4SOIigidlNode, B4SOIigidlNode);
                XFOO(B4SOIItunPtr, B4SOIItunBinding, B4SOIitunNode, B4SOIitunNode);
                XFOO(B4SOIIbpPtr, B4SOIIbpBinding, B4SOIibpNode, B4SOIibpNode);
                XFOO(B4SOICbbPtr, B4SOICbbBinding, B4SOIcbbNode, B4SOIcbbNode);
                XFOO(B4SOICbdPtr, B4SOICbdBinding, B4SOIcbdNode, B4SOIcbdNode);
                XFOO(B4SOICbgPtr, B4SOICbgBinding, B4SOIcbgNode, B4SOIcbgNode);
                XFOO(B4SOIQbfPtr, B4SOIQbfBinding, B4SOIqbfNode, B4SOIqbfNode);
                XFOO(B4SOIQjsPtr, B4SOIQjsBinding, B4SOIqjsNode, B4SOIqjsNode);
                XFOO(B4SOIQjdPtr, B4SOIQjdBinding, B4SOIqjdNode, B4SOIqjdNode);
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
                BFOO(B4SOITemptempPtr, B4SOITemptempBinding, B4SOItempNode, B4SOItempNode);
                BFOO(B4SOITempdpPtr, B4SOITempdpBinding, B4SOItempNode, B4SOIdNodePrime);
                BFOO(B4SOITempspPtr, B4SOITempspBinding, B4SOItempNode, B4SOIsNodePrime);
                BFOO(B4SOITempgPtr, B4SOITempgBinding, B4SOItempNode, B4SOIgNode);
                BFOO(B4SOITempbPtr, B4SOITempbBinding, B4SOItempNode, B4SOIbNode);
                BFOO(B4SOIGtempPtr, B4SOIGtempBinding, B4SOIgNode, B4SOItempNode);
                BFOO(B4SOIDPtempPtr, B4SOIDPtempBinding, B4SOIdNodePrime, B4SOItempNode);
                BFOO(B4SOISPtempPtr, B4SOISPtempBinding, B4SOIsNodePrime, B4SOItempNode);
                BFOO(B4SOIEtempPtr, B4SOIEtempBinding, B4SOIeNode, B4SOItempNode);
                BFOO(B4SOIBtempPtr, B4SOIBtempBinding, B4SOIbNode, B4SOItempNode);
                if (here->B4SOIbodyMod == 1)
                {
                    BFOO(B4SOIPtempPtr, B4SOIPtempBinding, B4SOIpNode, B4SOItempNode);
                }
                if (here->B4SOIsoiMod != 0)
                {
                    BFOO(B4SOITempePtr, B4SOITempeBinding, B4SOItempNode, B4SOIeNode);
                }
            }
            if (here->B4SOIbodyMod == 2)
            {
            }
            else if (here->B4SOIbodyMod == 1)
            {
                BFOO(B4SOIBpPtr, B4SOIBpBinding, B4SOIbNode, B4SOIpNode);
                BFOO(B4SOIPbPtr, B4SOIPbBinding, B4SOIpNode, B4SOIbNode);
                BFOO(B4SOIPpPtr, B4SOIPpBinding, B4SOIpNode, B4SOIpNode);
                BFOO(B4SOIPgPtr, B4SOIPgBinding, B4SOIpNode, B4SOIgNode);
                BFOO(B4SOIGpPtr, B4SOIGpBinding, B4SOIgNode, B4SOIpNode);
            }
            if (here->B4SOIrgateMod != 0)
            {
                BFOO(B4SOIGEgePtr, B4SOIGEgeBinding, B4SOIgNodeExt, B4SOIgNodeExt);
                BFOO(B4SOIGEgPtr, B4SOIGEgBinding, B4SOIgNodeExt, B4SOIgNode);
                BFOO(B4SOIGgePtr, B4SOIGgeBinding, B4SOIgNode, B4SOIgNodeExt);
                BFOO(B4SOIGEdpPtr, B4SOIGEdpBinding, B4SOIgNodeExt, B4SOIdNodePrime);
                BFOO(B4SOIGEspPtr, B4SOIGEspBinding, B4SOIgNodeExt, B4SOIsNodePrime);
                if (here->B4SOIsoiMod != 2)
                {
                    BFOO(B4SOIGEbPtr, B4SOIGEbBinding, B4SOIgNodeExt, B4SOIbNode);
                }
                BFOO(B4SOIGMdpPtr, B4SOIGMdpBinding, B4SOIgNodeMid, B4SOIdNodePrime);
                BFOO(B4SOIGMgPtr, B4SOIGMgBinding, B4SOIgNodeMid, B4SOIgNode);
                BFOO(B4SOIGMgmPtr, B4SOIGMgmBinding, B4SOIgNodeMid, B4SOIgNodeMid);
                BFOO(B4SOIGMgePtr, B4SOIGMgeBinding, B4SOIgNodeMid, B4SOIgNodeExt);
                BFOO(B4SOIGMspPtr, B4SOIGMspBinding, B4SOIgNodeMid, B4SOIsNodePrime);
                if (here->B4SOIsoiMod != 2)
                {
                    BFOO(B4SOIGMbPtr, B4SOIGMbBinding, B4SOIgNodeMid, B4SOIbNode);
                }
                BFOO(B4SOIGMePtr, B4SOIGMeBinding, B4SOIgNodeMid, B4SOIeNode);
                BFOO(B4SOIDPgmPtr, B4SOIDPgmBinding, B4SOIdNodePrime, B4SOIgNodeMid);
                BFOO(B4SOIGgmPtr, B4SOIGgmBinding, B4SOIgNode, B4SOIgNodeMid);
                BFOO(B4SOIGEgmPtr, B4SOIGEgmBinding, B4SOIgNodeExt, B4SOIgNodeMid);
                BFOO(B4SOISPgmPtr, B4SOISPgmBinding, B4SOIsNodePrime, B4SOIgNodeMid);
                BFOO(B4SOIEgmPtr, B4SOIEgmBinding, B4SOIeNode, B4SOIgNodeMid);
            }
            if (here->B4SOIsoiMod != 2) /* v3.2 */
            {
                BFOO(B4SOIEbPtr, B4SOIEbBinding, B4SOIeNode, B4SOIbNode);
                BFOO(B4SOIGbPtr, B4SOIGbBinding, B4SOIgNode, B4SOIbNode);
                BFOO(B4SOIDPbPtr, B4SOIDPbBinding, B4SOIdNodePrime, B4SOIbNode);
                BFOO(B4SOISPbPtr, B4SOISPbBinding, B4SOIsNodePrime, B4SOIbNode);
                BFOO(B4SOIBePtr, B4SOIBeBinding, B4SOIbNode, B4SOIeNode);
                BFOO(B4SOIBgPtr, B4SOIBgBinding, B4SOIbNode, B4SOIgNode);
                BFOO(B4SOIBdpPtr, B4SOIBdpBinding, B4SOIbNode, B4SOIdNodePrime);
                BFOO(B4SOIBspPtr, B4SOIBspBinding, B4SOIbNode, B4SOIsNodePrime);
                BFOO(B4SOIBbPtr, B4SOIBbBinding, B4SOIbNode, B4SOIbNode);
            }
            BFOO(B4SOIEgPtr, B4SOIEgBinding, B4SOIeNode, B4SOIgNode);
            BFOO(B4SOIEdpPtr, B4SOIEdpBinding, B4SOIeNode, B4SOIdNodePrime);
            BFOO(B4SOIEspPtr, B4SOIEspBinding, B4SOIeNode, B4SOIsNodePrime);
            BFOO(B4SOIGePtr, B4SOIGeBinding, B4SOIgNode, B4SOIeNode);
            BFOO(B4SOIDPePtr, B4SOIDPeBinding, B4SOIdNodePrime, B4SOIeNode);
            BFOO(B4SOISPePtr, B4SOISPeBinding, B4SOIsNodePrime, B4SOIeNode);
            BFOO(B4SOIEePtr, B4SOIEeBinding, B4SOIeNode, B4SOIeNode);
            BFOO(B4SOIGgPtr, B4SOIGgBinding, B4SOIgNode, B4SOIgNode);
            BFOO(B4SOIGdpPtr, B4SOIGdpBinding, B4SOIgNode, B4SOIdNodePrime);
            BFOO(B4SOIGspPtr, B4SOIGspBinding, B4SOIgNode, B4SOIsNodePrime);
            BFOO(B4SOIDPgPtr, B4SOIDPgBinding, B4SOIdNodePrime, B4SOIgNode);
            BFOO(B4SOIDPdpPtr, B4SOIDPdpBinding, B4SOIdNodePrime, B4SOIdNodePrime);
            BFOO(B4SOIDPspPtr, B4SOIDPspBinding, B4SOIdNodePrime, B4SOIsNodePrime);
            BFOO(B4SOIDPdPtr, B4SOIDPdBinding, B4SOIdNodePrime, B4SOIdNode);
            BFOO(B4SOISPgPtr, B4SOISPgBinding, B4SOIsNodePrime, B4SOIgNode);
            BFOO(B4SOISPdpPtr, B4SOISPdpBinding, B4SOIsNodePrime, B4SOIdNodePrime);
            BFOO(B4SOISPspPtr, B4SOISPspBinding, B4SOIsNodePrime, B4SOIsNodePrime);
            BFOO(B4SOISPsPtr, B4SOISPsBinding, B4SOIsNodePrime, B4SOIsNode);
            BFOO(B4SOIDdPtr, B4SOIDdBinding, B4SOIdNode, B4SOIdNode);
            BFOO(B4SOIDdpPtr, B4SOIDdpBinding, B4SOIdNode, B4SOIdNodePrime);
            BFOO(B4SOISsPtr, B4SOISsBinding, B4SOIsNode, B4SOIsNode);
            BFOO(B4SOISspPtr, B4SOISspBinding, B4SOIsNode, B4SOIsNodePrime);
            if (here->B4SOIrbodyMod == 1)
            {
                BFOO(B4SOIDPdbPtr, B4SOIDPdbBinding, B4SOIdNodePrime, B4SOIdbNode);
                BFOO(B4SOISPsbPtr, B4SOISPsbBinding, B4SOIsNodePrime, B4SOIsbNode);
                BFOO(B4SOIDBdpPtr, B4SOIDBdpBinding, B4SOIdbNode, B4SOIdNodePrime);
                BFOO(B4SOIDBdbPtr, B4SOIDBdbBinding, B4SOIdbNode, B4SOIdbNode);
                BFOO(B4SOIDBbPtr, B4SOIDBbBinding, B4SOIdbNode, B4SOIbNode);
                BFOO(B4SOISBspPtr, B4SOISBspBinding, B4SOIsbNode, B4SOIsNodePrime);
                BFOO(B4SOISBsbPtr, B4SOISBsbBinding, B4SOIsbNode, B4SOIsbNode);
                BFOO(B4SOISBbPtr, B4SOISBbBinding, B4SOIsbNode, B4SOIbNode);
                BFOO(B4SOIBdbPtr, B4SOIBdbBinding, B4SOIbNode, B4SOIdbNode);
                BFOO(B4SOIBsbPtr, B4SOIBsbBinding, B4SOIbNode, B4SOIsbNode);
            }
            if (model->B4SOIrdsMod)
            {
                BFOO(B4SOIDgPtr, B4SOIDgBinding, B4SOIdNode, B4SOIgNode);
                BFOO(B4SOIDspPtr, B4SOIDspBinding, B4SOIdNode, B4SOIsNodePrime);
                BFOO(B4SOISdpPtr, B4SOISdpBinding, B4SOIsNode, B4SOIdNodePrime);
                BFOO(B4SOISgPtr, B4SOISgBinding, B4SOIsNode, B4SOIgNode);
                if (model->B4SOIsoiMod != 2)
                {
                    BFOO(B4SOIDbPtr, B4SOIDbBinding, B4SOIdNode, B4SOIbNode);
                    BFOO(B4SOISbPtr, B4SOISbBinding, B4SOIsNode, B4SOIbNode);
                }
            }
            if (here->B4SOIdebugMod != 0)
            {
                BFOO(B4SOIVbsPtr, B4SOIVbsBinding, B4SOIvbsNode, B4SOIvbsNode);
                BFOO(B4SOIIdsPtr, B4SOIIdsBinding, B4SOIidsNode, B4SOIidsNode);
                BFOO(B4SOIIcPtr, B4SOIIcBinding, B4SOIicNode, B4SOIicNode);
                BFOO(B4SOIIbsPtr, B4SOIIbsBinding, B4SOIibsNode, B4SOIibsNode);
                BFOO(B4SOIIbdPtr, B4SOIIbdBinding, B4SOIibdNode, B4SOIibdNode);
                BFOO(B4SOIIiiPtr, B4SOIIiiBinding, B4SOIiiiNode, B4SOIiiiNode);
                BFOO(B4SOIIgPtr, B4SOIIgBinding, B4SOIigNode, B4SOIigNode);
                BFOO(B4SOIGiggPtr, B4SOIGiggBinding, B4SOIgiggNode, B4SOIgiggNode);
                BFOO(B4SOIGigdPtr, B4SOIGigdBinding, B4SOIgigdNode, B4SOIgigdNode);
                BFOO(B4SOIGigbPtr, B4SOIGigbBinding, B4SOIgigbNode, B4SOIgigbNode);
                BFOO(B4SOIIgidlPtr, B4SOIIgidlBinding, B4SOIigidlNode, B4SOIigidlNode);
                BFOO(B4SOIItunPtr, B4SOIItunBinding, B4SOIitunNode, B4SOIitunNode);
                BFOO(B4SOIIbpPtr, B4SOIIbpBinding, B4SOIibpNode, B4SOIibpNode);
                BFOO(B4SOICbbPtr, B4SOICbbBinding, B4SOIcbbNode, B4SOIcbbNode);
                BFOO(B4SOICbdPtr, B4SOICbdBinding, B4SOIcbdNode, B4SOIcbdNode);
                BFOO(B4SOICbgPtr, B4SOICbgBinding, B4SOIcbgNode, B4SOIcbgNode);
                BFOO(B4SOIQbfPtr, B4SOIQbfBinding, B4SOIqbfNode, B4SOIqbfNode);
                BFOO(B4SOIQjsPtr, B4SOIQjsBinding, B4SOIqjsNode, B4SOIqjsNode);
                BFOO(B4SOIQjdPtr, B4SOIQjdBinding, B4SOIqjdNode, B4SOIqjdNode);
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
                CFOO(B4SOITemptempPtr, B4SOITemptempBinding, B4SOItempNode, B4SOItempNode);
                CFOO(B4SOITempdpPtr, B4SOITempdpBinding, B4SOItempNode, B4SOIdNodePrime);
                CFOO(B4SOITempspPtr, B4SOITempspBinding, B4SOItempNode, B4SOIsNodePrime);
                CFOO(B4SOITempgPtr, B4SOITempgBinding, B4SOItempNode, B4SOIgNode);
                CFOO(B4SOITempbPtr, B4SOITempbBinding, B4SOItempNode, B4SOIbNode);
                CFOO(B4SOIGtempPtr, B4SOIGtempBinding, B4SOIgNode, B4SOItempNode);
                CFOO(B4SOIDPtempPtr, B4SOIDPtempBinding, B4SOIdNodePrime, B4SOItempNode);
                CFOO(B4SOISPtempPtr, B4SOISPtempBinding, B4SOIsNodePrime, B4SOItempNode);
                CFOO(B4SOIEtempPtr, B4SOIEtempBinding, B4SOIeNode, B4SOItempNode);
                CFOO(B4SOIBtempPtr, B4SOIBtempBinding, B4SOIbNode, B4SOItempNode);
                if (here->B4SOIbodyMod == 1)
                {
                    CFOO(B4SOIPtempPtr, B4SOIPtempBinding, B4SOIpNode, B4SOItempNode);
                }
                if (here->B4SOIsoiMod != 0)
                {
                    CFOO(B4SOITempePtr, B4SOITempeBinding, B4SOItempNode, B4SOIeNode);
                }
            }
            if (here->B4SOIbodyMod == 2)
            {
            }
            else if (here->B4SOIbodyMod == 1)
            {
                CFOO(B4SOIBpPtr, B4SOIBpBinding, B4SOIbNode, B4SOIpNode);
                CFOO(B4SOIPbPtr, B4SOIPbBinding, B4SOIpNode, B4SOIbNode);
                CFOO(B4SOIPpPtr, B4SOIPpBinding, B4SOIpNode, B4SOIpNode);
                CFOO(B4SOIPgPtr, B4SOIPgBinding, B4SOIpNode, B4SOIgNode);
                CFOO(B4SOIGpPtr, B4SOIGpBinding, B4SOIgNode, B4SOIpNode);
            }
            if (here->B4SOIrgateMod != 0)
            {
                CFOO(B4SOIGEgePtr, B4SOIGEgeBinding, B4SOIgNodeExt, B4SOIgNodeExt);
                CFOO(B4SOIGEgPtr, B4SOIGEgBinding, B4SOIgNodeExt, B4SOIgNode);
                CFOO(B4SOIGgePtr, B4SOIGgeBinding, B4SOIgNode, B4SOIgNodeExt);
                CFOO(B4SOIGEdpPtr, B4SOIGEdpBinding, B4SOIgNodeExt, B4SOIdNodePrime);
                CFOO(B4SOIGEspPtr, B4SOIGEspBinding, B4SOIgNodeExt, B4SOIsNodePrime);
                if (here->B4SOIsoiMod != 2)
                {
                    CFOO(B4SOIGEbPtr, B4SOIGEbBinding, B4SOIgNodeExt, B4SOIbNode);
                }
                CFOO(B4SOIGMdpPtr, B4SOIGMdpBinding, B4SOIgNodeMid, B4SOIdNodePrime);
                CFOO(B4SOIGMgPtr, B4SOIGMgBinding, B4SOIgNodeMid, B4SOIgNode);
                CFOO(B4SOIGMgmPtr, B4SOIGMgmBinding, B4SOIgNodeMid, B4SOIgNodeMid);
                CFOO(B4SOIGMgePtr, B4SOIGMgeBinding, B4SOIgNodeMid, B4SOIgNodeExt);
                CFOO(B4SOIGMspPtr, B4SOIGMspBinding, B4SOIgNodeMid, B4SOIsNodePrime);
                if (here->B4SOIsoiMod != 2)
                {
                    CFOO(B4SOIGMbPtr, B4SOIGMbBinding, B4SOIgNodeMid, B4SOIbNode);
                }
                CFOO(B4SOIGMePtr, B4SOIGMeBinding, B4SOIgNodeMid, B4SOIeNode);
                CFOO(B4SOIDPgmPtr, B4SOIDPgmBinding, B4SOIdNodePrime, B4SOIgNodeMid);
                CFOO(B4SOIGgmPtr, B4SOIGgmBinding, B4SOIgNode, B4SOIgNodeMid);
                CFOO(B4SOIGEgmPtr, B4SOIGEgmBinding, B4SOIgNodeExt, B4SOIgNodeMid);
                CFOO(B4SOISPgmPtr, B4SOISPgmBinding, B4SOIsNodePrime, B4SOIgNodeMid);
                CFOO(B4SOIEgmPtr, B4SOIEgmBinding, B4SOIeNode, B4SOIgNodeMid);
            }
            if (here->B4SOIsoiMod != 2) /* v3.2 */
            {
                CFOO(B4SOIEbPtr, B4SOIEbBinding, B4SOIeNode, B4SOIbNode);
                CFOO(B4SOIGbPtr, B4SOIGbBinding, B4SOIgNode, B4SOIbNode);
                CFOO(B4SOIDPbPtr, B4SOIDPbBinding, B4SOIdNodePrime, B4SOIbNode);
                CFOO(B4SOISPbPtr, B4SOISPbBinding, B4SOIsNodePrime, B4SOIbNode);
                CFOO(B4SOIBePtr, B4SOIBeBinding, B4SOIbNode, B4SOIeNode);
                CFOO(B4SOIBgPtr, B4SOIBgBinding, B4SOIbNode, B4SOIgNode);
                CFOO(B4SOIBdpPtr, B4SOIBdpBinding, B4SOIbNode, B4SOIdNodePrime);
                CFOO(B4SOIBspPtr, B4SOIBspBinding, B4SOIbNode, B4SOIsNodePrime);
                CFOO(B4SOIBbPtr, B4SOIBbBinding, B4SOIbNode, B4SOIbNode);
            }
            CFOO(B4SOIEgPtr, B4SOIEgBinding, B4SOIeNode, B4SOIgNode);
            CFOO(B4SOIEdpPtr, B4SOIEdpBinding, B4SOIeNode, B4SOIdNodePrime);
            CFOO(B4SOIEspPtr, B4SOIEspBinding, B4SOIeNode, B4SOIsNodePrime);
            CFOO(B4SOIGePtr, B4SOIGeBinding, B4SOIgNode, B4SOIeNode);
            CFOO(B4SOIDPePtr, B4SOIDPeBinding, B4SOIdNodePrime, B4SOIeNode);
            CFOO(B4SOISPePtr, B4SOISPeBinding, B4SOIsNodePrime, B4SOIeNode);
            CFOO(B4SOIEePtr, B4SOIEeBinding, B4SOIeNode, B4SOIeNode);
            CFOO(B4SOIGgPtr, B4SOIGgBinding, B4SOIgNode, B4SOIgNode);
            CFOO(B4SOIGdpPtr, B4SOIGdpBinding, B4SOIgNode, B4SOIdNodePrime);
            CFOO(B4SOIGspPtr, B4SOIGspBinding, B4SOIgNode, B4SOIsNodePrime);
            CFOO(B4SOIDPgPtr, B4SOIDPgBinding, B4SOIdNodePrime, B4SOIgNode);
            CFOO(B4SOIDPdpPtr, B4SOIDPdpBinding, B4SOIdNodePrime, B4SOIdNodePrime);
            CFOO(B4SOIDPspPtr, B4SOIDPspBinding, B4SOIdNodePrime, B4SOIsNodePrime);
            CFOO(B4SOIDPdPtr, B4SOIDPdBinding, B4SOIdNodePrime, B4SOIdNode);
            CFOO(B4SOISPgPtr, B4SOISPgBinding, B4SOIsNodePrime, B4SOIgNode);
            CFOO(B4SOISPdpPtr, B4SOISPdpBinding, B4SOIsNodePrime, B4SOIdNodePrime);
            CFOO(B4SOISPspPtr, B4SOISPspBinding, B4SOIsNodePrime, B4SOIsNodePrime);
            CFOO(B4SOISPsPtr, B4SOISPsBinding, B4SOIsNodePrime, B4SOIsNode);
            CFOO(B4SOIDdPtr, B4SOIDdBinding, B4SOIdNode, B4SOIdNode);
            CFOO(B4SOIDdpPtr, B4SOIDdpBinding, B4SOIdNode, B4SOIdNodePrime);
            CFOO(B4SOISsPtr, B4SOISsBinding, B4SOIsNode, B4SOIsNode);
            CFOO(B4SOISspPtr, B4SOISspBinding, B4SOIsNode, B4SOIsNodePrime);
            if (here->B4SOIrbodyMod == 1)
            {
                CFOO(B4SOIDPdbPtr, B4SOIDPdbBinding, B4SOIdNodePrime, B4SOIdbNode);
                CFOO(B4SOISPsbPtr, B4SOISPsbBinding, B4SOIsNodePrime, B4SOIsbNode);
                CFOO(B4SOIDBdpPtr, B4SOIDBdpBinding, B4SOIdbNode, B4SOIdNodePrime);
                CFOO(B4SOIDBdbPtr, B4SOIDBdbBinding, B4SOIdbNode, B4SOIdbNode);
                CFOO(B4SOIDBbPtr, B4SOIDBbBinding, B4SOIdbNode, B4SOIbNode);
                CFOO(B4SOISBspPtr, B4SOISBspBinding, B4SOIsbNode, B4SOIsNodePrime);
                CFOO(B4SOISBsbPtr, B4SOISBsbBinding, B4SOIsbNode, B4SOIsbNode);
                CFOO(B4SOISBbPtr, B4SOISBbBinding, B4SOIsbNode, B4SOIbNode);
                CFOO(B4SOIBdbPtr, B4SOIBdbBinding, B4SOIbNode, B4SOIdbNode);
                CFOO(B4SOIBsbPtr, B4SOIBsbBinding, B4SOIbNode, B4SOIsbNode);
            }
            if (model->B4SOIrdsMod)
            {
                CFOO(B4SOIDgPtr, B4SOIDgBinding, B4SOIdNode, B4SOIgNode);
                CFOO(B4SOIDspPtr, B4SOIDspBinding, B4SOIdNode, B4SOIsNodePrime);
                CFOO(B4SOISdpPtr, B4SOISdpBinding, B4SOIsNode, B4SOIdNodePrime);
                CFOO(B4SOISgPtr, B4SOISgBinding, B4SOIsNode, B4SOIgNode);
                if (model->B4SOIsoiMod != 2)
                {
                    CFOO(B4SOIDbPtr, B4SOIDbBinding, B4SOIdNode, B4SOIbNode);
                    CFOO(B4SOISbPtr, B4SOISbBinding, B4SOIsNode, B4SOIbNode);
                }
            }
            if (here->B4SOIdebugMod != 0)
            {
                CFOO(B4SOIVbsPtr, B4SOIVbsBinding, B4SOIvbsNode, B4SOIvbsNode);
                CFOO(B4SOIIdsPtr, B4SOIIdsBinding, B4SOIidsNode, B4SOIidsNode);
                CFOO(B4SOIIcPtr, B4SOIIcBinding, B4SOIicNode, B4SOIicNode);
                CFOO(B4SOIIbsPtr, B4SOIIbsBinding, B4SOIibsNode, B4SOIibsNode);
                CFOO(B4SOIIbdPtr, B4SOIIbdBinding, B4SOIibdNode, B4SOIibdNode);
                CFOO(B4SOIIiiPtr, B4SOIIiiBinding, B4SOIiiiNode, B4SOIiiiNode);
                CFOO(B4SOIIgPtr, B4SOIIgBinding, B4SOIigNode, B4SOIigNode);
                CFOO(B4SOIGiggPtr, B4SOIGiggBinding, B4SOIgiggNode, B4SOIgiggNode);
                CFOO(B4SOIGigdPtr, B4SOIGigdBinding, B4SOIgigdNode, B4SOIgigdNode);
                CFOO(B4SOIGigbPtr, B4SOIGigbBinding, B4SOIgigbNode, B4SOIgigbNode);
                CFOO(B4SOIIgidlPtr, B4SOIIgidlBinding, B4SOIigidlNode, B4SOIigidlNode);
                CFOO(B4SOIItunPtr, B4SOIItunBinding, B4SOIitunNode, B4SOIitunNode);
                CFOO(B4SOIIbpPtr, B4SOIIbpBinding, B4SOIibpNode, B4SOIibpNode);
                CFOO(B4SOICbbPtr, B4SOICbbBinding, B4SOIcbbNode, B4SOIcbbNode);
                CFOO(B4SOICbdPtr, B4SOICbdBinding, B4SOIcbdNode, B4SOIcbdNode);
                CFOO(B4SOICbgPtr, B4SOICbgBinding, B4SOIcbgNode, B4SOIcbgNode);
                CFOO(B4SOIQbfPtr, B4SOIQbfBinding, B4SOIqbfNode, B4SOIqbfNode);
                CFOO(B4SOIQjsPtr, B4SOIQjsBinding, B4SOIqjsNode, B4SOIqjsNode);
                CFOO(B4SOIQjdPtr, B4SOIQjdBinding, B4SOIqjdNode, B4SOIqjdNode);
            }
        }
    }

    return (OK) ;
}
