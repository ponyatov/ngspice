/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b3soidddef.h"
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
                XFOO(B3SOIDDTemptempPtr, B3SOIDDTemptempBinding, B3SOIDDtempNode, B3SOIDDtempNode);
                XFOO(B3SOIDDTempdpPtr, B3SOIDDTempdpBinding, B3SOIDDtempNode, B3SOIDDdNodePrime);
                XFOO(B3SOIDDTempspPtr, B3SOIDDTempspBinding, B3SOIDDtempNode, B3SOIDDsNodePrime);
                XFOO(B3SOIDDTempgPtr, B3SOIDDTempgBinding, B3SOIDDtempNode, B3SOIDDgNode);
                XFOO(B3SOIDDTempbPtr, B3SOIDDTempbBinding, B3SOIDDtempNode, B3SOIDDbNode);
                XFOO(B3SOIDDTempePtr, B3SOIDDTempeBinding, B3SOIDDtempNode, B3SOIDDeNode);
                XFOO(B3SOIDDGtempPtr, B3SOIDDGtempBinding, B3SOIDDgNode, B3SOIDDtempNode);
                XFOO(B3SOIDDDPtempPtr, B3SOIDDDPtempBinding, B3SOIDDdNodePrime, B3SOIDDtempNode);
                XFOO(B3SOIDDSPtempPtr, B3SOIDDSPtempBinding, B3SOIDDsNodePrime, B3SOIDDtempNode);
                XFOO(B3SOIDDEtempPtr, B3SOIDDEtempBinding, B3SOIDDeNode, B3SOIDDtempNode);
                XFOO(B3SOIDDBtempPtr, B3SOIDDBtempBinding, B3SOIDDbNode, B3SOIDDtempNode);
                if (here->B3SOIDDbodyMod == 1)
                {
                    XFOO(B3SOIDDPtempPtr, B3SOIDDPtempBinding, B3SOIDDpNode, B3SOIDDtempNode);
                }
            }
            if (here->B3SOIDDbodyMod == 2)
            {
            }
            else if (here->B3SOIDDbodyMod == 1)
            {
                XFOO(B3SOIDDBpPtr, B3SOIDDBpBinding, B3SOIDDbNode, B3SOIDDpNode);
                XFOO(B3SOIDDPbPtr, B3SOIDDPbBinding, B3SOIDDpNode, B3SOIDDbNode);
                XFOO(B3SOIDDPpPtr, B3SOIDDPpBinding, B3SOIDDpNode, B3SOIDDpNode);
                XFOO(B3SOIDDPgPtr, B3SOIDDPgBinding, B3SOIDDpNode, B3SOIDDgNode);
                XFOO(B3SOIDDPdpPtr, B3SOIDDPdpBinding, B3SOIDDpNode, B3SOIDDdNodePrime);
                XFOO(B3SOIDDPspPtr, B3SOIDDPspBinding, B3SOIDDpNode, B3SOIDDsNodePrime);
                XFOO(B3SOIDDPePtr, B3SOIDDPeBinding, B3SOIDDpNode, B3SOIDDeNode);
            }
            XFOO(B3SOIDDEgPtr, B3SOIDDEgBinding, B3SOIDDeNode, B3SOIDDgNode);
            XFOO(B3SOIDDEdpPtr, B3SOIDDEdpBinding, B3SOIDDeNode, B3SOIDDdNodePrime);
            XFOO(B3SOIDDEspPtr, B3SOIDDEspBinding, B3SOIDDeNode, B3SOIDDsNodePrime);
            XFOO(B3SOIDDGePtr, B3SOIDDGeBinding, B3SOIDDgNode, B3SOIDDeNode);
            XFOO(B3SOIDDDPePtr, B3SOIDDDPeBinding, B3SOIDDdNodePrime, B3SOIDDeNode);
            XFOO(B3SOIDDSPePtr, B3SOIDDSPeBinding, B3SOIDDsNodePrime, B3SOIDDeNode);
            XFOO(B3SOIDDEbPtr, B3SOIDDEbBinding, B3SOIDDeNode, B3SOIDDbNode);
            XFOO(B3SOIDDGbPtr, B3SOIDDGbBinding, B3SOIDDgNode, B3SOIDDbNode);
            XFOO(B3SOIDDDPbPtr, B3SOIDDDPbBinding, B3SOIDDdNodePrime, B3SOIDDbNode);
            XFOO(B3SOIDDSPbPtr, B3SOIDDSPbBinding, B3SOIDDsNodePrime, B3SOIDDbNode);
            XFOO(B3SOIDDBePtr, B3SOIDDBeBinding, B3SOIDDbNode, B3SOIDDeNode);
            XFOO(B3SOIDDBgPtr, B3SOIDDBgBinding, B3SOIDDbNode, B3SOIDDgNode);
            XFOO(B3SOIDDBdpPtr, B3SOIDDBdpBinding, B3SOIDDbNode, B3SOIDDdNodePrime);
            XFOO(B3SOIDDBspPtr, B3SOIDDBspBinding, B3SOIDDbNode, B3SOIDDsNodePrime);
            XFOO(B3SOIDDBbPtr, B3SOIDDBbBinding, B3SOIDDbNode, B3SOIDDbNode);
            XFOO(B3SOIDDEePtr, B3SOIDDEeBinding, B3SOIDDeNode, B3SOIDDeNode);
            XFOO(B3SOIDDGgPtr, B3SOIDDGgBinding, B3SOIDDgNode, B3SOIDDgNode);
            XFOO(B3SOIDDGdpPtr, B3SOIDDGdpBinding, B3SOIDDgNode, B3SOIDDdNodePrime);
            XFOO(B3SOIDDGspPtr, B3SOIDDGspBinding, B3SOIDDgNode, B3SOIDDsNodePrime);
            XFOO(B3SOIDDDPgPtr, B3SOIDDDPgBinding, B3SOIDDdNodePrime, B3SOIDDgNode);
            XFOO(B3SOIDDDPdpPtr, B3SOIDDDPdpBinding, B3SOIDDdNodePrime, B3SOIDDdNodePrime);
            XFOO(B3SOIDDDPspPtr, B3SOIDDDPspBinding, B3SOIDDdNodePrime, B3SOIDDsNodePrime);
            XFOO(B3SOIDDDPdPtr, B3SOIDDDPdBinding, B3SOIDDdNodePrime, B3SOIDDdNode);
            XFOO(B3SOIDDSPgPtr, B3SOIDDSPgBinding, B3SOIDDsNodePrime, B3SOIDDgNode);
            XFOO(B3SOIDDSPdpPtr, B3SOIDDSPdpBinding, B3SOIDDsNodePrime, B3SOIDDdNodePrime);
            XFOO(B3SOIDDSPspPtr, B3SOIDDSPspBinding, B3SOIDDsNodePrime, B3SOIDDsNodePrime);
            XFOO(B3SOIDDSPsPtr, B3SOIDDSPsBinding, B3SOIDDsNodePrime, B3SOIDDsNode);
            XFOO(B3SOIDDDdPtr, B3SOIDDDdBinding, B3SOIDDdNode, B3SOIDDdNode);
            XFOO(B3SOIDDDdpPtr, B3SOIDDDdpBinding, B3SOIDDdNode, B3SOIDDdNodePrime);
            XFOO(B3SOIDDSsPtr, B3SOIDDSsBinding, B3SOIDDsNode, B3SOIDDsNode);
            XFOO(B3SOIDDSspPtr, B3SOIDDSspBinding, B3SOIDDsNode, B3SOIDDsNodePrime);
            if ((here->B3SOIDDdebugMod > 1) || (here->B3SOIDDdebugMod == -1))
            {
                XFOO(B3SOIDDVbsPtr, B3SOIDDVbsBinding, B3SOIDDvbsNode, B3SOIDDvbsNode);
                XFOO(B3SOIDDIdsPtr, B3SOIDDIdsBinding, B3SOIDDidsNode, B3SOIDDidsNode);
                XFOO(B3SOIDDIcPtr, B3SOIDDIcBinding, B3SOIDDicNode, B3SOIDDicNode);
                XFOO(B3SOIDDIbsPtr, B3SOIDDIbsBinding, B3SOIDDibsNode, B3SOIDDibsNode);
                XFOO(B3SOIDDIbdPtr, B3SOIDDIbdBinding, B3SOIDDibdNode, B3SOIDDibdNode);
                XFOO(B3SOIDDIiiPtr, B3SOIDDIiiBinding, B3SOIDDiiiNode, B3SOIDDiiiNode);
                XFOO(B3SOIDDIgidlPtr, B3SOIDDIgidlBinding, B3SOIDDigidlNode, B3SOIDDigidlNode);
                XFOO(B3SOIDDItunPtr, B3SOIDDItunBinding, B3SOIDDitunNode, B3SOIDDitunNode);
                XFOO(B3SOIDDIbpPtr, B3SOIDDIbpBinding, B3SOIDDibpNode, B3SOIDDibpNode);
                XFOO(B3SOIDDAbeffPtr, B3SOIDDAbeffBinding, B3SOIDDabeffNode, B3SOIDDabeffNode);
                XFOO(B3SOIDDVbs0effPtr, B3SOIDDVbs0effBinding, B3SOIDDvbs0effNode, B3SOIDDvbs0effNode);
                XFOO(B3SOIDDVbseffPtr, B3SOIDDVbseffBinding, B3SOIDDvbseffNode, B3SOIDDvbseffNode);
                XFOO(B3SOIDDXcPtr, B3SOIDDXcBinding, B3SOIDDxcNode, B3SOIDDxcNode);
                XFOO(B3SOIDDCbbPtr, B3SOIDDCbbBinding, B3SOIDDcbbNode, B3SOIDDcbbNode);
                XFOO(B3SOIDDCbdPtr, B3SOIDDCbdBinding, B3SOIDDcbdNode, B3SOIDDcbdNode);
                XFOO(B3SOIDDCbgPtr, B3SOIDDCbgBinding, B3SOIDDcbgNode, B3SOIDDcbgNode);
                XFOO(B3SOIDDqbPtr, B3SOIDDqbBinding, B3SOIDDqbNode, B3SOIDDqbNode);
                XFOO(B3SOIDDQbfPtr, B3SOIDDQbfBinding, B3SOIDDqbfNode, B3SOIDDqbfNode);
                XFOO(B3SOIDDQjsPtr, B3SOIDDQjsBinding, B3SOIDDqjsNode, B3SOIDDqjsNode);
                XFOO(B3SOIDDQjdPtr, B3SOIDDQjdBinding, B3SOIDDqjdNode, B3SOIDDqjdNode);
                XFOO(B3SOIDDGmPtr, B3SOIDDGmBinding, B3SOIDDgmNode, B3SOIDDgmNode);
                XFOO(B3SOIDDGmbsPtr, B3SOIDDGmbsBinding, B3SOIDDgmbsNode, B3SOIDDgmbsNode);
                XFOO(B3SOIDDGdsPtr, B3SOIDDGdsBinding, B3SOIDDgdsNode, B3SOIDDgdsNode);
                XFOO(B3SOIDDGmePtr, B3SOIDDGmeBinding, B3SOIDDgmeNode, B3SOIDDgmeNode);
                XFOO(B3SOIDDVbs0teffPtr, B3SOIDDVbs0teffBinding, B3SOIDDvbs0teffNode, B3SOIDDvbs0teffNode);
                XFOO(B3SOIDDVthPtr, B3SOIDDVthBinding, B3SOIDDvthNode, B3SOIDDvthNode);
                XFOO(B3SOIDDVgsteffPtr, B3SOIDDVgsteffBinding, B3SOIDDvgsteffNode, B3SOIDDvgsteffNode);
                XFOO(B3SOIDDXcsatPtr, B3SOIDDXcsatBinding, B3SOIDDxcsatNode, B3SOIDDxcsatNode);
                XFOO(B3SOIDDVcscvPtr, B3SOIDDVcscvBinding, B3SOIDDvcscvNode, B3SOIDDvcscvNode);
                XFOO(B3SOIDDVdscvPtr, B3SOIDDVdscvBinding, B3SOIDDvdscvNode, B3SOIDDvdscvNode);
                XFOO(B3SOIDDCbePtr, B3SOIDDCbeBinding, B3SOIDDcbeNode, B3SOIDDcbeNode);
                XFOO(B3SOIDDDum1Ptr, B3SOIDDDum1Binding, B3SOIDDdum1Node, B3SOIDDdum1Node);
                XFOO(B3SOIDDDum2Ptr, B3SOIDDDum2Binding, B3SOIDDdum2Node, B3SOIDDdum2Node);
                XFOO(B3SOIDDDum3Ptr, B3SOIDDDum3Binding, B3SOIDDdum3Node, B3SOIDDdum3Node);
                XFOO(B3SOIDDDum4Ptr, B3SOIDDDum4Binding, B3SOIDDdum4Node, B3SOIDDdum4Node);
                XFOO(B3SOIDDDum5Ptr, B3SOIDDDum5Binding, B3SOIDDdum5Node, B3SOIDDdum5Node);
                XFOO(B3SOIDDQaccPtr, B3SOIDDQaccBinding, B3SOIDDqaccNode, B3SOIDDqaccNode);
                XFOO(B3SOIDDQsub0Ptr, B3SOIDDQsub0Binding, B3SOIDDqsub0Node, B3SOIDDqsub0Node);
                XFOO(B3SOIDDQsubs1Ptr, B3SOIDDQsubs1Binding, B3SOIDDqsubs1Node, B3SOIDDqsubs1Node);
                XFOO(B3SOIDDQsubs2Ptr, B3SOIDDQsubs2Binding, B3SOIDDqsubs2Node, B3SOIDDqsubs2Node);
                XFOO(B3SOIDDqePtr, B3SOIDDqeBinding, B3SOIDDqeNode, B3SOIDDqeNode);
                XFOO(B3SOIDDqdPtr, B3SOIDDqdBinding, B3SOIDDqdNode, B3SOIDDqdNode);
                XFOO(B3SOIDDqgPtr, B3SOIDDqgBinding, B3SOIDDqgNode, B3SOIDDqgNode);
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
                BFOO(B3SOIDDTemptempPtr, B3SOIDDTemptempBinding, B3SOIDDtempNode, B3SOIDDtempNode);
                BFOO(B3SOIDDTempdpPtr, B3SOIDDTempdpBinding, B3SOIDDtempNode, B3SOIDDdNodePrime);
                BFOO(B3SOIDDTempspPtr, B3SOIDDTempspBinding, B3SOIDDtempNode, B3SOIDDsNodePrime);
                BFOO(B3SOIDDTempgPtr, B3SOIDDTempgBinding, B3SOIDDtempNode, B3SOIDDgNode);
                BFOO(B3SOIDDTempbPtr, B3SOIDDTempbBinding, B3SOIDDtempNode, B3SOIDDbNode);
                BFOO(B3SOIDDTempePtr, B3SOIDDTempeBinding, B3SOIDDtempNode, B3SOIDDeNode);
                BFOO(B3SOIDDGtempPtr, B3SOIDDGtempBinding, B3SOIDDgNode, B3SOIDDtempNode);
                BFOO(B3SOIDDDPtempPtr, B3SOIDDDPtempBinding, B3SOIDDdNodePrime, B3SOIDDtempNode);
                BFOO(B3SOIDDSPtempPtr, B3SOIDDSPtempBinding, B3SOIDDsNodePrime, B3SOIDDtempNode);
                BFOO(B3SOIDDEtempPtr, B3SOIDDEtempBinding, B3SOIDDeNode, B3SOIDDtempNode);
                BFOO(B3SOIDDBtempPtr, B3SOIDDBtempBinding, B3SOIDDbNode, B3SOIDDtempNode);
                if (here->B3SOIDDbodyMod == 1)
                {
                    BFOO(B3SOIDDPtempPtr, B3SOIDDPtempBinding, B3SOIDDpNode, B3SOIDDtempNode);
                }
            }
            if (here->B3SOIDDbodyMod == 2)
            {
            }
            else if (here->B3SOIDDbodyMod == 1)
            {
                BFOO(B3SOIDDBpPtr, B3SOIDDBpBinding, B3SOIDDbNode, B3SOIDDpNode);
                BFOO(B3SOIDDPbPtr, B3SOIDDPbBinding, B3SOIDDpNode, B3SOIDDbNode);
                BFOO(B3SOIDDPpPtr, B3SOIDDPpBinding, B3SOIDDpNode, B3SOIDDpNode);
                BFOO(B3SOIDDPgPtr, B3SOIDDPgBinding, B3SOIDDpNode, B3SOIDDgNode);
                BFOO(B3SOIDDPdpPtr, B3SOIDDPdpBinding, B3SOIDDpNode, B3SOIDDdNodePrime);
                BFOO(B3SOIDDPspPtr, B3SOIDDPspBinding, B3SOIDDpNode, B3SOIDDsNodePrime);
                BFOO(B3SOIDDPePtr, B3SOIDDPeBinding, B3SOIDDpNode, B3SOIDDeNode);
            }
            BFOO(B3SOIDDEgPtr, B3SOIDDEgBinding, B3SOIDDeNode, B3SOIDDgNode);
            BFOO(B3SOIDDEdpPtr, B3SOIDDEdpBinding, B3SOIDDeNode, B3SOIDDdNodePrime);
            BFOO(B3SOIDDEspPtr, B3SOIDDEspBinding, B3SOIDDeNode, B3SOIDDsNodePrime);
            BFOO(B3SOIDDGePtr, B3SOIDDGeBinding, B3SOIDDgNode, B3SOIDDeNode);
            BFOO(B3SOIDDDPePtr, B3SOIDDDPeBinding, B3SOIDDdNodePrime, B3SOIDDeNode);
            BFOO(B3SOIDDSPePtr, B3SOIDDSPeBinding, B3SOIDDsNodePrime, B3SOIDDeNode);
            BFOO(B3SOIDDEbPtr, B3SOIDDEbBinding, B3SOIDDeNode, B3SOIDDbNode);
            BFOO(B3SOIDDGbPtr, B3SOIDDGbBinding, B3SOIDDgNode, B3SOIDDbNode);
            BFOO(B3SOIDDDPbPtr, B3SOIDDDPbBinding, B3SOIDDdNodePrime, B3SOIDDbNode);
            BFOO(B3SOIDDSPbPtr, B3SOIDDSPbBinding, B3SOIDDsNodePrime, B3SOIDDbNode);
            BFOO(B3SOIDDBePtr, B3SOIDDBeBinding, B3SOIDDbNode, B3SOIDDeNode);
            BFOO(B3SOIDDBgPtr, B3SOIDDBgBinding, B3SOIDDbNode, B3SOIDDgNode);
            BFOO(B3SOIDDBdpPtr, B3SOIDDBdpBinding, B3SOIDDbNode, B3SOIDDdNodePrime);
            BFOO(B3SOIDDBspPtr, B3SOIDDBspBinding, B3SOIDDbNode, B3SOIDDsNodePrime);
            BFOO(B3SOIDDBbPtr, B3SOIDDBbBinding, B3SOIDDbNode, B3SOIDDbNode);
            BFOO(B3SOIDDEePtr, B3SOIDDEeBinding, B3SOIDDeNode, B3SOIDDeNode);
            BFOO(B3SOIDDGgPtr, B3SOIDDGgBinding, B3SOIDDgNode, B3SOIDDgNode);
            BFOO(B3SOIDDGdpPtr, B3SOIDDGdpBinding, B3SOIDDgNode, B3SOIDDdNodePrime);
            BFOO(B3SOIDDGspPtr, B3SOIDDGspBinding, B3SOIDDgNode, B3SOIDDsNodePrime);
            BFOO(B3SOIDDDPgPtr, B3SOIDDDPgBinding, B3SOIDDdNodePrime, B3SOIDDgNode);
            BFOO(B3SOIDDDPdpPtr, B3SOIDDDPdpBinding, B3SOIDDdNodePrime, B3SOIDDdNodePrime);
            BFOO(B3SOIDDDPspPtr, B3SOIDDDPspBinding, B3SOIDDdNodePrime, B3SOIDDsNodePrime);
            BFOO(B3SOIDDDPdPtr, B3SOIDDDPdBinding, B3SOIDDdNodePrime, B3SOIDDdNode);
            BFOO(B3SOIDDSPgPtr, B3SOIDDSPgBinding, B3SOIDDsNodePrime, B3SOIDDgNode);
            BFOO(B3SOIDDSPdpPtr, B3SOIDDSPdpBinding, B3SOIDDsNodePrime, B3SOIDDdNodePrime);
            BFOO(B3SOIDDSPspPtr, B3SOIDDSPspBinding, B3SOIDDsNodePrime, B3SOIDDsNodePrime);
            BFOO(B3SOIDDSPsPtr, B3SOIDDSPsBinding, B3SOIDDsNodePrime, B3SOIDDsNode);
            BFOO(B3SOIDDDdPtr, B3SOIDDDdBinding, B3SOIDDdNode, B3SOIDDdNode);
            BFOO(B3SOIDDDdpPtr, B3SOIDDDdpBinding, B3SOIDDdNode, B3SOIDDdNodePrime);
            BFOO(B3SOIDDSsPtr, B3SOIDDSsBinding, B3SOIDDsNode, B3SOIDDsNode);
            BFOO(B3SOIDDSspPtr, B3SOIDDSspBinding, B3SOIDDsNode, B3SOIDDsNodePrime);
            if ((here->B3SOIDDdebugMod > 1) || (here->B3SOIDDdebugMod == -1))
            {
                BFOO(B3SOIDDVbsPtr, B3SOIDDVbsBinding, B3SOIDDvbsNode, B3SOIDDvbsNode);
                BFOO(B3SOIDDIdsPtr, B3SOIDDIdsBinding, B3SOIDDidsNode, B3SOIDDidsNode);
                BFOO(B3SOIDDIcPtr, B3SOIDDIcBinding, B3SOIDDicNode, B3SOIDDicNode);
                BFOO(B3SOIDDIbsPtr, B3SOIDDIbsBinding, B3SOIDDibsNode, B3SOIDDibsNode);
                BFOO(B3SOIDDIbdPtr, B3SOIDDIbdBinding, B3SOIDDibdNode, B3SOIDDibdNode);
                BFOO(B3SOIDDIiiPtr, B3SOIDDIiiBinding, B3SOIDDiiiNode, B3SOIDDiiiNode);
                BFOO(B3SOIDDIgidlPtr, B3SOIDDIgidlBinding, B3SOIDDigidlNode, B3SOIDDigidlNode);
                BFOO(B3SOIDDItunPtr, B3SOIDDItunBinding, B3SOIDDitunNode, B3SOIDDitunNode);
                BFOO(B3SOIDDIbpPtr, B3SOIDDIbpBinding, B3SOIDDibpNode, B3SOIDDibpNode);
                BFOO(B3SOIDDAbeffPtr, B3SOIDDAbeffBinding, B3SOIDDabeffNode, B3SOIDDabeffNode);
                BFOO(B3SOIDDVbs0effPtr, B3SOIDDVbs0effBinding, B3SOIDDvbs0effNode, B3SOIDDvbs0effNode);
                BFOO(B3SOIDDVbseffPtr, B3SOIDDVbseffBinding, B3SOIDDvbseffNode, B3SOIDDvbseffNode);
                BFOO(B3SOIDDXcPtr, B3SOIDDXcBinding, B3SOIDDxcNode, B3SOIDDxcNode);
                BFOO(B3SOIDDCbbPtr, B3SOIDDCbbBinding, B3SOIDDcbbNode, B3SOIDDcbbNode);
                BFOO(B3SOIDDCbdPtr, B3SOIDDCbdBinding, B3SOIDDcbdNode, B3SOIDDcbdNode);
                BFOO(B3SOIDDCbgPtr, B3SOIDDCbgBinding, B3SOIDDcbgNode, B3SOIDDcbgNode);
                BFOO(B3SOIDDqbPtr, B3SOIDDqbBinding, B3SOIDDqbNode, B3SOIDDqbNode);
                BFOO(B3SOIDDQbfPtr, B3SOIDDQbfBinding, B3SOIDDqbfNode, B3SOIDDqbfNode);
                BFOO(B3SOIDDQjsPtr, B3SOIDDQjsBinding, B3SOIDDqjsNode, B3SOIDDqjsNode);
                BFOO(B3SOIDDQjdPtr, B3SOIDDQjdBinding, B3SOIDDqjdNode, B3SOIDDqjdNode);
                BFOO(B3SOIDDGmPtr, B3SOIDDGmBinding, B3SOIDDgmNode, B3SOIDDgmNode);
                BFOO(B3SOIDDGmbsPtr, B3SOIDDGmbsBinding, B3SOIDDgmbsNode, B3SOIDDgmbsNode);
                BFOO(B3SOIDDGdsPtr, B3SOIDDGdsBinding, B3SOIDDgdsNode, B3SOIDDgdsNode);
                BFOO(B3SOIDDGmePtr, B3SOIDDGmeBinding, B3SOIDDgmeNode, B3SOIDDgmeNode);
                BFOO(B3SOIDDVbs0teffPtr, B3SOIDDVbs0teffBinding, B3SOIDDvbs0teffNode, B3SOIDDvbs0teffNode);
                BFOO(B3SOIDDVthPtr, B3SOIDDVthBinding, B3SOIDDvthNode, B3SOIDDvthNode);
                BFOO(B3SOIDDVgsteffPtr, B3SOIDDVgsteffBinding, B3SOIDDvgsteffNode, B3SOIDDvgsteffNode);
                BFOO(B3SOIDDXcsatPtr, B3SOIDDXcsatBinding, B3SOIDDxcsatNode, B3SOIDDxcsatNode);
                BFOO(B3SOIDDVcscvPtr, B3SOIDDVcscvBinding, B3SOIDDvcscvNode, B3SOIDDvcscvNode);
                BFOO(B3SOIDDVdscvPtr, B3SOIDDVdscvBinding, B3SOIDDvdscvNode, B3SOIDDvdscvNode);
                BFOO(B3SOIDDCbePtr, B3SOIDDCbeBinding, B3SOIDDcbeNode, B3SOIDDcbeNode);
                BFOO(B3SOIDDDum1Ptr, B3SOIDDDum1Binding, B3SOIDDdum1Node, B3SOIDDdum1Node);
                BFOO(B3SOIDDDum2Ptr, B3SOIDDDum2Binding, B3SOIDDdum2Node, B3SOIDDdum2Node);
                BFOO(B3SOIDDDum3Ptr, B3SOIDDDum3Binding, B3SOIDDdum3Node, B3SOIDDdum3Node);
                BFOO(B3SOIDDDum4Ptr, B3SOIDDDum4Binding, B3SOIDDdum4Node, B3SOIDDdum4Node);
                BFOO(B3SOIDDDum5Ptr, B3SOIDDDum5Binding, B3SOIDDdum5Node, B3SOIDDdum5Node);
                BFOO(B3SOIDDQaccPtr, B3SOIDDQaccBinding, B3SOIDDqaccNode, B3SOIDDqaccNode);
                BFOO(B3SOIDDQsub0Ptr, B3SOIDDQsub0Binding, B3SOIDDqsub0Node, B3SOIDDqsub0Node);
                BFOO(B3SOIDDQsubs1Ptr, B3SOIDDQsubs1Binding, B3SOIDDqsubs1Node, B3SOIDDqsubs1Node);
                BFOO(B3SOIDDQsubs2Ptr, B3SOIDDQsubs2Binding, B3SOIDDqsubs2Node, B3SOIDDqsubs2Node);
                BFOO(B3SOIDDqePtr, B3SOIDDqeBinding, B3SOIDDqeNode, B3SOIDDqeNode);
                BFOO(B3SOIDDqdPtr, B3SOIDDqdBinding, B3SOIDDqdNode, B3SOIDDqdNode);
                BFOO(B3SOIDDqgPtr, B3SOIDDqgBinding, B3SOIDDqgNode, B3SOIDDqgNode);
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
                CFOO(B3SOIDDTemptempPtr, B3SOIDDTemptempBinding, B3SOIDDtempNode, B3SOIDDtempNode);
                CFOO(B3SOIDDTempdpPtr, B3SOIDDTempdpBinding, B3SOIDDtempNode, B3SOIDDdNodePrime);
                CFOO(B3SOIDDTempspPtr, B3SOIDDTempspBinding, B3SOIDDtempNode, B3SOIDDsNodePrime);
                CFOO(B3SOIDDTempgPtr, B3SOIDDTempgBinding, B3SOIDDtempNode, B3SOIDDgNode);
                CFOO(B3SOIDDTempbPtr, B3SOIDDTempbBinding, B3SOIDDtempNode, B3SOIDDbNode);
                CFOO(B3SOIDDTempePtr, B3SOIDDTempeBinding, B3SOIDDtempNode, B3SOIDDeNode);
                CFOO(B3SOIDDGtempPtr, B3SOIDDGtempBinding, B3SOIDDgNode, B3SOIDDtempNode);
                CFOO(B3SOIDDDPtempPtr, B3SOIDDDPtempBinding, B3SOIDDdNodePrime, B3SOIDDtempNode);
                CFOO(B3SOIDDSPtempPtr, B3SOIDDSPtempBinding, B3SOIDDsNodePrime, B3SOIDDtempNode);
                CFOO(B3SOIDDEtempPtr, B3SOIDDEtempBinding, B3SOIDDeNode, B3SOIDDtempNode);
                CFOO(B3SOIDDBtempPtr, B3SOIDDBtempBinding, B3SOIDDbNode, B3SOIDDtempNode);
                if (here->B3SOIDDbodyMod == 1)
                {
                    CFOO(B3SOIDDPtempPtr, B3SOIDDPtempBinding, B3SOIDDpNode, B3SOIDDtempNode);
                }
            }
            if (here->B3SOIDDbodyMod == 2)
            {
            }
            else if (here->B3SOIDDbodyMod == 1)
            {
                CFOO(B3SOIDDBpPtr, B3SOIDDBpBinding, B3SOIDDbNode, B3SOIDDpNode);
                CFOO(B3SOIDDPbPtr, B3SOIDDPbBinding, B3SOIDDpNode, B3SOIDDbNode);
                CFOO(B3SOIDDPpPtr, B3SOIDDPpBinding, B3SOIDDpNode, B3SOIDDpNode);
                CFOO(B3SOIDDPgPtr, B3SOIDDPgBinding, B3SOIDDpNode, B3SOIDDgNode);
                CFOO(B3SOIDDPdpPtr, B3SOIDDPdpBinding, B3SOIDDpNode, B3SOIDDdNodePrime);
                CFOO(B3SOIDDPspPtr, B3SOIDDPspBinding, B3SOIDDpNode, B3SOIDDsNodePrime);
                CFOO(B3SOIDDPePtr, B3SOIDDPeBinding, B3SOIDDpNode, B3SOIDDeNode);
            }
            CFOO(B3SOIDDEgPtr, B3SOIDDEgBinding, B3SOIDDeNode, B3SOIDDgNode);
            CFOO(B3SOIDDEdpPtr, B3SOIDDEdpBinding, B3SOIDDeNode, B3SOIDDdNodePrime);
            CFOO(B3SOIDDEspPtr, B3SOIDDEspBinding, B3SOIDDeNode, B3SOIDDsNodePrime);
            CFOO(B3SOIDDGePtr, B3SOIDDGeBinding, B3SOIDDgNode, B3SOIDDeNode);
            CFOO(B3SOIDDDPePtr, B3SOIDDDPeBinding, B3SOIDDdNodePrime, B3SOIDDeNode);
            CFOO(B3SOIDDSPePtr, B3SOIDDSPeBinding, B3SOIDDsNodePrime, B3SOIDDeNode);
            CFOO(B3SOIDDEbPtr, B3SOIDDEbBinding, B3SOIDDeNode, B3SOIDDbNode);
            CFOO(B3SOIDDGbPtr, B3SOIDDGbBinding, B3SOIDDgNode, B3SOIDDbNode);
            CFOO(B3SOIDDDPbPtr, B3SOIDDDPbBinding, B3SOIDDdNodePrime, B3SOIDDbNode);
            CFOO(B3SOIDDSPbPtr, B3SOIDDSPbBinding, B3SOIDDsNodePrime, B3SOIDDbNode);
            CFOO(B3SOIDDBePtr, B3SOIDDBeBinding, B3SOIDDbNode, B3SOIDDeNode);
            CFOO(B3SOIDDBgPtr, B3SOIDDBgBinding, B3SOIDDbNode, B3SOIDDgNode);
            CFOO(B3SOIDDBdpPtr, B3SOIDDBdpBinding, B3SOIDDbNode, B3SOIDDdNodePrime);
            CFOO(B3SOIDDBspPtr, B3SOIDDBspBinding, B3SOIDDbNode, B3SOIDDsNodePrime);
            CFOO(B3SOIDDBbPtr, B3SOIDDBbBinding, B3SOIDDbNode, B3SOIDDbNode);
            CFOO(B3SOIDDEePtr, B3SOIDDEeBinding, B3SOIDDeNode, B3SOIDDeNode);
            CFOO(B3SOIDDGgPtr, B3SOIDDGgBinding, B3SOIDDgNode, B3SOIDDgNode);
            CFOO(B3SOIDDGdpPtr, B3SOIDDGdpBinding, B3SOIDDgNode, B3SOIDDdNodePrime);
            CFOO(B3SOIDDGspPtr, B3SOIDDGspBinding, B3SOIDDgNode, B3SOIDDsNodePrime);
            CFOO(B3SOIDDDPgPtr, B3SOIDDDPgBinding, B3SOIDDdNodePrime, B3SOIDDgNode);
            CFOO(B3SOIDDDPdpPtr, B3SOIDDDPdpBinding, B3SOIDDdNodePrime, B3SOIDDdNodePrime);
            CFOO(B3SOIDDDPspPtr, B3SOIDDDPspBinding, B3SOIDDdNodePrime, B3SOIDDsNodePrime);
            CFOO(B3SOIDDDPdPtr, B3SOIDDDPdBinding, B3SOIDDdNodePrime, B3SOIDDdNode);
            CFOO(B3SOIDDSPgPtr, B3SOIDDSPgBinding, B3SOIDDsNodePrime, B3SOIDDgNode);
            CFOO(B3SOIDDSPdpPtr, B3SOIDDSPdpBinding, B3SOIDDsNodePrime, B3SOIDDdNodePrime);
            CFOO(B3SOIDDSPspPtr, B3SOIDDSPspBinding, B3SOIDDsNodePrime, B3SOIDDsNodePrime);
            CFOO(B3SOIDDSPsPtr, B3SOIDDSPsBinding, B3SOIDDsNodePrime, B3SOIDDsNode);
            CFOO(B3SOIDDDdPtr, B3SOIDDDdBinding, B3SOIDDdNode, B3SOIDDdNode);
            CFOO(B3SOIDDDdpPtr, B3SOIDDDdpBinding, B3SOIDDdNode, B3SOIDDdNodePrime);
            CFOO(B3SOIDDSsPtr, B3SOIDDSsBinding, B3SOIDDsNode, B3SOIDDsNode);
            CFOO(B3SOIDDSspPtr, B3SOIDDSspBinding, B3SOIDDsNode, B3SOIDDsNodePrime);
            if ((here->B3SOIDDdebugMod > 1) || (here->B3SOIDDdebugMod == -1))
            {
                CFOO(B3SOIDDVbsPtr, B3SOIDDVbsBinding, B3SOIDDvbsNode, B3SOIDDvbsNode);
                CFOO(B3SOIDDIdsPtr, B3SOIDDIdsBinding, B3SOIDDidsNode, B3SOIDDidsNode);
                CFOO(B3SOIDDIcPtr, B3SOIDDIcBinding, B3SOIDDicNode, B3SOIDDicNode);
                CFOO(B3SOIDDIbsPtr, B3SOIDDIbsBinding, B3SOIDDibsNode, B3SOIDDibsNode);
                CFOO(B3SOIDDIbdPtr, B3SOIDDIbdBinding, B3SOIDDibdNode, B3SOIDDibdNode);
                CFOO(B3SOIDDIiiPtr, B3SOIDDIiiBinding, B3SOIDDiiiNode, B3SOIDDiiiNode);
                CFOO(B3SOIDDIgidlPtr, B3SOIDDIgidlBinding, B3SOIDDigidlNode, B3SOIDDigidlNode);
                CFOO(B3SOIDDItunPtr, B3SOIDDItunBinding, B3SOIDDitunNode, B3SOIDDitunNode);
                CFOO(B3SOIDDIbpPtr, B3SOIDDIbpBinding, B3SOIDDibpNode, B3SOIDDibpNode);
                CFOO(B3SOIDDAbeffPtr, B3SOIDDAbeffBinding, B3SOIDDabeffNode, B3SOIDDabeffNode);
                CFOO(B3SOIDDVbs0effPtr, B3SOIDDVbs0effBinding, B3SOIDDvbs0effNode, B3SOIDDvbs0effNode);
                CFOO(B3SOIDDVbseffPtr, B3SOIDDVbseffBinding, B3SOIDDvbseffNode, B3SOIDDvbseffNode);
                CFOO(B3SOIDDXcPtr, B3SOIDDXcBinding, B3SOIDDxcNode, B3SOIDDxcNode);
                CFOO(B3SOIDDCbbPtr, B3SOIDDCbbBinding, B3SOIDDcbbNode, B3SOIDDcbbNode);
                CFOO(B3SOIDDCbdPtr, B3SOIDDCbdBinding, B3SOIDDcbdNode, B3SOIDDcbdNode);
                CFOO(B3SOIDDCbgPtr, B3SOIDDCbgBinding, B3SOIDDcbgNode, B3SOIDDcbgNode);
                CFOO(B3SOIDDqbPtr, B3SOIDDqbBinding, B3SOIDDqbNode, B3SOIDDqbNode);
                CFOO(B3SOIDDQbfPtr, B3SOIDDQbfBinding, B3SOIDDqbfNode, B3SOIDDqbfNode);
                CFOO(B3SOIDDQjsPtr, B3SOIDDQjsBinding, B3SOIDDqjsNode, B3SOIDDqjsNode);
                CFOO(B3SOIDDQjdPtr, B3SOIDDQjdBinding, B3SOIDDqjdNode, B3SOIDDqjdNode);
                CFOO(B3SOIDDGmPtr, B3SOIDDGmBinding, B3SOIDDgmNode, B3SOIDDgmNode);
                CFOO(B3SOIDDGmbsPtr, B3SOIDDGmbsBinding, B3SOIDDgmbsNode, B3SOIDDgmbsNode);
                CFOO(B3SOIDDGdsPtr, B3SOIDDGdsBinding, B3SOIDDgdsNode, B3SOIDDgdsNode);
                CFOO(B3SOIDDGmePtr, B3SOIDDGmeBinding, B3SOIDDgmeNode, B3SOIDDgmeNode);
                CFOO(B3SOIDDVbs0teffPtr, B3SOIDDVbs0teffBinding, B3SOIDDvbs0teffNode, B3SOIDDvbs0teffNode);
                CFOO(B3SOIDDVthPtr, B3SOIDDVthBinding, B3SOIDDvthNode, B3SOIDDvthNode);
                CFOO(B3SOIDDVgsteffPtr, B3SOIDDVgsteffBinding, B3SOIDDvgsteffNode, B3SOIDDvgsteffNode);
                CFOO(B3SOIDDXcsatPtr, B3SOIDDXcsatBinding, B3SOIDDxcsatNode, B3SOIDDxcsatNode);
                CFOO(B3SOIDDVcscvPtr, B3SOIDDVcscvBinding, B3SOIDDvcscvNode, B3SOIDDvcscvNode);
                CFOO(B3SOIDDVdscvPtr, B3SOIDDVdscvBinding, B3SOIDDvdscvNode, B3SOIDDvdscvNode);
                CFOO(B3SOIDDCbePtr, B3SOIDDCbeBinding, B3SOIDDcbeNode, B3SOIDDcbeNode);
                CFOO(B3SOIDDDum1Ptr, B3SOIDDDum1Binding, B3SOIDDdum1Node, B3SOIDDdum1Node);
                CFOO(B3SOIDDDum2Ptr, B3SOIDDDum2Binding, B3SOIDDdum2Node, B3SOIDDdum2Node);
                CFOO(B3SOIDDDum3Ptr, B3SOIDDDum3Binding, B3SOIDDdum3Node, B3SOIDDdum3Node);
                CFOO(B3SOIDDDum4Ptr, B3SOIDDDum4Binding, B3SOIDDdum4Node, B3SOIDDdum4Node);
                CFOO(B3SOIDDDum5Ptr, B3SOIDDDum5Binding, B3SOIDDdum5Node, B3SOIDDdum5Node);
                CFOO(B3SOIDDQaccPtr, B3SOIDDQaccBinding, B3SOIDDqaccNode, B3SOIDDqaccNode);
                CFOO(B3SOIDDQsub0Ptr, B3SOIDDQsub0Binding, B3SOIDDqsub0Node, B3SOIDDqsub0Node);
                CFOO(B3SOIDDQsubs1Ptr, B3SOIDDQsubs1Binding, B3SOIDDqsubs1Node, B3SOIDDqsubs1Node);
                CFOO(B3SOIDDQsubs2Ptr, B3SOIDDQsubs2Binding, B3SOIDDqsubs2Node, B3SOIDDqsubs2Node);
                CFOO(B3SOIDDqePtr, B3SOIDDqeBinding, B3SOIDDqeNode, B3SOIDDqeNode);
                CFOO(B3SOIDDqdPtr, B3SOIDDqdBinding, B3SOIDDqdNode, B3SOIDDqdNode);
                CFOO(B3SOIDDqgPtr, B3SOIDDqgBinding, B3SOIDDqgNode, B3SOIDDqgNode);
            }
        }
    }

    return (OK) ;
}
