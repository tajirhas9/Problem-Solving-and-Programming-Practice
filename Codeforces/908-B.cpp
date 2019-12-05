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
ll i,j,k,a,b,c,d,n,m,cnt=0;
ll u,dwn,r,l,dirL;
char dir[123];
vector<char> v[100];
ll fx[] = {0,0,1,-1};
ll fy[] = {1,-1,0,0};
pii start,fin;
void dfs(pii s,ll d);
bool flag = false;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(j=0;j<m;j++)
		{
			v[i].pb(s[j]);
			if(s[j]=='S')	{ start.first = i; start.second = j; }
			if(s[j]=='E')	{ fin.first = i; fin.second = j; }
		}
	}
	cin >> dir;
	dirL = strlen(dir);
	dirL--;
	FOR(a,0,3)
	FOR(b,0,3)
	{
		if(a==b)	continue;
		FOR(c,0,3)
		{
			if(c==a || c==b)	continue;
			FOR(d,0,3)
			{
				if(d==a || d==b || d==c)	continue;
				u = a; dwn = b; l = c; r = d;
				dfs(start,0);
				if(flag)
				{
					//cout << a << " " << b << " " << c << " " << d << endl;
					cnt++;
					flag = false;
				}
			}
		}
	}
	cout << cnt << endl;
	return  0;
}
void dfs(pii xy,ll index)
{
	if(xy==fin)	{ flag = true; return; }
	if(index>dirL)	{flag = false; return; }
	if(xy.first>=0 && xy.first <n && xy.second>=0 && xy.second < m && 
	(v[xy.first][xy.second]=='.' || v[xy.first][xy.second]=='S' || v[xy.first][xy.second]=='E'))
	{
		pii pos,go;
		ll p;
		p = dir[index]-'1';
		p++;
		if(p==u)
		{
			pos.first = xy.first+0;
			pos.second = xy.second-1;
		}
		if(p==dwn)
		{
			pos.first = xy.first+0;
			pos.second = xy.second+1;
		}
		if(p==l)
		{
			pos.first = xy.first-1;
			pos.second = xy.second+0;
		}
		if(p==r)
		{
			pos.first = xy.first+1;
			pos.second = xy.second+0;
		}
		dfs(pos,index+1);
	}
	else
	{
		flag = false;
		return;
	}
}











//?

