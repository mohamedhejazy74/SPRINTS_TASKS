/*
 * external_interrupt.h
 *
 * Created: 4/8/2023 5:12:04 PM
 *  Author: Mohamed Abdel-Wahab
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

/**********************************  section 1: Includes ********************************************************/
#include "../../STD_LIBRARIES/STD_TYPES.h"
#include "../../STD_LIBRARIES/bit_math.h"
#include "../dio/dio.h"
#include "ext_int_private_reg.h"
#include <avr/interrupt.h>

/**********************************  section 2: Macro Declarations ***********************************************/
#define  NUM_OF_EXT_INTx 3

/**********************************  section 3: Macro Like Function Declarations *************************** *****/
/* This routine clears the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptDisable()         (CLEAR_BIT(GICR,INT0))
/* This routine sets the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptEnable()          (SET_BIT(GICR,INT0))
/* This routine clears the interrupt flag for the external interrupt, INT0 */
#define EXT_INT0_InterruptFlagClear()       (SET_BIT(GIFR,INTF0))

/* This routine clears the interrupt enable for the external interrupt, INT0 */
#define EXT_INT1_InterruptDisable()         (CLEAR_BIT(GICR,INT1))
/* This routine sets the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptEnable()          (SET_BIT(GICR,INT1))
/* This routine clears the interrupt flag for the external interrupt, INT1 */
#define EXT_INT1_InterruptFlagClear()       (SET_BIT(GIFR,INT1))

/* This routine clears the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptDisable()         (CLEAR_BIT(GICR,INT2))
/* This routine sets the interrupt enable for the external interrupt, INT2 */
#define EXT_INT2_InterruptEnable()          (SET_BIT(GICR,INT2))
/* This routine clears the interrupt flag for the external interrupt, INT2 */
#define EXT_INT2_InterruptFlagClear()       (SET_BIT(GIFR,INTF2))
/* This routine sets the I-BIT for global interrupt enable  */
#define  GLOBAL_InterruptEnable()			(SET_BIT(SREG,I))

/**********************************  section 4: Data Type Declarations  ******************************************/


typedef enum{
	INTERRUPT_LOW_LEVEL= 0,
	INTERRUPT_ANY_LOGICAL_CHANGE,
	INTERRUPT_FALLING_EDGE,
	INTERRUPT_RISING_EDGE,
	NOT_VALID_EDGE
}Interrupt_Edge_type_t;

typedef enum{
	INTERRUPT_EXTERNAL_INT0 =  0,
	INTERRUPT_EXTERNAL_INT1,
	INTERRUPT_EXTERNAL_INT2
}Interrupt_ID_t;

typedef struct{
	Interrupt_Edge_type_t edge;
	Interrupt_ID_t source_id;
}Interrupt_Config_t;
/**********************************  section 5: Function Declarations ********************************************/

/*
* Description : Call the Call Back function in the application after the edge is detected
* @param A pointer to function & the external interrupt id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
extern Std_ReturnType EXT_INTx_setCallBack( void(*a_fptr)(void), const Interrupt_ID_t a_interrupt_number );
/*
* Description : initialize the the dio pin to be an external interrupt
* @param A Reference of the external interrupt configuration
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
extern Std_ReturnType EXT_INTx_Init(const Interrupt_Config_t *Interrupt_Config_Ptr );
/*
* Description : set the edge in which the external interrupt will be triggered
* @param edge type & the external interrupt id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
extern Std_ReturnType EXT_INTx_setEdgeType(Interrupt_Edge_type_t a_edgeType ,  Interrupt_ID_t a_interrupt_Id);
/**
* @brief DeInitialize the interrupt module
* @param the external interrupt id
* @return Status of the a_interrupt_Id
* (E_OK) : The function done successfully
* (E_NOT_OK) : The function has issue to perform this action
*/
extern Std_ReturnType EXT_INTx_DeInit(const Interrupt_ID_t a_interrupt_Id);

#endif /* EXTERNAL_INTERRUPT_H_ */