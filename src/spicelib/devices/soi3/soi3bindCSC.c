/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "soi3defs.h"
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
SOI3bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    SOI3model *model = (SOI3model *)inModel ;
    SOI3instance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the SOI3 models */
    for ( ; model != NULL ; model = model->SOI3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->SOI3instances ; here != NULL ; here = here->SOI3nextInstance)
        {
            if ((here->SOI3dNode != 0) && (here->SOI3dNode != 0))
            {
                i = here->SOI3D_dPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3D_dBinding = matched ;
                here->SOI3D_dPtr = matched->CSC ;
            }

            if ((here->SOI3dNode != 0) && (here->SOI3dNodePrime != 0))
            {
                i = here->SOI3D_dpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3D_dpBinding = matched ;
                here->SOI3D_dpPtr = matched->CSC ;
            }

            if ((here->SOI3dNodePrime != 0) && (here->SOI3dNode != 0))
            {
                i = here->SOI3DP_dPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3DP_dBinding = matched ;
                here->SOI3DP_dPtr = matched->CSC ;
            }

            if ((here->SOI3sNode != 0) && (here->SOI3sNode != 0))
            {
                i = here->SOI3S_sPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3S_sBinding = matched ;
                here->SOI3S_sPtr = matched->CSC ;
            }

            if ((here->SOI3sNode != 0) && (here->SOI3sNodePrime != 0))
            {
                i = here->SOI3S_spPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3S_spBinding = matched ;
                here->SOI3S_spPtr = matched->CSC ;
            }

            if ((here->SOI3sNodePrime != 0) && (here->SOI3sNode != 0))
            {
                i = here->SOI3SP_sPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3SP_sBinding = matched ;
                here->SOI3SP_sPtr = matched->CSC ;
            }

            if ((here->SOI3gfNode != 0) && (here->SOI3gfNode != 0))
            {
                i = here->SOI3GF_gfPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GF_gfBinding = matched ;
                here->SOI3GF_gfPtr = matched->CSC ;
            }

            if ((here->SOI3gfNode != 0) && (here->SOI3gbNode != 0))
            {
                i = here->SOI3GF_gbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GF_gbBinding = matched ;
                here->SOI3GF_gbPtr = matched->CSC ;
            }

            if ((here->SOI3gfNode != 0) && (here->SOI3dNodePrime != 0))
            {
                i = here->SOI3GF_dpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GF_dpBinding = matched ;
                here->SOI3GF_dpPtr = matched->CSC ;
            }

            if ((here->SOI3gfNode != 0) && (here->SOI3sNodePrime != 0))
            {
                i = here->SOI3GF_spPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GF_spBinding = matched ;
                here->SOI3GF_spPtr = matched->CSC ;
            }

            if ((here->SOI3gfNode != 0) && (here->SOI3bNode != 0))
            {
                i = here->SOI3GF_bPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GF_bBinding = matched ;
                here->SOI3GF_bPtr = matched->CSC ;
            }

            if ((here->SOI3gbNode != 0) && (here->SOI3gfNode != 0))
            {
                i = here->SOI3GB_gfPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GB_gfBinding = matched ;
                here->SOI3GB_gfPtr = matched->CSC ;
            }

            if ((here->SOI3gbNode != 0) && (here->SOI3gbNode != 0))
            {
                i = here->SOI3GB_gbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GB_gbBinding = matched ;
                here->SOI3GB_gbPtr = matched->CSC ;
            }

            if ((here->SOI3gbNode != 0) && (here->SOI3dNodePrime != 0))
            {
                i = here->SOI3GB_dpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GB_dpBinding = matched ;
                here->SOI3GB_dpPtr = matched->CSC ;
            }

            if ((here->SOI3gbNode != 0) && (here->SOI3sNodePrime != 0))
            {
                i = here->SOI3GB_spPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GB_spBinding = matched ;
                here->SOI3GB_spPtr = matched->CSC ;
            }

            if ((here->SOI3gbNode != 0) && (here->SOI3bNode != 0))
            {
                i = here->SOI3GB_bPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3GB_bBinding = matched ;
                here->SOI3GB_bPtr = matched->CSC ;
            }

            if ((here->SOI3bNode != 0) && (here->SOI3gfNode != 0))
            {
                i = here->SOI3B_gfPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3B_gfBinding = matched ;
                here->SOI3B_gfPtr = matched->CSC ;
            }

            if ((here->SOI3bNode != 0) && (here->SOI3gbNode != 0))
            {
                i = here->SOI3B_gbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3B_gbBinding = matched ;
                here->SOI3B_gbPtr = matched->CSC ;
            }

            if ((here->SOI3bNode != 0) && (here->SOI3dNodePrime != 0))
            {
                i = here->SOI3B_dpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3B_dpBinding = matched ;
                here->SOI3B_dpPtr = matched->CSC ;
            }

            if ((here->SOI3bNode != 0) && (here->SOI3sNodePrime != 0))
            {
                i = here->SOI3B_spPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3B_spBinding = matched ;
                here->SOI3B_spPtr = matched->CSC ;
            }

            if ((here->SOI3bNode != 0) && (here->SOI3bNode != 0))
            {
                i = here->SOI3B_bPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3B_bBinding = matched ;
                here->SOI3B_bPtr = matched->CSC ;
            }

            if ((here->SOI3dNodePrime != 0) && (here->SOI3gfNode != 0))
            {
                i = here->SOI3DP_gfPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3DP_gfBinding = matched ;
                here->SOI3DP_gfPtr = matched->CSC ;
            }

            if ((here->SOI3dNodePrime != 0) && (here->SOI3gbNode != 0))
            {
                i = here->SOI3DP_gbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3DP_gbBinding = matched ;
                here->SOI3DP_gbPtr = matched->CSC ;
            }

            if ((here->SOI3dNodePrime != 0) && (here->SOI3dNodePrime != 0))
            {
                i = here->SOI3DP_dpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3DP_dpBinding = matched ;
                here->SOI3DP_dpPtr = matched->CSC ;
            }

            if ((here->SOI3dNodePrime != 0) && (here->SOI3sNodePrime != 0))
            {
                i = here->SOI3DP_spPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3DP_spBinding = matched ;
                here->SOI3DP_spPtr = matched->CSC ;
            }

            if ((here->SOI3dNodePrime != 0) && (here->SOI3bNode != 0))
            {
                i = here->SOI3DP_bPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3DP_bBinding = matched ;
                here->SOI3DP_bPtr = matched->CSC ;
            }

            if ((here->SOI3sNodePrime != 0) && (here->SOI3gfNode != 0))
            {
                i = here->SOI3SP_gfPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3SP_gfBinding = matched ;
                here->SOI3SP_gfPtr = matched->CSC ;
            }

            if ((here->SOI3sNodePrime != 0) && (here->SOI3gbNode != 0))
            {
                i = here->SOI3SP_gbPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3SP_gbBinding = matched ;
                here->SOI3SP_gbPtr = matched->CSC ;
            }

            if ((here->SOI3sNodePrime != 0) && (here->SOI3dNodePrime != 0))
            {
                i = here->SOI3SP_dpPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3SP_dpBinding = matched ;
                here->SOI3SP_dpPtr = matched->CSC ;
            }

            if ((here->SOI3sNodePrime != 0) && (here->SOI3sNodePrime != 0))
            {
                i = here->SOI3SP_spPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3SP_spBinding = matched ;
                here->SOI3SP_spPtr = matched->CSC ;
            }

            if ((here->SOI3sNodePrime != 0) && (here->SOI3bNode != 0))
            {
                i = here->SOI3SP_bPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->SOI3SP_bBinding = matched ;
                here->SOI3SP_bPtr = matched->CSC ;
            }

            if (here->SOI3rt == 0)
            {
                if ((here->SOI3toutNode != 0) && (here->SOI3branch != 0))
                {
                    i = here->SOI3TOUT_ibrPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_ibrBinding = matched ;
                    here->SOI3TOUT_ibrPtr = matched->CSC ;
                }

                if ((here->SOI3branch != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3IBR_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3IBR_toutBinding = matched ;
                    here->SOI3IBR_toutPtr = matched->CSC ;
                }

            }
            else
            {
                if ((here->SOI3toutNode != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3TOUT_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_toutBinding = matched ;
                    here->SOI3TOUT_toutPtr = matched->CSC ;
                }

                if (here->SOI3numThermalNodes > 1)
                {
                    if ((here->SOI3toutNode != 0) && (here->SOI3tout1Node != 0))
                    {
                        i = here->SOI3TOUT_tout1Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT_tout1Binding = matched ;
                        here->SOI3TOUT_tout1Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout1Node != 0) && (here->SOI3toutNode != 0))
                    {
                        i = here->SOI3TOUT1_toutPtr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT1_toutBinding = matched ;
                        here->SOI3TOUT1_toutPtr = matched->CSC ;
                    }

                    if ((here->SOI3tout1Node != 0) && (here->SOI3tout1Node != 0))
                    {
                        i = here->SOI3TOUT1_tout1Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT1_tout1Binding = matched ;
                        here->SOI3TOUT1_tout1Ptr = matched->CSC ;
                    }

                }
                if (here->SOI3numThermalNodes > 2)
                {
                    if ((here->SOI3tout1Node != 0) && (here->SOI3tout2Node != 0))
                    {
                        i = here->SOI3TOUT1_tout2Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT1_tout2Binding = matched ;
                        here->SOI3TOUT1_tout2Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout1Node != 0))
                    {
                        i = here->SOI3TOUT2_tout1Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT2_tout1Binding = matched ;
                        here->SOI3TOUT2_tout1Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout2Node != 0))
                    {
                        i = here->SOI3TOUT2_tout2Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT2_tout2Binding = matched ;
                        here->SOI3TOUT2_tout2Ptr = matched->CSC ;
                    }

                }
                if (here->SOI3numThermalNodes > 3)
                {
                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout3Node != 0))
                    {
                        i = here->SOI3TOUT2_tout3Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT2_tout3Binding = matched ;
                        here->SOI3TOUT2_tout3Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout2Node != 0))
                    {
                        i = here->SOI3TOUT3_tout2Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT3_tout2Binding = matched ;
                        here->SOI3TOUT3_tout2Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout3Node != 0))
                    {
                        i = here->SOI3TOUT3_tout3Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT3_tout3Binding = matched ;
                        here->SOI3TOUT3_tout3Ptr = matched->CSC ;
                    }

                }
                if (here->SOI3numThermalNodes > 4)
                {
                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout4Node != 0))
                    {
                        i = here->SOI3TOUT3_tout4Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT3_tout4Binding = matched ;
                        here->SOI3TOUT3_tout4Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout4Node != 0) && (here->SOI3tout3Node != 0))
                    {
                        i = here->SOI3TOUT4_tout3Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT4_tout3Binding = matched ;
                        here->SOI3TOUT4_tout3Ptr = matched->CSC ;
                    }

                    if ((here->SOI3tout4Node != 0) && (here->SOI3tout4Node != 0))
                    {
                        i = here->SOI3TOUT4_tout4Ptr ;
                        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                        here->SOI3TOUT4_tout4Binding = matched ;
                        here->SOI3TOUT4_tout4Ptr = matched->CSC ;
                    }

                }
                if ((here->SOI3toutNode != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3TOUT_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_toutBinding = matched ;
                    here->SOI3TOUT_toutPtr = matched->CSC ;
                }

                if ((here->SOI3toutNode != 0) && (here->SOI3gfNode != 0))
                {
                    i = here->SOI3TOUT_gfPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_gfBinding = matched ;
                    here->SOI3TOUT_gfPtr = matched->CSC ;
                }

                if ((here->SOI3toutNode != 0) && (here->SOI3gbNode != 0))
                {
                    i = here->SOI3TOUT_gbPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_gbBinding = matched ;
                    here->SOI3TOUT_gbPtr = matched->CSC ;
                }

                if ((here->SOI3toutNode != 0) && (here->SOI3dNodePrime != 0))
                {
                    i = here->SOI3TOUT_dpPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_dpBinding = matched ;
                    here->SOI3TOUT_dpPtr = matched->CSC ;
                }

                if ((here->SOI3toutNode != 0) && (here->SOI3sNodePrime != 0))
                {
                    i = here->SOI3TOUT_spPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_spBinding = matched ;
                    here->SOI3TOUT_spPtr = matched->CSC ;
                }

                if ((here->SOI3toutNode != 0) && (here->SOI3bNode != 0))
                {
                    i = here->SOI3TOUT_bPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3TOUT_bBinding = matched ;
                    here->SOI3TOUT_bPtr = matched->CSC ;
                }

                if ((here->SOI3gfNode != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3GF_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3GF_toutBinding = matched ;
                    here->SOI3GF_toutPtr = matched->CSC ;
                }

                if ((here->SOI3gbNode != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3GB_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3GB_toutBinding = matched ;
                    here->SOI3GB_toutPtr = matched->CSC ;
                }

                if ((here->SOI3dNodePrime != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3DP_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3DP_toutBinding = matched ;
                    here->SOI3DP_toutPtr = matched->CSC ;
                }

                if ((here->SOI3sNodePrime != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3SP_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3SP_toutBinding = matched ;
                    here->SOI3SP_toutPtr = matched->CSC ;
                }

                if ((here->SOI3bNode != 0) && (here->SOI3toutNode != 0))
                {
                    i = here->SOI3B_toutPtr ;
                    matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                    here->SOI3B_toutBinding = matched ;
                    here->SOI3B_toutPtr = matched->CSC ;
                }

            }
        }
    }

    return (OK) ;
}

int
SOI3bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    SOI3model *model = (SOI3model *)inModel ;
    SOI3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the SOI3 models */
    for ( ; model != NULL ; model = model->SOI3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->SOI3instances ; here != NULL ; here = here->SOI3nextInstance)
        {
            if ((here->SOI3dNode != 0) && (here->SOI3dNode != 0))
                here->SOI3D_dPtr = here->SOI3D_dBinding->CSC_Complex ;

            if ((here->SOI3dNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3D_dpPtr = here->SOI3D_dpBinding->CSC_Complex ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3dNode != 0))
                here->SOI3DP_dPtr = here->SOI3DP_dBinding->CSC_Complex ;

            if ((here->SOI3sNode != 0) && (here->SOI3sNode != 0))
                here->SOI3S_sPtr = here->SOI3S_sBinding->CSC_Complex ;

            if ((here->SOI3sNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3S_spPtr = here->SOI3S_spBinding->CSC_Complex ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3sNode != 0))
                here->SOI3SP_sPtr = here->SOI3SP_sBinding->CSC_Complex ;

            if ((here->SOI3gfNode != 0) && (here->SOI3gfNode != 0))
                here->SOI3GF_gfPtr = here->SOI3GF_gfBinding->CSC_Complex ;

            if ((here->SOI3gfNode != 0) && (here->SOI3gbNode != 0))
                here->SOI3GF_gbPtr = here->SOI3GF_gbBinding->CSC_Complex ;

            if ((here->SOI3gfNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3GF_dpPtr = here->SOI3GF_dpBinding->CSC_Complex ;

            if ((here->SOI3gfNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3GF_spPtr = here->SOI3GF_spBinding->CSC_Complex ;

            if ((here->SOI3gfNode != 0) && (here->SOI3bNode != 0))
                here->SOI3GF_bPtr = here->SOI3GF_bBinding->CSC_Complex ;

            if ((here->SOI3gbNode != 0) && (here->SOI3gfNode != 0))
                here->SOI3GB_gfPtr = here->SOI3GB_gfBinding->CSC_Complex ;

            if ((here->SOI3gbNode != 0) && (here->SOI3gbNode != 0))
                here->SOI3GB_gbPtr = here->SOI3GB_gbBinding->CSC_Complex ;

            if ((here->SOI3gbNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3GB_dpPtr = here->SOI3GB_dpBinding->CSC_Complex ;

            if ((here->SOI3gbNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3GB_spPtr = here->SOI3GB_spBinding->CSC_Complex ;

            if ((here->SOI3gbNode != 0) && (here->SOI3bNode != 0))
                here->SOI3GB_bPtr = here->SOI3GB_bBinding->CSC_Complex ;

            if ((here->SOI3bNode != 0) && (here->SOI3gfNode != 0))
                here->SOI3B_gfPtr = here->SOI3B_gfBinding->CSC_Complex ;

            if ((here->SOI3bNode != 0) && (here->SOI3gbNode != 0))
                here->SOI3B_gbPtr = here->SOI3B_gbBinding->CSC_Complex ;

            if ((here->SOI3bNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3B_dpPtr = here->SOI3B_dpBinding->CSC_Complex ;

            if ((here->SOI3bNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3B_spPtr = here->SOI3B_spBinding->CSC_Complex ;

            if ((here->SOI3bNode != 0) && (here->SOI3bNode != 0))
                here->SOI3B_bPtr = here->SOI3B_bBinding->CSC_Complex ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3gfNode != 0))
                here->SOI3DP_gfPtr = here->SOI3DP_gfBinding->CSC_Complex ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3gbNode != 0))
                here->SOI3DP_gbPtr = here->SOI3DP_gbBinding->CSC_Complex ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3DP_dpPtr = here->SOI3DP_dpBinding->CSC_Complex ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3DP_spPtr = here->SOI3DP_spBinding->CSC_Complex ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3bNode != 0))
                here->SOI3DP_bPtr = here->SOI3DP_bBinding->CSC_Complex ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3gfNode != 0))
                here->SOI3SP_gfPtr = here->SOI3SP_gfBinding->CSC_Complex ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3gbNode != 0))
                here->SOI3SP_gbPtr = here->SOI3SP_gbBinding->CSC_Complex ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3SP_dpPtr = here->SOI3SP_dpBinding->CSC_Complex ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3SP_spPtr = here->SOI3SP_spBinding->CSC_Complex ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3bNode != 0))
                here->SOI3SP_bPtr = here->SOI3SP_bBinding->CSC_Complex ;

            if (here->SOI3rt == 0)
            {
                if ((here->SOI3toutNode != 0) && (here->SOI3branch != 0))
                    here->SOI3TOUT_ibrPtr = here->SOI3TOUT_ibrBinding->CSC_Complex ;

                if ((here->SOI3branch != 0) && (here->SOI3toutNode != 0))
                    here->SOI3IBR_toutPtr = here->SOI3IBR_toutBinding->CSC_Complex ;

            }
            else
            {
                if ((here->SOI3toutNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3TOUT_toutPtr = here->SOI3TOUT_toutBinding->CSC_Complex ;

                if (here->SOI3numThermalNodes > 1)
                {
                    if ((here->SOI3toutNode != 0) && (here->SOI3tout1Node != 0))
                        here->SOI3TOUT_tout1Ptr = here->SOI3TOUT_tout1Binding->CSC_Complex ;

                    if ((here->SOI3tout1Node != 0) && (here->SOI3toutNode != 0))
                        here->SOI3TOUT1_toutPtr = here->SOI3TOUT1_toutBinding->CSC_Complex ;

                    if ((here->SOI3tout1Node != 0) && (here->SOI3tout1Node != 0))
                        here->SOI3TOUT1_tout1Ptr = here->SOI3TOUT1_tout1Binding->CSC_Complex ;

                }
                if (here->SOI3numThermalNodes > 2)
                {
                    if ((here->SOI3tout1Node != 0) && (here->SOI3tout2Node != 0))
                        here->SOI3TOUT1_tout2Ptr = here->SOI3TOUT1_tout2Binding->CSC_Complex ;

                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout1Node != 0))
                        here->SOI3TOUT2_tout1Ptr = here->SOI3TOUT2_tout1Binding->CSC_Complex ;

                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout2Node != 0))
                        here->SOI3TOUT2_tout2Ptr = here->SOI3TOUT2_tout2Binding->CSC_Complex ;

                }
                if (here->SOI3numThermalNodes > 3)
                {
                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout3Node != 0))
                        here->SOI3TOUT2_tout3Ptr = here->SOI3TOUT2_tout3Binding->CSC_Complex ;

                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout2Node != 0))
                        here->SOI3TOUT3_tout2Ptr = here->SOI3TOUT3_tout2Binding->CSC_Complex ;

                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout3Node != 0))
                        here->SOI3TOUT3_tout3Ptr = here->SOI3TOUT3_tout3Binding->CSC_Complex ;

                }
                if (here->SOI3numThermalNodes > 4)
                {
                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout4Node != 0))
                        here->SOI3TOUT3_tout4Ptr = here->SOI3TOUT3_tout4Binding->CSC_Complex ;

                    if ((here->SOI3tout4Node != 0) && (here->SOI3tout3Node != 0))
                        here->SOI3TOUT4_tout3Ptr = here->SOI3TOUT4_tout3Binding->CSC_Complex ;

                    if ((here->SOI3tout4Node != 0) && (here->SOI3tout4Node != 0))
                        here->SOI3TOUT4_tout4Ptr = here->SOI3TOUT4_tout4Binding->CSC_Complex ;

                }
                if ((here->SOI3toutNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3TOUT_toutPtr = here->SOI3TOUT_toutBinding->CSC_Complex ;

                if ((here->SOI3toutNode != 0) && (here->SOI3gfNode != 0))
                    here->SOI3TOUT_gfPtr = here->SOI3TOUT_gfBinding->CSC_Complex ;

                if ((here->SOI3toutNode != 0) && (here->SOI3gbNode != 0))
                    here->SOI3TOUT_gbPtr = here->SOI3TOUT_gbBinding->CSC_Complex ;

                if ((here->SOI3toutNode != 0) && (here->SOI3dNodePrime != 0))
                    here->SOI3TOUT_dpPtr = here->SOI3TOUT_dpBinding->CSC_Complex ;

                if ((here->SOI3toutNode != 0) && (here->SOI3sNodePrime != 0))
                    here->SOI3TOUT_spPtr = here->SOI3TOUT_spBinding->CSC_Complex ;

                if ((here->SOI3toutNode != 0) && (here->SOI3bNode != 0))
                    here->SOI3TOUT_bPtr = here->SOI3TOUT_bBinding->CSC_Complex ;

                if ((here->SOI3gfNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3GF_toutPtr = here->SOI3GF_toutBinding->CSC_Complex ;

                if ((here->SOI3gbNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3GB_toutPtr = here->SOI3GB_toutBinding->CSC_Complex ;

                if ((here->SOI3dNodePrime != 0) && (here->SOI3toutNode != 0))
                    here->SOI3DP_toutPtr = here->SOI3DP_toutBinding->CSC_Complex ;

                if ((here->SOI3sNodePrime != 0) && (here->SOI3toutNode != 0))
                    here->SOI3SP_toutPtr = here->SOI3SP_toutBinding->CSC_Complex ;

                if ((here->SOI3bNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3B_toutPtr = here->SOI3B_toutBinding->CSC_Complex ;

            }
        }
    }

    return (OK) ;
}

int
SOI3bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    SOI3model *model = (SOI3model *)inModel ;
    SOI3instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the SOI3 models */
    for ( ; model != NULL ; model = model->SOI3nextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->SOI3instances ; here != NULL ; here = here->SOI3nextInstance)
        {
            if ((here->SOI3dNode != 0) && (here->SOI3dNode != 0))
                here->SOI3D_dPtr = here->SOI3D_dBinding->CSC ;

            if ((here->SOI3dNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3D_dpPtr = here->SOI3D_dpBinding->CSC ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3dNode != 0))
                here->SOI3DP_dPtr = here->SOI3DP_dBinding->CSC ;

            if ((here->SOI3sNode != 0) && (here->SOI3sNode != 0))
                here->SOI3S_sPtr = here->SOI3S_sBinding->CSC ;

            if ((here->SOI3sNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3S_spPtr = here->SOI3S_spBinding->CSC ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3sNode != 0))
                here->SOI3SP_sPtr = here->SOI3SP_sBinding->CSC ;

            if ((here->SOI3gfNode != 0) && (here->SOI3gfNode != 0))
                here->SOI3GF_gfPtr = here->SOI3GF_gfBinding->CSC ;

            if ((here->SOI3gfNode != 0) && (here->SOI3gbNode != 0))
                here->SOI3GF_gbPtr = here->SOI3GF_gbBinding->CSC ;

            if ((here->SOI3gfNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3GF_dpPtr = here->SOI3GF_dpBinding->CSC ;

            if ((here->SOI3gfNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3GF_spPtr = here->SOI3GF_spBinding->CSC ;

            if ((here->SOI3gfNode != 0) && (here->SOI3bNode != 0))
                here->SOI3GF_bPtr = here->SOI3GF_bBinding->CSC ;

            if ((here->SOI3gbNode != 0) && (here->SOI3gfNode != 0))
                here->SOI3GB_gfPtr = here->SOI3GB_gfBinding->CSC ;

            if ((here->SOI3gbNode != 0) && (here->SOI3gbNode != 0))
                here->SOI3GB_gbPtr = here->SOI3GB_gbBinding->CSC ;

            if ((here->SOI3gbNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3GB_dpPtr = here->SOI3GB_dpBinding->CSC ;

            if ((here->SOI3gbNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3GB_spPtr = here->SOI3GB_spBinding->CSC ;

            if ((here->SOI3gbNode != 0) && (here->SOI3bNode != 0))
                here->SOI3GB_bPtr = here->SOI3GB_bBinding->CSC ;

            if ((here->SOI3bNode != 0) && (here->SOI3gfNode != 0))
                here->SOI3B_gfPtr = here->SOI3B_gfBinding->CSC ;

            if ((here->SOI3bNode != 0) && (here->SOI3gbNode != 0))
                here->SOI3B_gbPtr = here->SOI3B_gbBinding->CSC ;

            if ((here->SOI3bNode != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3B_dpPtr = here->SOI3B_dpBinding->CSC ;

            if ((here->SOI3bNode != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3B_spPtr = here->SOI3B_spBinding->CSC ;

            if ((here->SOI3bNode != 0) && (here->SOI3bNode != 0))
                here->SOI3B_bPtr = here->SOI3B_bBinding->CSC ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3gfNode != 0))
                here->SOI3DP_gfPtr = here->SOI3DP_gfBinding->CSC ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3gbNode != 0))
                here->SOI3DP_gbPtr = here->SOI3DP_gbBinding->CSC ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3DP_dpPtr = here->SOI3DP_dpBinding->CSC ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3DP_spPtr = here->SOI3DP_spBinding->CSC ;

            if ((here->SOI3dNodePrime != 0) && (here->SOI3bNode != 0))
                here->SOI3DP_bPtr = here->SOI3DP_bBinding->CSC ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3gfNode != 0))
                here->SOI3SP_gfPtr = here->SOI3SP_gfBinding->CSC ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3gbNode != 0))
                here->SOI3SP_gbPtr = here->SOI3SP_gbBinding->CSC ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3dNodePrime != 0))
                here->SOI3SP_dpPtr = here->SOI3SP_dpBinding->CSC ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3sNodePrime != 0))
                here->SOI3SP_spPtr = here->SOI3SP_spBinding->CSC ;

            if ((here->SOI3sNodePrime != 0) && (here->SOI3bNode != 0))
                here->SOI3SP_bPtr = here->SOI3SP_bBinding->CSC ;

            if (here->SOI3rt == 0)
            {
                if ((here->SOI3toutNode != 0) && (here->SOI3branch != 0))
                    here->SOI3TOUT_ibrPtr = here->SOI3TOUT_ibrBinding->CSC ;

                if ((here->SOI3branch != 0) && (here->SOI3toutNode != 0))
                    here->SOI3IBR_toutPtr = here->SOI3IBR_toutBinding->CSC ;

            }
            else
            {
                if ((here->SOI3toutNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3TOUT_toutPtr = here->SOI3TOUT_toutBinding->CSC ;

                if (here->SOI3numThermalNodes > 1)
                {
                    if ((here->SOI3toutNode != 0) && (here->SOI3tout1Node != 0))
                        here->SOI3TOUT_tout1Ptr = here->SOI3TOUT_tout1Binding->CSC ;

                    if ((here->SOI3tout1Node != 0) && (here->SOI3toutNode != 0))
                        here->SOI3TOUT1_toutPtr = here->SOI3TOUT1_toutBinding->CSC ;

                    if ((here->SOI3tout1Node != 0) && (here->SOI3tout1Node != 0))
                        here->SOI3TOUT1_tout1Ptr = here->SOI3TOUT1_tout1Binding->CSC ;

                }
                if (here->SOI3numThermalNodes > 2)
                {
                    if ((here->SOI3tout1Node != 0) && (here->SOI3tout2Node != 0))
                        here->SOI3TOUT1_tout2Ptr = here->SOI3TOUT1_tout2Binding->CSC ;

                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout1Node != 0))
                        here->SOI3TOUT2_tout1Ptr = here->SOI3TOUT2_tout1Binding->CSC ;

                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout2Node != 0))
                        here->SOI3TOUT2_tout2Ptr = here->SOI3TOUT2_tout2Binding->CSC ;

                }
                if (here->SOI3numThermalNodes > 3)
                {
                    if ((here->SOI3tout2Node != 0) && (here->SOI3tout3Node != 0))
                        here->SOI3TOUT2_tout3Ptr = here->SOI3TOUT2_tout3Binding->CSC ;

                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout2Node != 0))
                        here->SOI3TOUT3_tout2Ptr = here->SOI3TOUT3_tout2Binding->CSC ;

                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout3Node != 0))
                        here->SOI3TOUT3_tout3Ptr = here->SOI3TOUT3_tout3Binding->CSC ;

                }
                if (here->SOI3numThermalNodes > 4)
                {
                    if ((here->SOI3tout3Node != 0) && (here->SOI3tout4Node != 0))
                        here->SOI3TOUT3_tout4Ptr = here->SOI3TOUT3_tout4Binding->CSC ;

                    if ((here->SOI3tout4Node != 0) && (here->SOI3tout3Node != 0))
                        here->SOI3TOUT4_tout3Ptr = here->SOI3TOUT4_tout3Binding->CSC ;

                    if ((here->SOI3tout4Node != 0) && (here->SOI3tout4Node != 0))
                        here->SOI3TOUT4_tout4Ptr = here->SOI3TOUT4_tout4Binding->CSC ;

                }
                if ((here->SOI3toutNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3TOUT_toutPtr = here->SOI3TOUT_toutBinding->CSC ;

                if ((here->SOI3toutNode != 0) && (here->SOI3gfNode != 0))
                    here->SOI3TOUT_gfPtr = here->SOI3TOUT_gfBinding->CSC ;

                if ((here->SOI3toutNode != 0) && (here->SOI3gbNode != 0))
                    here->SOI3TOUT_gbPtr = here->SOI3TOUT_gbBinding->CSC ;

                if ((here->SOI3toutNode != 0) && (here->SOI3dNodePrime != 0))
                    here->SOI3TOUT_dpPtr = here->SOI3TOUT_dpBinding->CSC ;

                if ((here->SOI3toutNode != 0) && (here->SOI3sNodePrime != 0))
                    here->SOI3TOUT_spPtr = here->SOI3TOUT_spBinding->CSC ;

                if ((here->SOI3toutNode != 0) && (here->SOI3bNode != 0))
                    here->SOI3TOUT_bPtr = here->SOI3TOUT_bBinding->CSC ;

                if ((here->SOI3gfNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3GF_toutPtr = here->SOI3GF_toutBinding->CSC ;

                if ((here->SOI3gbNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3GB_toutPtr = here->SOI3GB_toutBinding->CSC ;

                if ((here->SOI3dNodePrime != 0) && (here->SOI3toutNode != 0))
                    here->SOI3DP_toutPtr = here->SOI3DP_toutBinding->CSC ;

                if ((here->SOI3sNodePrime != 0) && (here->SOI3toutNode != 0))
                    here->SOI3SP_toutPtr = here->SOI3SP_toutBinding->CSC ;

                if ((here->SOI3bNode != 0) && (here->SOI3toutNode != 0))
                    here->SOI3B_toutPtr = here->SOI3B_toutBinding->CSC ;

            }
        }
    }

    return (OK) ;
}
