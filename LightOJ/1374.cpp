#include <bits/stdc++.h>
using namespace std;


int n;
vector < int > a;
vector < int > db;

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		cin >> n;

		a.resize(n);

		int mx = 0;

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			mx = max(mx ,a[i]);

		}

		db.assign(mx+1, 0);

		for(auto x : a)
			db[x]++;

		bool flag = true;

		int lim = n/2 + (n&1);

		for(int i = 1; i <= lim; ++i) {
			int p1,p2;
			p1 = i-1 , p2 = n-i;

//			dbg(i , p1 , p2 , db[p1] , db[p2]);

			if(n & 1 && i == lim) {
				if(db[p1] > 0 || db[p2] > 0) 	continue;
			}

			if(db[p1] > 0 && db[p2] > 0 && p1 != p2) {
				db[p1]-- , db[p2]--;
			}
			else if(db[p1] > 1) {
				db[p1] -= 2;
			}
			else if(db[p2] > 1) {
				db[p2] -= 2;
			}
			else {
				flag = false;
				break;
			}
		}
	
		cout << "Case " << kase << ": " << (flag ? "yes" : "no") << endl;
	}
	
	return 0;
}