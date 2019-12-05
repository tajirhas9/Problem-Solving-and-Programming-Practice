#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 30005
#define cin1(x)	scanf("%lld",&x)
#define cin2(x,y)	scanf("%lld %lld",&x,&y)
#define cin3(x,y,z)	scanf("%lld %lld %lld",&x,&y,&z)
#define ll long long
ll bfs(ll s);
void reset(void);
typedef pair<ll,ll> ii;
vector<ii> graph[MAX];
ll n;
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
		printf("Case %d:\n",i);
		for(ll s=0;s<n;s++)
		{
			printf("%lld\n",bfs(s));
		}
	}
	return 0;
}
ll bfs(ll s)
{
	ll level[MAX],cost[MAX],maxim=0;
	memset(level,-1,sizeof(level));
	queue<ll>q;
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
				maxim = max(maxim,cost[v]);
				q.push(v);
			}
		}
	}
	return maxim;
}
void reset(void)
{
	for(int i=0;i<n;i++)	graph[i].clear();
}
