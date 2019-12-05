#include <bits/stdc++.h>
using namespace std;

#define MOD 1000007

typedef long long ll;

//debug
#ifdef tajir
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
			os << *it;
	}
	return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
			os << *it;
	}
	return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
		}
	return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () {
	cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
	cerr << arg << ' ';
	faltu(rest...);
}
#else
#define dbg(args...)
#endif // tajir



void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
ll modInverse(ll a) { return modPow(a, MOD-2); }
ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		ll K,C,n,a0;

		cin >> K >> C >> n >> a0;

		--n;

		ll sum = 0;

		vector < ll > a(n+1) , cum(n+1);

		a[0] = a0;

		cum[0] = a[0];

		for(int i = 1; i <= n; ++i) {
			a[i] = (K * a[i-1] + C ) % MOD;
		}

		// Due to the absolute values of the differences, every number will appear before or after.So the ordering doesn't matter
		sort(a.begin() , a.end());

		for(int i = 1; i <= n; ++i)
			cum[i] = cum[i-1] + a[i];

		for(int i = 0; i < n; ++i) {
			ll x,y;
			x = cum[n] - cum[i];

			y = (n-i) * a[i];

//			dbg(x,y);

			sum += (x-y);
		}
	
		cout << "Case " << kase << ": " << sum << endl;
	}
	
	return 0;
}