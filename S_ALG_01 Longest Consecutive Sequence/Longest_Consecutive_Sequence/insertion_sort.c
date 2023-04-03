#include "insertion_sort.h"
int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    int8_t i = 0,j=0;
    int32_t key=0;
    if(array)
    {
        if(arraySize <= 0)
        {
             return EMPTY_ARRAY;
        }
        else if(arraySize > MAX_ARRAY_SIZE)
        {
            return SIZE_OUT_OF_RANGE;
        }
        else
        {
            for(i=1;i<arraySize;i++)
            {
                key = array[i];
                j = i -1;
                /*Compare key with each element on the left of it until an element smaller than it is found.*/
                while(key < array[j] && j>=0)
                {
                    array[j+1] = array[j];
                    --j;
                }
                /*insertion of the key-smaller element- */
                 array[j+1] = key ;
            }

        }
    }
    else
    {
        return EMPTY_ARRAY;
    }
    return ARRAY_SORTED;
}

void printArray(int32_t *array, uint8_t arraySize)
{
    uint8_t i=0;
	for(i=0; i<arraySize; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}
