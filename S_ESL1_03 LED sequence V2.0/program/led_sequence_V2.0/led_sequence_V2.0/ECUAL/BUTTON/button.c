/*
 * button.c
 *
 * Created: 4/5/2023 8:28:22 PM
 *  Author: Mohamed Abdel-Wahab
 */ 
#include "button.h"

Std_ReturnType BTN_init(const button_t *btn_ptr)
{
	Std_ReturnType ret = E_OK;
	if(NULL == btn_ptr || (btn_ptr->button_pin.pin > PORT_PIN_MAX_NUMBER-1) || (btn_ptr->button_pin.port > PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = DIO_pin_direction_intialize(&(btn_ptr->button_pin),DIO_DIRECTION_INPUT);
		ret = DIO_pin_write_logic(&(btn_ptr->button_pin),DIO_LOGIC_LOW);
	}
	return ret;
}

Std_ReturnType BTN_read_state(const button_t *btn_ptr, button_status_t *btn_states_ptr)
{
	Std_ReturnType ret = E_OK;
	logic_t l_Pin_Logic_Status = DIO_LOGIC_LOW;
	
	if(NULL == btn_ptr || (btn_ptr->button_pin.pin > PORT_PIN_MAX_NUMBER-1) || (btn_ptr->button_pin.port > PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = DIO_pin_read_logic( &(btn_ptr->button_pin) , &l_Pin_Logic_Status);
		
		if(BUTTON_ACTIVE_HIGH == btn_ptr->button_connection)
		{
			switch(l_Pin_Logic_Status)
			{
				case DIO_LOGIC_HIGH:
					*btn_states_ptr = BUTTON_PRESSED;
					break;
				case DIO_LOGIC_LOW:
					*btn_states_ptr = BUTTON_RELEASED;
					break;
				default:
					ret = E_NOT_OK;
					break;
			}
		}
		else if(BUTTON_ACTIVE_LOW == btn_ptr->button_connection)
		{
			switch(l_Pin_Logic_Status)
			{
				case DIO_LOGIC_HIGH:
				*btn_states_ptr = BUTTON_RELEASED;
				break;
				case DIO_LOGIC_LOW:
				*btn_states_ptr = BUTTON_PRESSED;
				break;
				default:
				ret = E_NOT_OK;
				break;
			}
		}
		else 
		{
			 ret = E_NOT_OK;
	    }
	}
	return ret;
}