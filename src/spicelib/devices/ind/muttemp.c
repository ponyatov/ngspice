/**********
Copyright 2003 Paolo Nenzi
Author: 2003 Paolo Nenzi
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"


static void MUTfree_inductanceSets(struct INDmatrixSet *temp);


static int
cholesky(double *a, int n)
{
#define A(r,c) a[n*r + c]
    int i, j, k;
    if (0)
        for (i = 0; i < n; i++) {
            for (j = 0; j <= i; j++)
                printf(" %10g", A(i,j));
            printf("\n");
        }
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++) {
            double Summe = A(i, j);
            for (k = 0; k < j; k++)
                Summe -= A(i, k) * A(j, k);
            if (i > j)
                A(i, j) = Summe / A(j, j);
            else if (Summe > 0)
                A(i, i) = sqrt(Summe);
            else
                return 0;
        }
    if (0)
        for (i = 0; i < n; i++) {
            for (j = 0; j <= i; j++)
                printf(" %10g", A(i,j));
            printf("\n");
        }
    return 1;
#undef A
}

int
MUTtemp(GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel*) inModel;
    MUTinstance *here;

    struct INDmatrixSet *inductanceMatrixSets = NULL;

    NG_IGNORE(ckt);

    for (; model; model = model->MUTnextModel)
        for (here = model->MUTinstances; here; here = here->MUTnextInstance) {

            /* Value Processing for mutual inductors */

            double ind1 = here->MUTind1->INDinduct;
            double ind2 = here->MUTind2->INDinduct;

            /*           _______
             * M = k * \/L1 * L2
             */
            here->MUTfactor = here->MUTcoupling * sqrt(fabs(ind1 * ind2));

            if (ckt->CKTindverbosity > 0)
            {
                struct INDmatrixSet *temp;

                /* Assign 'setIndex' and 'matrixIndex' for L matrix */
                if (!here->MUTind1->setPtr && !here->MUTind2->setPtr) {
                    /* Create the set */
                    temp = TMALLOC (struct INDmatrixSet, 1);
                    temp->INDmatrixSize = 2;
                    temp->next = inductanceMatrixSets;
                    inductanceMatrixSets = temp;
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
            }
        }

    {
        int sz = 0;
        struct INDmatrixSet *temp;
        for (temp = inductanceMatrixSets; temp; temp = temp->next)
            if (sz < temp->INDmatrixSize)
                sz = temp->INDmatrixSize;

        char *pop = TMALLOC(char, sz * sz);
        double *INDmatrix = TMALLOC(double, sz * sz);

        for (temp = inductanceMatrixSets; temp; temp = temp->next) {
            if (!temp->INDmatrixSize)
                continue;

            int positive, i;

            sz = temp->INDmatrixSize;

            memset(pop, 0, (size_t)(sz*sz));
            memset(INDmatrix, 0, (size_t)(sz*sz) * sizeof(double));

            INDinstance *hi = temp->Xindhead;
            for (i = 0; hi; hi = hi->Xnext) {
                INDmatrix [i * sz + i] = hi->INDinduct;
                hi->INDmatrixIndex = i++;
            }

            MUTinstance *hm = temp->Xmuthead;
            int expect = (sz*sz - sz) / 2;
            int repetitions = 0;
            for (; hm; hm = hm->Xnext) {
                int j = hm->MUTind1->INDmatrixIndex;
                int k = hm->MUTind2->INDmatrixIndex;
                if (j < k)
                    SWAP(int, j, k);
                if (pop[j*sz + k]) {
                    repetitions ++;
                } else {
                    pop[j*sz + k] = 1;
                    expect --;
                }
                INDmatrix [j * sz + k] = INDmatrix [k * sz + j] = hm->MUTfactor;
            }

            positive = cholesky(INDmatrix, sz);

            if (!positive) {
                positive = 1;
                /* ignore check if all |K| == 1 and all L >= 0 */
                for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                    if (fabs(hm->MUTcoupling) != 1.0) {
                        positive = 0;
                        break;
                    }
                for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                    if (hi->INDinduct < 0) {
                        positive = 0;
                        break;
                    }
            }

            if (!positive || repetitions || (expect && ckt->CKTindverbosity > 1)) {
                fprintf(stderr, "The Inductive System consisting of\n");
                for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                    fprintf(stderr, " %s", hi->INDname);
                fprintf(stderr, "\n");
                for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                    fprintf(stderr, " %s", hm->MUTname);
                fprintf(stderr, "\n");
                if (!positive)
                    fprintf(stderr, "is not positive definite\n");
                for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                    if (fabs(hm->MUTcoupling) > 1.0)
                        fprintf(stderr, " |%s| > 1\n", hm->MUTname);
                for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                    if (hi->INDinduct < 0)
                        fprintf(stderr, " %s < 0\n", hi->INDname);
                if (repetitions)
                    fprintf(stderr, "has dupplicate K instances\n");
                if (expect && ckt->CKTindverbosity > 1)
                    fprintf(stderr, "has an incomplete set of K couplings, (missing ones are implicitly 0)\n");
                fprintf(stderr, "\n");
            }
        }

        tfree(pop);
        tfree(INDmatrix);
    }

    MUTfree_inductanceSets(inductanceMatrixSets);

    return(OK);
}


static void
MUTfree_inductanceSets(struct INDmatrixSet *temp)
{
    while (temp) {
        struct INDmatrixSet *next = temp->next;
        tfree(temp);
        temp = next;
    }
}
