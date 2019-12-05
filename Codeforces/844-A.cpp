#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	char s[2000];
	int k,i,j,l,m=0;
	cin >> s;
	cin >> k;
	l = strlen(s);
	if(k > l)
	{
		cout << "impossible" << endl;
		return 0;
	}
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(s[i] == s[j])	m++;
		}
	}
	if(m==0 && k < l)
	{
		cout << "impossible" << endl;
		return 0;
	}
	cout << k-(l-m) << endl;
	return 0;
}
