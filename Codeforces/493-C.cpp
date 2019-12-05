#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 2100000
#define INF 100000000
#define FOR(i,n)	for(i=0;i<n;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x);
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
ll n,m,a[MAX],b[MAX],maxDist,x,y,i,d,ax,by;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(i=0;i<n;i++)	cin >> a[i];
	a[n++] =INF;
	sort(a,a+n);
	cin >> m;
	for(i=0;i<m;i++)	cin >> b[i];
	sort(b,b+m);
	maxDist = -INF;
	for(i=0;i<n;i++)
	{
		d = (ll)(lower_bound(b,b+m,a[i])-b);
		ax = 2*i+(n-1-i)*3;
		by = 2*d+(m-d)*3;
		if((ax-by)>=maxDist)
		{
			if((ax-by)==maxDist && x > ax)	continue;
			x = ax;
			y = by;
			maxDist = ax-by;

		}
	}
	cout << x << ":" << y  << endl;
	return  0;
}













//?
