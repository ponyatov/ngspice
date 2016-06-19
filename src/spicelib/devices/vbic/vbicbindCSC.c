/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vbicdefs.h"
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
VBICbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    VBICmodel *model = (VBICmodel *)inModel ;
    VBICinstance *here ;
    double *i ;
    BindElement *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->CKTbindStruct ;
    nz = (size_t)ckt->CKTmatrix->CKTklunz ;

    /* loop through all the VBIC models */
    for ( ; model != NULL ; model = model->VBICnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VBICinstances ; here != NULL ; here = here->VBICnextInstance)
        {
            if ((here->VBICcollNode != 0) && (here->VBICcollNode != 0))
            {
                i = here->VBICcollCollPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCollBinding = matched ;
                here->VBICcollCollPtr = matched->CSC ;
            }

            if ((here->VBICbaseNode != 0) && (here->VBICbaseNode != 0))
            {
                i = here->VBICbaseBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBaseBinding = matched ;
                here->VBICbaseBasePtr = matched->CSC ;
            }

            if ((here->VBICemitNode != 0) && (here->VBICemitNode != 0))
            {
                i = here->VBICemitEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEmitBinding = matched ;
                here->VBICemitEmitPtr = matched->CSC ;
            }

            if ((here->VBICsubsNode != 0) && (here->VBICsubsNode != 0))
            {
                i = here->VBICsubsSubsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSubsBinding = matched ;
                here->VBICsubsSubsPtr = matched->CSC ;
            }

            if ((here->VBICcollCXNode != 0) && (here->VBICcollCXNode != 0))
            {
                i = here->VBICcollCXCollCXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCXCollCXBinding = matched ;
                here->VBICcollCXCollCXPtr = matched->CSC ;
            }

            if ((here->VBICcollCINode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICcollCICollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCICollCIBinding = matched ;
                here->VBICcollCICollCIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICbaseBXBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXBaseBXBinding = matched ;
                here->VBICbaseBXBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICbaseBINode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICbaseBIBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBIBaseBIBinding = matched ;
                here->VBICbaseBIBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICemitEINode != 0) && (here->VBICemitEINode != 0))
            {
                i = here->VBICemitEIEmitEIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEIEmitEIBinding = matched ;
                here->VBICemitEIEmitEIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBPNode != 0))
            {
                i = here->VBICbaseBPBaseBPPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBPBaseBPBinding = matched ;
                here->VBICbaseBPBaseBPPtr = matched->CSC ;
            }

            if ((here->VBICsubsSINode != 0) && (here->VBICsubsSINode != 0))
            {
                i = here->VBICsubsSISubsSIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSISubsSIBinding = matched ;
                here->VBICsubsSISubsSIPtr = matched->CSC ;
            }

            if ((here->VBICbaseNode != 0) && (here->VBICemitNode != 0))
            {
                i = here->VBICbaseEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseEmitBinding = matched ;
                here->VBICbaseEmitPtr = matched->CSC ;
            }

            if ((here->VBICemitNode != 0) && (here->VBICbaseNode != 0))
            {
                i = here->VBICemitBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitBaseBinding = matched ;
                here->VBICemitBasePtr = matched->CSC ;
            }

            if ((here->VBICbaseNode != 0) && (here->VBICcollNode != 0))
            {
                i = here->VBICbaseCollPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseCollBinding = matched ;
                here->VBICbaseCollPtr = matched->CSC ;
            }

            if ((here->VBICcollNode != 0) && (here->VBICbaseNode != 0))
            {
                i = here->VBICcollBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollBaseBinding = matched ;
                here->VBICcollBasePtr = matched->CSC ;
            }

            if ((here->VBICcollNode != 0) && (here->VBICcollCXNode != 0))
            {
                i = here->VBICcollCollCXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCollCXBinding = matched ;
                here->VBICcollCollCXPtr = matched->CSC ;
            }

            if ((here->VBICbaseNode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICbaseBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBaseBXBinding = matched ;
                here->VBICbaseBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICemitNode != 0) && (here->VBICemitEINode != 0))
            {
                i = here->VBICemitEmitEIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEmitEIBinding = matched ;
                here->VBICemitEmitEIPtr = matched->CSC ;
            }

            if ((here->VBICsubsNode != 0) && (here->VBICsubsSINode != 0))
            {
                i = here->VBICsubsSubsSIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSubsSIBinding = matched ;
                here->VBICsubsSubsSIPtr = matched->CSC ;
            }

            if ((here->VBICcollCXNode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICcollCXCollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCXCollCIBinding = matched ;
                here->VBICcollCXCollCIPtr = matched->CSC ;
            }

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICcollCXBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCXBaseBXBinding = matched ;
                here->VBICcollCXBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICcollCXBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCXBaseBIBinding = matched ;
                here->VBICcollCXBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBPNode != 0))
            {
                i = here->VBICcollCXBaseBPPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCXBaseBPBinding = matched ;
                here->VBICcollCXBaseBPPtr = matched->CSC ;
            }

            if ((here->VBICcollCINode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICcollCIBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCIBaseBIBinding = matched ;
                here->VBICcollCIBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICcollCINode != 0) && (here->VBICemitEINode != 0))
            {
                i = here->VBICcollCIEmitEIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCIEmitEIBinding = matched ;
                here->VBICcollCIEmitEIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICbaseBXBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXBaseBIBinding = matched ;
                here->VBICbaseBXBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICemitEINode != 0))
            {
                i = here->VBICbaseBXEmitEIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXEmitEIBinding = matched ;
                here->VBICbaseBXEmitEIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBPNode != 0))
            {
                i = here->VBICbaseBXBaseBPPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXBaseBPBinding = matched ;
                here->VBICbaseBXBaseBPPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICsubsSINode != 0))
            {
                i = here->VBICbaseBXSubsSIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXSubsSIBinding = matched ;
                here->VBICbaseBXSubsSIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBINode != 0) && (here->VBICemitEINode != 0))
            {
                i = here->VBICbaseBIEmitEIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBIEmitEIBinding = matched ;
                here->VBICbaseBIEmitEIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBPNode != 0) && (here->VBICsubsSINode != 0))
            {
                i = here->VBICbaseBPSubsSIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBPSubsSIBinding = matched ;
                here->VBICbaseBPSubsSIPtr = matched->CSC ;
            }

            if ((here->VBICcollCXNode != 0) && (here->VBICcollNode != 0))
            {
                i = here->VBICcollCXCollPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCXCollBinding = matched ;
                here->VBICcollCXCollPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseNode != 0))
            {
                i = here->VBICbaseBXBasePtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXBaseBinding = matched ;
                here->VBICbaseBXBasePtr = matched->CSC ;
            }

            if ((here->VBICemitEINode != 0) && (here->VBICemitNode != 0))
            {
                i = here->VBICemitEIEmitPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEIEmitBinding = matched ;
                here->VBICemitEIEmitPtr = matched->CSC ;
            }

            if ((here->VBICsubsSINode != 0) && (here->VBICsubsNode != 0))
            {
                i = here->VBICsubsSISubsPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSISubsBinding = matched ;
                here->VBICsubsSISubsPtr = matched->CSC ;
            }

            if ((here->VBICcollCINode != 0) && (here->VBICcollCXNode != 0))
            {
                i = here->VBICcollCICollCXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICcollCICollCXBinding = matched ;
                here->VBICcollCICollCXPtr = matched->CSC ;
            }

            if ((here->VBICbaseBINode != 0) && (here->VBICcollCXNode != 0))
            {
                i = here->VBICbaseBICollCXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBICollCXBinding = matched ;
                here->VBICbaseBICollCXPtr = matched->CSC ;
            }

            if ((here->VBICbaseBPNode != 0) && (here->VBICcollCXNode != 0))
            {
                i = here->VBICbaseBPCollCXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBPCollCXBinding = matched ;
                here->VBICbaseBPCollCXPtr = matched->CSC ;
            }

            if ((here->VBICbaseBXNode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICbaseBXCollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBXCollCIBinding = matched ;
                here->VBICbaseBXCollCIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBINode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICbaseBICollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBICollCIBinding = matched ;
                here->VBICbaseBICollCIPtr = matched->CSC ;
            }

            if ((here->VBICemitEINode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICemitEICollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEICollCIBinding = matched ;
                here->VBICemitEICollCIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBPNode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICbaseBPCollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBPCollCIBinding = matched ;
                here->VBICbaseBPCollCIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBINode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICbaseBIBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBIBaseBXBinding = matched ;
                here->VBICbaseBIBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICemitEINode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICemitEIBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEIBaseBXBinding = matched ;
                here->VBICemitEIBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICbaseBPBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBPBaseBXBinding = matched ;
                here->VBICbaseBPBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBXNode != 0))
            {
                i = here->VBICsubsSIBaseBXPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSIBaseBXBinding = matched ;
                here->VBICsubsSIBaseBXPtr = matched->CSC ;
            }

            if ((here->VBICemitEINode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICemitEIBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICemitEIBaseBIBinding = matched ;
                here->VBICemitEIBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICbaseBPBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICbaseBPBaseBIBinding = matched ;
                here->VBICbaseBPBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICsubsSINode != 0) && (here->VBICcollCINode != 0))
            {
                i = here->VBICsubsSICollCIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSICollCIBinding = matched ;
                here->VBICsubsSICollCIPtr = matched->CSC ;
            }

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBINode != 0))
            {
                i = here->VBICsubsSIBaseBIPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSIBaseBIBinding = matched ;
                here->VBICsubsSIBaseBIPtr = matched->CSC ;
            }

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBPNode != 0))
            {
                i = here->VBICsubsSIBaseBPPtr ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VBICsubsSIBaseBPBinding = matched ;
                here->VBICsubsSIBaseBPPtr = matched->CSC ;
            }

        }
    }

    return (OK) ;
}

int
VBICbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    VBICmodel *model = (VBICmodel *)inModel ;
    VBICinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VBIC models */
    for ( ; model != NULL ; model = model->VBICnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VBICinstances ; here != NULL ; here = here->VBICnextInstance)
        {
            if ((here->VBICcollNode != 0) && (here->VBICcollNode != 0))
                here->VBICcollCollPtr = here->VBICcollCollBinding->CSC_Complex ;

            if ((here->VBICbaseNode != 0) && (here->VBICbaseNode != 0))
                here->VBICbaseBasePtr = here->VBICbaseBaseBinding->CSC_Complex ;

            if ((here->VBICemitNode != 0) && (here->VBICemitNode != 0))
                here->VBICemitEmitPtr = here->VBICemitEmitBinding->CSC_Complex ;

            if ((here->VBICsubsNode != 0) && (here->VBICsubsNode != 0))
                here->VBICsubsSubsPtr = here->VBICsubsSubsBinding->CSC_Complex ;

            if ((here->VBICcollCXNode != 0) && (here->VBICcollCXNode != 0))
                here->VBICcollCXCollCXPtr = here->VBICcollCXCollCXBinding->CSC_Complex ;

            if ((here->VBICcollCINode != 0) && (here->VBICcollCINode != 0))
                here->VBICcollCICollCIPtr = here->VBICcollCICollCIBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBXBaseBXPtr = here->VBICbaseBXBaseBXBinding->CSC_Complex ;

            if ((here->VBICbaseBINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICbaseBIBaseBIPtr = here->VBICbaseBIBaseBIBinding->CSC_Complex ;

            if ((here->VBICemitEINode != 0) && (here->VBICemitEINode != 0))
                here->VBICemitEIEmitEIPtr = here->VBICemitEIEmitEIBinding->CSC_Complex ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICbaseBPBaseBPPtr = here->VBICbaseBPBaseBPBinding->CSC_Complex ;

            if ((here->VBICsubsSINode != 0) && (here->VBICsubsSINode != 0))
                here->VBICsubsSISubsSIPtr = here->VBICsubsSISubsSIBinding->CSC_Complex ;

            if ((here->VBICbaseNode != 0) && (here->VBICemitNode != 0))
                here->VBICbaseEmitPtr = here->VBICbaseEmitBinding->CSC_Complex ;

            if ((here->VBICemitNode != 0) && (here->VBICbaseNode != 0))
                here->VBICemitBasePtr = here->VBICemitBaseBinding->CSC_Complex ;

            if ((here->VBICbaseNode != 0) && (here->VBICcollNode != 0))
                here->VBICbaseCollPtr = here->VBICbaseCollBinding->CSC_Complex ;

            if ((here->VBICcollNode != 0) && (here->VBICbaseNode != 0))
                here->VBICcollBasePtr = here->VBICcollBaseBinding->CSC_Complex ;

            if ((here->VBICcollNode != 0) && (here->VBICcollCXNode != 0))
                here->VBICcollCollCXPtr = here->VBICcollCollCXBinding->CSC_Complex ;

            if ((here->VBICbaseNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBaseBXPtr = here->VBICbaseBaseBXBinding->CSC_Complex ;

            if ((here->VBICemitNode != 0) && (here->VBICemitEINode != 0))
                here->VBICemitEmitEIPtr = here->VBICemitEmitEIBinding->CSC_Complex ;

            if ((here->VBICsubsNode != 0) && (here->VBICsubsSINode != 0))
                here->VBICsubsSubsSIPtr = here->VBICsubsSubsSIBinding->CSC_Complex ;

            if ((here->VBICcollCXNode != 0) && (here->VBICcollCINode != 0))
                here->VBICcollCXCollCIPtr = here->VBICcollCXCollCIBinding->CSC_Complex ;

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICcollCXBaseBXPtr = here->VBICcollCXBaseBXBinding->CSC_Complex ;

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBINode != 0))
                here->VBICcollCXBaseBIPtr = here->VBICcollCXBaseBIBinding->CSC_Complex ;

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICcollCXBaseBPPtr = here->VBICcollCXBaseBPBinding->CSC_Complex ;

            if ((here->VBICcollCINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICcollCIBaseBIPtr = here->VBICcollCIBaseBIBinding->CSC_Complex ;

            if ((here->VBICcollCINode != 0) && (here->VBICemitEINode != 0))
                here->VBICcollCIEmitEIPtr = here->VBICcollCIEmitEIBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBINode != 0))
                here->VBICbaseBXBaseBIPtr = here->VBICbaseBXBaseBIBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICemitEINode != 0))
                here->VBICbaseBXEmitEIPtr = here->VBICbaseBXEmitEIBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICbaseBXBaseBPPtr = here->VBICbaseBXBaseBPBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICsubsSINode != 0))
                here->VBICbaseBXSubsSIPtr = here->VBICbaseBXSubsSIBinding->CSC_Complex ;

            if ((here->VBICbaseBINode != 0) && (here->VBICemitEINode != 0))
                here->VBICbaseBIEmitEIPtr = here->VBICbaseBIEmitEIBinding->CSC_Complex ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICsubsSINode != 0))
                here->VBICbaseBPSubsSIPtr = here->VBICbaseBPSubsSIBinding->CSC_Complex ;

            if ((here->VBICcollCXNode != 0) && (here->VBICcollNode != 0))
                here->VBICcollCXCollPtr = here->VBICcollCXCollBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseNode != 0))
                here->VBICbaseBXBasePtr = here->VBICbaseBXBaseBinding->CSC_Complex ;

            if ((here->VBICemitEINode != 0) && (here->VBICemitNode != 0))
                here->VBICemitEIEmitPtr = here->VBICemitEIEmitBinding->CSC_Complex ;

            if ((here->VBICsubsSINode != 0) && (here->VBICsubsNode != 0))
                here->VBICsubsSISubsPtr = here->VBICsubsSISubsBinding->CSC_Complex ;

            if ((here->VBICcollCINode != 0) && (here->VBICcollCXNode != 0))
                here->VBICcollCICollCXPtr = here->VBICcollCICollCXBinding->CSC_Complex ;

            if ((here->VBICbaseBINode != 0) && (here->VBICcollCXNode != 0))
                here->VBICbaseBICollCXPtr = here->VBICbaseBICollCXBinding->CSC_Complex ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICcollCXNode != 0))
                here->VBICbaseBPCollCXPtr = here->VBICbaseBPCollCXBinding->CSC_Complex ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICcollCINode != 0))
                here->VBICbaseBXCollCIPtr = here->VBICbaseBXCollCIBinding->CSC_Complex ;

            if ((here->VBICbaseBINode != 0) && (here->VBICcollCINode != 0))
                here->VBICbaseBICollCIPtr = here->VBICbaseBICollCIBinding->CSC_Complex ;

            if ((here->VBICemitEINode != 0) && (here->VBICcollCINode != 0))
                here->VBICemitEICollCIPtr = here->VBICemitEICollCIBinding->CSC_Complex ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICcollCINode != 0))
                here->VBICbaseBPCollCIPtr = here->VBICbaseBPCollCIBinding->CSC_Complex ;

            if ((here->VBICbaseBINode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBIBaseBXPtr = here->VBICbaseBIBaseBXBinding->CSC_Complex ;

            if ((here->VBICemitEINode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICemitEIBaseBXPtr = here->VBICemitEIBaseBXBinding->CSC_Complex ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBPBaseBXPtr = here->VBICbaseBPBaseBXBinding->CSC_Complex ;

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICsubsSIBaseBXPtr = here->VBICsubsSIBaseBXBinding->CSC_Complex ;

            if ((here->VBICemitEINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICemitEIBaseBIPtr = here->VBICemitEIBaseBIBinding->CSC_Complex ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBINode != 0))
                here->VBICbaseBPBaseBIPtr = here->VBICbaseBPBaseBIBinding->CSC_Complex ;

            if ((here->VBICsubsSINode != 0) && (here->VBICcollCINode != 0))
                here->VBICsubsSICollCIPtr = here->VBICsubsSICollCIBinding->CSC_Complex ;

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICsubsSIBaseBIPtr = here->VBICsubsSIBaseBIBinding->CSC_Complex ;

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICsubsSIBaseBPPtr = here->VBICsubsSIBaseBPBinding->CSC_Complex ;

        }
    }

    return (OK) ;
}

int
VBICbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    VBICmodel *model = (VBICmodel *)inModel ;
    VBICinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VBIC models */
    for ( ; model != NULL ; model = model->VBICnextModel)
    {
        /* loop through all the instances of the model */
        for (here = model->VBICinstances ; here != NULL ; here = here->VBICnextInstance)
        {
            if ((here->VBICcollNode != 0) && (here->VBICcollNode != 0))
                here->VBICcollCollPtr = here->VBICcollCollBinding->CSC ;

            if ((here->VBICbaseNode != 0) && (here->VBICbaseNode != 0))
                here->VBICbaseBasePtr = here->VBICbaseBaseBinding->CSC ;

            if ((here->VBICemitNode != 0) && (here->VBICemitNode != 0))
                here->VBICemitEmitPtr = here->VBICemitEmitBinding->CSC ;

            if ((here->VBICsubsNode != 0) && (here->VBICsubsNode != 0))
                here->VBICsubsSubsPtr = here->VBICsubsSubsBinding->CSC ;

            if ((here->VBICcollCXNode != 0) && (here->VBICcollCXNode != 0))
                here->VBICcollCXCollCXPtr = here->VBICcollCXCollCXBinding->CSC ;

            if ((here->VBICcollCINode != 0) && (here->VBICcollCINode != 0))
                here->VBICcollCICollCIPtr = here->VBICcollCICollCIBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBXBaseBXPtr = here->VBICbaseBXBaseBXBinding->CSC ;

            if ((here->VBICbaseBINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICbaseBIBaseBIPtr = here->VBICbaseBIBaseBIBinding->CSC ;

            if ((here->VBICemitEINode != 0) && (here->VBICemitEINode != 0))
                here->VBICemitEIEmitEIPtr = here->VBICemitEIEmitEIBinding->CSC ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICbaseBPBaseBPPtr = here->VBICbaseBPBaseBPBinding->CSC ;

            if ((here->VBICsubsSINode != 0) && (here->VBICsubsSINode != 0))
                here->VBICsubsSISubsSIPtr = here->VBICsubsSISubsSIBinding->CSC ;

            if ((here->VBICbaseNode != 0) && (here->VBICemitNode != 0))
                here->VBICbaseEmitPtr = here->VBICbaseEmitBinding->CSC ;

            if ((here->VBICemitNode != 0) && (here->VBICbaseNode != 0))
                here->VBICemitBasePtr = here->VBICemitBaseBinding->CSC ;

            if ((here->VBICbaseNode != 0) && (here->VBICcollNode != 0))
                here->VBICbaseCollPtr = here->VBICbaseCollBinding->CSC ;

            if ((here->VBICcollNode != 0) && (here->VBICbaseNode != 0))
                here->VBICcollBasePtr = here->VBICcollBaseBinding->CSC ;

            if ((here->VBICcollNode != 0) && (here->VBICcollCXNode != 0))
                here->VBICcollCollCXPtr = here->VBICcollCollCXBinding->CSC ;

            if ((here->VBICbaseNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBaseBXPtr = here->VBICbaseBaseBXBinding->CSC ;

            if ((here->VBICemitNode != 0) && (here->VBICemitEINode != 0))
                here->VBICemitEmitEIPtr = here->VBICemitEmitEIBinding->CSC ;

            if ((here->VBICsubsNode != 0) && (here->VBICsubsSINode != 0))
                here->VBICsubsSubsSIPtr = here->VBICsubsSubsSIBinding->CSC ;

            if ((here->VBICcollCXNode != 0) && (here->VBICcollCINode != 0))
                here->VBICcollCXCollCIPtr = here->VBICcollCXCollCIBinding->CSC ;

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICcollCXBaseBXPtr = here->VBICcollCXBaseBXBinding->CSC ;

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBINode != 0))
                here->VBICcollCXBaseBIPtr = here->VBICcollCXBaseBIBinding->CSC ;

            if ((here->VBICcollCXNode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICcollCXBaseBPPtr = here->VBICcollCXBaseBPBinding->CSC ;

            if ((here->VBICcollCINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICcollCIBaseBIPtr = here->VBICcollCIBaseBIBinding->CSC ;

            if ((here->VBICcollCINode != 0) && (here->VBICemitEINode != 0))
                here->VBICcollCIEmitEIPtr = here->VBICcollCIEmitEIBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBINode != 0))
                here->VBICbaseBXBaseBIPtr = here->VBICbaseBXBaseBIBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICemitEINode != 0))
                here->VBICbaseBXEmitEIPtr = here->VBICbaseBXEmitEIBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICbaseBXBaseBPPtr = here->VBICbaseBXBaseBPBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICsubsSINode != 0))
                here->VBICbaseBXSubsSIPtr = here->VBICbaseBXSubsSIBinding->CSC ;

            if ((here->VBICbaseBINode != 0) && (here->VBICemitEINode != 0))
                here->VBICbaseBIEmitEIPtr = here->VBICbaseBIEmitEIBinding->CSC ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICsubsSINode != 0))
                here->VBICbaseBPSubsSIPtr = here->VBICbaseBPSubsSIBinding->CSC ;

            if ((here->VBICcollCXNode != 0) && (here->VBICcollNode != 0))
                here->VBICcollCXCollPtr = here->VBICcollCXCollBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICbaseNode != 0))
                here->VBICbaseBXBasePtr = here->VBICbaseBXBaseBinding->CSC ;

            if ((here->VBICemitEINode != 0) && (here->VBICemitNode != 0))
                here->VBICemitEIEmitPtr = here->VBICemitEIEmitBinding->CSC ;

            if ((here->VBICsubsSINode != 0) && (here->VBICsubsNode != 0))
                here->VBICsubsSISubsPtr = here->VBICsubsSISubsBinding->CSC ;

            if ((here->VBICcollCINode != 0) && (here->VBICcollCXNode != 0))
                here->VBICcollCICollCXPtr = here->VBICcollCICollCXBinding->CSC ;

            if ((here->VBICbaseBINode != 0) && (here->VBICcollCXNode != 0))
                here->VBICbaseBICollCXPtr = here->VBICbaseBICollCXBinding->CSC ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICcollCXNode != 0))
                here->VBICbaseBPCollCXPtr = here->VBICbaseBPCollCXBinding->CSC ;

            if ((here->VBICbaseBXNode != 0) && (here->VBICcollCINode != 0))
                here->VBICbaseBXCollCIPtr = here->VBICbaseBXCollCIBinding->CSC ;

            if ((here->VBICbaseBINode != 0) && (here->VBICcollCINode != 0))
                here->VBICbaseBICollCIPtr = here->VBICbaseBICollCIBinding->CSC ;

            if ((here->VBICemitEINode != 0) && (here->VBICcollCINode != 0))
                here->VBICemitEICollCIPtr = here->VBICemitEICollCIBinding->CSC ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICcollCINode != 0))
                here->VBICbaseBPCollCIPtr = here->VBICbaseBPCollCIBinding->CSC ;

            if ((here->VBICbaseBINode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBIBaseBXPtr = here->VBICbaseBIBaseBXBinding->CSC ;

            if ((here->VBICemitEINode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICemitEIBaseBXPtr = here->VBICemitEIBaseBXBinding->CSC ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICbaseBPBaseBXPtr = here->VBICbaseBPBaseBXBinding->CSC ;

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBXNode != 0))
                here->VBICsubsSIBaseBXPtr = here->VBICsubsSIBaseBXBinding->CSC ;

            if ((here->VBICemitEINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICemitEIBaseBIPtr = here->VBICemitEIBaseBIBinding->CSC ;

            if ((here->VBICbaseBPNode != 0) && (here->VBICbaseBINode != 0))
                here->VBICbaseBPBaseBIPtr = here->VBICbaseBPBaseBIBinding->CSC ;

            if ((here->VBICsubsSINode != 0) && (here->VBICcollCINode != 0))
                here->VBICsubsSICollCIPtr = here->VBICsubsSICollCIBinding->CSC ;

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBINode != 0))
                here->VBICsubsSIBaseBIPtr = here->VBICsubsSIBaseBIBinding->CSC ;

            if ((here->VBICsubsSINode != 0) && (here->VBICbaseBPNode != 0))
                here->VBICsubsSIBaseBPPtr = here->VBICsubsSIBaseBPBinding->CSC ;

        }
    }

    return (OK) ;
}
