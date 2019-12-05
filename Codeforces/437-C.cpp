#include <bits/stdc++.h>
using namespace std;
int main() {
//	freopen("input.txt", "r" , stdin);
	int n,m,v[1002],x,y,ans=0;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int i = 1; i <= m; ++i) {
		cin >> x >> y;
		ans += min(v[x] , v[y]);
	}
	cout << ans << endl;
	return 0;
}