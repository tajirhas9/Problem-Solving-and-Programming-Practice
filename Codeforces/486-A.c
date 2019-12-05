#include <stdio.h>
#include <math.h>
int main()
{
    long long int n,i;
    double sumEven=0,sumOdd=0,m,x;
    scanf("%lld",&n);
    if(n%2 == 0)
    {
        m = (double)n;
        x = (2+m)/2-1;
        sumEven = x*(x+1);
        sumOdd = pow(m/2,2);
    }
    else
    {
        m = (double)n;
        x = (1+m)/2-1;
        sumEven = x*(x+1);
        sumOdd = pow((m+1)/2,2);
    }
    printf("%.0lf",sumEven-sumOdd);
}
