/* 
 * File:   BIT_MATH_H
 * Author:  Mohamed Abdel-Wahab
 */

#define BIT_MASK    0x01u
#define PORT_MASK   0xffu

#define PORT_PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER         5



/**********************************  section 3: Macro Like Function Declarations *************************** *****/

/*dereference a register*/
#define HWREG8(_X)      (*((volatile uint8 *)(_x)))

/*set a certain bit in a 8-bit register*/
#define SET_BIT(REG,BIT_POSN)    (REG |=  (BIT_MASK << BIT_POSN))
/*reset a certain bit in a 8-bit register*/
#define CLEAR_BIT(REG,BIT_POSN)  (REG &= ~(BIT_MASK << BIT_POSN))
/*toggle a certain bit in a 8-bit register*/
#define TOGGLE_BIT(REG,BIT_POS)  (REG ^=  (BIT_MASK << BIT_POS) )
/*read a certain bit in a 8-bit register*/
#define READ_BIT(REG,BIT_POS)    ((REG >> BIT_POS) & (BIT_MASK) )


#endif	/*BIT_MATH_H */

