#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 2000000000;

int main() {

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif

	int n, a[112345],b[112345];

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b,b+n);

	int m = *max_element(a,a+n);
		
	for(int i = 0; i < n; ++i) {
		int p,q;
		p = b[i];
		if(b[i] & 1)
			q = p+1;
		else 
			q = inf;

		for(int j = 0; j < n; ++j) {
			if(a[j] == p) {
				if(a[j] & 1)
					a[j]++;
				else
					a[j]--;
			}
		}
		if(q != inf) {
			for(int j = 0; j < n; ++j) {
				if(a[j] == q) 
					a[j]--;
			}
		}
	}

	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}