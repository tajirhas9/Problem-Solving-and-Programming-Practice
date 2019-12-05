#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b)	for(i = a; i <= b; ++i)
#define repR(i,a,b)	for(i = a; i >= b; --i)
int main() {
	string s;
	int x,i,len,p;
	
	cin >> s;
	len = s.length();
	p  = -1;
	int pre = (s[len-1]-'0');
	rep(i,0,len - 1) {
		x = s[i]-'0';
		if( !( x & 1 ) && (x < pre) ) {
			p = i;
			break;
		}
	}
	if(p == -1) {
		repR(i,len-1,0) {
			x = s[i]-'0';
			if( !( x & 1 ) ) {
				p = i;
				break;
			}
		}
	}
	if(p == -1)
		cout << -1 << endl;
	else {
		swap(s[p], s[len-1]);
		cout << s << endl;
	}
	return 0;
}