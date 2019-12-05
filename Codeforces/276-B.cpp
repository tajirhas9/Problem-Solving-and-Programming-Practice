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
ll i,j,k,cnt[30],l,odd=0;
char s[123457];
int main()
{
	ios_base::sync_with_stdio(0);
	scanf("%s",s);
	l = strlen(s);
	RESET(cnt,0);
	FOR(i,0,l-1)	cnt[s[i]-'a']++;
	FOR(i,0,25)
	{
		if(cnt[i]&1)	odd++;
	}
	if(odd>1 && !(odd&1))	cout << "Second" << endl;
	else 	cout << "First" << endl;
	return  0;
}













//?
