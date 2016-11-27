/**********
Copyright 2003 Paolo Nenzi
Author: 2003 Paolo Nenzi
**********/
/*
 */


#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

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
            for (k = 0 ; k < j; k++)
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

/*ARGSUSED*/
int
MUTtemp(GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel*)inModel;
    MUTinstance *here;
    INDmatrixSet *temp;
    double ind1, ind2 ;
    int found, i;

    NG_IGNORE(ckt);

    /*  loop through all the inductor models */
    for( ; model != NULL; model = model->MUTnextModel ) {

        /* loop through all the instances of the model */
        for (here = model->MUTinstances; here != NULL ;
                here=here->MUTnextInstance) {

            /* Value Processing for mutual inductors */
	   
	    ind1 = here->MUTind1->INDinduct;
	    ind2 = here->MUTind2->INDinduct;
	    
        /*           _______
	 * M = k * \/l1 * l2 
	 */
            here->MUTfactor = here->MUTcoupling * sqrt(fabs(ind1 * ind2)); 

            /* Fill in the L matrix for each set */
            here->MUTind1->setPtr->INDmatrix [here->MUTind1->INDmatrixIndex * here->MUTind1->setPtr->INDmatrixSize + here->MUTind1->INDmatrixIndex] = ind1 ;
            here->MUTind1->setPtr->INDmatrix [here->MUTind2->INDmatrixIndex * here->MUTind1->setPtr->INDmatrixSize + here->MUTind2->INDmatrixIndex] = ind2 ;
            here->MUTind1->setPtr->INDmatrix [here->MUTind1->INDmatrixIndex * here->MUTind1->setPtr->INDmatrixSize + here->MUTind2->INDmatrixIndex] = here->MUTfactor ;
            here->MUTind1->setPtr->INDmatrix [here->MUTind2->INDmatrixIndex * here->MUTind1->setPtr->INDmatrixSize + here->MUTind1->INDmatrixIndex] = here->MUTfactor ;
	}

        /* Extract Eigenvalues by using Jacobi's Algorithm */
        temp = ckt->inductanceMatrixSets ;
        for (; temp; temp = temp->next) {
            if (!temp->INDmatrixSize)
                continue;
            static int use_cholesky = 1;
            static double jactime;
            double tjactime = SPfrontEnd->IFseconds();
            if (use_cholesky)
                found = !cholesky(temp->INDmatrix, temp->INDmatrixSize) ;
            else
            {
                double *ev = TMALLOC (double, temp->INDmatrixSize) ;

                int ret = jacobi (temp->INDmatrix, (unsigned int)temp->INDmatrixSize, ev) ;
                if (ret < 0) {
                    fprintf(stderr, "jacobi() did not properly terminate, skipping the check\n");
                    FREE (ev) ;
                    continue;
                }

                found = 0 ;
                for (i = 0 ; i < temp->INDmatrixSize ; i++)
                    if (ev [i] < 0) {
                        found = 1 ;
                        break ;
                    }
                FREE (ev) ;
            }
            jactime += SPfrontEnd->IFseconds() - tjactime;
            fprintf(stderr, "Time used by Jacobi/Cholesky positive definite test:  %6.3g seconds.\n", jactime);

            {
                MUTinstance *hm;
                INDinstance *hi;

                if (found) {
                    found = 0 ;
                    /* ignore jacobi if all K's are exactly 1 and all L's >= 0*/
                    for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                        if (fabs (hm->MUTcoupling) != 1.0) {
                            found = 1 ;
                            break ;
                        }
                    for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                        if (hi->INDinduct < 0) {
                            found = 1 ;
                            break ;
                        }
                }

                if (found) {
                    fprintf(stderr, "The inductive System composed of following components, is not positive definite\n");
                    for (hi = temp->Xindhead;  hi; hi = hi->Xnext)
                        fprintf(stderr, " %s", hi->INDname);
                    fprintf(stderr, "\n");
                    for (hm = temp->Xmuthead;  hm; hm = hm->Xnext)
                        fprintf(stderr, " %s", hm->MUTname);
                    fprintf(stderr, "\n");
                    for (hm = temp->Xmuthead; hm; hm = hm->Xnext)
                        if (fabs (hm->MUTcoupling) > 1.0)
                            fprintf(stderr, " |%s| > 1\n", hm->MUTname);
                    for (hi = temp->Xindhead; hi; hi = hi->Xnext)
                        if (hi->INDinduct < 0)
                            fprintf(stderr, " %s < 0\n", hi->INDname);
                    fprintf(stderr, "\n");
                }
            }
        }

        /* Free memory related to the inductance matrix sets */
        for (temp = ckt->inductanceMatrixSets; temp; temp = temp->next)
            FREE (temp->INDmatrix) ;
    }
    return(OK);
}
