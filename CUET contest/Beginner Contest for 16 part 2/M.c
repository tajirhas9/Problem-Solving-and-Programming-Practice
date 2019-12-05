#include <stdio.h>
int main()
{
    int test,n,p,q,i=0,total=0,j,k=0;
    int egg;
    scanf("%d",&test);
    for(i = 1; i <= test; i++)
    {
        scanf("%d %d %d",&n,&p,&q);
        for(j = 1; j <= n; j++)
        {
            scanf("%d",&egg);
            if(j <= p && total <= q)
            {
                total += egg;
                k++;
                if(total > q)
                {
                    k--;
                }
            }
        }
        printf("Case %d: %d\n",i,k);
        k = 0;
        total = 0;
    }

    return 0;
}
