#include <stdio.h>
#include <math.h>
int main()
{
    long long int a,b,stan,ollie;
    int i,j;
    double condition = (1+sqrt(5))/2;
    while(1)
    {
        scanf("%lld %lld",&a,&b);
        if(a == 0 && b == 0)
        {
            return 0;
        }
        else if(a > 0 && b > 0)
        {
