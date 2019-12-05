#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define PI 3.1416
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
bool b[11234567];
ll binary[11234567];
ll sq[11234567];
priority_queue<ll> q;
int main()
{
	optimize();
	ll i,j,k,n,t,indx=0,cnt=0;
	rep(i,0,100)
	{
		binary[i] = pow(2,indx);
		sq[i] = indx++;
	}
	indx=0;
	cin >> n >> k;
	t = n;
	i=0;
	while(t)
	{
		if((t&1))
		{
			b[i] = true;	
			cnt++;
		}
		t >>=1; i++;
		indx++;
	}
	if(k<cnt) { cout << "No" << endl; return 0; }
	rep(i,0,indx)
	{
		if(b[i])
			q.push(sq[i]);
	}
	cout << "Yes" << endl;
	if(q.size()==k)
	{
		while(!q.empty())
		{
			cout << q.top() << " ";
			q.pop();
		}
	}
	else
	{
		ll p = k-q.size();
		rep(i,1,p)
		{
			ll top,t1;
			top = q.top();
			q.pop();
			t1 = --top;
			q.push(top);
			q.push(t1);
		}
		while(!q.empty())
		{
			cout << q.top() << " ";
			q.pop();
		}
	}
	
	return  0;
}













//?

