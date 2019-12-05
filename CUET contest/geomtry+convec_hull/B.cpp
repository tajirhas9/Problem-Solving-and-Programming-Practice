#include <bits/stdc++.h>
using namespace std;


template < typename T = double >
class Vector {

public:
	T x,y;

	Vector() {
		x = 0 , y = 0;
	}

	Vector(T x,T y) : x(x) , y(y) {}

	//-----------------------------------------

	//Overloading relational operators
	bool operator ==(const Vector &b) {
		return (x == b.x && y == b.y);
	}

	bool operator <(const Vector &b) {
		return (x < b.x && y < b.y);
	}

	bool operator >(const Vector &b) {
		return (x > b.x && y > b.y);
	}

	bool operator <=(const Vector &b) {
		return (x <= b.x && y <= b.y);
	}

	bool operator >=(const Vector &b) {
		return (x >= b.x && y >= b.y);
	}

	//-----------------------------------------

	//distance between two points
	friend T distance(Vector a, Vector b) {
		T _x = abs(a.x - b.x);
		T _y = abs(a.y - b.y);

		_x *= _x;
		_y *= _y;

		return sqrt(_x+_y);
	}

	friend T squaredDistance(Vector a, Vector b) {
		T _x = abs(a.x - b.x);
		T _y = abs(a.y - b.y);

		_x *= _x;
		_y *= _y;

		return (_x+_y);
	}

	//distance between two points along X axis
	friend T distanceX(Vector a, Vector b) {
		return abs(a.x - b.x);
	}
	
	//distance between two points along Y axis
	friend T distanceY(Vector a, Vector b) {
		return abs(a.y - b.y);
	}

	//-------------------------------------------

	//Print a point (x,y) as "x y"
	friend ostream& operator << (ostream& os, Vector < T >& point) {
		os << point.x << " " << point.y;

		return os;
	}

	//--------------------------------------------

	//Check if points are counter clock wised
	friend bool IsCCW(Vector < T >& a, Vector <T>& b, Vector <T>& c) {
		return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
	}

	//Check if points are clockwised
	friend bool IsCW(Vector < T >& a, Vector <T>& b, Vector <T>& c) {
		return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
	}

	friend T NumberOfLatticePointsInBetween(Vector<T>& a, Vector<T>& b) {
		T _x = abs(a.x - b.x);
		T _y = abs(a.y - b.y);

		return __gcd(_x,_y)+1;
	}

	friend T Cross(Vector<T>& a , Vector<T>&b) {
		return a.x * b.y - b.x * a.y;
	}

	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	//Polygon

	//Area of a Polygon with vertices given
	friend T AreaOfPolygon(vector < Vector < T > >& v) {
		
		T n = v.size();
		T area = 0;

		bool isCW = IsCW(v[0] , v[1] , v[2]);

		for(int i = 0; i < n; ++i) {
			int j = (i+1)%n;
			if(j < 0)	j += n;

			area += Cross(v[i] , v[j]);
		}

		area = fabs(area) * 0.5;

		return area;
	}

	friend T TotalBorderPoints(vector < Vector < T > > &v) {
		T n = v.size();
		long long b = 0;

		for(int i = 0 , j = n-1; i < n; j = i++) {
			
			b += (NumberOfLatticePointsInBetween(v[i] , v[j])-1) ;
		}

		return b;
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

bool comp(Vector< long long > const &a, Vector < long long > const &b) {
	return (a.x < b.x || (a.x == b.x ? a.y < b.y : a.x < b.x));
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
		
		int n;

		cin >> n;

		vector < Vector < long long > > p(n);

		for(int i = 0; i < n; ++i)
			cin >> p[i].x >> p[i].y;

		long long res = 0;

		vector < pair < int , int >  > line;

		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {

				long long x,y;

				x = p[i].x + p[j].x;
				y = p[i].y + p[j].y;

//				long long g = __gcd(x,y);
//				x /= g , y /= g;

				line.push_back(make_pair(x,y));
			}
		}	

		sort(line.begin() , line.end());

		int j = 0;

		for(int i = 1; i < line.size(); ++i) {
			if(line[i] == line[i-1])
				j++;
			else {
				res += (j *(j+1))/2;
				j = 0;
			}
			
		}

		cout << "Case " << kase << ": " << res << endl;
	}
	

	return 0;
}