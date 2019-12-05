#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i,n)	for(i=0;i<n;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x);
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
int main()
{
	ll n,col=1;
	string s1,s2;
	s2 = "A";
	cin >> n;
	while(n--)
	{
		cin >> s1;
		while(s2 != s1)
		{
			col++;
			s2[s2.length()-1]++;
			if(s2[s2.length()-1]>'Z')
			{
				s2[s2.length()] = 'A';
			}
		}
	}
	return  0;
}













//?

