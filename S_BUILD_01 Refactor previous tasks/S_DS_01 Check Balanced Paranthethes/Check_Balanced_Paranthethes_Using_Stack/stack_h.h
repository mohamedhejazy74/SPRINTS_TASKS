#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include "test_STACK.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */


#define STACK_SIZE        10U
#define STACK_TOP_INIT   (-1)
#define STACK_FULL       (-1)
#define STACK_NOT_FULL   (0)
#define STACK_EMPTY      (-2)
#define STACK_NOT_EMPTY  (0)

/* ********************** Macro Section End   ************************* */
typedef unsigned char uint8_t;
typedef char int8_t;
/* ********************** Global Data declarations Start ************************* */

typedef struct stack {
uint8_t elements[STACK_SIZE];
int8_t top;
}ST_stack_t; // Type

/* ********************** Global Data declarations Ended ************************* */


/* ********************** Functions declarations Start ************************* */


/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t *stack);


/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t *stack, uint8_t data);




/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t *stack, uint8_t *data);



/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
*/
int8_t printStack(ST_stack_t *stack);




/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);




/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t *stack);




/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t *stack);



/* ********************** Functions declarations Section End   ************************* */


#endif // STACK_H_INCLUDED
