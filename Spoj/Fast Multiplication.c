#include <stdio.h>
long long int x[10000],n;
int mul(long long int n);
int print();
int main()
{
    scanf("%lld",&n);
    mul(n);
    return 0;
}
int mul(long long int y)
{
    long long int a,b;
    if(y==0)
    {
        print();
        return 0;
    }
    scanf("%lld %lld",&a,&b);
    x[y] = a*b;
    mul(y-1);
    printf("%lld\n",x[n-y-1]);
}
int print()
{
    int i;
    for(i=n;i>0;i--)
    {
        printf("%lld\n",x[i]);
    }
    return 0;
}
