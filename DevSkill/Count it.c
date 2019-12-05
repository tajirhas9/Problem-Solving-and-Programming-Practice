#include <stdio.h>
#include <string.h>
int main()
{
    int count[150],i,t,l,j;
    char s[110];
    scanf("%d",&t);
    for(j=1; j<=t; j++)
    {
        for(i=95; i< 125;i++)
            count[i] = 0;
        scanf("%s",s);
        l = strlen(s);
        for(i=0; i < l; i++)
        {
            count[s[i]]++;
        }
        printf("Case %d:\n",j);
        for(i=95; i< 125;i++)
        {
            if(count[i] > 0)
                printf("%c %d\n",i,count[i]);
        }
    }
    return 0;
}
