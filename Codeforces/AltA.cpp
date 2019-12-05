#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;

	cin >> T;

	while(T--) {
		int l,r,d;
		cin >> l >> r >> d;
		int x = l/d;
		if(l%d==0)
			x--;
		x = min(1,x);
		x = x*d;
		if(x > 0) {
			cout << x << endl;
			continue;
		}
		x = r/d;
		x++;
		x = x*d;
		cout << x << endl;
	}
}