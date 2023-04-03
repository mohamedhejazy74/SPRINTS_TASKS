#include "lcs.h"

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    uint8_t count = 1, lcs_maxCount = 1;
    int8_t i = 0;
    int8_t sort_status = ARRAY_SORTED;
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
            sort_status = insertionSort(array,arraySize);
            if(ARRAY_SORTED==sort_status)
            {
                 for(i=0;i<arraySize;i++)
                 {
                     if(array[i+1]-array[i]==1)
                     {
                         count++;
                         lcs_maxCount = (count > lcs_maxCount) ? count : lcs_maxCount;
                     }
                     else
                     {

                         count = 1;
                     }

                 }
            }
            *sizeofLCS = lcs_maxCount;
        }
    }
    else
    {
        return EMPTY_ARRAY;
    }
    if(lcs_maxCount == 1) return NO_CONSCUTIVE_SEQ;
    else return FOUND_CONSCUTIVE_SEQ;
}

