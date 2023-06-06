/*
 * button_config.c
 *
 * Created: 6/6/2023 4:09:24 PM
 *  Author: Mcs
 */ 

#include "button.h"

button_t s_btn0 = {
	.button_pin.port = PORTA_INDEX,
	.button_pin.pin  = PIN0,
	.button_connection = BUTTON_ACTIVE_HIGH,
	.button_state = BUTTON_RELEASED
};