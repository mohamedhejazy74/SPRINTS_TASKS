/*
 * app.c
 *
 * Created: 4/5/2023 8:31:23 PM
 *  Author: Mohamed Abdel-Wahab
 */ 
#include "app.h"


 
 
static button_status_t g_btn_state = BUTTON_RELEASED;
static button_status_t g_btn0_valid_state = BUTTON_RELEASED;
static button_status_t g_btn0_last_valid_state = BUTTON_RELEASED;
static uint32_t g_btn0_pressDuration = 0;
static uint8_t g_pressCnt = IDLE_STATE ;


Std_ReturnType APP_init(void)
{
	Std_ReturnType ret = E_OK;
	ret = LED_initialize(&s_led0);
	ret |= LED_initialize(&s_led1);
	ret |= LED_initialize(&s_led2);
	ret |= LED_initialize(&s_led3);
	ret |= BTN_init(&s_btn0);
	return ret;
}
Std_ReturnType APP_start_program(void)
{
	Std_ReturnType ret = E_OK;
	
	ret  = BTN_read_state(&s_btn0,&g_btn_state);
	if((BUTTON_PRESSED == g_btn_state))
	{
		
		if(g_btn0_pressDuration > DEBOUNCE_DELAY)
		{
			g_btn0_valid_state = BUTTON_PRESSED;
		}
		else
		{
			g_btn0_pressDuration++;
			
		}
	}
	else
	{
		g_btn0_pressDuration = 0;
		g_btn0_valid_state = BUTTON_RELEASED;
	}
	
	if(g_btn0_last_valid_state != g_btn0_valid_state)
	{
		g_btn0_last_valid_state = g_btn0_valid_state;
		
		if((BUTTON_PRESSED == g_btn0_valid_state))
		{
			g_pressCnt++;
			switch(g_pressCnt)
			{
				case FIRST_STATE:
					ret |= LED_turn_on(&s_led0);
					break;
				case SECOND_STATE:
					ret |= LED_turn_on(&s_led1);
					break;
				case THIRD_STATE:
					ret |= LED_turn_on(&s_led2);
					break;
				case FOURTH_STATE:
					ret |= LED_turn_on(&s_led3);
					break;
				case FIFTH_STATE:
					ret |= LED_turn_off(&s_led0);
					break;
				case SIXTH_STATE:
					ret |= LED_turn_off(&s_led1);
					break;
				case SEVENTH_STATE:
					ret |= LED_turn_off(&s_led2);
					break;
				case EIGHTH_STATE:
					ret |= LED_turn_off(&s_led3);
					g_pressCnt = IDLE_STATE;
					break;
				default:
					ret = E_NOT_OK;
					break;
			}
		}
		else
		{
			/*do nothing*/
		}
	}
	else
	{
		/*do nothing*/
	}
	return ret;
}