#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n,k,m,x,y;
    char c[201],string[10001];
    double value[201];
    double money=0;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        getchar();
        j = 0;
        do
        {
            scanf("%c %lf",&c[j],&value[j]);
            getchar();
            j++;
        }
        while(j < k);
        scanf("%d",&m);
        getchar();
        for(j = 1; j <= m; j++)
        {
            gets(string);
            /*getchar();*/
            for(x = 0; x < k; x++)
            {
                for(y = 0 ; y < strlen(string); y++)
                {
                    if(string[y] == c[x])
                    {
                        money += value[x];
                    }
                }
            }
        }
        printf("%.2lf$\n",money/100);
        money = 0;
    }
    return 0;
}
