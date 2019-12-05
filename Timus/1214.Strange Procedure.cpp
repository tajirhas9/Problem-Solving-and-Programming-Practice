#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i,n)	for(i=0;i<n;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x);
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
int main()
{
	ios_base::sync_with_stdio(0);
	ll x,y;
	cin >> x >> y;
	if((x-y)&1 && x>0 && y>0)
		cout << y << " " << x;
	else
		cout << x << " " << y;
	return  0;
}













//?
