#include <stdio.h>
#include <string.h>
int main()
{
    unsigned long long int n1,n2,revN1=0,revN2=0,sum,revSum=0,r;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu",&n1,&n2);
        while(n1>0)
        {
            r = n1%10;
            revN1 = 10*revN1+r;
            n1 /= 10;
        }
        while(n2>0)
        {
            r = n2%10;
            revN2 = 10*revN2+r;
            n2 /= 10;
        }
        sum = revN1+revN2;
        while(sum > 0)
        {
            r = sum%10;
            revSum = 10*revSum+r;
            sum /= 10;
        }
        printf("%llu\n",revSum);
        revN1=0;
        revN2=0;
        revSum=0;
        if(t==0)
            break;
    }
    return 0;
}
