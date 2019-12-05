#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
#define pii pair<int,int>
queue <pii> q;
int cell[2000][2000];
int vis[2000][2000] = {0};
int d[2000][2000] = {0};
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int row,col,brow,bcol,x,y,tx,ty,sx,sy,dx,dy,i,j,k;
int main()
{
    //freopen("bombsNoMines.txt","r",stdin);
    while(1)
    {
        cin >> row >> col;
        if(row == 0 && col == 0)    return 0;
        cin >> brow;
        for(i=1;i<=brow;i++)
        {
            cin >> x >> bcol;
            for(j=1;j<=bcol;j++)
            {
                cin >> y;
                cell[x][y] = -1;
            }
        }
        cin >> sx >> sy;
        cin >> dx >> dy;
        vis[sx][sy] = 1;
        q.push(pii(sx,sy));
        d[sx][sy] = 0;
        while(!q.empty())
        {
            pii top = q.front();
            q.pop();
            for(k=0;k<4;k++)
            {
                tx = top.first+fx[k];
                ty = top.second+fy[k];
                if(tx >= 0 && tx < row &&
                    ty >= 0 && ty < col &&
                    cell[tx][ty] != -1 &&
                    vis[tx][ty] == 0)
                {
                        vis[tx][ty] = 1;
                        d[tx][ty] = d[top.first][top.second]+1;
                        q.push(pii(tx,ty));
                }
            }
        }
        cout << d[dx][dy] << endl;
        memset(vis,0,sizeof vis);
        memset(cell,0,sizeof cell);
    }
}
