%{
	#include<stdio.h> 
	int a,i,flag=0;
%}
%%
[0-9]+ {a=atoi(yytext);
if (a==1)
{
printf("neither prime nor composite");
break;}
for (i=2;i<a;i++) 
{ 
if(a%i==0) 
{
flag=1;break;
}}
}
%%
int main()
{
yylex();
if (flag==1){
printf("Not prime");
}
else{
printf("Prime"); 
}
}


/*
Output
1)
13
Prime

2)
8
Not prime
*/
