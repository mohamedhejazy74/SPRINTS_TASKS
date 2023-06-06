/*
 * led_config.c
 *
 * Created: 6/6/2023 3:54:28 PM
 *  Author: Mcs
 */ 
#include "led.h"

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
