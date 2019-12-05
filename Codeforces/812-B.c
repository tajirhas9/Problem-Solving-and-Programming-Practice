#include <stdio.h>
int main()
{
    char room[20][110];
    int i,j,k,time=0,n,m,flag=0;
    scanf("%d %d",&n,&m);
    getchar();
    for(i=(n-1);i>=0;i--)
    {
        scanf("%s",room[i]);
        getchar();
    }
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<=(m+1);j++)
            {
                if(room[i][j] == '1')
                {
                    for(k=j;k<=(m+1);k++)
                    {
                        if(room[i][j] == '1')
                            flag = 1;
                    }
                    if(flag == 0)
                    {
                        if(j < (m+1)/2)
                            j = ((m+1)-j)+1;
                        room[i][j] == '0';
                    }
                    else
                        room[i][j] == '0';
                }
                time++;
            }
        }
        else
        {
            for(j=(m+1);j>=0;j--)
            {
                if(room[i][j] == '1')
                {
                    for(k=j;k>=0;k--)
                    {
                        if(room[i][j] == '1')
                            flag = 1;
                    }
                    if(flag == 0)
                    {
                        if(j > (m+1)/2)
                            j = ((m+1)-j)+1;
                        room[i][j] == '0';
                    }
                    else
                        room[i][j] == '0';
                }
                time++;
            }
        }
        time++;
        flag=0;
    }
    printf("%d",time);
    return 0;
}
