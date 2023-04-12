/*
 * ext_int_private_reg.h
 *
 * Created: 4/8/2023 5:12:49 PM
 *  Author: Mohamed Abdel-Wahab
 */ 


#ifndef EXT_INT_PRIVATE_REG_H_
#define EXT_INT_PRIVATE_REG_H_
#include "../../STD_LIBRARIES/STD_TYPES.h"
#include "../../STD_LIBRARIES/bit_math.h"

/****************************************EXT_INTx_REGISTERS *************************************************/

/*MCUCR -The MCU Control Register contains control bits for interrupt sense control*/
#define MCUCR	(*(volatile uint8_t*)(0x55))
/*MCUCSR – MCU Control and Status Register*/
#define MCUCSR	(*(volatile uint8_t*)(0x54))
/*GICR – General Interrupt Control Register*/
#define GICR	(*(volatile uint8_t*)(0x5B))
/*GIFR – General Interrupt Flag Register*/
#define GIFR	(*(volatile uint8_t*)(0x5A))
/*SREG - has  the global interrupt enable bit I-bit  */
#define SREG 	(*(volatile uint8_t*)(0x5F)) 


/* ISC10 , ISC11 -Interrupt Sense Control INT0 Bit 1 and Bit 0 in MCUCR*/
#define  ISC00	(0u)
#define  ISC01	(1u)
/* ISC10 , ISC11 -Interrupt Sense Control INT1 Bit 3 and Bit 2 in MCUCR*/
#define  ISC10	(2u)
#define  ISC11	(3u)
/* ISC2 -Interrupt Sense Control INT2(on change only) Bit 6 in MCUCSR*/
#define  ISC2	(6u)

/*INT1- External Interrupt Request 1 Enable bit 6 in GICR*/
#define  INT1   (7u)
/*INT1- External Interrupt Request 0 Enable bit 6 in GICR*/
#define  INT0   (6u)
/*INT1- External Interrupt Request 2 Enable bit 6 in GICR*/
#define  INT2   (5u)

/*INTF1- External Interrupt Flag 1 bit 7 in GIFR*/
#define  INTF1   (7u)
/*INTF1- External Interrupt Flag 0 bit 6 in GIFR*/
#define  INTF0   (6u)
/*INTF1- External Interrupt Flag 2 bit 5 in GIFR*/
#define  INTF2   (5u)

/*I-BIT Global Interrupt Enable IN SREG*/
#define  I		(7u)

#endif /* EXT_INT_PRIVATE_REG_H_ */