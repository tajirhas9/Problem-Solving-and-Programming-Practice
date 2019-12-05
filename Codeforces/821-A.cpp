#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n[100][100],c=0,i,j,k,l,co=0,flag = 0;
    cin >> t;
    for(i=0;i<t;i++)
    {
        for(j=0;j<t;j++)
        {
            cin >> n[i][j];
            if(n[i][j] > 1)
                c++;
        }
    }
    for(i=0;i<t;i++)
    {
        for(j=0;j<t;j++)
        {
            if(n[i][j] > 1)
            {
                for(k=0;k<t;k++)
                {
                    if(k == j)
                        continue;
                    for(l=0;l<t;l++)
                    {
                        if(l == i)
                            continue;
                        if(n[i][k]+n[l][j] == n[i][j])
                        {
                            co++;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
    }
    if(co == c)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
