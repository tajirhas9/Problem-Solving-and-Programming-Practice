#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector < ll > a;

bool isOk(ll k) {
	
	int j = 0;

	for(int i = 0; i < n; ++i) {
		int d = a[i] - j;

		if(d > k)	return false;
		if(d == k)
			k--;
		j = a[i];
	}

	return true;
}

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

		a.resize(n);

		for(int i = 0; i < n; ++i)
			cin >> a[i];

		ll lo = 0 , hi = 1e15;
		int loop = 400;

		while(lo < hi && loop--) {
			ll mid = (lo+hi)/2;

			if(isOk(mid))
				hi = mid;
			else
				lo = mid+1;
		}	

		if(isOk(hi) && hi > lo)
			lo = hi;
	
		cout << "Case " << kase << ": " << lo << endl;
	}
	

	return 0;
}