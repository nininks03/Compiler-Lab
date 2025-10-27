%{
	#include<stdio.h> 
	int a ;
%}

%%
[0-9]+ {a=atoi(yytext);
if((a%4==0 && a%100!=0)||a%400==0) 
{printf("leap year");}
else 
{printf("not leap year");}
}
[.] { }
%%

int main()
{
yylex(); 
}

/*
Output
2024
leap year
1991
not leap year
*/
