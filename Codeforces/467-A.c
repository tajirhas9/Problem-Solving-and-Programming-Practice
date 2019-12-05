#include <stdio.h>
int main()
{
    int i,t,a,b,count=0;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d",&a,&b);
        if((b-a) >= 2)
            count++;
    }
    printf("%d",count);
    return 0;
}
