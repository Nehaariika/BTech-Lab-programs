#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, m = 0, prodCount = 0;
char a[20][20], f[20];

void follow(char c);
void first(char c);

int main() {
    int i;
    char input[100], *token;
    printf("Enter the number of production Numbers: ");
    scanf("%d", &n);
    getchar();
    printf("Enter the productions(e.g S=Ab|a) :\n");

    for (i = 0; i < n; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 

        char lhs = input[0]; 
        char *rhs = strchr(input, '=');
        if (!rhs) continue;
        rhs++;

        token = strtok(rhs, "|");
        while (token != NULL) {
            a[prodCount][0] = lhs;
            a[prodCount][1] = '=';
            strcpy(&a[prodCount][2], token);
            prodCount++;
            token = strtok(NULL, "|");
        }
    }

    
    char done[20] = "";
    int doneCount = 0;

    for (i = 0; i < prodCount; i++) {
        char c = a[i][0];
        int alreadyDone = 0,k,p;
        for ( k = 0; k < doneCount; k++) {
            if (done[k] == c) {
                alreadyDone = 1;
                break;
            }
        }
        if (!alreadyDone) {
            m = 0;
            follow(c);
            printf("Follow(%c) = { ", c);
            for ( p = 0; p < m; p++)
                printf("%c ", f[p]);
            printf("}\n");
            done[doneCount++] = c;
        }
    }

    return 0;
}

void follow(char c) {
	int i, j;
    if (a[0][0] == c)
        f[m++] = '$';

    for (i = 0; i < prodCount; i++) {
        for ( j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0') {
                    first(a[i][j + 1]);
                }
                if (a[i][j + 1] == '\0' && c != a[i][0]) {
                    follow(a[i][0]);
                }
            }
        }
    }
}

void first(char c) {
    if (!isupper(c)) {
        f[m++] = c;
    }  
    int k;
    for ( k = 0; k < prodCount; k++) {
        if (a[k][0] == c) {
            if (a[k][2] == '$') {
                follow(a[k][0]);
            } else if (!isupper(a[k][2])) {
                f[m++] = a[k][2];
            } else {
                first(a[k][2]);
            }
        }
    }
}





















