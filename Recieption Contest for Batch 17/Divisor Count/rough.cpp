#include <bits/stdc++.h> /*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;
//using namespace __gnu_pbds;

//typedefs

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;

/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
*/

//#Defines
#define rep(i,a,b)  for(i=a;i<=b;i++)
#define repR(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
// #define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)      c.begin(),c.end()
#define endl '\n'
#define pf printf
#define sf scanf
//#define left __left
//#define right __right
//#define tree __tree
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define RESET(a,b)  memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const LL infLL = 9000000000000000000;


//Bit Operations
inline bool checkBit(LL n, int i) { return n&(1LL<<i); }
inline LL setBit(LL n, int i) { return n|(1LL<<i);; }
inline LL resetBit(LL n, int i) { return n&(~(1LL<<i)); }

int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


//Inline functions

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(LL year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(LL &a) { a %= MOD; (a < 0) && (a += MOD); }
inline LL modMul(LL a, LL b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline LL modAdd(LL a, LL b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline LL modSub(LL a, LL b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline LL modPow(LL b, LL p) { LL r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline LL modInverse(LL a) { return modPow(a, MOD-2); }
inline LL modDiv(LL a, LL b) { return modMul(a, modInverse(b)); }
inline bool isInside(PII p,LL n,LL m)   { return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); }
inline bool isInside(PII p,LL n)        { return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); }
inline bool isSquare(LL x)              { LL s = sqrt(x);   return (s*s==x); }
inline bool isFib(LL x)                 { return isSquare(5*x*x+4)|| isSquare(5*x*x-4); }
inline bool isPowerOfTwo(LL x)          { return ((1LL<<(LL)log2(x))==x); }

//Prime Number Generator
/*
#define mx = 1000006;
bitset <mx> mark;
vector <int> primes;

void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}
*/
int main() {
    optimize();
    string s;
    int n; cin >> n;
    cin >> s;
    map <char, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }

    LL ans = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        LL x = it -> second;
        ans += ((x * (x + 1)) / 2);
    }

    if (ans & 1) cout << "Not Shera" << endl;
    else cout << "Shera" << endl;
}