#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED
/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define MAX_ARRAY_SIZE       10u
#define EMPTY_ARRAY          -1
#define SIZE_OUT_OF_RANGE    -2
#define ARRAY_SORTED          0
/* ********************** Macro Section End   ************************* */
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef signed int int32_t;

/* ********************** Functions declarations Start ************************* */
/**
 * @brief sorts the referenced array using insertion sort algorithm
 *
 * @param array reference to the array to sort
 * @param arraySize size of the referenced array
 * @return int8_t  Options:
 *                  EMPTY_ARRAY
 *                  SIZE_OUT_OF_RANGE
 *                  ARRAY_SORTED
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);

/**
 * @brief prints a referenced array
 *
 * @param array pointer to the array to print
 * @param arraySize size of the referenced array
 */
void printArray(int32_t *array, uint8_t arraySize);

/* ********************** Functions declarations Section End   ************************* */
#endif // INSERTION_SORT_H_INCLUDED
