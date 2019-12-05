#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		if(i&1)		cout << "I hate that ";
		else 		cout << "I love that ";
	}
	(n&1)? cout << "I hate it" << endl: cout << "I love it" << endl;
	return  0;
}

