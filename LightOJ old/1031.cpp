#include <bits/stdc++.h>
using namespace std;

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


int n;
int a[1123];
int dp[112][112];

int solve(int l, int r) {
	if(l > r)	return 0;

	int &ret = dp[l][r];

	if(ret != -1)	return ret;

	ret = -2000000000;

	int sum = 0;
	for(int i = l; i <= r; ++i) {
		sum += a[i];
		ret = max(ret, sum-solve(i+1,r) );
	}
	sum = 0;
	for(int i = r; i >= l; --i) {
		sum += a[i];
		ret = max(ret , sum-solve(l,i-1));
	}
	dbg(l,r,ret);
	return ret;
}

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> n;

		memset(dp,-1,sizeof(dp));

		for(int i = 1; i <= n; ++i)
			cin >> a[i];

		cout << "Case " << kase << ": ";

		cout << solve(1,n) << endl;
	}

	return 0;
}