/*
 * timer_manger.c
 *
 * Created: 4/13/2023 3:45:23 AM
 *  Author: Mohamed Abdel-Wahab
 */ 
#include "timer_manger.h"

static Timer_Config_t st_g_Timer;
Std_ReturnType TIMER_MANGER_init(const TimerManger_config_t *stPtr_a_TimerConfig)
{
	Std_ReturnType l_ret = E_OK;
	if( (stPtr_a_TimerConfig->timer_num >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		/*initiate the timer */
		
		st_g_Timer.timer_type=stPtr_a_TimerConfig->timer_num;
		st_g_Timer.timer_mode=stPtr_a_TimerConfig->timer_mode;
		st_g_Timer.timer_InitialValue=stPtr_a_TimerConfig->timer_InitialValue;
		st_g_Timer.timer_compare_MatchValue=stPtr_a_TimerConfig->timer_compare_MatchValue;
		
		l_ret = TIMERx_init(&st_g_Timer);
		/*set call-back function  */
		l_ret |= TIMERx_setCallBack(stPtr_a_TimerConfig->call_back_function , stPtr_a_TimerConfig->timer_num);
	}
	return l_ret;
}

Std_ReturnType TIMER_MANGER_start(const TimerClock_t en_a_timer_clock,const TimerType_t en_a_timer_num)
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_clock >= INVALID_TIMER_CLK)||(en_a_timer_num >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		/*Configure the TIMER Pres-scaler value for Timer-x clock*/
		l_ret = TIMERx_start(en_a_timer_clock,en_a_timer_num);
	}
	return l_ret;
}

Std_ReturnType TIMER_MANGER_stop(const TimerType_t en_a_timer_num)
{
	
	Std_ReturnType l_ret = E_OK;
	if(en_a_timer_num >= INVALID_TIMER_TYPE)
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		/*stop the clock for the specific timer*/
		l_ret = TIMERx_stop(en_a_timer_num);
	}
	return l_ret;
}
