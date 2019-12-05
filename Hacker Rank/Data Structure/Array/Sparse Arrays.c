#include <stdio.h>
int main()
{
    char n[1100][25],q[1100][25];
    int totalItem,queryItem,i,j,p[1100];
    scanf("%d",&totalItem);
    for(i=0;i<totalItem;i++)
    {
        scanf("%s",n[i]);
    }
    scanf("%d",&queryItem);
    for(i=0;i<queryItem;i++)
    {
        scanf("%s",q[i]);
    }
    for(i=0;i<queryItem;i++)
    {
        for(j=0;j<totalItem;j++)
        {
            if(strcmp(q[i],n[j]) == 0)
                p[i]++;
        }
    }
    for(i=0;i<queryItem;i++)
        printf("%d\n",p[i]);
    return 0;
}
