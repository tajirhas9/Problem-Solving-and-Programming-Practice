#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) 	for(int i=0;i<(int)n;i++)
typedef long long ll;
vector<int> a,b,c,given;
int main()
{
	ll n,x,i;
	cin >> n;
	i=0;
	FOR(i,n)
	{
		cin >> x;
		given.push_back(x);
	}
	vector<int>::iterator it;
	for(it = given.begin(); it!=given.end();it++)
	{
		if((*it)==0)
		{
			c.push_back((*it));
		}
		else if((*it)>0)
		{
			a.push_back((*it));
		}
		else
		{
			b.push_back((*it));
		}
	}
	if(a.empty())
	{
		a.push_back(b[0]);
		b.erase(b.begin());
		a.push_back(b[0]);
		b.erase(b.begin());
	}
	if(!(b.size()&1))
	{
		c.push_back(b[0]);
		b.erase(b.begin());
	}
	cout << b.size() << " ";
	for(it = b.begin();it != b.end();it++)	cout << *it << " ";
	cout << endl;
	cout << a.size() << " ";
	for(it = a.begin();it != a.end();it++)	cout << *it << " ";
	cout << endl;
	cout << c.size() << " ";
	for(it = c.begin();it != c.end();it++)	cout << *it << " ";
	cout << endl;
	return  0;
}













//?
