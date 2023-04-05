/* 
 * File:   ecu_dc_motor.h
 * Author: Mohamed Abdel-Wahab
 *
 * Created on February 22, 2023, 10:18 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/**********************************  section 1: Includes ********************************************************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_dc_motor_cfg.h"
/**********************************  section 2: Macro Declarations ***********************************************/
#define DC_MOTOR_PIN1 0u
#define DC_MOTOR_PIN2 1u
#define DC_MOTOR_PINS 2u
/**********************************  section 3: Macro Like Function Declarations *************************** *****/

/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum{
    DC_MOTOR_OFF = 0,
    DC_MOTOR_ON
}dc_motor_status_t;


typedef struct{
    pin_config_t    dc_motor_pin[DC_MOTOR_PINS];
    dc_motor_status_t  dc_motor_state;
}dc_motor_t;
/**********************************  section 5: Software Interfaces Declarations ********************************************/

/**
* @brief Initialize the assigned pins to be OUTPUT and turn the motor OFF or ON.
* @param _dc_motor pointer to the motor configurations
* @return Status of the function
* (E_OK) : The function done successfully
* (E_NOT_OK) : The function has issue to perform this action
*/
Std_ReturnType DC_MOTOR_init(const dc_motor_t *dc_motor_ptr);
/**
* @brief Move the motor to the right direction
* @param _dc_motor pointer to the motor configurations
* @return Status of the function
* (E_OK) : The function done successfully
* (E_NOT_OK) : The function has issue to perform this action
*/
Std_ReturnType DC_MOTOR_move_right(const dc_motor_t *dc_motor_ptr);
/**
* @brief Move the motor to the left direction
* @param _dc_motor pointer to the motor configurations
* @return Status of the function
* (E_OK) : The function done successfully
* (E_NOT_OK) : The function has issue to perform this action
*/
Std_ReturnType DC_MOTOR_move_left(const dc_motor_t *dc_motor_ptr);
/**
* @brief stop the motor movement
* @param _dc_motor pointer to the motor configurations
* @return Status of the function
* (E_OK) : The function done successfully
* (E_NOT_OK) : The function has issue to perform this action
*/
Std_ReturnType DC_MOTOR_stop(const dc_motor_t *dc_motor_ptr);





#endif	/* ECU_DC_MOTOR_H */


