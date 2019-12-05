#include <bits/stdc++.h>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
void reset(void);
#define pii pair<int,int>
queue <pii> q;
char graph[30][30];
int vis[30][30],i,j,n=25,m=25,t,c=0;
int fx[4] = {0,0,1,-1};
int fy[4] = {1,-1,0,0};
int main()
{
	//freopen("Guilty Prince.txt","r",stdin);
	char s[30];
	int i,j,k,x,y;
	pii pos;
    cin >> t;
    for(i=1;i<=t;i++)
    {
		reset();
        scanf("%d %d",&n,&m);
        getchar();
        for(j=0;j<m;j++)
        {
            scanf("%s",s);
            getchar();
            for(k=0;k<strlen(s);k++)
            {
				graph[j][k] = s[k];
                if(graph[j][k] == '@')
                {
                    vis[j][k] = 1;
                    pos.first = j;
                    pos.second = k;
                    q.push(pos);
                    c++;
                }
                else if(graph[j][k] == '.')
                {
					vis[j][k] = 0;
				}
            }
        }
        while(!q.empty())
        {
			pii top;
			top = q.front();
			q.pop();
			for(k=0;k<4;k++)
			{
				y = top.first+fy[k];
				x = top.second+fx[k];
				
				if(x>=0 && x < n && y >= 0 && y < m)
				{
					if(graph[y][x] == '.' && vis[y][x] == 0)
					{
						vis[y][x] = 1;
						c++;
						pos.first = y;
						pos.second = x;
						q.push(pos);
					}
				}
			}
		}
		printf("Case %d: %d\n",i,c);
	}
}
void reset(void)
{
	for(int x=0;i<m;i++)
	{
		for(int y=0;j<n;j++)
		{
			vis[y][x] = 0;
			graph[y][x] = '\0';
		}
	}
	c=0;
}
