#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a)
typedef long long ll;
typedef string string;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setl;
typedef set<string> sets;
typedef set<ll>::iterator setl_it;
typedef set<string>::iterator sets_it;
typedef vector<ll>::iterator vl_it;
typedef vector<string>::iterator vs_it;
struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pii const &a, pii const &b)	
	{
		if(a.first==b.first)
			return (a.second<b.second);
		return (a.first>b.first);
	}
};
ll i,j,k,n,in_hand=0,a[5];
queue<ll> q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		q.push(x);
	}
	ll top,rest;
	RESET(a,0);
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		rest = top-25;
		if(rest==0)
			a[0]++;
		else if(rest==25 && a[0]>=1)
		{
			a[0]--;
			a[1]++;
		}
		else if(rest==75 && ((a[0]>=1 && a[1]>=1)||a[0]>=3))
		{
			if(a[1]>=1)
			{
				a[0]--;
				a[1]--;
			}
			else
				a[0] -= 3;
			a[2]++;
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return  0;
}













//?

