#include <stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i = 1;i <= n;i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        for(k = i+1; k <= n-1;k++)
        {
            printf(" ");
        }
        for(j = 1; j <= i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=1; i <= n; i++)
    {
        for(j = n; j >= i; j--)
        {
            printf("*");
        }
        for(k = i+1; k <= n-1;k++)
        {
            printf(" ");
        }
        for(j = n; j >= i;j--)
        {
            printf("*");
        }
        printf("\n");
    }
}
