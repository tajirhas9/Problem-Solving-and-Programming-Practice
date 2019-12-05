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

#define inf 2e9
int n,k;
string s;
vector < int > v;

int dp[500][500];


int solve(int i, int sz) {
	if(sz < 0)	return inf;

	if(i >= n)	return 0;
	int &ret = dp[i][sz];
//	dbg(i,sz);
	if(ret != -1)	return ret;

	if(s[i] == '0')	return solve(i+1,sz);

	ret = inf;

	int f = i;

	for( ; f < n && s[f] == '1'; ++f){
		int x = f-i;
		ret = min(ret , solve(f+1 , sz-1) + ((x * (x+1))/2));
		if(ret==0)	return ret;
	}
	int x = f-i;
	ret = min(ret , solve(f , sz) + ((x * (x+1))/2));
//	dbg(i,sz,ret);
	return ret;
}

bool isOk(int x) {
//	dbg(x);

	int f = solve(0,x);

	dbg(x,f);
	return f <= k;
}

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	cin >> n >> k;
	cin >> s;
/*
	v.resize(n+1);
	for(int i = 0;i < n; ++i)
		v[i+1] = s[i]-'0';
	dbg(v);*/

	memset(dp,-1,sizeof(dp));

	for(int i = 0; i <= n; ++i) {
		if(isOk(i)) {
			dbg(i);
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}