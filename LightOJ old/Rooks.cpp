#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k;

ll solve(ll n, ll m, ll k) {
	if(k > n || k > m) 	return 0;
	if(k == 0)	return 1;
	if(m == 1)	return n;

	return n*solve(n-1,m-1,k-1) + solve(n,m-1,k);
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
		cin >> n >> k;
		cout << "Case " << kase << ": ";
		cout << solve(n,n,k) << endl;
	}
	return 0;
}