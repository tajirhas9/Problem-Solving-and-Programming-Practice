#include <stdio.h>
int main()
{
    long n,m,a;
    float result;
    scanf("%ld %ld %ld",&n,&m,&a);
    result = (n*m)/(a*a);
    if((n*m)%(a*a) != 0)
    {
        result += 2;
    }
    if((n*m)<(a*a))
    {
        result = 1;
    }
    printf("%d",(int)result);
    return 0;
}
