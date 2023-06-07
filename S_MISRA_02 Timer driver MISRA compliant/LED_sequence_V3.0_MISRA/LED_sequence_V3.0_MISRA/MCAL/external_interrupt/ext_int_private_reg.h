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


#ifndef MCUCR
/*MCUCR -The MCU Control Register contains control bits for interrupt sense control*/
#define MCUCR	(*(volatile uint8_t*)(0x55))
#endif

#ifndef MCUCSR
/*MCUCSR – MCU Control and Status Register*/
#define MCUCSR	(*(volatile uint8_t*)(0x54))
#endif


#ifndef GICR
/*GICR – General Interrupt Control Register*/
#define GICR	(*(volatile uint8_t*)(0x5B))
#endif

#ifndef GIFR
/*GIFR – General Interrupt Flag Register*/
#define GIFR	(*(volatile uint8_t*)(0x5A))
#endif


#ifndef SREG
/*SREG - has  the global interrupt enable bit I-bit  */
#define SREG 	(*(volatile uint8_t*)(0x5F)) 
#endif


/* ISC10 , ISC11 -Interrupt Sense Control INT0 Bit 1 and Bit 0 in MCUCR*/
#ifndef  ISC00
#define  ISC00	(0u)
#endif
#ifndef	 ISC01
#define  ISC01	(1u)
#endif
/* ISC10 , ISC11 -Interrupt Sense Control INT1 Bit 3 and Bit 2 in MCUCR*/
#ifndef	 ISC10	
#define  ISC10	(2u)
#endif
#ifndef  ISC10
#define  ISC11	(3u)
#endif
/* ISC2 -Interrupt Sense Control INT2(on change only) Bit 6 in MCUCSR*/
#ifndef  ISC2
#define  ISC2	(6u)
#endif

/*INT1- External Interrupt Request 1 Enable bit 6 in GICR*/
#ifndef  INT1
#define  INT1   (7u)
#endif
/*INT1- External Interrupt Request 0 Enable bit 6 in GICR*/
#ifndef  INT0
#define  INT0   (6u)
#endif
/*INT1- External Interrupt Request 2 Enable bit 6 in GICR*/
#ifndef  INT2
#define  INT2   (5u)
#endif

/*INTF1- External Interrupt Flag 1 bit 7 in GIFR*/
#ifndef  INTF1
#define  INTF1   (7u)
#endif
/*INTF1- External Interrupt Flag 0 bit 6 in GIFR*/
#ifndef  INTF0
#define  INTF0   (6u)
#endif
/*INTF1- External Interrupt Flag 2 bit 5 in GIFR*/
#ifndef  INTF2
#define  INTF2   (5u)
#endif

/*I-BIT Global Interrupt Enable IN SREG*/
#ifndef  I
#define  I		(7u)
#endif

#endif /* EXT_INT_PRIVATE_REG_H_ */