%{
#include<stdio.h>
#include<string.h> 
%}
%% 
int|float|char|if|else|for|while|return|void {printf("Keyword : %s \n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* { printf("");} 
. { }
%%
int main()
{
printf("Enter source code:\n");
yylex();
return 0;
}

/*
Output
Enter source code:
int a;float b;
Keyword : int 
Keyword : float 
*/
