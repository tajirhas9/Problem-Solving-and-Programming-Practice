#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define pii 	pair<int,int>
#define cin(n)	scanf("%d",&n)
#define cout(n)	printf("%d\n",n)
queue <pii> q;
int main()
{
	pii x,top;
	int i,n,read=0;
	cin(n);
	for(i=1;i<=7;i++)
	{
		cin(x.first);
		x.second = i;
		q.push(x);
	}
	while(read<n)
	{
		top = q.front();
		q.pop();
		read += top.first;
		q.push(top);
	}
	cout(top.second);
	return 0;
}
