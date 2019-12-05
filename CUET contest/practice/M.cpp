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

int n,m; // n = string size , m = pattern size
int pi[1000000]; //size = string length
string s,p;

void prefixFunction() {
	int j = 0 , i = 1;
	while(i < m) {						
		if(p[i] == p[j]) {
			pi[i] = ++j;
			++i;
		}
		else {
			if(j == 0) {
				pi[i] = 0;
				++i;
			}
			else
				j = pi[j-1];
		}
	}
}

int kmp() {	//bool for checking if a substring exists or not, if number of subtring is asked,then return type will be ll
	
	prefixFunction();
	
	int i = 0 , j = 0;
	int cnt = 0;
	while(i < n) {
		if(s[i] == p[j]) {
			++i;
			++j;
		}
		if(j == m) {		// m = pattern size
			
			cnt++;
			j = pi[j-1];		//for counting number of appearence of substring p in s;

	//		return 1;		//for checking if a substring exists or not;comment this line for counting number of appearences.
		}
		if(s[i] != p[j]) {
			if(j == 0)
				++i;
			else
				j = pi[j-1];
		}
	}
//	return false;
	return cnt;		//for counting number of appearence of substring p in s;
}


int main() {
	
	optimize();

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> s >> p;

		n = s.size() , m = p.size();

		cout << "Case " << kase << ": " << kmp() << endl;
	}

	return 0;
}