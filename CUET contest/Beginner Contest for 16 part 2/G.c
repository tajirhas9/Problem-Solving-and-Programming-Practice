#include <stdio.h>
#include <math.h>
int main()
{
    int num,sum,n,t,i,init;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        init = n;
        if(n == 1)
        {
            printf("Case #%d: %d is a Happy number.\n",i,init);
            continue;
        }
        while(n < 10)
            n = n*n;
        while(n >= 10)
        {
            num = n;
            n = 0;
            while(num != 0)
            {
                sum = num%10;
                n += sum*sum;
                num /= 10;
            }
        }
        if(n == 1)
            printf("Case #%d: %d is a Happy number.\n",i,init);
        else
            printf("Case #%d: %d is an Unhappy number.\n",i,init);
    }
    return 0;
}
