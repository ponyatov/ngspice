/**********
Author: Francesco Lannutti - July 2015
**********/

#include "ngspice/ngspice.h"
#include "ngspice/smpdefs.h"
#include "ngspice/cktdefs.h"
#include "relmodeldefs.h"
#include "../bsim4/bsim4def.h"
#include "ngspice/sperror.h"
#include "ngspice/suffix.h"

//#define CONSTepsZero (8.854214871e-12)   /* epsilon zero F/m */
//#define CONSTepsSiO2 (3.4531479969e-11)  /* epsilon SiO2 F/m */

static int
listInsert (RELMODELrelList **list, double time, double deltaVth)
{
    RELMODELrelList *current ;
    RELMODELrelList *previous ;

    /* Loop until the end of the list */
    previous = NULL ;
    current = *list ;
    while (current != NULL)
    {
        previous = current ;
        current = current->next ;
    }

    /* Insert the new element into the list */
    if (previous == NULL)
    {
        *list = TMALLOC (RELMODELrelList, 1) ;
        current = *list ;
    } else {
        current = TMALLOC (RELMODELrelList, 1) ;
        previous->next = current ;
    }

    /* Populate the element */
    current->time = time ;
    current->deltaVth = deltaVth ;
    current->next = NULL ;

    return 0 ;
}

int
RELMODELcalculateAging (GENinstance *inInstance, int modType, double t_aging, unsigned int stress_or_recovery)
{
    double A, Nt ;
    BSIM4instance *here ;
    RELMODELmodel *relmodel ;

    if (modType == 10)
    {
        here = (BSIM4instance *)inInstance ;
    } else {
        printf ("Error: The Reliability Analysis isn't supported for this model: %d\n\n\n", modType) ;
        return 1 ;
    }

    relmodel = (RELMODELmodel *)(here->BSIM4modPtr->BSIM4relmodelModel) ;
    if (relmodel == NULL)
    {
        printf ("Error: The Reliability Model hasn't been declared or it hasn't been connected to the device model (%s) through the '.appendmodel' command\n\n\n", here->BSIM4modPtr->BSIM4modName) ;
        return 1 ;
    }

    Nt = pow ((sqrt (relmodel->RELMODELnts)), 3) * 1e-21 ;
    A = (CHARGE / (4 * CONSTepsZero * 1e-9 * relmodel->RELMODELeps_hk)) * pow ((relmodel->RELMODELh_cut / (2 * sqrt (2 * relmodel->RELMODELm_star * relmodel->RELMODELw)) * 1e9), 2) ;

    if (stress_or_recovery)
    {
        if (relmodel->RELMODELh_cut / (2 * sqrt (2 * relmodel->RELMODELm_star * relmodel->RELMODELw)) * log (1 + pow (((t_aging + here->relStruct->t_star) / relmodel->RELMODELtau_0), relmodel->RELMODELbeta)) * 1e9 <= 2)
        {
            here->relStruct->deltaVth = Nt * A * pow (log (1 + pow (((t_aging + here->relStruct->t_star) / relmodel->RELMODELtau_0), relmodel->RELMODELbeta)), 2) ;
        } else {
            here->relStruct->deltaVth = pow ((CHARGE / (4 * CONSTepsZero * 1e-9 * relmodel->RELMODELeps_hk)) * Nt * here->BSIM4modPtr->BSIM4toxe * 1e9, 2) ;
        }
    } else {
        here->relStruct->deltaVth = here->relStruct->deltaVth * log (1 + (1.718 / (1 + pow ((t_aging / relmodel->RELMODELtau_e), relmodel->RELMODELbeta1)))) ;
    }

    /* Insert 'here->relStruct->deltaVth' into the list for the later fitting */
    listInsert (&(here->relStruct->deltaVthList), here->relStruct->time, here->relStruct->deltaVth) ;
//    RELMODELrelList *temp ;
//    temp = TMALLOC (RELMODELrelList, 1) ;
//    temp->time = here->relStruct->time ;
//    temp->deltaVth = here->relStruct->deltaVth ;
//    temp->next = here->relStruct->deltaVthList ;
//    here->relStruct->deltaVthList = temp ;
//    printf ("QUI\n\n") ;

    if (!stress_or_recovery)
    {
        here->relStruct->t_star = pow ((exp (sqrt (here->relStruct->deltaVth / (Nt * A))) - 1), (1 / relmodel->RELMODELbeta)) * relmodel->RELMODELtau_0 ;
    }

    return 0 ;
}
