%{
	#include<stdio.h> 
	int a,sum,r,l,m,n,i,f;
%}
%%
[0-9]+ {
	a=atoi(yytext);
	m=a;n=a;l=0;sum=0;
	while(n>0){
	l=l+1;
	n=n/10; } 
	while(a>0)
	{
	r=a%10;
	f=1;
	for(i=0;i<l;i++)	{ f=f*r;}
	sum=sum+f;
	a=a/10;
	}
	if (sum==m)
	printf("Armstrong");
	else
	printf("not Armstrong");
}
[.] { }
%%
int main()
{ yylex(); }

/*
Output
153
Armstrong
96
not Armstrong
*/
