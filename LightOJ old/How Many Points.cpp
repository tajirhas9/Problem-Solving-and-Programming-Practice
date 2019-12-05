#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll i,a,b,c,d,T;
	cin >> T;
	for(ll i = 1; i <= T; ++i) {
		cin >> a >> b >> c >> d;
		cout << "Case " << i << ": ";
		cout << __gcd( abs(a-c) , abs(b-d) ) + 1 << endl;
	}
	return 0;
}