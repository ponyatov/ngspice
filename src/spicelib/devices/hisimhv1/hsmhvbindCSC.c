/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "hsmhvdef.h"
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
            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVDPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDPbpBinding = matched ;
                here->HSMHVDPbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVSPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSPbpBinding = matched ;
                here->HSMHVSPbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVGPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPbpBinding = matched ;
                here->HSMHVGPbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVBPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPdBinding = matched ;
                here->HSMHVBPdPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVBPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPsBinding = matched ;
                here->HSMHVBPsPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
            {
                i = here->HSMHVBPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPdpBinding = matched ;
                here->HSMHVBPdpPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
            {
                i = here->HSMHVBPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPspBinding = matched ;
                here->HSMHVBPspPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVBPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPgpBinding = matched ;
                here->HSMHVBPgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVBPbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPbpBinding = matched ;
                here->HSMHVBPbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVDdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDdBinding = matched ;
                here->HSMHVDdPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVGPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPgpBinding = matched ;
                here->HSMHVGPgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVSsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSsBinding = matched ;
                here->HSMHVSsPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
            {
                i = here->HSMHVDPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDPdpBinding = matched ;
                here->HSMHVDPdpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
            {
                i = here->HSMHVSPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSPspBinding = matched ;
                here->HSMHVSPspPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdNodePrime != 0))
            {
                i = here->HSMHVDdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDdpBinding = matched ;
                here->HSMHVDdpPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
            {
                i = here->HSMHVGPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPdpBinding = matched ;
                here->HSMHVGPdpPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
            {
                i = here->HSMHVGPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPspBinding = matched ;
                here->HSMHVGPspPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsNodePrime != 0))
            {
                i = here->HSMHVSspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSspBinding = matched ;
                here->HSMHVSspPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
            {
                i = here->HSMHVDPspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDPspBinding = matched ;
                here->HSMHVDPspPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVDPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDPdBinding = matched ;
                here->HSMHVDPdPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVDPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDPgpBinding = matched ;
                here->HSMHVDPgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVSPgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSPgpBinding = matched ;
                here->HSMHVSPgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVSPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSPsBinding = matched ;
                here->HSMHVSPsPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
            {
                i = here->HSMHVSPdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSPdpBinding = matched ;
                here->HSMHVSPdpPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNode != 0) && (here-> HSMHVgNode != 0))
            {
                i = here->HSMHVGgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGgBinding = matched ;
                here->HSMHVGgPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNode != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVGgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGgpBinding = matched ;
                here->HSMHVGgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVgNode != 0))
            {
                i = here->HSMHVGPgPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPgBinding = matched ;
                here->HSMHVGPgPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdbNode != 0))
            {
                i = here->HSMHVDdbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDdbBinding = matched ;
                here->HSMHVDdbPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsbNode != 0))
            {
                i = here->HSMHVSsbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSsbBinding = matched ;
                here->HSMHVSsbPtr = matched->CSC ;
            }

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVDBdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDBdBinding = matched ;
                here->HSMHVDBdPtr = matched->CSC ;
            }

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVdbNode != 0))
            {
                i = here->HSMHVDBdbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDBdbBinding = matched ;
                here->HSMHVDBdbPtr = matched->CSC ;
            }

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVDBbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDBbpBinding = matched ;
                here->HSMHVDBbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdbNode != 0))
            {
                i = here->HSMHVBPdbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPdbBinding = matched ;
                here->HSMHVBPdbPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVbNode != 0))
            {
                i = here->HSMHVBPbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPbBinding = matched ;
                here->HSMHVBPbPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsbNode != 0))
            {
                i = here->HSMHVBPsbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBPsbBinding = matched ;
                here->HSMHVBPsbPtr = matched->CSC ;
            }

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVSBsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSBsBinding = matched ;
                here->HSMHVSBsPtr = matched->CSC ;
            }

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVSBbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSBbpBinding = matched ;
                here->HSMHVSBbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVsbNode != 0))
            {
                i = here->HSMHVSBsbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSBsbBinding = matched ;
                here->HSMHVSBsbPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNode != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVBbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBbpBinding = matched ;
                here->HSMHVBbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVbNode != 0) && (here-> HSMHVbNode != 0))
            {
                i = here->HSMHVBbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVBbBinding = matched ;
                here->HSMHVBbPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVDgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDgpBinding = matched ;
                here->HSMHVDgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVDsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDsBinding = matched ;
                here->HSMHVDsPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVDbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDbpBinding = matched ;
                here->HSMHVDbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVsNodePrime != 0))
            {
                i = here->HSMHVDspPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDspBinding = matched ;
                here->HSMHVDspPtr = matched->CSC ;
            }

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVDPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVDPsBinding = matched ;
                here->HSMHVDPsPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVgNodePrime != 0))
            {
                i = here->HSMHVSgpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSgpBinding = matched ;
                here->HSMHVSgpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVSdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSdBinding = matched ;
                here->HSMHVSdPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVbNodePrime != 0))
            {
                i = here->HSMHVSbpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSbpBinding = matched ;
                here->HSMHVSbpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVdNodePrime != 0))
            {
                i = here->HSMHVSdpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSdpBinding = matched ;
                here->HSMHVSdpPtr = matched->CSC ;
            }

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVSPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVSPdBinding = matched ;
                here->HSMHVSPdPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVdNode != 0))
            {
                i = here->HSMHVGPdPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPdBinding = matched ;
                here->HSMHVGPdPtr = matched->CSC ;
            }

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVsNode != 0))
            {
                i = here->HSMHVGPsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->HSMHVGPsBinding = matched ;
                here->HSMHVGPsPtr = matched->CSC ;
            }

            if (here->HSMHVsubNode > 0)
            {
                if ((here-> HSMHVdNode != 0) && (here-> HSMHVsubNode != 0))
                {
                    i = here->HSMHVDsubPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVDsubBinding = matched ;
                    here->HSMHVDsubPtr = matched->CSC ;
                }

                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsubNode != 0))
                {
                    i = here->HSMHVDPsubPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVDPsubBinding = matched ;
                    here->HSMHVDPsubPtr = matched->CSC ;
                }

                if ((here-> HSMHVsNode != 0) && (here-> HSMHVsubNode != 0))
                {
                    i = here->HSMHVSsubPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVSsubBinding = matched ;
                    here->HSMHVSsubPtr = matched->CSC ;
                }

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsubNode != 0))
                {
                    i = here->HSMHVSPsubPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVSPsubBinding = matched ;
                    here->HSMHVSPsubPtr = matched->CSC ;
                }

            }
            if (here->HSMHV_coselfheat > 0)
            {
                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVTemptempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTemptempBinding = matched ;
                    here->HSMHVTemptempPtr = matched->CSC ;
                }

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVdNode != 0))
                {
                    i = here->HSMHVTempdPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTempdBinding = matched ;
                    here->HSMHVTempdPtr = matched->CSC ;
                }

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVdNodePrime != 0))
                {
                    i = here->HSMHVTempdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTempdpBinding = matched ;
                    here->HSMHVTempdpPtr = matched->CSC ;
                }

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVsNode != 0))
                {
                    i = here->HSMHVTempsPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTempsBinding = matched ;
                    here->HSMHVTempsPtr = matched->CSC ;
                }

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVsNodePrime != 0))
                {
                    i = here->HSMHVTempspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTempspBinding = matched ;
                    here->HSMHVTempspPtr = matched->CSC ;
                }

                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVDPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVDPtempBinding = matched ;
                    here->HSMHVDPtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVSPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVSPtempBinding = matched ;
                    here->HSMHVSPtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVgNodePrime != 0))
                {
                    i = here->HSMHVTempgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTempgpBinding = matched ;
                    here->HSMHVTempgpPtr = matched->CSC ;
                }

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVbNodePrime != 0))
                {
                    i = here->HSMHVTempbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVTempbpBinding = matched ;
                    here->HSMHVTempbpPtr = matched->CSC ;
                }

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVGPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVGPtempBinding = matched ;
                    here->HSMHVGPtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVBPtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVBPtempBinding = matched ;
                    here->HSMHVBPtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVdbNode != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVDBtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVDBtempBinding = matched ;
                    here->HSMHVDBtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVsbNode != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVSBtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVSBtempBinding = matched ;
                    here->HSMHVSBtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVdNode != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVDtempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVDtempBinding = matched ;
                    here->HSMHVDtempPtr = matched->CSC ;
                }

                if ((here-> HSMHVsNode != 0) && (here-> HSMHVtempNode != 0))
                {
                    i = here->HSMHVStempPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVStempBinding = matched ;
                    here->HSMHVStempPtr = matched->CSC ;
                }

            }
            if (model->HSMHV_conqs)
            {
                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVqiNode != 0))
                {
                    i = here->HSMHVDPqiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVDPqiBinding = matched ;
                    here->HSMHVDPqiPtr = matched->CSC ;
                }

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVqiNode != 0))
                {
                    i = here->HSMHVGPqiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVGPqiBinding = matched ;
                    here->HSMHVGPqiPtr = matched->CSC ;
                }

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVqbNode != 0))
                {
                    i = here->HSMHVGPqbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVGPqbBinding = matched ;
                    here->HSMHVGPqbPtr = matched->CSC ;
                }

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVqiNode != 0))
                {
                    i = here->HSMHVSPqiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVSPqiBinding = matched ;
                    here->HSMHVSPqiPtr = matched->CSC ;
                }

                if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVqbNode != 0))
                {
                    i = here->HSMHVBPqbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVBPqbBinding = matched ;
                    here->HSMHVBPqbPtr = matched->CSC ;
                }

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVdNodePrime != 0))
                {
                    i = here->HSMHVQIdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQIdpBinding = matched ;
                    here->HSMHVQIdpPtr = matched->CSC ;
                }

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVgNodePrime != 0))
                {
                    i = here->HSMHVQIgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQIgpBinding = matched ;
                    here->HSMHVQIgpPtr = matched->CSC ;
                }

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVsNodePrime != 0))
                {
                    i = here->HSMHVQIspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQIspBinding = matched ;
                    here->HSMHVQIspPtr = matched->CSC ;
                }

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVbNodePrime != 0))
                {
                    i = here->HSMHVQIbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQIbpBinding = matched ;
                    here->HSMHVQIbpPtr = matched->CSC ;
                }

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVqiNode != 0))
                {
                    i = here->HSMHVQIqiPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQIqiBinding = matched ;
                    here->HSMHVQIqiPtr = matched->CSC ;
                }

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVdNodePrime != 0))
                {
                    i = here->HSMHVQBdpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQBdpBinding = matched ;
                    here->HSMHVQBdpPtr = matched->CSC ;
                }

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVgNodePrime != 0))
                {
                    i = here->HSMHVQBgpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQBgpBinding = matched ;
                    here->HSMHVQBgpPtr = matched->CSC ;
                }

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVsNodePrime != 0))
                {
                    i = here->HSMHVQBspPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQBspBinding = matched ;
                    here->HSMHVQBspPtr = matched->CSC ;
                }

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVbNodePrime != 0))
                {
                    i = here->HSMHVQBbpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQBbpBinding = matched ;
                    here->HSMHVQBbpPtr = matched->CSC ;
                }

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVqbNode != 0))
                {
                    i = here->HSMHVQBqbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->HSMHVQBqbBinding = matched ;
                    here->HSMHVQBqbPtr = matched->CSC ;
                }

                if (here->HSMHV_coselfheat > 0)
                {
                    if ((here-> HSMHVqiNode != 0) && (here-> HSMHVtempNode != 0))
                    {
                        i = here->HSMHVQItempPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->HSMHVQItempBinding = matched ;
                        here->HSMHVQItempPtr = matched->CSC ;
                    }

                    if ((here-> HSMHVqbNode != 0) && (here-> HSMHVtempNode != 0))
                    {
                        i = here->HSMHVQBtempPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->HSMHVQBtempBinding = matched ;
                        here->HSMHVQBtempPtr = matched->CSC ;
                    }

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
            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVDPbpPtr = here->HSMHVDPbpBinding->CSC_Complex ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVSPbpPtr = here->HSMHVSPbpBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVGPbpPtr = here->HSMHVGPbpBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVBPdPtr = here->HSMHVBPdBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVBPsPtr = here->HSMHVBPsBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVBPdpPtr = here->HSMHVBPdpBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVBPspPtr = here->HSMHVBPspBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVBPgpPtr = here->HSMHVBPgpBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVBPbpPtr = here->HSMHVBPbpBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVDdPtr = here->HSMHVDdBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVGPgpPtr = here->HSMHVGPgpBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVSsPtr = here->HSMHVSsBinding->CSC_Complex ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVDPdpPtr = here->HSMHVDPdpBinding->CSC_Complex ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVSPspPtr = here->HSMHVSPspBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVDdpPtr = here->HSMHVDdpBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVGPdpPtr = here->HSMHVGPdpBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVGPspPtr = here->HSMHVGPspBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVSspPtr = here->HSMHVSspBinding->CSC_Complex ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVDPspPtr = here->HSMHVDPspBinding->CSC_Complex ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVDPdPtr = here->HSMHVDPdBinding->CSC_Complex ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVDPgpPtr = here->HSMHVDPgpBinding->CSC_Complex ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVSPgpPtr = here->HSMHVSPgpBinding->CSC_Complex ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVSPsPtr = here->HSMHVSPsBinding->CSC_Complex ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVSPdpPtr = here->HSMHVSPdpBinding->CSC_Complex ;

            if ((here-> HSMHVgNode != 0) && (here-> HSMHVgNode != 0))
                here->HSMHVGgPtr = here->HSMHVGgBinding->CSC_Complex ;

            if ((here-> HSMHVgNode != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVGgpPtr = here->HSMHVGgpBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVgNode != 0))
                here->HSMHVGPgPtr = here->HSMHVGPgBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdbNode != 0))
                here->HSMHVDdbPtr = here->HSMHVDdbBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsbNode != 0))
                here->HSMHVSsbPtr = here->HSMHVSsbBinding->CSC_Complex ;

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVDBdPtr = here->HSMHVDBdBinding->CSC_Complex ;

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVdbNode != 0))
                here->HSMHVDBdbPtr = here->HSMHVDBdbBinding->CSC_Complex ;

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVDBbpPtr = here->HSMHVDBbpBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdbNode != 0))
                here->HSMHVBPdbPtr = here->HSMHVBPdbBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVbNode != 0))
                here->HSMHVBPbPtr = here->HSMHVBPbBinding->CSC_Complex ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsbNode != 0))
                here->HSMHVBPsbPtr = here->HSMHVBPsbBinding->CSC_Complex ;

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVSBsPtr = here->HSMHVSBsBinding->CSC_Complex ;

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVSBbpPtr = here->HSMHVSBbpBinding->CSC_Complex ;

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVsbNode != 0))
                here->HSMHVSBsbPtr = here->HSMHVSBsbBinding->CSC_Complex ;

            if ((here-> HSMHVbNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVBbpPtr = here->HSMHVBbpBinding->CSC_Complex ;

            if ((here-> HSMHVbNode != 0) && (here-> HSMHVbNode != 0))
                here->HSMHVBbPtr = here->HSMHVBbBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVDgpPtr = here->HSMHVDgpBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVDsPtr = here->HSMHVDsBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVDbpPtr = here->HSMHVDbpBinding->CSC_Complex ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVDspPtr = here->HSMHVDspBinding->CSC_Complex ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVDPsPtr = here->HSMHVDPsBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVSgpPtr = here->HSMHVSgpBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVSdPtr = here->HSMHVSdBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVSbpPtr = here->HSMHVSbpBinding->CSC_Complex ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVSdpPtr = here->HSMHVSdpBinding->CSC_Complex ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVSPdPtr = here->HSMHVSPdBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVGPdPtr = here->HSMHVGPdBinding->CSC_Complex ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVGPsPtr = here->HSMHVGPsBinding->CSC_Complex ;

            if (here->HSMHVsubNode > 0)
            {
                if ((here-> HSMHVdNode != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVDsubPtr = here->HSMHVDsubBinding->CSC_Complex ;

                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVDPsubPtr = here->HSMHVDPsubBinding->CSC_Complex ;

                if ((here-> HSMHVsNode != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVSsubPtr = here->HSMHVSsubBinding->CSC_Complex ;

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVSPsubPtr = here->HSMHVSPsubBinding->CSC_Complex ;

            }
            if (here->HSMHV_coselfheat > 0)
            {
                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVTemptempPtr = here->HSMHVTemptempBinding->CSC_Complex ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVdNode != 0))
                    here->HSMHVTempdPtr = here->HSMHVTempdBinding->CSC_Complex ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVdNodePrime != 0))
                    here->HSMHVTempdpPtr = here->HSMHVTempdpBinding->CSC_Complex ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVsNode != 0))
                    here->HSMHVTempsPtr = here->HSMHVTempsBinding->CSC_Complex ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVsNodePrime != 0))
                    here->HSMHVTempspPtr = here->HSMHVTempspBinding->CSC_Complex ;

                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVDPtempPtr = here->HSMHVDPtempBinding->CSC_Complex ;

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVSPtempPtr = here->HSMHVSPtempBinding->CSC_Complex ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVgNodePrime != 0))
                    here->HSMHVTempgpPtr = here->HSMHVTempgpBinding->CSC_Complex ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVbNodePrime != 0))
                    here->HSMHVTempbpPtr = here->HSMHVTempbpBinding->CSC_Complex ;

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVGPtempPtr = here->HSMHVGPtempBinding->CSC_Complex ;

                if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVBPtempPtr = here->HSMHVBPtempBinding->CSC_Complex ;

                if ((here-> HSMHVdbNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVDBtempPtr = here->HSMHVDBtempBinding->CSC_Complex ;

                if ((here-> HSMHVsbNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVSBtempPtr = here->HSMHVSBtempBinding->CSC_Complex ;

                if ((here-> HSMHVdNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVDtempPtr = here->HSMHVDtempBinding->CSC_Complex ;

                if ((here-> HSMHVsNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVStempPtr = here->HSMHVStempBinding->CSC_Complex ;

            }
            if (model->HSMHV_conqs)
            {
                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVDPqiPtr = here->HSMHVDPqiBinding->CSC_Complex ;

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVGPqiPtr = here->HSMHVGPqiBinding->CSC_Complex ;

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVqbNode != 0))
                    here->HSMHVGPqbPtr = here->HSMHVGPqbBinding->CSC_Complex ;

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVSPqiPtr = here->HSMHVSPqiBinding->CSC_Complex ;

                if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVqbNode != 0))
                    here->HSMHVBPqbPtr = here->HSMHVBPqbBinding->CSC_Complex ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVdNodePrime != 0))
                    here->HSMHVQIdpPtr = here->HSMHVQIdpBinding->CSC_Complex ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVgNodePrime != 0))
                    here->HSMHVQIgpPtr = here->HSMHVQIgpBinding->CSC_Complex ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVsNodePrime != 0))
                    here->HSMHVQIspPtr = here->HSMHVQIspBinding->CSC_Complex ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVbNodePrime != 0))
                    here->HSMHVQIbpPtr = here->HSMHVQIbpBinding->CSC_Complex ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVQIqiPtr = here->HSMHVQIqiBinding->CSC_Complex ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVdNodePrime != 0))
                    here->HSMHVQBdpPtr = here->HSMHVQBdpBinding->CSC_Complex ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVgNodePrime != 0))
                    here->HSMHVQBgpPtr = here->HSMHVQBgpBinding->CSC_Complex ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVsNodePrime != 0))
                    here->HSMHVQBspPtr = here->HSMHVQBspBinding->CSC_Complex ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVbNodePrime != 0))
                    here->HSMHVQBbpPtr = here->HSMHVQBbpBinding->CSC_Complex ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVqbNode != 0))
                    here->HSMHVQBqbPtr = here->HSMHVQBqbBinding->CSC_Complex ;

                if (here->HSMHV_coselfheat > 0)
                {
                    if ((here-> HSMHVqiNode != 0) && (here-> HSMHVtempNode != 0))
                        here->HSMHVQItempPtr = here->HSMHVQItempBinding->CSC_Complex ;

                    if ((here-> HSMHVqbNode != 0) && (here-> HSMHVtempNode != 0))
                        here->HSMHVQBtempPtr = here->HSMHVQBtempBinding->CSC_Complex ;

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
            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVDPbpPtr = here->HSMHVDPbpBinding->CSC ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVSPbpPtr = here->HSMHVSPbpBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVGPbpPtr = here->HSMHVGPbpBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVBPdPtr = here->HSMHVBPdBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVBPsPtr = here->HSMHVBPsBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVBPdpPtr = here->HSMHVBPdpBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVBPspPtr = here->HSMHVBPspBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVBPgpPtr = here->HSMHVBPgpBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVBPbpPtr = here->HSMHVBPbpBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVDdPtr = here->HSMHVDdBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVGPgpPtr = here->HSMHVGPgpBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVSsPtr = here->HSMHVSsBinding->CSC ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVDPdpPtr = here->HSMHVDPdpBinding->CSC ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVSPspPtr = here->HSMHVSPspBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVDdpPtr = here->HSMHVDdpBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVGPdpPtr = here->HSMHVGPdpBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVGPspPtr = here->HSMHVGPspBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVSspPtr = here->HSMHVSspBinding->CSC ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVDPspPtr = here->HSMHVDPspBinding->CSC ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVDPdPtr = here->HSMHVDPdBinding->CSC ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVDPgpPtr = here->HSMHVDPgpBinding->CSC ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVSPgpPtr = here->HSMHVSPgpBinding->CSC ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVSPsPtr = here->HSMHVSPsBinding->CSC ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVSPdpPtr = here->HSMHVSPdpBinding->CSC ;

            if ((here-> HSMHVgNode != 0) && (here-> HSMHVgNode != 0))
                here->HSMHVGgPtr = here->HSMHVGgBinding->CSC ;

            if ((here-> HSMHVgNode != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVGgpPtr = here->HSMHVGgpBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVgNode != 0))
                here->HSMHVGPgPtr = here->HSMHVGPgBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVdbNode != 0))
                here->HSMHVDdbPtr = here->HSMHVDdbBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVsbNode != 0))
                here->HSMHVSsbPtr = here->HSMHVSsbBinding->CSC ;

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVDBdPtr = here->HSMHVDBdBinding->CSC ;

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVdbNode != 0))
                here->HSMHVDBdbPtr = here->HSMHVDBdbBinding->CSC ;

            if ((here-> HSMHVdbNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVDBbpPtr = here->HSMHVDBbpBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVdbNode != 0))
                here->HSMHVBPdbPtr = here->HSMHVBPdbBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVbNode != 0))
                here->HSMHVBPbPtr = here->HSMHVBPbBinding->CSC ;

            if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVsbNode != 0))
                here->HSMHVBPsbPtr = here->HSMHVBPsbBinding->CSC ;

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVSBsPtr = here->HSMHVSBsBinding->CSC ;

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVSBbpPtr = here->HSMHVSBbpBinding->CSC ;

            if ((here-> HSMHVsbNode != 0) && (here-> HSMHVsbNode != 0))
                here->HSMHVSBsbPtr = here->HSMHVSBsbBinding->CSC ;

            if ((here-> HSMHVbNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVBbpPtr = here->HSMHVBbpBinding->CSC ;

            if ((here-> HSMHVbNode != 0) && (here-> HSMHVbNode != 0))
                here->HSMHVBbPtr = here->HSMHVBbBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVDgpPtr = here->HSMHVDgpBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVDsPtr = here->HSMHVDsBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVDbpPtr = here->HSMHVDbpBinding->CSC ;

            if ((here-> HSMHVdNode != 0) && (here-> HSMHVsNodePrime != 0))
                here->HSMHVDspPtr = here->HSMHVDspBinding->CSC ;

            if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVDPsPtr = here->HSMHVDPsBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVgNodePrime != 0))
                here->HSMHVSgpPtr = here->HSMHVSgpBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVSdPtr = here->HSMHVSdBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVbNodePrime != 0))
                here->HSMHVSbpPtr = here->HSMHVSbpBinding->CSC ;

            if ((here-> HSMHVsNode != 0) && (here-> HSMHVdNodePrime != 0))
                here->HSMHVSdpPtr = here->HSMHVSdpBinding->CSC ;

            if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVSPdPtr = here->HSMHVSPdBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVdNode != 0))
                here->HSMHVGPdPtr = here->HSMHVGPdBinding->CSC ;

            if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVsNode != 0))
                here->HSMHVGPsPtr = here->HSMHVGPsBinding->CSC ;

            if (here->HSMHVsubNode > 0)
            {
                if ((here-> HSMHVdNode != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVDsubPtr = here->HSMHVDsubBinding->CSC ;

                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVDPsubPtr = here->HSMHVDPsubBinding->CSC ;

                if ((here-> HSMHVsNode != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVSsubPtr = here->HSMHVSsubBinding->CSC ;

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVsubNode != 0))
                    here->HSMHVSPsubPtr = here->HSMHVSPsubBinding->CSC ;

            }
            if (here->HSMHV_coselfheat > 0)
            {
                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVTemptempPtr = here->HSMHVTemptempBinding->CSC ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVdNode != 0))
                    here->HSMHVTempdPtr = here->HSMHVTempdBinding->CSC ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVdNodePrime != 0))
                    here->HSMHVTempdpPtr = here->HSMHVTempdpBinding->CSC ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVsNode != 0))
                    here->HSMHVTempsPtr = here->HSMHVTempsBinding->CSC ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVsNodePrime != 0))
                    here->HSMHVTempspPtr = here->HSMHVTempspBinding->CSC ;

                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVDPtempPtr = here->HSMHVDPtempBinding->CSC ;

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVSPtempPtr = here->HSMHVSPtempBinding->CSC ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVgNodePrime != 0))
                    here->HSMHVTempgpPtr = here->HSMHVTempgpBinding->CSC ;

                if ((here-> HSMHVtempNode != 0) && (here-> HSMHVbNodePrime != 0))
                    here->HSMHVTempbpPtr = here->HSMHVTempbpBinding->CSC ;

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVGPtempPtr = here->HSMHVGPtempBinding->CSC ;

                if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVBPtempPtr = here->HSMHVBPtempBinding->CSC ;

                if ((here-> HSMHVdbNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVDBtempPtr = here->HSMHVDBtempBinding->CSC ;

                if ((here-> HSMHVsbNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVSBtempPtr = here->HSMHVSBtempBinding->CSC ;

                if ((here-> HSMHVdNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVDtempPtr = here->HSMHVDtempBinding->CSC ;

                if ((here-> HSMHVsNode != 0) && (here-> HSMHVtempNode != 0))
                    here->HSMHVStempPtr = here->HSMHVStempBinding->CSC ;

            }
            if (model->HSMHV_conqs)
            {
                if ((here-> HSMHVdNodePrime != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVDPqiPtr = here->HSMHVDPqiBinding->CSC ;

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVGPqiPtr = here->HSMHVGPqiBinding->CSC ;

                if ((here-> HSMHVgNodePrime != 0) && (here-> HSMHVqbNode != 0))
                    here->HSMHVGPqbPtr = here->HSMHVGPqbBinding->CSC ;

                if ((here-> HSMHVsNodePrime != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVSPqiPtr = here->HSMHVSPqiBinding->CSC ;

                if ((here-> HSMHVbNodePrime != 0) && (here-> HSMHVqbNode != 0))
                    here->HSMHVBPqbPtr = here->HSMHVBPqbBinding->CSC ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVdNodePrime != 0))
                    here->HSMHVQIdpPtr = here->HSMHVQIdpBinding->CSC ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVgNodePrime != 0))
                    here->HSMHVQIgpPtr = here->HSMHVQIgpBinding->CSC ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVsNodePrime != 0))
                    here->HSMHVQIspPtr = here->HSMHVQIspBinding->CSC ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVbNodePrime != 0))
                    here->HSMHVQIbpPtr = here->HSMHVQIbpBinding->CSC ;

                if ((here-> HSMHVqiNode != 0) && (here-> HSMHVqiNode != 0))
                    here->HSMHVQIqiPtr = here->HSMHVQIqiBinding->CSC ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVdNodePrime != 0))
                    here->HSMHVQBdpPtr = here->HSMHVQBdpBinding->CSC ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVgNodePrime != 0))
                    here->HSMHVQBgpPtr = here->HSMHVQBgpBinding->CSC ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVsNodePrime != 0))
                    here->HSMHVQBspPtr = here->HSMHVQBspBinding->CSC ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVbNodePrime != 0))
                    here->HSMHVQBbpPtr = here->HSMHVQBbpBinding->CSC ;

                if ((here-> HSMHVqbNode != 0) && (here-> HSMHVqbNode != 0))
                    here->HSMHVQBqbPtr = here->HSMHVQBqbBinding->CSC ;

                if (here->HSMHV_coselfheat > 0)
                {
                    if ((here-> HSMHVqiNode != 0) && (here-> HSMHVtempNode != 0))
                        here->HSMHVQItempPtr = here->HSMHVQItempBinding->CSC ;

                    if ((here-> HSMHVqbNode != 0) && (here-> HSMHVtempNode != 0))
                        here->HSMHVQBtempPtr = here->HSMHVQBtempBinding->CSC ;

                }
            }
        }
    }

    return (OK) ;
}
