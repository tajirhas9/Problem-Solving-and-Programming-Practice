#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,vector<string>> p;
int main()
{
	long long n;
	cin >> n;
	for(ll i=0;i<n;i++)
	{
		ll c;
		string name;
		cin >> name >> c;
		for(ll j=0;j<c;j++)
		{
			string num;
			cin >> num;
			p[name].push_back(num);
		}
	}
	map<string,vector<string>>::iterator it;
	for(it = p.begin(); it != p.end(); it++)
	{
		for(ll i=0; i<(it->second).size();i++)
		{
			for(ll j=i+1;j<(it->second).size();j++)
			{
				if((it->second)[i].length()>(it->second)[j].length())
				{
					if((it->second)[i].find((it->second)[j]))
						(it->second).erase((it->second).begin()+j);
				}
				else
				{
					if((it->second)[j].find((it->second)[i]))
						(it->second).erase((it->second).begin()+i);
				}
			}
		}
	}
	cout << p.size() << endl;
	for(it = p.begin(); it != p.end(); it++)
	{
		cout << it->first << " ";
		cout << (it->second).size() << " ";
		for(ll i=0;i<(it->second).size(); i++)
			cout << (it->second)[i] << " ";
		cout << endl;
	}
	return 0;
}
