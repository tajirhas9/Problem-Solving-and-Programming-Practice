#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define pb push_back
#define M 200000005
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))


bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num))); 
}

void sieve(ll n) {
	for (ll i = 3; i * i < n; i += 2) {
		if (!on(i)) {
			for (ll j = i * i; j <= n; j += i + i) {
				mark(j);
			}
		}
	}
}

int main() {
	sieve(200000000);

	long int T,a,b,cnt=0;
	scanf("%lld", &T);
	for(long long kase = 1; kase <= T; kase++ ) {
		cnt = 0;

		scanf("%lld %lld", &a, &b);
		for(ll i = a; i<= b; ++i) {
			if(isPrime(i) ) {
				printf("%lld\n", i);
				cnt++;
			}
		}
		printf("\n");
	//	printf("Case %lld: %lld\n", kase, cnt);
	}
	return 0;
}