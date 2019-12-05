#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[412345] , sum[412345];

int main() 
{
	#ifdef tajir
		freopen("input.txt", "r" , stdin);
	#else
		//online submission
	#endif
	cin >> n >> m;
	sum[0] = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	ll ans = 0;
	for(int i = 1 , j = 1; i <= n && j <= n ;) {
		if(sum[j] - sum[i-1] <= m) {
			ans = max(ans, sum[j] - sum[i-1] );
			++j;
		}
		else
			++i;
	}
	cout << ans << endl;

	return 0;
}