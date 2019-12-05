#include <bits/stdc++.h>
using namespace std;
set<char> s;
int main()
{
	char a[10000],b[10000],c[10000];
	while((scanf("%s %s",a,b)))
	{
		int l1,l2,k=0,m,n;
		l1 = strlen(a);
		l2 = strlen(b);
		m = min(l1,l2);
		n = max(l1,l2);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;i++)
			{
				if(a[i]==b[j])	s.insert(a[i]);
			}
		}
		set<char>::iterator it;
		for(it = s.end(); it != s.begin();it--)
		{
			cout << *it;
		}
	}
	return 0;
}
