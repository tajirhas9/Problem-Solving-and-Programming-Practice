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
inline bool isInside(pii p,ll n,ll m)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); };
inline bool isInside(pii p,ll n)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); };
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
string solve(string s,ll indx);
int main()
{
	optimize();
	ll i,j,k,r,g,b,y;
	string s,s1;
	cin >> s;
	i=0;
	r = g = b= y = 0;
	s1 = solve(s,0);
	//cout <<"s1 " << s1 << endl;
	rep(i,0,s.length()-1)
	{
		if(s[i] == '!')
		{
			switch(s1[i])
			{
				case 'R' :
					r++;
					break;
				case 'G' :
					g++;
					break;
				case 'B' :
					b++;
					break;
				case 'Y' :
					y++;
					break;
			}
		}
	}
	cout << r << " " << b << " " << y << " " << g << endl;
	return  0;
}
string solve(string s,ll indx)
{
	string sR,sB,sG,sY;
	// what if s[indx] = '!' & s[indx+i] = '!'?
	if((s[indx] == s[indx+1] || s[indx] == s[indx+2] || s[indx] == s[indx+3]) && s[indx] != '!')	return "false";
	if((s[indx] == s[indx-1] || s[indx] == s[indx-2] || s[indx] == s[indx-3]) && s[indx] != '!')	return "false";
	while(s[indx] != '!' && indx<=s.length())	indx++;
	if(indx>=s.length())	return s;
	s[indx] = 'R';
	sR = solve(s,indx);
	s[indx] = 'G';
	sG = solve(s,indx);
	s[indx] = 'B';
	sB = solve(s,indx);
	s[indx] = 'Y';
	sY = solve(s,indx);
	if(sR.compare("false") != 0)	return sR;
	if(sB.compare("false") != 0)	return sB;
	if(sG.compare("false") != 0)	return sG;
	if(sY.compare("false") != 0)	return sY;
	return "false";
}












//?
