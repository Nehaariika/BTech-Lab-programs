%{
#include<stdio.h>

%}

%%
".inh"     { printf("L-Attributed Grammar\n");}
".val"     { printf("S-Attributed Grammar\n");}
".syn"     { printf("S-Attributed Grammar\n");}

\n          ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter attributed grammar S or L : ");
    yylex();
    return 0;
}