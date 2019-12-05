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
		
		string s;

		cin >> s;

		vector < int > a;

		for(auto x : s)
			a.push_back(x-'0');	

		int sum = 0;

		int n = s.size();

		for(int i = 0; i < n; ++i)
			sum += a[i];

		cout << sum << endl;
	
		cout << "Case " << kase << ": ";
	}
	

	return 0;
}