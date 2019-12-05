#include <stdio.h>
int main()
{
    int t,n,i,j,dif,num;
    scanf("%d",&t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        if(n == 1)
            num = 0;
        else if(n == 2)
            num = 2;
        else if(n == 3)
            num = 8;
        else
        {
            num = 8;
            dif = 10;
            for(j = 4; j <= n; j++,dif += 4)
            {
                num += dif;
            }
        }
        printf("%d\n",num);

    }
    return 0;
}
