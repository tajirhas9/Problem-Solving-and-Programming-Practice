#include<bits/stdc++.h> /*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;

typedef long long ll;

//Prime Number Generator

char Prime[65001] = {};
void sieve() {
	int i, j;
	for(i = 2; i < 65000; i++) {
		if(Prime[i] == 0) {
			for(j = 2; i*j < 65000; j++)
				Prime[i*j] = 1;
		}
	}
}

long long mod(long long x, long long y, long long m) {
	long long tmp = x, ans = 1;
	while(y) {
		if(y&1) {
			ans *= tmp;
			ans %= m;
		}
		tmp = tmp*tmp, tmp %= m;
		y >>= 1;
	}
	return ans;
}

int main()
{
	#ifdef tajir
	//	freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
//	optimize();
	
	sieve();

	ll n;

	while( scanf("%lld",&n) == 1 && n) {
		ll i;
		for(i = 2; i <= n-1; ++i) {
			if(mod(i,n,n) != i)	break;
			else	continue;
		}
		if(i == n && Prime[n] == 1)
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}
	
	
	return 0;
}






//?
