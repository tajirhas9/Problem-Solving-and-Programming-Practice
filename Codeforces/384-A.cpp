#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define gcd(a,b)	__gcd)(a,b)
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
inline bool isLeapYear(ll y) { return ((y%400==0) || (y%4==0 && y%100!=0)); }
inline void optimize(void) { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
inline bool check(pii go,ll n)	{ return (go.first>=0&&go.first<n&&go.second>=0&&go.second<n); }
const ll mod = 1e9+7;
const double pi = acos(-1.0);
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
ll fx[] = {1,1,-1,-1};
ll fy[] = {1,-1,1,-1};
int main()
{
	optimize();
	ll x,y,i,j,k,n,cnt=0;
	char board[1234][1234];
	bool vis[1234][1234];
	RESET(vis,false);
	cin >> n;
	rep(i,0,n-1)
	rep(j,0,n-1)	board[i][j] = '.';
	queue<pii> q;
	q.push(mp(0,0));
	board[0][0] = 'C';
	while(!q.empty())
	{
		pii top;
		top = q.front();
		q.pop();
		rep(i,0,3)
		{
			pii go;
			go.first = top.first+fx[i];
			go.second = top.second+fy[i];
			if(check(go,n) && !vis[go.first][go.second])
			{
				board[go.first][go.second] = 'C';
				q.push(go);
				cnt++;
				vis[go.first][go.second] = true;
			}
		}
	}
	cout << max((ll)1,cnt) << endl;
	rep(i,0,n-1)
	{
		rep(j,0,n-1) 	cout << board[i][j];
		cout << endl;
	}
	return  0;
}













//?

