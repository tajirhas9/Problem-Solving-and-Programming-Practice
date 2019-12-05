#include <stdio.h>
int main()
{
    int i,n,a,b;
    scanf("%d",&n);
    if(n > 125)
    {
        return 0;
    }
    for(i = 1; i <= n;i++)
    {
        scanf("%d %d",&a,&b);
        if((a >= 0 && a <= 10) && (b >= 0 && b <= 10))
        {
            printf("Case %d: %d\n",i,(a+b));
        }
    }
    return 0;
}
