/*
 * delay.h
 *
 * Created: 4/11/2023 7:29:17 AM
 *  Author: Mcs
 */ 


#ifndef DELAY_H_
#define DELAY_H_
/**********************************  section 1: Includes ********************************************************/
#include "../../MCAL/timer/timer.h"

/**********************************  section 2: Macro Declarations ***********************************************/
#define  INTIALIZE_TIMER_WITH_ZERO   (0)
#define  OVERFLOW_COUNT_FOR_ONE_SEC  (30U)
#define CONFIG_COMPARE_VALUE	 (uint8_t)97

/**********************************  section 3: Macro Like Function Declarations *************************** *****/


/**********************************  section 4: Data Type Declarations  ******************************************/


/**********************************  section 5: Function Declarations ********************************************/

/**
 * @brief  generate a delay (busy wait using timer) in ms 
 * @param u16_a_delay_ms the delay value in ms
 * @return status of the function 
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function has issues performing the function
 */
extern Std_ReturnType DELAY_ms(const uint16_t u16_a_delay_ms);


#endif /* DELAY_H_ */