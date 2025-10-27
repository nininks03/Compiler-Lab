#include<stdio.h>
#include<string.h>
int z = 0, k = 0, i = 0, j = 0, length = 0;
char a[16], ac[20], stk[15], act[10];
void check();
int c=1;
void main() {
        printf("\tGrammer : \n \tE -> E + E \n \tE -> E * E \n \tE -> id\n \tE -> (E)");
        printf("\nInput : ");
        scanf("%s", a);
        printf("\n");
        length = strlen(a);
        strcpy(act, "SHIFT");
        printf("Stack\t Input \t Action");
        printf("\n$%s\t%s$\t%s", stk, a);
        for (i = 0; j < length; i++, j++) {
                if (a[j] == 'i' && a[j + 1] == 'd') {
                        stk[i] = a[j];
                        stk[i + 1] = a[j + 1];
                        stk[i + 2] = '\0';
                        a[j] = ' ';
                        a[j + 1] = ' ';
                        c=c+1;
                        printf("\n$%s\t%s$\t%s", stk, a, act);
                        check();
                }
                 else {
                        stk[i] = a[j];
                        stk[i + 1] = '\0';
                        a[j] = ' ';
                        printf("\n$%s\t%s$\t%s", stk, a, act);
                        c=c+1;
                        check();
                }
        }
        if (stk[0] == 'E' && stk[1] == '\0')
                printf("\n\nString Accepted\n");
        else
                printf("\n\nString Rejected\n");
}
void check() {
        for (z = 0; stk[z] != '\0'; z++) {
                if (stk[z] == 'i' && stk[z + 1] == 'd') {
                        strcpy(ac, "REDUCE (E->id)");
                        stk[z] = 'E';
                        stk[z + 1] = '\0';
                        printf("\n$%s\t%s$\t%s", stk, a, ac);
                        j++;
                        c=c+1;
                }
        }
        for (z = 0; z < strlen(stk); z++) {
                if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
                        strcpy(ac, "REDUCE (E->E*E)");
                        stk[z] = 'E';
                        stk[z + 1] = '\0';
                        printf("\n$%s\t%s$\t%s", stk, a, ac);
                        i = i - 2;
                        c=c+1;
                }
        }
        if(c==10)
        {
        for (z = 0; z < strlen(stk); z++) {
                if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E' ) {
                        strcpy(ac, "REDUCE (E->E+E)");
                        stk[z] = 'E';
                        stk[z + 1] = '\0';
                        printf("\n$%s\t%s$\t%s", stk, a, ac);
                        i = i - 2;
                }
        }
        }
}




/*
OUTPUT
Grammer : 
 	E -> E + E 
 	E -> E * E 
 	E -> id
 	E -> (E)
Input : id+id*id

Stack	 Input                 Action
$	id+id*id$	(null)
$id	  +id*id$	SHIFT
$E	  +id*id$	REDUCE (E->id)
$E+	   id*id$	SHIFT
$E+id	     *id$		SHIFT
$E+E	     *id$		REDUCE (E->id)
$E+E*	      id$		SHIFT
$E+E*id        $	 	SHIFT
$E+E*E        $		REDUCE (E->id)
$E+E	         $		REDUCE (E->E*E)
$E	         $		REDUCE (E->E+E)

String Accepted

*/
