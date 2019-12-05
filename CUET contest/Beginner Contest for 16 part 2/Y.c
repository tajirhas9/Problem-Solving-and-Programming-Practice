#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,i;
    double peb,count=0,pebbles;
    scanf("%d %d",&a,&b);
    for(i = 1; i <= a;i++)
    {
        scanf("%lf",&pebbles);
        count += ceil(pebbles/b);
    }
    printf("%.0lf",ceil(count/2));
    return 0;
}
