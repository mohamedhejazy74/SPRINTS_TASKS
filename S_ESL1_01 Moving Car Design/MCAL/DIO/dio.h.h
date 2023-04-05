/* 
 * File:   dio.h
 * Author: Mohamed Abdel-Wahab
 *
 * 
 */

#ifndef HAL_DIO_H
#define	HAL_DIO_H


/**********************************  section 1: Includes ********************************************************/

#include "../mcal_std_types.h"
#include "../mcal_bit_math"
#include "dio_cfg.h"


/**********************************  section 2: Macro Declarations ***********************************************/


/**********************************  section 3: Macro Like Function Declarations *************************** *****/


/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum{
    GPIO_LOW=0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT=0,
    GPIO_DIRECTION_INPUT
}direction_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port : 3;        /* @ref port_index_t*/
    uint8 pin : 3;         /* @ref pin_index_t*/          
    uint8 direction : 1;   /* @ref direction_t*/
    uint8 logic : 1;       /* @ref logic_t*/
}pin_config_t;
/**********************************  section 5: Function Declarations ********************************************/

/**
* @brief Initialize the direction of specific pin @ref direction_t
* @param _pin_config A Reference of the pin configuration @pin_config_t
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
/**
* @brief Write the logic of specific pin @ref logic_t
* @param _pin_config A Reference of the pin configuration @pin_config_t
* @param logic
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_pin_write_logic(const pin_config_t *pin_config_ptr, logic_t a_logic);
/**
* @brief Read the logic of specific pin @ref logic_t
* @param _pin_config A Reference of the pin configuration @pin_config_t
* @param logic
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_pin_read_logic(const pin_config_t * pin_config_ptr, logic_t *const logic_ptr);

/**
* @brief Toggle the logic of specific pin @ref logic_t
* @param _pin_config A Reference of the pin configuration @pin_config_t
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_pin_toggle_logic(const pin_config_t *pin_config_ptr);
/**
* @brief Initialize the direction of specific pin and Initialize its logic
* @param _pin_config A Reference of the pin configuration @pin_config_t
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_pin_intialize(const pin_config_t *pin_config_ptr);
/**
*
* @param port_index
* @param direction
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_port_direction_intialize(const port_index_t a_port_index, uint8 a_direction);
/**
* @param port_index
* @param logic
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_port_write_logic(const port_index_t a_ port_index , uint8 a_logic);
/**
* @param port_index
* @param logic
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_port_read_logic(const port_index_t a_port_index , uint8 *const a_logic_ptr);
/**
* @param port_index
* @return status of the function
* E_OK :the function done successfully
* E_NOT_OK :the function has issues performing the function
*/
Std_ReturnType DIO_port_toggle_logic(const port_index_t a_port_index);

#endif	/* HAL_DIO_H*/

