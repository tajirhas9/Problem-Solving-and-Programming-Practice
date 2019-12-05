#include <stdio.h>
int palindrome(long long int x)
{
    long long int original,reverse=0,rem;
    original = x;
    while(original != 0)
    {
        rem = original%10;
        reverse = reverse*10+rem;
        original /= 10;
    }
    if(x == reverse) return 1;
    else return 0;
}
int main()
{
    long long int original,reverse,sum=12;
    int n,i,j=1,t,r;
    scanf("%d",&t);
    for(i = 1; i <= t; i++)
    {
        j = 1;
        scanf("%lld",&original);
        while(1)
        {
            n = original;
            reverse = 0;
            while(n != 0)
            {
                r = n%10;
                reverse = reverse*10 + r;
                n /= 10;
            }
            sum = original + reverse;
            if(palindrome(sum) == 1) break;
            original = sum;
            j++;
        }
        printf("%d %lld\n",j,sum);
    }
    return 0;
}
