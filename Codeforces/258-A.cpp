#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int i,len = s.size();
	for(i = 0; i < len; ++i) {
		if(s[i] == '0') {
			s.erase(s.begin()+i);
			break;
		}
	}
	if(i == len)
		s.erase(s.begin()+(i-1));
	cout << s << endl;
	return 0;
}