#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b)	for(i = a; i <= b; ++i)

int main() {
	int i,n,d[1123], sum[1123], a,b;
	cin >> n;
	rep(i,2,n) cin >> d[i];
	sum[1] = 0;
	d[1] = 0;
	rep(i,2,n)	sum[i] = sum[i-1] + d[i];
	cin >> a >> b;
	cout << sum[b] - sum[a] << endl;
	return 0;
}