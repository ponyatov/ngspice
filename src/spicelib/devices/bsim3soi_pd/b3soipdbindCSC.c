/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "b3soipddef.h"
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
                XFOO(B3SOIPDTemptempPtr, B3SOIPDTemptempBinding, B3SOIPDtempNode, B3SOIPDtempNode);
                XFOO(B3SOIPDTempdpPtr, B3SOIPDTempdpBinding, B3SOIPDtempNode, B3SOIPDdNodePrime);
                XFOO(B3SOIPDTempspPtr, B3SOIPDTempspBinding, B3SOIPDtempNode, B3SOIPDsNodePrime);
                XFOO(B3SOIPDTempgPtr, B3SOIPDTempgBinding, B3SOIPDtempNode, B3SOIPDgNode);
                XFOO(B3SOIPDTempbPtr, B3SOIPDTempbBinding, B3SOIPDtempNode, B3SOIPDbNode);
                XFOO(B3SOIPDGtempPtr, B3SOIPDGtempBinding, B3SOIPDgNode, B3SOIPDtempNode);
                XFOO(B3SOIPDDPtempPtr, B3SOIPDDPtempBinding, B3SOIPDdNodePrime, B3SOIPDtempNode);
                XFOO(B3SOIPDSPtempPtr, B3SOIPDSPtempBinding, B3SOIPDsNodePrime, B3SOIPDtempNode);
                XFOO(B3SOIPDEtempPtr, B3SOIPDEtempBinding, B3SOIPDeNode, B3SOIPDtempNode);
                XFOO(B3SOIPDBtempPtr, B3SOIPDBtempBinding, B3SOIPDbNode, B3SOIPDtempNode);
                if (here->B3SOIPDbodyMod == 1)
                {
                    XFOO(B3SOIPDPtempPtr, B3SOIPDPtempBinding, B3SOIPDpNode, B3SOIPDtempNode);
                }
            }
            if (here->B3SOIPDbodyMod == 2)
            {
            }
            else if (here->B3SOIPDbodyMod == 1)
            {
                XFOO(B3SOIPDBpPtr, B3SOIPDBpBinding, B3SOIPDbNode, B3SOIPDpNode);
                XFOO(B3SOIPDPbPtr, B3SOIPDPbBinding, B3SOIPDpNode, B3SOIPDbNode);
                XFOO(B3SOIPDPpPtr, B3SOIPDPpBinding, B3SOIPDpNode, B3SOIPDpNode);
            }
            XFOO(B3SOIPDEbPtr, B3SOIPDEbBinding, B3SOIPDeNode, B3SOIPDbNode);
            XFOO(B3SOIPDGbPtr, B3SOIPDGbBinding, B3SOIPDgNode, B3SOIPDbNode);
            XFOO(B3SOIPDDPbPtr, B3SOIPDDPbBinding, B3SOIPDdNodePrime, B3SOIPDbNode);
            XFOO(B3SOIPDSPbPtr, B3SOIPDSPbBinding, B3SOIPDsNodePrime, B3SOIPDbNode);
            XFOO(B3SOIPDBePtr, B3SOIPDBeBinding, B3SOIPDbNode, B3SOIPDeNode);
            XFOO(B3SOIPDBgPtr, B3SOIPDBgBinding, B3SOIPDbNode, B3SOIPDgNode);
            XFOO(B3SOIPDBdpPtr, B3SOIPDBdpBinding, B3SOIPDbNode, B3SOIPDdNodePrime);
            XFOO(B3SOIPDBspPtr, B3SOIPDBspBinding, B3SOIPDbNode, B3SOIPDsNodePrime);
            XFOO(B3SOIPDBbPtr, B3SOIPDBbBinding, B3SOIPDbNode, B3SOIPDbNode);
            XFOO(B3SOIPDEgPtr, B3SOIPDEgBinding, B3SOIPDeNode, B3SOIPDgNode);
            XFOO(B3SOIPDEdpPtr, B3SOIPDEdpBinding, B3SOIPDeNode, B3SOIPDdNodePrime);
            XFOO(B3SOIPDEspPtr, B3SOIPDEspBinding, B3SOIPDeNode, B3SOIPDsNodePrime);
            XFOO(B3SOIPDGePtr, B3SOIPDGeBinding, B3SOIPDgNode, B3SOIPDeNode);
            XFOO(B3SOIPDDPePtr, B3SOIPDDPeBinding, B3SOIPDdNodePrime, B3SOIPDeNode);
            XFOO(B3SOIPDSPePtr, B3SOIPDSPeBinding, B3SOIPDsNodePrime, B3SOIPDeNode);
            XFOO(B3SOIPDEePtr, B3SOIPDEeBinding, B3SOIPDeNode, B3SOIPDeNode);
            XFOO(B3SOIPDGgPtr, B3SOIPDGgBinding, B3SOIPDgNode, B3SOIPDgNode);
            XFOO(B3SOIPDGdpPtr, B3SOIPDGdpBinding, B3SOIPDgNode, B3SOIPDdNodePrime);
            XFOO(B3SOIPDGspPtr, B3SOIPDGspBinding, B3SOIPDgNode, B3SOIPDsNodePrime);
            XFOO(B3SOIPDDPgPtr, B3SOIPDDPgBinding, B3SOIPDdNodePrime, B3SOIPDgNode);
            XFOO(B3SOIPDDPdpPtr, B3SOIPDDPdpBinding, B3SOIPDdNodePrime, B3SOIPDdNodePrime);
            XFOO(B3SOIPDDPspPtr, B3SOIPDDPspBinding, B3SOIPDdNodePrime, B3SOIPDsNodePrime);
            XFOO(B3SOIPDDPdPtr, B3SOIPDDPdBinding, B3SOIPDdNodePrime, B3SOIPDdNode);
            XFOO(B3SOIPDSPgPtr, B3SOIPDSPgBinding, B3SOIPDsNodePrime, B3SOIPDgNode);
            XFOO(B3SOIPDSPdpPtr, B3SOIPDSPdpBinding, B3SOIPDsNodePrime, B3SOIPDdNodePrime);
            XFOO(B3SOIPDSPspPtr, B3SOIPDSPspBinding, B3SOIPDsNodePrime, B3SOIPDsNodePrime);
            XFOO(B3SOIPDSPsPtr, B3SOIPDSPsBinding, B3SOIPDsNodePrime, B3SOIPDsNode);
            XFOO(B3SOIPDDdPtr, B3SOIPDDdBinding, B3SOIPDdNode, B3SOIPDdNode);
            XFOO(B3SOIPDDdpPtr, B3SOIPDDdpBinding, B3SOIPDdNode, B3SOIPDdNodePrime);
            XFOO(B3SOIPDSsPtr, B3SOIPDSsBinding, B3SOIPDsNode, B3SOIPDsNode);
            XFOO(B3SOIPDSspPtr, B3SOIPDSspBinding, B3SOIPDsNode, B3SOIPDsNodePrime);
            if (here->B3SOIPDdebugMod != 0)
            {
                XFOO(B3SOIPDVbsPtr, B3SOIPDVbsBinding, B3SOIPDvbsNode, B3SOIPDvbsNode);
                XFOO(B3SOIPDIdsPtr, B3SOIPDIdsBinding, B3SOIPDidsNode, B3SOIPDidsNode);
                XFOO(B3SOIPDIcPtr, B3SOIPDIcBinding, B3SOIPDicNode, B3SOIPDicNode);
                XFOO(B3SOIPDIbsPtr, B3SOIPDIbsBinding, B3SOIPDibsNode, B3SOIPDibsNode);
                XFOO(B3SOIPDIbdPtr, B3SOIPDIbdBinding, B3SOIPDibdNode, B3SOIPDibdNode);
                XFOO(B3SOIPDIiiPtr, B3SOIPDIiiBinding, B3SOIPDiiiNode, B3SOIPDiiiNode);
                XFOO(B3SOIPDIgPtr, B3SOIPDIgBinding, B3SOIPDigNode, B3SOIPDigNode);
                XFOO(B3SOIPDGiggPtr, B3SOIPDGiggBinding, B3SOIPDgiggNode, B3SOIPDgiggNode);
                XFOO(B3SOIPDGigdPtr, B3SOIPDGigdBinding, B3SOIPDgigdNode, B3SOIPDgigdNode);
                XFOO(B3SOIPDGigbPtr, B3SOIPDGigbBinding, B3SOIPDgigbNode, B3SOIPDgigbNode);
                XFOO(B3SOIPDIgidlPtr, B3SOIPDIgidlBinding, B3SOIPDigidlNode, B3SOIPDigidlNode);
                XFOO(B3SOIPDItunPtr, B3SOIPDItunBinding, B3SOIPDitunNode, B3SOIPDitunNode);
                XFOO(B3SOIPDIbpPtr, B3SOIPDIbpBinding, B3SOIPDibpNode, B3SOIPDibpNode);
                XFOO(B3SOIPDCbbPtr, B3SOIPDCbbBinding, B3SOIPDcbbNode, B3SOIPDcbbNode);
                XFOO(B3SOIPDCbdPtr, B3SOIPDCbdBinding, B3SOIPDcbdNode, B3SOIPDcbdNode);
                XFOO(B3SOIPDCbgPtr, B3SOIPDCbgBinding, B3SOIPDcbgNode, B3SOIPDcbgNode);
                XFOO(B3SOIPDQbfPtr, B3SOIPDQbfBinding, B3SOIPDqbfNode, B3SOIPDqbfNode);
                XFOO(B3SOIPDQjsPtr, B3SOIPDQjsBinding, B3SOIPDqjsNode, B3SOIPDqjsNode);
                XFOO(B3SOIPDQjdPtr, B3SOIPDQjdBinding, B3SOIPDqjdNode, B3SOIPDqjdNode);
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
                BFOO(B3SOIPDTemptempPtr, B3SOIPDTemptempBinding, B3SOIPDtempNode, B3SOIPDtempNode);
                BFOO(B3SOIPDTempdpPtr, B3SOIPDTempdpBinding, B3SOIPDtempNode, B3SOIPDdNodePrime);
                BFOO(B3SOIPDTempspPtr, B3SOIPDTempspBinding, B3SOIPDtempNode, B3SOIPDsNodePrime);
                BFOO(B3SOIPDTempgPtr, B3SOIPDTempgBinding, B3SOIPDtempNode, B3SOIPDgNode);
                BFOO(B3SOIPDTempbPtr, B3SOIPDTempbBinding, B3SOIPDtempNode, B3SOIPDbNode);
                BFOO(B3SOIPDGtempPtr, B3SOIPDGtempBinding, B3SOIPDgNode, B3SOIPDtempNode);
                BFOO(B3SOIPDDPtempPtr, B3SOIPDDPtempBinding, B3SOIPDdNodePrime, B3SOIPDtempNode);
                BFOO(B3SOIPDSPtempPtr, B3SOIPDSPtempBinding, B3SOIPDsNodePrime, B3SOIPDtempNode);
                BFOO(B3SOIPDEtempPtr, B3SOIPDEtempBinding, B3SOIPDeNode, B3SOIPDtempNode);
                BFOO(B3SOIPDBtempPtr, B3SOIPDBtempBinding, B3SOIPDbNode, B3SOIPDtempNode);
                if (here->B3SOIPDbodyMod == 1)
                {
                    BFOO(B3SOIPDPtempPtr, B3SOIPDPtempBinding, B3SOIPDpNode, B3SOIPDtempNode);
                }
            }
            if (here->B3SOIPDbodyMod == 2)
            {
            }
            else if (here->B3SOIPDbodyMod == 1)
            {
                BFOO(B3SOIPDBpPtr, B3SOIPDBpBinding, B3SOIPDbNode, B3SOIPDpNode);
                BFOO(B3SOIPDPbPtr, B3SOIPDPbBinding, B3SOIPDpNode, B3SOIPDbNode);
                BFOO(B3SOIPDPpPtr, B3SOIPDPpBinding, B3SOIPDpNode, B3SOIPDpNode);
            }
            BFOO(B3SOIPDEbPtr, B3SOIPDEbBinding, B3SOIPDeNode, B3SOIPDbNode);
            BFOO(B3SOIPDGbPtr, B3SOIPDGbBinding, B3SOIPDgNode, B3SOIPDbNode);
            BFOO(B3SOIPDDPbPtr, B3SOIPDDPbBinding, B3SOIPDdNodePrime, B3SOIPDbNode);
            BFOO(B3SOIPDSPbPtr, B3SOIPDSPbBinding, B3SOIPDsNodePrime, B3SOIPDbNode);
            BFOO(B3SOIPDBePtr, B3SOIPDBeBinding, B3SOIPDbNode, B3SOIPDeNode);
            BFOO(B3SOIPDBgPtr, B3SOIPDBgBinding, B3SOIPDbNode, B3SOIPDgNode);
            BFOO(B3SOIPDBdpPtr, B3SOIPDBdpBinding, B3SOIPDbNode, B3SOIPDdNodePrime);
            BFOO(B3SOIPDBspPtr, B3SOIPDBspBinding, B3SOIPDbNode, B3SOIPDsNodePrime);
            BFOO(B3SOIPDBbPtr, B3SOIPDBbBinding, B3SOIPDbNode, B3SOIPDbNode);
            BFOO(B3SOIPDEgPtr, B3SOIPDEgBinding, B3SOIPDeNode, B3SOIPDgNode);
            BFOO(B3SOIPDEdpPtr, B3SOIPDEdpBinding, B3SOIPDeNode, B3SOIPDdNodePrime);
            BFOO(B3SOIPDEspPtr, B3SOIPDEspBinding, B3SOIPDeNode, B3SOIPDsNodePrime);
            BFOO(B3SOIPDGePtr, B3SOIPDGeBinding, B3SOIPDgNode, B3SOIPDeNode);
            BFOO(B3SOIPDDPePtr, B3SOIPDDPeBinding, B3SOIPDdNodePrime, B3SOIPDeNode);
            BFOO(B3SOIPDSPePtr, B3SOIPDSPeBinding, B3SOIPDsNodePrime, B3SOIPDeNode);
            BFOO(B3SOIPDEePtr, B3SOIPDEeBinding, B3SOIPDeNode, B3SOIPDeNode);
            BFOO(B3SOIPDGgPtr, B3SOIPDGgBinding, B3SOIPDgNode, B3SOIPDgNode);
            BFOO(B3SOIPDGdpPtr, B3SOIPDGdpBinding, B3SOIPDgNode, B3SOIPDdNodePrime);
            BFOO(B3SOIPDGspPtr, B3SOIPDGspBinding, B3SOIPDgNode, B3SOIPDsNodePrime);
            BFOO(B3SOIPDDPgPtr, B3SOIPDDPgBinding, B3SOIPDdNodePrime, B3SOIPDgNode);
            BFOO(B3SOIPDDPdpPtr, B3SOIPDDPdpBinding, B3SOIPDdNodePrime, B3SOIPDdNodePrime);
            BFOO(B3SOIPDDPspPtr, B3SOIPDDPspBinding, B3SOIPDdNodePrime, B3SOIPDsNodePrime);
            BFOO(B3SOIPDDPdPtr, B3SOIPDDPdBinding, B3SOIPDdNodePrime, B3SOIPDdNode);
            BFOO(B3SOIPDSPgPtr, B3SOIPDSPgBinding, B3SOIPDsNodePrime, B3SOIPDgNode);
            BFOO(B3SOIPDSPdpPtr, B3SOIPDSPdpBinding, B3SOIPDsNodePrime, B3SOIPDdNodePrime);
            BFOO(B3SOIPDSPspPtr, B3SOIPDSPspBinding, B3SOIPDsNodePrime, B3SOIPDsNodePrime);
            BFOO(B3SOIPDSPsPtr, B3SOIPDSPsBinding, B3SOIPDsNodePrime, B3SOIPDsNode);
            BFOO(B3SOIPDDdPtr, B3SOIPDDdBinding, B3SOIPDdNode, B3SOIPDdNode);
            BFOO(B3SOIPDDdpPtr, B3SOIPDDdpBinding, B3SOIPDdNode, B3SOIPDdNodePrime);
            BFOO(B3SOIPDSsPtr, B3SOIPDSsBinding, B3SOIPDsNode, B3SOIPDsNode);
            BFOO(B3SOIPDSspPtr, B3SOIPDSspBinding, B3SOIPDsNode, B3SOIPDsNodePrime);
            if (here->B3SOIPDdebugMod != 0)
            {
                BFOO(B3SOIPDVbsPtr, B3SOIPDVbsBinding, B3SOIPDvbsNode, B3SOIPDvbsNode);
                BFOO(B3SOIPDIdsPtr, B3SOIPDIdsBinding, B3SOIPDidsNode, B3SOIPDidsNode);
                BFOO(B3SOIPDIcPtr, B3SOIPDIcBinding, B3SOIPDicNode, B3SOIPDicNode);
                BFOO(B3SOIPDIbsPtr, B3SOIPDIbsBinding, B3SOIPDibsNode, B3SOIPDibsNode);
                BFOO(B3SOIPDIbdPtr, B3SOIPDIbdBinding, B3SOIPDibdNode, B3SOIPDibdNode);
                BFOO(B3SOIPDIiiPtr, B3SOIPDIiiBinding, B3SOIPDiiiNode, B3SOIPDiiiNode);
                BFOO(B3SOIPDIgPtr, B3SOIPDIgBinding, B3SOIPDigNode, B3SOIPDigNode);
                BFOO(B3SOIPDGiggPtr, B3SOIPDGiggBinding, B3SOIPDgiggNode, B3SOIPDgiggNode);
                BFOO(B3SOIPDGigdPtr, B3SOIPDGigdBinding, B3SOIPDgigdNode, B3SOIPDgigdNode);
                BFOO(B3SOIPDGigbPtr, B3SOIPDGigbBinding, B3SOIPDgigbNode, B3SOIPDgigbNode);
                BFOO(B3SOIPDIgidlPtr, B3SOIPDIgidlBinding, B3SOIPDigidlNode, B3SOIPDigidlNode);
                BFOO(B3SOIPDItunPtr, B3SOIPDItunBinding, B3SOIPDitunNode, B3SOIPDitunNode);
                BFOO(B3SOIPDIbpPtr, B3SOIPDIbpBinding, B3SOIPDibpNode, B3SOIPDibpNode);
                BFOO(B3SOIPDCbbPtr, B3SOIPDCbbBinding, B3SOIPDcbbNode, B3SOIPDcbbNode);
                BFOO(B3SOIPDCbdPtr, B3SOIPDCbdBinding, B3SOIPDcbdNode, B3SOIPDcbdNode);
                BFOO(B3SOIPDCbgPtr, B3SOIPDCbgBinding, B3SOIPDcbgNode, B3SOIPDcbgNode);
                BFOO(B3SOIPDQbfPtr, B3SOIPDQbfBinding, B3SOIPDqbfNode, B3SOIPDqbfNode);
                BFOO(B3SOIPDQjsPtr, B3SOIPDQjsBinding, B3SOIPDqjsNode, B3SOIPDqjsNode);
                BFOO(B3SOIPDQjdPtr, B3SOIPDQjdBinding, B3SOIPDqjdNode, B3SOIPDqjdNode);
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
                CFOO(B3SOIPDTemptempPtr, B3SOIPDTemptempBinding, B3SOIPDtempNode, B3SOIPDtempNode);
                CFOO(B3SOIPDTempdpPtr, B3SOIPDTempdpBinding, B3SOIPDtempNode, B3SOIPDdNodePrime);
                CFOO(B3SOIPDTempspPtr, B3SOIPDTempspBinding, B3SOIPDtempNode, B3SOIPDsNodePrime);
                CFOO(B3SOIPDTempgPtr, B3SOIPDTempgBinding, B3SOIPDtempNode, B3SOIPDgNode);
                CFOO(B3SOIPDTempbPtr, B3SOIPDTempbBinding, B3SOIPDtempNode, B3SOIPDbNode);
                CFOO(B3SOIPDGtempPtr, B3SOIPDGtempBinding, B3SOIPDgNode, B3SOIPDtempNode);
                CFOO(B3SOIPDDPtempPtr, B3SOIPDDPtempBinding, B3SOIPDdNodePrime, B3SOIPDtempNode);
                CFOO(B3SOIPDSPtempPtr, B3SOIPDSPtempBinding, B3SOIPDsNodePrime, B3SOIPDtempNode);
                CFOO(B3SOIPDEtempPtr, B3SOIPDEtempBinding, B3SOIPDeNode, B3SOIPDtempNode);
                CFOO(B3SOIPDBtempPtr, B3SOIPDBtempBinding, B3SOIPDbNode, B3SOIPDtempNode);
                if (here->B3SOIPDbodyMod == 1)
                {
                    CFOO(B3SOIPDPtempPtr, B3SOIPDPtempBinding, B3SOIPDpNode, B3SOIPDtempNode);
                }
            }
            if (here->B3SOIPDbodyMod == 2)
            {
            }
            else if (here->B3SOIPDbodyMod == 1)
            {
                CFOO(B3SOIPDBpPtr, B3SOIPDBpBinding, B3SOIPDbNode, B3SOIPDpNode);
                CFOO(B3SOIPDPbPtr, B3SOIPDPbBinding, B3SOIPDpNode, B3SOIPDbNode);
                CFOO(B3SOIPDPpPtr, B3SOIPDPpBinding, B3SOIPDpNode, B3SOIPDpNode);
            }
            CFOO(B3SOIPDEbPtr, B3SOIPDEbBinding, B3SOIPDeNode, B3SOIPDbNode);
            CFOO(B3SOIPDGbPtr, B3SOIPDGbBinding, B3SOIPDgNode, B3SOIPDbNode);
            CFOO(B3SOIPDDPbPtr, B3SOIPDDPbBinding, B3SOIPDdNodePrime, B3SOIPDbNode);
            CFOO(B3SOIPDSPbPtr, B3SOIPDSPbBinding, B3SOIPDsNodePrime, B3SOIPDbNode);
            CFOO(B3SOIPDBePtr, B3SOIPDBeBinding, B3SOIPDbNode, B3SOIPDeNode);
            CFOO(B3SOIPDBgPtr, B3SOIPDBgBinding, B3SOIPDbNode, B3SOIPDgNode);
            CFOO(B3SOIPDBdpPtr, B3SOIPDBdpBinding, B3SOIPDbNode, B3SOIPDdNodePrime);
            CFOO(B3SOIPDBspPtr, B3SOIPDBspBinding, B3SOIPDbNode, B3SOIPDsNodePrime);
            CFOO(B3SOIPDBbPtr, B3SOIPDBbBinding, B3SOIPDbNode, B3SOIPDbNode);
            CFOO(B3SOIPDEgPtr, B3SOIPDEgBinding, B3SOIPDeNode, B3SOIPDgNode);
            CFOO(B3SOIPDEdpPtr, B3SOIPDEdpBinding, B3SOIPDeNode, B3SOIPDdNodePrime);
            CFOO(B3SOIPDEspPtr, B3SOIPDEspBinding, B3SOIPDeNode, B3SOIPDsNodePrime);
            CFOO(B3SOIPDGePtr, B3SOIPDGeBinding, B3SOIPDgNode, B3SOIPDeNode);
            CFOO(B3SOIPDDPePtr, B3SOIPDDPeBinding, B3SOIPDdNodePrime, B3SOIPDeNode);
            CFOO(B3SOIPDSPePtr, B3SOIPDSPeBinding, B3SOIPDsNodePrime, B3SOIPDeNode);
            CFOO(B3SOIPDEePtr, B3SOIPDEeBinding, B3SOIPDeNode, B3SOIPDeNode);
            CFOO(B3SOIPDGgPtr, B3SOIPDGgBinding, B3SOIPDgNode, B3SOIPDgNode);
            CFOO(B3SOIPDGdpPtr, B3SOIPDGdpBinding, B3SOIPDgNode, B3SOIPDdNodePrime);
            CFOO(B3SOIPDGspPtr, B3SOIPDGspBinding, B3SOIPDgNode, B3SOIPDsNodePrime);
            CFOO(B3SOIPDDPgPtr, B3SOIPDDPgBinding, B3SOIPDdNodePrime, B3SOIPDgNode);
            CFOO(B3SOIPDDPdpPtr, B3SOIPDDPdpBinding, B3SOIPDdNodePrime, B3SOIPDdNodePrime);
            CFOO(B3SOIPDDPspPtr, B3SOIPDDPspBinding, B3SOIPDdNodePrime, B3SOIPDsNodePrime);
            CFOO(B3SOIPDDPdPtr, B3SOIPDDPdBinding, B3SOIPDdNodePrime, B3SOIPDdNode);
            CFOO(B3SOIPDSPgPtr, B3SOIPDSPgBinding, B3SOIPDsNodePrime, B3SOIPDgNode);
            CFOO(B3SOIPDSPdpPtr, B3SOIPDSPdpBinding, B3SOIPDsNodePrime, B3SOIPDdNodePrime);
            CFOO(B3SOIPDSPspPtr, B3SOIPDSPspBinding, B3SOIPDsNodePrime, B3SOIPDsNodePrime);
            CFOO(B3SOIPDSPsPtr, B3SOIPDSPsBinding, B3SOIPDsNodePrime, B3SOIPDsNode);
            CFOO(B3SOIPDDdPtr, B3SOIPDDdBinding, B3SOIPDdNode, B3SOIPDdNode);
            CFOO(B3SOIPDDdpPtr, B3SOIPDDdpBinding, B3SOIPDdNode, B3SOIPDdNodePrime);
            CFOO(B3SOIPDSsPtr, B3SOIPDSsBinding, B3SOIPDsNode, B3SOIPDsNode);
            CFOO(B3SOIPDSspPtr, B3SOIPDSspBinding, B3SOIPDsNode, B3SOIPDsNodePrime);
            if (here->B3SOIPDdebugMod != 0)
            {
                CFOO(B3SOIPDVbsPtr, B3SOIPDVbsBinding, B3SOIPDvbsNode, B3SOIPDvbsNode);
                CFOO(B3SOIPDIdsPtr, B3SOIPDIdsBinding, B3SOIPDidsNode, B3SOIPDidsNode);
                CFOO(B3SOIPDIcPtr, B3SOIPDIcBinding, B3SOIPDicNode, B3SOIPDicNode);
                CFOO(B3SOIPDIbsPtr, B3SOIPDIbsBinding, B3SOIPDibsNode, B3SOIPDibsNode);
                CFOO(B3SOIPDIbdPtr, B3SOIPDIbdBinding, B3SOIPDibdNode, B3SOIPDibdNode);
                CFOO(B3SOIPDIiiPtr, B3SOIPDIiiBinding, B3SOIPDiiiNode, B3SOIPDiiiNode);
                CFOO(B3SOIPDIgPtr, B3SOIPDIgBinding, B3SOIPDigNode, B3SOIPDigNode);
                CFOO(B3SOIPDGiggPtr, B3SOIPDGiggBinding, B3SOIPDgiggNode, B3SOIPDgiggNode);
                CFOO(B3SOIPDGigdPtr, B3SOIPDGigdBinding, B3SOIPDgigdNode, B3SOIPDgigdNode);
                CFOO(B3SOIPDGigbPtr, B3SOIPDGigbBinding, B3SOIPDgigbNode, B3SOIPDgigbNode);
                CFOO(B3SOIPDIgidlPtr, B3SOIPDIgidlBinding, B3SOIPDigidlNode, B3SOIPDigidlNode);
                CFOO(B3SOIPDItunPtr, B3SOIPDItunBinding, B3SOIPDitunNode, B3SOIPDitunNode);
                CFOO(B3SOIPDIbpPtr, B3SOIPDIbpBinding, B3SOIPDibpNode, B3SOIPDibpNode);
                CFOO(B3SOIPDCbbPtr, B3SOIPDCbbBinding, B3SOIPDcbbNode, B3SOIPDcbbNode);
                CFOO(B3SOIPDCbdPtr, B3SOIPDCbdBinding, B3SOIPDcbdNode, B3SOIPDcbdNode);
                CFOO(B3SOIPDCbgPtr, B3SOIPDCbgBinding, B3SOIPDcbgNode, B3SOIPDcbgNode);
                CFOO(B3SOIPDQbfPtr, B3SOIPDQbfBinding, B3SOIPDqbfNode, B3SOIPDqbfNode);
                CFOO(B3SOIPDQjsPtr, B3SOIPDQjsBinding, B3SOIPDqjsNode, B3SOIPDqjsNode);
                CFOO(B3SOIPDQjdPtr, B3SOIPDQjdBinding, B3SOIPDqjdNode, B3SOIPDqjdNode);
            }
        }
    }

    return (OK) ;
}
