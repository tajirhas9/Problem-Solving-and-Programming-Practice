#include <bits/stdc++.h>
using namespace std;

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


int n,len;
vector < int > b;
ll dp[40][40][2];

void gen() {
	int num = n;

	while(num) {
		int r = num%2;
		b.push_back(r);
		num /= 2;
	}
	len = b.size();
}

ll solve(int pos, int cnt, int pre, int lim) {
//	dbg(pos,cnt,pre,lim);
	if(pos < 0)	return cnt;

	ll &ret = dp[pos][cnt][pre];

	if(lim && ret != -1)	return ret;

	ret = 0;

	int msb = (!lim ? b[pos] : 1);

	for(int i = 0; i <= msb; ++i) {
		if(pre && i == 1)
			ret += solve(pos-1,cnt+1,i,lim||b[pos]>i);
		else
			ret += solve(pos-1,cnt,i,lim||b[pos]>i);
	}
//	dbg(ret);
	return ret;
}

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	#else
		//online submission
	#endif
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		memset(dp,-1,sizeof(dp));

		cin >> n;

		gen();

		ll ret = solve(len-1,0,0,0);

		cout << "Case " << kase << ": " << ret << endl;
		b.clear();
	}
	
}