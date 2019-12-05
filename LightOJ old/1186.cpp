#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n;
		cin >> n;
		int nimsum = 0;
		vector < int > a(n) , b(n);

		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];

		for(int i =0 ; i < n; ++i)
			nimsum ^= (b[i] - a[i] - 1);
		cout << "Case " << kase << ": ";
		if(nimsum == 0)
			cout << "black wins" << endl;
		else
			cout << "white wins" << endl;
	}
}