#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

int precedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }

    if(op == '*' || op == '/')
    {
        return 2;
    }

    return 0;
}

void push(char ch)
{
    stack[++top] = ch;
    stack[top + 1] = '\0';
}

char pop()
{
    return stack[top--];
}

int main()
{
    char exp[50];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    printf("\nSymbol\tStack\tAction\n");

    for(i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        /* Operand */
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z'))
        {
            push(ch);

            printf("%c\t%s\tSHIFT\n",
                   ch, stack);
        }

        /* Operator */
        else
        {
            while(top != -1 &&
                  precedence(stack[top]) >=
                  precedence(ch))
            {
                printf("%c\t%s\tREDUCE\n",
                       ch, stack);

                pop();
            }

            push(ch);

            printf("%c\t%s\tSHIFT\n",
                   ch, stack);
        }
    }

    /* Final reductions */
    while(top != -1)
    {
        printf("$\t%s\tREDUCE\n",
               stack);

        pop();
        stack[top + 1] = '\0';
    }

    printf("\nExpression Parsed Successfully\n");

    return 0;
}

