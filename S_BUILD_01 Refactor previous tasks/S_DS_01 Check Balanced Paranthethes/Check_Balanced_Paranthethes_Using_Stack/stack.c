#include "stack_h.h"

void createEmptyStack(ST_stack_t *stack)
{
    uint8_t i = 0;
    if(stack)
    {
        for(i=0; i<STACK_SIZE; i++)
        {
            stack->elements[i] = 0;
        }
        stack->top = STACK_TOP_INIT;
    }
    else
    {
        // do nothing
    }

}

int8_t push(ST_stack_t *stack, uint8_t data)
{
    if(stack)
    {
        if(STACK_NOT_FULL == isFull(stack))
        {
            (stack->top)++;
            stack->elements[stack->top] = data;

            return STACK_NOT_FULL;
        }
        else
        {
            return STACK_FULL;
        }
    }
    else
    {
        // do nothing
    }
}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    if(stack)
    {
        if(STACK_NOT_EMPTY == isEmpty(stack))
        {
            (*data) = stack->elements[stack->top];
            (stack->top)--;
            return STACK_NOT_EMPTY;
        }
        else
        {
            return STACK_EMPTY;
        }
    }
    else
    {
        // do nothing
    }
}

int8_t printStack(ST_stack_t *stack)
{
    int8_t i = 0;
    if(stack)
    {
        if(STACK_FULL == isFull(stack))
        {
            printf("Stack Is Full And Stack Elements Are :\n");
            for(i=(stack->top); i>STACK_TOP_INIT; i--)
            {
                printf("%c\n",stack->elements[i]);
            }
            return STACK_FULL;
        }
        else if(STACK_EMPTY == isEmpty(stack))
        {
            printf("Stack Is Empty !!\n");
            return STACK_EMPTY;
        }
        else
        {
            printf("Stack Elements Are :\n");
            for(i=(stack->top); i>STACK_TOP_INIT; i--)
            {
                printf("%c\n",stack->elements[i]);
            }
            return STACK_NOT_FULL && STACK_NOT_EMPTY;
        }
    }
    else
    {
        // do nothing
    }
}
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{

    if(stack && topData)
    {
        if(STACK_EMPTY == isEmpty(stack))
        {
#if STACK_DEBUGING==ENABLE_DEBUGING
            printf("Stack Is Empty !!\n");
#endif // STACK_DEBUGING
            return STACK_EMPTY;
        }
        else
        {
            (*topData) = stack->elements[stack->top];
            return STACK_NOT_FULL && STACK_NOT_EMPTY;
        }

    }
    else
    {
        // do nothing
    }
}
int8_t isFull(ST_stack_t *stack)
{
    if(stack)
    {
        if((STACK_SIZE-1)==stack->top)
        {
            return STACK_FULL;
        }
        else
        {
            return STACK_NOT_FULL;
        }
    }
    else
    {
        // do nothing
    }
}
int8_t isEmpty(ST_stack_t *stack)
{
    if(stack)
    {
        if(STACK_TOP_INIT==stack->top)
        {
            return STACK_EMPTY;
        }
        else
        {
            return STACK_NOT_EMPTY;
        }
    }
    else
    {
        // do nothing
    }
}
