
%{
#include<stdio.h>
int id=0,k=0;
void countkey(){
k++;
}
void countid(){
id++;
}

%}

%%
int|auto|double|struct|break|else|long|switch|case|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|enum|default|goto|sizeof|volatile|const|float|short  {ECHO; printf("\n KEYWORD \n");countkey();}
[{};,()] {ECHO; printf("\n SEPARATOR\n");} 
[+-/=*%] {ECHO; printf("\n OPERATOR\n");}
([A-Z a-z][0-9])+[a-z A-Z]* {ECHO; printf("\n IDENTIFIER\n");countid();}
[0-9]+ {ECHO; printf("\n NUmber");}
.|\n;
%%
int main()
{
	printf("Enter a string:");
	yylex();
	printf("No of keyword:%d",k);
	printf("No of identifiers:%d",id);
	return 0;
}
int yywrap(){
return 1;
}