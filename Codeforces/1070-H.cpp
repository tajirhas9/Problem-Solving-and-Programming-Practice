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
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;



int main() {
	
	optimize();

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif

	map < string , pair < int , string > > M;
	map < string , bool > vis;
	string a[112345];
	int n;

	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		for(int j = 0; j < a[i].size(); ++j) {
			for(int k = 1; k < a[i].size() - j+1; ++k) {
				string p;
				p = a[i].substr(j,k);
				if(!vis[p]) {
					M[p].F++;
					M[p].S = a[i];
					vis[p] = true;
				}
			}
		}
		vis.clear();
	}

	int q;

	cin >> q;

	while(q--) {
		string p;
		cin >> p;

		if(M.find(p) != M.end()) 
			cout << M[p].F << " " << M[p].S << endl;
		else
			cout << 0 << " -" << endl;
	}

	return 0;
}