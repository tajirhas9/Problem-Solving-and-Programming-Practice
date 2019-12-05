#include <stdio.h>
int main()
{
    long long int n,x,i,x1=1,x2=1,reverse,r;
    int t,k,count,binary[3] = {0,0,0};
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            x1 *=2;
        printf("x1=%lld\n",x1);
        for(i=1;i<=(n-(n-1));i++)
            x2 *= 2;
        printf("x2=%lld\n",x2);
        x = x1-x2;
        printf("nTOx=%lld\n",x);
        i=0;
        count=1;
        while(x>0)
        {
            binary[i] = x%2;
            x /= 2;
            printf("%lld\n",x);
            count++;
            i++;
            if(count>3)
                break;
        }
        printf("%lld ",n);
        for(i=2;i>=0;i--)
            printf("%d",binary[i]);
        printf("\n");
        x1=1;
        x2=1;
    }
    return 0;
}
