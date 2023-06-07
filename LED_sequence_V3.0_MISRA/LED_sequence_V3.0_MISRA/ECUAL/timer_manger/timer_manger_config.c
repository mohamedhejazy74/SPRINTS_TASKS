/*
 * timer_manger_config.c
 *
 * Created: 6/7/2023 5:17:10 PM
 *  Author: Mcs
 */ 
#include "timer_manger.h"

 TimerManger_config_t st_g_timer = {
	 .timer_num = Timer0,
	 .timer_mode = TIMER_CTC_MODE,
	 .timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	 .timer_compare_MatchValue = CONFIG_COMPARE_VALUE,
	 
 };