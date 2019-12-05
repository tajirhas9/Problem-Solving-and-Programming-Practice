#include <bits/stdc++.h>
using namespace std;
struct pii
{
	string name;
	int id;
};
map<string,int> team;
vector<string> list1;
int main()
{
	string s;
	int y,n,q;
	cin >> y >> n >> q;
	getchar();
	for(int i=1;i<=n;i++)
	{
		string x;
		getline(cin,s);
		if(s[s.size()-2]=='#')
		{ 
			x = s; 
			x.erase(x.end()-3,x.end());
		}
		else
		{
			x=s;
		}
		team[x]++;
		if(team[x]<2)	list1.push_back(s);
	}
	cout << list1[q] << endl;
	return 0;
}
