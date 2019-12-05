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
typedef vector<int> vl;
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
class RangeEncoding
{
	int s=1;
	public:
	int minRanges(vl p);
};
int RangeEncoding::minRanges(vl p)
{
	int x,i;
	x = p[0];
	for(i=1; i< p.size(); i++)
	{
		if(++x == p[i])	continue;
		else 
		{
			x = p[i];
			s++;
		}
	}
	return s;
}
int i,j,k;
vl v;
int main()
{
	RangeEncoding c;
	int x;
	while((scanf("%d",&x)) != EOF)
		v.push_back(x);
	cout << c.minRanges(v);
	return 0;   
}
