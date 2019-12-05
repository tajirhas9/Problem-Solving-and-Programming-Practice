#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long
ll int p[1000],n,k;
queue <ll int> q;
int main()
{
	ll int p1,p2,wins=0,winner=1000,m=0,maxP;
	cin >> n >> k;
	for(int i=1;i<=n;i++)	q.push(i);
	for(int i=1;i<=n;i++)
	{
		cin >> p[i];
		if(m < p[i])
		{
			m = p[i];
			maxP = i;
		}
	}
	while(wins<k && winner != maxP)
	{
		if(winner != 1000)	p1 = winner;
		else
		{
			p1 = q.front();
			q.pop();
		}
		
		p2 = q.front();
		q.pop();
		if(p[p1] > p[p2])
		{
			q.push(p2);
			if(winner == p1 || winner == 1000)	wins++;
			else wins = 0;
			winner = p1;
		}
		else
		{
			q.push(p1);
			if(winner==p2 || winner == 1000)	wins++;
			else
			{
				wins = 0;
			}
			winner = p2;
		}
	}
	cout << p[winner] << endl;
	return 0;
}
