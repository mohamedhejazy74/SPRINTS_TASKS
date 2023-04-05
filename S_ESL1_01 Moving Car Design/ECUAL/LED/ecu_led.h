/* 
 * File:   ecu_led.h
 * Author:  Mohamed Abdel-Wahab
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/**********************************  section 1: Includes ********************************************************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/**********************************  section 2: Macro Declarations ***********************************************/

/**********************************  section 3: Macro Like Function Declarations *************************** *****/

/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum{
    LED_OFF=0,
    LED_ON
}led_status_t;


typedef struct{
    pin_config_t led_pin;
    led_status_t led_status;
}led_t;
/**********************************  Software Interfaces Declarations********************************************/


/**
 * @breif  Initialize The led by configuring the pin as output and write low
 * @param Led  The reference of the led module configuration
 * @return status of the function 
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function has issues performing the function 
 */
Std_ReturnType LED_initialize(const led_t *led_ptr);

/**
 * @breif Turn the led on
 * @param led  The reference of the led module configuration
 * @return status of the function 
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function has issues performing the function 
 */

Std_ReturnType LED_turn_on(const led_t *led_ ptr);

/**
 * @breif Turn the led off
 * @param led  The reference of the led module configuration
 * @return status of the function 
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function has issues performing the function 
 */

Std_ReturnType LED_ turn_off (const led_t *led_ ptr);

/**
 * @breif  Toggle the led
 * @param led  The reference of the led module configuration
 * @return status of the function 
 *          E_OK :the function done successfully
 *          E_NOT_OK :the function has issues performing the function 
 */
Std_ReturnType LED_ turn_toggle (const led_t *led_ ptr);




#endif	/* ECU_LED_H */

