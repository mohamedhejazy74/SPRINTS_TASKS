/*
 * LED sequence V3.0.c
 *
 * Created: 4/10/2023 3:29:30 PM
 * Author :  Mohamed Abdel-Wahab
 */ 

//#include <avr/io.h>
#include "APP/app.h"




int main(void)
{
	Std_ReturnType l_ret = E_OK;

#if  RUN_MAIN_PROGRAM==ENABLE_FEATURE
	l_ret =  APP_init();
#endif

    while (1) 
    {
#if  RUN_MAIN_PROGRAM==ENABLE_FEATURE	
		l_ret = APP_start_program();
#endif
    }
}

