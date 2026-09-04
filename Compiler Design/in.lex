%{
#include <stdio.h>
#include <stdlib.h>

int val[50], vtop = -1;
char op[50];
int otop = -1;

void pushVal(int x) { val[++vtop] = x; }
int popVal() { return val[vtop--]; }

void pushOp(char x) { op[++otop] = x; }
char popOp() { return op[otop--]; }

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int calc(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
    return 0;
}
%}

%%

[0-9]+    { pushVal(atoi(yytext)); }

[+\-*/]   {
             char c = yytext[0];
             while (otop != -1 && prec(op[otop]) >= prec(c)) {
                 int b = popVal();
                 int a = popVal();
                 pushVal(calc(a, b, popOp()));
             }
             pushOp(c);
          }

\n        {
             while (otop != -1) {
                 int b = popVal();
                 int a = popVal();
                 pushVal(calc(a, b, popOp()));
             }
             printf("Result = %d\n", popVal());
             return 0;
          }

[ \t]    ;   /* ignore spaces */

.        { printf("Error\n"); }

%%

int yywrap() { return 1; }

int main() {
    printf("Enter expression: ");
    yylex();
    return 0;
}