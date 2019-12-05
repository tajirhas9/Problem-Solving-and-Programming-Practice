#include <bits/stdc++.h>
using namespace std;

bool secondStepPossible(vector < int > a, int sum) {
	for(auto x : a) {
		if((sum-x)%3==0)
			return true;
	}

	return false;
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
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		string s;

		cin >> s;

		vector < int > a;

		for(auto x : s)
			a.push_back(x-'0');	

		int sum = 0;

		int n = s.size();

		int cnt = 0;

		for(int i = 0; i < n; ++i) {
			sum += a[i];

			cnt += (a[i]%3==0);
		}
		
//		dbg(a,sum,cnt);

		bool flag;

		if(sum % 3 == 0) {
			if(cnt & 1)
				flag = true;
			else
				flag = false;
		}
		else if(secondStepPossible(a,sum)) {
			if(cnt & 1)
				flag = false;
			else
				flag = true;
		}
		else
			flag = false;

		if(n == 1)
			flag = true;

		cout << "Case " << kase << ": ";
		cout << (flag ? "S" : "T") << endl;
	}
	

	return 0;
}