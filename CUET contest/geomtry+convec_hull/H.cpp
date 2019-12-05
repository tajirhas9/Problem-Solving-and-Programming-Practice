#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-9;

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

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	

	int T;
	scanf("%d",&T);
	
	for(int kase = 1; kase <= T; ++kase) {
		
		double r1,r2,r3;

		scanf("%lf %lf %lf" , &r1, &r2, &r3);

		double a = r2 + r3;
		double b = r1 + r3;
		double c = r1 + r2;
		
		double s = (a+b+c);
		s *= 0.5;

		double triangleArea = s * (s - a) * (s - b) * (s - c);
		
		triangleArea = sqrt(triangleArea);

		double A = b*b + c*c - a*a;
		A /= (2 * b * c) ;
		A = acos(A);
		A *= 180;
		A /= PI;

		double B = c*c + a*a - b*b;
		B /= (2*c*a);
		B = acos(B);
		B *= 180;
		B /= PI;

		double C = a*a + b*b - c*c;
		C /= (2*a*b);
		C = acos(C);
		C *= 180;
		C /= PI;


		double curveArea1 = A * r1 * r1;
		double curveArea2 = B * r2 * r2;
		double curveArea3 = C * r3 * r3;

		double curveArea = curveArea1 + curveArea2 + curveArea3;

		curveArea *= PI;
		curveArea /= 360;
		double res = triangleArea - curveArea;

		printf("Case %d: %0.10lf\n", kase, res);
	}
	

	return 0;
}