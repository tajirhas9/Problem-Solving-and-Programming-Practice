#include <stdio.h>
#define MAX 30000
int main()
{
    long long int a=1,b=1,c=1;
    int i;
    while(1)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if((a >= 0 && a < MAX) && (b >= 0 && b < MAX) && (c >= 0 && c < MAX))
        {
            if((a == 0) && (b == 0) && (c == 0))
            {
                return 0;
            }
            if( a != 0 && b != 0 && c != 0)
            {
                if((a*a == (b*b + c*c)) || (b*b == (c*c + a*a)) || (c*c == (a*a + b*b)))
                {
                    printf("right\n");
                }
                else
                {
                    printf("wrong\n");
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
