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
ll i,j,k,n,pile1[12345],pile2[12345],sum1=0,sum2=0,findOdd1=-1,findOdd2=-1,findEven1=-1,findEven2=-1;
bool f1=false,f2=false,f3=false,f4=false;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	FOR(i,0,n-1)
	{
		cin >> pile1[i] >> pile2[i];
		sum1 += pile1[i]; sum2 += pile2[i];
		if(pile1[i]&1 && i != findOdd2 && !f1)	{ findOdd1 = i; f1 = true; }
		if(pile2[i]&1 && i != findOdd1 && !f2) { findOdd2 = i; f2 = true; }
		if(!(pile1[i]&1) && i != findEven2 && !f3) { findEven1 = i; f3 = true; }
		if(!(pile2[i]&1) && i != findEven1 && !f4) { findEven2 = i; f4 = true; }
	}
	//cout << sum1 << " " << findOdd1 << " " << findEven1 << endl;
	//cout << sum2 << " " << findOdd2 <<  " " << findEven2 << endl;
	if(sum1&1 && sum2&1)
	{
		if(f1 && f2 && (f3 || f4))	cout << 1 << endl;
		else 			cout << -1 << endl;
	}
	else if(!(sum1&1) && !(sum2&1))	cout << 0 << endl;
	else 	cout << -1 << endl;
	return  0;
}













//?

