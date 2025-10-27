%{
	#include<stdio.h>
	int capc=0,digc=0;
%}

%% 
[A-Z] {capc++;} 
[0-9] {digc++;}
. {}
%% 
int main()
{
	yylex(); 
	printf("Capital count: %d \n",capc);
	printf("Digit count: %d \n",digc); 
}

/*
Output
ABcd342f45E

Capital count: 3 
Digit count: 5 
*/
