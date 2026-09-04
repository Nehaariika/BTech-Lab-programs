%{
#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

char inp[50];
int i = 0;

// precedence table
char precedence[4][4] = {
/*      +    *    i    $ */
/* + */ {'>', '<', '<', '>'},
/* * */ {'>', '>', '<', '>'},
/* i */ {'>', '>', 'e', '>'},
/* $ */ {'<', '<', '<', 'a'}
};

int getIndex(char c) {
    if (c == '+') return 0;
    if (c == '*') return 1;
    if (c == 'i') return 2;
    if (c == '$') return 3;
    return -1;
}

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop() {
    if (top >= 0) {
        stack[top--] = '\0';
    }
}

char topTerminal() {
    int j;
    for (j = top; j >= 0; j--) {
        if (stack[j]=='+' || stack[j]=='*' || stack[j]=='i' || stack[j]=='$')
            return stack[j];
    }
    return '$';
}
%}

%%

[+\*i$]   { inp[i++] = yytext[0]; }
\n        { return 0; }

%%

int main() {
    printf("Enter expression (end with $): ");
    yylex();   // take inp via lex

    inp[i] = '\0';

    i = 0;
    push('$');
    char a = inp[i];

    printf("\nSTACK\tINP\tACTION\n");

    while (1) {
        char t = topTerminal();
        int row = getIndex(t);
        int col = getIndex(a);

        printf("%s\t%s\t", stack, inp + i);

        if (precedence[row][col] == '<') {
            push(a);
            printf("Shift %c\n", a);
            a = inp[++i];
        }
        else if (precedence[row][col] == '>') {
            pop();
            printf("Reduce\n");
        }
        else if (precedence[row][col] == 'a') {
            printf("Accepted\n");
            break;
        }
        else {
            printf("Error\n");
            break;
        }
    }

    return 0;
}

int yywrap() {
    return 1;
}