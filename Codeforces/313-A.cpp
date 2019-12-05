#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,temp,first,second;
	cin >> x;
	first = x/10;
	temp = x;
	second = temp/100;
	second *=10;
	temp %= 10;
	second += temp;
	cout << max(x,max(first,second)) << endl;
	return 0;
}
