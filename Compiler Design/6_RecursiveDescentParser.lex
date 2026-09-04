%{
    #include<stdio.h>
    #include <string.h>

    int i = 0;
    char input[100];

    void E();
    void Eprime();
    void T();
    void Tprime();
    void F();

    void match(char c){
        if (input[i] == c){
            i++;
        } else {
            printf("Invalid Expression\n");
        }
    }
%}

%%

[a-zA-Z0-9\+\*\(\)]+    {
    strcpy(input, yytext);
    i = 0;
    E();
    if (input[i] == '\0')
    printf("Valid Expression\n");
    elseprintf("Invalid Expression\n");
}
\n return 0;

%%

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[i] == '*') {
        match('*');
        F();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[i] == '*') {
        match('*');
        F();
        Tprime();
    }
}

void F() {
    if (input[i] == '(') {
        match('(');
        E();
        match(')');
    }
    else if (isalnum(input[i])) {
        i++;
    }
    else {
        printf("Invalid Expression\n");
    }
}

int main(){
    printf("Enter Expression:");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
