#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1,10);
    cout << T << endl; /* Random number in the range [1,10]. */
    while(T--) {
    	int n,m;
    	n = rnd.next(1,40000);
    	m = rnd.next(1,min(15000,(n*(n-1) )));
    	cout << n << " " << m << endl;
    	for(int i = 0; i < m; ++i) {

	 		int u,v,w;
	 		u = rnd.next(1,n);
	 		v = rnd.next(1,n);
	 		w = rnd.next(1,1000000000);
	 		cout << u << " " << v << " " << w << endl;
 		}
 		int q = rnd.next(1,100000);
 		cout << q << endl;
 		while(q--)
 			cout << rnd.next(1,1000000000) << endl;
 	}
}