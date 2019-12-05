#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int r1,c1,r2,c2;

		cin >> r1 >> c1 >> r2 >> c2;
	
		bool f1,f2;
		f1 = abs(r1-r2) & 1;
		f2 = abs(c1-c2) & 1;

		cout << "Case " << kase << ": ";
		if(f1 == !f2) 
			cout << "impossible" << endl;
		else {
			int x,y;
			x = abs(r2-r1);
			y = abs(c2-c1);

			if(x == y)
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
	}
	return 0;
}