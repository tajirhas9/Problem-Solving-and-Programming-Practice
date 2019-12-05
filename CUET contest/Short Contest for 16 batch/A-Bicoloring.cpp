#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000
vector <int> graph[300];
queue <int> q;
int n,m,level[300],flag;
void reset()
{
	int i;
	for(i=0;i<n;i++)
	{
		level[i] = MAX;
		graph[i].clear();
	}
	flag = 0;
}
int main()
{
	int i,j,x,y,top;
	while(1)
	{
		reset();
		cin >> n;
		if(n==0)	return 0;
		cin >> m;
		for(i=0;i<m;i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		q.push(0);
		level[0] = 0;
		while(!q.empty())
		{
			top = q.front();
			q.pop();
			for(j=0;j<graph[top].size();j++)
			{
				if(level[graph[top][j]] == MAX)
				{
					level[graph[top][j]] = level[top] + 1;
					q.push(graph[top][j]);	
				}
				else
				{
					if(level[graph[top][j]] == level[top]);
					{
						flag = 1;
					}
				}
			}
		}
		if(flag == 1)	cout << "NOT BICOLORABLE." << endl;
		else cout << "BICOLORABLE." << endl;
	}
}
