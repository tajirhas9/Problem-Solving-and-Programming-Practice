#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,T;

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d %d",&n,&m);

		int nm = n * m;
		int ans;

		if(n == 1 || m == 1) 
			ans = nm;
		else if(n == 2 || m == 2) {
			int x = (m == 2) ? n : m;
			if(x % 4 == 3)
				ans = x+1;
			else
				ans = x + x%4;
		}
		else if(nm & 1)
			ans = nm/2+1;
		else
			ans = nm/2;
		printf("Case %d: %d\n", kase, ans);
	}
	return 0;
}