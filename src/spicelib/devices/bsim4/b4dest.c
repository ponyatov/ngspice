/* ******************************************************************************
   *  BSIM4 4.8.1 released by Chetan Kumar Dabhi 2/15/2017                      *
   *  BSIM4 Model Equations                                                     *
   ******************************************************************************

   ******************************************************************************
   *  Copyright 2017 Regents of the University of California.                   *
   *  All rights reserved.                                                      *
   *                                                                            *
   *  Project Director: Prof. Chenming Hu.                                      *
   *  Authors: Gary W. Ng, Weidong Liu, Xuemei Xi, Mohan Dunga, Wenwei Yang     *
   *           Ali Niknejad, Shivendra Singh Parihar, Chetan Kumar Dabhi        *
   *           Yogesh Singh Chauhan, Sayeef Salahuddin, Chenming Hu             *
   ******************************************************************************

   ******************************************************************************
   *                          CMC In-Code Statement                             *
   *                                                                            *
   *  The Developer agrees that the following statement will appear in the      *
   *  model code that has been adopted as a CMC Standard.                       *
   *                                                                            *
   *  Software is distributed as is, completely without warranty or service     *
   *  support. The University of California and its employees are not liable    *
   *  for the condition or performance of the software.                         *
   *                                                                            *
   *  The University of California owns the copyright and grants users a        *
   *  perpetual, irrevocable, worldwide, non-exclusive, royalty-free license    *
   *  with respect to the software as set forth below.                          *
   *                                                                            *
   *  The University of California hereby disclaims all implied warranties.     *
   *                                                                            *
   *  The University of California grants the users the right to modify,        *
   *  copy, and redistribute the software and documentation, both within        *
   *  the user's organization and externally, subject to the following          *
   *  restrictions:                                                             *
   *                                                                            *
   *  1. The users agree not to charge for the University of California code    *
   *     itself but may charge for additions, extensions, or support.           *
   *                                                                            *
   *  2. In any product based on the software, the users agree to               *
   *     acknowledge the University of California that developed the            *
   *     software. This acknowledgment shall appear in the product              *
   *     documentation.                                                         *
   *                                                                            *
   *  3. Redistributions to others of source code and documentation must        *
   *     retain the copyright notice, disclaimer, and list of conditions.       *
   *                                                                            *
   *  4. Redistributions to others in binary form must reproduce the            *
   *     copyright notice, disclaimer, and list of conditions in the            *
   *     documentation and/or other materials provided with the                 *
   *     distribution.                                                          *
   *                                                                            *
   *  Agreed to on ______Feb. 15, 2017______________                            *
   *                                                                            *
   *  By: ____University of California, Berkeley___                             *
   *      ____Chenming Hu__________________________                             *
   *      ____Professor in Graduate School ________                             *
   *                                                                            *
   ****************************************************************************** */

#include "ngspice/ngspice.h"
#include "bsim4def.h"
#include "ngspice/suffix.h"


void
BSIM4destroy(GENmodel **inModel)
{
    BSIM4model *mod = *(BSIM4model**) inModel;

#ifdef USE_OMP
    /* free just once for all models */
    FREE(mod->BSIM4InstanceArray);
#endif

    while (mod) {
        BSIM4model *next_mod = mod->BSIM4nextModel;
        BSIM4instance *inst = mod->BSIM4instances;
        /** added to get rid of link list pSizeDependParamKnot **/
        struct bsim4SizeDependParam *p = mod->pSizeDependParamKnot;
        while (p) {
            struct bsim4SizeDependParam *next_p = p->pNext;
            FREE(p);
            p = next_p;
        }
        /** end of extra code **/
        while (inst) {
            BSIM4instance *next_inst = inst->BSIM4nextInstance;
            FREE(inst);
            inst = next_inst;
        }
        FREE(mod->BSIM4version);
        FREE(mod);
        mod = next_mod;
    }

    *inModel = NULL;
}
