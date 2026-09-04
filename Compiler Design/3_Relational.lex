%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%%
(==|!=|>=|<=|>|<) {
    printf("Relational Operator\n");
}
. {printf("Not Relational Operator\n"); }

%%
int main(){
    printf("Enter Operators:");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}