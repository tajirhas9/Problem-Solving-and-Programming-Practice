#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,x[300];
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i];
	sort(x,x+n);
	int lo = 1 , hi = 103;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		bool f = true;
		for(int i = 0; i < n; ++i) {
			if(x[i] < i/mid)
				f = false;
		}
		if(f)
			hi = mid;
		else
			lo = mid+1;
	}
	cout << lo << endl;
	return 0;
}