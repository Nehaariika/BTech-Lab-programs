%{
  #include<stdio.h>
%}
%%
^[a-zA-Z_][a-zA-Z0-9_]*$ {printf("valid\n"); }
^.* {printf("Not Valid");
}
%%
int main(){
  printf("Enter String:");
  yylex();
  return 0;
}

  int yywrap(){
    return -1;
  }
