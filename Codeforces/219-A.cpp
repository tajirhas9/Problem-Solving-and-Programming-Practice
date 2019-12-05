#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n;
	int a[30];
	queue <char> q;
	memset(a,0,sizeof(a));

	cin >> n;
	cin >> s;

	for(int i = 0; i < s.size(); ++i)
		a[(s[i] -'a') ]++;

	for(int i = 0; i < 26; ++i) {
		if(a[i] % n != 0) {
			cout << -1 << endl;
			return 0;
		}
	}
/*	int cnt = -1;
	for(int i = 0; i < 26; ++i) {
		if(a[i] != 0) {
			if(cnt == -1 )	{ cnt = a[i]; continue; }
			if(a[i] != cnt) {
				cout << -1 << endl;
				return 0;
			}
		}
	}*/
	for(int i = 0; i < 26; ++i) {
		if(a[i] != 0) {
			for(int j = 1; j <= (a[i]/n); ++j )
				q.push( (i+'a') );
		}
	}
	queue <char> temp;
	for(int i = 1; i <= n; ++i) {
		while(!q.empty()) {
			temp.push(q.front());
			cout << q.front();
			q.pop();
		}
		while(!temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
	}
	return 0;
}