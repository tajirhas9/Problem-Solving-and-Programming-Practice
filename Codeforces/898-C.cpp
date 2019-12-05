#include <bits/stdc++.h>
#include <cstring>
#include <set>
#include <map>
using namespace std;
struct func
{
	bool operator() (const string &s1,const string &s2) const
	{
		if(s1==s2)	return false;
		return s1.length() >= s2.length();
	}
};
map<string,set<string,func> > phone_number;
int main()
{
	long long n,i,c,j;
	string name,number;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> name >> c;
		for(j=1;j<=c;j++)
		{
			cin >> number;
			phone_number[name].insert(number);
		}
	}
	set<string,func>::iterator str1,str2;
	map<string,set<string,func> >::iterator it;
	for(it = phone_number.begin() ; it != phone_number.end(); it++)
	{
		//cout << it->first << endl;
		for(str1 = (it->second).begin() ; str1 != (it->second).end() ; str1++)
		{
			str2 = str1;
			str2++;
			for( ; str2 != (it->second).end() && !((it->second).size()==1); str2++)
			{
				string s1 = (*str1),s2=(*str2);
				//cout << *str1 << " " << *str2 << endl;
				if(((*str1).find(*str2)) == (s1.size()-s2.size()))
				{
					//cout << *str2 << "erased" << endl;
					it->second.erase(str2);
					str2--;
				}
			}
			//cout << endl;
		}
	}
	cout << phone_number.size() << endl;
	for(it = phone_number.begin(); it != phone_number.end(); it++)
	{
		cout << it->first << " ";
		cout << (it->second).size() << " ";
		for(str1 = (it->second).begin(); str1 != (it->second).end(); str1++)
			cout << *str1 << " ";
		cout << endl;
	}
	return 0;
}
