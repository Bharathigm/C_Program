/* Program to Print the length of the given string using user defined function and 
while loop        */

#include<stdio.h>
int main()
{
    char ch[10]="Mysore";
    int len=0;
    while(ch[len]!='\0')
    {
        len++;
    }
    printf("String Length = %d\n",len);
}