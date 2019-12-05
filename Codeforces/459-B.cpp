#include <bits/stdc++.h>
using namespace std;
#define MAX 1234567898
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
ll i,j,k,n,b[12345678],mi=MAX,ma=0,c[12345678],cntMi=0,cntMa=0,dif;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> b[i];
		if(b[i]<mi)	mi = b[i];
		if(b[i]>ma)	ma = b[i];
	}
	dif=ma-mi;
	for(i=0;i<n;i++)
	{
		if(b[i]==mi)	cntMi++;
		if(b[i]==ma)	cntMa++;
	}
	if(mi!=ma)
		cout << dif << " " << cntMi*cntMa << endl;
	else
		cout << dif << " " << (cntMi*(cntMi-1))/2 << endl;
	return  0;
}













//?
