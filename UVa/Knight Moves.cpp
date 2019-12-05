#include <bits/stdc++.h>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define pii pair<int,int>
int cell[100][100];
int vis[100][100] = {0};
int d[100][100] = {0};
int fx[] = {1,1,-1,-1,2,2,-2,-2};
int fy[] = {-2,2,-2,2,-1,1,-1,1};
int x,y,tx,ty,sx,sy,dx,dy,i,j,k;
string s1,s2;
queue <pii> q;
int main()
{

    while((cin>>s1>>s2))
    {
        getchar();
        sy = s1[0]-'a';
        sx = s1[1]-'0'-1;
        dy = s2[0]-'a';
        dx = s2[1]-'0'-1;
        q.push(pii(sx,sy));
        vis[sx][sy] = 1;
        d[sx][sy] = 0;
        while(!q.empty())
        {
            pii top = q.front();
            q.pop();
            for(k=0;k<8;k++)
            {
                tx = top.first+fx[k];
                ty = top.second+fy[k];
                if(tx >=0 && tx < 8 && ty >= 0 && ty < 8 && vis[tx][ty] == 0)
                {
                    q.push(pii(tx,ty));
                    vis[tx][ty] = 1;
                    d[tx][ty] = d[top.first][top.second]+1;
                }
            }
        }
        cout << "To get from " << s1 << " to " << s2 << " takes " << d[dx][dy] << " knight moves." << endl;
        for(k=0;k<100;k++)
        {
            for(i=0;i<100;i++)
                vis[k][i] = 0;
        }
        for(k=0;k<100;k++)
        {
            for(i=0;i<100;i++)
                cell[k][i] = -1;
        }
        for(k=0;k<100;k++)
        {
            for(i=0;i<100;i++)
                d[k][i] = -1;
        }
    }
    return 0;
}
