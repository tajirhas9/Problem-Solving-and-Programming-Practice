#include<bits/stdc++.h> 
using namespace std;

//typedefs

typedef long long ll;


#define RESET(a,b)	memset(a,b,sizeof(a))

//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int n;
int x[20], y[20];

int dp[(1<<20)];

int Map[20][20];

bool collinear(int i, int j, int k) {
  return ((x[i] - x[j]) * (y[k] - y[j]) - (y[i] - y[j]) * (x[k] - x[j])) == 0;
}

int solve(int mask) {
//	dbg(mask);
	if(mask == (1<<n)-1)	return 0;

	int &ret = dp[mask];

	if(ret != -1)	return ret;

	if (__builtin_popcount(mask) == (n - 1))
    	return ret = 1;
	
	int idx = 0;

	for(int i = 0; i < n; ++i) {
		if(!checkBit(mask,i)) {
			idx = i;
			break;
		}

	}

	ret = 100000;

	for(int i = 0; i < n; ++i) {
		if(checkBit(mask,i))	continue;

		ret = min(ret , 1+solve(mask | Map[idx][i]));
	}

	return ret;
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cout << "Case " << kase << ": ";

		cin >> n;

		for(int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];

		RESET(Map,0);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j)	continue;
				for(int k = 0; k < n; ++k) {
					if(collinear(i,j,k))
						Map[i][j] = setBit(Map[i][j],k);
				}
			}
		}

//		dbg(Map);
		RESET(dp,-1);

		cout << solve(0) << endl;
	}
	
	return 0;
}






//?
