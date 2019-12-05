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
	friend bool ccw(Vector < T >& a, Vector <T>& b, Vector <T>& c) {
		return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
	}

	//Check if points are clockwised
	friend bool cw(Vector < T >& a, Vector <T>& b, Vector <T>& c) {
		return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
	}

	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	//Polygon

	//Area of a Polygon with four points given
	friend T AreaOfPolygon(Vector <T>& a, Vector<T>& b, Vector<T>& c, Vector<T>& d) {
		
		T ax[] = {a.x , b.x , c.x , d.x};
		T ay[] = {a.y , b.y , c.y , d.y};
		T area;

		bool flag = cw(a,b,c);

		for(int i = 0; i < 4; ++i) {
			int j = (i+1)%4;
			if(j < 0)	j += 4;

			area += (ax[i] * ay[j]);
		}

		for(int i = 3; i >= 0; --i) {
			int j = (i-1)%4;
			if(j < 0)	j += 4;

			area -= ax[i] * ay[j];
		}

		area /= 2;

		area = (flag ? -area : area);

		return area;
	}
};


int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		Vector < int >  a,b,c;

		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

		Vector < int > d;

		d.x = a.x + c.x - b.x;

		d.y = a.y + c.y - b.y;

		int area = AreaOfPolygon(a,b,c,d);
	
		cout << "Case " << kase << ": " << d << " " << area << endl;
	}
	
}