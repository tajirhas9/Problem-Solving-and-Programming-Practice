#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
int main()
{
	ios_base::sync_with_stdio(0);
	ll x,y,s,m;
	cin >> x >> y >> s >> m;
	if((m<=2*s && 2*m>=s))
	{
		ll big=x,mid=y,small;
		small = min(2*m,2*s);
		if(small > mid)
			mid = small+1;
		if(mid>big)
			big = mid+1;
		if(mid>2*y || big>2*x)	goto check;
		cout << big << endl << mid << endl << small << endl;
		return 0;
	}
	else
		goto check;
	check:
	cout << -1 << endl;
	return  0;
}













//?

