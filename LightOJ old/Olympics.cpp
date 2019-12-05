#include <bits/stdc++.h>
using namespace std;

#define sqr(a) ((a) * (a))

const double PI = acos(-1.0);
const double eps = 1e-9;

double a,b;

double isOk(double l) {
   double r,theta,s;

   r = 1 + (sqr(b) / sqr(a));
   r = sqrt(r);
   r *= l;
   r /= 2;

   theta = 2*r*r - sqr( (b*l)/a );
   theta /= (2*r*r) ;
   theta = acos(theta);
   s = r*theta;

   return s+l;
}

int main() {
    #ifdef WIN64
        freopen("input.txt","r",stdin);
    #endif // WIN64

    int T;

    scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase) {
        scanf("%lf : %lf",&a,&b);
        double lo = 0 , hi = 100000000000;
        int loop = 100000;

        while( (hi-lo) > eps && loop-- ) {
            double mid = (lo+hi)/2;
            double s = isOk(mid);
            if(abs(s-200) <= eps) {
                lo = mid;
                break;
            }
            if( s < 200)
                lo = mid;
            else
                hi = mid;
        }
        printf("Case %d: %0.10lf %0.10lf\n", kase, lo , (b*lo)/a );
    }

    return 0;
}
