/*
 * LED_sequence_V3.0_MISRA.c
 *
 * Created: 6/6/2023 7:46:27 PM
 * Author : Mcs
 */ 
 #include "APP/app.h"

int main(void)
{

#if  RUN_MAIN_PROGRAM==ENABLE_FEATURE
	 APP_init();
#endif

	while (1)
	{
#if  RUN_MAIN_PROGRAM==ENABLE_FEATURE
	 APP_start_program();
#endif
	}
}

