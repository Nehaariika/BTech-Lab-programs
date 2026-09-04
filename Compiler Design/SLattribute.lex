%{
#include<stdio.h>
%}

%%
"S"     { printf("S-Attributed Grammar\n"); }

"L"     { printf("L-Attributed Grammar\n"); }

.       { printf("Invalid Input\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter S or L : ");
    yylex();
    return 0;
}