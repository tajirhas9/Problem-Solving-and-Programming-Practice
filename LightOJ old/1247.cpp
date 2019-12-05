#include <bits/stdc++.h>
using namespace std;

int main() {

//		freopen("input.txt","r",stdin);
	
	int T;
	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n,m;
		cin >> n >> m;
		int nimsum = 0;
		for(int i = 0; i < n; ++i) {
			int sum = 0;
			for(int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				sum += x;
			}
			nimsum ^= sum;
		}

		cout << "Case " << kase << ": ";

		cout << ((nimsum == 0)? "Bob" : "Alice") << endl;
	}
	return 0;
}