#include <stdio.h>
int main()
{
    int d,x1,x2,y1,y2,temp,i=1;
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    if(y1>y2)
    {
        temp =  y2;
        y2 = y1;
        y1 = temp;
    }
    if(x1>x2)
    {
        temp = x2;
        x2 = x1;
        x1 = temp;
    }
    if((y2-y1) < (x2-x1))
    {
        d = y2-y1;
        i = d+(x2-x1-d);
    }
    else
    {
        d = x2-x1;
        i = d+(y2-y1-d);
    }
    printf("%d",i);
    return 0;
}
