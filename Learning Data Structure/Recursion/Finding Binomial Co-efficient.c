/*
*The triangle is not complete
*/
#include <stdio.h>
int factorial(int n);
int binomial_coefficient(int n,int r);
int main()
{
    int j,n,r,i,k;
    scanf("%d %d",&n,&r);
    for(j=0;j<=n;j++)
    {
        if(j%2 != 0)
        {
            for(k=1;k<=((n-j)/2)+1;k++)
                printf("  ");
            for(i=0;i<=j;i++,k++)
            {
                printf("%d ",binomial_coefficient(j,i));
            }
        }
        else
        {
            for(k=1;k<=((n-j)/2);k++)
                printf(" ");
            for(i=0;i<=j;i++,k++)
            {
                printf("%d ",binomial_coefficient(j,i));
            }
        }
        printf("\n");
    }
    return 0;
}
int factorial(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return (n*factorial(n-1));
}
int binomial_coefficient(int n,int r)
{
    return factorial(n)/((factorial(r)*factorial(n-r)));
}
