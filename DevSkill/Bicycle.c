#include <stdio.h>
int main()
{
    int t,i,n,j;
    long long int p1,p2=0,m1,m2=0;
    scanf("%d",&t);
    for(i=1; i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%lld %lld",&p1,&m1);
            if(j==1)
            {
                p2 = p1;
                m2 = m1;
            }
            if(p1 == p2)
            {
                if(m2 > m1)
                {
                    on_the_cart_m1 = m1;
                }
            }
            else if(p1 < p2)
            {
                p2 = p1;
                m2 = m1;
            }
            else
            {
                continue;
            }
        }
        printf("Case %d: %lld %lld\n",i,p2,m2);
        p2 = 0;
        m2 = 0;
    }
    return 0;
}
