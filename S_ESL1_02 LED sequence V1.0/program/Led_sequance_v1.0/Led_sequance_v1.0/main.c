/*
 * Led_sequance_v1.0.c
 *
 * Created: 4/5/2023 7:50:29 PM
 * Author : Mohamed Abdel-Wahab
 */ 

//#include <avr/io.h>

#include "APP/app.h"

Std_ReturnType ret = E_OK;

#if UINT_TEST==ENABLE_FEATURE
pin_config_t pin = {
	.port = PORTA_INDEX,
	.pin = PIN0
};
#endif


#if UINT_TEST==ENABLE_FEATURE
logic_t g_readLogic = DIO_LOGIC_LOW;
uint8_t g_readPortLogic;
#endif


int main(void)
{
    
#if RUN_MAIN_PROGRAM==ENABLE_FEATURE
	ret = APP_init();
#endif

#if UINT_TEST==ENABLE_FEATURE
/**********************************UINT TESTING FOR DIO DRIVER***********************************/
	/*test pin0 on port A as input */
	ret |= DIO_pin_direction_intialize(&pin,DIO_DIRECTION_INPUT);
	/*test pin0 as output */
	ret = DIO_pin_direction_intialize(&pin,DIO_DIRECTION_OUTPUT);
	/*test write high logic on pin0 on port A  */
	ret |= DIO_pin_write_logic(&pin,DIO_LOGIC_HIGH);
	/*test read the logic on pin0 on port A */
	ret |= DIO_pin_read_logic(&pin,&g_readLogic);
	/*test write low logic on pin0 on port A  */
	ret |= DIO_pin_write_logic(&pin,DIO_LOGIC_LOW);
	/*test read the logic on pin0 on port A */
	ret |= DIO_pin_read_logic(&pin,&g_readLogic);
	/*test toggle the logic on pin0 on port A  */
	ret |= DIO_pin_toggle_logic(&pin);
	/*test make all port A as output */
	ret |= DIO_port_direction_intialize(PORTA_INDEX,0xff);
	/*test make last 4-pin of port A  as input */
	ret |= DIO_port_direction_intialize(PORTA_INDEX,0x0f);
	/*test writing 00001010 on port a  */
	ret |= DIO_port_write_logic(PORTA_INDEX,0x0a);
	/*test read the logic on port a */
	ret |= DIO_port_read_logic(PORTA_INDEX,&g_readPortLogic);
	/*test toggle the logic on port a*/
	ret |= DIO_port_toggle_logic(PORTA_INDEX);
#endif
/**********************************END OFUINT TESTING ***************************************************/
	
    while (1) 
    {
#if RUN_MAIN_PROGRAM==ENABLE_FEATURE
		ret = APP_start_program();
#endif
    }
}
