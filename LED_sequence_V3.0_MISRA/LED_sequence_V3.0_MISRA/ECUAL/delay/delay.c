/*
 * delay.c
 *
 * Created: 4/11/2023 7:29:32 AM
 *  Author: Mcs
 */ 
#include "delay.h"

/*configure the timer increment tick to every 1ms */
/*Timer_Config_t st_g_timerForDelay = {
	.timer_type = Timer0,
	.timer_mode = TIMER_NORMAL_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue =157,
};*/
 Timer_Config_t st_g_timerForDelay = {
	.timer_type = Timer0,
	.timer_mode = TIMER_CTC_MODE,
	.timer_clock = F_CPU_1024,
	.timer_InitialValue = INTIALIZE_TIMER_WITH_ZERO,
	.timer_compare_MatchValue = CONFIG_COMPARE_VALUE,
	.output_compare_mode = CTC_Output_Compare_Mode_DISCONNECTED
};

static volatile uint16_t u16_sg_timerTick;
static volatile uint16_t u16_sg_delay_ms;
static volatile uint8_t u8_sg_haltDelay;

static void INCREMENT_TICK(void)
{
	/*ticks equal 100s*/
	u16_sg_timerTick++;
	if((u16_sg_timerTick ) >= (u16_sg_delay_ms))
	{
			u16_sg_timerTick = 0;
			u8_sg_haltDelay = 1;
	}
	else 
	{
		
	}	
} 

/*get delay to the static global variable so that the update tick function could see it*/
static void get_delay(uint16_t u16_a_delay_ms)
{
	u16_sg_delay_ms = u16_a_delay_ms;
}

Std_ReturnType DELAY_ms(const uint16_t u16_a_delay_ms)
{
	Std_ReturnType l_ret = E_OK;
	if( (st_g_timerForDelay.timer_type >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		/*get delay to the static global variable so that the update tick function could see it*/
		get_delay(u16_a_delay_ms);
		/*set call-back function that increment the timer tick */
		l_ret |= TIMERx_setCallBack(&INCREMENT_TICK , st_g_timerForDelay.timer_type);
		/*initiate the timer */
		l_ret = TIMERx_init(&st_g_timerForDelay);
		/*wait here in the busy loop till the u8_sg_haltDelay get set by the ISR which indicate that the delay time has ended*/
		while(u8_sg_haltDelay);
		u8_sg_haltDelay = 0;
		/*HALT the timer */
		l_ret |= TIMERx_stop(st_g_timerForDelay.timer_type);		
	}
	return l_ret;
}