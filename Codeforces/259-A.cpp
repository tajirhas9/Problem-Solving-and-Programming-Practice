#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n)	for(;i<n;i++)
typedef long long ll;
int main()
{
	string s[10];
	bool w,b,flag;
	w=b=false;
	flag=true;
	for(int i=0;i<8;i++)
	{
		cin >> s[i];
		int j=0;
		w=b=false;
		(s[i][j]=='W') ? w=true : b=true;
		j++;
		if(flag)
		{
			FOR(j,s[i].size())
			{
				if(s[i][j]=='W' && w)	flag=false;
				else if(s[i][j]=='B' && b)	flag=false;
				else if(s[i][j]=='W' && b)
				{
					w=true;
					b=false;
				}
				else
				{
					b=true;
					w=false;
				}
			}
		}
	}
	(flag) ?	cout << "YES" : cout << "NO";
	return  0;
}













//?

