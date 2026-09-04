#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int precedence(char c)
{
    if(c == '^')
        return 3;

    if(c == '*' || c == '/')
        return 2;

    if(c == '+' || c == '-')
        return 1;

    return 0;
}

int isOperator(char c)
{
    return c == '+' ||
           c == '-' ||
           c == '*' ||
           c == '/' ||
           c == '^';
}

void infixToPostfix(char *infix,
                    char *postfix)
{
    int i, k = 0;
    int len = strlen(infix);

    for(i = 0; i < len; i++)
    {
        char c = infix[i];

        /* Operand */
        if(isalnum(c))
        {
            postfix[k++] = c;
        }

        /* Left Parenthesis */
        else if(c == '(')
        {
            push(c);
        }

        /* Right Parenthesis */
        else if(c == ')')
        {
            while(!isEmpty() &&
                  peek() != '(')
            {
                postfix[k++] = pop();
            }

            pop(); /* discard '(' */
        }

        /* Operator */
        else if(isOperator(c))
        {
            /* ^ is right associative */
            while(!isEmpty() &&
                  precedence(peek()) >=
                  precedence(c) &&
                  !(c == '^' &&
                    peek() == '^'))
            {
                postfix[k++] = pop();
            }

            push(c);
        }
    }

    while(!isEmpty())
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[100],
         postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix,
                   postfix);

    printf("Postfix expression : %s\n",
           postfix);

    return 0;
}

Enter infix expression: A+B*C

Postfix expression : ABC*+