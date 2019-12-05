#include <stdio.h>
int main()
{
    int n,i,f,c;
    float result;
    scanf("%d",&n);
    if(n >= 1 && n <= 100)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d",&c,&f);
            if((c >= 0 && c <= 100) && (f >= 0 && f <= 100))
            {
                printf("Case %d: %.2f\n",i,(c+(((float)f/180)*100)));
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
