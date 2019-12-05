#include <stdio.h>
int main()
{
    int h1,h2,m2,m1;
    double time1,time2,diff;
    while(1)
    {
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
        {
            return 0;
        }
        else if( (h1 >= 0 && h1 <= 23) && (h2 >= 0 && h2 <= 23) && (m1 >= 0 && m1 <= 59) && (m2 >= 0 && m2 <= 59))
        {
            if(h2 < h1)
            {
                h2 += 24;
            }
            time1 = h1+((double)m1/60);
            time2 = h2+((double)m2/60);
            diff = time2-time1;
            diff *= 60;
            if(diff < 0)
            {
                diff += 24*60;
            }
            printf("%.0lf\n",diff);
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
