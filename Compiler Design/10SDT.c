#include <stdio.h>
#include <ctype.h>

char input[100];
int pos = 0;

/* Forward declarations */
int E();
int T();
int F();

/* E -> T {(+|-) T} */
int E()
{
    int value = T();

    while(input[pos] == '+' ||
          input[pos] == '-')
    {
        char op = input[pos++];

        int temp = T();

        /* Semantic action */
        if(op == '+')
        {
            value = value + temp;
        }
        else
        {
            value = value - temp;
        }
    }

    return value;
}

/* T -> F {(*|/) F} */
int T()
{
    int value = F();

    while(input[pos] == '*' ||
          input[pos] == '/')
    {
        char op = input[pos++];

        int temp = F();

        /* Semantic action */
        if(op == '*')
        {
            value = value * temp;
        }
        else
        {
            value = value / temp;
        }
    }

    return value;
}

/* F -> digit */
int F()
{
    int value = 0;

    if(isdigit(input[pos]))
    {
        value =
            input[pos] - '0';

        pos++;
    }

    return value;
}

int main()
{
    int result;

    printf("Enter expression: ");
    scanf("%s", input);

    result = E();

    printf("Result = %d\n",
           result);

    return 0;
}

