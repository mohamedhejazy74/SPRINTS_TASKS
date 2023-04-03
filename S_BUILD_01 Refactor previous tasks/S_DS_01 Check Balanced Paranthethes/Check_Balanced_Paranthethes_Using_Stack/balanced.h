#ifndef BALANCED_H_INCLUDED
#define BALANCED_H_INCLUDED
/* ********************** Includes Section Start ********************** */
#include "stack_h.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define ENABLE_DEBUGING  1U
#define DISABLE_DEBUGING 0U
#define CHECK_BALANCED_PARANTHETHES_DEBUGING  ENABLE_DEBUGING

#define MAX_EXPRESSION_SIZE 10u
#define ALL_BALANCED         0
#define UNBALANCED          -1
#define NO_PARENTHESES      -2
#define CLOSED_PARENTHESES   1
#define OPEN_PARENTHESES     0
/* ********************** Macro Section End   ************************* */

/* ********************** Functions declarations Start ************************* */
/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t *expression);

/* ********************** Functions declarations Section End   ************************* */
#endif // BALANCED_H_INCLUDED
