#include <stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i = 0; i <= n; i++)
    {
        sum += i;
    }
    printf("\n%d",sum);
    return 0;
}