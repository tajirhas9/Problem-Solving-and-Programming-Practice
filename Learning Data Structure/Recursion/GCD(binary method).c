/*
*Finding GCD using Joseph Stein's Algorithm/binary method
*/
#include <stdio.h>
#include <math.h>
int gcd(int x,int y);
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}
int gcd(int x,int y)
{
    if(x==y)
        return x;
    else if(y==0)
        return x;
    else if(x==0)
        return y;
    if(x%2==0 && y%2==0)
        return (2*gcd(x/2,y/2));
    else if(x%2==0 && y%2 != 0)
        return gcd(x/2,y);
    else
    {
        if(x>y)
            return gcd((x-y),y);
        else
            return gcd((y-x),x);
    }
}
