/* 
 * File:   mcal_std_types.h
 * Author: Mohamed Abdel-Wahab
 *
 * Created on February 14, 2023, 8:45 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/**********************************  section 1: Includes ********************************************************/

/**********************************  section 2: Macro Declarations ***********************************************/
#define E_OK            0x01u
#define E_NOT_OK        0x00u

#define STD_HIGH        0x01u  /* Physical state 5V or 3.3V */
#define STD_LOW         0x00u  /* Physical state 0V */

#define STD_ACTIVE      0x01u  /* Logical state active */
#define STD_IDLE        0x00u  /* Logical state idle */

#define STD_ON          0x01u
#define STD_OFF         0x00u

#define CONFIG_ENABLE   0x01u  
#define CONFIG_DISABLE  0x00u  
/**********************************  section 3: Macro Like Function Declarations *************************** *****/

/**********************************  section 4: Data Type Declarations  ******************************************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed char sint16;
typedef signed char sint32;

typedef uint8 Std_ReturnType;

/**********************************  section 5: Function Declarations ********************************************/

#endif	/* MCAL_STD_TYPES_H */

