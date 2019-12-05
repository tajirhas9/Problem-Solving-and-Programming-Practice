#include <stdio.h>
int main()
{
    long long int a,b,c;
    while((scanf("%lld %lld",&a,&b)) == 2)
    {
            c = b-a;
            if(c < 0)
            {
                c = -c;
            }
            printf("%lld\n",c);
    }
    return 0;
}
