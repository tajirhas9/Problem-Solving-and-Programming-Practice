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
int main()
{
	optimize();
	ll i,j,k=0,x,cnt=0;
	string s1,s2;
	cin >> x;
	cin >> s1 >> s2;
	if(s2.find("7") != std::string::npos || s1.find("7") != std::string::npos)	{ cout << 0 << endl; return 0; }
	while(1)
	{
		if(s2=="00")
		{
			int x1,y1;
			x1 = s1[0]-'0'; y1 = s1[1]-'0';
			y1 = y1 + x1*10;
			//cout << y1 << endl;
			y1--;
			//cout << y1 << endl;
			if(s1=="00")
			{
				s1 = "23";
			}
			else
			{
				s1[1] = (y1%10) + '0';
				s1[0] = ((y1/10)%10)+'0';
			}
			s2 = "59";
		}
		else
		{
			int x1,y1;
			x1 = s2[0]-'0'; y1 = s2[1]-'0';
			y1 = y1 + x1*10;
			//cout << y1 << endl;
			y1--;
			s2[1] = (y1%10) + '0';
			s2[0] = ((y1/10)%10)+'0';
			//cout << s2 << endl;
		}
		//cout << s1 << " " << s2 << endl;;
		k++;
		if(k==x)
		{
			if(s2.find("7") != std::string::npos || s1.find("7") != std::string::npos)
			{
				cnt++; break;
			}
			cnt++;
			k=0;
		}
		//cout << k << endl;
	}
	cout << cnt << endl;
	return  0;
}













//?

