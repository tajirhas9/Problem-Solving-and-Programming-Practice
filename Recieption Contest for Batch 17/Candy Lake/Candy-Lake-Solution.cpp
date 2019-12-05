#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll n,s,sum,f,ans;
bool func(ll x)
{
    vector <ll> v;
    for(ll i=1;i<=n;i++)
    {
        v.push_back(a[i]+x*i);
    }
    sort(v.begin(),v.end());
  //  cout << "x = " << x << endl;

    sum = 0;
 /*   for(int i=0;i<n;i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;
*/
    for(ll i=1;i<=x;i++)
    {
        sum = sum+v[i-1];
    }
  //  cout<< endl;
    v.clear();
    if(sum<=s)
    {
        ans = x;
        f = sum;
        return 1;
    }
    else
    {
        return 0;
    }
}




int main()
{

    scanf(" %I64d",&n);

    for(ll i=1;i<=n;i++)
    {
        scanf(" %I64d",&a[i]);
    }
    scanf(" %I64d",&s);
    ll lo = 0,hi=n;
    ll mid;
    while(lo<=hi)
    {
        mid = lo+(hi-lo)/2;
        bool e;
        e = func(mid);
        if(e==0)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    printf("%I64d %I64d\n",ans,f);
    return 0;
}

