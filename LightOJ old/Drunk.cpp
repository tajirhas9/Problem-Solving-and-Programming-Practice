#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
map<pair<string,string>,bool> m;
int main()
{
	//optimize();
	ll i,j,k,t,n;
	scanf("%lld",&t);
	rep(k,1,t)
	{
		m.clear();
		bool ans=true;
		string a,b;
		scanf("%lld",&n);
		rep(i,1,n)
		{
			cin >> a >> b;
			if(m[mp(b,a)])	ans=false;
			else m[mp(a,b)] = true;
		}
		if(!ans)	printf("Case %lld: No\n",k);
		else 		printf("Case %lld: Yes\n",k);
	}
	return 0;
}













//?


