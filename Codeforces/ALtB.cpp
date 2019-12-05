#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
int main() {
	string s;
	cin >> s;

	int firstb,lastb,firstc,lastc;

	firstb = firstc = inf;
	lastb = lastc = -1;

	for(int i = 0; i < s.size() && firstb == inf || firstc == inf; ++i) {
		if(s[i] == '[' && i < firstb) 
			firstb = i;
		if(s[i] == ':' && i < firstc && i > firstb)
			firstc = i;	
	}
	if(firstc == inf || firstb == inf) {
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = s.size()-1; i > firstc && (lastb == -1 || lastc == -1) ; --i) {
		if(s[i] == ']' && i > lastb)
			lastb = i;
		if(s[i] == ':' && i < lastb && i > lastc)
			lastc = i;
	}
	if(firstb == inf || firstc == inf || lastb == -1 || lastc == -1) {
		cout << -1 << endl;
		return 0;
	}

	int sz = 4;

	for(int i = firstc+1; i < lastc; ++i)
		sz += (s[i] == '|');

	cout << sz << endl;
	return 0;
}