#include <bits/stdc++.h>
using namespace std;
#define MAX 5000000+5
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
//#define pb(x)		emplace_back(x)
#define pb(x)		push_back(x)
#define all(c)		c.begin(),c.end()
#define F 			first
#define S 			second
#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b)	__gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))
typedef unsigned long long ll;
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
int primeMarked[MAX/64 + 2];
inline bool on(ll x) 					{ return (primeMarked[x/64] & (1<<((x%64)/2))); };
inline void mark(ll x)					{ primeMarked[x/64] |= (1<<((x%64)/2)); };
void sieve(ll n) {
    for (int i=3; i*i<n; i+=2) {
        if (!on(i)) {
            for (int j=i*i; j<=n; j+=i+i) {
                mark(j);
            }
        }
    }
}
inline bool isPrime(int num) { return num > 1 && (num == 2 || ((num & 1) && !on(num))); }
//ll fx[] = {1,1,-1,-1};
//ll fy[] = {1,-1,1,-1};
vector<int> primes;
ll phi[MAX+1];
int main()
{
	int i,j,k;
	sieve(MAX);
	rep(i,2,MAX)
	{
		if(isPrime(i))	primes.pb(i);
	}
	rep(i,1,MAX)	phi[i] = i;
	rep(i,0,primes.size()-1)
	{
		for(j=primes[i]; j<=MAX; j+=primes[i])	phi[j] -= phi[j]/primes[i];
	}
	phi[0] = phi[1] = 0;
	rep(i,2,MAX)
	{
		//cout << phi[i] << " ";
		phi[i] *= phi[i];
		phi[i] += phi[i-1];
		//cout << phi[i] << endl;
	}
	scanf("%d",&k);
	rep(i,1,k)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case %d: %llu\n",i,phi[b]-phi[a-1]);
	}
	return 0;
}













//?

