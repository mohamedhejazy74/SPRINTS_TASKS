/*
 * ext_int_config.c
 *
 * Created: 6/7/2023 4:52:26 PM
 *  Author: Mcs
 */ 

#include "external_interrupt.h"

Interrupt_Config_t s_INT0 = {
	.source_id = INTERRUPT_EXTERNAL_INT0,
	.edge = INTERRUPT_RISING_EDGE
};
Interrupt_Config_t s_INT1 = {
	.source_id = INTERRUPT_EXTERNAL_INT1,
	.edge = INTERRUPT_RISING_EDGE
};