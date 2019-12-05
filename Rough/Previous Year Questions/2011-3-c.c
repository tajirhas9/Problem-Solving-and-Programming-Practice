#include <stdio.h>
int product_digit(int n)
{
    int r,temp,t=1;
    while(n>=10)
    {
        temp = n;
        while(temp>0)
        {
            r = temp%10;
            t *= r;
            temp /= 10;
        }
        n = t;
        t = 1;
    }
    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",product_digit(n));
    return 0;
}
