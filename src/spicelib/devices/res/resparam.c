/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Thomas L. Quarles
Modified: Apr 2000 - Paolo Nenzi
**********/

#include "ngspice/ngspice.h"
#include "ngspice/const.h"
#include "ngspice/ifsim.h"
#include "resdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/missing_math.h"
#include "ngspice/fteext.h"

static void
recalc_RESconduct(RESinstance *here);

int
RESparam(int param, IFvalue *value, GENinstance *inst, IFvalue *select)
{
    double scale;

    RESinstance *here = (RESinstance *)inst;

    NG_IGNORE(select);

    if (!cp_getvar("scale", CP_REAL, &scale))
        scale = 1;

    switch(param) {
    case RES_TEMP:
        here->REStemp = value->rValue + CONSTCtoK;
        here->REStempGiven = TRUE;
        break;
    case RES_DTEMP:
        here->RESdtemp = value->rValue;
        here->RESdtempGiven = TRUE;
        break;
    case RES_RESIST:
        /* 0 valued resistor causes ngspice to hang -- can't solve for initial voltage */
        if ( AlmostEqualUlps( value->rValue, 0, 3 ) ) value->rValue = 0.001; /* 0.001 should be sufficiently small */
        here->RESresist = value->rValue;
        here->RESresGiven = TRUE;
        break;
    case RES_ACRESIST:
        here->RESacResist = value->rValue;
        here->RESacresGiven = TRUE;
        break;
    case RES_WIDTH:
        here->RESwidth = value->rValue * scale;
        here->RESwidthGiven = TRUE;
        break;
    case RES_LENGTH:
        here->RESlength = value->rValue * scale;
        here->RESlengthGiven = TRUE;
        break;
    case RES_SCALE:
        here->RESscale = value->rValue;
        here->RESscaleGiven = TRUE;
        break;
    case RES_RESIST_SENS:
        here->RESsenParmNo = value->iValue;
        break;
    case RES_M:
        here->RESm = value->rValue;
        here->RESmGiven = TRUE;
        break;
    case RES_TC1:
        here->REStc1 = value->rValue;
        here->REStc1Given = TRUE;
        break;
    case RES_TC2:
        here->REStc2 = value->rValue;
        here->REStc2Given = TRUE;
        break;
    case RES_TCE:
        here->REStce = value->rValue;
        here->REStceGiven = TRUE;
        break;
    case RES_NOISY:
        here->RESnoisy = value->iValue;
        here->RESnoisyGiven = TRUE;
        break;
    case RES_BV_MAX:
        here->RESbv_max = value->rValue;
        here->RESbv_maxGiven = TRUE;
        break;
    default:
        return(E_BADPARM);
    }
    recalc_RESconduct(here);
    return(OK);
}

/* Re-calculate the conduction of the resistor if a parameter has been changed by
   command 'alter' */
static void
recalc_RESconduct(RESinstance *here)
{
    double factor;
    double difference;
    double tc1, tc2, tce;
    RESmodel *model = (RESmodel *)here->RESmodPtr;
    CKTcircuit *ckt = ft_curckt->ci_ckt;

    /* Upon initialization ckt is not yet defined.
      So we don't repeat here what will be done in restemp.c anyway. */
    if (!ckt)
        return;

    if (!here->RESresGiven) {
        if (here->RESlength * here->RESwidth * model->RESsheetRes > 0.0) {
            here->RESresist =
                (here->RESlength - model->RESshort) /
                (here->RESwidth - model->RESnarrow) *
                model->RESsheetRes;
        }
        else if (model->RESresGiven) {
            here->RESresist = model->RESres;
        }
        else {
            SPfrontEnd->IFerrorf(ERR_WARNING,
                "%s: resistance to low, set to 1 mOhm", here->RESname);
            here->RESresist = 1e-03;
        }
    }

    /* Default Value Processing for Resistor Instance */

    if (!here->REStempGiven) {
        here->REStemp = ckt->CKTtemp;
        if (!here->RESdtempGiven)   here->RESdtemp = 0.0;
    }
    else { /* REStempGiven */
        here->RESdtemp = 0.0;
        if (here->RESdtempGiven)
            printf("%s: Instance temperature specified, dtemp ignored\n", here->RESname);
    }

    difference = (here->REStemp + here->RESdtemp) - model->REStnom;

    /* instance parameters tc1,tc2 and tce will override
    model parameters tc1,tc2 and tce */
    if (here->REStc1Given)
        tc1 = here->REStc1; /* instance */
    else
        tc1 = model->REStempCoeff1; /* model */

    if (here->REStc2Given)
        tc2 = here->REStc2;
    else
        tc2 = model->REStempCoeff2;

    if (here->REStceGiven)
        tce = here->REStce;
    else
        tce = model->REStempCoeffe;

    if ((here->REStceGiven) || (model->REStceGiven))
        factor = pow(1.01, tce * difference);
    else
        factor = (((tc2 * difference) + tc1) * difference) + 1.0;

    here->RESconduct = (1.0 / (here->RESresist * factor * here->RESscale));

    if (here->RESacresGiven)
        here->RESacConduct = (1.0 / (here->RESacResist * factor * here->RESscale));
    else {
        here->RESacConduct = here->RESconduct;
        here->RESacResist = here->RESresist;
    }
}
