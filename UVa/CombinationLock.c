#include <stdio.h>
int main()
{
    int i,a,b,c,x,y,z,total;
    while(1)
    {
        scanf("%d %d %d %d",&i,&a,&b,&c);
        if(i == 0 && a == 0 && b == 0 && c == 0)
        {
            break;
        }
        if(a > i)
        {
            x = (a-i)*9;
        }
        else
        {
            x = (40 - (i-a))*9;
        }
        if(a > b)
        {
            y = (a-b)*9;
        }
        else
        {
            y = (40 - (b-a))*9;
        }
        if(c > b)
        {
            z = (c-b)*9;
        }
        else
        {
            z = 360 - (c-b)*9;
        }
        total = 720+x+360y+z;
        printf("%d\n",total);
    }
    return 0;
}
