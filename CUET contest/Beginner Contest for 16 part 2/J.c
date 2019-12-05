#include <stdio.h>
int main()
{
    int t,k,i,j=1,sum=0;
    long long int n;
    scanf("%d",&t);
    while(t != 0)
    {
        scanf("%lld",&n);
        if(n < 0)
            n =  -n;
        while(1)
        {
            sum += j;
            if(sum >= n)
                break;
            j++;
        }
        if((sum-n)%2 == 0)
            printf("%d\n",j);
        else
        {
            if(((sum+(j+1))-n)%2 == 0)
            {
                printf("%d\n",j+1);
            }
            else
            {
                printf("%d\n",j+2);
            }
        }
        if(t != 1)
        {
            printf("\n");
        }
            j=1;
            sum=0;
            t--;
    }
    return 0;
}
