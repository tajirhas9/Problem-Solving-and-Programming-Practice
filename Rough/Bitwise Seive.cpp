#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin >> x;
	cout << (x%64)/2 << endl;
	printf("%d\n",(1<<((x%64)/2)));
	return 0;
}
