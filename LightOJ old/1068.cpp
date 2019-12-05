#include<bits/stdc++.h>
using namespace std;

#define optimize() 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(c) 			c.begin(),c.end()

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

string a,b;
int k,n;
int dp[20][110][100][3][3];

int solve(int pos, int rem, int sod, int f1, int f2) {
	if(pos < 0)	return rem==0&&sod==0;

	int &ret = dp[pos][rem][sod][f1][f2];

	if(ret != -1)	return ret;

	int low = (f1 ? 0 : a[pos]-'0');
	int high = (f2 ? 9 : b[pos]-'0');

	if(high < low)
		high = 9;

	ret = 0ll;

	dbg(pos,low,high);

	for(int i = low; i <= high; ++i) {
		int _rem = ((rem*10)%k +i)%k;
		int _sod = (sod+i)%k;
		int _f1 = f1 || (i > a[pos]-'0');
		int _f2 = f2 || (i < b[pos]-'0');

		ret += solve(pos-1,_rem,_sod,_f1,_f2);
	}

	return ret;
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
	
		memset(dp,-1,sizeof(dp));

		cin >> a >> b >> k;

		reverse(all(a));
		reverse(all(b));

		while(a.size() < b.size())
			a += '0';

//		dbg(a,b);
		
		n = a.size();

		int ret = (k>99 ? 0 : solve(n-1,0,0,0,0));	
	
		cout << "Case " << kase << ": " << ret << endl;
	}
	
	
	return 0;
}






//?
