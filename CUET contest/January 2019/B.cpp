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


int main() {
//	freopen("input.txt","r",stdin);
	long long a,b;
	int q;
	long long l,r;
	cin >> a >> b;
	if(a > b)
		swap(a,b);

	set < int > Set;
	for(int i = 1; i * i <= max(a,b); ++i) {
		if(a%i == 0 && b%i == 0) {
			Set.insert(i);

			if(a%(b/i) == 0)
				Set.insert(b/i);
			if(b%(a/i) == 0)
				Set.insert(a/i);
		}
	}

	dbg(Set);

	vector < int > v;

	for(auto x : Set)
		v.push_back(x);

	cin >> q;
	while(q--) {
		cin >> l >> r;

		int lo = 0 , hi = v.size()-1,loop=400;

		while(lo < hi && loop--) {
			int mid = (lo + hi)/2;

			if(v[mid] <= r)
				lo = mid;
			else
				hi = mid-1;
		}

		if(v[hi] >= l && v[hi] <= r)
			cout << v[hi] << endl;
		else if(v[lo] >= l && v[lo] <= r)
			cout << v[lo] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}