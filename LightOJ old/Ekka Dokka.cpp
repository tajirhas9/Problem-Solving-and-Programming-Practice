#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;



//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

ll w;

int main()
{
	
	ll n,m,T;

	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		cin >> w;

		cout << "Case " << kase << ": ";

		if(w & 1 ) {
			cout << "Impossible" << endl;
			continue;
		}

		ll i = 2;

		while( 1 ) {
			if(w % i == 0 && ( w / i ) & 1 ) {
				cout << w / i << " " << i << endl;
				break;
			}
			i += 2;
		}
	}
	
	return 0;
}






//?
