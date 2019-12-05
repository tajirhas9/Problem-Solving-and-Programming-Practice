#include<bits/stdc++.h> 
using namespace std;

#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)

int n;
int a[100005];
long long nCr[100005];

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	
	int T;

	nCr[4] = 1;

	for(int i = 5; i <= 100000; ++i)
		nCr[i] = nCr[i-1]*i / (i-4);

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {

		scanf("%d",&n);

		vector < int >  ff(100005,0);

		for(int i = 1; i <= n; ++i) {
			scanf("%d",&a[i]);

			for(int j = 1; j * j <= a[i]; ++j) {
				if(a[i] % j == 0) {
					ff[j]++;
					if(a[i]/j != j)
						ff[a[i]/j]++;
				}
			}
		}
			
		vector < int >  ans(10005, 0);

		for(int i = 10000; i >= 1; --i) {
			ans[i] = nCr[ff[i]];

			for(int j = i+i; j <= 10000; j += i)
				ans[i] -= ans[j];
		}

		printf("Case %d: %d\n", kase, ans[a[1]] );
	}
	
	return 0;
}






//?
