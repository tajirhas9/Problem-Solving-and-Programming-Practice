#include <stdio.h>
int main()
{
    int n;
    double v,t,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %lf",&v,&t);
        a = (0-v)/t;
        printf("%.2lf\n",a);
        if(t==0)
            break;
    }
    return 0;
}
