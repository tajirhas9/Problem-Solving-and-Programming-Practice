#include <stdio.h>
int main()
{
    int i,n,a;
    scanf("%d",&n);
    if(n > 25)
    {
        return 0;
    }
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&a);
        if(a >= 0 && a <= 20)
        {
            if(a <= 10)
            {
                printf("%d %d\n",0,a);
            }
            else
            {
                printf("%d %d\n",10,a-10);
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
