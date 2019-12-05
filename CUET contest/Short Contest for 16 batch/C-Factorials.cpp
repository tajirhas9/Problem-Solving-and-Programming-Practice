#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int n,k,sum;
	char s[30];
	cin >> n;
	getchar();
	gets(s);
	sum = n;
	k = strlen(s);
	while(n > k)
	{
		sum *= n-k;
		n -= k;
	}
	cout << sum << endl;
	return 0;
}
