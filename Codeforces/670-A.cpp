#include <iostream>
using namespace std;

int main() {
	long n,mi,ma,cycle=0,i,dC,hDm,hDma;
	cin >> n;
	for(i = 1, dC = 1, hDm = 0; i<= n; ++i, ++dC) {
		if( dC > 7 )	dC = 1;
		if(dC > 5)	hDm++;
	}
	for(i = 1, dC = 6, hDma = 0; i <= n; ++i, ++dC) {
		if(dC > 7)	dC = 1;
		if(dC > 5)	hDma++;
	}
	cout << hDm << " " << hDma << endl;
	return 0;
}