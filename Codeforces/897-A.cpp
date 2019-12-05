#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	string s;
	char x,y;
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin >> l >> r >> x >> y;
		l--;
		r--;
		for(int i=l;i<=r;i++)
		{
			if(s[i]==x)	s[i] = y;
		}
	}
	cout << s;
	return 0;
}
