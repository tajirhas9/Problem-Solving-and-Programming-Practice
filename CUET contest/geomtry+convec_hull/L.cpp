#include <bits/stdc++.h>
using namespace std;


const double EPS=1e-9;
const double PI=acos(-1);

struct point{
	double x, y; // check the data type
	point(){ x=y=0.0; }
	point(double _x, double _y){ x=_x; y=_y; } // user defined
	bool operator< (point p) const{    // sorting
		if(fabs(x-p.x)>EPS) return x<p.x;
		else return y<p.y;
	}
};

double dist(point p1, point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


struct vec{
     double x, y;
     vec(){x=y=0.0;}
     vec(double _x, double _y){x=_x; y=_y;}
};

vec toVector(point p1, point p2){ return vec(p2.x-p1.x, p2.y-p1.y); }
double dotProduct(vec a, vec b){ return a.x*b.x+a.y*b.y; }

double crossProduct(vec a, vec b) { return a.x * b.y - a.y * b.x; }


bool ccw(point p, point q, point r){ return crossProduct(toVector(p, q), toVector(p, r))>0; }
bool cw(point p, point q, point r) { return crossProduct(toVector(p, q), toVector(p, r))<0; }

double cross(point p1, point p2, point p3){ return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x); }

void ConvexHull(vector < point > &v){
    int n = v.size();

	if(n < 3)	return;

	sort(v.begin() , v.end());

	point p1 = v[0] , p2 = v.back();


	vector < point > up,down;

	up.push_back(p1);
	down.push_back(p1);

	for(int i = 1; i < n; ++i) {
		if(i == n-1 || cw(p1, v[i] ,p2)) {
			while(up.size() >= 2 && !cw(up[up.size()-2] , up[up.size()-1] , v[i]))
				up.pop_back();
			up.push_back(v[i]);
		}
		if(i == n-1 || ccw(p1, v[i] , p2)) {
			while(down.size() >= 2 && !ccw(down[down.size()-2] , down[down.size()-1] , v[i]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	v.clear();

	for(int i = 0; i < up.size(); ++i)
		v.push_back(up[i]);
	for(int i = down.size()-2; i >= 0; --i)
		v.push_back(down[i]);
}

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
		double d;

		scanf("%d %lf",&n,&d);

		vector < point > p(n);

		for(int i = 0; i < n; ++i)
			scanf("%lf %lf",&p[i].x , &p[i].y);


		double res=0.0;

		if(n == 1) {
			res = 2.0 * PI * d;
		}
		else if(n == 2) {
			res = (2.0 * dist(p[0] , p[1])) + 2.0 * PI * d;
		}
		else {
			ConvexHull(p);
			n = p.size();
			for(int i = 0; i+1 < n; ++i) {
				res += dist(p[i] , p[i+1]);
			}

			res += (2.0 * PI * d);
		}

		printf("Case %d: %0.10lf\n", kase, res+EPS);
	}
	
	return 0;
}