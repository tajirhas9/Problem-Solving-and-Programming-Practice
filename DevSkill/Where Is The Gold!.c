#include <stdio.h>
#include <string.h>
int main()
{
    char s[100][100];
    int t,a,b,i,j,k=1,count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                scanf("%c",&s[i][j]);
            }
            getchar();
        }
        printf("Case %d:\n",k);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if(s[i][j] == '$')
                {
                    count++;
                    printf("%d,%d\n",i,j);
                }
            }
        }
        if(count == 0)
        {
            printf("No Gold Found\n");
        }
        k++;
        if(t==0)
            break;
    }
    return 0;
}
