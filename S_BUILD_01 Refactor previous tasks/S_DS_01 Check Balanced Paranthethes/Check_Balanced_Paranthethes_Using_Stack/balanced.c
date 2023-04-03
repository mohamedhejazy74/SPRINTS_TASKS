#include "balanced.h"
ST_stack_t s_stack_obj;

uint8_t isBalance = 0;
/*HELPER STATIC FUNCTION TO CHECK IF THE OPENED PARENTHESES HAVE CLOSED OR NOT*/
static uint8_t isParenthesesOpened(uint8_t open, uint8_t close);

int8_t isBalancedParanthethes(uint8_t *expression)
{
    uint8_t i = 0;
    uint8_t curl_flag = 0;
    uint8_t parentheses_flag = 0;
    int8_t STACK_STATUS = STACK_EMPTY;
    uint8_t STACK_POP = 0;
    uint8_t STACK_TOP = 0;
    if(*expression=='\0') return NO_PARENTHESES;
    createEmptyStack(&s_stack_obj);
    for(i=0;i<MAX_EXPRESSION_SIZE;i++)
    {
        /* { ( ( } ) } { } */
        STACK_STATUS = getStackTop(&s_stack_obj,&STACK_TOP);
        if('{'==expression[i])
        {
            STACK_STATUS = push(&s_stack_obj,expression[i]);
            curl_flag ++;
        }
        else if('('==expression[i])
        {
            STACK_STATUS = push(&s_stack_obj,expression[i]);
            parentheses_flag ++;
        }
        else if('}'==expression[i] && curl_flag)
        {
            STACK_STATUS = pop(&s_stack_obj,&STACK_POP);
             curl_flag --;
        }
        else if(')'==expression[i] && parentheses_flag)
        {
            STACK_STATUS = pop(&s_stack_obj,&STACK_POP);
            parentheses_flag --;
        }
        else if((('}'==expression[i]) || (')'==expression[i])) && !isParenthesesOpened(STACK_TOP,expression[i]))
        {
            return UNBALANCED;
        }
        else
        {
            // do nothing
        }
    }
    if(STACK_EMPTY==isEmpty(&s_stack_obj)) return ALL_BALANCED;
    else return UNBALANCED;
}


static uint8_t isParenthesesOpened(uint8_t open, uint8_t close)
{
    if( ('('==open) && (')'==close))
        {
            return CLOSED_PARENTHESES;
        }
        else if(('{'==open) && ('}'==close))
        {
            return CLOSED_PARENTHESES;
        }
        else
        {
            return OPEN_PARENTHESES;
        }
}
