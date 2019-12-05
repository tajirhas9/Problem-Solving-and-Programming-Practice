#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;
map<string,set<string>> graph;
map <string,int> level;
queue <string> q;
int main()
{
	int t;
	string author = "Isenbaev";
	cin >> t;
	for(int i=0;i<t;i++)
	{
		string x,y,z;
		cin >> x >> y >> z;
		graph[x].insert(y);
		graph[x].insert(z);
		graph[y].insert(x);
		graph[y].insert(z);
		graph[z].insert(x);
		graph[z].insert(y);
		level[x] = -1;
		level[y] = -1;
		level[z] = -1;
	}
	q.push(author);
	if(level[author]==-1)
		level[author] = 0;
	else 
	{
		level[author] = -1;
		q.pop();
	}
	while(!q.empty())
	{
		string top;
		top = q.front();
		q.pop();
		set<string> :: iterator it = graph[top].begin();
		for( ; it != graph[top].end(); it++)
		{
			if(level[*it]==-1)
			{
				level[*it] = level[top]+1;
				q.push(*it);
			}
		}
	}
	map<string,int>::iterator it;
	for(it = level.begin(); it != level.end(); it++)
	{	
		if(it->first == author && it->second==-1)
		{
			continue;
		}
		cout << it->first << " ";
		(it->second==-1) ? cout << "undefined" << endl : cout << it->second << endl;
	}
	return  0;
}


