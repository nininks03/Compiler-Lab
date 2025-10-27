%{
	#include<stdio.h> 
	int a ;
%}

%%

[0-9]+ {a=atoi(yytext);
if(a%2==0) 
{printf("even number");}
else 
{printf("Odd number");}
}
[.] { }
%%

int main()
{
yylex(); 
}

/*
Output
8
even number
23
Odd number
*/
