#include <stdio.h>
#include <math.h>
int main()
{
    double n,p;
    double k;
    while(scanf("%lf %lf",&n,&p) == 2)
    {
        if((n >= 1 && n <= 200) && (p >= 1 && p <= pow(10,101)))
        {
            k = pow(p,(1/n));
            printf("%.0lf\n",k);
        }
    }
    return 0;
}
