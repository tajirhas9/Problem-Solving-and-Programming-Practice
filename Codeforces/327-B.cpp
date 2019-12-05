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
ll i,j,k,n,marked[100000000/64+2];
vl primes;
void seive(void);
void genPrime(void);
bool isPrime(ll n);
bool on(ll x) {  return (marked[x/64] & (1<<((x%64)/2))); }
void mark(ll x)	{  marked[x/64] |= (1<<((x%64)/2)); }
int main()
{
	ios_base::sync_with_stdio(0);
	RESET(marked,0);
	ll cnt=0;
	cin >> n;
	seive();
	FOR(i,2,100000000)
	{
		if(isPrime(i))
		{
			cout << i << " ";
			cnt++;
		}
		if(cnt==n)	break;
	}
	return  0;
}

void seive(void)
{
	ll i,j,n=100000000;
	for(i=3;i*i<n; i+=2)
	{
		if(!on(i))
		{
			for(j=i*i;j<=n;j += i+i)
			{	
				mark(j);
			}
		}
	}
}
bool isPrime(ll x)
{
	return x>1 && ((x==2) || (x&1 && !on(x)));
}







//?

