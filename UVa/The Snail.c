#include <stdio.h>
int main()
{
    double h,u,d,f,dHeight=0,height=0,fatigue;
    double day=0;
    while(1)
    {
        scanf("%lf %lf %lf %lf",&h,&u,&d,&f);
        if(h==0)
            return 0;
        else
        {
            while(height < h)
            {
                day++;
                fatigue = u*(f/100)*(day-1);
                dHeight = u-fatigue;
                if(dHeight < 0)
                    dHeight = 0;
                height += dHeight;
                if(height <= h)
                    height -= d;
                if(height < 0)
                {
                    printf("failure on day %.0lf\n",day);
                    break;
                }
                if(height >= h)
                {
                    printf("success on day %.0lf\n",day);
                }
            }
        }
        day = 0;
        fatigue = 0;
        height = 0;
    }
    return 0;
}
