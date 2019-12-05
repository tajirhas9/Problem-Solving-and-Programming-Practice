#include <stdio.h>
int main()
{
    int i,t,n;
    scanf("%d",&t);
    for(i = 0; i < t; i++)
    {
        scanf("%d",&n);
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        if(n > 0)
        {
            printf("%d\n", (n/10)%10);
        }
        else
        {
            printf("%d\n", (-n/10)%10);
        }
    }
    return 0;
}
