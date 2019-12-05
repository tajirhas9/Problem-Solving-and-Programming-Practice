#include<stdio.h>
int main()
{
    int frnd,bud,hotel,week,amount,cost=0,b,p,visit,i,j,room;
    while(scanf("%d%d%d%d",&frnd,&bud,&hotel,&week)==4)
    {
        for(i=0; i<hotel; i++)
        {
            scanf("%d",&amount);
            for(j=0; j<week; j++)
            {
                scanf("%d",&room);
                p=0;
                if(room>=frnd)
                {
                    p=amount*frnd;
                    cost=p;
                }
            }
        }
        if(cost>bud)
            printf("stay home\n");
        else
            printf("%d\n",cost);
        cost=0;


    }
    return 0;
}
