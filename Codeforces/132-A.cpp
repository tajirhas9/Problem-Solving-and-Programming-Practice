#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int a[1000],x=255,y,b[1000];
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		x = s[i];
		for(int j=0;j<8;j++)
		{
			int z;
			z = x&(1<<j);
			if(z)
				y |= 1<<(7-j);
		}
		a[i] = y;
		y=0;
	}
	b[0] = ((0-a[0])%256+256)%256;
	for(int i=1;i<s.size();i++)
	{
		b[i] = ((a[i-1]-a[i])%256+256)%256;
	}
	for(int i=0;i<s.size();i++)	cout << b[i] << endl;
	return 0;
}
