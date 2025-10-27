#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
char prod[MAX][MAX];
char nt[MAX], firstSet[MAX][MAX], followSet[MAX][MAX];
int n, ntCount = 0;
void add(char s[MAX][MAX], int i, char c) {
    if (strchr(s[i], c) == NULL) {
        int l = strlen(s[i]);
        s[i][l] = c;
        s[i][l + 1] = '\0';
    }
}
int indexOf(char c) {
    for (int i = 0; i < ntCount; i++)
        if (nt[i] == c) return i;
    return -1;
}
void findFirst(char c, int k) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c){
            char *rhs = strchr(prod[i], '=') + 1;
            if (!isupper(rhs[0]))        
                add(firstSet, k, rhs[0]);
            else if (rhs[0] == '#')
                add(firstSet, k, '#');
            else {
                int x = indexOf(rhs[0]);
                if (x != -1) findFirst(rhs[0], k);
            }
        }
    }
}
void findFollow(char c, int k) {
    if (c == nt[0])
         add(followSet, k, '$');
    for (int i = 0; i < n; i++) {
        char *rhs = strchr(prod[i], '=') + 1;
        	for (int j = 0; rhs[j]; j++) {
            if (rhs[j] == c) {
                if (rhs[j + 1] != '\0'){
                    if (!isupper(rhs[j + 1]))      
                          add(followSet, k, rhs[j + 1]);
                    else{
                        int x = indexOf(rhs[j + 1]);
                        for (int p = 0; firstSet[x][p]; p++) {
                            if (firstSet[x][p] != '#')
                                add(followSet, k, firstSet[x][p]);
                        }
                        if (strchr(firstSet[x], '#')) {    // epsilon case
                            int A = indexOf(prod[i][0]);
                            if (A != -1) 
                                findFollow(prod[i][0], k);
                            for (int p = 0; followSet[A][p]; p++)
                                add(followSet, k, followSet[A][p]);
                        }
                    }
                } else if (prod[i][0] != c) {     // at end
                    int A = indexOf(prod[i][0]);
                    if (A != -1) 
                        findFollow(prod[i][0], k);
                    for (int p = 0; followSet[A][p]; p++)
                        add(followSet, k, followSet[A][p]);
                }
            }
        }
    }
}
int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (e.g. E=E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
        if (indexOf(prod[i][0]) == -1)
            nt[ntCount++] = prod[i][0];
    }
    for (int i = 0; i < ntCount; i++)
        firstSet[i][0] = followSet[i][0] = '\0';
    for (int i = 0; i < ntCount; i++) 
        findFirst(nt[i], i);
    for (int i = 0; i < ntCount; i++) 
        findFollow(nt[i], i);
    printf("\n--- FIRST sets ---\n");
    for (int i = 0; i < ntCount; i++) {
        printf("FIRST(%c) = { ", nt[i]);
        for (int j = 0; firstSet[i][j]; j++) 
            printf("%c, ", firstSet[i][j]);
        printf("}\n");
    }
    printf("\n--- FOLLOW sets ---\n");
    for (int i = 0; i < ntCount; i++) {
        printf("FOLLOW(%c) = { ", nt[i]);
        for (int j = 0; followSet[i][j]; j++) 
            printf("%c, ", followSet[i][j]);
        printf("}\n");    }
}



/*
OUTPUT 

Enter number of productions: 5
Enter the productions (e.g. E=E+T):
S=Aa
A=BD
B=b
D=d
D=#

--- FIRST sets ---
FIRST(S) = { b, }
FIRST(A) = { b, }
FIRST(B) = { b, }
FIRST(D) = { d, #, }

--- FOLLOW sets ---
FOLLOW(S) = { $, }
FOLLOW(A) = { a, }
FOLLOW(B) = { d, a, }
FOLLOW(D) = { a, }

*/
