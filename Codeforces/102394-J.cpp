#include <bits/stdc++.h>
using namespace std;


int main() {
	
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
			
		int n;

		cin >> n;

		if(n < 6)
			cout << -1 << endl;
		else if(n & 1) {
			cout << 3 << " " << n-3 << endl;
		}
		else
			cout << 2 << " " << n-2 << endl;
	
	}
	
}