%{
    #include<stdio.h>
    #include<ctype.h>
    #include<string.h>
    #include<unistd.h>

    char production[10][10];
    int n;
    int i;

    void findFirst(char c);
%}

%%
[a-zA-Z=+#*()]+ {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter Productions (A=BC): ");
    for(i=0; i<n; i++)
    scanf("%s", production[i]);

    printf("\nFIRST sets: \n");
    for( i=0; i<n; i++) {
        printf("FIRST(%c) = { ", production[i][0]);
        findFirst(production[i][0]);
        printf("}\n");
        }
    }
    \n return 0;
%%

    void findFirst(char c) {
        int i;
        if(!isupper(c)) {
            printf("%c",c);
            return;
        }

        for(i=0; i<n; i++){
            if(production[i][0] == c){
                char ch= production[i][2];

                if(ch == '#'){
                    printf("#");
                }
                else if(!isupper(ch)){
                    printf("%c", ch);
                }
                else {
                    findFirst(ch);
                }
            }
        }
    }

int main(){
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}