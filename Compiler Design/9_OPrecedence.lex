%{
    #include<stdio.h>
    #include<string.h>

    char stack[50], input[50];
    int top = -1, i=0;

    void push(char);
    char pop();
    int precedence(char);
    void parse();
%}

%%

\n {
    printf("Enter Expression: ");
    scanf("%s", input);
    strcat(input, "$");

    parse();
%}

%%

void push(char c) {
    stack[++top] = c;
}

char pop() {
    stack[top--] ;
}

int precedence(char c){
    if(c=='+' || c=='-')return 1;
    if(c=='+' || c=='/')return 2;
    return 0;
}

void parse() {
    int j =0; 
    char a, b;

    stack[++top] = '$';

    printf("\nStack\tInput\tAction\n");

    while(1) {
        a=stack[top];
        b=input[j];

        printf("%s\t%s\t", stcak, input+j);

        if(a=='$' && b=='$') {
            printf("Accepted\n");
            break;
        }

        else if(b=='i') {
            push(b);
            j++;
            printf("Shift i\n");
        }

        else if(precedence(a) < precedence(b)) {
            push(b);
            j++;
            printf("shift %c\n", b);
        }

        else {
            pop();
            printf("Reduce\n");
        }
    }
}

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}