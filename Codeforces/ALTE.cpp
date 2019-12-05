#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	int x,y;
	x = y = 0;
	scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase) {
		char c;
		int l,r;
		getchar();
		scanf("%c %d %d",&c,&l,&r);

		if(l > r)	swap(l,r);
//		cout << c << " " << l << r << endl;
		if(c == '+') {
			x = max(x , l);
			y = max(y , r);
		}
		else {
//			cout << x << "," << y << endl;
//			cout << l << "," << r << endl << endl;
			if((x <= l && y <= r) || (x <= r && y <= l))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}