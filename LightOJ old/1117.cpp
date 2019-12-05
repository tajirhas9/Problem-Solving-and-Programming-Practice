#include <bits/stdc++.h>
using namespace std;

#define lcm(a,b) ((a*b) / __gcd(a,b))

int main() {

	int T;

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {
		long long n;
		int m;

		scanf("%lld %d",&n,&m);

		vector < long long > v(m);

		for(int i = 0; i < m; ++i)
			scanf("%lld",&v[i]);

		long long res = 0;

		for(long long mask = 1; mask < (1<<m); ++mask) {
			int bits = 0;
			long long p = 1;
			for(int i = 0; i < m; ++i) {
				if(mask & (1<<i) ) {
					bits++;
					p = lcm(p , v[i]);
				}
			}

			long long x = n / p;

			if(bits & 1)
				res += x;
			else
				res -= x;
		}

		printf("Case %d: %lld\n", kase, n-res);
	}

	return 0;
}