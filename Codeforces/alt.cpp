#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX 400005
#define PI 2*acos(0.0)
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define pf(a) printf("%d\n", a)
#define pfl(a) printf("%lld\n", a)
#define Case(t) printf("Case %d: ", t)
#define pii pair<int, int>
#define MOD 1000000007
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
clock_t t_Start;
void Start()
{
    t_Start = clock();
}
void End()
{
    double Time = (double)(clock()-t_Start)/CLOCKS_PER_SEC;
    error(Time);
}
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;
 
int n, k;
int cnt[8005];
 
ll check(ll x)
{
    map<ll,ll>mp;
    int j = k;
    ll p = 0;
    for(int i = 1; i <= k; i++)
    {
        if(mp[i]==0)
        {
            mp[i] = 1;
            if(i == j) {
            	if(cnt[i] <= x) {
            		p++;
            	}
            }
            else {
	            if(cnt[i]+cnt[j]<=x)
	            {
	                mp[j] = 1;
	                j--;
	                p++;
	            }
	            else if(cnt[i]<=x)
	            {
	                p++;
	            }
	            else
	            {
	                return 0;
	            }
	        }
        }
    }
    return (x*p);
}
 
ll BS()
{
    ll ans = infLL;
    ll lo = 1;
    ll hi = 4000000009;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        ll ret = check(mid);
        if(ans > ret && ret!=0)
        {
            ans = ret;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //Start();
 
    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }
    sort(cnt+1,cnt+1+k, greater<int>());
    ll ans = BS();
    cout<<ans<<endl;
 
    //End();
    return 0;
}