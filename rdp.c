#include<stdio.h>
#include<ctype.h>
#include<string.h>
char input[100];
int i;
int E();
int EE();
int T();
int TT();
int F();
void main()
{
    printf("\nEnter the string to be checked:");
    scanf("%s", input);
    if (E())
    {
        if (input[i + 1] == '\0')
            printf("\nString is accepted");
        else
            printf("\nString is not accepted");
    }
    else
        printf("\nString not accepted");
}
int E()
{
    if (T())
    {
        if (EE())
            return (1);
        else
            return (0);
    }
    else
        return (0);
}
int EE()
{
    if (input[i] == '+'||input[i] == '-')
    {
        i++;
        if (T())
        {
            if (EE())
                return (1);
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}
int T()
{
    if (F())
    {
        if (TT())
            return (1);
        else
            return (0);
    }
    else
        return (0);
}
int TT()
{
    if (input[i] == '*'||input[i] == '/')
    {
        i++;
        if (F())
        {
            if (TT())
                return (1);
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}
int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else if (input[i] == 'i' )
    {
    	i++;
    	if(input[i]=='d'){
    		i++;
	        return (1);
    	}        
    }
    else
        return (0);
}


/*
Output
1.
Enter the string to be checked:id+id

String is accepted
2.
Enter expression : l+l
lsyntax error
*/
