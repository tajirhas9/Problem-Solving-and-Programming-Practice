#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
map<string,pii>devices;
map<string,int> chosen;
struct ans
{
	string name;
	ll id,price;
};
ans a;
int main()
{
	for(int i=1;i<=6;i++)
	{
		string x,y,mName[10];
		long long z;
		cin >> x >> y  >> z;
		devices[y].first++;
		if(devices[y].first==1)	devices[y].second = z;
		else	devices[y].second = min(devices[y].second,z);
	}
	a.id=0;
	a.price=0;
	a.name="";
	map<string,pii>::iterator it;
	for(it=devices.begin();it != devices.end();it++)
	{
		if(it->second.first>a.id)
		{
			a.name = it->first;
			a.id = it->second.first;
			a.price = it->second.second;
		}
		else if(it->second.first==a.id && it->second.second < a.price)
		{
			a.name = it->first;
			a.id = it->second.first;
			a.price = it->second.second;
		}
	}
	cout << a.name << endl;
	return 0;
}
