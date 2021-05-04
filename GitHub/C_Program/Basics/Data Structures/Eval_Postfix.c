#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 50
int top =-1;
char s[SIZE];
void push(int);
int pop(void);

int main()
{
    int i=0,a,b;
    char ch, postfix[50];
    system("clear");
    printf("Enter the Value of Postfix Expression");
    scanf("%s",postfix);
   
    while((ch=postfix[i++])!='\0')
    {
        if(isdigit(ch))
        {
            printf("%c",ch);
            push(ch-'0');
        }
        else if(ch== '+' ||ch== '-' ||ch== '*' ||ch== '/' )
        {
            b=pop();
            a=pop();
            switch(ch)
            {
                case '+': push(a+b);
                break;
                case '-': push(a-b);
                break;
                case '*': push(a*b);
                break;
                case '/': push(a/b);
                break;
            }
        }
    }
    printf("\n Result =%d \n \n ",s[top]);
    return(0);    
}

void push(int ele)
{
    if(top>= SIZE -1)
    {
        printf("stack overflow");
        return;
    }
    else
    {
        top=top+1;
        s[top]=ele;
    }
}

int pop()
{
    int ele;
    if(top<0)
    {
        printf("stack underflow");

    }
    else{
        ele=s[top];
        top=top-1;
        return(ele);
    }
}