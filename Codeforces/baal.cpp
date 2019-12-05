#include <bits/stdc++.h>
using namespace std;

//typedefs

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

//#Defines

//#define pb push_back
#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define endl '\n'
#define pf printf
#define sf scanf
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

inline void normal(ll &a) { 
	a %= MOD; 
	(a < 0) && (a += MOD); 
}

inline ll modMul(ll a, ll b) { 
	a %= MOD, b %= MOD; 
	normal(a), normal(b); 
	return (a*b)%MOD; 
}

inline ll modAdd(ll a, ll b) { 
	a %= MOD, b %= MOD; 
	normal(a), normal(b); 
	return (a+b)%MOD; 
}

inline ll modSub(ll a, ll b) { 
	a %= MOD, b %= MOD; 
	normal(a), normal(b); 
	a -= b; 
	normal(a); 
	return a; 
}

inline ll modPow(ll b, ll p) { 
	ll r = 1; 
	while(p) { 
		if(p&1) 
			r = modMul(r, b); 
		b = modMul(b, b); 
		p >>= 1; 
	} 
	return r; 
}

inline ll modInverse(ll a) { 
	return modPow(a, MOD-2); 
}

inline ll modDiv(ll a, ll b) { 
	return modMul(a, modInverse(b)); 
}


int main() {
	
	optimize();

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif

	cout << modAdd(1,2) << endl;
	cout << modSub(1,2) << endl;
	cout << modMul(4,2) << endl;
	cout << modDiv(6,3) << endl;
	return 0;
}