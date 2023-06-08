/*
 * external_interrupt.c
 *
 * Created: 4/8/2023 5:12:22 PM
 *  Author: Mohamed Abdel-Wahab
 */ 
#include "external_interrupt.h"

static  void(*g_EXT_INT0_fptr)(void) = NULL;
static  void(*g_EXT_INT1_fptr)(void) = NULL;
static  void(*g_EXT_INT2_fptr)(void) = NULL;

ISR(INT0_vect)
{
	/* The INT0 external interrupt occurred (must be cleared in software) */
	EXT_INT0_InterruptFlagClear();
	
	if(g_EXT_INT0_fptr)
	{
		/* Application Callback function gets called every time this ISR executes */
		(*g_EXT_INT0_fptr)();
	}
	else{/*do nothing*/}
}

ISR(INT1_vect)
{
	/* The INT1 external interrupt occurred (must be cleared in software) */
	EXT_INT1_InterruptFlagClear();
	if(g_EXT_INT1_fptr)
	{
		/* Application Callback function gets called every time this ISR executes */
		(*g_EXT_INT1_fptr)();
	}
	else{/*do nothing*/}
}

ISR(INT2_vect)
{
	/* The INT1 external interrupt occurred (must be cleared in software) */
	EXT_INT1_InterruptFlagClear();
	if(g_EXT_INT2_fptr)
	{
		/* Application Callback function gets called every time this ISR executes */
		(*g_EXT_INT2_fptr)();
	}
	else{/*do nothing*/}
}

Std_ReturnType EXT_INTx_setCallBack( void(*a_fptr)(void), const Interrupt_ID_t a_interrupt_number )
{
	Std_ReturnType ret = E_OK;
	if((NULL == a_fptr) ||( a_interrupt_number > NUM_OF_EXT_INTx - 1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(a_interrupt_number)
		{
			case INTERRUPT_EXTERNAL_INT0:
				g_EXT_INT0_fptr = a_fptr;
				break;
			case INTERRUPT_EXTERNAL_INT1:
				g_EXT_INT1_fptr = a_fptr;
				break;
			case INTERRUPT_EXTERNAL_INT2:
				g_EXT_INT2_fptr = a_fptr;
				break;
			default:
				ret = E_NOT_OK;
				break;		
		}	
	}
	return ret;
}

Std_ReturnType EXT_INTx_setEdgeType(Interrupt_Edge_type_t a_edgeType ,  Interrupt_ID_t a_interrupt_Id)
{
	Std_ReturnType ret = E_OK;
	if((a_interrupt_Id > NUM_OF_EXT_INTx - 1) || (a_edgeType > NOT_VALID_EDGE))
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(a_interrupt_Id)
		{
			case INTERRUPT_EXTERNAL_INT0:
				switch(a_edgeType)
				{
					case INTERRUPT_LOW_LEVEL:
						CLEAR_BIT(MCUCR,ISC00);
						CLEAR_BIT(MCUCR,ISC01);
						break;
					case INTERRUPT_ANY_LOGICAL_CHANGE:
						SET_BIT(MCUCR,ISC00);
						CLEAR_BIT(MCUCR,ISC01);
						break;
					case INTERRUPT_FALLING_EDGE:
						CLEAR_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
						break;
					case INTERRUPT_RISING_EDGE:
						SET_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
						break;
					default:
						ret = E_NOT_OK;
						break;
				}
				break;
			
			case INTERRUPT_EXTERNAL_INT1:
			
				switch(a_edgeType)
				{
					case INTERRUPT_LOW_LEVEL:
						CLEAR_BIT(MCUCR,ISC10);
						CLEAR_BIT(MCUCR,ISC11);
						break;
					case INTERRUPT_ANY_LOGICAL_CHANGE:
						SET_BIT(MCUCR,ISC10);
						CLEAR_BIT(MCUCR,ISC11);
						break;
					case INTERRUPT_FALLING_EDGE:
						CLEAR_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
						break;
					case INTERRUPT_RISING_EDGE:
						SET_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
						break;
					default:
						ret = E_NOT_OK;
						break;
				}
				break;
			
			case INTERRUPT_EXTERNAL_INT2:
			
				switch(a_edgeType)
				{
					case INTERRUPT_FALLING_EDGE:
						CLEAR_BIT(MCUCSR,ISC2);
						break;
					case INTERRUPT_RISING_EDGE:
						SET_BIT(MCUCSR,ISC2);
						break;
					default:
						ret = E_NOT_OK;
						break;
				}
				break;
			
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	return ret;
}

Std_ReturnType EXT_INTx_Init(const Interrupt_Config_t *Interrupt_Config_Ptr )
{
	Std_ReturnType ret = E_OK;
	if((NULL == Interrupt_Config_Ptr) || (Interrupt_Config_Ptr->source_id > NUM_OF_EXT_INTx - 1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(Interrupt_Config_Ptr->source_id)
		{
			case INTERRUPT_EXTERNAL_INT0:
			
				/* Disable the External interrupt */
				EXT_INT0_InterruptDisable();
				/* Clear Interrupt Flag : External interrupt did not occur */
				EXT_INT0_InterruptFlagClear();
				/* Configure External interrupt edge */
				ret = EXT_INTx_setEdgeType(Interrupt_Config_Ptr->edge,INTERRUPT_EXTERNAL_INT0);
				/* Configure External interrupt I/O pin */
				pin_config_t INT0_PIN={.pin=PIN2,.port=PORTD_INDEX};
				ret |= DIO_pin_direction_intialize(&INT0_PIN,DIO_DIRECTION_INPUT);
				/* Enable the External interrupt */
				EXT_INT0_InterruptEnable();
				break;
				
			case INTERRUPT_EXTERNAL_INT1:
			
				/* Disable the External interrupt */
				EXT_INT1_InterruptDisable();
				/* Clear Interrupt Flag : External interrupt did not occur */
				EXT_INT1_InterruptFlagClear();
				/* Configure External interrupt edge */
				ret = EXT_INTx_setEdgeType(Interrupt_Config_Ptr->edge,INTERRUPT_EXTERNAL_INT1);
				/* Configure External interrupt I/O pin */
				pin_config_t INT1_PIN={.pin=PIN3,.port=PORTD_INDEX};
				ret |= DIO_pin_direction_intialize(&INT1_PIN,DIO_DIRECTION_INPUT);
				/* Enable the External interrupt */
				EXT_INT1_InterruptEnable();
				break;
				
				
			case INTERRUPT_EXTERNAL_INT2:
			
				/* Disable the External interrupt */
				EXT_INT2_InterruptDisable();
				/* Clear Interrupt Flag : External interrupt did not occur */
				EXT_INT2_InterruptFlagClear();
				/* Configure External interrupt edge */
				ret = EXT_INTx_setEdgeType(Interrupt_Config_Ptr->edge,INTERRUPT_EXTERNAL_INT2);
				/* Configure External interrupt I/O pin */
				pin_config_t INT2_PIN={.pin=PIN2,.port=PORTB};
				ret |= DIO_pin_direction_intialize(&INT2_PIN,DIO_DIRECTION_INPUT);
				/* Enable the External interrupt */
				EXT_INT1_InterruptEnable();
				break;
				
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	return ret;
}

Std_ReturnType EXT_INTx_DeInit(const Interrupt_ID_t a_interrupt_Id)
{
	Std_ReturnType ret = E_OK;
	if(a_interrupt_Id > NUM_OF_EXT_INTx - 1)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(a_interrupt_Id)
		{
			case INTERRUPT_EXTERNAL_INT0 :
				EXT_INT0_InterruptDisable(); /* Disable the INT0 external interrupt */
				ret = E_OK;
				break;
			case INTERRUPT_EXTERNAL_INT1 :
				EXT_INT1_InterruptDisable(); /* Disable the INT1 external interrupt */
				ret = E_OK;
				break;
			case INTERRUPT_EXTERNAL_INT2 :
				EXT_INT2_InterruptDisable(); /* Disable the INT2 external interrupt */
				ret = E_OK;
				break;
			default : ret = E_NOT_OK;
		}
	}
	return ret;
}


