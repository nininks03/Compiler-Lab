%{
	#include<stdio.h>
	int countn=0,countp=0;
%}

%%

"+"[0-9]+ {countp++;}
"-"[0-9]+ {countn++;}
"--"+[0-9]+ {printf(" %s Invalid input \n",yytext);}
[.] { printf(" %s Invalid input \n",yytext);}
%%

int main()
{
yylex();
printf("Negative numbers: %d \n ",countn);
printf("Positive numbers: %d \n ",countp);
}

/*
Output
-9 67 -5 --9 4
    --9 Invalid input 
 
Negative numbers: 2 
Positive numbers :2 

*/
