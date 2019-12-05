#include <bits/stdc++.h>
#include <set>
using namespace std;
#define ll long long
multiset<int> s1,s2,s3;
int main()
{
	ll i,n,x;
	bool first,sec;
	first = sec = false;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x;
		s1.insert(x);
	}
	for(i=1;i<=(n-1);i++)
	{
		cin >> x;
		s2.insert(x);
	}
	for(i=1;i<=(n-2);i++)
	{
		cin >> x;
		s3.insert(x);
	}
	multiset<int>::iterator it = s1.begin();
	multiset<int>::iterator it1 = s2.begin();
	while(it1 != s2.end())
	{
		if(*it1==*it)
		{
			it++;
			it1++;
		}
		else
		{
			cout << *it << endl;
			first = true;
			break;
		}
	}
	if(!first)	cout << *it << endl;
	it = s2.begin();
	it1 = s3.begin();
	while(it1 != s3.end())
	{
		if(*it1==*it)
		{
			it++;
			it1++;
		}
		else
		{
			cout << *it << endl;
			sec = true;
			break;
		}
	}
	if(!sec)	cout << *it << endl;
	return 0;
}
