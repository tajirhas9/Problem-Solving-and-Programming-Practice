#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vl;
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
vector < ll > v;

vector < ll > steps[10000];

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

ll processor(){
 	int N=v.size();
    ll sum = 1e18;
    ll num = sum;
 	for(int i=1;i<(1<<N);i++){
        ll ct=1;
 		for(int k=0;k<N;k++) {
                if( i & (1<<k) )
                    ct=lcm(ct,v[k]);
 		}
		if(1 & __builtin_popcount(i))
            sum+=num/ct;
		else
            sum-=num/ct;
        cout << sum << endl;
	}
	return sum;
}

int main() {

    sieve(10000000);

    long long b,c;

    cin >> b;

    c = b;

    for(int i = 0; prime[i] <= c; ++i) {
        if(c % prime[i] == 0) {
            v.pb(prime[i]);
            while(c % prime[i] == 0)
                c /= prime[i];
        }
    }

   cout << processor() << endl;


    return 0;
}

