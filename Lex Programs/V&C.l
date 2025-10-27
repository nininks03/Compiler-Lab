%{
#include<stdio.h>
int v_count=0;
int c_count=0;
%}
%%
[aeiouAEIOU] {v_count++;}
[a-zA-Z] {c_count++;}
. {}
%%
int main()
{
yylex();
printf("Number of vowels = %d ",v_count);
printf("Number of consonants = %d ",c_count);
return 0;
} 


/*
Output
AdhgEG

Number of vowels = 2 
Number of consonants = 4 
*/
