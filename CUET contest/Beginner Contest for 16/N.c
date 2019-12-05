#include <stdio.h>
int gcd(int x,int y);
int main()
{
    int i,j,t=1,temp,g=0,n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
        {
            return 0;
        }
        else if(n > 1 && n < 501)
        {
            for(i = 1; i < n; i++)
            {
                for(j = i+1; j <= n; j++)
                {
                    g += gcd(i,j);
                }
            }
            printf("%d\n",g);
            g = 0;
        }
        else
        {
            return 0;
        }
        t++;
        if(t == 100)
        {
            break;
        }
    }
    return 0;
}
int gcd(int x,int y)
{
    int t;
    if(x == 0) return y;
    else if(y == 0) return x;
    else
    {
        while(y != 0)
        {
            t = y;
            y = x%y;
            x = t;
        }
        return x;
    }
}
