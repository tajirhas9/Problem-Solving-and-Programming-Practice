#include <stdio.h>
int main()
{
    int n,a,b,c,i;
    scanf("%d",&n);
    if(n >= 1 && n <= 100)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if((a >= 1 && a <= 50) && (b >= 1 && b <= 50) && (c >= 1 && c <= 50))
            {
                if(a > 20 || b > 20 || c > 20)
                {
                    printf("Case %d: bad\n",i);
                }
                else
                {
                    printf("Case %d: good\n",i);
                }
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
