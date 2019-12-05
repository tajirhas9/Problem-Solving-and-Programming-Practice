#include <stdio.h>
int gcd(int a,int b)
{
    return (a==0)?b:gcd(b%a,a);
}
int main()
{
    int a,b,n,turn=1,x;
    scanf("%d %d %d",&a,&b,&n);
    while(n>0)
    {
        if(turn%2 != 0)
            x = gcd(a,n);
        else
            x = gcd(b,n);
        n -= x;
        turn++;
    }
    if(turn%2==0)
        printf("0");
    else
        printf("1");
    return 0;
}
