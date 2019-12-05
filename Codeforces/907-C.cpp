#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
int main()
{
	ios_base::sync_with_stdio(0);
	int a[30];
	string s1,s;
	ll n,cnt=0,shock=0,lock=0;
	memset(a,0,sizeof(a));
	cin >> n;
	while(n--)
	{
		cin >> s1 >> s;
		ll i,l;
		l = s.length(); l--;
		if(s1=="!")
		{
			if(cnt==1)
			{
				shock++;
			}
			else
			{
				if(l<cnt)
				{
					FOR(i,0,l)
					{
						int c;
						c = s[i]-'a';
						if(a[c]==0)
						{
							a[c] = 1;
							cout << s[i] << " ";
							cnt++;
						}
					}
				}
				else
				{
					
				}
			}
		}
		else if(s1==".")
		{
			FOR(i,0,l)
			{
				int c;
				c = s[i]-'a';
				if(a[c]==1)
					cnt--;
				a[c] = 2;
			}
		}
		else if(s1=="?")
		{
			if(cnt==1)
			{
				cout << "y" << endl;
				if(l==0)
				{
					cout << "z" << endl;
					char it;
					FOR(i,0,25)
					{
						if(a[i]==1)	it = a[i]+'a'+1;
					}
					cout << it << endl;
					if(it==s[0])	lock = shock;
					else
						shock++;
				}
				else
					shock++;
			}
		}
		cout << cnt << endl;
	}
	cout << lock;
	return  0;
}













//?

