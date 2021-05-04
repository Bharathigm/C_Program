/* Program to Print the length of the given string using user defined function and 
for loop        */

#include<stdio.h>
int main()
{
    char ch[10]="Mysore";
    int len=0,i;
    for(i=0;ch[i]!='\0';i++)
    {
        len++;
    }
    printf("String Length = %d\n",len);
}