#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	bool color = false;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			if(c != 'W' && c != 'B' && c != 'G')	color = true;
		}
	}
	if(color) 
		cout << "#Color" << endl;
	else
		cout << "#Black&White" << endl;
	return 0;
}