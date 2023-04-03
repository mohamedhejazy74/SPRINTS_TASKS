#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int32_t g_arr[MAX_INPUT_ARRAY];
uint32_t g_arrSize;
int8_t  g_status = ARRAY_SORTED;
uint8_t g_lcs_count  = 0;
int main()
{
     uint8_t temp[] = {0};
#if INSETION_SORT_DEBUGING==ENABLE_DEBUGING

    while(1)
    {
        printf("ENTER THE SIZE OF ARRAY THAT YOU WANT TO SORT:\n");
           // scanf("%i",&g_arrSize);
        gets(temp);
        fflush(stdin);
        if('\n'==*temp)
        {
            printf("nothing entered please enter a valid number");
        }
        else
        {
            g_arrSize = atoi(temp);
            if(g_arrSize>0 && g_arrSize<=10)
            {
                printf("ENTER THE ARRAY ELEMENTS TO GET SORTED :\n");
                for(int i=0; i<g_arrSize; i++)
                {
                    scanf("%i",&g_arr[i]);
                    fflush(stdin);
                }
            }


            g_status = insertionSort(g_arr,g_arrSize);
            switch (g_status)
            {
                case ARRAY_SORTED:
                    printf("THE SORTED ARRAY :\n");
                    printArray(g_arr,g_arrSize);
                    break;

                case EMPTY_ARRAY:
                    printf("Empty Array!!\n");
                    break;

                case SIZE_OUT_OF_RANGE:
                    printf("Array size is out of range.\n");
                    break;
            }
        }

    }

#endif // INSETION_SORT_DEBUGING

#if LCS_DEBUGING==ENABLE_DEBUGING
    while(1)
    {
        printf("ENTER THE SIZE OF ARRAY THAT YOU WANT TO GET THE LCS :\n");
        gets(temp);
        fflush(stdin);
        if('\n'==*temp)
        {
            printf("nothing entered please enter a valid number");
        }
        else
        {
            g_arrSize = atoi(temp);
            if(g_arrSize>0 && g_arrSize<=10)
            {
                printf("ENTER CHARACTERS OF THE ARRAY TO GET THE LCS :\n");
                for(int i=0; i<g_arrSize; i++)
                {
                    scanf("%i",&g_arr[i]);
                    fflush(stdin);
                }
            }
            g_status = lcsGetSize(g_arr,g_arrSize,&g_lcs_count);
            switch (g_status)
            {
                case FOUND_CONSCUTIVE_SEQ:
                    printf("THE COUNT OF THE LCS: %d\n", g_lcs_count);
                    break;

                case EMPTY_ARRAY:
                    printf("EMPTY ARRAY!!\n");
                    break;

                case SIZE_OUT_OF_RANGE:
                    printf("ARRAY SIZE IS OUT OF RANGE\n");
                    break;

                case NO_CONSCUTIVE_SEQ:
                    printf("THERE ARE NO CONSECUTIVE ELEMENTS\n");
                    break;
            }
        }
    }

#endif // LCS_DEBUGING

    return 0;
}
