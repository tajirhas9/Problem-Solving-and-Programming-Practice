#include <stdio.h>
int main()
{
    int t,n,i,k,p,j;
    scanf("%d",&t);
    if(t <= 1000)
    {
        for(j = 1; j <= t; j++)
        {
            scanf("%d %d %d",&n,&k,&p);
            if((n >= 2 && n <= 23 ) && (k >= 1 && k <= n) && (p >= 1 && p <= 200))
            {
                for(i = 1; i <= p; i++)
                {
                    k++;
                    if(k > n)
                    {
                        k = 1;
                    }
                }
                printf("Case %d: %d\n",j,k);
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
