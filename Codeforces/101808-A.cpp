#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double const pi = acos(-1.0);
int main() {
	ll R,r;
	int T;
	cin >> T;
	while(T--) {
		cin >> R >> r;
		(pi*R*R > 2*pi*r*r) ? cout << 1 : cout << 2;
		cout << endl;
	}
	return 0;
}