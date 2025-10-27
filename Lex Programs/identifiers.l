%{
#include<stdio.h>
#include<string.h> 
%}
%% 
int|float|char|if|else|for|while|return|void {printf("");}
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier : %s \n",yytext);} 
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
int a,k;
Identifier : a 
Identifier : k 
*/
