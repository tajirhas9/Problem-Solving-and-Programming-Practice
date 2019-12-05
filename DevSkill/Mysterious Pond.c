#include <stdio.h>
#include <string.h>
int main()
{
    char name[20][50];
    int n,t,value[20],max,min,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        max=0;
        min=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",name[i]);
            scanf("%d",&value[i]);
            if(value[i] > value[max])
                max = i;
            if(value[i] < value[min])
                min = i;
        }
        printf("%s %s\n",name[max],name[min]);
        if(t==0)
            break;
    }
    return 0;
}
