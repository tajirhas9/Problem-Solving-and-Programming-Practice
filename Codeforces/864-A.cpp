#include <bits/stdc++.h>
using namespace std;
int cnt[105];
int main(){
	int i,j,n,ans,ans2,c,c2,min,ca = 0;
	cin >> n;

	int a[n];

	for(i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	int mn = min_element(a,a+n) - a;
	int mx = max_element(a,a+n) - a;
	for(j = 1; j <= 100; j++){
		if(cnt[j] == n/2){
			ans = j;
			c = 1;
			break;
		}
	}
	for(j = ans+1; j <= 100; j++){
		if(cnt[j] == n/2){
			ans2 = j;
			c2 = 1;
			break;
		}
	}
	if(c == 1 && c2 == 1){
		cout << "YES" << endl;
		if(mn < mx)
			cout << ans << " " << ans2 << endl;
		else
			cout << ans2 << " " << ans << endl;
	}
	else
		cout << "NO" << endl;
}
