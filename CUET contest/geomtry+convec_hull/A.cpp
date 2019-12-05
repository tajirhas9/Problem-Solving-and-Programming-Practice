#include <bits/stdc++.h>
using namespace std;

class Vector {

public:
	int x,y;

	Vector() {
		x = 0 , y = 0;
	}

	Vector(int x,int y) : x(x) , y(y) {}

	bool operator <=(const Vector &b) {
		return (x <= b.x && y <= b.y);
	}

	bool operator >=(const Vector &b) {
		return (x >= b.x && y >= b.y);
	}

};

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	

	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		Vector lo,hi;

		cin >> lo.x >> lo.y >> hi.x >> hi.y;

		Vector point;

		int m;

		cin >> m;


		cout << "Case " << kase << ":\n";

		while(m--) {
			cin >> point.x >> point.y;

			if(point >= lo && point <= hi)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}	
	}
	

	return 0;
}