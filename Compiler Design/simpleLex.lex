%{
    #include<stdio.h>

%}
%%
int main(){
    printf("Hiee! This is Kl");
    yylex();
    return 0;
}
int yywrap(){
    return 1;
}