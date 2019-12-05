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

vector < double > d[100005];

double dp[100005];
int main() {
	
	d[1].pb(1);

	for(int i = 2; i <= 100000; ++i) {
		for(int j = 1; j * j <= i; ++j) {
			if(i % j == 0) {
				d[i].pb(j);
				if(i/j != j)
					d[i].pb(i/j);
			}
		}
//		dbg(i,d[i]);
	}

	dp[1] = 0;

	for(int i = 2; i <= 100000; ++i) {
		int m = d[i].size();
		for(auto x : d[i]) {
			if(x == 1)
				dp[i] += ((double)1/(double)m);
			else 
				dp[i] += ((1+dp[(int)(i/x)]) / m);
		}
		dp[i] *= m;
		dp[i] /= (m-1);
	}

	int T;
	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n;
		cin >> n;
		cout << fixed << setprecision(10) << "Case " << kase << ": " << dp[n] << endl;
	}

	return 0;
}