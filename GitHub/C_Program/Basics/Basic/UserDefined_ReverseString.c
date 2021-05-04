/* Program to Print the Reverse of the given string using user defined function and 
while loop        */

#include<stdio.h>
int main()
{
    char ch[10]={'M','Y','S','O','R','E'};
    int len=0,i;
    while(ch[len]!='\0')
    {
        len++;
    }
    printf("String Length = %d\n",len);
    printf("Reverse String is ");
    while(len!=-1)
    {
        printf("%c",ch[len]);
    len--;
    }
    printf("\n");

}