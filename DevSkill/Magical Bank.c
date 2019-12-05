#include <stdio.h>
int main()
{
    int i,n,t,sum=0,count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;sum<n;i++)
        {
            sum += i;
            count++;
        }
            printf("%d\n",count);
        count=0;
        sum=0;
        if(t==0)
            break;
    }
    return 0;
}
