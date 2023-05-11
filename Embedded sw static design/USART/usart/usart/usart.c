/*
 * usart.c
 *
 * Created: 5/1/2023 7:35:51 AM
 *  Author: Mohamed Abdel-Wahab
 *	EMAIL : mohamedhegay22@gmail.com
 */ 
#include "usart.h"


#if USART_TX_INTERRUPT==USART_TX_INTERRUPT_ENABLE
static volatile uint8_t u8_sg_dataTransimted;
#endif

#if USART_RX_INTERRUPT==USART_RX_INTERRUPT_ENABLE
static volatile uint8_t u8_sg_dataRecieved;
#endif


#if USART_TX_INTERRUPT==USART_TX_INTERRUPT_ENABLE
ISR(USART_UDRE_vect)
{
	UDR= u8_sg_dataTransimted;
}
#endif

#if USART_RX_INTERRUPT==USART_RX_INTERRUPT_ENABLE
ISR(USART_RXC_vect)
{

	u8_sg_dataRecieved= UDR;
}
#endif

u8_usartErorrState_t USART_init(const uint32_t u32_a_usartBaudRate)
{
	u8_usartErorrState_t l_ret = USART_E_OK;
	float32_t f32_l_baudRatePrescaler;
	if(u32_a_usartBaudRate < USART_MIN_BAUDRATE || u32_a_usartBaudRate > USART_MAX_BAUDRATE)
	{
		l_ret = USART_E_NOK;
	}
	else
	{
		/*calculate the value on UBRR -high & low- with the defined baudRate */
#if   USART_MODE_TYPE==USART_ASYNCHRONOUS_NORMAL_SPEED_MODE
		f32_l_baudRatePrescaler =  GET_UBRR_VALUE_FOR_NORMAL_SPEED(u32_a_usartBaudRate);
		UBRRH = (uint8_t)(((uint32_t)f32_l_baudRatePrescaler) >> SFIFT_EIGHT_BIT);
		UBRRL = (uint8_t)((uint32_t)f32_l_baudRatePrescaler);
#elif USART_MODE_TYPE==USART_ASYNCHRONOUS_DOUBLE_SPEED_MODE
		f32_l_baudRatePrescaler =  GET_UBRR_VALUE_FOR_DOUBLE_SPEED(u32_a_usartBaudRate);
		UBRRH = (uint8_t)(((uint32_t)f32_l_baudRatePrescaler) >> SFIFT_EIGHT_BIT);
		UBRRL = (uint8_t)((uint32_t)f32_l_baudRatePrescaler);
#else
		l_ret = USART_E_NOK;
#endif


		/*The URSEL-BIT must be one when writing on UCSRC register*/
		SET_BIT(UCSRC,URSEL);
		
		/*set USART mode*/
#if   USART_MODE_TYPE==USART_ASYNCHRONOUS_NORMAL_SPEED_MODE
		//CLEAR UMSEL BIT TO SELECT ASYNCHRONOUS MODE
		CLEAR_BIT(UCSRC,UMSEL);
#elif USART_MODE_TYPE==USART_ASYNCHRONOUS_DOUBLE_SPEED_MODE
		//CLEAR UMSEL BIT TO SELECT ASYNCHRONOUS MODE
		CLEAR_BIT(UCSRC,UMSEL);
		//SET THE U2X TO DOUBLE THE USART TRANSMISSION SPEED
		SET_BIT(UCSRA,U2X);
#elif USART_MODE_TYPE==USART_SYNCHRONOUS_MODE
		//SET UMSEL BIT TO SELECT SYNCHRONOUS MODE
		SET_BIT(UCSRC,UMSEL);
#if   (USART_TX_CLK_POLARITY==USART_SYNCHRONOUS_TX_RISING_XCK_EDGE) || ( USART_RX_CLK_POLARITY==USART_SYNCHRONOUS_RX_FALLING_XCK_EDGE)
		CLEAR_BIT(UCSRC,UCPOL);
#elif (USART_TX_CLK_POLARITY==USART_SYNCHRONOUS_TX_FALLING_XCK_EDGE) || ( USART_RX_CLK_POLARITY==USART_SYNCHRONOUS_RX_RISING_XCK_EDGE)
		SET_BIT(UCSRC,UCPOL);
#else
		l_ret = USART_E_NOK;
#endif

#else
		l_ret = USART_E_NOK;
#endif

		/*enable transmitter if set*/
#if USART_TX==USART_TX_ENABLE
		SET_BIT(UCSRB,TXEN);
#else
		//do nothing
#endif
		/*enable receiver if set*/
#if USART_TX==USART_TX_ENABLE
		SET_BIT(UCSRB,RXEN);
#else
		//do nothing
#endif
			
		/*enable transmitter interrupt if set*/
#if USART_TX_INTERRUPT==USART_TX_INTERRUPT_ENABLE
		//TX Complete Interrupt Enable
		SET_BIT(UCSRB,TXCIE);
		//USART Data Register Empty Interrupt Enable
		SET_BIT(UCSRB,UDRIE);
#else
		//do nothing
#endif
		/*enable receiver if interrupt set*/
#if USART_RX_INTERRUPT==USART_RX_INTERRUPT_ENABLE
		//RX Complete Interrupt Enable
		SET_BIT(UCSRB,RXCIE);
#else
		//do nothing
#endif		
		
				
		/*adjust frame format*/
			
		//Select Number of stop-bit either one or two
#if   USART_STOP_BITS_NUM==USART_ONE_STOP_BIT
		CLEAR_BIT(UCSRC,USBS);
#elif USART_STOP_BITS_NUM==USART_TWO_STOP_BITS
		SET_BIT(UCSRC,USBS);
#else
		l_ret = USART_E_NOK;
#endif
		
		//Select Parity mode or disabled parity
#if	  USART_PARITY_TYPE==USART_DISABLED_PARITY_BIT
		CLEAR_BIT(UCSRC,UPM0);
		CLEAR_BIT(UCSRC,UPM1);
#elif USART_PARITY_TYPE==USART_EVEN_PARITY_BIT
		CLEAR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1)
#elif USART_PARITY_TYPE==USART_ODD_PARITY_BIT
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
#else
		l_ret = USART_E_NOK;
#endif
		
		//Select the data-bit number
#if	  USART_DATA_SIZE==USART_FIVE_BIT_DATA
		CLEAR_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
#elif USART_DATA_SIZE==USART_SIX_BIT_DATA
		SET_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
#elif USART_DATA_SIZE==USART_SEVEN_BIT_DATA
		CLEAR_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
#elif USART_DATA_SIZE==USART_EIGHT_BIT_DATA
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
#elif USART_DATA_SIZE==USART_NINE_BIT_DATA
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
#else
		l_ret = USART_E_NOK;
#endif
			
	}
	return l_ret;
}

u8_usartErorrState_t USART_sendData( uint8_t u8_a_data)
{
		u8_usartErorrState_t l_ret = USART_E_OK;
	
#if  USART_TX_INTERRUPT==USART_TX_INTERRUPT_DISABLE
		/*if not using interrupt then will use blocking technique*/
		
		// UDRE flag is set when the Tx buffer (UDR) is empty and ready for transmitting a new byte so wait until this flag is set to one
		while(!READ_BIT(UCSRA,UDRE));
		UDR = u8_a_data;
		
#elif USART_TX_INTERRUPT==USART_TX_INTERRUPT_ENABLE
		/*when Tx buffer (UDR) is empty and ready for transmitting a new byte so wait until this flag is set to one and will generate an interrupt*/
		u8_sg_dataTransimted = u8_a_data ;
#else
		l_ret = USART_E_NOK;
#endif
		
	return l_ret;
}


u8_usartErorrState_t USART_reciveData( uint8_t *const u8Ptr_a_data)
{
	u8_usartErorrState_t l_ret = USART_E_OK;
#if  USART_RX_INTERRUPT==USART_RX_INTERRUPT_DISABLE
		/*if not using interrupt then will use blocking technique*/
		//RXC flag is set when the UART receive data so wait until this flag is set to one
		while(!READ_BIT(UCSRA,RXC));
		*u8Ptr_a_data = UDR;
		
#elif USART_RX_INTERRUPT==USART_RX_INTERRUPT_ENABLE
		/*RXC flag is set when the UART receive data so wait until this flag is set to one and will generate an interrupt*/
		*u8Ptr_a_data = u8_sg_dataRecieved;
#else
		l_ret = USART_E_NOK;
#endif	
	
	return l_ret;	
}

u8_usartErorrState_t USART_sendString( uint8_t *u8Arr_a_stringOfData)
{
	u8_usartErorrState_t l_ret = USART_E_OK;
	uint8_t u8_l_index=U8_ZERO_INITIALIZE;
	
	if(NULL==u8Arr_a_stringOfData)
	{
		l_ret = USART_E_NOK;
	}
	else
	{
		while(u8Arr_a_stringOfData[u8_l_index] != '\0')
		{
			l_ret = USART_sendData(u8Arr_a_stringOfData[u8_l_index]);
			u8_l_index++;
		}
	}
	return l_ret;
}

u8_usartErorrState_t USART_reciveString(uint8_t *const u8Arr_a_stringOfData)
{
		u8_usartErorrState_t l_ret = USART_E_OK;
		uint8_t u8_l_index=U8_ZERO_INITIALIZE;
		uint8_t u8_l_breakloopFalg=U8_ZERO_INITIALIZE;
		
		if(NULL==u8Arr_a_stringOfData )
		{
			l_ret = USART_E_NOK;
		}
		else
		{
			while(!u8_l_breakloopFalg)
			{
				 l_ret = USART_reciveData(&u8Arr_a_stringOfData[u8_l_index]);
				 if(u8Arr_a_stringOfData[u8_l_index] == END_OF_STRING_SYMPOL)
				 {
					 u8_l_breakloopFalg++;
					 u8Arr_a_stringOfData[u8_l_index] = '\0';	 
				 }
				 else
				 {
					 //do nothing
				 }
				 u8_l_index++;
			}
		}
		return l_ret;
}