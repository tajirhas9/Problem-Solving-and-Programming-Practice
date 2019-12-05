#include <stdio.h>
int main()
{
    int roads,digits,i=1,j,count=0;
    while((scanf("%d %d",&roads,&digits)) == 2)
    {
        if(roads == 0 && digits == 0) return 0;
        if((digits+digits*26) < roads)
        {
            printf("Case %d: impossible\n",i);
            i++;
            continue;
        }
        for(j = digits+1; j <= roads; j += digits)
        {
            count++;
        }
        printf("Case %d: %d\n",i,count);
        i++;
        count = 0;
    }
    return 0;
}
