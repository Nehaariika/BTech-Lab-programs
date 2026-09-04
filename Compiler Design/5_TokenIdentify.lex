%{
    #include<stdio.h>
    
%}
%%
int|float|char|if|else|while|for|return
{ printf("Keyword: %s \n", yytext);}


[0-9]+ { printf("Number: %s \n", yytext); }

[a-zA-Z][a-zA-Z0-9]* { printf(Identifier: %s \n", yytext); }

[+\-*/=] { printf("Operator: %s\n", yytext); }

[ \t\n] {}

. { printf("Special Symbol: %s\n", yytext); }

%%
int main(){
    printf("Enter the input:");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}