#include <bits/stdc++.h>
using namespace std;
int main() {
	long long a,b;
	cin >> a >> b;
	cout << (( (a/b) & 1 ) ? "YES" : "NO" ) << endl;
	return 0;
}