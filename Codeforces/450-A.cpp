#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define cin(n) scanf("%d",&n)
#define cout(n) printf("%d\n",n)
#define pii pair<int,int>
queue<pii> q;
int main()
{
	pii x,top;
	int n,m,i;
	cin(n);
	cin(m);
	for(i=1;i<=n;i++)
	{
		cin(x.first);
		x.second = i;
		q.push(x);
	}
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		top.first -= m;
		if(top.first > 0)	q.push(top);
	}
	cout(top.second);
	return 0;
}
