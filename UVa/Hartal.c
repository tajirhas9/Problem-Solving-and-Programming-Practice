#include <stdio.h>
int main()
{
    int t,d,p,party[110],i,j,count=0,weekDay=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&d);
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d",&party[i]);
        for(i=1;i<=d;i++)
        {
            weekDay++;
            if(weekDay==6 || weekDay==7)
            {
                if(weekDay==7)
                        weekDay=0;
                continue;
            }
            else
            {
                for(j=0;j<p;j++)
                {
                    if(i%party[j] == 0)
                        {
                            count++;
                            break;
                        }
                }
            }
        }
        printf("%d\n",count);
        count=0;
        weekDay=0;
        if(t==0)
            break;
    }
    return 0;
}
