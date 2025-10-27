#include <stdio.h>
#include <string.h>
void main() {
    char icode[10][30], str[20], opr[10];
    int i = 0;
    printf("\nEnter the set of intermediate code (terminated by 'exit'):\n");
    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);
    printf("\nTarget code generation");
    printf("\n**********************\n");
    i = 0;
    while (strcmp(icode[i], "exit") != 0) {
        strcpy(str, icode[i]);
        switch (str[3]) {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
            default:
                strcpy(opr, "???"); // Handle invalid operator
        }
        printf("\nMOV %c, R%d", str[2], i);
        printf("\n%s %c, R%d", opr, str[4], i);
        printf("\nMOV R%d, %c\n", i, str[0]);
        i++;
    }
}




/*
OUTPUT: 
Enter the set of intermediate code (terminated by 'exit'):
t=a+b
v=a-c
v=t+u
d=t+u
d=v+u
exit

Target code generation
**********************
MOV a, R0
ADD b, R0
MOV R0, t
MOV a, R1
SUB c, R1
MOV R1, v
MOV t, R2
ADD u, R2
MOV R2, v
MOV t, R3
ADD u, R3
MOV R3, d
MOV v, R4
ADD u, R4
MOV R4, d

*/
