#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
	int n;
	cin >> n;
	queue <int > q;

	if( !(n&1) ) {
		cout << -1 << endl;
		return 0;
	}

	for(int i = n-2; i >= 1; i -= 2 )
		q.push(i);
	for(int i = n-1; i >= 0; i -= 2)
		q.push(i);

	vector< int > v;
	for(int i = 0; i < n; ++i)
		cout << i << " ";
	cout << endl;
	int i = 0;
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		cout << top << " ";
		v.pb((top+i)%n );
		i++;
	}
	cout << endl;
	for(int i = 0;i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}