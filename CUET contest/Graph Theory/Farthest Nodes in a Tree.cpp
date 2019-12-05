#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define MAX 30009
#define cin1(x)	scanf("%lld",&x)
#define cin3(x,y,z)	scanf("%lld %lld %lld",&x,&y,&z)
typedef pair<ll,ll> ii;
void bfs(ll s);
void reset(void);
ll n;
ll level[MAX],cost[MAX];
vector<ii> graph[MAX];
int main()
{
	ll T;
	cin1(T);
	for(int i=1;i<=T;i++)
	{
		cin1(n);
		reset();
		for(int i=1;i<n;i++)
		{
			ll x,y,z;
			cin3(x,y,z);
			graph[x].push_back(ii(y,z));
			graph[y].push_back(ii(x,z));
		}
		ll s=0;
		bfs(s);
		for(int i=0;i<n;i++)
		{
			if(cost[s]<cost[i])	s=i;
			level[i] = -1;
		}
		bfs(s);
		printf("Case %lld: %lld\n",i,*max_element(cost,cost+n));
	}
	return 0;
}
void bfs(ll s)
{
	ll e;
	queue <ll> q;
	q.push(s);
	level[s] = 0;
	cost[s] = 0;
	while(!q.empty())
	{
		ll top;
		top = q.front();
		q.pop();
		for(ll i=0;i<graph[top].size();i++)
		{
			ll v;
			v = graph[top][i].first;
			if(level[v] == -1)
			{
				level[v] = level[top]+1;
				cost[v] = cost[top]+graph[top][i].second;
				q.push(v);
			}
		}
	}	
}
void reset(void)
{
	memset(level,-1,sizeof(level));
	for(int i=0;i<n;i++)
	{
		graph[i].clear();
	}
}
