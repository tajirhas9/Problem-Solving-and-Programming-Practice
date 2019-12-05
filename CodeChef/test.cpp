#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,flag = 0;
	while(1)
	{
		cin >> n;
		if(n==42) flag = 1;
		if(flag == 0)
			cout << n << endl;
	}
}
