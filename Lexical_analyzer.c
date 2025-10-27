#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int is_digit(char ch){
	if(ch >= '0' && ch <= '9')
		return 1;
	return 0;
}
int is_letter(char ch){
	if(ch <= 'Z' && ch >= 'A')
		return 1;
	if(ch <= 'z' && ch >= 'a')
		return 1;
	return 0;
}
int is_symbol(char ch){
	if(ch == ';' || ch == '{' || ch == '}')
		return 1;
	if(ch == ',' || ch == '(' || ch == ')')
		return 1;
	return 0;
}
int search(char word[20],char keywords[20][10]){
	for(int i = 0;i<20;i++){
		if(strcmp(word,keywords[i]) == 0)
			return 1;
	}
	return 0;
}
int main(){
	FILE *fp=fopen("input.txt","r");
	char carray[20];
	char keywords[20][10] = {"int","float","main","if","for","while","else","char","printf","return"};
	char ch = fgetc(fp);
	int state = 0, i;
	while(ch != EOF){
		switch(state){
			case 0: memset(carray,0,20);
				i = 0;
				carray[i++] = ch;
				if(ch == '<')
					state = 1;
				else if(ch == '>')
					state = 5;
				else if(ch == '=')
					state = 8;
				else if(is_letter(ch))
					state = 10;
				else if(is_digit(ch))
					state = 22;
				else if(ch == '+')
					state = 12;
				else if(ch == '-')
					state = 15;
				else if(ch == '*'){
					state = 0;
					printf("Operator : *\n");
				}
				else if(ch == '/'){
					state = 30; 
				}
				else if(ch == '%'){
					state = 0;
					printf("Operator : %\n");
				}
				else if(is_symbol(ch)){
					state = 0;
					printf("Symbol : %c\n",ch);
				}break;
			case 1:if(ch == '='){
					state = 0;
					printf("Operator : <=\n");
				}
				else if(ch == '>'){
					state = 0;
					printf("Operator : <>\n");
				}
				else{
					state = 0;
					printf("Operator : <\n");
					continue;
				}break;
			case 5:if(ch == '='){
					state = 0;
					printf("Operator : >=\n");
				}
				else{
					state = 0;
					printf("Operator : >\n");
					continue;
				}
				break;
			case 8:if(ch == '='){
					state = 0;
					printf("Operator : ==\n");
				}
				else{
					state = 0;
					printf("Operator : =\n");
					continue;
				}
				break;
			case 10:if(is_letter(ch) || is_digit(ch)){
					if(i == 19)
						break;
					carray[i++] = ch;
				}
				else{
					carray[i] = '\0';
					if(search(carray,keywords))
						printf("Keyword :%s\n",carray);
					else
						printf("Identifier :%s\n",carray);
					state = 0;
					continue;
				}
				break;
			case 12:if(ch == '+'){
					state = 0;
					printf("Operator : ++\n");
				}
				else{
					state = 0;
					printf("Operator : +\n");
					continue;
				}
				break;
			case 15:if(ch == '-'){
					state = 0;
					printf("Operator : --\n");
				}
				else{
					state = 0;
					printf("Operator : -\n");
					continue;
				}break;
			case 22:if(is_digit(ch)){
					if(i == 19)
						break;
					carray[i++] = ch;
				}
				else{
					carray[i] = '\0';
					printf("Constant :%s\n",carray);
					state = 0;
					continue;
				}break;
		                case 30:  if(ch == '/') { 
					while(ch != '\n' && ch != EOF) {
						ch = fgetc(fp);
					} 
				} 
				
			        else if(ch == '*') {  
					while(ch != '/' && ch != EOF) 
					{
						ch = fgetc(fp);
					}   
				} 
				else { 
					printf("Operator : /\n"); 
				}
				state=0;break;
		}
		ch = fgetc(fp);
	}
}



/*
input.txt

int a=100,b=20;
int c=a/(b+2);
/*check condition*/
if(c>5){
//multiple and return 
return a*b;
}

Output
Keyword :int
Identifier :a
Operator : =
Constant :100
Symbol : ,
Identifier :b
Operator : =
Constant :20
Symbol : ;
Keyword :int
Identifier :c
Operator : =
Identifier :a
Operator : /
Identifier :b
Operator : +
Constant :2
Symbol : )
Symbol : ;
Keyword :if
Symbol : (
Identifier :c
Operator : >
Constant :5
Symbol : )
Symbol : {
Keyword :return
Identifier :a
Operator : *
Identifier :b
Symbol : ;
Symbol : }
*/
