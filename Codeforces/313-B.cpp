#include <bits/stdc++.h>
using namespace std;
int length[100005];
int main()
{
	string s;
	char pre;
	int q,l,r,i,len,ans=0;
	cin >> s;
	len =s.length();
	length[0] = 0;
	pre = s[0];
	for(i=1;i<len;i++)
	{
		if(s[i]==pre)
		{
			length[i] = length[i-1]+1;
		}
		else
		{
			pre = s[i];
			length[i] = length[i-1];
		}
	}
	cin >> q;
	for(i=1;i<=q;i++)
	{
		cin >> l >> r;
		--l;
		--r;
		cout << length[r]-length[l] << endl;
		ans=0;
	}
	return 0;
}
