%{
    #include<stdio.h>
%}

%%

[A-Z] { printf("UpperCase Letter\n"); }
[a-z] { printf("LowerCase Letter\n"); }

\n { return 0; }

%%
int main()
{
    printf("Enter a Character:");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}