#include <bits/stdc++.h>
using namespace std;
map<string,int> user;
int main()
{
	int i,n;
	string s;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> s;
		user[s]++;
		if(user[s] > 1)		cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
