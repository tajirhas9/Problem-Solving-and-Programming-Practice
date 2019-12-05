#include <bits/stdc++.h>
using namespace std;

//typedefs

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

//#Defines

//#define pb push_back
#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define endl '\n'
#define pf printf
#define sf scanf
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const double PI = acos(-1);
const double EPS = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

int main() {
	
	optimize();

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif

	int T;

	cin >> T;

	while(T--) {
		int a;
		cin >> a;

		int b = gcd(a,180);

		if(b == 1)
			cout << -1 << endl;
		else {
			int n = 180/b;
			double arg = (n-2)*180*1.0;
			arg /= (n*1.0);
			if((arg - a) >= EPS)
				cout << n << endl;
			else {
				int divider = (int)(ceil((a*1.0) / arg));
				cout << n*divider << endl;
			}
		}
	}

	return 0;
}