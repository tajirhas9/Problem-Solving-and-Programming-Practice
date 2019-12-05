#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a)
typedef long long ll;
typedef string string;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setl;
typedef set<string> sets;
typedef set<ll>::iterator setl_it;
typedef set<string>::iterator sets_it;
typedef vector<ll>::iterator vl_it;
typedef vector<string>::iterator vs_it;
struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pii const &a, pii const &b)	
	{
		if(a.first==b.first)
			return (a.second<b.second);
		return (a.first>b.first);
	}
};
int i,j,k,n,m;
int r[2000],c[2000],v[2000][2000];
int main()
{
	ios_base::sync_with_stdio(0);
	int x,y;
	char s;
	scanf("%d %d %d",&n,&m,&k);
	FOR(i,0,n-1)
	FOR(j,0,m-1)
	{
		scanf("%d",&v[i][j]);
		r[i] = i;
		c[j] = j;
	}
	FOR(i,1,k)
	{
		getchar();
		scanf("%c %d %d",&s,&x,&y);
		x--; y--;
		if(s=='g')	printf("%d\n",v[r[x]][c[y]]);
		else if(s=='r')	swap(r[x],r[y]);
		else if(s=='c')	swap(c[x],c[y]);
	}
	
	return  0;
}













//?

