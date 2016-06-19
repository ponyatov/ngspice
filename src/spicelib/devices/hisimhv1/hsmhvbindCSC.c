/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "hsmhvdef.h"
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
HSMHVbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    HSMHVmodel *model = (HSMHVmodel *)inModel ;
    HSMHVinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the HSMHV models */
    for ( ; model != NULL ; model = model->HSMHVnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HSMHVinstances ; here != NULL ; here = here->HSMHVnextInstance)
        {
            XFOO(HSMHVDPbpPtr, HSMHVDPbpBinding, HSMHVdNodePrime, HSMHVbNodePrime);
            XFOO(HSMHVSPbpPtr, HSMHVSPbpBinding, HSMHVsNodePrime, HSMHVbNodePrime);
            XFOO(HSMHVGPbpPtr, HSMHVGPbpBinding, HSMHVgNodePrime, HSMHVbNodePrime);
            XFOO(HSMHVBPdPtr, HSMHVBPdBinding, HSMHVbNodePrime, HSMHVdNode);
            XFOO(HSMHVBPsPtr, HSMHVBPsBinding, HSMHVbNodePrime, HSMHVsNode);
            XFOO(HSMHVBPdpPtr, HSMHVBPdpBinding, HSMHVbNodePrime, HSMHVdNodePrime);
            XFOO(HSMHVBPspPtr, HSMHVBPspBinding, HSMHVbNodePrime, HSMHVsNodePrime);
            XFOO(HSMHVBPgpPtr, HSMHVBPgpBinding, HSMHVbNodePrime, HSMHVgNodePrime);
            XFOO(HSMHVBPbpPtr, HSMHVBPbpBinding, HSMHVbNodePrime, HSMHVbNodePrime);
            XFOO(HSMHVDdPtr, HSMHVDdBinding, HSMHVdNode, HSMHVdNode);
            XFOO(HSMHVGPgpPtr, HSMHVGPgpBinding, HSMHVgNodePrime, HSMHVgNodePrime);
            XFOO(HSMHVSsPtr, HSMHVSsBinding, HSMHVsNode, HSMHVsNode);
            XFOO(HSMHVDPdpPtr, HSMHVDPdpBinding, HSMHVdNodePrime, HSMHVdNodePrime);
            XFOO(HSMHVSPspPtr, HSMHVSPspBinding, HSMHVsNodePrime, HSMHVsNodePrime);
            XFOO(HSMHVDdpPtr, HSMHVDdpBinding, HSMHVdNode, HSMHVdNodePrime);
            XFOO(HSMHVGPdpPtr, HSMHVGPdpBinding, HSMHVgNodePrime, HSMHVdNodePrime);
            XFOO(HSMHVGPspPtr, HSMHVGPspBinding, HSMHVgNodePrime, HSMHVsNodePrime);
            XFOO(HSMHVSspPtr, HSMHVSspBinding, HSMHVsNode, HSMHVsNodePrime);
            XFOO(HSMHVDPspPtr, HSMHVDPspBinding, HSMHVdNodePrime, HSMHVsNodePrime);
            XFOO(HSMHVDPdPtr, HSMHVDPdBinding, HSMHVdNodePrime, HSMHVdNode);
            XFOO(HSMHVDPgpPtr, HSMHVDPgpBinding, HSMHVdNodePrime, HSMHVgNodePrime);
            XFOO(HSMHVSPgpPtr, HSMHVSPgpBinding, HSMHVsNodePrime, HSMHVgNodePrime);
            XFOO(HSMHVSPsPtr, HSMHVSPsBinding, HSMHVsNodePrime, HSMHVsNode);
            XFOO(HSMHVSPdpPtr, HSMHVSPdpBinding, HSMHVsNodePrime, HSMHVdNodePrime);
            XFOO(HSMHVGgPtr, HSMHVGgBinding, HSMHVgNode, HSMHVgNode);
            XFOO(HSMHVGgpPtr, HSMHVGgpBinding, HSMHVgNode, HSMHVgNodePrime);
            XFOO(HSMHVGPgPtr, HSMHVGPgBinding, HSMHVgNodePrime, HSMHVgNode);
            XFOO(HSMHVDdbPtr, HSMHVDdbBinding, HSMHVdNode, HSMHVdbNode);
            XFOO(HSMHVSsbPtr, HSMHVSsbBinding, HSMHVsNode, HSMHVsbNode);
            XFOO(HSMHVDBdPtr, HSMHVDBdBinding, HSMHVdbNode, HSMHVdNode);
            XFOO(HSMHVDBdbPtr, HSMHVDBdbBinding, HSMHVdbNode, HSMHVdbNode);
            XFOO(HSMHVDBbpPtr, HSMHVDBbpBinding, HSMHVdbNode, HSMHVbNodePrime);
            XFOO(HSMHVBPdbPtr, HSMHVBPdbBinding, HSMHVbNodePrime, HSMHVdbNode);
            XFOO(HSMHVBPbPtr, HSMHVBPbBinding, HSMHVbNodePrime, HSMHVbNode);
            XFOO(HSMHVBPsbPtr, HSMHVBPsbBinding, HSMHVbNodePrime, HSMHVsbNode);
            XFOO(HSMHVSBsPtr, HSMHVSBsBinding, HSMHVsbNode, HSMHVsNode);
            XFOO(HSMHVSBbpPtr, HSMHVSBbpBinding, HSMHVsbNode, HSMHVbNodePrime);
            XFOO(HSMHVSBsbPtr, HSMHVSBsbBinding, HSMHVsbNode, HSMHVsbNode);
            XFOO(HSMHVBbpPtr, HSMHVBbpBinding, HSMHVbNode, HSMHVbNodePrime);
            XFOO(HSMHVBbPtr, HSMHVBbBinding, HSMHVbNode, HSMHVbNode);
            XFOO(HSMHVDgpPtr, HSMHVDgpBinding, HSMHVdNode, HSMHVgNodePrime);
            XFOO(HSMHVDsPtr, HSMHVDsBinding, HSMHVdNode, HSMHVsNode);
            XFOO(HSMHVDbpPtr, HSMHVDbpBinding, HSMHVdNode, HSMHVbNodePrime);
            XFOO(HSMHVDspPtr, HSMHVDspBinding, HSMHVdNode, HSMHVsNodePrime);
            XFOO(HSMHVDPsPtr, HSMHVDPsBinding, HSMHVdNodePrime, HSMHVsNode);
            XFOO(HSMHVSgpPtr, HSMHVSgpBinding, HSMHVsNode, HSMHVgNodePrime);
            XFOO(HSMHVSdPtr, HSMHVSdBinding, HSMHVsNode, HSMHVdNode);
            XFOO(HSMHVSbpPtr, HSMHVSbpBinding, HSMHVsNode, HSMHVbNodePrime);
            XFOO(HSMHVSdpPtr, HSMHVSdpBinding, HSMHVsNode, HSMHVdNodePrime);
            XFOO(HSMHVSPdPtr, HSMHVSPdBinding, HSMHVsNodePrime, HSMHVdNode);
            XFOO(HSMHVGPdPtr, HSMHVGPdBinding, HSMHVgNodePrime, HSMHVdNode);
            XFOO(HSMHVGPsPtr, HSMHVGPsBinding, HSMHVgNodePrime, HSMHVsNode);
            if (here->HSMHVsubNode > 0)
            {
                XFOO(HSMHVDsubPtr, HSMHVDsubBinding, HSMHVdNode, HSMHVsubNode);
                XFOO(HSMHVDPsubPtr, HSMHVDPsubBinding, HSMHVdNodePrime, HSMHVsubNode);
                XFOO(HSMHVSsubPtr, HSMHVSsubBinding, HSMHVsNode, HSMHVsubNode);
                XFOO(HSMHVSPsubPtr, HSMHVSPsubBinding, HSMHVsNodePrime, HSMHVsubNode);
            }
            if (here->HSMHV_coselfheat > 0)
            {
                XFOO(HSMHVTemptempPtr, HSMHVTemptempBinding, HSMHVtempNode, HSMHVtempNode);
                XFOO(HSMHVTempdPtr, HSMHVTempdBinding, HSMHVtempNode, HSMHVdNode);
                XFOO(HSMHVTempdpPtr, HSMHVTempdpBinding, HSMHVtempNode, HSMHVdNodePrime);
                XFOO(HSMHVTempsPtr, HSMHVTempsBinding, HSMHVtempNode, HSMHVsNode);
                XFOO(HSMHVTempspPtr, HSMHVTempspBinding, HSMHVtempNode, HSMHVsNodePrime);
                XFOO(HSMHVDPtempPtr, HSMHVDPtempBinding, HSMHVdNodePrime, HSMHVtempNode);
                XFOO(HSMHVSPtempPtr, HSMHVSPtempBinding, HSMHVsNodePrime, HSMHVtempNode);
                XFOO(HSMHVTempgpPtr, HSMHVTempgpBinding, HSMHVtempNode, HSMHVgNodePrime);
                XFOO(HSMHVTempbpPtr, HSMHVTempbpBinding, HSMHVtempNode, HSMHVbNodePrime);
                XFOO(HSMHVGPtempPtr, HSMHVGPtempBinding, HSMHVgNodePrime, HSMHVtempNode);
                XFOO(HSMHVBPtempPtr, HSMHVBPtempBinding, HSMHVbNodePrime, HSMHVtempNode);
                XFOO(HSMHVDBtempPtr, HSMHVDBtempBinding, HSMHVdbNode, HSMHVtempNode);
                XFOO(HSMHVSBtempPtr, HSMHVSBtempBinding, HSMHVsbNode, HSMHVtempNode);
                XFOO(HSMHVDtempPtr, HSMHVDtempBinding, HSMHVdNode, HSMHVtempNode);
                XFOO(HSMHVStempPtr, HSMHVStempBinding, HSMHVsNode, HSMHVtempNode);
            }
            if (model->HSMHV_conqs)
            {
                XFOO(HSMHVDPqiPtr, HSMHVDPqiBinding, HSMHVdNodePrime, HSMHVqiNode);
                XFOO(HSMHVGPqiPtr, HSMHVGPqiBinding, HSMHVgNodePrime, HSMHVqiNode);
                XFOO(HSMHVGPqbPtr, HSMHVGPqbBinding, HSMHVgNodePrime, HSMHVqbNode);
                XFOO(HSMHVSPqiPtr, HSMHVSPqiBinding, HSMHVsNodePrime, HSMHVqiNode);
                XFOO(HSMHVBPqbPtr, HSMHVBPqbBinding, HSMHVbNodePrime, HSMHVqbNode);
                XFOO(HSMHVQIdpPtr, HSMHVQIdpBinding, HSMHVqiNode, HSMHVdNodePrime);
                XFOO(HSMHVQIgpPtr, HSMHVQIgpBinding, HSMHVqiNode, HSMHVgNodePrime);
                XFOO(HSMHVQIspPtr, HSMHVQIspBinding, HSMHVqiNode, HSMHVsNodePrime);
                XFOO(HSMHVQIbpPtr, HSMHVQIbpBinding, HSMHVqiNode, HSMHVbNodePrime);
                XFOO(HSMHVQIqiPtr, HSMHVQIqiBinding, HSMHVqiNode, HSMHVqiNode);
                XFOO(HSMHVQBdpPtr, HSMHVQBdpBinding, HSMHVqbNode, HSMHVdNodePrime);
                XFOO(HSMHVQBgpPtr, HSMHVQBgpBinding, HSMHVqbNode, HSMHVgNodePrime);
                XFOO(HSMHVQBspPtr, HSMHVQBspBinding, HSMHVqbNode, HSMHVsNodePrime);
                XFOO(HSMHVQBbpPtr, HSMHVQBbpBinding, HSMHVqbNode, HSMHVbNodePrime);
                XFOO(HSMHVQBqbPtr, HSMHVQBqbBinding, HSMHVqbNode, HSMHVqbNode);
                if (here->HSMHV_coselfheat > 0)
                {
                    XFOO(HSMHVQItempPtr, HSMHVQItempBinding, HSMHVqiNode, HSMHVtempNode);
                    XFOO(HSMHVQBtempPtr, HSMHVQBtempBinding, HSMHVqbNode, HSMHVtempNode);
                }
            }
        }
    }

    return (OK) ;
}

int
HSMHVbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    HSMHVmodel *model = (HSMHVmodel *)inModel ;
    HSMHVinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HSMHV models */
    for ( ; model != NULL ; model = model->HSMHVnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HSMHVinstances ; here != NULL ; here = here->HSMHVnextInstance)
        {
            BFOO(HSMHVDPbpPtr, HSMHVDPbpBinding, HSMHVdNodePrime, HSMHVbNodePrime);
            BFOO(HSMHVSPbpPtr, HSMHVSPbpBinding, HSMHVsNodePrime, HSMHVbNodePrime);
            BFOO(HSMHVGPbpPtr, HSMHVGPbpBinding, HSMHVgNodePrime, HSMHVbNodePrime);
            BFOO(HSMHVBPdPtr, HSMHVBPdBinding, HSMHVbNodePrime, HSMHVdNode);
            BFOO(HSMHVBPsPtr, HSMHVBPsBinding, HSMHVbNodePrime, HSMHVsNode);
            BFOO(HSMHVBPdpPtr, HSMHVBPdpBinding, HSMHVbNodePrime, HSMHVdNodePrime);
            BFOO(HSMHVBPspPtr, HSMHVBPspBinding, HSMHVbNodePrime, HSMHVsNodePrime);
            BFOO(HSMHVBPgpPtr, HSMHVBPgpBinding, HSMHVbNodePrime, HSMHVgNodePrime);
            BFOO(HSMHVBPbpPtr, HSMHVBPbpBinding, HSMHVbNodePrime, HSMHVbNodePrime);
            BFOO(HSMHVDdPtr, HSMHVDdBinding, HSMHVdNode, HSMHVdNode);
            BFOO(HSMHVGPgpPtr, HSMHVGPgpBinding, HSMHVgNodePrime, HSMHVgNodePrime);
            BFOO(HSMHVSsPtr, HSMHVSsBinding, HSMHVsNode, HSMHVsNode);
            BFOO(HSMHVDPdpPtr, HSMHVDPdpBinding, HSMHVdNodePrime, HSMHVdNodePrime);
            BFOO(HSMHVSPspPtr, HSMHVSPspBinding, HSMHVsNodePrime, HSMHVsNodePrime);
            BFOO(HSMHVDdpPtr, HSMHVDdpBinding, HSMHVdNode, HSMHVdNodePrime);
            BFOO(HSMHVGPdpPtr, HSMHVGPdpBinding, HSMHVgNodePrime, HSMHVdNodePrime);
            BFOO(HSMHVGPspPtr, HSMHVGPspBinding, HSMHVgNodePrime, HSMHVsNodePrime);
            BFOO(HSMHVSspPtr, HSMHVSspBinding, HSMHVsNode, HSMHVsNodePrime);
            BFOO(HSMHVDPspPtr, HSMHVDPspBinding, HSMHVdNodePrime, HSMHVsNodePrime);
            BFOO(HSMHVDPdPtr, HSMHVDPdBinding, HSMHVdNodePrime, HSMHVdNode);
            BFOO(HSMHVDPgpPtr, HSMHVDPgpBinding, HSMHVdNodePrime, HSMHVgNodePrime);
            BFOO(HSMHVSPgpPtr, HSMHVSPgpBinding, HSMHVsNodePrime, HSMHVgNodePrime);
            BFOO(HSMHVSPsPtr, HSMHVSPsBinding, HSMHVsNodePrime, HSMHVsNode);
            BFOO(HSMHVSPdpPtr, HSMHVSPdpBinding, HSMHVsNodePrime, HSMHVdNodePrime);
            BFOO(HSMHVGgPtr, HSMHVGgBinding, HSMHVgNode, HSMHVgNode);
            BFOO(HSMHVGgpPtr, HSMHVGgpBinding, HSMHVgNode, HSMHVgNodePrime);
            BFOO(HSMHVGPgPtr, HSMHVGPgBinding, HSMHVgNodePrime, HSMHVgNode);
            BFOO(HSMHVDdbPtr, HSMHVDdbBinding, HSMHVdNode, HSMHVdbNode);
            BFOO(HSMHVSsbPtr, HSMHVSsbBinding, HSMHVsNode, HSMHVsbNode);
            BFOO(HSMHVDBdPtr, HSMHVDBdBinding, HSMHVdbNode, HSMHVdNode);
            BFOO(HSMHVDBdbPtr, HSMHVDBdbBinding, HSMHVdbNode, HSMHVdbNode);
            BFOO(HSMHVDBbpPtr, HSMHVDBbpBinding, HSMHVdbNode, HSMHVbNodePrime);
            BFOO(HSMHVBPdbPtr, HSMHVBPdbBinding, HSMHVbNodePrime, HSMHVdbNode);
            BFOO(HSMHVBPbPtr, HSMHVBPbBinding, HSMHVbNodePrime, HSMHVbNode);
            BFOO(HSMHVBPsbPtr, HSMHVBPsbBinding, HSMHVbNodePrime, HSMHVsbNode);
            BFOO(HSMHVSBsPtr, HSMHVSBsBinding, HSMHVsbNode, HSMHVsNode);
            BFOO(HSMHVSBbpPtr, HSMHVSBbpBinding, HSMHVsbNode, HSMHVbNodePrime);
            BFOO(HSMHVSBsbPtr, HSMHVSBsbBinding, HSMHVsbNode, HSMHVsbNode);
            BFOO(HSMHVBbpPtr, HSMHVBbpBinding, HSMHVbNode, HSMHVbNodePrime);
            BFOO(HSMHVBbPtr, HSMHVBbBinding, HSMHVbNode, HSMHVbNode);
            BFOO(HSMHVDgpPtr, HSMHVDgpBinding, HSMHVdNode, HSMHVgNodePrime);
            BFOO(HSMHVDsPtr, HSMHVDsBinding, HSMHVdNode, HSMHVsNode);
            BFOO(HSMHVDbpPtr, HSMHVDbpBinding, HSMHVdNode, HSMHVbNodePrime);
            BFOO(HSMHVDspPtr, HSMHVDspBinding, HSMHVdNode, HSMHVsNodePrime);
            BFOO(HSMHVDPsPtr, HSMHVDPsBinding, HSMHVdNodePrime, HSMHVsNode);
            BFOO(HSMHVSgpPtr, HSMHVSgpBinding, HSMHVsNode, HSMHVgNodePrime);
            BFOO(HSMHVSdPtr, HSMHVSdBinding, HSMHVsNode, HSMHVdNode);
            BFOO(HSMHVSbpPtr, HSMHVSbpBinding, HSMHVsNode, HSMHVbNodePrime);
            BFOO(HSMHVSdpPtr, HSMHVSdpBinding, HSMHVsNode, HSMHVdNodePrime);
            BFOO(HSMHVSPdPtr, HSMHVSPdBinding, HSMHVsNodePrime, HSMHVdNode);
            BFOO(HSMHVGPdPtr, HSMHVGPdBinding, HSMHVgNodePrime, HSMHVdNode);
            BFOO(HSMHVGPsPtr, HSMHVGPsBinding, HSMHVgNodePrime, HSMHVsNode);
            if (here->HSMHVsubNode > 0)
            {
                BFOO(HSMHVDsubPtr, HSMHVDsubBinding, HSMHVdNode, HSMHVsubNode);
                BFOO(HSMHVDPsubPtr, HSMHVDPsubBinding, HSMHVdNodePrime, HSMHVsubNode);
                BFOO(HSMHVSsubPtr, HSMHVSsubBinding, HSMHVsNode, HSMHVsubNode);
                BFOO(HSMHVSPsubPtr, HSMHVSPsubBinding, HSMHVsNodePrime, HSMHVsubNode);
            }
            if (here->HSMHV_coselfheat > 0)
            {
                BFOO(HSMHVTemptempPtr, HSMHVTemptempBinding, HSMHVtempNode, HSMHVtempNode);
                BFOO(HSMHVTempdPtr, HSMHVTempdBinding, HSMHVtempNode, HSMHVdNode);
                BFOO(HSMHVTempdpPtr, HSMHVTempdpBinding, HSMHVtempNode, HSMHVdNodePrime);
                BFOO(HSMHVTempsPtr, HSMHVTempsBinding, HSMHVtempNode, HSMHVsNode);
                BFOO(HSMHVTempspPtr, HSMHVTempspBinding, HSMHVtempNode, HSMHVsNodePrime);
                BFOO(HSMHVDPtempPtr, HSMHVDPtempBinding, HSMHVdNodePrime, HSMHVtempNode);
                BFOO(HSMHVSPtempPtr, HSMHVSPtempBinding, HSMHVsNodePrime, HSMHVtempNode);
                BFOO(HSMHVTempgpPtr, HSMHVTempgpBinding, HSMHVtempNode, HSMHVgNodePrime);
                BFOO(HSMHVTempbpPtr, HSMHVTempbpBinding, HSMHVtempNode, HSMHVbNodePrime);
                BFOO(HSMHVGPtempPtr, HSMHVGPtempBinding, HSMHVgNodePrime, HSMHVtempNode);
                BFOO(HSMHVBPtempPtr, HSMHVBPtempBinding, HSMHVbNodePrime, HSMHVtempNode);
                BFOO(HSMHVDBtempPtr, HSMHVDBtempBinding, HSMHVdbNode, HSMHVtempNode);
                BFOO(HSMHVSBtempPtr, HSMHVSBtempBinding, HSMHVsbNode, HSMHVtempNode);
                BFOO(HSMHVDtempPtr, HSMHVDtempBinding, HSMHVdNode, HSMHVtempNode);
                BFOO(HSMHVStempPtr, HSMHVStempBinding, HSMHVsNode, HSMHVtempNode);
            }
            if (model->HSMHV_conqs)
            {
                BFOO(HSMHVDPqiPtr, HSMHVDPqiBinding, HSMHVdNodePrime, HSMHVqiNode);
                BFOO(HSMHVGPqiPtr, HSMHVGPqiBinding, HSMHVgNodePrime, HSMHVqiNode);
                BFOO(HSMHVGPqbPtr, HSMHVGPqbBinding, HSMHVgNodePrime, HSMHVqbNode);
                BFOO(HSMHVSPqiPtr, HSMHVSPqiBinding, HSMHVsNodePrime, HSMHVqiNode);
                BFOO(HSMHVBPqbPtr, HSMHVBPqbBinding, HSMHVbNodePrime, HSMHVqbNode);
                BFOO(HSMHVQIdpPtr, HSMHVQIdpBinding, HSMHVqiNode, HSMHVdNodePrime);
                BFOO(HSMHVQIgpPtr, HSMHVQIgpBinding, HSMHVqiNode, HSMHVgNodePrime);
                BFOO(HSMHVQIspPtr, HSMHVQIspBinding, HSMHVqiNode, HSMHVsNodePrime);
                BFOO(HSMHVQIbpPtr, HSMHVQIbpBinding, HSMHVqiNode, HSMHVbNodePrime);
                BFOO(HSMHVQIqiPtr, HSMHVQIqiBinding, HSMHVqiNode, HSMHVqiNode);
                BFOO(HSMHVQBdpPtr, HSMHVQBdpBinding, HSMHVqbNode, HSMHVdNodePrime);
                BFOO(HSMHVQBgpPtr, HSMHVQBgpBinding, HSMHVqbNode, HSMHVgNodePrime);
                BFOO(HSMHVQBspPtr, HSMHVQBspBinding, HSMHVqbNode, HSMHVsNodePrime);
                BFOO(HSMHVQBbpPtr, HSMHVQBbpBinding, HSMHVqbNode, HSMHVbNodePrime);
                BFOO(HSMHVQBqbPtr, HSMHVQBqbBinding, HSMHVqbNode, HSMHVqbNode);
                if (here->HSMHV_coselfheat > 0)
                {
                    BFOO(HSMHVQItempPtr, HSMHVQItempBinding, HSMHVqiNode, HSMHVtempNode);
                    BFOO(HSMHVQBtempPtr, HSMHVQBtempBinding, HSMHVqbNode, HSMHVtempNode);
                }
            }
        }
    }

    return (OK) ;
}

int
HSMHVbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    HSMHVmodel *model = (HSMHVmodel *)inModel ;
    HSMHVinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the HSMHV models */
    for ( ; model != NULL ; model = model->HSMHVnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->HSMHVinstances ; here != NULL ; here = here->HSMHVnextInstance)
        {
            CFOO(HSMHVDPbpPtr, HSMHVDPbpBinding, HSMHVdNodePrime, HSMHVbNodePrime);
            CFOO(HSMHVSPbpPtr, HSMHVSPbpBinding, HSMHVsNodePrime, HSMHVbNodePrime);
            CFOO(HSMHVGPbpPtr, HSMHVGPbpBinding, HSMHVgNodePrime, HSMHVbNodePrime);
            CFOO(HSMHVBPdPtr, HSMHVBPdBinding, HSMHVbNodePrime, HSMHVdNode);
            CFOO(HSMHVBPsPtr, HSMHVBPsBinding, HSMHVbNodePrime, HSMHVsNode);
            CFOO(HSMHVBPdpPtr, HSMHVBPdpBinding, HSMHVbNodePrime, HSMHVdNodePrime);
            CFOO(HSMHVBPspPtr, HSMHVBPspBinding, HSMHVbNodePrime, HSMHVsNodePrime);
            CFOO(HSMHVBPgpPtr, HSMHVBPgpBinding, HSMHVbNodePrime, HSMHVgNodePrime);
            CFOO(HSMHVBPbpPtr, HSMHVBPbpBinding, HSMHVbNodePrime, HSMHVbNodePrime);
            CFOO(HSMHVDdPtr, HSMHVDdBinding, HSMHVdNode, HSMHVdNode);
            CFOO(HSMHVGPgpPtr, HSMHVGPgpBinding, HSMHVgNodePrime, HSMHVgNodePrime);
            CFOO(HSMHVSsPtr, HSMHVSsBinding, HSMHVsNode, HSMHVsNode);
            CFOO(HSMHVDPdpPtr, HSMHVDPdpBinding, HSMHVdNodePrime, HSMHVdNodePrime);
            CFOO(HSMHVSPspPtr, HSMHVSPspBinding, HSMHVsNodePrime, HSMHVsNodePrime);
            CFOO(HSMHVDdpPtr, HSMHVDdpBinding, HSMHVdNode, HSMHVdNodePrime);
            CFOO(HSMHVGPdpPtr, HSMHVGPdpBinding, HSMHVgNodePrime, HSMHVdNodePrime);
            CFOO(HSMHVGPspPtr, HSMHVGPspBinding, HSMHVgNodePrime, HSMHVsNodePrime);
            CFOO(HSMHVSspPtr, HSMHVSspBinding, HSMHVsNode, HSMHVsNodePrime);
            CFOO(HSMHVDPspPtr, HSMHVDPspBinding, HSMHVdNodePrime, HSMHVsNodePrime);
            CFOO(HSMHVDPdPtr, HSMHVDPdBinding, HSMHVdNodePrime, HSMHVdNode);
            CFOO(HSMHVDPgpPtr, HSMHVDPgpBinding, HSMHVdNodePrime, HSMHVgNodePrime);
            CFOO(HSMHVSPgpPtr, HSMHVSPgpBinding, HSMHVsNodePrime, HSMHVgNodePrime);
            CFOO(HSMHVSPsPtr, HSMHVSPsBinding, HSMHVsNodePrime, HSMHVsNode);
            CFOO(HSMHVSPdpPtr, HSMHVSPdpBinding, HSMHVsNodePrime, HSMHVdNodePrime);
            CFOO(HSMHVGgPtr, HSMHVGgBinding, HSMHVgNode, HSMHVgNode);
            CFOO(HSMHVGgpPtr, HSMHVGgpBinding, HSMHVgNode, HSMHVgNodePrime);
            CFOO(HSMHVGPgPtr, HSMHVGPgBinding, HSMHVgNodePrime, HSMHVgNode);
            CFOO(HSMHVDdbPtr, HSMHVDdbBinding, HSMHVdNode, HSMHVdbNode);
            CFOO(HSMHVSsbPtr, HSMHVSsbBinding, HSMHVsNode, HSMHVsbNode);
            CFOO(HSMHVDBdPtr, HSMHVDBdBinding, HSMHVdbNode, HSMHVdNode);
            CFOO(HSMHVDBdbPtr, HSMHVDBdbBinding, HSMHVdbNode, HSMHVdbNode);
            CFOO(HSMHVDBbpPtr, HSMHVDBbpBinding, HSMHVdbNode, HSMHVbNodePrime);
            CFOO(HSMHVBPdbPtr, HSMHVBPdbBinding, HSMHVbNodePrime, HSMHVdbNode);
            CFOO(HSMHVBPbPtr, HSMHVBPbBinding, HSMHVbNodePrime, HSMHVbNode);
            CFOO(HSMHVBPsbPtr, HSMHVBPsbBinding, HSMHVbNodePrime, HSMHVsbNode);
            CFOO(HSMHVSBsPtr, HSMHVSBsBinding, HSMHVsbNode, HSMHVsNode);
            CFOO(HSMHVSBbpPtr, HSMHVSBbpBinding, HSMHVsbNode, HSMHVbNodePrime);
            CFOO(HSMHVSBsbPtr, HSMHVSBsbBinding, HSMHVsbNode, HSMHVsbNode);
            CFOO(HSMHVBbpPtr, HSMHVBbpBinding, HSMHVbNode, HSMHVbNodePrime);
            CFOO(HSMHVBbPtr, HSMHVBbBinding, HSMHVbNode, HSMHVbNode);
            CFOO(HSMHVDgpPtr, HSMHVDgpBinding, HSMHVdNode, HSMHVgNodePrime);
            CFOO(HSMHVDsPtr, HSMHVDsBinding, HSMHVdNode, HSMHVsNode);
            CFOO(HSMHVDbpPtr, HSMHVDbpBinding, HSMHVdNode, HSMHVbNodePrime);
            CFOO(HSMHVDspPtr, HSMHVDspBinding, HSMHVdNode, HSMHVsNodePrime);
            CFOO(HSMHVDPsPtr, HSMHVDPsBinding, HSMHVdNodePrime, HSMHVsNode);
            CFOO(HSMHVSgpPtr, HSMHVSgpBinding, HSMHVsNode, HSMHVgNodePrime);
            CFOO(HSMHVSdPtr, HSMHVSdBinding, HSMHVsNode, HSMHVdNode);
            CFOO(HSMHVSbpPtr, HSMHVSbpBinding, HSMHVsNode, HSMHVbNodePrime);
            CFOO(HSMHVSdpPtr, HSMHVSdpBinding, HSMHVsNode, HSMHVdNodePrime);
            CFOO(HSMHVSPdPtr, HSMHVSPdBinding, HSMHVsNodePrime, HSMHVdNode);
            CFOO(HSMHVGPdPtr, HSMHVGPdBinding, HSMHVgNodePrime, HSMHVdNode);
            CFOO(HSMHVGPsPtr, HSMHVGPsBinding, HSMHVgNodePrime, HSMHVsNode);
            if (here->HSMHVsubNode > 0)
            {
                CFOO(HSMHVDsubPtr, HSMHVDsubBinding, HSMHVdNode, HSMHVsubNode);
                CFOO(HSMHVDPsubPtr, HSMHVDPsubBinding, HSMHVdNodePrime, HSMHVsubNode);
                CFOO(HSMHVSsubPtr, HSMHVSsubBinding, HSMHVsNode, HSMHVsubNode);
                CFOO(HSMHVSPsubPtr, HSMHVSPsubBinding, HSMHVsNodePrime, HSMHVsubNode);
            }
            if (here->HSMHV_coselfheat > 0)
            {
                CFOO(HSMHVTemptempPtr, HSMHVTemptempBinding, HSMHVtempNode, HSMHVtempNode);
                CFOO(HSMHVTempdPtr, HSMHVTempdBinding, HSMHVtempNode, HSMHVdNode);
                CFOO(HSMHVTempdpPtr, HSMHVTempdpBinding, HSMHVtempNode, HSMHVdNodePrime);
                CFOO(HSMHVTempsPtr, HSMHVTempsBinding, HSMHVtempNode, HSMHVsNode);
                CFOO(HSMHVTempspPtr, HSMHVTempspBinding, HSMHVtempNode, HSMHVsNodePrime);
                CFOO(HSMHVDPtempPtr, HSMHVDPtempBinding, HSMHVdNodePrime, HSMHVtempNode);
                CFOO(HSMHVSPtempPtr, HSMHVSPtempBinding, HSMHVsNodePrime, HSMHVtempNode);
                CFOO(HSMHVTempgpPtr, HSMHVTempgpBinding, HSMHVtempNode, HSMHVgNodePrime);
                CFOO(HSMHVTempbpPtr, HSMHVTempbpBinding, HSMHVtempNode, HSMHVbNodePrime);
                CFOO(HSMHVGPtempPtr, HSMHVGPtempBinding, HSMHVgNodePrime, HSMHVtempNode);
                CFOO(HSMHVBPtempPtr, HSMHVBPtempBinding, HSMHVbNodePrime, HSMHVtempNode);
                CFOO(HSMHVDBtempPtr, HSMHVDBtempBinding, HSMHVdbNode, HSMHVtempNode);
                CFOO(HSMHVSBtempPtr, HSMHVSBtempBinding, HSMHVsbNode, HSMHVtempNode);
                CFOO(HSMHVDtempPtr, HSMHVDtempBinding, HSMHVdNode, HSMHVtempNode);
                CFOO(HSMHVStempPtr, HSMHVStempBinding, HSMHVsNode, HSMHVtempNode);
            }
            if (model->HSMHV_conqs)
            {
                CFOO(HSMHVDPqiPtr, HSMHVDPqiBinding, HSMHVdNodePrime, HSMHVqiNode);
                CFOO(HSMHVGPqiPtr, HSMHVGPqiBinding, HSMHVgNodePrime, HSMHVqiNode);
                CFOO(HSMHVGPqbPtr, HSMHVGPqbBinding, HSMHVgNodePrime, HSMHVqbNode);
                CFOO(HSMHVSPqiPtr, HSMHVSPqiBinding, HSMHVsNodePrime, HSMHVqiNode);
                CFOO(HSMHVBPqbPtr, HSMHVBPqbBinding, HSMHVbNodePrime, HSMHVqbNode);
                CFOO(HSMHVQIdpPtr, HSMHVQIdpBinding, HSMHVqiNode, HSMHVdNodePrime);
                CFOO(HSMHVQIgpPtr, HSMHVQIgpBinding, HSMHVqiNode, HSMHVgNodePrime);
                CFOO(HSMHVQIspPtr, HSMHVQIspBinding, HSMHVqiNode, HSMHVsNodePrime);
                CFOO(HSMHVQIbpPtr, HSMHVQIbpBinding, HSMHVqiNode, HSMHVbNodePrime);
                CFOO(HSMHVQIqiPtr, HSMHVQIqiBinding, HSMHVqiNode, HSMHVqiNode);
                CFOO(HSMHVQBdpPtr, HSMHVQBdpBinding, HSMHVqbNode, HSMHVdNodePrime);
                CFOO(HSMHVQBgpPtr, HSMHVQBgpBinding, HSMHVqbNode, HSMHVgNodePrime);
                CFOO(HSMHVQBspPtr, HSMHVQBspBinding, HSMHVqbNode, HSMHVsNodePrime);
                CFOO(HSMHVQBbpPtr, HSMHVQBbpBinding, HSMHVqbNode, HSMHVbNodePrime);
                CFOO(HSMHVQBqbPtr, HSMHVQBqbBinding, HSMHVqbNode, HSMHVqbNode);
                if (here->HSMHV_coselfheat > 0)
                {
                    CFOO(HSMHVQItempPtr, HSMHVQItempBinding, HSMHVqiNode, HSMHVtempNode);
                    CFOO(HSMHVQBtempPtr, HSMHVQBtempBinding, HSMHVqbNode, HSMHVtempNode);
                }
            }
        }
    }

    return (OK) ;
}
