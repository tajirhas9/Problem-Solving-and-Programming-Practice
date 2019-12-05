#include <stdio.h>
int main()
{
    int n,coins[110],i,count=0,sum=0,max,checkMax=0,coinSum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
        sum += coins[i];
    }
    count=1;
    label:
    max = 0;
    for(i=0;i<n;i++)
    {
        if(max<coins[i])
        {
            max = coins[i];
            checkMax = i;
        }
    }
    coinSum += max;
    if(coinSum <= (sum/2))
    {
        coins[checkMax] = 0;
        count++;
        goto label;
    }
    else
        printf("%d",count);
    return 0;
}
