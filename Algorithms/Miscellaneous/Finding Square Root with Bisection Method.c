#include <stdio.h>
int main()
{
    double h,l,n,mid;
    scanf("%lf",&n);
    h = n;
    l = 0;
    while((h-l) > 0.0000001)
    {
        mid = (l+h)/2;
        if(mid*mid > n)
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
    }
    printf("%lf",mid);
    return 0;
}
