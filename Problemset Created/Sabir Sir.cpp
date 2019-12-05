#include <bits/stdc++.h>
using namespace std;

#define MAX 10000007
typedef long long ll;

ll divisor[MAX],vis[MAX],mark[MAX];
ll v[300],x=0;

void genDiv(ll n) {
	for(ll i=1; i<=n; ++i) {
		for(ll j = i+i; j<=n; j += i) {
			divisor[j] += i;
		}
	}
	for(ll i=1; i<=n; ++i) {
		if(divisor[divisor[i]] == i && i != divisor[i] && divisor[i] <= MAX) {
			vis[i] = 1;
			vis[divisor[i]] = 1;
		}
	}
	for(ll i=1; i<=n; ++i ) {
		if(vis[i])
			v[x++] = i;
	}
}

int main()
{
	genDiv(MAX);
	ll T,n,m,i,p;
	scanf("%lld",&T);
	for(i = 1; i<= T; ++i )	{
		p=0;
		scanf("%lld %lld",&n,&m);
		printf("Case %lld:\n",i );
		for(ll j = 0; j < n; ++j ) {
			for(ll k = 0; k < m; ++k ) {
				printf("%lld ", v[p++]);
			}
			printf("\n");
		}
	}
	return 0;
}

