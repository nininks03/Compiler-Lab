#include <stdio.h>
#include <string.h>
struct Expression {
    char result[10];
    char op1[10];
    char op2[10];
    char op;
} expr[20];
int main() {
    int n;
    printf("Enter number of statements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s = %s %c %s", expr[i].result, expr[i].op1, &expr[i].op, expr[i].op2);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int redefined = 0;
            for (int k = i + 1; k < j; k++) {
                if (strcmp(expr[k].result, expr[i].op1) == 0 || strcmp(expr[k].result, expr[i].op2) == 0)
{
                    redefined = 1;
                    break;
                }
            }
            if (redefined) continue;
            if (expr[i].op == expr[j].op &&
                ((strcmp(expr[i].op1, expr[j].op1) == 0 && strcmp(expr[i].op2, expr[j].op2) == 0) ||
                 (strcmp(expr[i].op1, expr[j].op2) == 0 && strcmp(expr[i].op2, expr[j].op1) == 0))) {
                strcpy(expr[j].op1, expr[i].result);
                strcpy(expr[j].op2, "");
                expr[j].op = '\0';
            }
        }
    }
    printf("\nAfter Common Subexpression Elimination:\n");
    for (int i = 0; i < n; i++) {
        if (expr[i].op != '\0')
            printf("%s = %s %c %s\n", expr[i].result, expr[i].op1, expr[i].op, expr[i].op2);
        else
            printf("%s = %s\n", expr[i].result, expr[i].op1);
    }
    return 0;
}


/*
OUTPUT:
Enter number of statements: 3
c = a + b
l = m + n
k = a + b

After Common Subexpression Elimination:
c = a + b
l = m + n
k = c

*/
