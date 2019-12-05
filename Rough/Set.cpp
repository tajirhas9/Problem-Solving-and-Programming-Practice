#include <bits/stdc++.h>
#include <list>
using namespace std;
pair<string,list<int>> pii;
list<string> s[1000];
int main()
{
	int i,n;
	string str;
	cin >> str;
	for(i=0;i<4;i++)
	{
		cin >> n;
		s[str].insert(n);
		set<string> :: iterator p;
		cout << s[str][i] << endl;
	}
	
}
