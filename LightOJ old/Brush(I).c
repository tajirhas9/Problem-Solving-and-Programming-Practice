#include <stdio.h>
int main()
{
    int t,n,i,j,sum=0,a;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1; j<= n; j++)
        {
            scanf("%d",&a);
            if(a >= 0)
                sum += a;
        }
        printf("Case %d: %d\n",i,sum);
        sum = 0;
    }
    return 0;
}
