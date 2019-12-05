#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt","r",stdin);

	int n;
	cin >> n;
	vector < int > a(n) , b(n);

	for(int i =0 ; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];

	int x = 0 , y = 0;

	for(int i = 1; i <= n; ++i) {
		int s = 0,pre=0;
		for(int j = 0; j < i; ++j)
			s |= a[j];
		x = max(s , x);
		for(int j = i; j < n; ++j) {
			s |= a[j];
			s |= ~a[pre];
			pre++;
			x = max(s,x);
		}
	}

	for(int i = 1; i <= n; ++i) {
		int s = 0,pre=0;
		for(int j = 0; j < i; ++j)
			s |= b[j];
		y = max(s , y);
		for(int j = i; j < n; ++j) {
			s |= b[j];
			s |= ~b[pre];
			pre++;
			y = max(s,y);
		}
	}
	cout << x + y << endl;

	return 0;
}