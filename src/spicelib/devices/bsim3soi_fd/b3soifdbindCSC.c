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
                XFOO(B3SOIFDTemptempPtr, B3SOIFDTemptempBinding, B3SOIFDtempNode, B3SOIFDtempNode);
                XFOO(B3SOIFDTempdpPtr, B3SOIFDTempdpBinding, B3SOIFDtempNode, B3SOIFDdNodePrime);
                XFOO(B3SOIFDTempspPtr, B3SOIFDTempspBinding, B3SOIFDtempNode, B3SOIFDsNodePrime);
                XFOO(B3SOIFDTempgPtr, B3SOIFDTempgBinding, B3SOIFDtempNode, B3SOIFDgNode);
                XFOO(B3SOIFDTempbPtr, B3SOIFDTempbBinding, B3SOIFDtempNode, B3SOIFDbNode);
                XFOO(B3SOIFDTempePtr, B3SOIFDTempeBinding, B3SOIFDtempNode, B3SOIFDeNode);
                XFOO(B3SOIFDGtempPtr, B3SOIFDGtempBinding, B3SOIFDgNode, B3SOIFDtempNode);
                XFOO(B3SOIFDDPtempPtr, B3SOIFDDPtempBinding, B3SOIFDdNodePrime, B3SOIFDtempNode);
                XFOO(B3SOIFDSPtempPtr, B3SOIFDSPtempBinding, B3SOIFDsNodePrime, B3SOIFDtempNode);
                XFOO(B3SOIFDEtempPtr, B3SOIFDEtempBinding, B3SOIFDeNode, B3SOIFDtempNode);
                XFOO(B3SOIFDBtempPtr, B3SOIFDBtempBinding, B3SOIFDbNode, B3SOIFDtempNode);
                if (here->B3SOIFDbodyMod == 1)
                {
                    XFOO(B3SOIFDPtempPtr, B3SOIFDPtempBinding, B3SOIFDpNode, B3SOIFDtempNode);
                }
            }
            if (here->B3SOIFDbodyMod == 2)
            {
            }
            else if (here->B3SOIFDbodyMod == 1)
            {
                XFOO(B3SOIFDBpPtr, B3SOIFDBpBinding, B3SOIFDbNode, B3SOIFDpNode);
                XFOO(B3SOIFDPbPtr, B3SOIFDPbBinding, B3SOIFDpNode, B3SOIFDbNode);
                XFOO(B3SOIFDPpPtr, B3SOIFDPpBinding, B3SOIFDpNode, B3SOIFDpNode);
                XFOO(B3SOIFDPgPtr, B3SOIFDPgBinding, B3SOIFDpNode, B3SOIFDgNode);
                XFOO(B3SOIFDPdpPtr, B3SOIFDPdpBinding, B3SOIFDpNode, B3SOIFDdNodePrime);
                XFOO(B3SOIFDPspPtr, B3SOIFDPspBinding, B3SOIFDpNode, B3SOIFDsNodePrime);
                XFOO(B3SOIFDPePtr, B3SOIFDPeBinding, B3SOIFDpNode, B3SOIFDeNode);
            }
            XFOO(B3SOIFDEgPtr, B3SOIFDEgBinding, B3SOIFDeNode, B3SOIFDgNode);
            XFOO(B3SOIFDEdpPtr, B3SOIFDEdpBinding, B3SOIFDeNode, B3SOIFDdNodePrime);
            XFOO(B3SOIFDEspPtr, B3SOIFDEspBinding, B3SOIFDeNode, B3SOIFDsNodePrime);
            XFOO(B3SOIFDGePtr, B3SOIFDGeBinding, B3SOIFDgNode, B3SOIFDeNode);
            XFOO(B3SOIFDDPePtr, B3SOIFDDPeBinding, B3SOIFDdNodePrime, B3SOIFDeNode);
            XFOO(B3SOIFDSPePtr, B3SOIFDSPeBinding, B3SOIFDsNodePrime, B3SOIFDeNode);
            XFOO(B3SOIFDEbPtr, B3SOIFDEbBinding, B3SOIFDeNode, B3SOIFDbNode);
            XFOO(B3SOIFDEePtr, B3SOIFDEeBinding, B3SOIFDeNode, B3SOIFDeNode);
            XFOO(B3SOIFDGgPtr, B3SOIFDGgBinding, B3SOIFDgNode, B3SOIFDgNode);
            XFOO(B3SOIFDGdpPtr, B3SOIFDGdpBinding, B3SOIFDgNode, B3SOIFDdNodePrime);
            XFOO(B3SOIFDGspPtr, B3SOIFDGspBinding, B3SOIFDgNode, B3SOIFDsNodePrime);
            XFOO(B3SOIFDDPgPtr, B3SOIFDDPgBinding, B3SOIFDdNodePrime, B3SOIFDgNode);
            XFOO(B3SOIFDDPdpPtr, B3SOIFDDPdpBinding, B3SOIFDdNodePrime, B3SOIFDdNodePrime);
            XFOO(B3SOIFDDPspPtr, B3SOIFDDPspBinding, B3SOIFDdNodePrime, B3SOIFDsNodePrime);
            XFOO(B3SOIFDDPdPtr, B3SOIFDDPdBinding, B3SOIFDdNodePrime, B3SOIFDdNode);
            XFOO(B3SOIFDSPgPtr, B3SOIFDSPgBinding, B3SOIFDsNodePrime, B3SOIFDgNode);
            XFOO(B3SOIFDSPdpPtr, B3SOIFDSPdpBinding, B3SOIFDsNodePrime, B3SOIFDdNodePrime);
            XFOO(B3SOIFDSPspPtr, B3SOIFDSPspBinding, B3SOIFDsNodePrime, B3SOIFDsNodePrime);
            XFOO(B3SOIFDSPsPtr, B3SOIFDSPsBinding, B3SOIFDsNodePrime, B3SOIFDsNode);
            XFOO(B3SOIFDDdPtr, B3SOIFDDdBinding, B3SOIFDdNode, B3SOIFDdNode);
            XFOO(B3SOIFDDdpPtr, B3SOIFDDdpBinding, B3SOIFDdNode, B3SOIFDdNodePrime);
            XFOO(B3SOIFDSsPtr, B3SOIFDSsBinding, B3SOIFDsNode, B3SOIFDsNode);
            XFOO(B3SOIFDSspPtr, B3SOIFDSspBinding, B3SOIFDsNode, B3SOIFDsNodePrime);
            if ((here->B3SOIFDdebugMod > 1) || (here->B3SOIFDdebugMod == -1))
            {
                XFOO(B3SOIFDVbsPtr, B3SOIFDVbsBinding, B3SOIFDvbsNode, B3SOIFDvbsNode);
                XFOO(B3SOIFDIdsPtr, B3SOIFDIdsBinding, B3SOIFDidsNode, B3SOIFDidsNode);
                XFOO(B3SOIFDIcPtr, B3SOIFDIcBinding, B3SOIFDicNode, B3SOIFDicNode);
                XFOO(B3SOIFDIbsPtr, B3SOIFDIbsBinding, B3SOIFDibsNode, B3SOIFDibsNode);
                XFOO(B3SOIFDIbdPtr, B3SOIFDIbdBinding, B3SOIFDibdNode, B3SOIFDibdNode);
                XFOO(B3SOIFDIiiPtr, B3SOIFDIiiBinding, B3SOIFDiiiNode, B3SOIFDiiiNode);
                XFOO(B3SOIFDIgidlPtr, B3SOIFDIgidlBinding, B3SOIFDigidlNode, B3SOIFDigidlNode);
                XFOO(B3SOIFDItunPtr, B3SOIFDItunBinding, B3SOIFDitunNode, B3SOIFDitunNode);
                XFOO(B3SOIFDIbpPtr, B3SOIFDIbpBinding, B3SOIFDibpNode, B3SOIFDibpNode);
                XFOO(B3SOIFDAbeffPtr, B3SOIFDAbeffBinding, B3SOIFDabeffNode, B3SOIFDabeffNode);
                XFOO(B3SOIFDVbs0effPtr, B3SOIFDVbs0effBinding, B3SOIFDvbs0effNode, B3SOIFDvbs0effNode);
                XFOO(B3SOIFDVbseffPtr, B3SOIFDVbseffBinding, B3SOIFDvbseffNode, B3SOIFDvbseffNode);
                XFOO(B3SOIFDXcPtr, B3SOIFDXcBinding, B3SOIFDxcNode, B3SOIFDxcNode);
                XFOO(B3SOIFDCbbPtr, B3SOIFDCbbBinding, B3SOIFDcbbNode, B3SOIFDcbbNode);
                XFOO(B3SOIFDCbdPtr, B3SOIFDCbdBinding, B3SOIFDcbdNode, B3SOIFDcbdNode);
                XFOO(B3SOIFDCbgPtr, B3SOIFDCbgBinding, B3SOIFDcbgNode, B3SOIFDcbgNode);
                XFOO(B3SOIFDqbPtr, B3SOIFDqbBinding, B3SOIFDqbNode, B3SOIFDqbNode);
                XFOO(B3SOIFDQbfPtr, B3SOIFDQbfBinding, B3SOIFDqbfNode, B3SOIFDqbfNode);
                XFOO(B3SOIFDQjsPtr, B3SOIFDQjsBinding, B3SOIFDqjsNode, B3SOIFDqjsNode);
                XFOO(B3SOIFDQjdPtr, B3SOIFDQjdBinding, B3SOIFDqjdNode, B3SOIFDqjdNode);
                XFOO(B3SOIFDGmPtr, B3SOIFDGmBinding, B3SOIFDgmNode, B3SOIFDgmNode);
                XFOO(B3SOIFDGmbsPtr, B3SOIFDGmbsBinding, B3SOIFDgmbsNode, B3SOIFDgmbsNode);
                XFOO(B3SOIFDGdsPtr, B3SOIFDGdsBinding, B3SOIFDgdsNode, B3SOIFDgdsNode);
                XFOO(B3SOIFDGmePtr, B3SOIFDGmeBinding, B3SOIFDgmeNode, B3SOIFDgmeNode);
                XFOO(B3SOIFDVbs0teffPtr, B3SOIFDVbs0teffBinding, B3SOIFDvbs0teffNode, B3SOIFDvbs0teffNode);
                XFOO(B3SOIFDVthPtr, B3SOIFDVthBinding, B3SOIFDvthNode, B3SOIFDvthNode);
                XFOO(B3SOIFDVgsteffPtr, B3SOIFDVgsteffBinding, B3SOIFDvgsteffNode, B3SOIFDvgsteffNode);
                XFOO(B3SOIFDXcsatPtr, B3SOIFDXcsatBinding, B3SOIFDxcsatNode, B3SOIFDxcsatNode);
                XFOO(B3SOIFDVcscvPtr, B3SOIFDVcscvBinding, B3SOIFDvcscvNode, B3SOIFDvcscvNode);
                XFOO(B3SOIFDVdscvPtr, B3SOIFDVdscvBinding, B3SOIFDvdscvNode, B3SOIFDvdscvNode);
                XFOO(B3SOIFDCbePtr, B3SOIFDCbeBinding, B3SOIFDcbeNode, B3SOIFDcbeNode);
                XFOO(B3SOIFDDum1Ptr, B3SOIFDDum1Binding, B3SOIFDdum1Node, B3SOIFDdum1Node);
                XFOO(B3SOIFDDum2Ptr, B3SOIFDDum2Binding, B3SOIFDdum2Node, B3SOIFDdum2Node);
                XFOO(B3SOIFDDum3Ptr, B3SOIFDDum3Binding, B3SOIFDdum3Node, B3SOIFDdum3Node);
                XFOO(B3SOIFDDum4Ptr, B3SOIFDDum4Binding, B3SOIFDdum4Node, B3SOIFDdum4Node);
                XFOO(B3SOIFDDum5Ptr, B3SOIFDDum5Binding, B3SOIFDdum5Node, B3SOIFDdum5Node);
                XFOO(B3SOIFDQaccPtr, B3SOIFDQaccBinding, B3SOIFDqaccNode, B3SOIFDqaccNode);
                XFOO(B3SOIFDQsub0Ptr, B3SOIFDQsub0Binding, B3SOIFDqsub0Node, B3SOIFDqsub0Node);
                XFOO(B3SOIFDQsubs1Ptr, B3SOIFDQsubs1Binding, B3SOIFDqsubs1Node, B3SOIFDqsubs1Node);
                XFOO(B3SOIFDQsubs2Ptr, B3SOIFDQsubs2Binding, B3SOIFDqsubs2Node, B3SOIFDqsubs2Node);
                XFOO(B3SOIFDqePtr, B3SOIFDqeBinding, B3SOIFDqeNode, B3SOIFDqeNode);
                XFOO(B3SOIFDqdPtr, B3SOIFDqdBinding, B3SOIFDqdNode, B3SOIFDqdNode);
                XFOO(B3SOIFDqgPtr, B3SOIFDqgBinding, B3SOIFDqgNode, B3SOIFDqgNode);
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
                BFOO(B3SOIFDTemptempPtr, B3SOIFDTemptempBinding, B3SOIFDtempNode, B3SOIFDtempNode);
                BFOO(B3SOIFDTempdpPtr, B3SOIFDTempdpBinding, B3SOIFDtempNode, B3SOIFDdNodePrime);
                BFOO(B3SOIFDTempspPtr, B3SOIFDTempspBinding, B3SOIFDtempNode, B3SOIFDsNodePrime);
                BFOO(B3SOIFDTempgPtr, B3SOIFDTempgBinding, B3SOIFDtempNode, B3SOIFDgNode);
                BFOO(B3SOIFDTempbPtr, B3SOIFDTempbBinding, B3SOIFDtempNode, B3SOIFDbNode);
                BFOO(B3SOIFDTempePtr, B3SOIFDTempeBinding, B3SOIFDtempNode, B3SOIFDeNode);
                BFOO(B3SOIFDGtempPtr, B3SOIFDGtempBinding, B3SOIFDgNode, B3SOIFDtempNode);
                BFOO(B3SOIFDDPtempPtr, B3SOIFDDPtempBinding, B3SOIFDdNodePrime, B3SOIFDtempNode);
                BFOO(B3SOIFDSPtempPtr, B3SOIFDSPtempBinding, B3SOIFDsNodePrime, B3SOIFDtempNode);
                BFOO(B3SOIFDEtempPtr, B3SOIFDEtempBinding, B3SOIFDeNode, B3SOIFDtempNode);
                BFOO(B3SOIFDBtempPtr, B3SOIFDBtempBinding, B3SOIFDbNode, B3SOIFDtempNode);
                if (here->B3SOIFDbodyMod == 1)
                {
                    BFOO(B3SOIFDPtempPtr, B3SOIFDPtempBinding, B3SOIFDpNode, B3SOIFDtempNode);
                }
            }
            if (here->B3SOIFDbodyMod == 2)
            {
            }
            else if (here->B3SOIFDbodyMod == 1)
            {
                BFOO(B3SOIFDBpPtr, B3SOIFDBpBinding, B3SOIFDbNode, B3SOIFDpNode);
                BFOO(B3SOIFDPbPtr, B3SOIFDPbBinding, B3SOIFDpNode, B3SOIFDbNode);
                BFOO(B3SOIFDPpPtr, B3SOIFDPpBinding, B3SOIFDpNode, B3SOIFDpNode);
                BFOO(B3SOIFDPgPtr, B3SOIFDPgBinding, B3SOIFDpNode, B3SOIFDgNode);
                BFOO(B3SOIFDPdpPtr, B3SOIFDPdpBinding, B3SOIFDpNode, B3SOIFDdNodePrime);
                BFOO(B3SOIFDPspPtr, B3SOIFDPspBinding, B3SOIFDpNode, B3SOIFDsNodePrime);
                BFOO(B3SOIFDPePtr, B3SOIFDPeBinding, B3SOIFDpNode, B3SOIFDeNode);
            }
            BFOO(B3SOIFDEgPtr, B3SOIFDEgBinding, B3SOIFDeNode, B3SOIFDgNode);
            BFOO(B3SOIFDEdpPtr, B3SOIFDEdpBinding, B3SOIFDeNode, B3SOIFDdNodePrime);
            BFOO(B3SOIFDEspPtr, B3SOIFDEspBinding, B3SOIFDeNode, B3SOIFDsNodePrime);
            BFOO(B3SOIFDGePtr, B3SOIFDGeBinding, B3SOIFDgNode, B3SOIFDeNode);
            BFOO(B3SOIFDDPePtr, B3SOIFDDPeBinding, B3SOIFDdNodePrime, B3SOIFDeNode);
            BFOO(B3SOIFDSPePtr, B3SOIFDSPeBinding, B3SOIFDsNodePrime, B3SOIFDeNode);
            BFOO(B3SOIFDEbPtr, B3SOIFDEbBinding, B3SOIFDeNode, B3SOIFDbNode);
            BFOO(B3SOIFDEePtr, B3SOIFDEeBinding, B3SOIFDeNode, B3SOIFDeNode);
            BFOO(B3SOIFDGgPtr, B3SOIFDGgBinding, B3SOIFDgNode, B3SOIFDgNode);
            BFOO(B3SOIFDGdpPtr, B3SOIFDGdpBinding, B3SOIFDgNode, B3SOIFDdNodePrime);
            BFOO(B3SOIFDGspPtr, B3SOIFDGspBinding, B3SOIFDgNode, B3SOIFDsNodePrime);
            BFOO(B3SOIFDDPgPtr, B3SOIFDDPgBinding, B3SOIFDdNodePrime, B3SOIFDgNode);
            BFOO(B3SOIFDDPdpPtr, B3SOIFDDPdpBinding, B3SOIFDdNodePrime, B3SOIFDdNodePrime);
            BFOO(B3SOIFDDPspPtr, B3SOIFDDPspBinding, B3SOIFDdNodePrime, B3SOIFDsNodePrime);
            BFOO(B3SOIFDDPdPtr, B3SOIFDDPdBinding, B3SOIFDdNodePrime, B3SOIFDdNode);
            BFOO(B3SOIFDSPgPtr, B3SOIFDSPgBinding, B3SOIFDsNodePrime, B3SOIFDgNode);
            BFOO(B3SOIFDSPdpPtr, B3SOIFDSPdpBinding, B3SOIFDsNodePrime, B3SOIFDdNodePrime);
            BFOO(B3SOIFDSPspPtr, B3SOIFDSPspBinding, B3SOIFDsNodePrime, B3SOIFDsNodePrime);
            BFOO(B3SOIFDSPsPtr, B3SOIFDSPsBinding, B3SOIFDsNodePrime, B3SOIFDsNode);
            BFOO(B3SOIFDDdPtr, B3SOIFDDdBinding, B3SOIFDdNode, B3SOIFDdNode);
            BFOO(B3SOIFDDdpPtr, B3SOIFDDdpBinding, B3SOIFDdNode, B3SOIFDdNodePrime);
            BFOO(B3SOIFDSsPtr, B3SOIFDSsBinding, B3SOIFDsNode, B3SOIFDsNode);
            BFOO(B3SOIFDSspPtr, B3SOIFDSspBinding, B3SOIFDsNode, B3SOIFDsNodePrime);
            if ((here->B3SOIFDdebugMod > 1) || (here->B3SOIFDdebugMod == -1))
            {
                BFOO(B3SOIFDVbsPtr, B3SOIFDVbsBinding, B3SOIFDvbsNode, B3SOIFDvbsNode);
                BFOO(B3SOIFDIdsPtr, B3SOIFDIdsBinding, B3SOIFDidsNode, B3SOIFDidsNode);
                BFOO(B3SOIFDIcPtr, B3SOIFDIcBinding, B3SOIFDicNode, B3SOIFDicNode);
                BFOO(B3SOIFDIbsPtr, B3SOIFDIbsBinding, B3SOIFDibsNode, B3SOIFDibsNode);
                BFOO(B3SOIFDIbdPtr, B3SOIFDIbdBinding, B3SOIFDibdNode, B3SOIFDibdNode);
                BFOO(B3SOIFDIiiPtr, B3SOIFDIiiBinding, B3SOIFDiiiNode, B3SOIFDiiiNode);
                BFOO(B3SOIFDIgidlPtr, B3SOIFDIgidlBinding, B3SOIFDigidlNode, B3SOIFDigidlNode);
                BFOO(B3SOIFDItunPtr, B3SOIFDItunBinding, B3SOIFDitunNode, B3SOIFDitunNode);
                BFOO(B3SOIFDIbpPtr, B3SOIFDIbpBinding, B3SOIFDibpNode, B3SOIFDibpNode);
                BFOO(B3SOIFDAbeffPtr, B3SOIFDAbeffBinding, B3SOIFDabeffNode, B3SOIFDabeffNode);
                BFOO(B3SOIFDVbs0effPtr, B3SOIFDVbs0effBinding, B3SOIFDvbs0effNode, B3SOIFDvbs0effNode);
                BFOO(B3SOIFDVbseffPtr, B3SOIFDVbseffBinding, B3SOIFDvbseffNode, B3SOIFDvbseffNode);
                BFOO(B3SOIFDXcPtr, B3SOIFDXcBinding, B3SOIFDxcNode, B3SOIFDxcNode);
                BFOO(B3SOIFDCbbPtr, B3SOIFDCbbBinding, B3SOIFDcbbNode, B3SOIFDcbbNode);
                BFOO(B3SOIFDCbdPtr, B3SOIFDCbdBinding, B3SOIFDcbdNode, B3SOIFDcbdNode);
                BFOO(B3SOIFDCbgPtr, B3SOIFDCbgBinding, B3SOIFDcbgNode, B3SOIFDcbgNode);
                BFOO(B3SOIFDqbPtr, B3SOIFDqbBinding, B3SOIFDqbNode, B3SOIFDqbNode);
                BFOO(B3SOIFDQbfPtr, B3SOIFDQbfBinding, B3SOIFDqbfNode, B3SOIFDqbfNode);
                BFOO(B3SOIFDQjsPtr, B3SOIFDQjsBinding, B3SOIFDqjsNode, B3SOIFDqjsNode);
                BFOO(B3SOIFDQjdPtr, B3SOIFDQjdBinding, B3SOIFDqjdNode, B3SOIFDqjdNode);
                BFOO(B3SOIFDGmPtr, B3SOIFDGmBinding, B3SOIFDgmNode, B3SOIFDgmNode);
                BFOO(B3SOIFDGmbsPtr, B3SOIFDGmbsBinding, B3SOIFDgmbsNode, B3SOIFDgmbsNode);
                BFOO(B3SOIFDGdsPtr, B3SOIFDGdsBinding, B3SOIFDgdsNode, B3SOIFDgdsNode);
                BFOO(B3SOIFDGmePtr, B3SOIFDGmeBinding, B3SOIFDgmeNode, B3SOIFDgmeNode);
                BFOO(B3SOIFDVbs0teffPtr, B3SOIFDVbs0teffBinding, B3SOIFDvbs0teffNode, B3SOIFDvbs0teffNode);
                BFOO(B3SOIFDVthPtr, B3SOIFDVthBinding, B3SOIFDvthNode, B3SOIFDvthNode);
                BFOO(B3SOIFDVgsteffPtr, B3SOIFDVgsteffBinding, B3SOIFDvgsteffNode, B3SOIFDvgsteffNode);
                BFOO(B3SOIFDXcsatPtr, B3SOIFDXcsatBinding, B3SOIFDxcsatNode, B3SOIFDxcsatNode);
                BFOO(B3SOIFDVcscvPtr, B3SOIFDVcscvBinding, B3SOIFDvcscvNode, B3SOIFDvcscvNode);
                BFOO(B3SOIFDVdscvPtr, B3SOIFDVdscvBinding, B3SOIFDvdscvNode, B3SOIFDvdscvNode);
                BFOO(B3SOIFDCbePtr, B3SOIFDCbeBinding, B3SOIFDcbeNode, B3SOIFDcbeNode);
                BFOO(B3SOIFDDum1Ptr, B3SOIFDDum1Binding, B3SOIFDdum1Node, B3SOIFDdum1Node);
                BFOO(B3SOIFDDum2Ptr, B3SOIFDDum2Binding, B3SOIFDdum2Node, B3SOIFDdum2Node);
                BFOO(B3SOIFDDum3Ptr, B3SOIFDDum3Binding, B3SOIFDdum3Node, B3SOIFDdum3Node);
                BFOO(B3SOIFDDum4Ptr, B3SOIFDDum4Binding, B3SOIFDdum4Node, B3SOIFDdum4Node);
                BFOO(B3SOIFDDum5Ptr, B3SOIFDDum5Binding, B3SOIFDdum5Node, B3SOIFDdum5Node);
                BFOO(B3SOIFDQaccPtr, B3SOIFDQaccBinding, B3SOIFDqaccNode, B3SOIFDqaccNode);
                BFOO(B3SOIFDQsub0Ptr, B3SOIFDQsub0Binding, B3SOIFDqsub0Node, B3SOIFDqsub0Node);
                BFOO(B3SOIFDQsubs1Ptr, B3SOIFDQsubs1Binding, B3SOIFDqsubs1Node, B3SOIFDqsubs1Node);
                BFOO(B3SOIFDQsubs2Ptr, B3SOIFDQsubs2Binding, B3SOIFDqsubs2Node, B3SOIFDqsubs2Node);
                BFOO(B3SOIFDqePtr, B3SOIFDqeBinding, B3SOIFDqeNode, B3SOIFDqeNode);
                BFOO(B3SOIFDqdPtr, B3SOIFDqdBinding, B3SOIFDqdNode, B3SOIFDqdNode);
                BFOO(B3SOIFDqgPtr, B3SOIFDqgBinding, B3SOIFDqgNode, B3SOIFDqgNode);
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
                CFOO(B3SOIFDTemptempPtr, B3SOIFDTemptempBinding, B3SOIFDtempNode, B3SOIFDtempNode);
                CFOO(B3SOIFDTempdpPtr, B3SOIFDTempdpBinding, B3SOIFDtempNode, B3SOIFDdNodePrime);
                CFOO(B3SOIFDTempspPtr, B3SOIFDTempspBinding, B3SOIFDtempNode, B3SOIFDsNodePrime);
                CFOO(B3SOIFDTempgPtr, B3SOIFDTempgBinding, B3SOIFDtempNode, B3SOIFDgNode);
                CFOO(B3SOIFDTempbPtr, B3SOIFDTempbBinding, B3SOIFDtempNode, B3SOIFDbNode);
                CFOO(B3SOIFDTempePtr, B3SOIFDTempeBinding, B3SOIFDtempNode, B3SOIFDeNode);
                CFOO(B3SOIFDGtempPtr, B3SOIFDGtempBinding, B3SOIFDgNode, B3SOIFDtempNode);
                CFOO(B3SOIFDDPtempPtr, B3SOIFDDPtempBinding, B3SOIFDdNodePrime, B3SOIFDtempNode);
                CFOO(B3SOIFDSPtempPtr, B3SOIFDSPtempBinding, B3SOIFDsNodePrime, B3SOIFDtempNode);
                CFOO(B3SOIFDEtempPtr, B3SOIFDEtempBinding, B3SOIFDeNode, B3SOIFDtempNode);
                CFOO(B3SOIFDBtempPtr, B3SOIFDBtempBinding, B3SOIFDbNode, B3SOIFDtempNode);
                if (here->B3SOIFDbodyMod == 1)
                {
                    CFOO(B3SOIFDPtempPtr, B3SOIFDPtempBinding, B3SOIFDpNode, B3SOIFDtempNode);
                }
            }
            if (here->B3SOIFDbodyMod == 2)
            {
            }
            else if (here->B3SOIFDbodyMod == 1)
            {
                CFOO(B3SOIFDBpPtr, B3SOIFDBpBinding, B3SOIFDbNode, B3SOIFDpNode);
                CFOO(B3SOIFDPbPtr, B3SOIFDPbBinding, B3SOIFDpNode, B3SOIFDbNode);
                CFOO(B3SOIFDPpPtr, B3SOIFDPpBinding, B3SOIFDpNode, B3SOIFDpNode);
                CFOO(B3SOIFDPgPtr, B3SOIFDPgBinding, B3SOIFDpNode, B3SOIFDgNode);
                CFOO(B3SOIFDPdpPtr, B3SOIFDPdpBinding, B3SOIFDpNode, B3SOIFDdNodePrime);
                CFOO(B3SOIFDPspPtr, B3SOIFDPspBinding, B3SOIFDpNode, B3SOIFDsNodePrime);
                CFOO(B3SOIFDPePtr, B3SOIFDPeBinding, B3SOIFDpNode, B3SOIFDeNode);
            }
            CFOO(B3SOIFDEgPtr, B3SOIFDEgBinding, B3SOIFDeNode, B3SOIFDgNode);
            CFOO(B3SOIFDEdpPtr, B3SOIFDEdpBinding, B3SOIFDeNode, B3SOIFDdNodePrime);
            CFOO(B3SOIFDEspPtr, B3SOIFDEspBinding, B3SOIFDeNode, B3SOIFDsNodePrime);
            CFOO(B3SOIFDGePtr, B3SOIFDGeBinding, B3SOIFDgNode, B3SOIFDeNode);
            CFOO(B3SOIFDDPePtr, B3SOIFDDPeBinding, B3SOIFDdNodePrime, B3SOIFDeNode);
            CFOO(B3SOIFDSPePtr, B3SOIFDSPeBinding, B3SOIFDsNodePrime, B3SOIFDeNode);
            CFOO(B3SOIFDEbPtr, B3SOIFDEbBinding, B3SOIFDeNode, B3SOIFDbNode);
            CFOO(B3SOIFDEePtr, B3SOIFDEeBinding, B3SOIFDeNode, B3SOIFDeNode);
            CFOO(B3SOIFDGgPtr, B3SOIFDGgBinding, B3SOIFDgNode, B3SOIFDgNode);
            CFOO(B3SOIFDGdpPtr, B3SOIFDGdpBinding, B3SOIFDgNode, B3SOIFDdNodePrime);
            CFOO(B3SOIFDGspPtr, B3SOIFDGspBinding, B3SOIFDgNode, B3SOIFDsNodePrime);
            CFOO(B3SOIFDDPgPtr, B3SOIFDDPgBinding, B3SOIFDdNodePrime, B3SOIFDgNode);
            CFOO(B3SOIFDDPdpPtr, B3SOIFDDPdpBinding, B3SOIFDdNodePrime, B3SOIFDdNodePrime);
            CFOO(B3SOIFDDPspPtr, B3SOIFDDPspBinding, B3SOIFDdNodePrime, B3SOIFDsNodePrime);
            CFOO(B3SOIFDDPdPtr, B3SOIFDDPdBinding, B3SOIFDdNodePrime, B3SOIFDdNode);
            CFOO(B3SOIFDSPgPtr, B3SOIFDSPgBinding, B3SOIFDsNodePrime, B3SOIFDgNode);
            CFOO(B3SOIFDSPdpPtr, B3SOIFDSPdpBinding, B3SOIFDsNodePrime, B3SOIFDdNodePrime);
            CFOO(B3SOIFDSPspPtr, B3SOIFDSPspBinding, B3SOIFDsNodePrime, B3SOIFDsNodePrime);
            CFOO(B3SOIFDSPsPtr, B3SOIFDSPsBinding, B3SOIFDsNodePrime, B3SOIFDsNode);
            CFOO(B3SOIFDDdPtr, B3SOIFDDdBinding, B3SOIFDdNode, B3SOIFDdNode);
            CFOO(B3SOIFDDdpPtr, B3SOIFDDdpBinding, B3SOIFDdNode, B3SOIFDdNodePrime);
            CFOO(B3SOIFDSsPtr, B3SOIFDSsBinding, B3SOIFDsNode, B3SOIFDsNode);
            CFOO(B3SOIFDSspPtr, B3SOIFDSspBinding, B3SOIFDsNode, B3SOIFDsNodePrime);
            if ((here->B3SOIFDdebugMod > 1) || (here->B3SOIFDdebugMod == -1))
            {
                CFOO(B3SOIFDVbsPtr, B3SOIFDVbsBinding, B3SOIFDvbsNode, B3SOIFDvbsNode);
                CFOO(B3SOIFDIdsPtr, B3SOIFDIdsBinding, B3SOIFDidsNode, B3SOIFDidsNode);
                CFOO(B3SOIFDIcPtr, B3SOIFDIcBinding, B3SOIFDicNode, B3SOIFDicNode);
                CFOO(B3SOIFDIbsPtr, B3SOIFDIbsBinding, B3SOIFDibsNode, B3SOIFDibsNode);
                CFOO(B3SOIFDIbdPtr, B3SOIFDIbdBinding, B3SOIFDibdNode, B3SOIFDibdNode);
                CFOO(B3SOIFDIiiPtr, B3SOIFDIiiBinding, B3SOIFDiiiNode, B3SOIFDiiiNode);
                CFOO(B3SOIFDIgidlPtr, B3SOIFDIgidlBinding, B3SOIFDigidlNode, B3SOIFDigidlNode);
                CFOO(B3SOIFDItunPtr, B3SOIFDItunBinding, B3SOIFDitunNode, B3SOIFDitunNode);
                CFOO(B3SOIFDIbpPtr, B3SOIFDIbpBinding, B3SOIFDibpNode, B3SOIFDibpNode);
                CFOO(B3SOIFDAbeffPtr, B3SOIFDAbeffBinding, B3SOIFDabeffNode, B3SOIFDabeffNode);
                CFOO(B3SOIFDVbs0effPtr, B3SOIFDVbs0effBinding, B3SOIFDvbs0effNode, B3SOIFDvbs0effNode);
                CFOO(B3SOIFDVbseffPtr, B3SOIFDVbseffBinding, B3SOIFDvbseffNode, B3SOIFDvbseffNode);
                CFOO(B3SOIFDXcPtr, B3SOIFDXcBinding, B3SOIFDxcNode, B3SOIFDxcNode);
                CFOO(B3SOIFDCbbPtr, B3SOIFDCbbBinding, B3SOIFDcbbNode, B3SOIFDcbbNode);
                CFOO(B3SOIFDCbdPtr, B3SOIFDCbdBinding, B3SOIFDcbdNode, B3SOIFDcbdNode);
                CFOO(B3SOIFDCbgPtr, B3SOIFDCbgBinding, B3SOIFDcbgNode, B3SOIFDcbgNode);
                CFOO(B3SOIFDqbPtr, B3SOIFDqbBinding, B3SOIFDqbNode, B3SOIFDqbNode);
                CFOO(B3SOIFDQbfPtr, B3SOIFDQbfBinding, B3SOIFDqbfNode, B3SOIFDqbfNode);
                CFOO(B3SOIFDQjsPtr, B3SOIFDQjsBinding, B3SOIFDqjsNode, B3SOIFDqjsNode);
                CFOO(B3SOIFDQjdPtr, B3SOIFDQjdBinding, B3SOIFDqjdNode, B3SOIFDqjdNode);
                CFOO(B3SOIFDGmPtr, B3SOIFDGmBinding, B3SOIFDgmNode, B3SOIFDgmNode);
                CFOO(B3SOIFDGmbsPtr, B3SOIFDGmbsBinding, B3SOIFDgmbsNode, B3SOIFDgmbsNode);
                CFOO(B3SOIFDGdsPtr, B3SOIFDGdsBinding, B3SOIFDgdsNode, B3SOIFDgdsNode);
                CFOO(B3SOIFDGmePtr, B3SOIFDGmeBinding, B3SOIFDgmeNode, B3SOIFDgmeNode);
                CFOO(B3SOIFDVbs0teffPtr, B3SOIFDVbs0teffBinding, B3SOIFDvbs0teffNode, B3SOIFDvbs0teffNode);
                CFOO(B3SOIFDVthPtr, B3SOIFDVthBinding, B3SOIFDvthNode, B3SOIFDvthNode);
                CFOO(B3SOIFDVgsteffPtr, B3SOIFDVgsteffBinding, B3SOIFDvgsteffNode, B3SOIFDvgsteffNode);
                CFOO(B3SOIFDXcsatPtr, B3SOIFDXcsatBinding, B3SOIFDxcsatNode, B3SOIFDxcsatNode);
                CFOO(B3SOIFDVcscvPtr, B3SOIFDVcscvBinding, B3SOIFDvcscvNode, B3SOIFDvcscvNode);
                CFOO(B3SOIFDVdscvPtr, B3SOIFDVdscvBinding, B3SOIFDvdscvNode, B3SOIFDvdscvNode);
                CFOO(B3SOIFDCbePtr, B3SOIFDCbeBinding, B3SOIFDcbeNode, B3SOIFDcbeNode);
                CFOO(B3SOIFDDum1Ptr, B3SOIFDDum1Binding, B3SOIFDdum1Node, B3SOIFDdum1Node);
                CFOO(B3SOIFDDum2Ptr, B3SOIFDDum2Binding, B3SOIFDdum2Node, B3SOIFDdum2Node);
                CFOO(B3SOIFDDum3Ptr, B3SOIFDDum3Binding, B3SOIFDdum3Node, B3SOIFDdum3Node);
                CFOO(B3SOIFDDum4Ptr, B3SOIFDDum4Binding, B3SOIFDdum4Node, B3SOIFDdum4Node);
                CFOO(B3SOIFDDum5Ptr, B3SOIFDDum5Binding, B3SOIFDdum5Node, B3SOIFDdum5Node);
                CFOO(B3SOIFDQaccPtr, B3SOIFDQaccBinding, B3SOIFDqaccNode, B3SOIFDqaccNode);
                CFOO(B3SOIFDQsub0Ptr, B3SOIFDQsub0Binding, B3SOIFDqsub0Node, B3SOIFDqsub0Node);
                CFOO(B3SOIFDQsubs1Ptr, B3SOIFDQsubs1Binding, B3SOIFDqsubs1Node, B3SOIFDqsubs1Node);
                CFOO(B3SOIFDQsubs2Ptr, B3SOIFDQsubs2Binding, B3SOIFDqsubs2Node, B3SOIFDqsubs2Node);
                CFOO(B3SOIFDqePtr, B3SOIFDqeBinding, B3SOIFDqeNode, B3SOIFDqeNode);
                CFOO(B3SOIFDqdPtr, B3SOIFDqdBinding, B3SOIFDqdNode, B3SOIFDqdNode);
                CFOO(B3SOIFDqgPtr, B3SOIFDqgBinding, B3SOIFDqgNode, B3SOIFDqgNode);
            }
        }
    }

    return (OK) ;
}
