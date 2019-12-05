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
	bool operator()(pii const &a, pii const &b)
	{
		if(a.first==b.first)
			return (a.second<b.second);
		return (a.first>b.first);
	}
};
ll i,j,k,x=0;
char s[12345678];
int main()
{
	ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	while(n>0)
	{
		if((n-7)<0 && (n-4)<0)
		{
			cout << -1 << endl;
			return 0;
		}
		if(n%7!=0)
		{
			s[x++] = '4';
			n -= 4;
		}
		else
		{
			s[x++] = '7';
			n -= 7;
		}
	}
	s[x] = '\0';
	cout << s << endl;
	return  0;
}













//?
