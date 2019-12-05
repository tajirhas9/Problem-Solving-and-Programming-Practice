#include <stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    if(n%5==0)
        printf("%lld",n/5);
    else
        printf("%lld",n/5+1);
    return 0;
}
