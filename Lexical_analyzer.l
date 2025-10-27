%{
#include<stdio.h>
#include<string.h>
int isKeyword(char * word)
{
const char * keywords[]={"int","float","char","if","else","for","while","return","void"};
int i;
for(i=0;i<sizeof(keywords)/sizeof(keywords[0]);i++)
{
if(strcmp(word,keywords[i])==0)
return 1;
}
return 0;
}
%}
%%
[\t\n];
[0-9]+(\.[0-9]+)? { printf("Number: %s \n",yytext);  }
[a-zA-Z_][a-zA-Z0-9_]* {
if (isKeyword(yytext))
printf("keyword:%s \n",yytext);
else
printf("Identifier : %s \n",yytext);
}
"=="|"!="|">="|"<="|"<"|">"|"="|"+"|"-"|"*"|"/" {
printf("operator :%s \n",yytext);
}
[{}();] {
printf("symbol: %s \n",yytext);
}
"//"[a-zA-Z0-9_ ]* { }
"/*"[a-zA-Z0-9_ ]*"*/" { }
"/**"[a-zA-Z0-9_ ]*"*/" { } 
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
int ab,b;
a = 10;
//helo
b = a + 10 ;
/* check */
if ( a >= b ) {
	printf ( " Hello " ) ;
}


keyword:int
Identifier : ab
Identifier : b
symbol: ;
Identifier : a
operator :=
Number: 10
symbol: ;
Identifier : b
operator :=
Identifier : a
operator :+
Number: 10
symbol: ;
keyword:if
symbol: (
Identifier : a
operator :>=
Identifier : b
symbol: )
symbol: {
Identifier : printf
symbol: (
Identifier : Hello
symbol: )
symbol: ;
symbol: }
*/
