#include "test_STACK.h"

ST_stack_t s_stack;
uint8_t g_data = 0;
uint8_t g_TopData = 0;
int8_t g_stackStatus = (STACK_EMPTY);

void test_stack(void)
{
    uint8_t temp[10]= {0};
    //1. Create an empty stack
    createEmptyStack(&s_stack);

    //2. Push 5 different characters to the stack
    printf("ENTER 5 CHARACTERS TO BE PUSHED INTO THE STACK : \n");
    for(int i=0; i<5; i++)
    {
        temp[i] = getchar();
        fflush(stdin);
    }
    for(int i=0; i<5; i++)
    {
        g_stackStatus = push(&s_stack,temp[i]);
        if(g_stackStatus!=STACK_FULL) printf("THE PUSHED ELEMENT IS : %c\n",temp[i]);
    }

    //3. Print all stack data
    g_stackStatus = printStack(&s_stack);

     //4. Pop one character from the stack
    printf("ENTER 'Y' IF YOU WANT TO POP ONE ELEMENT FROM THE STACK \n");
    temp[0] = getchar();
    fflush(stdin);
    if('Y'==temp[0])
    {
        g_stackStatus = pop(&s_stack,&g_data);
        if(g_stackStatus!=STACK_EMPTY) printf("THE POPPED ELEMENT IS : %c\n",g_data);
    }

    //5. Print the stack's top
    g_stackStatus = getStackTop(&s_stack,&g_TopData);
    printf("NOW STACK TOP IS: %c\n",g_TopData);

    //6. Print all stack data
    g_stackStatus = printStack(&s_stack);

    //7. Push another 7 different characters to the stack
    printf("ENTER 7 CHARACTERS TO BE PUSHED INTO THE STACK : \n");
    for(int i=0; i<7; i++)
    {
        temp[i] = getchar();
        fflush(stdin);
    }
    for(int i=0; i<7; i++)
    {
        g_stackStatus = push(&s_stack,temp[i]);
        if(g_stackStatus!=STACK_FULL) printf("THE PUSHED ELEMENT IS : %c\n",temp[i]);
    }

    //8. Print the stack's top
    g_stackStatus = getStackTop(&s_stack,&g_TopData);
    if(g_stackStatus!=STACK_EMPTY) printf("NOW STACK TOP IS: %c\n",g_TopData);

    //9. Print all stack data
    g_stackStatus = printStack(&s_stack);

    //10. Pop 4 characters from the stack
    printf("ENTER 'Y' IF YOU WANT TO POP 4 MORE ELEMENTS FROM THE STACK \n");
    temp[0] = getchar();
    fflush(stdin);
    if('Y'==temp[0])
    {
        for(int i=0; i<4; i++)
        {
            g_stackStatus |= pop(&s_stack,&g_data);
           if(g_stackStatus!=STACK_EMPTY)  printf("THE POPPED ELEMENT IS : %c\n",g_data);
        }
    }

    //11. Print the stack's top
    g_stackStatus = getStackTop(&s_stack,&g_TopData);
    if(g_stackStatus!=STACK_EMPTY) printf("NOW STACK TOP IS: %c\n",g_TopData);

    //12. Print all stack data
    g_stackStatus = printStack(&s_stack);
    //13. Pop 7 more times from the stack
    printf("ENTER 'Y' IF YOU WANT TO POP 7 MORE ELEMENTS FROM THE STACK \n");
    temp[0] = getchar();
    fflush(stdin);
    if('Y'==temp[0])
    {
        for(int i=0; i<7; i++)
        {
            g_stackStatus |= pop(&s_stack,&g_data);
            if(g_stackStatus!=STACK_EMPTY) printf("THE POPPED ELEMENT IS : %c\n",g_data);
        }
    }

    //14. Print the stack's top
    g_stackStatus = getStackTop(&s_stack,&g_TopData);
    if(g_stackStatus!=STACK_EMPTY) printf("NOW STACK TOP IS: %c\n",g_TopData);

    //15. Print all stack data
    g_stackStatus = printStack(&s_stack);
}
