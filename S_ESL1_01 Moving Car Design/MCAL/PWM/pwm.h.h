/* 
 * File:   pwm.h
 * Author: Mohamed Abdel-Wahab
 *
 * 
 */

#ifndef PWM_H
#define	PWM_H

/**********************************  section 1: Includes ********************************************************/
#include "../mcal_std_types.h"
#include "../mcal_bit_math"
#include "dio.h"
#include "timer.h"
/**********************************  section 2: Macro Declarations ***********************************************/

/**********************************  section 3: Macro Like Function Declarations *************************** *****/

/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum
{
	TIMER_0,TIMER_1,TIMER_2
}PWM_timerType_t;

typedef enum
{
	NORMAL_OC0_DISCONNECTED,REVERSED,NON_INVERTING,INVERTING
}PWM_modeType_t;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,EXTERNAL_CLOCK_FALLING,EXTERNAL_CLOCK_RISING
}PWM_ClockType_t;

typedef struct
{
	PWM_timerType timer;
	PWM_modeType  mode;
	PWM_ClockType clock;
}PWM_config_t;

/**********************************  section 5: Function Declarations ********************************************/
/*
* Description: Function to Init the pwm
* @param A Reference of the pwm configuration
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType PWM_init(const PWM_config_t * config_Ptr);
/*
* Description: Function to DeInit the timer to start again from beginning
* @param A Reference of the pwm configuration & the desired duty cycle
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
Std_ReturnType PWM_changeDuty(const PWM_config_t * config_Ptr,uint8_t a_duty);
#endif	/* PWM_H*/

