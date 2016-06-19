/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vbicdefs.h"
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
            XFOO(VBICcollCollPtr, VBICcollCollBinding, VBICcollNode, VBICcollNode);
            XFOO(VBICbaseBasePtr, VBICbaseBaseBinding, VBICbaseNode, VBICbaseNode);
            XFOO(VBICemitEmitPtr, VBICemitEmitBinding, VBICemitNode, VBICemitNode);
            XFOO(VBICsubsSubsPtr, VBICsubsSubsBinding, VBICsubsNode, VBICsubsNode);
            XFOO(VBICcollCXCollCXPtr, VBICcollCXCollCXBinding, VBICcollCXNode, VBICcollCXNode);
            XFOO(VBICcollCICollCIPtr, VBICcollCICollCIBinding, VBICcollCINode, VBICcollCINode);
            XFOO(VBICbaseBXBaseBXPtr, VBICbaseBXBaseBXBinding, VBICbaseBXNode, VBICbaseBXNode);
            XFOO(VBICbaseBIBaseBIPtr, VBICbaseBIBaseBIBinding, VBICbaseBINode, VBICbaseBINode);
            XFOO(VBICemitEIEmitEIPtr, VBICemitEIEmitEIBinding, VBICemitEINode, VBICemitEINode);
            XFOO(VBICbaseBPBaseBPPtr, VBICbaseBPBaseBPBinding, VBICbaseBPNode, VBICbaseBPNode);
            XFOO(VBICsubsSISubsSIPtr, VBICsubsSISubsSIBinding, VBICsubsSINode, VBICsubsSINode);
            XFOO(VBICbaseEmitPtr, VBICbaseEmitBinding, VBICbaseNode, VBICemitNode);
            XFOO(VBICemitBasePtr, VBICemitBaseBinding, VBICemitNode, VBICbaseNode);
            XFOO(VBICbaseCollPtr, VBICbaseCollBinding, VBICbaseNode, VBICcollNode);
            XFOO(VBICcollBasePtr, VBICcollBaseBinding, VBICcollNode, VBICbaseNode);
            XFOO(VBICcollCollCXPtr, VBICcollCollCXBinding, VBICcollNode, VBICcollCXNode);
            XFOO(VBICbaseBaseBXPtr, VBICbaseBaseBXBinding, VBICbaseNode, VBICbaseBXNode);
            XFOO(VBICemitEmitEIPtr, VBICemitEmitEIBinding, VBICemitNode, VBICemitEINode);
            XFOO(VBICsubsSubsSIPtr, VBICsubsSubsSIBinding, VBICsubsNode, VBICsubsSINode);
            XFOO(VBICcollCXCollCIPtr, VBICcollCXCollCIBinding, VBICcollCXNode, VBICcollCINode);
            XFOO(VBICcollCXBaseBXPtr, VBICcollCXBaseBXBinding, VBICcollCXNode, VBICbaseBXNode);
            XFOO(VBICcollCXBaseBIPtr, VBICcollCXBaseBIBinding, VBICcollCXNode, VBICbaseBINode);
            XFOO(VBICcollCXBaseBPPtr, VBICcollCXBaseBPBinding, VBICcollCXNode, VBICbaseBPNode);
            XFOO(VBICcollCIBaseBIPtr, VBICcollCIBaseBIBinding, VBICcollCINode, VBICbaseBINode);
            XFOO(VBICcollCIEmitEIPtr, VBICcollCIEmitEIBinding, VBICcollCINode, VBICemitEINode);
            XFOO(VBICbaseBXBaseBIPtr, VBICbaseBXBaseBIBinding, VBICbaseBXNode, VBICbaseBINode);
            XFOO(VBICbaseBXEmitEIPtr, VBICbaseBXEmitEIBinding, VBICbaseBXNode, VBICemitEINode);
            XFOO(VBICbaseBXBaseBPPtr, VBICbaseBXBaseBPBinding, VBICbaseBXNode, VBICbaseBPNode);
            XFOO(VBICbaseBXSubsSIPtr, VBICbaseBXSubsSIBinding, VBICbaseBXNode, VBICsubsSINode);
            XFOO(VBICbaseBIEmitEIPtr, VBICbaseBIEmitEIBinding, VBICbaseBINode, VBICemitEINode);
            XFOO(VBICbaseBPSubsSIPtr, VBICbaseBPSubsSIBinding, VBICbaseBPNode, VBICsubsSINode);
            XFOO(VBICcollCXCollPtr, VBICcollCXCollBinding, VBICcollCXNode, VBICcollNode);
            XFOO(VBICbaseBXBasePtr, VBICbaseBXBaseBinding, VBICbaseBXNode, VBICbaseNode);
            XFOO(VBICemitEIEmitPtr, VBICemitEIEmitBinding, VBICemitEINode, VBICemitNode);
            XFOO(VBICsubsSISubsPtr, VBICsubsSISubsBinding, VBICsubsSINode, VBICsubsNode);
            XFOO(VBICcollCICollCXPtr, VBICcollCICollCXBinding, VBICcollCINode, VBICcollCXNode);
            XFOO(VBICbaseBICollCXPtr, VBICbaseBICollCXBinding, VBICbaseBINode, VBICcollCXNode);
            XFOO(VBICbaseBPCollCXPtr, VBICbaseBPCollCXBinding, VBICbaseBPNode, VBICcollCXNode);
            XFOO(VBICbaseBXCollCIPtr, VBICbaseBXCollCIBinding, VBICbaseBXNode, VBICcollCINode);
            XFOO(VBICbaseBICollCIPtr, VBICbaseBICollCIBinding, VBICbaseBINode, VBICcollCINode);
            XFOO(VBICemitEICollCIPtr, VBICemitEICollCIBinding, VBICemitEINode, VBICcollCINode);
            XFOO(VBICbaseBPCollCIPtr, VBICbaseBPCollCIBinding, VBICbaseBPNode, VBICcollCINode);
            XFOO(VBICbaseBIBaseBXPtr, VBICbaseBIBaseBXBinding, VBICbaseBINode, VBICbaseBXNode);
            XFOO(VBICemitEIBaseBXPtr, VBICemitEIBaseBXBinding, VBICemitEINode, VBICbaseBXNode);
            XFOO(VBICbaseBPBaseBXPtr, VBICbaseBPBaseBXBinding, VBICbaseBPNode, VBICbaseBXNode);
            XFOO(VBICsubsSIBaseBXPtr, VBICsubsSIBaseBXBinding, VBICsubsSINode, VBICbaseBXNode);
            XFOO(VBICemitEIBaseBIPtr, VBICemitEIBaseBIBinding, VBICemitEINode, VBICbaseBINode);
            XFOO(VBICbaseBPBaseBIPtr, VBICbaseBPBaseBIBinding, VBICbaseBPNode, VBICbaseBINode);
            XFOO(VBICsubsSICollCIPtr, VBICsubsSICollCIBinding, VBICsubsSINode, VBICcollCINode);
            XFOO(VBICsubsSIBaseBIPtr, VBICsubsSIBaseBIBinding, VBICsubsSINode, VBICbaseBINode);
            XFOO(VBICsubsSIBaseBPPtr, VBICsubsSIBaseBPBinding, VBICsubsSINode, VBICbaseBPNode);
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
            BFOO(VBICcollCollPtr, VBICcollCollBinding, VBICcollNode, VBICcollNode);
            BFOO(VBICbaseBasePtr, VBICbaseBaseBinding, VBICbaseNode, VBICbaseNode);
            BFOO(VBICemitEmitPtr, VBICemitEmitBinding, VBICemitNode, VBICemitNode);
            BFOO(VBICsubsSubsPtr, VBICsubsSubsBinding, VBICsubsNode, VBICsubsNode);
            BFOO(VBICcollCXCollCXPtr, VBICcollCXCollCXBinding, VBICcollCXNode, VBICcollCXNode);
            BFOO(VBICcollCICollCIPtr, VBICcollCICollCIBinding, VBICcollCINode, VBICcollCINode);
            BFOO(VBICbaseBXBaseBXPtr, VBICbaseBXBaseBXBinding, VBICbaseBXNode, VBICbaseBXNode);
            BFOO(VBICbaseBIBaseBIPtr, VBICbaseBIBaseBIBinding, VBICbaseBINode, VBICbaseBINode);
            BFOO(VBICemitEIEmitEIPtr, VBICemitEIEmitEIBinding, VBICemitEINode, VBICemitEINode);
            BFOO(VBICbaseBPBaseBPPtr, VBICbaseBPBaseBPBinding, VBICbaseBPNode, VBICbaseBPNode);
            BFOO(VBICsubsSISubsSIPtr, VBICsubsSISubsSIBinding, VBICsubsSINode, VBICsubsSINode);
            BFOO(VBICbaseEmitPtr, VBICbaseEmitBinding, VBICbaseNode, VBICemitNode);
            BFOO(VBICemitBasePtr, VBICemitBaseBinding, VBICemitNode, VBICbaseNode);
            BFOO(VBICbaseCollPtr, VBICbaseCollBinding, VBICbaseNode, VBICcollNode);
            BFOO(VBICcollBasePtr, VBICcollBaseBinding, VBICcollNode, VBICbaseNode);
            BFOO(VBICcollCollCXPtr, VBICcollCollCXBinding, VBICcollNode, VBICcollCXNode);
            BFOO(VBICbaseBaseBXPtr, VBICbaseBaseBXBinding, VBICbaseNode, VBICbaseBXNode);
            BFOO(VBICemitEmitEIPtr, VBICemitEmitEIBinding, VBICemitNode, VBICemitEINode);
            BFOO(VBICsubsSubsSIPtr, VBICsubsSubsSIBinding, VBICsubsNode, VBICsubsSINode);
            BFOO(VBICcollCXCollCIPtr, VBICcollCXCollCIBinding, VBICcollCXNode, VBICcollCINode);
            BFOO(VBICcollCXBaseBXPtr, VBICcollCXBaseBXBinding, VBICcollCXNode, VBICbaseBXNode);
            BFOO(VBICcollCXBaseBIPtr, VBICcollCXBaseBIBinding, VBICcollCXNode, VBICbaseBINode);
            BFOO(VBICcollCXBaseBPPtr, VBICcollCXBaseBPBinding, VBICcollCXNode, VBICbaseBPNode);
            BFOO(VBICcollCIBaseBIPtr, VBICcollCIBaseBIBinding, VBICcollCINode, VBICbaseBINode);
            BFOO(VBICcollCIEmitEIPtr, VBICcollCIEmitEIBinding, VBICcollCINode, VBICemitEINode);
            BFOO(VBICbaseBXBaseBIPtr, VBICbaseBXBaseBIBinding, VBICbaseBXNode, VBICbaseBINode);
            BFOO(VBICbaseBXEmitEIPtr, VBICbaseBXEmitEIBinding, VBICbaseBXNode, VBICemitEINode);
            BFOO(VBICbaseBXBaseBPPtr, VBICbaseBXBaseBPBinding, VBICbaseBXNode, VBICbaseBPNode);
            BFOO(VBICbaseBXSubsSIPtr, VBICbaseBXSubsSIBinding, VBICbaseBXNode, VBICsubsSINode);
            BFOO(VBICbaseBIEmitEIPtr, VBICbaseBIEmitEIBinding, VBICbaseBINode, VBICemitEINode);
            BFOO(VBICbaseBPSubsSIPtr, VBICbaseBPSubsSIBinding, VBICbaseBPNode, VBICsubsSINode);
            BFOO(VBICcollCXCollPtr, VBICcollCXCollBinding, VBICcollCXNode, VBICcollNode);
            BFOO(VBICbaseBXBasePtr, VBICbaseBXBaseBinding, VBICbaseBXNode, VBICbaseNode);
            BFOO(VBICemitEIEmitPtr, VBICemitEIEmitBinding, VBICemitEINode, VBICemitNode);
            BFOO(VBICsubsSISubsPtr, VBICsubsSISubsBinding, VBICsubsSINode, VBICsubsNode);
            BFOO(VBICcollCICollCXPtr, VBICcollCICollCXBinding, VBICcollCINode, VBICcollCXNode);
            BFOO(VBICbaseBICollCXPtr, VBICbaseBICollCXBinding, VBICbaseBINode, VBICcollCXNode);
            BFOO(VBICbaseBPCollCXPtr, VBICbaseBPCollCXBinding, VBICbaseBPNode, VBICcollCXNode);
            BFOO(VBICbaseBXCollCIPtr, VBICbaseBXCollCIBinding, VBICbaseBXNode, VBICcollCINode);
            BFOO(VBICbaseBICollCIPtr, VBICbaseBICollCIBinding, VBICbaseBINode, VBICcollCINode);
            BFOO(VBICemitEICollCIPtr, VBICemitEICollCIBinding, VBICemitEINode, VBICcollCINode);
            BFOO(VBICbaseBPCollCIPtr, VBICbaseBPCollCIBinding, VBICbaseBPNode, VBICcollCINode);
            BFOO(VBICbaseBIBaseBXPtr, VBICbaseBIBaseBXBinding, VBICbaseBINode, VBICbaseBXNode);
            BFOO(VBICemitEIBaseBXPtr, VBICemitEIBaseBXBinding, VBICemitEINode, VBICbaseBXNode);
            BFOO(VBICbaseBPBaseBXPtr, VBICbaseBPBaseBXBinding, VBICbaseBPNode, VBICbaseBXNode);
            BFOO(VBICsubsSIBaseBXPtr, VBICsubsSIBaseBXBinding, VBICsubsSINode, VBICbaseBXNode);
            BFOO(VBICemitEIBaseBIPtr, VBICemitEIBaseBIBinding, VBICemitEINode, VBICbaseBINode);
            BFOO(VBICbaseBPBaseBIPtr, VBICbaseBPBaseBIBinding, VBICbaseBPNode, VBICbaseBINode);
            BFOO(VBICsubsSICollCIPtr, VBICsubsSICollCIBinding, VBICsubsSINode, VBICcollCINode);
            BFOO(VBICsubsSIBaseBIPtr, VBICsubsSIBaseBIBinding, VBICsubsSINode, VBICbaseBINode);
            BFOO(VBICsubsSIBaseBPPtr, VBICsubsSIBaseBPBinding, VBICsubsSINode, VBICbaseBPNode);
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
            CFOO(VBICcollCollPtr, VBICcollCollBinding, VBICcollNode, VBICcollNode);
            CFOO(VBICbaseBasePtr, VBICbaseBaseBinding, VBICbaseNode, VBICbaseNode);
            CFOO(VBICemitEmitPtr, VBICemitEmitBinding, VBICemitNode, VBICemitNode);
            CFOO(VBICsubsSubsPtr, VBICsubsSubsBinding, VBICsubsNode, VBICsubsNode);
            CFOO(VBICcollCXCollCXPtr, VBICcollCXCollCXBinding, VBICcollCXNode, VBICcollCXNode);
            CFOO(VBICcollCICollCIPtr, VBICcollCICollCIBinding, VBICcollCINode, VBICcollCINode);
            CFOO(VBICbaseBXBaseBXPtr, VBICbaseBXBaseBXBinding, VBICbaseBXNode, VBICbaseBXNode);
            CFOO(VBICbaseBIBaseBIPtr, VBICbaseBIBaseBIBinding, VBICbaseBINode, VBICbaseBINode);
            CFOO(VBICemitEIEmitEIPtr, VBICemitEIEmitEIBinding, VBICemitEINode, VBICemitEINode);
            CFOO(VBICbaseBPBaseBPPtr, VBICbaseBPBaseBPBinding, VBICbaseBPNode, VBICbaseBPNode);
            CFOO(VBICsubsSISubsSIPtr, VBICsubsSISubsSIBinding, VBICsubsSINode, VBICsubsSINode);
            CFOO(VBICbaseEmitPtr, VBICbaseEmitBinding, VBICbaseNode, VBICemitNode);
            CFOO(VBICemitBasePtr, VBICemitBaseBinding, VBICemitNode, VBICbaseNode);
            CFOO(VBICbaseCollPtr, VBICbaseCollBinding, VBICbaseNode, VBICcollNode);
            CFOO(VBICcollBasePtr, VBICcollBaseBinding, VBICcollNode, VBICbaseNode);
            CFOO(VBICcollCollCXPtr, VBICcollCollCXBinding, VBICcollNode, VBICcollCXNode);
            CFOO(VBICbaseBaseBXPtr, VBICbaseBaseBXBinding, VBICbaseNode, VBICbaseBXNode);
            CFOO(VBICemitEmitEIPtr, VBICemitEmitEIBinding, VBICemitNode, VBICemitEINode);
            CFOO(VBICsubsSubsSIPtr, VBICsubsSubsSIBinding, VBICsubsNode, VBICsubsSINode);
            CFOO(VBICcollCXCollCIPtr, VBICcollCXCollCIBinding, VBICcollCXNode, VBICcollCINode);
            CFOO(VBICcollCXBaseBXPtr, VBICcollCXBaseBXBinding, VBICcollCXNode, VBICbaseBXNode);
            CFOO(VBICcollCXBaseBIPtr, VBICcollCXBaseBIBinding, VBICcollCXNode, VBICbaseBINode);
            CFOO(VBICcollCXBaseBPPtr, VBICcollCXBaseBPBinding, VBICcollCXNode, VBICbaseBPNode);
            CFOO(VBICcollCIBaseBIPtr, VBICcollCIBaseBIBinding, VBICcollCINode, VBICbaseBINode);
            CFOO(VBICcollCIEmitEIPtr, VBICcollCIEmitEIBinding, VBICcollCINode, VBICemitEINode);
            CFOO(VBICbaseBXBaseBIPtr, VBICbaseBXBaseBIBinding, VBICbaseBXNode, VBICbaseBINode);
            CFOO(VBICbaseBXEmitEIPtr, VBICbaseBXEmitEIBinding, VBICbaseBXNode, VBICemitEINode);
            CFOO(VBICbaseBXBaseBPPtr, VBICbaseBXBaseBPBinding, VBICbaseBXNode, VBICbaseBPNode);
            CFOO(VBICbaseBXSubsSIPtr, VBICbaseBXSubsSIBinding, VBICbaseBXNode, VBICsubsSINode);
            CFOO(VBICbaseBIEmitEIPtr, VBICbaseBIEmitEIBinding, VBICbaseBINode, VBICemitEINode);
            CFOO(VBICbaseBPSubsSIPtr, VBICbaseBPSubsSIBinding, VBICbaseBPNode, VBICsubsSINode);
            CFOO(VBICcollCXCollPtr, VBICcollCXCollBinding, VBICcollCXNode, VBICcollNode);
            CFOO(VBICbaseBXBasePtr, VBICbaseBXBaseBinding, VBICbaseBXNode, VBICbaseNode);
            CFOO(VBICemitEIEmitPtr, VBICemitEIEmitBinding, VBICemitEINode, VBICemitNode);
            CFOO(VBICsubsSISubsPtr, VBICsubsSISubsBinding, VBICsubsSINode, VBICsubsNode);
            CFOO(VBICcollCICollCXPtr, VBICcollCICollCXBinding, VBICcollCINode, VBICcollCXNode);
            CFOO(VBICbaseBICollCXPtr, VBICbaseBICollCXBinding, VBICbaseBINode, VBICcollCXNode);
            CFOO(VBICbaseBPCollCXPtr, VBICbaseBPCollCXBinding, VBICbaseBPNode, VBICcollCXNode);
            CFOO(VBICbaseBXCollCIPtr, VBICbaseBXCollCIBinding, VBICbaseBXNode, VBICcollCINode);
            CFOO(VBICbaseBICollCIPtr, VBICbaseBICollCIBinding, VBICbaseBINode, VBICcollCINode);
            CFOO(VBICemitEICollCIPtr, VBICemitEICollCIBinding, VBICemitEINode, VBICcollCINode);
            CFOO(VBICbaseBPCollCIPtr, VBICbaseBPCollCIBinding, VBICbaseBPNode, VBICcollCINode);
            CFOO(VBICbaseBIBaseBXPtr, VBICbaseBIBaseBXBinding, VBICbaseBINode, VBICbaseBXNode);
            CFOO(VBICemitEIBaseBXPtr, VBICemitEIBaseBXBinding, VBICemitEINode, VBICbaseBXNode);
            CFOO(VBICbaseBPBaseBXPtr, VBICbaseBPBaseBXBinding, VBICbaseBPNode, VBICbaseBXNode);
            CFOO(VBICsubsSIBaseBXPtr, VBICsubsSIBaseBXBinding, VBICsubsSINode, VBICbaseBXNode);
            CFOO(VBICemitEIBaseBIPtr, VBICemitEIBaseBIBinding, VBICemitEINode, VBICbaseBINode);
            CFOO(VBICbaseBPBaseBIPtr, VBICbaseBPBaseBIBinding, VBICbaseBPNode, VBICbaseBINode);
            CFOO(VBICsubsSICollCIPtr, VBICsubsSICollCIBinding, VBICsubsSINode, VBICcollCINode);
            CFOO(VBICsubsSIBaseBIPtr, VBICsubsSIBaseBIBinding, VBICsubsSINode, VBICbaseBINode);
            CFOO(VBICsubsSIBaseBPPtr, VBICsubsSIBaseBPBinding, VBICsubsSINode, VBICbaseBPNode);
        }
    }

    return (OK) ;
}
