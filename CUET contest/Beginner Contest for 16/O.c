#include <stdio.h>
int main()
{
    unsigned int j,i,a,b,n;
    float m,sum=0;
    scanf("%d",&n);
    if(n >= 1 && n <= 100)
    {
        for(i  = 1; i <= n; i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            if(a <= 100 && b <= 100 && a <= b)
            {
                if(a % 2 == 0)
                {
                    a += 1;
                }
                if(b % 2 == 0)
                {
                    b -= 1;
                }
                m = ((b-a)/2)+1;
                sum = (m/2)*(2*a+(m-1)*2);
                printf("Case %d: %.0f\n",i,sum);
                sum = 0;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
