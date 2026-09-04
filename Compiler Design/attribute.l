%{
#include<stdio.h>
#include<string.h>

int inherited=0;
int synthesized=0;
%}

%%
".inh"     { inherited=1;}
".val"     { synthesized=1;}
".syn"     { synthesized=1;}

\n         {
    
    if (synthesized && ! inherited)
    printf("S-Attributed Grammar\n");

else if (inherited)
printf("L-Attributed Grammar\n");


inherited=0;
synthesized=0;
}
. ;
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