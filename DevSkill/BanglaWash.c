#include <stdio.h>
int main()
{
    int i,a1,a2,b1,b2,a3,b3,a4,b4,t,win1=0,win2=0;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
        scanf("%d %d %d %d",&a3,&a4,&b3,&b4);
        if(((a1-b1)+a2) > b2 && ((a3-b3)+a4) > b4)
        {
            printf("Banglawash\n");
        }
        else
        {
            printf("Miss\n");
        }
    }
    return 0;
}
