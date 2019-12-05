#include <bits/stdc++.h>
using namespace std;

int main() {

	int n,m,x,y,cnt=0;
	bool vis[101];
	
	memset(vis,false,sizeof(vis));
	
	cin >> n >> m;

	for( int i = 1; i<= n; i++ ) {
		cin >> x;
		while(x--)	{
			cin >> y;
			vis[y]  = true;
		}
	}
	for(int i=1;i<=100; i++)	{
		if(vis[i])	{
			cnt++;
		}
	}
	(cnt>=m) ? cout << "YES" << endl : cout << "NO" << endl;
	return 0; 
}