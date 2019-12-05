#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; ++kase) {
		int n,k;
		string s;

		cin >> n >> k;

		for(char i = 'A'; i < 'A'+n; ++i)
			s += i;

		cout << "Case " << kase << ":" << endl;
		cout << s << endl;
		--k;
		while(next_permutation(s.begin(),s.end()) && k--)
			cout << s << endl;
	}
	return 0;
}
