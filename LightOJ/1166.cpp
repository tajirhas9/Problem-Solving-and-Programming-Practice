#include <bits/stdc++.h>
using namespace std;

int n;
vector < int > a;


int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	

	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		cin >> n;

		a.resize(n+1);

		for(int i = 1; i <= n; ++i)
			cin >> a[i];

		int res = 0;

		for(int i = 1; i <= n; ++i) {
			
			while(a[i] != i) {
				swap(a[i] , a[a[i]]);
				res++;
			}
		}
		
		cout << "Case " << kase << ": " << res << endl;
	}
	
	return 0;
}