#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#endif

	ll n;

	cin >> n;

	while(n--) {
		ll c,s;
		cin >> c >> s;

		ll res = 0;

		while(s % c != 0) {
			ll rem = s%c;

			res += rem;

			s -= rem;
			c -= rem;
		}

		res += (s / c) * (s/c) * c;

		cout << res << endl;
	}
	return 0;
}
