#include <stdio.h>
#include <stdlib.h>
#include "main.h"

uint8_t input_expression[MAX_INPUT_SIZE];
uint8_t parentheses_expression[MAX_EXPRESSION_SIZE];
int8_t returns_status;
int main()
{
#if STACK_DEBUGING==ENABLE_DEBUGING
    test_stack();
#endif // STACK_DEBUGING

#if CHECK_BALANCED_PARANTHETHES_DEBUGING==ENABLE_DEBUGING
    while(1)
    {
        printf("please Enter a string: ");
        fgets(input_expression, sizeof(input_expression), stdin);
        getParentheses(input_expression);
        returns_status = isBalancedParanthethes(parentheses_expression);
        if (returns_status == UNBALANCED)
        {
            printf("unbalanced expression\n");
        }
        else if (returns_status == NO_PARENTHESES)
        {
            printf("there are no parentheses\n");
        }
        else
        {
            printf("expression is balanced\n");
        }
    }

#endif // CHECK_BALANCED_PARANTHETHES_DEBUGING
    return 0;
}
void getParentheses(uint8_t *expression)
{
    uint8_t i=0;
    uint8_t j=0;
    if(expression)
    {
        for(i=0;i<MAX_INPUT_SIZE;i++)
        {
            if(expression[i]=='{' || expression[i]=='}' || expression[i]=='(' || expression[i]==')')
            {
                parentheses_expression[j] = expression[i];
#if CHECK_BALANCED_PARANTHETHES_DEBUGING==ENABLE_DEBUGING
                printf("%c\t",parentheses_expression[j]);
#endif // CHECK_BALANCED_PARANTHETHES_DEBUGING
                j++;
                if(j>MAX_EXPRESSION_SIZE) break;
            }

        }
#if CHECK_BALANCED_PARANTHETHES_DEBUGING==ENABLE_DEBUGING
        printf("\n");
#endif // CHECK_BALANCED_PARANTHETHES_DEBUGIN
    }
}
