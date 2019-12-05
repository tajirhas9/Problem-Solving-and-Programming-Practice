#include <stdio.h>
#define MAX 2147483647
int main()
{
    int n,i;
    signed long long int a,b,c;
    scanf("%d",&n);
    if(n >= 1 && n < 20)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
                if(((a+b)>c) && ((b+c)>a) && ((c+a)>b))
                {
                    if(a == b && b == c && c == a)
                    {
                        printf("Case %d: Equilateral\n",i);
                    }
                    else if((a == b && a != c) || (b == c && b != a) ||  (c == a && c != b))
                    {
                        printf("Case %d: Isosceles\n",i);
                    }
                    else
                    {
                        printf("Case %d: Scalene\n",i);
                    }
                    {

                    }
                }
                else
                {
                    printf("Case %d: Invalid\n",i);
                }
        }
    }
    return 0;
}
