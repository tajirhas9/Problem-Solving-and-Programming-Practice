#include <stdio.h>
int main()
{
    int count=0,n,i=1,a,j=1;
    while((scanf("%d",&n)) == 1)
    {
        if(n == 0)
        {
            break;
        }
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&a);
            if(a >= 1 && a <= 99)
            {
                count++;
            }
            else if(a == 0)
            {
                count--;
            }
            else
            {
                break;
            }
        }
        printf("Case %d: %d\n",j,count);
        j++;
        count = 0;
        if(j == 75)
        {
            break;
        }
    }
    return 0;
}
