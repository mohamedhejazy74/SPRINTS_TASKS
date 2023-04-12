/*
 * timer_uint_test.c
 *
 * Created: 4/12/2023 4:58:04 PM
 *  Author: Mcs
 */ 
#include "timer_uint_test.h"
#if 1
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_NORMAL_MODE,
	.timer_clock = NO_CLOCK,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_64,
	.timer_InitialValue = 0x25,
	.timer_compare_MatchValue = 97,
	.output_compare_mode = CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.output_compare_mode = CTC_Output_Compare_Mode_CLEAR,
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_FAST_PWM_MODE,
	.timer_clock = F_CPU_256,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.fast_pwm_mode = FAST_Output_Compare_Mode_DISCONNECTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_FAST_PWM_MODE,
	.timer_clock = F_CPU_8,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.fast_pwm_mode = FAST_Output_Compare_Mode_TOGGLE
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_PHASE_CORRECT_PWM_MODE,
	.timer_clock = F_CPU_256,
	.timer_InitialValue = 97,
	.timer_compare_MatchValue = 254,
	.phase_correct_pwm_mode = PC_Output_Compare_Mode_INVERTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer0,
	.timer_mode = TIMER_PHASE_CORRECT_PWM_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = 97,
	.timer_compare_MatchValue = 250,
	.phase_correct_pwm_mode = PC_Output_Compare_Mode_NON_INVERTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_NORMAL_MODE,
	.timer_clock = NO_CLOCK,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_64,
	.timer_InitialValue = 0x25,
	.timer_compare_MatchValue = 97,
	.output_compare_mode = CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.output_compare_mode = CTC_Output_Compare_Mode_CLEAR,
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_FAST_PWM_MODE,
	.timer_clock = F_CPU_256,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.fast_pwm_mode = FAST_Output_Compare_Mode_DISCONNECTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_FAST_PWM_MODE,
	.timer_clock = F_CPU_8,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.fast_pwm_mode = FAST_Output_Compare_Mode_TOGGLE
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_PHASE_CORRECT_PWM_MODE,
	.timer_clock = F_CPU_256,
	.timer_InitialValue = 97,
	.timer_compare_MatchValue = 254,
	.phase_correct_pwm_mode = PC_Output_Compare_Mode_INVERTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer1,
	.timer_mode = TIMER_PHASE_CORRECT_PWM_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = 97,
	.timer_compare_MatchValue = 250,
	.phase_correct_pwm_mode = PC_Output_Compare_Mode_NON_INVERTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_NORMAL_MODE,
	.timer_clock = NO_CLOCK,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_64,
	.timer_InitialValue = 0x25,
	.timer_compare_MatchValue = 97,
	.output_compare_mode = CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.output_compare_mode = CTC_Output_Compare_Mode_CLEAR,
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_FAST_PWM_MODE,
	.timer_clock = F_CPU_256,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.fast_pwm_mode = FAST_Output_Compare_Mode_DISCONNECTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_FAST_PWM_MODE,
	.timer_clock = F_CPU_8,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = 97,
	.fast_pwm_mode = FAST_Output_Compare_Mode_TOGGLE
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_PHASE_CORRECT_PWM_MODE,
	.timer_clock = F_CPU_256,
	.timer_InitialValue = 97,
	.timer_compare_MatchValue = 254,
	.phase_correct_pwm_mode = PC_Output_Compare_Mode_INVERTED
};
#endif
#if 0
Timer_Config_t st_g_uintTestTimer = {
	.timer_type = Timer2,
	.timer_mode = TIMER_PHASE_CORRECT_PWM_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = 97,
	.timer_compare_MatchValue = 250,
	.phase_correct_pwm_mode = PC_Output_Compare_Mode_NON_INVERTED
};
#endif
Std_ReturnType TIMERx_uintTest(void)
{
	Std_ReturnType l_ret = E_OK;
	if( (st_g_uintTestTimer.timer_type >= INVALID_TIMER_TYPE) || (st_g_uintTestTimer.timer_mode >= INVALID_TIMER_MODE) ||
	    (st_g_uintTestTimer.output_compare_mode >=CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE ) || st_g_uintTestTimer.fast_pwm_mode >= FAST_INVALID_TIMER_FAST_PWM_MODE )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		l_ret = TIMERx_init(&st_g_uintTestTimer);
		l_ret |= TIMERx_start(&st_g_uintTestTimer);
		l_ret |= TIMERx_reset(st_g_uintTestTimer.timer_type);
		l_ret |= TIMERx_stop(st_g_uintTestTimer.timer_type);
		
	}
	return l_ret;
}