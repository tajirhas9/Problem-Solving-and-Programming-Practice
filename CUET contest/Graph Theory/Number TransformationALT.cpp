#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
void bfs(int s);
void findPrime(void);
void reset(void);
int s,t,level[1005];
vector<int> prime;
int main()
{
	int T;
	findPrime();
	int i=0;
	while(i++)
	{
		reset();
		scanf("%d %d",&s,&t);
		if(s==0 && t==0 )	return 0;
		bfs(s);
		printf("Case %d: %d\n",i,level[t]);
	}
}
void reset(void)
{
	for(int i=0;i<1005;i++)
	{
		level[i] = -1;
	}
}
void findPrime(void)
{
	bool isPrime=true;
	for(int i=2;i<=1000;i++)
	{
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				isPrime = false;
				break;
			}
		}
		if(isPrime)	prime.push_back(i);
		isPrime = true;
	}
}
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	level[s] = 0;
	while(!q.empty())
	{
		int top;
		top = q.front();
		q.pop();
		if(top > t)	return;
		for(int i=0;i<prime.size();i++)
		{
			if(top%prime[i]==0 && prime[i] != top && (top+prime[i]) <= t && level[top+prime[i]] == -1)
			{
				level[top+prime[i]] = level[top]+1;
				q.push(top+prime[i]);
				if((top+prime[i]) == t)	return;
			}
		}
	}
}
