#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000000
vector <int> graph[2000];
queue <int> q;
int n,m,i,j,x,y,level[2000],top;
void reset()
{
	for(i=0;i<n;i++)
	{
		graph[i].clear();
		level[i] = MAX;
	}
}
int main()
{
	//freopen("The Party,Part 1.txt","r",stdin);
	int testCases;
	cin >> testCases;
	for(j=1;j<=testCases;j++)
	{
		cin >> n >> m;
		reset();
		for(i=1;i<=m;i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		q.push(0);
		level[q.front()] = 0;
		while(!q.empty())
		{
			top = q.front();
			q.pop();
			for(i=0;i<graph[top].size();i++)
			{
				if(level[graph[top][i]] == MAX)
				{
					level[graph[top][i]] = level[top]+1;
					q.push(graph[top][i]);
				}
			}
		}
		if(j != 1)	cout << endl;
		for(i=1;i<n;i++)
			cout << level[i] << endl;
	}
	return 0;
}
