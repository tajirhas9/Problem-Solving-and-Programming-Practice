#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RESET(a,b)	memset(a,b,sizeof(a))

//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

ll n,k;
string s;
ll digit[100];
ll dp[25][(1<<20)];

ll solve(ll mask, ll rem) {
//	dbg(mask,rem);
	if(mask == (1<<s.size())-1) {
//		dbg(mask);
		if(rem==0)
			return 1ll;
		return 0ll;
	}
	ll &ret = dp[rem][mask];
	if(ret != -1)	return ret;
	ret = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(!checkBit(mask,i))
			ret += solve(setBit(mask,i) , (rem*n+digit[i])%k );
	}
	return ret;
}

int main()
{
	#ifdef tajir
//		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
//	optimize();
	
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> n >> k;
		cin >> s;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] >= '0' && s[i] <= '9')
				digit[i] = s[i]-'0';
			else
				digit[i] = s[i]-'A'+10;
		}
//		dbg(digit,16);
		RESET(dp,-1);

		cout << "Case " << kase << ": " << solve(0,0) << endl;
	}
	
	return 0;
}






//?
