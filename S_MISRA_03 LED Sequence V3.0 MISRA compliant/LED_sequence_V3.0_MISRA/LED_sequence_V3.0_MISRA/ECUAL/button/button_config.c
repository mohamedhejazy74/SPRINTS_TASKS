/*
 * button_config.c
 *
 * Created: 6/7/2023 5:22:24 PM
 *  Author: Mcs
 */ 

#include "button.h"

button_t s_btn0 = {
	.button_pin.port = PORTD_INDEX,
	.button_pin.pin  = PIN2,
	.button_connection = BUTTON_ACTIVE_HIGH,
	.button_state = BUTTON_RELEASED
};
button_t s_btn1 = {
	.button_pin.port = PORTD_INDEX,
	.button_pin.pin  = PIN3,
	.button_connection = BUTTON_ACTIVE_HIGH,
	.button_state = BUTTON_RELEASED
};