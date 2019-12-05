#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,ct,p[101];
    double day=0,hours_spent=0,work_a_day=0;
    while((scanf("%d %d",&ct,&n)) != EOF)
    {
        if(n >= 1 && n <= 100)
        {
            for(i = 0; i < n; i++)
            {
                scanf("%d",&p[i]);
                if(p[i] > 0 && p[i] <= 24)
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            for(i = 0; i < n; i++)
                {
                    work_a_day += p[i];

                }
            while(1)
            {

                for(i = 0; i < n; i++)
                {
                    hours_spent += p[i];

                }
                if(hours_spent >= ct)
                {
                    break;
                }
            }
            day = hours_spent/work_a_day;
            if(day == 1)
            {
                printf("Project will finish within %.0lf day.\n",day);

            }
            else
            {
                printf("Project will finish within %.0lf days.\n",day);
            }
            day = 0;
            hours_spent = 0;
            work_a_day = 0;
        }
    }
    return 0;
}
