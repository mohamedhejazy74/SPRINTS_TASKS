/*
 * timer_uint_test.h
 *
 * Created: 4/12/2023 4:58:53 PM
 *  Author: Mcs
 */ 


#ifndef TIMER_UINT_TEST_H_
#define TIMER_UINT_TEST_H_

#include "../MCAL/timer/timer.h"

/*
* Description : function to test all timers on all mode 
* @param void 
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
extern Std_ReturnType TIMERx_uintTest(void);



#endif /* TIMER_UINT_TEST_H_ */