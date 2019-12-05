/*
* https://reponroy.wordpress.com/2015/04/21/lightoj-1396-palindromic-numbers-iii-spoj-pallin/
*/

#include <bits/stdc++.h>
using namespace std;

/*
* corner case 1 : string length = 1
* corner case 2 : all characters are '9'

* mirror the string. If it is greater than the input string, this is the answer
* otherwise:
* increament the first digit < 9 from len/2 to 0;
* due to this increament, all the positions between that index and its mirror index need to be zero ( to minimize the string)

*/

bool allNine(string s) {
	for(auto x : s) {
		if(x != '9')	return false;
	}
	return true;
}

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	

	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		string s;

		cin >> s;
	
		cout << "Case " << kase << ": ";
		
		if(s.size() == 1) {
			if(s == "9")
				cout << "11" << endl;
			else
				cout << (char)(s[0]+1) << endl;	
			continue;
		}

		if(allNine(s)) {
			cout << "1";
			for(int i = 1; i < s.size(); ++i)
				cout << '0';

			cout << '1' << endl;
			continue;
		}

		int len = s.size();

		string r;

		r.resize(len);

		for(int i = 0; i < (len+1)/2; ++i)
			r[i] = r[len-i-1] = s[i];

		if(r > s) {
			cout << r << endl;
			continue;
		}

		int id = 0;

		for(int i = len/2; i >= 0; --i) {
			if(r[i] != '9') {
				id = i;
				break;
			}
		}

		r[id] = r[len-id-1] = (char)(r[id]+1);

		for(int i = id+1; i < len-id-1; ++i)
			r[i] = '0';

		cout << r << endl;
	}
	

	return 0;
}