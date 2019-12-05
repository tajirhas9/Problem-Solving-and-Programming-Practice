#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n;
		cin >> n;

		int nimsum = 0 , ones = 0;

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			nimsum ^= x;
			ones += (x==1);
		}

		cout << "Case " << kase << ": ";

		if(ones == n) {
			if(ones & 1)
				cout << "Bob" << endl;
			else
				cout << "Alice" << endl;
		}
		else {
			cout << ((nimsum==0)? "Bob" : "Alice") << endl;
		}
	}

	return 0;
}