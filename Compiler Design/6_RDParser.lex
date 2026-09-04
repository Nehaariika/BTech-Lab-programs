%{
#include <stdio.h>
#include <stdlib.h>
#define ID 257

int token;
int yylex();

void E(), Eprime();
void match(int);
%}

IDEN    [a-zA-Z]

%%

{IDEN}        { return ID; }
"+"           { return '+'; }
"-"           { return '-'; }
"*"           { return '*'; }
"/"           { return '/'; }

\n            { return 0; }  

[ \t]         ;  

. {
    printf("Invalid character: %s\n", yytext);
    exit(1);
}

%%

void match(int expected) {
    if (token == expected)
        token = yylex();
    else {
        printf("Syntax Error\n");
        exit(1);
    }
}

/* Grammar:
   E  → i E'
   E' → + i E' | - i E' | * i E' | / i E' | ε
*/

void E() {
    if (token == ID) {
        match(ID);
        Eprime();
    } else {
        printf("Syntax Error\n");
        exit(1);
    }
}

void Eprime() {
    if (token == '+' || token == '-' || token == '*' || token == '/') {
        int op = token;
        match(op);
        match(ID);
        Eprime();
    }
 
}

int main() {
    printf("Enter expression:\n");

    token = yylex();
    E();

    if (token == 0)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}

int yywrap() {
    return 1;
}