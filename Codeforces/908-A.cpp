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
ll i,j,k,n=0;
char s[50];
int main()
{
	ios_base::sync_with_stdio(0);
	scanf("%s",s);
	ll l;
	l = strlen(s);
	FOR(i,0,l-1)
	{
		if(s[i]=='a' ||
		   s[i]=='e' ||
		   s[i]=='i' ||
		   s[i]=='o' ||
		   s[i]=='u')
			n++;
		else if(s[i]=='1' ||	
			s[i]=='3' ||
			s[i]=='5' ||
			s[i]=='7' ||
			s[i]=='9')
				n++;
	}
	cout << n;
	return  0;
}













//?
