/*
 * app.h
 *
 * Created: 4/5/2023 8:31:05 PM
 *  Author: Mohamed Abdel-Wahab
 */ 


#ifndef APP_H_
#define APP_H_


/**********************************  section 1: Includes ********************************************************/
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"


/**********************************  section 2: Macro Declarations ***********************************************/
#define  DEBOUNCE_DELAY  500U

#define  ENABLE_FEATURE  1U
#define  DISABLE_FEATURE 0U
#define  UINT_TEST				 DISABLE_FEATURE
#define  RUN_MAIN_PROGRAM		 ENABLE_FEATURE
/**********************************  section 3: Macro Like Function Declarations *************************** *****/


/**********************************  section 4: Data Type Declarations  ******************************************/
extern led_t s_led0;
extern led_t s_led1;
extern led_t s_led2;
extern led_t s_led3;
extern pin_config_t pin;
extern button_t s_btn0;

typedef enum{
	IDLE_STATE = 0,FIRST_STATE,SECOND_STATE,THIRD_STATE,FOURTH_STATE,FIFTH_STATE,SIXTH_STATE,SEVENTH_STATE,EIGHTH_STATE,MAX_STATE_NUM
	}LED_SEQ_STATES_t;

/**********************************  section 5: Function Declarations ********************************************/
Std_ReturnType APP_init(void);
Std_ReturnType APP_start_program(void);



#endif /* APP_H_ */