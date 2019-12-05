#include <bits/stdc++.h>
using namespace std;
int main() {
	string a,b;
	vector <long long> v;
	cin >> a >> b;
	if(a.length() != b.length()) {
		cout << "NO" << endl;
		return 0;
	}
	for(long long i = 0; i < a.size(); ++i) {
		if(a[i] != b[i])	v.push_back(i);
	}
	if(v.size() > 2) {
		cout << "NO" << endl;
		return 0;
	}
	if(v.size() != 0)
		swap(a[v[0]], a[v[1]] );
	if(a.compare(b) == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}