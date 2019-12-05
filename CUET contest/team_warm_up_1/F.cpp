#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
	string r = s;

	reverse(s.begin() , s.end());

	return s == r;
}

int main() {
/*
	#ifdef tajir
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#else
		//online submission
	#endif
	
*/
	string s;

	bool first = true;

	while(getline(cin , s)) {
		if(s == "DONE")
			break;

		string r;

		r.clear();
		for(auto& x : s)
			x = tolower(x);

		for(auto x : s) {
			if(x >= 'a' && x <= 'z')
				r += x;
		}

		cout << (isPalindrome(r) ? "You won't be eaten!" : "Uh oh.." ) << endl;
	}
	return 0;
}