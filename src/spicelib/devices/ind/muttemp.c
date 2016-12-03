/**********
Copyright 2003 Paolo Nenzi
Author: 2003 Paolo Nenzi
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

static int
cholesky(double *a, int n)
{
#define A(r,c) a[n*r + c]
    int i, j, k;
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
    return 1;
#undef A
}

int
MUTtemp(GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel*) inModel;
    MUTinstance *here;

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
        }

    int sz = 0;
    struct INDmatrixSet *temp;
    for (temp = ckt->inductanceMatrixSets; temp; temp = temp->next)
        if (sz < temp->INDmatrixSize)
            sz = temp->INDmatrixSize;

    char *pop = TMALLOC(char, sz * sz);
    double *INDmatrix = TMALLOC(double, sz * sz);

    for (temp = ckt->inductanceMatrixSets; temp; temp = temp->next) {
        if (!temp->INDmatrixSize)
            continue;

        int found, i;

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

        found = !cholesky(INDmatrix, sz);

        if (found) {
            found = 0;
            /* ignore check if all |K| == 1 and all L >= 0 */
            for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                if (fabs(hm->MUTcoupling) != 1.0) {
                    found = 1;
                    break;
                }
            for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                if (hi->INDinduct < 0) {
                    found = 1;
                    break;
                }
        }

        if (found || repetitions || expect) {
            fprintf(stderr, "The inductive System composed of following components\n");
            for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                fprintf(stderr, " %s", hi->INDname);
            fprintf(stderr, "\n");
            for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                fprintf(stderr, " %s", hm->MUTname);
            fprintf(stderr, "\n");
            if (found)
                fprintf(stderr, "is not positive definite\n");
            for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                if (fabs(hm->MUTcoupling) > 1.0)
                    fprintf(stderr, " |%s| > 1\n", hm->MUTname);
            for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                if (hi->INDinduct < 0)
                    fprintf(stderr, " %s < 0\n", hi->INDname);
            if (repetitions)
                fprintf(stderr, "has dupplicate K instances\n");
            if (expect)
                fprintf(stderr, "has an incomplete set of K couplings, (missing ones are implicitly 0)\n");
            fprintf(stderr, "\n");
        }
    }

    tfree(pop);
    tfree(INDmatrix);
    return(OK);
}
