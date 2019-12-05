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
		long long area, b = 0 , res;

		scanf("%d",&n);

		vector < Vector < long long > > p(n,Vector<long long>());

		for(int i = 0; i < n; ++i)
			scanf("%lld %lld" , &p[i].x , &p[i].y);

		area = AreaOfPolygon(p);

		b = TotalBorderPoints(p);

		res = area + 1 - (b / 2) ;			// area = i + b/2 - 1 -> i = area + 1 - b/2

		res = max(res , 0ll);

		printf("Case %d: %lld\n", kase,res);
	}
	

	return 0;
}