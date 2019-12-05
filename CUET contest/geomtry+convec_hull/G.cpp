#include <bits/stdc++.h>
using namespace std;


template < typename T = double >
class Line {
public:
	T a,b,c;

	Line() : a(1) , b(1) , c(1) {}

	Line(T a,T b, T c) : a(a) , b(b) , c(c) {}

	Line(T x1, T y1, T x2 , T y2) {
		a = y1 - y2;
		b = x2 - x1;
		c = x1 * a + y1 * b;
		c = -c;

		int g = __gcd(a , __gcd(b,c));

		a /= g , b /= g , c /= g;

		if(a < 0) {
			a = -a;
			b = -b;
			c = -c;
		}
	}

	//print the line as ax+by+c ( = 0 is ommitted)
	friend ostream& operator << (ostream& os, Line < T >& line) {
		os << line.a << "x + " << line.b << "y + " << line.c;

		return os;
	}

	friend bool concide(int x, int y , Line<T> l) {
		int res = l.a * x;
		res += l.b * y;
		res += l.c;

		return res == 0;
	}
};

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

typedef pair < pair < int , int > , int > piii;

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	scanf("%d",&T);
	
	for(int kase = 1; kase <= T; ++kase) {
		
		int n;

		scanf("%d",&n);

		vector < pair < int , int > > p(n);

		// O(n) * O(T)
		for(int i = 0; i < n; ++i) {
			scanf("%d %d" , &p[i].first , &p[i].second);
		}	

		// O(nlogn) * O(T)
		sort(p.begin() , p.end());

		int res = 0;
		
		map < pair < pair < int , int > , int > , int > Map;

		vector < piii > lines;

		// O(n*n)
		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {
				if(i == j)	continue;
				Line <int> l = Line<int>(p[i].first , p[i].second , p[j].first , p[j].second);
				pair < pair < int , int > , int > f;
				f.first.first = l.a;
				f.first.second = l.b;
				f.second = l.c;

				lines.push_back(f);
			}
		}

		set < piii > Set;

		//O(nlogn)
		for(auto x : lines)
			Set.insert(x);

		lines.clear();

		//O(nlogn)
		for(auto x : Set)
			lines.push_back(x);

		Line < int > l;

		//O( nC2 * n)
		for(auto x : lines) {
			int cnt = 0;
			for(int i = 0; i < n; ++i) {
				if(concide(p[i].first , p[i].second , Line<int>(x.first.first , x.first.second , x.second)))
					cnt++;
			}
			res = max(res , cnt);
		}
	
		printf("Case %d: %d\n", kase, res);
	}
	

	return 0;
}