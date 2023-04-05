/* 
 * File:   timer.h
 * Author: Mohamed Abdel-Wahab
 *
 * 
 */

#ifndef TIMER_H
#define	TIMER_H

/**********************************  section 1: Includes ********************************************************/
#include "../mcal_std_types.h"
#include "../mcal_bit_math"
#include "dio.h"
/**********************************  section 2: Macro Declarations ***********************************************/

/**********************************  section 3: Macro Like Function Declarations *************************** *****/

/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Timer_Clock_t;


typedef enum
{
	Timer0,Timer1,Timer2
}Timer_Type_t;

typedef enum
{
	Overflow,Compare
}Timer_Mode_t;

typedef struct
{
	uint32 timer_InitialValue;
	uint32 timer_compare_MatchValue;
	Timer_Type_t timer_ID;
	Timer_Clock_t timer_clock;
	Timer_Mode_t timer_mode;

}Timer_Config_t;

/**********************************  section 5: Function Declarations ********************************************/
*/
* Description: Function to Initialize Timer Driver
* Working in Interrupt Mode
*Choose Timer initial value
* Choose Timer_ID (Timer0, Timer1, Timer2)
* Choose Timer_Mode (OverFlow, Compare)
* Choose Timer compare match value if using CTC mode
* Choose Timer_Clock
* @param _pin_config A Reference of the timer configuration
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
/*
Std_ReturnType TIMER_init(const timer_config_t * timer_config_Ptr);
/*
* Description: Function to set the Call Back function address.
* @param -pointer to function & timer Id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
/*
Std_ReturnType TIMER_setCallBack(void(*a_ptr)(void), Timer_Type_t a_timer_type );
/*
* Description: Function to stop the clock of the timer to stop incrementing.
* @param timer Id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMER_stop(Timer_Type_t timer_type);
/*
* Description: Function to DeInit the timer to start again from beginning
* @param timer Id
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMER_deInit(Timer_Type_t timer_type);
#endif	/* TIMER_H*/

