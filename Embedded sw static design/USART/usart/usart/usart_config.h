/*
 * usart_config.h
 *
 * Created: 5/1/2023 5:19:37 PM
 *  Author: Mohamed Abdel-Wahab
 *	EMAIL : mohamedhegay22@gmail.com
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#include "usart.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


/*@ref u8_usartMode_t*/
#ifndef USART_MODE_TYPE
#define USART_MODE_TYPE			USART_ASYNCHRONOUS_NORMAL_SPEED_MODE
#endif

/*@ref u8_usartTx_enable_t*/
#ifndef USART_TX
#define USART_TX				USART_TX_ENABLE
#endif

/*@ref u8_usartRx_enable_t*/
#ifndef USART_RX
#define USART_RX				USART_RX_ENABLE
#endif

/*@ref u8_usartTx_interruptMask_t*/
#ifndef	USART_TX_INTERRUPT
#define USART_TX_INTERRUPT		USART_TX_INTERRUPT_DISABLE
#endif

/*@ref u8_usartRx_interruptMask_t*/
#ifndef USART_RX_INTERRUPT
#define USART_RX_INTERRUPT		USART_RX_INTERRUPT_DISABLE
#endif


/*@ref u8_usartStopBit_t*/
#ifndef USART_STOP_BITS_NUM
#define USART_STOP_BITS_NUM		USART_ONE_STOP_BIT
#endif

/*@ref u8_usartParityBit_t*/
#ifndef USART_PARITY_TYPE
#define USART_PARITY_TYPE		USART_DISABLED_PARITY_BIT
#endif

/*@ref u8_usartDataSize_t*/
#ifndef USART_DATA_SIZE
#define USART_DATA_SIZE		USART_EIGHT_BIT_DATA
#endif

#if  USART_MODE_TYPE==USART_SYNCHRONOUS_MODE

/*@ref u8_usartDataSize_t*/
#ifndef USART_TX_CLK_POLARITY
#define USART_TX_CLK_POLARITY		USART_SYNCHRONOUS_TX_RISING_XCK_EDGE
#endif

/*@ref u8_usartDataSize_t*/
#ifndef USART_RX_CLK_POLARITY
#define USART_RX_CLK_POLARITY		USART_SYNCHRONOUS_RX_RISING_XCK_EDGE
#endif

#endif



#ifndef USART_MIN_BAUDRATE
#define USART_MIN_BAUDRATE		2400U
#endif

#ifndef USART_MAX_BAUDRATE
#define USART_MAX_BAUDRATE		250000U
#endif

#endif /* USART_CONFIG_H_ */