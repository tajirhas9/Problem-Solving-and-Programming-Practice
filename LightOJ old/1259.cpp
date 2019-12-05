#include<bits/stdc++.h>
using namespace std;

//typedefs

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define endl '\n'

#define RESET(a,b)	memset(a,b,sizeof(a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


//Prime Number Generator


#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

vl prime;

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
	prime.pb(2);
	for(ll i = 3; i <= n; i += 2) {
		if(!on(i))	prime.pb(i);	
	}
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	
	sieve(10000007);
	
	int T;

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {
		int n;
		scanf("%d",&n);

		int cnt = 0;

		for(int i = 0; prime[i] < n; ++i) {
			int x,y;
			x = prime[i];
			y = n - prime[i];

			if(x > y)
				break;

			if(isPrime(y))
				cnt++;
		}

		printf("Case %d: %d\n", kase,cnt);
	}
	
	return 0;
}






//?
