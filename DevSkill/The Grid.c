#include <stdio.h>
#include <math.h>
int main()
{
    int x1,x2,y1,y2,t,i,moveX,moveY,move;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
        moveX= y1-x1;
        moveY = y2-x2;
        if(moveX < 0)
            moveX = -moveX;
        if(moveY < 0)
            moveY = -moveY;
        move = moveX+moveY;
        printf("Case %d: %d\n",i,move);
    }
    return 0;
}
