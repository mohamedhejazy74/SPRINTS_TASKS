/*
 * app.h
 *
 * Created: 4/5/2023 8:31:05 PM
 *  Author: Mohamed Abdel-Wahab
 */ 


#ifndef APP_H_
#define APP_H_


/**********************************  section 1: Includes ********************************************************/
#include "../ECUAL/button/button.h"
#include "../ECUAL/button/button_config.h"
#include "../ECUAL/led/led.h"
#include "../ECUAL/led/led_config.h"
#include "../MCAL/external_interrupt/external_interrupt.h"
#include "../MCAL/external_interrupt/ext_int_config.h"
#include "../ECUAL/delay/delay.h"
#include "../ECUAL/timer_manger/timer_manger.h"
#include "../ECUAL/timer_manger/timer_manger_config.h"


/**********************************  section 2: Macro Declarations ***********************************************/
//#define  DEBOUNCE_DELAY  500U

#define  ON_OFF_INDEX_EQUAL_ON  0U
#define  ON_OFF_INDEX_EQUAL_OFF 1U
#define  MAX_NUM_OF_BLINK_MODES 5U
#define  NUM_OF_ON_OFF_IN_BLINK 2U

/*DELAY DURATION FOR EACH BLINK MODE*/
#define BLINK_MODE_ONE_ON	   (uint8_t)1
#define BLINK_MODE_ONE_OFF	   (uint8_t)9

#define BLINK_MODE_TWO_ON	   (uint8_t)2
#define BLINK_MODE_TWO_OFF	   (uint8_t)8

#define BLINK_MODE_THREE_ON	   (uint8_t)3
#define BLINK_MODE_THREE_OFF   (uint8_t)7

#define BLINK_MODE_FOUR_ON	   (uint8_t)5
#define BLINK_MODE_FOUR_OFF	   (uint8_t)5

#define BLINK_MODE_FIVE_ON	   (uint8_t)8
#define BLINK_MODE_FIVE_OFF	   (uint8_t)2

#define BLINK_ON_OFF_MAX_DURATION	 (uint8_t)10

#define CONFIG_COMPARE_VALUE	 (uint8_t)97


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
extern button_t s_btn1;
extern Interrupt_Config_t s_INT0;
extern Interrupt_Config_t s_INT1;

typedef enum{
	IDLE_STATE = 0,FIRST_STATE,SECOND_STATE,THIRD_STATE,FOURTH_STATE,FIFTH_STATE,SIXTH_STATE,SEVENTH_STATE,EIGHTH_STATE,MAX_STATE_NUM
}LED_SEQ_STATES_t;

typedef enum{
	BLINK_ONE = 0,BLINK_TWO,BLINK_THREE,BLINK_FOUR,BLINK_FIVE,
}BLINK_MODES_t;

/**********************************  section 5: Function Declarations ********************************************/
extern Std_ReturnType APP_init(void);

extern Std_ReturnType APP_start_program(void);



#endif /* APP_H_ */