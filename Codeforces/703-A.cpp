#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,mishka=0,chris=0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		if(a>b)	mishka++;
		else if(a<b)	chris++;
	}
	if(mishka>chris)	cout << "Mishka" << endl;
	else if(chris>mishka)	cout << "Chris" << endl;
	else 	cout << "Friendship is magic!^^" << endl;
	return 0;
}
