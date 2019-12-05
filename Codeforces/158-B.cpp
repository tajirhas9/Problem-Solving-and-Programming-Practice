#include <bits/stdc++.h>
using namespace std;
int main() {
	int n , a[100005];
	cin  >> n;
	for(int i = 0; i < n; ++i)	cin >> a[i];
	sort(a , a+n);
	reverse(a , a+n);
	
	deque < int > q;
	for(int i = 0; i < n; ++i)
		q.push_back(a[i]);
	int car = 0;
	while(!q.empty()) {
		int in_queue = q.front();
		q.pop_front();
	//	cout << a[f++] << " ";
		while( in_queue + q.back() <= 4 && !q.empty() ) {
			in_queue += q.back();
			q.pop_back();
	//		cout << a[r--] << " ";
		}
		car++;
	//	cout << endl;
	}
	
	cout << car << endl;

	return 0;
}