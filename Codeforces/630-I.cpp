#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;

	cin >> n;

	ll res1 = 4 * 3;	//4 types  * adjacent cell with 3 choices

	for(ll i = 1; i <= n-3; ++i)
		res1 *= 4;
	res1 *= 2;		// first and last n successive;


	ll res2 = 3 * 4 * 3;	// adjacent cell * 4 types successive * adjacent cell

	for(ll i = 1; i <= n-4; ++i)
		res2 *= 4;

	res2 *= (n-3);

	cout << res1+res2 << endl;
	

	return 0;
}