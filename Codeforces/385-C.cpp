#include <bits/stdc++.h>
using namespace std; 

#define mx 3200

int a[10000002];
bool base[mx+7];
int primes[mx];

void sieve() {
	int x = sqrt(mx);
	for(int i = 3; i <= x; i += 2) if(!base[i]) for(int j = i*i, k = (i<<1); j < mx; j += k) base[j] = 1;

	primes[0] = 2;
	for(int i = 3, j = 1; i < mx; i += 2) if(!base[i]) primes[j++] = i;
}

void calculate(int n) {
	int x = sqrt(n);

	for(int i = 0; primes[i] <= x; ++i) {
		if(n%primes[i] == 0) {
			++a[primes[i]];
			while(n%primes[i] == 0) n /= primes[i];
		}
	}
	if(n > 1) ++a[n];
}

int main() {
	sieve();

	int n, u, v, m;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i) { scanf("%d", &u); calculate(u); }

	for(int i = 2; i <= 10000000; ++i) a[i] += a[i-1];

	scanf("%d", &m);
	while(m--) {
		scanf("%d %d", &u, &v);
		if(v > 10000000) v = 10000000;
		if(u > 10000000) u = 10000000;
		printf("%d\n", a[v]-a[u-1]);
	}

	return 0;
}