#include <stdio.h>
#include <math.h>
int main()
{
    int me,lift,time,t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&me,&lift);
        time = abs(lift-me)*4+3+5+me*4+3+5+3;
        printf("Case %d: %d\n",i,time);
    }
    return 0;
}
