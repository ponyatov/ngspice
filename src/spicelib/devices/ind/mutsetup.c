/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Thomas L. Quarles
**********/

/* load the inductor structure with those pointers needed later
 * for fast matrix loading
 */

#include "ngspice/ngspice.h"
#include "ngspice/ifsim.h"
#include "ngspice/smpdefs.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"


#define TSTALLOC(ptr, first, second)                                    \
    do {                                                                \
        if ((here->ptr = SMPmakeElt(matrix, here->first, here->second)) == NULL) { \
            return(E_NOMEM);                                            \
        }                                                               \
    } while(0)


#ifdef MUTUAL

int
MUTsetup(SMPmatrix *matrix, GENmodel *inModel, CKTcircuit *ckt, int *states)
{
    MUTmodel *model = (MUTmodel*) inModel;
    MUTinstance *here;

    NG_IGNORE(states);

    MUTfree_inductanceSets(ckt);

    for (; model; model = model->MUTnextModel)
        for (here = model->MUTinstances; here; here = here->MUTnextInstance) {

            struct INDmatrixSet *temp;
            int ktype = CKTtypelook("Inductor");

            if (ktype <= 0) {
                SPfrontEnd->IFerrorf (ERR_PANIC,
                                      "mutual inductor, but inductors not available!");
                return(E_INTERN);
            }

            if (!here->MUTind1)
                here->MUTind1 = (INDinstance *) CKTfndDev(ckt, here->MUTindName1);
            if (!here->MUTind1) {
                SPfrontEnd->IFerrorf (ERR_WARNING,
                                      "%s: coupling to non-existant inductor %s.",
                                      here->MUTname, here->MUTindName1);
            }
            if (!here->MUTind2)
                here->MUTind2 = (INDinstance *) CKTfndDev(ckt, here->MUTindName2);
            if (!here->MUTind2) {
                SPfrontEnd->IFerrorf (ERR_WARNING,
                                      "%s: coupling to non-existant inductor %s.",
                                      here->MUTname, here->MUTindName2);
            }

            /* Assign 'setIndex' and 'matrixIndex' for L matrix */
            if (!here->MUTind1->setPtr && !here->MUTind2->setPtr) {
                /* Create the set */
                temp = TMALLOC (struct INDmatrixSet, 1);
                temp->INDmatrixSize = 2;
                temp->next = ckt->inductanceMatrixSets;
                ckt->inductanceMatrixSets = temp;
                temp->Xindhead = here->MUTind1;
                here->MUTind1->Xnext = here->MUTind2;
                here->MUTind2->Xnext = NULL;
                here->MUTind1->setPtr = temp;
                here->MUTind2->setPtr = temp;
                temp->Xmuthead = here;
                here->Xnext = NULL;
            } else if (here->MUTind1->setPtr && !here->MUTind2->setPtr) {
                /* Add the new MUTind2 into the set */
                temp = here->MUTind1->setPtr;
                temp->INDmatrixSize++;
                here->MUTind2->Xnext = temp->Xindhead;
                temp->Xindhead = here->MUTind2;
                here->Xnext = temp->Xmuthead;
                temp->Xmuthead = here;
                here->MUTind2->setPtr = temp;
            } else if (!here->MUTind1->setPtr && here->MUTind2->setPtr) {
                /* Add the new MUTind1 into the set */
                temp = here->MUTind2->setPtr;
                temp->INDmatrixSize++;
                here->MUTind1->Xnext = temp->Xindhead;
                temp->Xindhead = here->MUTind1;
                here->Xnext = temp->Xmuthead;
                temp->Xmuthead = here;
                here->MUTind1->setPtr = temp;
            } else if (here->MUTind1->setPtr == here->MUTind2->setPtr) {
                /* Add only the K coefficient into the set */
                temp = here->MUTind2->setPtr;
                here->Xnext = temp->Xmuthead;
                temp->Xmuthead = here;
            } else {
                struct INDmatrixSet *s1 = here->MUTind1->setPtr;
                struct INDmatrixSet *s2 = here->MUTind2->setPtr;
                MUTinstance *hm;
                INDinstance *hi;
                // append set2 to set1, leave a consumed set2 behind
                s1->INDmatrixSize += s2->INDmatrixSize;
                s2->INDmatrixSize = 0;
                for (hi = s2->Xindhead; hi; hi = hi->Xnext) {
                    hi->setPtr = s1;
                    if (!hi->Xnext)
                        break;
                }
                hi->Xnext = s1->Xindhead;
                s1->Xindhead = s2->Xindhead;
                s2->Xindhead = NULL;
                for (hm = s2->Xmuthead; hm; hm = hm->Xnext)
                    if (!hm->Xnext)
                        break;
                hm->Xnext = s1->Xmuthead;
                here->Xnext = s2->Xmuthead;
                s1->Xmuthead = here;
                s2->Xmuthead = NULL;
            }

            TSTALLOC(MUTbr1br2, MUTind1->INDbrEq, MUTind2->INDbrEq);
            TSTALLOC(MUTbr2br1, MUTind2->INDbrEq, MUTind1->INDbrEq);
        }

    return(OK);
}


void
MUTfree_inductanceSets(CKTcircuit *ckt)
{
    struct INDmatrixSet *temp = ckt->inductanceMatrixSets;
    while (temp) {
        struct INDmatrixSet *next_temp = temp->next;
        tfree(temp);
        temp = next_temp;
    }
    ckt->inductanceMatrixSets = NULL;
}

#endif
