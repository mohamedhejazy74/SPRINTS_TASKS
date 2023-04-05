
#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"
#include "../mcal_std_types.h"
#include "../mcal_bit_math"
#include "../../MCAL_Layer/GPIO/dio.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/



/* ----------------- Data Type Declarations -----------------*/

typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}interrupt_Edge_type_t;

typedef enum{
    INTERRUPT_EXTERNAL_INT0 =  0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
}interrupt_ID;

typedef struct{
    pin_config_t mcu_pin;
    interrupt_Edge_type_t edge;
    interrupt_ID source;
}Interrupt_Config_t;


/* ----------------- Software Interfaces Declarations -----------------*/
/*
* Description : Call the Call Back function in the application after the edge is detected
* @param A pointer to function & the external interrupt id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
Std_ReturnType EXT_INTx_setCallBack(void(*a_ptr)(void), const Interrupt_ID_t a_interrupt_number );
/*
* Description : initialize the the dio pin to be an external interrupt
* @param A Reference of the external interrupt configuration
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
Std_ReturnType EXT_INTx_Init(const Interrupt_Config_t * Interrupt_Config_Ptr );
/*
* Description : set the edge in which the external interrupt will be triggered
* @param edge type & the external interrupt id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
Std_ReturnType EXT_INTx_setEdgeType(const Edge_type_t a_edgeType , Interrupt_ID_t a_interrupt_number);
/**
* @brief DeInitialize the interrupt module
* @param the external interrupt id
* @return Status of the function
* (E_OK) : The function done successfully
* (E_NOT_OK) : The function has issue to perform this action
*/
Std_ReturnType EXT_INTx _DeInit(const Interrupt_ID_t a_interrupt_number);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */
