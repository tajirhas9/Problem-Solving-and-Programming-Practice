#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define MOD 1000000007
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		emplace_back(x)
//#define pb(x)		push_back(x)
#define all(c)		c.begin(),c.end()
#define F 			first
#define S 			second
#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b)	__gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))
typedef int ll;
typedef string string;
typedef pair<int,int> pii;
typedef vector<int> vl;
typedef vector<string> vs;
typedef set<ll> setl;
typedef set<string> sets;
typedef set<ll>::iterator setl_it;
typedef set<string>::iterator sets_it;
typedef vector<ll>::iterator vl_it;
typedef vector<string>::iterator vs_it;
inline bool isLeapYear(ll y) 			{ return ((y%400==0) || (y%4==0 && y%100!=0)); }
inline void optimize(void) 				{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
inline bool isInside(pii p,ll n,ll m)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); };
inline bool isInside(pii p,ll n)		{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); };
inline bool isSquare(ll x) 				{ ll s = sqrt(x);	return (s*s==x); };
inline bool isFib(ll x) 				{ return isSquare(5*x*x+4)|| isSquare(5*x*x-4); };
inline bool isPowerOfTwo(ll x)			{ return ((1LL<<(ll)log2(x))==x); };
ll primeMarked[MAX/64 + 2];
inline bool on(ll x) 					{ return (primeMarked[x/64] & (1<<((x%64)/2))); };
inline void mark(ll x)					{ primeMarked[x/64] |= (1<<((x%64)/2)); };
inline ll bitOn(ll x,ll k)				{	return x |= 1<<k;	}
inline ll bitOff(ll x,ll k)				{	return x ^= 1<<k;	}
inline bool checkBit(ll x,ll k)			{	return x &= 1<<k;	}
//debug
//#ifdef tajir
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () {
            cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}
//#else
//#define dbg(args...)
//#endif // tajir
const ll mod = 1e9+7;
const double pi = acos(-1.0);
struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pii const &a, pii const &b)	
	{
		if(a.F==b.F)
			return (a.S<b.S);
		return (a.F<b.F);
	}
};/*
void sieve(ll n) {
    for (ll i=3; i*i<n; i+=2) {
        if (!on(i)) {
            for (ll j=i*i; j<=n; j+=i+i) {
                mark(j);
            }
        }
    }
}
inline bool isPrime(int num) { return num > 1 && (num == 2 || ((num & 1) && !on(num))); }*/
//ll fx[] = {1,1,-1,-1};
//ll fy[] = {1,-1,1,-1};
stack<pii> s;
queue<pii> q,q1;
vector<pii> v1;
vl v2;
int main()
{
	optimize();
	ll i,prev,len=0;
	bool ff;
	string s;
	cin >> s;
	rep(i,0,s.size()-1)
		q.push(mp((s[i]-'0'),i+1));
	(q.front().F)	? ff = true : ff = false;
	if(ff)
	{
		cout << -1 << endl;
		return 0;
	}
	pii top = q.front();
	q.pop();
	v1.pb(top);
	prev = top.S;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		if(top.S<=prev)
		{
			(top.F)	? ff = true : ff = false;
			if(!ff)
				v1.pb(top);
			else
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else
		{
			if(ff && top.F)
				q.push(top);
			else if(!ff && !top.F)
				q.push(top);
			else if(ff && !top.F)
				v1.pb(top) , ff = false;
			else if(!ff && top.F)
				v1.pb(top) , ff = true;
		}
		prev = top.S;
		//cout << top.F << " " << q.size() << " " << q1.size() << endl;
	}
	dbg(v1);
	len=0;
	rep(i,0,v1.size()-1)
	{
		//cout << v1[i].F << " " << v1[i].S << endl;
		if((((v1[i].F==0 && v1[i+1].F==0) || (v1[i].S>=v1[i+1].S)) && ((i+1)<s.size())) || (v1[i].F==0 && i==(s.size()-1)))
		{
			len++;
			v2.pb(len);
			len=0;
			continue;
		}
		len++;
		//cout << len << endl;
	}
	//cout << endl;
	int j=0,k;
	if(v2.size()==0)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << v2.size() << endl;
	rep(i,0,v2.size()-1)
	{
		cout << v2[i] << " ";
		rep(k,0,v2[i]-1)
			cout << v1[j++].S << " ";
		cout << endl;
	}
	return 0;
}













//?


