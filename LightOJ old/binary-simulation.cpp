#include <bits/stdc++.h> 
using namespace std;
#define MAX 100005
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
typedef long long ll;
typedef string string;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
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
#ifdef tajir
#define dbg(args...) do {cerr << #args << " : "; ff(args); } while(0)
void ff(){
	cerr << endl;
}

template <typename T>
void ff(T a[],int n ) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename T,typename ... hello>
void ff( T arg, const hello &... rest) {
	cerr << arg << ' ';
	ff(rest...);
}
#else
#define dbg(args...)
#endif
//endDebug
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
void build(int node,int left,int right);
void update(int node,int left,int right,int l,int r);
int query(int node,int left,int right,int k);
int tree[4*MAX];

int main()
{
	optimize();
	int i,j,k,n;
	int T,l,r,q;
	char s[112345],c;
	scanf("%d",&T);
	getchar();
	rep(i,1,T) {
		scanf("%s",s);
		//cout << s << endl;
		n = strlen(s);
		//cout << n << endl;
		//dbg(tree);
		build(1,0,n-1);
		//cout << "Build Complete" << endl;
		scanf("%d",&q);
		printf("Case %d:\n",i);
		while(q--)
		{
			getchar();
			scanf("%c",&c);
			//cout << c << endl;
			if(c=='I')
			{
				scanf(" %d %d",&l,&r);
				--l; --r;
				update(1,0,n-1,l,r);
				//cout << "Updated" << endl;
			}	
			else
			{
				scanf(" %d",&k);
				--k;
				int p = query(1,0,n-1,k);
				if(p&1)	(s[k]=='1')	?  printf("0\n") : printf("1\n");
				else 				printf("%d\n",s[k]-'0');
				//cout << "Query Completed" << endl;
			}
		}
	}
	return 0;
}
void build(int node,int left,int right)
{
	//cout << node << " " << left << " " << right << endl;
	if(left==right)
	{
		tree[node] = 0;
		return;
	}
	int tm;
	tm = (left+right)/2;
	build(2*node,left,tm);
	build(2*node+1,tm+1,right);
	tree[node] = 0;
}
void update(int node,int left,int right,int l,int r)
{
	if(l<=left && r>=right)
	{
		tree[node]++;
		return;
	}
	int tm;
	tm = left+right;
	tm /= 2;
	if(l>tm)	update(2*node+1,tm+1,right,l,r);
	else if(r<=tm)	update(2*node,left,tm,l,r);
	else
	{
		update(2*node,left,tm,l,r);
		update(2*node+1,tm+1,right,l,r);
	}
}
int query(int node,int left,int right,int k)
{
	//cout << node << " " << left << " " << right << endl;
	if(left==right)
			return tree[node];
	int tm;
	tm = left+right;
	tm /= 2;
	if(k>tm)	return (tree[node]+query(2*node+1, tm+1,right,k));
	else if(k<=tm)	return (tree[node]+query(2*node,left,tm,k));
}









//?

