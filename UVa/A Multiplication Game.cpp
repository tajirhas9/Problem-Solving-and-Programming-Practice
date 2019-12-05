#include <bits/stdc++.h>
using namespace std;
int main() {
	long long x;
	bool player1;
	while((cin>>x) ) {
		long long p = 1;
		player1 = true;
		while(p < x) {
			if(player1)
				p *= 9;
			else
				p *= 2;
			player1 = !player1;
		}
		cout << ((!player1) ? "Stan " : "Ollie ") << "wins." << endl;
	}
}