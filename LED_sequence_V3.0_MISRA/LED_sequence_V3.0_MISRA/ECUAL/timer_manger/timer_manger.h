/*
 * timer_manger.h
 *
 * Created: 4/13/2023 3:44:33 AM
 *  Author: Mohamed Abdel-Wahab
 */ 


#ifndef TIMER_MANGER_H_
#define TIMER_MANGER_H_

/**********************************  section 1: Includes ********************************************************/
#include "../../MCAL/timer/timer.h"

typedef  void (*Fptr) (void);
/**********************************  section 2: Macro Declarations ***********************************************/
#define  INTIALIZE_TIMER_WITH_ZERO   (0)
#define  OVERFLOW_COUNT_FOR_ONE_SEC  (30U)
#define CONFIG_COMPARE_VALUE	 (uint8_t)97

/**********************************  section 3: Macro Like Function Declarations *************************** *****/


/**********************************  section 4: Data Type Declarations  ******************************************/

typedef struct
{
	TimerType_t  timer_num;  /* @ref TimerType_t*/
	TimerMode_t  timer_mode;  /* @ref TimerMode_t*/
	uint16_t timer_InitialValue;		/* the pres-loaded value on Timer/Counter Register*/
	uint16_t timer_compare_MatchValue;		/* the top value on Output Compare Register*/
	Fptr call_back_function;	 /*pointer to function that take void and return nothing(void) ,should loaded with call-back function's address*/
}TimerManger_config_t;


/**********************************  section 5: Function Declarations ********************************************/

/*
 * Description:  Function to Initialize Timer Driver
 *                 - Working in Interrupt Mode
 *                 - set Timer initial value
 *                 - set Timer_ID (Timer0, Timer1, Timer2)
 *                 - set Timer_Mode(OverFlow, Compare,PWM)
 *                 - if using CTC mode choose Timer compare match value  And choose output_compare_mode
 * 
 *@param stPtr_a_TimerConfig :A Reference of the Timer configuration
 * @return Std_ReturnType : status of the function
 * E_OK :the function done successfully
 * E_NOT_OK :the function has issues performing the function
 */
Std_ReturnType TIMER_MANGER_init(const TimerManger_config_t *stPtr_a_TimerConfig);

/*
* Description : TIMER START COUNTING BY CONFIGURE THE TIMER CLOCK
* @param en_a_timer_clk :timer clock configuration with pres-scaler
		en_a_timer_num  :timer channel : timer0,timer1,timer2
* @return Std_ReturnType: status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMER_MANGER_start(const TimerClock_t en_a_timer_clock,const TimerType_t en_a_timer_num);

/*
* Description :Function to Halt the timer (stop)
* @param the en_a_timer_num timer type 
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType TIMER_MANGER_stop(const TimerType_t en_a_timer_num);

#endif /* TIMER_MANGER_H_ */