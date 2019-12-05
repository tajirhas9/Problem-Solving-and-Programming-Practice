#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n,i;
	string s,p;
	for( i = 1; i<= 1000; ++i) {
		p = to_string(i);
		s += p;
	}
	cin >> n;
	cout << s[n-1] << endl;
	return 0;
}