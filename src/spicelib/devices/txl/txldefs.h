#ifndef TXL
#define TXL

#include "ngspice/ifsim.h"
#include "ngspice/cktdefs.h"
#include "ngspice/gendefs.h"
#include "ngspice/complex.h"
#include "ngspice/noisedef.h"
#include "ngspice/swec.h"

/* information used to describe a single instance */

typedef struct sTXLinstance {
    struct sTXLmodel *TXLmodPtr;    /* backpointer to model */
    struct sTXLinstance *TXLnextInstance;   /* pointer to next instance of 
                                             * current model*/

    IFuid TXLname;  /* pointer to character string naming this instance */
    
        int dimensions; /* may we not need this but ... */
	int TXLposNode;
	int TXLnegNode;
	double TXLlength;
	int TXLibr1;
	int TXLibr2;
	TXLine *txline;  /* pointer to SWEC txline type */
	TXLine *txline2;  /* pointer to SWEC txline type. temporary storage */
	char *in_node_name;
	char *out_node_name;
	int TXLbranch;       /* unused */
	
	double *TXLposPosPtr;
	double *TXLposNegPtr;
	double *TXLnegPosPtr;
	double *TXLnegNegPtr;
	double *TXLibr1PosPtr;
	double *TXLibr2NegPtr;
	double *TXLposIbr1Ptr;
	double *TXLnegIbr2Ptr;
	double *TXLibr1NegPtr;
	double *TXLibr2PosPtr;
	double *TXLibr1Ibr1Ptr;
	double *TXLibr2Ibr2Ptr;
	double *TXLibr1Ibr2Ptr;
	double *TXLibr2Ibr1Ptr;
	
	unsigned TXLibr1Given : 1;
	unsigned TXLibr2Given : 1;
	unsigned TXLdcGiven : 1;
	unsigned TXLlengthgiven : 1;   /* flag to indicate that instance parameter len is specified */

#ifdef KLU
    BindElement *TXLposPosptrStructPtr ;
    BindElement *TXLposNegptrStructPtr ;
    BindElement *TXLnegPosptrStructPtr ;
    BindElement *TXLnegNegptrStructPtr ;
    BindElement *TXLibr1PosptrStructPtr ;
    BindElement *TXLibr2NegptrStructPtr ;
    BindElement *TXLnegIbr2ptrStructPtr ;
    BindElement *TXLposIbr1ptrStructPtr ;
    BindElement *TXLibr1Ibr1ptrStructPtr ;
    BindElement *TXLibr2Ibr2ptrStructPtr ;
    BindElement *TXLibr1NegptrStructPtr ;
    BindElement *TXLibr2PosptrStructPtr ;
    BindElement *TXLibr1Ibr2ptrStructPtr ;
    BindElement *TXLibr2Ibr1ptrStructPtr ;
#endif

} TXLinstance ;


/* per model data */

typedef struct sTXLmodel {       /* model structure for a txl */
    int TXLmodType; /* type index of this device type */
    struct sTXLmodel *TXLnextModel; /* pointer to next possible model in 
                                     * linked list */
    TXLinstance * TXLinstances; /* pointer to list of instances that have this
                                 * model */
    IFuid TXLmodName;       /* pointer to character string naming this model */

    /* --- end of generic struct GENmodel --- */

	double R;
	double L;
	double G;
	double C;
	double length;
    unsigned Rgiven : 1;   /* flag to indicate R was specified */
    unsigned Lgiven : 1;   /* flag to indicate L was specified */
    unsigned Ggiven : 1;   /* flag to indicate G was specified */
    unsigned Cgiven : 1;   /* flag to indicate C was specified */
    unsigned lengthgiven : 1;   /* flag to indicate length was specified */

} TXLmodel;

/* instance parameters */
#define TXL_IN_NODE 1
#define TXL_OUT_NODE 2
#define TXL_LENGTH 3

/* model parameters */
#define TXL_R 101
#define TXL_C 102
#define TXL_G 103
#define TXL_L 104
#define TXL_length 105
#define TXL_MOD_R 106

#include "txlext.h"
extern VI_list_txl *pool_vi_txl;

#endif /*TXL*/
