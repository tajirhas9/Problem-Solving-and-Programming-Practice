#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	ll n,p,a,b;

	cin >> n >> p >> a >> b;

	ll x,y,g;

	if(!find_any_solution(a,b,p,x,y,g)) {
		cout << -1 << endl;
	}
	else {
			ll f1 = b/g;
			ll f2 = a/g;

			ll k = (n-x)/f1;

			x = x + k * f1;

			k = (y-n)/f2;

			y = y - k * f2;

			cout << x << " " << y << " " << (n-x-y) << endl;
		}

	return 0;
}