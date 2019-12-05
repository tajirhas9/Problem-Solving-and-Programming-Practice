#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,b,i;
	cin >> n >> a >> b;
	for(i=0;i<=30000000;i++)
	{
		long long nom;
		nom = n-(b*i);
		if(nom<0)	break;
		if((nom%a)==0)
		{
			cout << "YES" << endl;
			cout << nom/a << " " << i << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
