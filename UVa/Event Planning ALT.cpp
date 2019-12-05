#include<stdio.h>
#define MAX 100000000
int main()
{
    int frnd,bud,hotel,week,amount,cost=MAX,b,p,visit,i,j,room,old_cost=MAX,flag=1;
    while(scanf("%d %d %d %d",&frnd,&bud,&hotel,&week)==4)
    {
        for(i=0; i<hotel; i++)
        {

            if(flag == 0) old_cost = amount;
            flag = 0;
            scanf("%d",&amount);
            for(j=0; j<week; j++)
            {
                scanf("%d",&room);
                if(room < frnd)   flag = 1;
                if(flag == 1)   continue; //jayga nai,oi hotel ta baad
                if(room>=frnd)
                {
                    cost = amount;
                }
                if(cost > old_cost) //daam beshi..ager hotel tai valo chilo.
                {
                    cost = old_cost;
                    old_cost = MAX;
                }
            }
        }
        if((cost*frnd) > bud)
            printf("stay home\n");
        else
            printf("%d\n",cost*frnd);
        cost=MAX;
        old_cost = MAX;
        flag = 1;
    }
    return 0;
}
