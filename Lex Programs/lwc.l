%{
	#include<stdio.h>
	#include<string.h>
	int cl=0,cw=0,cc=0,l;
%}

%%
[a-zA-Z]+ {cw++;l=strlen(yytext);cc=cc+l;} 
[\n] {cl++;}
[.] { }
%% 
int main()
{
	yylex();
	printf("character count: %d \n",cc);
	printf("word count: %d \n",cw); 
	printf("line count: %d \n",cl); 
	return 0;
}


/*
Output
hai hello
good day
hi
character count: 17 
word count: 5 
line count: 3

*/
