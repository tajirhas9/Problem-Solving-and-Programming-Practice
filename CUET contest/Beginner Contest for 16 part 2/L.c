#include <stdio.h>
#include <math.h>
int isPrime(int x);
int digitSum(int x);
int main()
{
    int t,i,count=0;
    long long int a,b,j,sum;
    scanf("%d",&t);
    for(i = 1; i <= t;i++)
    {
        scanf("%lld %lld",&a,&b);
        for(j = a; j <= b; j++)
        {
            if(isPrime(j) == 1)
            {
                sum = digitSum(j);
                if(isPrime(sum) == 1)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
        count = 0;
    }
    return 0;
}

int isPrime(int x)
{
    int i;
    if(x == 2) return 1;
    for(i = 2; i <= sqrt(x); i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int digitSum(int x)
{
    int rem,count=0;
    while(x != 0)
    {
        rem = x%10;
        count += rem;
        x /= 10;
    }
    return count;
}
