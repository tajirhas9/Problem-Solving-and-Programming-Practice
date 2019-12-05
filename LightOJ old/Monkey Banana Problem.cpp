#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define MOD 1000000007
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		emplace_back(x)
//#define pb(x)		push_back(x)
#define F 			first
#define S 			second
#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b)	__gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))
typedef long long ll;
ll solve(ll x,ll y);
ll n,store[1234][1234],ans[1234][1234];
int main()
{
	RESET(store,0);
	//freopen("../Rough/input.txt","r",stdin);
	ll i,j,k,t;
	scanf("%lld",&t);
	rep(k,1,t)
	{
		RESET(ans,0);
		RESET(store,-1);
		scanf("%lld",&n);
		ll cnt=n-2;
		rep(i,0,2*n-2)
		{
			if(i<n)
			{
				rep(j,0,i)
					scanf("%lld",&store[i][j]);
			}
			else
			{
				rep(j,0,cnt)
					scanf("%lld",&store[i][j]);
				cnt--;
			}
		}
		//cout << "input end" << endl;
		printf("Case %lld: %lld\n",k,solve(0LL,0LL));
		//cout << ans[0][0] << endl;
	}
	
	return 0;
}
ll solve(ll x,ll y)
{
	ll p,q;
	if(store[x][y]==-1)	return 0;
	if(x==2*n-1 && y==0)	return store[x][y];
	if(ans[x][y])		return ans[x][y];
	p = solve(x+1,y); 
	if(x<(n-1))	q = solve(x+1,y+1);
	else 	q = solve(x+1,max(0LL,y-1));
	//cout << x << " " << y << ": " << p << " " << q << endl;
	ans[x][y] = max(ans[x][y],(max(p,q)+store[x][y]));
	//cout << ans[x][y] << endl;
	return ans[x][y];
}












//?


