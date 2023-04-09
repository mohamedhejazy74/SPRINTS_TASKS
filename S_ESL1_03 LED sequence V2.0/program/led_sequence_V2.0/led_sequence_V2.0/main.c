/*
 * led_sequence_V2.0.c
 *
 * Created: 4/8/2023 5:04:59 PM
 * Author : Mohamed Abdel-Wahab
 */ 

//#include <avr/io.h>
#include "APP/app.h"

Std_ReturnType ret = E_OK;

#if UINT_TEST==ENABLE_FEATURE
Interrupt_Config_t INT0_TEST = {
	.source_id = INTERRUPT_EXTERNAL_INT0,
	.edge = INTERRUPT_RISING_EDGE
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
	/**********************************UINT TESTING FOR EXTERNAL INTERRUPT DRIVER***********************************/
	/*test initialize INT0 with rising edge*/
	ret = EXT_INTx_Init(&INT0_TEST);
	/*test set the edge INT0 with falling edge*/
	ret |= EXT_INTx_setEdgeType(INTERRUPT_FALLING_EDGE,INTERRUPT_EXTERNAL_INT0);
	/*test set the edge INT0 with low level*/
	ret |= EXT_INTx_setEdgeType(INTERRUPT_LOW_LEVEL,INTERRUPT_EXTERNAL_INT0);
	/*test set the edge INT0 with any change*/
	ret |= EXT_INTx_setEdgeType(INTERRUPT_ANY_LOGICAL_CHANGE,INTERRUPT_EXTERNAL_INT0);
	/*test de_initialize INT0*/
	ret = EXT_INTx_DeInit(INTERRUPT_EXTERNAL_INT0);
	/**********************************END OFUINT TESTING ***************************************************/
	#endif
	
	while (1)
	{
		#if RUN_MAIN_PROGRAM==ENABLE_FEATURE
		ret = APP_start_program();
		#endif
	}
}

