#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int from = 1 , to = n , cost = 0;
	while(1) {
		if(from == to)	break;
		cost += (from+to)%(n+1);
		swap(from, to);
		if(from > to)	to++;
		else	to--;
	}
	cout << cost << endl;
	return 0;
}