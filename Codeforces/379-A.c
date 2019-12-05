#include <stdio.h>
int main()
{
    int a,b,hour,i,r = 0;
    scanf("%d %d",&a,&b);
    hour = a;
    while(a>=b)
    {
        hour += a/b;
        r += a%b;
        a /= b;
        a += r;
        r = 0;
    }
    if(a > 0)
        r += a;
    while(r >= b)
    {
        hour += r/b;
        r /= b;
    }
    printf("%d",hour);
    return 0;
}
