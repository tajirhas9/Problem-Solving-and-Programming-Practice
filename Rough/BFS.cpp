#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int root, node;
	int i,e,kase,u,v,level[1000],graph[1000][1000];
	memset(graph,0,sizeof(graph));
	cin >> e;
	for(kase = 1; kase <= e; kase++)
	{
		cin >> u >> v;
		graph[u][v] = 1;
	}
	memset(level,1,sizeof(level));
	cin >> root; //From
	cin >> node; //To
	queue <int> q;
	q.push(root);
	level[root] = 0;
	while(!q.empty())
	{
		int top;
		top = q.front();
		for(i = 1; i<= 1000; i++)
		{
			if(graph[top][i] == 1 && level[i] == -1)
			{
				level[i] = level[top]+1;
				q.push(i);
			}
		}
		q.pop();
	}
	cout << level[node] << endl;
	
	return 0;
}
