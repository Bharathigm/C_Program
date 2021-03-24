#include <stdio.h>

int main()
{
        int a[100],i,j,n=100;
        printf("initially all doors are closed");
        for(i=1;i<=n;i++)
        {
            a[i]=0;
        }
        
        for(i=1;i<=n;i++)
        {
            a[i]=1;
        }
        for(i=1;i<=n;i++)
        {
            printf("Iternation 1=");      
            printf("\n%d=%d ",i, a[i]);
        }
     for(i=2;i<=n;i++)
       {
         for(j=i;j<=n;)
         {
            printf("\n");
            printf("Iternation %d=",i);
             if(a[j]==1)
             {
                 a[j]=0;
                  printf("%d=%d ",j, a[j]);
             }
             else
             {
                 a[j]=1;
                 printf("%d=%d ",j, a[j]);
             }
                     j=i*j;
             }
             
           
         }
         printf("\n");
          for(i=1;i<=n;i++)
        {
            printf("\n%d=%d ",i, a[i]);
        }
         
}