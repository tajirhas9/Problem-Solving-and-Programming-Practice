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
	
	int n,k,m;

	
	
	while(cin >> n >> k >> m) {
		if(n == 0 && m == 0 && k == 0)
			break;

		vector < int > pore(n) , aage(n);

		for(int i = 0; i < n; ++i) {
			pore[i] = (i+1)%n;
			aage[i] = (i-1)%n;
			if(aage[i] < 0)
				aage[i] += n;
		}

//		dbg(aage,pore);

		int baki = n;
		vector < bool > vis(n,false);
		int ami = 0 , tumi = n-1;
		int first = true;

		while(baki > 0) {

			for(int i = 1; i < k; ++i)
				ami = pore[ami];

			for(int i = 1; i < m; ++i)
				tumi = aage[tumi];

			if(first)
				first = false;
			else
				cout << ",";

			if(ami == tumi) {
				cout << fixed << setw(3) << ami+1;

				int eta,sheta;
				eta = aage[ami];
				sheta = pore[ami];

				pore[eta] = sheta;
				aage[sheta] = eta;
				baki--;
				vis[ami] = true;
			}
			else {
				cout << fixed << setw(3) << ami+1;
				cout << fixed << setw(3) << tumi+1;

				int eta,sheta;
				eta = aage[ami];
				sheta = pore[ami];

				pore[eta] = sheta;
				aage[sheta] = eta;
				baki--;

				eta = aage[tumi];
				sheta = pore[tumi];

				pore[eta] = sheta;
				aage[sheta] = eta;
				baki--;

				vis[ami] = vis[tumi] = true;
			}

			int f = n;
			while(vis[ami] && f--)
				ami = pore[ami];
			f = n;
			while(vis[tumi] && f--)
				tumi = aage[tumi];

			bool flag = true;

			for(auto x : vis) {
				flag &= x;
			}

			if(flag)
				break;
		}

		cout << endl;
	}

	return 0;	
}