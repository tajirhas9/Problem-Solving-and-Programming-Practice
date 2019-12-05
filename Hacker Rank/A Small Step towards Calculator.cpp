#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	char s[3];
	cin >> s;
	if(s[1] == '+')
		cout << (s[0]-'0')+(s[2]-'0') << endl;
	else
		cout << (s[0]-'0')-(s[2]-'0') << endl;
	return 0;
}
