/*
 * usart.h
 *
 * Created: 5/1/2023 6:54:34 AM
 *  Author: Mohamed Abdel-Wahab
 *	EMAIL : mohamedhegay22@gmail.com
 */ 


#ifndef USART_H_
#define USART_H_

/* ------------------------------------------------------- Includes ---------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "bit_math.h"
#include "usart_private_regs.h"
#include "usart_config.h"

/* ------------------------------------------------------Data Type Declarations ----------------------------------------------------------*/
#if 0

typedef uint8_t u8_usartMode_t;

typedef uint8_t u8_usartTx_enable_t;
typedef uint8_t u8_usartRx_enable_t;

typedef uint8_t u8_usartTx_interruptMask_t;
typedef uint8_t u8_usartRx_interruptMask_t;

typedef uint8_t u8_usartStopBit_t;
typedef uint8_t u8_usartParityBit_t;
typedef uint8_t u8_usartDataSize_t;

typedef uint8_t u8_usartTxClkPolarity_t;
typedef uint8_t u8_usartRxClkPolarity_t;






typedef struct{
	u8_usartMode_t usartMode;	/*@ref u8_usartMode_t*/
	u8_usartTx_enable_t usartTxEnable;	/*@ref u8_usartTx_enable_t*/
	u8_usartTx_interruptMask_t usartTxInterrupt;	/*@ref u8_usartTx_interruptMask_t*/
	u8_usartRx_enable_t usartRxEnable;	/*@ref u8_usartRx_enable_t*/
	u8_usartRx_interruptMask_t usartRxInterrupt;	/*@ref u8_usartRx_interruptMask_t*/
	u8_usartStopBit_t usartStopBitNum;	/*@ref u8_usartStopBit_t*/
	u8_usartParityBit_t usartParityBit;	/*@ref u8_usartParityBit_t*/
	u8_usartDataSize_t usartDataSize;	/*@ref u8_usartDataSize_t*/
	u8_usartTxClkPolarity_t usartTxClkPolarity;		/*@ref u8_usartTxClkPolarity_t*/
	u8_usartRxClkPolarity_t usartRxClkPolarity;		/*@ref u8_usartRxClkPolarity_t*/
	uint32_t usartBaudRate; /*define the Buadrate value*/ 
}st_usart_config_t;	
#endif

typedef uint8_t u8_usartErorrState_t;


/* ------------------------------------------------------ Macro Declarations ------------------------------------------------------------*/

/* USART Working Mode */
#define USART_ASYNCHRONOUS_NORMAL_SPEED_MODE		 (0x00)
#define USART_ASYNCHRONOUS_DOUBLE_SPEED_MODE		 (0x01)
#define USART_SYNCHRONOUS_MODE						 (0x02)
#define USART_INVALID_MODE							 (0x03)
/* USART Transmit Enable */
#define USART_TX_DISABLE		 (0x00)
#define USART_TX_ENABLE			 (0x01)
/* USART Receiver Enable */
#define USART_RX_DISABLE		 (0x00)
#define USART_RX_ENABLE			 (0x01)
/* USART Transmit Interrupt Enable Feature */
#define USART_TX_INTERRUPT_DISABLE			 (0x00)
#define USART_TX_INTERRUPT_ENABLE			 (0x01)
/* EUSART Receiver Interrupt Enable Feature*/
#define USART_RX_INTERRUPT_DISABLE			 (0x00)
#define USART_RX_INTERRUPT_ENABLE			 (0x01)
/*Select Number of stop-bit either one or two */
#define USART_ONE_STOP_BIT			 (0x00)
#define USART_TWO_STOP_BITS			 (0x01)
#define USART_INVALID_STOP_BITS		 (0x02)
/*Select Parity mode or disabled parity*/
#define USART_DISABLED_PARITY_BIT	 (0x00)
#define USART_EVEN_PARITY_BIT		 (0x01)
#define USART_ODD_PARITY_BIT		 (0x02)
#define USART_INVALID_PARITY_BIT	 (0x03)
/*Select the data-bit number*/
#define USART_FIVE_BIT_DATA			 (0x00)
#define USART_SIX_BIT_DATA			 (0x01)
#define USART_SEVEN_BIT_DATA		 (0x02)
#define USART_EIGHT_BIT_DATA		 (0x03)
#define USART_NINE_BIT_DATA			 (0x04)
#define USART_INVALID_BIT_DATA		 (0x05)
/*SELCET THE CLOCK POLARITY IN CASE OF SYNCHRONOUS MODE ONLY */
#define USART_SYNCHRONOUS_TX_RISING_XCK_EDGE		 (0x00)
#define USART_SYNCHRONOUS_TX_FALLING_XCK_EDGE		 (0x01)

#define USART_SYNCHRONOUS_RX_RISING_XCK_EDGE		 (0x00)
#define USART_SYNCHRONOUS_RX_FALLING_XCK_EDGE		 (0x01)

/*The Error state of The USART*/	
#define USART_E_OK		 (0x00)
#define USART_E_NOK      (0x01)


/*AN INDICATION TO TERMINATE RECIEVING BYTES AND STORE IT IN THE CHARCTER ARRAY (ASCII OF ENTER)*/
#define END_OF_STRING_SYMPOL ((uint8_t)0x0D)
/* ------------------------------------------------------ Macro Like Functions Declarations ---------------------------------------------*/

#define  GET_UBRR_VALUE_FOR_NORMAL_SPEED(BAUDRATE)   (( F_CPU / ((BAUDRATE) * 16.0))  - 1)
#define  GET_UBRR_VALUE_FOR_DOUBLE_SPEED(BAUDRATE)   (( F_CPU / ((BAUDRATE) * 8.0))   - 1)





/* ------------------------------------------------- Software Interfaces Declarations ---------------------------------------------------*/

/*
* Description : initialize the USART driver
* @param defined Buadrate value
* @return Std_ReturnType: status of the function
* USART_E_OK :the function done successfully
* USART_E_NOK :the function has issues performing the function
*/
u8_usartErorrState_t USART_init(const uint32_t u32_a_usartBaudRate);
/*
* Description : Send one byte via USART bus 
* @param u8_a_data : The data to be send
* @return Std_ReturnType: status of the function
* USART_E_OK :the function done successfully
* USART_E_NOK :the function has issues performing the function
*/
u8_usartErorrState_t USART_sendData( uint8_t u8_a_data);
/*
* Description : Receive one byte via USART bus
* @param u8Ptr_a_data: A Reference of the container of the received data
* @return Std_ReturnType: status of the function
* USART_E_OK :the function done successfully
* USART_E_NOK :the function has issues performing the function
*/
u8_usartErorrState_t USART_reciveData( uint8_t *const u8Ptr_a_data);
/*
* Description : Send string via USART bus
* @param The data string -array of characters- to be send
* @return Std_ReturnType: status of the function
* USART_E_OK :the function done successfully
* USART_E_NOK :the function has issues performing the function
*/
u8_usartErorrState_t USART_sendString( uint8_t *u8Arr_a_stringOfData);
/*
* Description : Receive string via USART bus
* @param The data string -array of characters- to store the received data string
* @return Std_ReturnType: status of the function
* USART_E_OK :the function done successfully
* USART_E_NOK :the function has issues performing the function
*/
u8_usartErorrState_t USART_reciveString(uint8_t *const u8Arr_a_stringOfData);




#endif /* USART_H_ */