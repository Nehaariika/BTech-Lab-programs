#include<stdio.h>
#include<string.h>

int main(){
    int n,i;
    char rule[100];
    int inherited =0;
    int invalid =0;

    printf("Enter number of semantic rules: ");
    scanf("%d",&n);
    getchar();

    printf("\nEnter semantic rules:\n");

    for(i=0;i<n;i++) {
        fgets(rule,sizeof(rule),stdin);

        if(strstr(rule,".in") != NULL) {
            inherited=1;

            if(strstr(rule,"right") != NULL){
                invalid =1;
            }
        }
    }
    printf("\nResult:\n");

    if(inherited ==0){
        printf("The SDT is S-Attributed.\n");
    }
    else if(invalid ==0) {
        printf("The SDT is L-Attributed.\n");
    }
    else{
        printf("The SDT is neither S-Attributed nor L-Attributed.\n");
    }
    return 0;
}

