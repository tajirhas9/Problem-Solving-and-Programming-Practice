#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,s=0,x,cnt=0;
	bool vis[10000];
	memset(vis,false,sizeof(vis));
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		s += x;
	}
	for(int i=1; i<=1000; i += (n+1) ) vis[i] = true;
	int i=s;
	while(((++i) - s) <= 5 ) {
		if(!vis[i])	cnt++;
	} 
	cout << cnt << endl;

	return 0;
}