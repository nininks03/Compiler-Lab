#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
int tmpCount = 0; 
int precedence(char op) { 
    switch (op) { 
        case '=': return 0; 
        case '+': 
        case '-': return 1; 
        case '*': 
        case '/': return 2; 
        case '^': return 3; 
        default: return -1; 
    } 
} 
void infixToPostfix(char* expr, char* postfix) { 
    char stack[100]; 
    int top = -1, k = 0;  
    for (int i = 0; expr[i]; i++) { 
        if (isalnum(expr[i])) { 
            postfix[k++] = expr[i]; 
        }  
        else if (expr[i] == '(') { 
            stack[++top] = expr[i]; 
        }  
        else if (expr[i] == ')') { 
            while (top != -1 && stack[top] != '(') { 
                postfix[k++] = stack[top--]; 
            } 
            top--; 
        }  
        else { 
            while (top != -1 && 
                  ((expr[i] != '^' && precedence(stack[top]) >= precedence(expr[i])) || 
                   (expr[i] == '^' && precedence(stack[top]) > precedence(expr[i])))) { 
                postfix[k++] = stack[top--]; 
            } 
            stack[++top] = expr[i]; 
        } 
    } 
    while (top != -1) { 
        postfix[k++] = stack[top--]; 
    } 
    postfix[k] = '\0'; 
} 
void generateThreeAddressCode(char* postfix) { 
    char stack[100][10]; 
    int top = -1; 
    char result[10]; 
    char threeAddr[100][50]; 
    int codeIndex = 0; 
    printf("Postfix Expression: %s\n\n", postfix); 
    printf("Intermediate Code (Quadruples):\n"); 
    printf("%-9s %-9s %-9s %-9s\n", "Op", "Arg1", "Arg2", "Result"); 
    printf("----------------------------------------------\n"); 
    for (int i = 0; postfix[i] != '\0'; i++) { 
        if (isalnum(postfix[i])) { 
            stack[++top][0] = postfix[i]; 
            stack[top][1] = '\0'; 
        } else { 
            if (postfix[i] == '=') { 
                char rhs[10], lhs[10]; 
                strcpy(rhs, stack[top--]); 
                strcpy(lhs, stack[top--]); 
                printf("%-9c %-9s %-9s %-9s\n", '=', rhs, "", lhs); 
                sprintf(threeAddr[codeIndex++], "%s = %s", lhs, rhs); 
            } else { 
                char arg2[10], arg1[10]; 
                strcpy(arg2, stack[top--]); 
                strcpy(arg1, stack[top--]); 
                sprintf(result, "T%d", tmpCount++); 
                printf("%-9c %-9s %-9s %-9s\n", postfix[i], arg1, arg2, result); 
                sprintf(threeAddr[codeIndex++], "%s = %s %c %s", result, arg1, postfix[i], arg2); 
                strcpy(stack[++top], result); 
            } 
        } 
    }  
    printf("\n\nThree Address Code:\n"); 
    for (int i = 0; i < codeIndex; i++) { 
        printf(" %s\n", threeAddr[i]); 
    } 
} 
int main() { 
    char expr[100], postfix[100];  
    printf("Enter an infix expression: "); 
    scanf("%99s", expr);  
    tmpCount = 0; 
    infixToPostfix(expr, postfix); 
    generateThreeAddressCode(postfix); 
    printf("\n"); 
    return 0; 
} 


/*
OUTPUT:
Enter an infix expression: c=a*b+d
Postfix Expression: cab*d+=

Intermediate Code (Quadruples):
Op        Arg1      Arg2      Result   
----------------------------------------------
*         a         b         T0       
+         T0        d         T1       
=         T1                  c        


Three Address Code:
 T0 = a * b
 T1 = T0 + d
 c = T1

*/
