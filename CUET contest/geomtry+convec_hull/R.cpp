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
};


int main() {
	
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	

	int n,x0,y0;

	cin >> n >> x0 >> y0;

	vector < pair < int , int > > v(n);

	for(int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	vector < Line < int > > lines;

	for(int i = 0; i < n; ++i)
		lines.push_back(Line<int>(v[i].first , v[i].second , x0, y0));

	set < pair < pair < int , int > , int > > Set;

	for(auto l : lines)
		Set.insert(make_pair(make_pair(l.a , l.b) , l.c));

	cout << Set.size() << endl;

	return 0;
}