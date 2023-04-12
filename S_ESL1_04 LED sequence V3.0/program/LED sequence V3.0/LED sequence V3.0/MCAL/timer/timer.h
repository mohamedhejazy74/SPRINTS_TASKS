/*
 * timer.h
 *
 * Created: 4/10/2023 3:37:27 PM
 *  Author:  Mohamed Abdel-Wahab
 */ 


#ifndef TIMER_H_
#define TIMER_H_
/**********************************  section 1: Includes ********************************************************/
#include "../../STD_LIBRARIES/STD_TYPES.h"
#include "../../STD_LIBRARIES/bit_math.h"
#include "../dio/dio.h"
#include "../external_interrupt/external_interrupt.h"
#include "timer_private_reg.h"

/**********************************  section 2: Macro Declarations ***********************************************/
#define  INTIALIZE_TIMER_WITH_ZERO   (0)

/**********************************  section 3: Macro Like Function Declarations *************************** *****/


/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum
{
	Timer0,Timer1,Timer2,INVALID_TIMER_TYPE
}TimerType_t;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_32,F_CPU_64,F_CPU_128,F_CPU_256,F_CPU_1024,
	TIMER_EXTERNAL_CLK_FALLING_EDGE,TIMER_EXTERNAL_CLK_RISING_EDGE,
	INVALID_TIMER_CLK
}TimerClock_t;

typedef enum
{
	TIMER_NORMAL_MODE=0,
	TIMER_PHASE_CORRECT_PWM_MODE,
	TIMER_CTC_MODE,
	TIMER_FAST_PWM_MODE,
	INVALID_TIMER_MODE
}TimerMode_t;

typedef enum
{
	CTC_Output_Compare_Mode_DISCONNECTED=0, /*Normal port operation, OCx disconnected.*/
	CTC_Output_Compare_Mode_TOGGLE,			/*Toggle OCx on compare match*/
	CTC_Output_Compare_Mode_CLEAR,			/*Clear OCx on compare match*/
	CTC_Output_Compare_SET,					/*Set OCx on compare match*/
	CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE
}Output_Compare_Mode_t;

typedef enum
{
	FAST_Output_Compare_Mode_DISCONNECTED=0,	/*Normal port operation, OCx disconnected.*/
	FAST_Output_Compare_Mode_TOGGLE,			/*Toggle OCx on compare match*/
	FAST_Output_Compare_Mode_NON_INVERTED,	/*Clear OCx on compare match, set OCx at BOTTOM*/
	FAST_Output_Compare_Mode_INVERTED,		/* Set OCx on compare match, clear OCx at BOTTOM*/
	FAST_INVALID_TIMER_FAST_PWM_MODE
}FAST_PWM_MODE_t;

typedef enum
{
	PC_Output_Compare_Mode_DISCONNECTED=0,	/*Normal port operation, OCx disconnected.*/
	PC_Output_Compare_Mode_TOGGLE,			/*Toggle OCx on compare match*/
	PC_Output_Compare_Mode_NON_INVERTED,	/*Clear OCx on compare match when up-counting Set OCx on compare match when down counting*/
	PC_Output_Compare_Mode_INVERTED,		/*Set OCx on compare match when up-counting Clear OCx on compare match when down counting*/
	PC_INVALID_TIMER_Phase_Correct_PWM_MODE
}Phase_Correct_PWM_Mode;

typedef struct
{
	TimerType_t  timer_type;  /* @ref TimerType_t*/
	TimerClock_t timer_clock; /* @ref TimerClock_t*/
	TimerMode_t  timer_mode;  /* @ref TimerMode_t*/
	Output_Compare_Mode_t output_compare_mode;	/* @ref Output_Compare_Mode_t*/
	FAST_PWM_MODE_t  fast_pwm_mode;		/* @ref FAST_PWM_MODE_t 8-bit resolution only*/
	Phase_Correct_PWM_Mode phase_correct_pwm_mode;		/* @ref Phase_Correct_PWM_Mode  8-bit resolution only*/
	uint16_t timer_InitialValue;		/* the pre-loaded value on Timer/Counter Register*/
	uint16_t timer_compare_MatchValue;		/* the top value on Output Compare Register*/
}Timer_Config_t;


/**********************************  section 5: Function Declarations ********************************************/

/*
 * Description:  Function to Initialize Timer Driver
 *                 - Working in Interrupt Mode
 *                 - Choose Timer initial value
 *                 - Choose Timer_ID (Timer0, Timer1, Timer2)
 *                 - Choose Timer_Mode (OverFlow, Compare,PWM)
 *                 - if using CTC mode choose Timer compare match value  And choose output_compare_mode
 * 
 *@param A Reference of the Timer configuration
 * @return status of the function
 * E_OK :the function done successfully
 * E_NOT_OK :the function has issues performing the function
 */
Std_ReturnType TIMERx_init(const Timer_Config_t *stPtr_a_Config);
/*
* Description : START COUNTING BY CONFIGURE THE TIMER CLOCK 
* @param A Reference of the Timer configuration
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMERx_start(const Timer_Config_t *stPtr_a_Config);
/*
* Description : Call the Call Back function in the application after timer did its job
* @param A pointer to function & the  timer type
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMERx_setCallBack(volatile void(*a_fptr)(void), const TimerType_t en_a_timer_type );

/*
* Description :set a certain value on the timer counting register 
* @param the  timer type and the initial value to be set
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMERx_setValue(const TimerType_t en_a_timer_type ,const uint16_t u16_a_timer_value);

/*
* Description :this function sets the offset of the compare unit 
* @param timer type and the top value to be compared with the TCNCx
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMERx_CTC_SetCompare(const TimerType_t en_a_timer_type ,const uint16_t u16_a_compareValue);

/*
* Description :Function to make the timer to start again from beginning(reset)
* @param the  timer type and the initial value to be set
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMERx_reset(const TimerType_t en_a_timer_type);

/*
* Description :Function to Halt the timer (stop)
* @param the  timer type and the initial value to be set
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMERx_stop(const TimerType_t en_a_timer_type);

#endif /* TIMER_H_ */
