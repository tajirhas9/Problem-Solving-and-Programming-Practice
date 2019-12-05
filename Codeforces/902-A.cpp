#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i,n)	for(i=0;i<n;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
ll n,m,x[2000],y[2000],i,pos;
int main()
{
	ios_base::sync_with_stdio(0);
	bool flag = true;
	cin >> n >> m;
	for(i=1;i<=n;i++)
	{
		cin >> x[i] >> y[i];
		if(i==1)
		{
			if(x[i]==0)
			{	
				pos = y[i];
				continue;
			}
			else
			{
				flag = false;
			}
		}
		if(x[i]==x[i-1])
		{
			pos = max(y[i],y[i-1]);
			continue;
		}
		if(pos>=x[i])
		{
			pos = y[i]; 
		}
		else
		{
			flag = false;
		}
	}
	if(pos < m)	flag = false;
	(flag) ? cout << "YES" << endl : cout << "NO" << endl;
	return  0;
}













//?

