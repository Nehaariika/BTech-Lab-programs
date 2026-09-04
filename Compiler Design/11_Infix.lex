%{
    #include<stdio.h>
    #include<ctype.h>
    #include<string.h>

    char stack[100];
    int top=-1;

    void push(char c);
    char pop();
    int precedence(char c);

%}

%%

[a-zA-Z0-9] {
    printf("%s", yytext);
}

"(" {
    push('(');
}

")" {
    while(top !=-1 && stack[top] !='(')
    printf("%c", pop());

    pop();
}

"+"|"-"|"*"|"/" {
    char op = yytext[0];

    while(top !=-1 && precedence(stack[top]) >= precedence(op))
    {
        printf("%c", pop());
    }

    push(op);
}

\n {
    while(top != -1)
    printf("%c", pop());
    printf("\n");
    return 0;
}

[\t] ;
. ;

%%
void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int precedence(char c) {
    if(c == '+' || c=='-')
    return 1;

    if(c == '*' || c=='/')
    return 2;

    return 0;
}

int main() {
    printf("Enter Infix Expression: ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}