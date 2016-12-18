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


/* From EISPACK */

/* S: real, symmetric matrix
   n: dimension of S
   w: contains unsorted eigenvalues
   RETURNS: >0 : number of jacobi iterations
   -1 : number of jacobi iterations exceeded 50
*/

static int jacobi(double *a, unsigned int n, double w[]) {
    unsigned int i, j, iq, ip;
    double tresh, theta, tau, t, sm, s, h, g, c;
    int nrot = 0;
    double * const b = (double *)malloc(n * sizeof(double)) - 1;
    double * const z = (double *)malloc(n * sizeof(double)) - 1;
#define A(r,c) a[n*(r-1)+c-1]
#define W(c) w[c-1]
#define ROTATE(i,j,k,l) g=A(i,j);h=A(k,l);A(i,j)=g-s*(h+g*tau);A(k,l)=h+s*(g-h*tau)
    for (ip = 1; ip <= n; ip++) { b[ip] = W(ip) = A(ip,ip); z[ip] = 0; }
    for (i = 1; i <= 50; i++) {
        sm = 0;
        for (ip = 1; ip <= n - 1; ip++) for (iq = ip + 1; iq <= n; iq++) sm += fabs(A(ip,iq));
        if (sm == 0) { /*free(z++); free(b++);*/ return nrot; }
        tresh = (i<4) ? 0.2*sm / (n*n) : 0;
        for (ip = 1; ip <= n - 1; ip++) {
            for (iq = ip + 1; iq <= n; iq++) {
                g = 100*fabs(A(ip, iq));
                if (i > 4 && fabs(W(ip)) + g == fabs(W(ip)) && fabs(W(iq)) + g == fabs(W(iq)))
                    A(ip, iq) = 0;
                else if (fabs(A(ip, iq)) > tresh) {
                    h = W(iq) - W(ip);
                    if (fabs(h) + g == fabs(h))
                        t = A(ip, iq) / h;
                    else {
                        theta = 0.5*h / A(ip, iq);
                        t = 1 / (fabs(theta) + sqrt(1 + theta*theta));
                        if (theta < 0) t = -t;
                    }
                    c = 1 / sqrt(1 + t*t); s = t*c; tau = s / (1 + c); h = t*A(ip, iq);
                    z[ip] -= h; z[iq] += h; W(ip) -= h; W(iq) += h;  A(ip, iq) = 0;
                    for (j = 1;      j <= ip - 1; j++) { ROTATE(j, ip, j, iq); }
                    for (j = ip + 1; j <= iq - 1; j++) { ROTATE(ip, j, j, iq); }
                    for (j = iq + 1; j <= n;      j++) { ROTATE(ip, j, iq, j); }
                    ++nrot;
                }
            }
        }
        for (ip = 1; ip <= n; ip++) { b[ip] += z[ip]; W(ip) = b[ip]; z[ip] = 0; }
    }
    free(z + 1); free(b + 1); return -1;
#undef A
}


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

            static int use_cholesky = 1;
            if (use_cholesky)
                positive = cholesky(INDmatrix, sz);
            else
            {
                double *ev = TMALLOC(double, sz);

                int ret = jacobi(INDmatrix, (unsigned int)sz, ev);
                if (ret < 0) {
                    fprintf(stderr, "jacobi() did not properly terminate, skipping the check\n");
                    FREE(ev);
                    continue;
                }

                positive = 1;
                for (i = 0; i < sz; i++)
                    if (ev [i] < 0) {
                        positive = 0;
                        break;
                    }
                FREE(ev);
            }

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
