#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-18;
int main() {
	double x,y,n,p,q,r,ans = 900000000000000000;
	cin >> x >> y;
	cin >> n;
	while(n--) {
		cin >> p >> q >> r;
		double dist = (p-x)*(p-x);
		dist += (q-y)*(q-y);
		dist = sqrt(dist);
		dist /= r;
		if((ans-dist) > eps)
			ans = dist;
	}
	cout << setprecision(15) << ans << endl;
	return 0;
}