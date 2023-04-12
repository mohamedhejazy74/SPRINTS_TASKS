/*
 * timer_private_reg.h
 *
 * Created: 4/10/2023 3:40:44 PM
 *  Author: Mcs
 */ 


#ifndef TIMER_PRIVATE_REG_H_
#define TIMER_PRIVATE_REG_H_
#include "../../STD_LIBRARIES/STD_TYPES.h"
#include "../../STD_LIBRARIES/bit_math.h"

/****************************************TIMER0_REGISTERS *************************************************/
/* TCNT0 – Timer/Counter Register*/
#define TCNT0   (*(volatile uint8_t*)0x52)
/*Timer/Counter Control Register*/
#define TCCR0   (*(volatile uint8_t*)0x53)
/*TIMSK – Timer/Counter Interrupt Mask Register*/
#define TIMSK   (*(volatile uint8_t*)0x59)
/*GIFR – General Interrupt Flag Register*/
#define GIFR    (*(volatile uint8_t*)0x5A)
/*TIFR – Timer/Counter Interrupt Flag Register*/
#define TIFR    (*(volatile uint8_t*)0x58)
/*OCR0 – Output Compare Register*/
#define OCR0    (*(volatile uint8_t*)0x5C)

/*TCCR0-TIMER_0_CONTROL_REG_BITS*/
/*Bit 2:0 – CS02:0: Clock Select in TCCR0 REG */
#define CS00  (0u)
#define CS01  (1u)
#define CS02  (2u)
/*Bit 5:4 – COM0[1:0]: Compare Match Output Mode in TCCR0 REG */
#define COM00 (4u)
#define COM01 (5u)
/*Bit 6, 3 – WGM0[1:0]: Waveform Generation Mode in TCCR0 REG */
#define WGM00 (6u)
#define WGM01 (3u)
/*Bit 7 – FOC0:Force Output Compare bit in TCCR0 REG*/
#define FOC0  (7u)


/*TIMSK-TIMER 0 INTERRUPT MASK REG BITS*/
/*Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable in TIMSK REG */
#define TOIE0 (0u)
/*Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable in TIMSK REG*/
#define OCIE0 (1u)

/*GIFR-TIMER 0 INTERRUPT FLAG REG BITS*/
/*Bit 0 – TOV0: Timer/Counter0 Overflow Flag in TIFR REG*/
#define TOV0  (0u)
/* Bit 1 – OCF0: Output Compare Flag 0 in TIFR REG*/
#define OCF0  (1u)

/****************************************TIMER1_REGISTERS *************************************************/

/* TCCR1A – Timer/Counter1 Control Register A*/
#define TCCR1A   (*(volatile uint8_t*)0x4F)
/*TCCR1B – Timer/Counter1 Control Register B*/
#define TCCR1B   (*(volatile uint8_t*)0x4E)
/*TCNT1H  Timer/Counter1 – Counter Register High Byte*/
#define TCNT1H   (*(volatile uint8_t*)0x4D)
/*TCNT1L  Timer/Counter1 – Counter Register low Byte*/
#define TCNT1L   (*(volatile uint8_t*)0x4C)
/*OCR1AH Timer/Counter1 – Output Compare Register A High Byte */
#define OCR1AH   (*(volatile uint8_t*)0x4B)
/*OCR1AL Timer/Counter1 – Output Compare Register A Low Byte*/
#define OCR1AL   (*(volatile uint8_t*)0x4A)
/*OCR1BH Timer/Counter1 – Output Compare Register B High Byte*/
#define OCR1BH   (*(volatile uint8_t*)0x49)
/*OCR1BL Timer/Counter1 – Output Compare Register B Low Byte*/
#define OCR1BL   (*(volatile uint8_t*)0x48)


/*TCCR1A -TIMER_1_CONTROL_REG_A_BITS*/
/* Bit 7:6 – COM1A1:0: Compare Output Mode for Compare unit A in TCCR1A REG */
#define COM1A0 (6u)
#define COM1A1 (7u)
/* Bit 5:4 – COM1B1:0: Compare Output Mode for Compare unit B*/
#define COM1B1 (4u)
#define COM1B1 (5u)
/* Bit 3 – FOC1A: Force Output Compare for Compare unit A*/
#define FOC1A (3u)
/*Bit 2 – FOC1B: Force Output Compare for Compare unit B*/
#define FOC1B (2u)
/* Bit 1:0 – WGM11:0: Waveform Generation Mode*/
#define WGM10 (0u)
#define WGM11 (1u)

/*TCCR1B-TIMER_1_CONTROL_REG_B_BITS*/
/*Bit 7 – ICNC1: Input Capture Noise Canceler*/
#define ICNC1 (7u)
/*Bit 6 – ICES1: Input Capture Edge Select*/
#define ICES1 (6u)
/*Bit 4:3 – WGM13:2: Waveform Generation Mode*/
#define WGM12 (4u)
#define WGM13 (3u)
/*Bit 2:0 – CS12:0: Clock Select*/

#define CS12 (2u)
#define CS11 (1u)
#define CS10 (0u)

/*TIMSK-TIMER1 INTERRUPT MASK REG BITS*/

/*Bit 2 – TOIE1: Timer/Counter1, Overflow Interrupt Enable */
#define TOIE1 (2u)
/*Bit 4 – OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable*/
#define OCIE1A (4u)
/*Bit 3 – OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define OCIE1B (3u)


/* TIFR – Timer/Counter1 Interrupt Flag Register bits*/

/*Bit 4 – OCF1A: Timer/Counter1, Output Compare A Match Flag*/
#define OCF1A (4u)
/*Bit 3 – OCF1B: Timer/Counter1, Output Compare B Match Flag*/
#define OCF1B (3u)
/* Bit 2 – TOV1: Timer/Counter1, Overflow Flag*/
#define TOV1 (2u)



/****************************************TIMER2_REGISTERS *************************************************/
/*TCCR2 – Timer/Counter Control Register*/
#define TCCR2   (*(volatile uint8_t*)0x45)
/*TCNT2 – Timer/Counter Register*/
#define TCNT2   (*(volatile uint8_t*)0x44)
/*OCR2 – Output Compare Register*/
#define OCR2   (*(volatile uint8_t*)0x43)


/*TCCR2 - TIMER_2_CONTROL_REG_BITS*/

/*Bit 7 – FOC2: Force Output Compare*/
#define FOC2 (7u)
/*Bit 6, 3 – WGM2[1:0]: Waveform Generation Mode*/
#define WGM20 (6u)
#define WGM21 (3u)
/*Bit 5:4 – COM2[1:0]: Compare Match Output Mode*/
#define COM20 (4u)
#define COM21 (5u)
/*Bit 2:0 – CS2[2:0]: Clock Select*/
#define CS20 (2u)
#define CS21 (1u)
#define CS22 (0u)

/*TIMSK-TIMER 2 INTERRUPT MASK REG BITS*/

/*Bit 7 – OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable*/
#define OCIE2 (7u)
/* Bit 6 – TOIE2: Timer/Counter2 Overflow Interrupt Enable*/
#define TOIE2 (6u)


/*TIFR – Timer/Counter Interrupt Flag Register bits */

/*Bit 7 – OCF2: Output Compare Flag 2*/
#define OCF2 (7u)
/* Bit 6 – TOV2: Timer/Counter2 Overflow Flag*/
#define TOV2 (6u)





#endif /* TIMER_PRIVATE_REG_H_ */