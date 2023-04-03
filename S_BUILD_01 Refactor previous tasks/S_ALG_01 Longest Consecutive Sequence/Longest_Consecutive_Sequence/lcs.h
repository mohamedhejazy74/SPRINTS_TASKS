#ifndef LCS_H_INCLUDED
#define LCS_H_INCLUDED
/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define LCS_MAX_ARRAY_SIZE       10u
#define EMPTY_ARRAY          -1
#define SIZE_OUT_OF_RANGE    -2
#define NO_CONSCUTIVE_SEQ    -3
#define FOUND_CONSCUTIVE_SEQ  0
/* ********************** Macro Section End   ************************* */

/* ********************** Functions declarations Start ************************* */
/**
 * @brief returns the longest subsequence of consecutive integers
 *        in the given array
 *
 * @param array a reference to desired array of integers
 * @param arraySize size of referenced array (should be less than LCS_MAX_ARRAY_SIZE)
 * @param sizeofLCS reference to a variable to return the size of LCS into
 * @return int8_t : EMPTY_ARRAY
 *                  SIZE_OUT_OF_RANGE
 *                  NO_CONSCUTIVE_SEQ
 *                  FOUND_CONSCUTIVE_SEQ
 */

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);
/* ********************** Functions declarations Section End   ************************* */

#endif // LCS_H_INCLUDED
