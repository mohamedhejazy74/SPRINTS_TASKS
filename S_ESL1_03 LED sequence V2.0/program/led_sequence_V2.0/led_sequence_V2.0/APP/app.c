/*
 * app.c
 *
 * Created: 4/5/2023 8:31:23 PM
 *  Author: Mohamed Abdel-Wahab
 */ 
#include "app.h"

led_t s_led0 = {
	.led_pin.port=PORTC_INDEX,
	.led_pin.pin=PIN0,
	.led_status = LED_OFF
};
led_t s_led1 = {
	.led_pin.port=PORTC_INDEX,
	.led_pin.pin=PIN1,
	.led_status = LED_OFF
};
led_t s_led2 = {
	.led_pin.port=PORTC_INDEX,
	.led_pin.pin=PIN2,
	.led_status = LED_OFF
};
led_t s_led3 = {
	.led_pin.port=PORTC_INDEX,
	.led_pin.pin=PIN3,
	.led_status = LED_OFF
};
button_t s_btn0 = {
	.button_pin.port = PORTD_INDEX,
	.button_pin.pin  = PIN2,
	.button_connection = BUTTON_ACTIVE_HIGH,
	.button_state = BUTTON_RELEASED
 };
 Interrupt_Config_t s_INT0 = {
	.source_id = INTERRUPT_EXTERNAL_INT0,
	.edge = INTERRUPT_RISING_EDGE 
 };
 

volatile uint8_t g_pressCnt = IDLE_STATE ;

volatile void LEDS_SEQ_UPDATE(void)
{
	g_pressCnt++;
}

Std_ReturnType APP_init(void)
{
	Std_ReturnType ret = E_OK;
	GLOBAL_InterruptEnable();
	ret  = LED_initialize(&s_led0);
	ret |= LED_initialize(&s_led1);
	ret |= LED_initialize(&s_led2);
	ret |= LED_initialize(&s_led3);
	ret |= BTN_init(&s_btn0);
	ret |= EXT_INTx_Init(&s_INT0);
	return ret;
}

Std_ReturnType APP_start_program(void)
{
	Std_ReturnType ret = E_OK;
	ret = EXT_INTx_setCallBack(&LEDS_SEQ_UPDATE,INTERRUPT_EXTERNAL_INT0);
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
		}
	
	return ret;
}

