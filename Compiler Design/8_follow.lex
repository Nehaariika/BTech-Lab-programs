%{
    #include<stdio.h>
    #include<ctype.h>
    #include<string.h>

    char productions[10][10];
    char follow[10];
    int n;

    void findFollow(char c);
    void addToResult(char);
    int i;
%}

%%
\n {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter Productions (A=BC, # for epsilon): \n");
    for(i=0; i<n; i++)
    scanf("%s", productions[i]);

    printf("\nFOLLOW sets: \n");

    for( i=0; i<n; i++) {
        printf("FOLLOW(%c) = { ", productions[i][0]);
        findFollow(productions[i][0]);
        printf("}\n");
        }
    }
%%

void findFollow(char c) {
    int j, k;

    //Rule 1: Add $ to start symbol
    if(c == productions[0][0])
    printf("$");
        
    for(j=0; j<n; j++){
        for(k=2; k<strlen(productions[j]);
        k++) {
            if(productions[j][k+1] !='\0') {

                //If terminal
                if(! isupper(productions[j][k+1])) {
                    printf("%c ", productions[j][k+1]);
                }
                // If non-terminal
                else {
                    char next = productions[j][k+1];
                    int x; 
                    for(x=0; x<n; x++) {
                            if(productions[x][0] == next) {
                                char ch = productions[x][2];
                                if(ch !='#')
                                printf("%c", ch);
                            }
                        }
                    }
                }
                //If at end
                else {
                    if(productions[j][0] !=c)
                    findFollow(productions[j][0]);
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