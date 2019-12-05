#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n,m=0,tot=0;

		cin >> n;

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			tot += abs(x);
			m += (x>0);
		}
		if(m == 0)
			cout << "Case " << kase << ": inf" << endl;
		else
			cout << "Case " << kase << ": " << tot/__gcd(tot,m) << "/" << m / __gcd(tot,m) << endl;
	}
	return 0;
}