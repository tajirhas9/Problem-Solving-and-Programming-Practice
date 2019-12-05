#include <stdio.h>
int main()
{
    int x,y,a,b,c,d,i,countA=0,countB=0,t,m,gcd,lcd;
    scanf("%d %d %d %d",&x,&y,&a,&b);
    if(x > y)
    {
        t = x;
        x = y;
        y = t;
    }
    c = x;
    d = y;
    if(x == 0) gcd = y;
    else if(y == 0) gcd = x;
    else
    {
        while(y != 0)
        {
            t = y;
            y = x%y;
            x = t;
        }
        gcd = x;
    }
    lcd = (c*d)/gcd;
    if(lcd == 1)
    {
        countB = b-a+1;
        printf("%d",countB);
    }
    else
    {
        for(i = 0; i <= b; i += lcd)
        {

            countB++;

        }
        for(i = 0; i < a; i += lcd)
        {
            countA++;
        }
        printf("%d",countB-countA);
    }
    return 0;
}
