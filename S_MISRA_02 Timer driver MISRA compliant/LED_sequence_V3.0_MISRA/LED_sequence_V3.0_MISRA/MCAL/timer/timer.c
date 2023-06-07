/*
 * timer.c
 *
 * Created: 4/10/2023 3:38:03 PM
 *  Author:  Mohamed Abdel-Wahab
 */ 
#include "timer.h"

/* Global pointers to function to hold the address of the call back function in the upper layers */
static  void (*g_Timer0_callBackPtr)(void) = NULL;
static  void (*g_Timer1_callBackPtr)(void) = NULL;
static  void (*g_Timer2_callBackPtr)(void) = NULL;

/*helper static functions prototypes*/
static Std_ReturnType TIMERx_selectClk(const TimerType_t en_a_timer_type,const TimerClock_t en_a_timer_clk);
static Std_ReturnType TIMERx_setTimerMode(const Timer_Config_t *stPtr_a_Config);

/***********************Interrupt Service Routines for Timer0 *************************/
ISR(TIMER0_OVF_vect)
{
	if(g_Timer0_callBackPtr != NULL)
	{
		/* The timer0 overflow  occurred (must be cleared in software) */
		 CLEAR_BIT(TIFR,TOV0);
		/* Call the Call Back function in the upper layer after the timer overflow*/
		(*g_Timer0_callBackPtr)();
	}
}
ISR(TIMER0_COMP_vect)
{
	if(g_Timer0_callBackPtr != NULL)
	{
		/* The timer0 compare match occurred (must be cleared in software) */
		CLEAR_BIT(TIFR,OCF0);
		/* Call the Call Back function in the upper layer after the timer matches the compare value*/
		(*g_Timer0_callBackPtr)();
	}
}
/***********************Interrupt Service Routines for Timer1 *************************/
ISR(TIMER1_OVF_vect)
{
	if(g_Timer1_callBackPtr != NULL)
	{
		/* The timer0 overflow  occurred (must be cleared in software) */
		CLEAR_BIT(TIFR,TOV1);
		/* Call the Call Back function in the upper layer after the timer overflow*/
		(*g_Timer1_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(g_Timer1_callBackPtr != NULL)
	{
		/* The timer0 compare match occurred (must be cleared in software) */
		CLEAR_BIT(TIFR,OCF1A);
		/* Call the Call Back function in the upper layer after the timer matches the compare value*/
		(*g_Timer1_callBackPtr)();
	}
}
/***********************Interrupt Service Routines for Timer2 *************************/
ISR(TIMER2_OVF_vect)
{
	if(g_Timer2_callBackPtr != NULL)
	{
		/* The timer2 overflow  occurred (must be cleared in software) */
		CLEAR_BIT(TIFR,TOV2);
		/* Call the Call Back function in the upper layer after the timer overflow*/
		(*g_Timer2_callBackPtr)();
	}
}

ISR(TIMER2_COMP_vect)
{
	if(g_Timer2_callBackPtr != NULL)
	{
		/* The timer2 compare match occurred (must be cleared in software) */
		CLEAR_BIT(TIFR,OCF2);
		/* Call the Call Back function in the upper layer after the timer matches the compare value*/
		(*g_Timer2_callBackPtr)();
	}
}
/*****************************************************************************************/
Std_ReturnType TIMERx_setCallBack( void(*a_fptr)(void), const TimerType_t en_a_timer_type )
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_type >= INVALID_TIMER_TYPE) || (NULL==a_fptr) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(en_a_timer_type)
		{
			case Timer0:
				/* load the address of the Call back function from upper layer in the global pointer to function */
				g_Timer0_callBackPtr = a_fptr;
				break;
			case Timer1:
				/* load the address of the Call back function from upper layer in the global pointer to function */
				g_Timer1_callBackPtr = a_fptr;
				break;
			case Timer2:
				/* load the address of the Call back function from upper layer in the global pointer to function */
				g_Timer2_callBackPtr = a_fptr;
				break;
			default:
				l_ret = E_NOT_OK;
				break;
		}
	}
	return l_ret;
}


Std_ReturnType TIMERx_init(const Timer_Config_t *stPtr_a_Config)
{
	Std_ReturnType l_ret = E_OK;
	if((stPtr_a_Config == NULL) || (stPtr_a_Config->timer_type >= INVALID_TIMER_TYPE) || (stPtr_a_Config->timer_mode >= INVALID_TIMER_MODE) ||
	(stPtr_a_Config->output_compare_mode >=CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE ) || stPtr_a_Config->fast_pwm_mode >= FAST_INVALID_TIMER_FAST_PWM_MODE)
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(stPtr_a_Config->timer_type)
		{
			case Timer0:
				/*Clear registers of Timer0 before processing any of them*/
				CLEAR_REG(TCNT0);
				CLEAR_REG(TCCR0);
				CLEAR_REG(OCR0);
				/*Configure initial value in TCNT0 for Timer0 to start count from it*/
				TCNT0 = stPtr_a_Config->timer_InitialValue & U8_BIT_REG_MASK;
				/*Configure the TIMER mode value and enable the interrupt for this mode*/
				l_ret |= TIMERx_setTimerMode(stPtr_a_Config);
				break;
			
			case Timer1:
				/*Clear registers of Timer1 before processing any of them*/
				CLEAR_REG(TCNT1L);
				CLEAR_REG(TCNT1H);
				CLEAR_REG(TCCR1A);
				CLEAR_REG(TCCR1B);
				CLEAR_REG(OCR1AH);
				CLEAR_REG(OCR1AL);
				/*Configure initial value in TCNT1(high&low) for Timer0 to start count from it*/
// 				TCNT1L =(stPtr_a_Config->timer_InitialValue) & U8_BIT_REG_MASK;
// 				TCNT1H = (stPtr_a_Config->timer_InitialValue >> U8_BIT_REG_MASK) & U8_BIT_REG_MASK;
				TCNT1 = stPtr_a_Config->timer_InitialValue;
				
				/*Configure the TIMER mode value and enable the interrupt for this mode*/
				l_ret |= TIMERx_setTimerMode(stPtr_a_Config);
				break;
			
			case Timer2:
				/*Clear registers of Timer2 before processing any of them*/
				CLEAR_REG(TCNT2);
				CLEAR_REG(TCCR2);
				CLEAR_REG(OCR2);
				/*Configure initial value in TCNT for Timer2 to start count from it*/
				TCNT2 = stPtr_a_Config->timer_InitialValue & U8_BIT_REG_MASK;
				/*Configure the TIMER mode value and enable the interrupt for this mode*/
				l_ret |= TIMERx_setTimerMode(stPtr_a_Config);
				break;
			
			default:
				l_ret |= E_NOT_OK;
				break;
		}
	}
	return l_ret;
}
Std_ReturnType TIMERx_start(const TimerClock_t en_a_timer_clk,const TimerType_t en_a_timer_type)
{
	Std_ReturnType l_ret = E_OK;
	if((en_a_timer_clk >= INVALID_TIMER_CLK)||(en_a_timer_type >= INVALID_TIMER_TYPE))
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		/*Configure the TIMER Pres-scaler value for Timer-x clock*/
		l_ret = TIMERx_selectClk(en_a_timer_type,en_a_timer_clk);
	}
	return l_ret;
}
Std_ReturnType TIMERx_setValue(const TimerType_t en_a_timer_type ,const uint16_t u16_a_timer_value)
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_type >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(en_a_timer_type)
		{
			case Timer0:
				TCNT0 = u16_a_timer_value & U8_BIT_REG_MASK;
				break;
				
			case Timer1:
// 				TCNT1L = (uint8_t)(u16_a_timer_value) & U8_BIT_REG_MASK;
// 				TCNT1H = (uint8_t)(u16_a_timer_value >> 8) & U8_BIT_REG_MASK;
				TCNT1 = u16_a_timer_value;		
				break;
				
			case Timer2:
				TCNT2 = u16_a_timer_value & U8_BIT_REG_MASK;
				break;
				
			default:
				l_ret |= E_NOT_OK;
				break;
		}
	}
	return l_ret;
}

Std_ReturnType TIMERx_CTC_SetCompare(const TimerType_t en_a_timer_type ,const uint16_t u16_a_compareValue)
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_type >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(en_a_timer_type)
		{
			case Timer0:
				OCR0 =(uint8_t) u16_a_compareValue & U8_BIT_REG_MASK;
				break;
				
			case Timer1:
// 				OCR1AL = (uint8_t)u16_a_compareValue & U8_BIT_REG_MASK;
// 				OCR1AH = (uint8_t)(u16_a_compareValue >> U8_BIT_REG_MASK) & U8_BIT_REG_MASK;
				OCR1A  = u16_a_compareValue;
				break;
				
			case Timer2:
				OCR2 =(uint8_t) u16_a_compareValue & U8_BIT_REG_MASK;
				break;
				
			default:
				l_ret |= E_NOT_OK;
				break;
		}
	}
	return l_ret;
}


Std_ReturnType TIMERx_reset(const TimerType_t en_a_timer_type)
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_type >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(en_a_timer_type)
		{
			case Timer0:
				/*Clear registers of Timer0 before processing any of them*/
				CLEAR_REG(TCNT0);
				CLEAR_REG(TCCR0);
				CLEAR_REG(OCR0);
				break;
				
			case Timer1:
				/*Clear registers of Timer1 before processing any of them*/
				CLEAR_REG(TCNT1L);
				CLEAR_REG(TCNT1H);
				CLEAR_REG(TCCR1A);
				CLEAR_REG(TCCR1B);
				CLEAR_REG(OCR1AH);
				CLEAR_REG(OCR1AL);
				break;
				
			case Timer2:
				/*Clear registers of Timer2 before processing any of them*/
				CLEAR_REG(TCNT2);
				CLEAR_REG(TCCR2);
				CLEAR_REG(OCR2);
				break;
				
			default:
				l_ret |= E_NOT_OK;
				break;
		}
	}
	return l_ret;
}

Std_ReturnType TIMERx_stop(const TimerType_t en_a_timer_type)
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_type >= INVALID_TIMER_TYPE) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(en_a_timer_type)
		{
			case Timer0:
				/*use no clock to halt timer0*/
				CLEAR_BIT(TCCR0,CS00);
				CLEAR_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS02);
				break;
				
			case Timer1:
				/*use no clock to halt timer1*/
				CLEAR_BIT(TCCR1B,CS10);
				CLEAR_BIT(TCCR1B,CS11);
				CLEAR_BIT(TCCR1B,CS12);
				break;
				
			case Timer2:
				/*use no clock to halt timer2*/
				CLEAR_BIT(TCCR2,CS20);
				CLEAR_BIT(TCCR2,CS21);
				CLEAR_BIT(TCCR2,CS22);
				break;
				
			default:
				l_ret |= E_NOT_OK;
				break;
		}
	}
	return l_ret;
}

static Std_ReturnType TIMERx_selectClk(const TimerType_t en_a_timer_type,const TimerClock_t en_a_timer_clk)
{
	Std_ReturnType l_ret = E_OK;
	if( (en_a_timer_type >= INVALID_TIMER_TYPE) || (en_a_timer_clk >= INVALID_TIMER_CLK) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(en_a_timer_type)
		{
			case Timer0:
				switch(en_a_timer_clk)
				{
					case NO_CLOCK:
						CLEAR_BIT(TCCR0,CS00);
						CLEAR_BIT(TCCR0,CS01);
						CLEAR_BIT(TCCR0,CS02);
						break;
					case F_CPU_CLOCK:
						SET_BIT(TCCR0,CS00);
						CLEAR_BIT(TCCR0,CS01);
						CLEAR_BIT(TCCR0,CS02);
						break;
					case F_CPU_8:
						CLEAR_BIT(TCCR0,CS00);
						SET_BIT(TCCR0,CS01);
						CLEAR_BIT(TCCR0,CS02);
						break;
					case F_CPU_64:
						SET_BIT(TCCR0,CS00);
						SET_BIT(TCCR0,CS01);
						CLEAR_BIT(TCCR0,CS02);
						break;
					case F_CPU_256:
						CLEAR_BIT(TCCR0,CS00);
						CLEAR_BIT(TCCR0,CS01);
						SET_BIT(TCCR0,CS02);
						break;
					case F_CPU_1024:
						SET_BIT(TCCR0,CS00);
						CLEAR_BIT(TCCR0,CS01);
						SET_BIT(TCCR0,CS02);	
						break;
					case TIMER_EXTERNAL_CLK_FALLING_EDGE:
						CLEAR_BIT(TCCR0,CS00);
						SET_BIT(TCCR0,CS01);
						SET_BIT(TCCR0,CS02);
						break;
					case TIMER_EXTERNAL_CLK_RISING_EDGE:
						SET_BIT(TCCR0,CS00);
						SET_BIT(TCCR0,CS01);
						SET_BIT(TCCR0,CS02);
						break;
					default:
						l_ret = E_NOT_OK;
						break;
				}
				break;
				
			case Timer1:
				switch(en_a_timer_clk)
				{
					case NO_CLOCK:
						CLEAR_BIT(TCCR1B,CS10);
						CLEAR_BIT(TCCR1B,CS11);
						CLEAR_BIT(TCCR1B,CS12);
						break;
					case F_CPU_CLOCK:
						SET_BIT(TCCR1B,CS10);
						CLEAR_BIT(TCCR1B,CS11);
						CLEAR_BIT(TCCR1B,CS12);
						break;
					case F_CPU_8:
						CLEAR_BIT(TCCR1B,CS10);
						SET_BIT(TCCR1B,CS11);
						CLEAR_BIT(TCCR1B,CS12);
						break;
					case F_CPU_64:
						SET_BIT(TCCR1B,CS10);
						SET_BIT(TCCR1B,CS11);
						CLEAR_BIT(TCCR1B,CS12);
						break;
					case F_CPU_256:
						CLEAR_BIT(TCCR1B,CS10);
						CLEAR_BIT(TCCR1B,CS11);
						SET_BIT(TCCR1B,CS12);
						break;
					case F_CPU_1024:
						SET_BIT(TCCR1B,CS10);
						CLEAR_BIT(TCCR1B,CS11);
						SET_BIT(TCCR1B,CS12);	
						break;
					case TIMER_EXTERNAL_CLK_FALLING_EDGE:
						CLEAR_BIT(TCCR1B,CS10);
						SET_BIT(TCCR1B,CS11);
						SET_BIT(TCCR1B,CS12);
						break;
					case TIMER_EXTERNAL_CLK_RISING_EDGE:
						SET_BIT(TCCR1B,CS10);
						SET_BIT(TCCR1B,CS11);
						SET_BIT(TCCR1B,CS12);
						break;
					default:
						l_ret = E_NOT_OK;
						break;
				}			
				break;
				
			case Timer2:
				switch(en_a_timer_clk)
				{
					case NO_CLOCK:
						CLEAR_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS21);
						CLEAR_BIT(TCCR2,CS22);
						break;
					case F_CPU_CLOCK:
						SET_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS21);
						CLEAR_BIT(TCCR2,CS22);
						break;
					case F_CPU_8:
						CLEAR_BIT(TCCR2,CS20);
						SET_BIT(TCCR2,CS21);
						CLEAR_BIT(TCCR2,CS22);
						break;
					case F_CPU_32:
						SET_BIT(TCCR2,CS20);
						SET_BIT(TCCR2,CS21);
						CLEAR_BIT(TCCR2,CS22);
						break;
					case F_CPU_64:
						CLEAR_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS21);
						SET_BIT(TCCR2,CS22);
						break;
					case F_CPU_128:
						SET_BIT(TCCR2,CS20);
						CLEAR_BIT(TCCR2,CS21);
						SET_BIT(TCCR2,CS22);
						break;
					case F_CPU_256:
						CLEAR_BIT(TCCR2,CS20);
						SET_BIT(TCCR2,CS21);
						SET_BIT(TCCR2,CS22);
						break;
					case F_CPU_1024:
						SET_BIT(TCCR2,CS20);
						SET_BIT(TCCR2,CS21);
						SET_BIT(TCCR2,CS22);	
						break;
					default:
						l_ret = E_NOT_OK;
						break;
				}
				break;
				
			default:
				l_ret |= E_NOT_OK;
				break;
		}
	}
	return l_ret;
}


static Std_ReturnType TIMERx_setTimerMode(const Timer_Config_t *stPtr_a_Config)
{
	Std_ReturnType l_ret = E_OK;
	if( (stPtr_a_Config == NULL) || (stPtr_a_Config->timer_type >= INVALID_TIMER_TYPE) || (stPtr_a_Config->timer_mode >= INVALID_TIMER_MODE) ||
	    (stPtr_a_Config->output_compare_mode >=CTC_INVALID_TIMER_OUTPUT_COMPARE_MODE ) )
	{
		l_ret = E_NOT_OK;
	}
	else
	{
		switch(stPtr_a_Config->timer_type)
		{
			case Timer0:
				switch(stPtr_a_Config->timer_mode)
				{
					case TIMER_NORMAL_MODE:
						/*Make FOC0 to be Active as it is overflow mode(for non-PWM mode)*/
						SET_BIT(TCCR0,FOC0);
						/*Normal Overflow mode*/
						CLEAR_BIT(TCCR0,WGM00);
						CLEAR_BIT(TCCR0,WGM01);
						/*Normal port operation, OC0 disconnected*/
						CLEAR_BIT(TCCR0,COM00);
						CLEAR_BIT(TCCR0,COM01);
						/* Enable Timer0 overflow interrupt*/
						SET_BIT(TIMSK,TOIE0);
						break;
					case TIMER_PHASE_CORRECT_PWM_MODE:
						/*PWM Phase Correct*/
						SET_BIT(TCCR0,WGM00);
						CLEAR_BIT(TCCR0,WGM01);
						/*Compare Output Mode, Phase Correct PWM Mode*/
						switch(stPtr_a_Config->phase_correct_pwm_mode)
						{
							case PC_Output_Compare_Mode_DISCONNECTED:
								/* Normal port operation, OC0 disconnected.*/
								CLEAR_BIT(TCCR0,COM00);
								CLEAR_BIT(TCCR0,COM01);
								break;
							case PC_Output_Compare_Mode_NON_INVERTED:
								/*Clear OC0 on compare match when up-counting Set OC0 on compare match when down counting*/
								CLEAR_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							case PC_Output_Compare_Mode_INVERTED:
							/*Set OC0 on compare match when up-counting Clear OC0 on compare match when down counting*/
								SET_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
						 /*The Output Compare Register contains an 8-bit value that is continuously compared with the  counter value (TCNT0) */
						 OCR0 =(uint8_t) stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
						break;
						
					case TIMER_FAST_PWM_MODE:
						/*Fast PWM*/
						SET_BIT(TCCR0,WGM00);
						SET_BIT(TCCR0,WGM01);
						/*Compare Output Mode, Fast PWM Mode*/
						switch(stPtr_a_Config->fast_pwm_mode)
						{
							case FAST_Output_Compare_Mode_DISCONNECTED:
								/* Normal port operation, OC0 disconnected.*/
								CLEAR_BIT(TCCR0,COM00);
								CLEAR_BIT(TCCR0,COM01);
								break;
							case FAST_Output_Compare_Mode_NON_INVERTED:
								/*Clear OC0 on compare match, set OC0 at BOTTOM*/
								CLEAR_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							case FAST_Output_Compare_Mode_INVERTED:
							/*Set OC0 on compare match, clear OC0 at BOTTOM*/
								SET_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
						 /*The Output Compare Register contains an 8-bit value that is continuously compared with the  counter value (TCNT0) */
						 OCR0 = stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
						break;
						
					case TIMER_CTC_MODE:
						/*Make FOC0 to be Active as it is CTC mode(for non-PWM mode)*/
						SET_BIT(TCCR0,FOC0);
						/*CTC Mode, non-PWM Mode*/
						CLEAR_BIT(TCCR0,WGM00);
						SET_BIT(TCCR0,WGM01);
						/*Compare Output Mode, non-PWM Mode*/
						switch(stPtr_a_Config->output_compare_mode)
						{
							case CTC_Output_Compare_Mode_DISCONNECTED:
								/* Normal port operation, OC0 disconnected.*/
								CLEAR_BIT(TCCR0,COM00);
								CLEAR_BIT(TCCR0,COM01);
								break;
							case CTC_Output_Compare_Mode_TOGGLE:
								/* Toggle OC0 on compare match*/
								SET_BIT(TCCR0,COM00);
								CLEAR_BIT(TCCR0,COM01);
								break;
							case CTC_Output_Compare_Mode_CLEAR:
								/*Clear OC0 on compare match*/
								CLEAR_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							case CTC_Output_Compare_SET:
							/*Set OC0 on compare match*/
								SET_BIT(TCCR0,COM00);
								SET_BIT(TCCR0,COM01);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
					    /*The Output Compare Register contains an 8-bit value that is continuously compared with the  counter value (TCNT0) */
						OCR0 = stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;	
						/* Enable Timer0 CTC mode interrupt*/
						SET_BIT(TIMSK,OCIE0);
						break;
					default:
						l_ret = E_NOT_OK;
						break;
				}
				break;
				
			case Timer1:
				switch(stPtr_a_Config->timer_mode)
				{
					case TIMER_NORMAL_MODE:
						/*Make FOC1A,FOC1B to be Active as it is overflow mode(for non-PWM mode)*/
						SET_BIT(TCCR1A,FOC1A);
						SET_BIT(TCCR1A,FOC1B);
						/*Normal Overflow mode*/
						CLEAR_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						CLEAR_BIT(TCCR1B,WGM12);
						CLEAR_BIT(TCCR1B,WGM13);
						/*Normal port operation, OC1A/OC1B disconnected.*/
						CLEAR_BIT(TCCR1A,COM1A0);
						CLEAR_BIT(TCCR1A,COM1A1);
						CLEAR_BIT(TCCR1A,COM1B0);
						CLEAR_BIT(TCCR1A,COM1B1);
						/* Enable Timer0 overflow interrupt*/
						SET_BIT(TIMSK,TOIE1);
						break;
					case TIMER_PHASE_CORRECT_PWM_MODE:
						/*PWM Phase Correct 8-bit,top= 0x00FF ,Update of OCR1A at TOP,TOV1 Flag Set on BOTTOM*/
						SET_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						CLEAR_BIT(TCCR1B,WGM12);
						CLEAR_BIT(TCCR1B,WGM13);
						/*Compare Output Mode, Phase Correct PWM Mode*/
						switch(stPtr_a_Config->phase_correct_pwm_mode)
						{
							case PC_Output_Compare_Mode_DISCONNECTED:
								/*Normal port operation, OC1A/OC1B disconnected.*/
								CLEAR_BIT(TCCR1A,COM1A0);
								CLEAR_BIT(TCCR1A,COM1A1);
								CLEAR_BIT(TCCR1A,COM1B0);
								CLEAR_BIT(TCCR1A,COM1B1);
								break;
							case PC_Output_Compare_Mode_TOGGLE:
								/* Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
								 * For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected
								 */
								SET_BIT(TCCR1A,COM1A0);
								CLEAR_BIT(TCCR1A,COM1A1);
								SET_BIT(TCCR1A,COM1B0);
								CLEAR_BIT(TCCR1A,COM1B1);
								break;
							case PC_Output_Compare_Mode_NON_INVERTED:
								/*Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare
								* match when down counting. (non-inverting mode)
								*/
								CLEAR_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1A1);
								CLEAR_BIT(TCCR1A,COM1B0);
								SET_BIT(TCCR1A,COM1B1);
								break;
							case PC_Output_Compare_Mode_INVERTED:
								/* Set OC1A/OC1B on compare match when up-counting. Clear OC1A/OC1B on compare
								* match when down counting,(inverting mode)
								*/
								SET_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1A1);
								SET_BIT(TCCR1A,COM1B0);
								SET_BIT(TCCR1A,COM1B1);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
						/*The Output Compare Register contains an 16-bit value that is continuously compared with the  counter value (TCNT1) */
// 						OCR1AL = (uint8_t)stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
// 						OCR1AH = (uint8_t)(stPtr_a_Config->timer_compare_MatchValue >> U8_BIT_REG_MASK) & U8_BIT_REG_MASK;
						OCR1A = stPtr_a_Config->timer_compare_MatchValue;
						break;
						
					case TIMER_FAST_PWM_MODE:
						/*Fast PWM 8-bit,top= 0x00FF ,Update of OCR1A at BOTTOM,TOV1 Flag Set on TOP*/
						SET_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						SET_BIT(TCCR1B,WGM12);
						CLEAR_BIT(TCCR1B,WGM13);
						/*Compare Output Mode, Fast PWM Mode*/
						switch(stPtr_a_Config->fast_pwm_mode)
						{
							case FAST_Output_Compare_Mode_DISCONNECTED:
								/*Normal port operation, OC1A/OC1B disconnected.*/
								CLEAR_BIT(TCCR1A,COM1A0);
								CLEAR_BIT(TCCR1A,COM1A1);
								CLEAR_BIT(TCCR1A,COM1B0);
								CLEAR_BIT(TCCR1A,COM1B1);
								break;
							case FAST_Output_Compare_Mode_TOGGLE:
								/* Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
								 * For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected
								 */
								SET_BIT(TCCR1A,COM1A0);
								CLEAR_BIT(TCCR1A,COM1A1);
								SET_BIT(TCCR1A,COM1B0);
								CLEAR_BIT(TCCR1A,COM1B1);
								break;
							case FAST_Output_Compare_Mode_NON_INVERTED:
								/*Clear OC1A/OC1B on compare match, setOC1A/OC1B at BOTTOM, (non-inverting mode)*/
								CLEAR_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1A1);
								CLEAR_BIT(TCCR1A,COM1B0);
								SET_BIT(TCCR1A,COM1B1);
								break;
							case FAST_Output_Compare_Mode_INVERTED:
							/* Set OC1A/OC1B on compare match, clear OC1A/OC1B at BOTTOM,(inverting mode)*/
								SET_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1A1);
								SET_BIT(TCCR1A,COM1B0);
								SET_BIT(TCCR1A,COM1B1);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
						/*The Output Compare Register contains an 16-bit value that is continuously compared with the  counter value (TCNT1) */
// 						OCR1AL = (uint8_t)stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
// 						OCR1AH = (uint8_t)(stPtr_a_Config->timer_compare_MatchValue >> U8_BIT_REG_MASK) & U8_BIT_REG_MASK;
						OCR1A = stPtr_a_Config->timer_compare_MatchValue;
						break;
						
					case TIMER_CTC_MODE:
						/*Make FOC1A,FOC1B to be Active as it is overflow mode(for non-PWM mode)*/
						SET_BIT(TCCR1A,FOC1A);
						SET_BIT(TCCR1A,FOC1B);
						/*CTC Mode, non-PWM Mode*/
						CLEAR_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						SET_BIT(TCCR1B,WGM12);
						CLEAR_BIT(TCCR1B,WGM13);
						/*Compare Output Mode, non-PWM Mode*/
						switch(stPtr_a_Config->output_compare_mode)
						{
							case CTC_Output_Compare_Mode_DISCONNECTED:
								/*Normal port operation, OC1A/OC1B disconnected.*/
								CLEAR_BIT(TCCR1A,COM1A0);
								CLEAR_BIT(TCCR1A,COM1A1);
								CLEAR_BIT(TCCR1A,COM1B0);
								CLEAR_BIT(TCCR1A,COM1B1);
								break;
							case CTC_Output_Compare_Mode_TOGGLE:
								/* Toggle OC1A/OC1B on compare match*/
								SET_BIT(TCCR1A,COM1A0);
								CLEAR_BIT(TCCR1A,COM1A1);
								SET_BIT(TCCR1A,COM1B0);
								CLEAR_BIT(TCCR1A,COM1B1);
								break;
							case CTC_Output_Compare_Mode_CLEAR:
								/*clear OC1A/OC1B on compare match (Set output to low level)*/
								CLEAR_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1A1);
								CLEAR_BIT(TCCR1A,COM1B0);
								SET_BIT(TCCR1A,COM1B1);
								break;
							case CTC_Output_Compare_SET:
							/* Set OC1A/OC1B on compare match (Set output to high level)*/
								SET_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1A1);
								SET_BIT(TCCR1A,COM1B0);
								SET_BIT(TCCR1A,COM1B1);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
					    /*The Output Compare Register contains an 16-bit value that is continuously compared with the  counter value (TCNT1) */
// 						OCR1AL = (uint8_t)stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
// 						OCR1AH = (uint8_t)(stPtr_a_Config->timer_compare_MatchValue >> U8_BIT_REG_MASK) & U8_BIT_REG_MASK;
						OCR1A = stPtr_a_Config->timer_compare_MatchValue;	
						/* Enable Timer1 CTC-A mode interrupt*/
						SET_BIT(TIMSK,OCIE1A);
						break;
					default:
						l_ret = E_NOT_OK;
						break;
				}
				
				break;
				
			case Timer2:
				switch(stPtr_a_Config->timer_mode)
				{
					case TIMER_NORMAL_MODE:
						/*Make FOC2 to be Active as it is overflow mode(for non-PWM mode)*/
						SET_BIT(TCCR2,FOC2);
						/*Normal Overflow mode*/
						CLEAR_BIT(TCCR2,WGM20);
						CLEAR_BIT(TCCR2,WGM21);
						/*Normal port operation, OC2 disconnected*/
						CLEAR_BIT(TCCR2,COM20);
						CLEAR_BIT(TCCR2,COM21);
						/* Enable Timer2 overflow interrupt*/
						SET_BIT(TIMSK,TOIE2);
						break;
					case TIMER_PHASE_CORRECT_PWM_MODE:
						/*PWM Phase Correct*/
						SET_BIT(TCCR2,WGM20);
						CLEAR_BIT(TCCR2,WGM21);
						/*Compare Output Mode, Phase Correct PWM Mode*/
						switch(stPtr_a_Config->phase_correct_pwm_mode)
						{
							case PC_Output_Compare_Mode_DISCONNECTED:
								/* Normal port operation, OC2 disconnected.*/
								CLEAR_BIT(TCCR2,COM20);
								CLEAR_BIT(TCCR2,COM21);
								break;
							case PC_Output_Compare_Mode_NON_INVERTED:
								/*Clear OC2 on compare match when up-counting Set OC2 on compare match when down counting*/
								CLEAR_BIT(TCCR2,COM20);
								SET_BIT(TCCR2,COM21);
								break;
							case PC_Output_Compare_Mode_INVERTED:
							/*Set OC2 on compare match when up-counting Clear OC2 on compare match when down counting*/
								SET_BIT(TCCR2,COM20);
								SET_BIT(TCCR2,COM21);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
						/*The Output Compare Register contains an 8-bit value that is continuously compared with the  counter value (TCNT2) */
						OCR2 = (uint8_t)stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
						break;
						
					case TIMER_FAST_PWM_MODE:
						/*Fast PWM*/
						SET_BIT(TCCR2,WGM20);
						SET_BIT(TCCR2,WGM21);
						/*Compare Output Mode, Fast PWM Mode*/
						switch(stPtr_a_Config->fast_pwm_mode)
						{
							case FAST_Output_Compare_Mode_DISCONNECTED:
								/* Normal port operation, OC2 disconnected.*/
								CLEAR_BIT(TCCR2,COM20);
								CLEAR_BIT(TCCR2,COM21);
								break;
							case FAST_Output_Compare_Mode_NON_INVERTED:
								/*Clear OC2 on compare match, set OC2 at BOTTOM*/
								CLEAR_BIT(TCCR2,COM20);
								SET_BIT(TCCR2,COM21);
								break;
							case FAST_Output_Compare_Mode_INVERTED:
							/*Set OC2 on compare match, clear OC2 at BOTTOM*/
								SET_BIT(TCCR2,COM20);
								SET_BIT(TCCR2,COM21);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
						 /*The Output Compare Register contains an 8-bit value that is continuously compared with the  counter value (TCNT2) */
						 OCR2 =(uint8_t) stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
						break;
						
					case TIMER_CTC_MODE:
						/*Make FOC2 to be Active as it is CTC mode(for non-PWM mode)*/
						SET_BIT(TCCR2,FOC2);
						/*CTC Mode, non-PWM Mode*/
						CLEAR_BIT(TCCR2,WGM20);
						SET_BIT(TCCR2,WGM21);
						/*Compare Output Mode, non-PWM Mode*/
						switch(stPtr_a_Config->output_compare_mode)
						{
							case CTC_Output_Compare_Mode_DISCONNECTED:
								/* Normal port operation, OC2 disconnected.*/
								CLEAR_BIT(TCCR2,COM20);
								CLEAR_BIT(TCCR2,COM21);
								break;
							case CTC_Output_Compare_Mode_TOGGLE:
								/* Toggle OC2 on compare match*/
								SET_BIT(TCCR2,COM20);
								CLEAR_BIT(TCCR2,COM21);
								break;
							case CTC_Output_Compare_Mode_CLEAR:
								/*Clear OC2 on compare match*/
								CLEAR_BIT(TCCR2,COM20);
								SET_BIT(TCCR2,COM21);
								break;
							case CTC_Output_Compare_SET:
							/*Set OC2 on compare match*/
								SET_BIT(TCCR2,COM20);
								SET_BIT(TCCR2,COM21);
								break;
							default: 
								l_ret |= E_NOT_OK;
								break;
						}
					     /*The Output Compare Register contains an 8-bit value that is continuously compared with the  counter value (TCNT2) */
					     OCR2 =(uint8_t) stPtr_a_Config->timer_compare_MatchValue & U8_BIT_REG_MASK;
						/* Enable Timer0 CTC mode interrupt*/
						SET_BIT(TIMSK,OCIE2);
						break;
					default:
						l_ret = E_NOT_OK;
						break;
				}
				
				break;
				
			default:
				l_ret = E_NOT_OK;
				break;
		}
	}
	
	return l_ret;
}


