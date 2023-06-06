/*
 * Led_sequance_v1.0_MISRA.c
 *
 * Created: 6/6/2023 3:31:27 PM
 * Author : Mcs
 */ 

/*#include <avr/io.h>*/
#include "APP/app.h"

int main(void)
{
	Std_ReturnType enu_l_ret = E_OK;
	enu_l_ret = APP_init();
    /* Replace with your application code */
    while (TRUE) 
    {
		enu_l_ret = APP_start_program();
    }
}

