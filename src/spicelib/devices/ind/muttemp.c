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
    double tresh, theta, tau, t, sm, s, h, g, c, *b, *z;
    int nrot = 0;
    b = (double *)malloc(n * sizeof(double)); b--;
    z = (double *)malloc(n * sizeof(double)); z--;
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
    free(z++); free(b++); return -1;
}

/*ARGSUSED*/
int
MUTtemp(GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel*)inModel;
    MUTinstance *here;
    double ind1, ind2;
    int i ;
//    int j ;

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
            here->MUTfactor = here->MUTcoupling * sqrt(ind1 * ind2); 

            /* Fill in the L matrix */
//            printf ("Index 1: %d\n", here->MUTind1->INDindex) ;
//            printf ("Index 2: %d\n", here->MUTind2->INDindex) ;
            model->MUTl [here->MUTind1->INDindex * model->MUTcount + here->MUTind1->INDindex] = ind1 ;
            model->MUTl [here->MUTind2->INDindex * model->MUTcount + here->MUTind2->INDindex] = ind2 ;
            model->MUTl [here->MUTind1->INDindex * model->MUTcount + here->MUTind2->INDindex] = here->MUTfactor ;
            model->MUTl [here->MUTind2->INDindex * model->MUTcount + here->MUTind1->INDindex] = here->MUTfactor ;
	}
/*
        printf ("L matrix:\n") ;
        j = 1 ;
        for (i = 0 ; i < model->MUTcount * model->MUTcount ; i++) {
            printf ("%-.9g ", model->MUTl [i]) ;
            if (i == j * model->MUTcount - 1) {
                printf ("\n") ;
                j++ ;
            }
        }
*/
        /* Extract Eigenvalues by using Jacobi's Algorithm */
        double *ev = TMALLOC (double, model->MUTcount) ;

        int ret = jacobi (model->MUTl, (unsigned int)model->MUTcount, ev) ;
        if (ret > -1) {
//            printf ("Eigenvalues:\n") ;
            int found = 0 ;
            for (i = 0 ; i < model->MUTcount ; i++) {
                if (ev [i] < 0) {
                    found = 1 ;
                    printf ("The eigenvalue '%-.9g' is less than zero!\n", ev [i]) ;
                }
//                printf ("%-.9g\n", ev [i]) ;
            }
            if (found) {
                printf ("At least one eigenvalue is less than zero, so the conductances matrix L is NOT positive definite\n") ;
            } else {
                printf ("The conductances matrix L is positive definite!!!\n") ;
            }
        }
    }
    return(OK);
}
