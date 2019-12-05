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
		
		int r,c;

		cin >> r >> c;

		int nimsum = 0;

		for(int i = 1; i <= r; ++i) {
			for(int j = 1; j <= c; ++j) {
				int manhatten = r-i + c-j;

				int x;
				cin >> x;

				if(manhatten & 1)
					nimsum ^= x;
			}
		}	
	
		cout << "Case " << kase << ": " << (nimsum ? "win" : "lose") << endl;
	}

	return 0;
}