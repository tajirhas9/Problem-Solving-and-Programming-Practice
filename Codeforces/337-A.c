#include <stdio.h>
int main()
{
    int n,m,max=0,min=0,p[60],i,j,s;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d",&p[i]);
    }
    if(n == 2)
    {
        for(i=0;i<m;i++)
        {
            for(j=i+1;j<m;j++)
            {
                if(p[i] == p[j])
                {
                    printf("%d",0);
                    return 0;
                }
            }
        }
    }
    s = m;
    while(s > n)
    {
        for(i=0; i<m; i++)
        {
            if(p[max] < p[i])
                max = i;
            if(p[min] > p[i])
                min = i;
        }
        if((m-n) > 1)
        {
            p[max] = 0;
            p[min] = 0;
            s-=2;
        }
        else
        {
            p[max] = 0;
            s--;
        }
    }
    max = 0;
    min = 0;
    for(i=0; i<m; i++)
    {
        if(p[max] < p[i])
            max = i;
        if(p[min] > p[i] && p[i] != 0)
            min = i;
    }
    printf("%d",p[max]-p[min]);
    return 0;
}
