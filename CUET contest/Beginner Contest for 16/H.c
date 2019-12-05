#include <stdio.h>
#define MAX 1073741824
int main()
{
    int n,i;
    long long int a,b,c,d;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if((a > 0 && a < MAX) && (b > 0 && b < MAX) && (c > 0 && c < MAX) && (d > 0 && d < MAX))
        {
            if(((a+b+c) > d) && ((b+c+d) > a) && ((c+d+a) > b) && ((d+a+b) > c))
            {
                if(a == b && b == c && c == d && d == a)
                {
                    printf("square\n");
                }
                else if((a == b && c == d) || (a == c && b == d) || ( b == c && a == d))
                {
                    printf("rectangle\n");
                }
                else
                {
                    printf("quadrangle\n");
                }
            }
            else
            {
                printf("banana\n");
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
