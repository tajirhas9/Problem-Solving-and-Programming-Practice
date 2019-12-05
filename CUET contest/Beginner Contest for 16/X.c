#include <stdio.h>
int main()
{
    int n,i,t,j,high=0,low=0;
    int ara[50];
    for(i = 0; i < 50; i++)
    {
        ara[i] = 0;
    }
    scanf("%d",&t);
    if(t < 30)
    {
        for(j = 1; j <= t; j++)
        {
            scanf("%d",&n);
            if(n > 0 && n < 50)
            {
                for(i = 0; i < n; i++)
                {
                    scanf("%d",&ara[i]);
                    if(ara[i] > 10)
                    {
                        return 0;
                    }
                }

                for(i = 0;i < n-1; i++)
                {
                    if(ara[i+1]- ara[i] >0)
                    {
                        high++;
                    }
                    else if(ara[i+1] - ara[i] < 0)
                    {
                        low++;
                    }
                }
                printf("Case %d: %d %d\n",j,high,low);
                high = 0;
                low = 0;
            }
            else
            {
                return 0;
            }

        }
    }
    return 0;
}
