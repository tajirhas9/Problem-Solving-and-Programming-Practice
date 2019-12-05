
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

  ll Divisors(ll n)
{
    ll cnt = 0;
    ll sqrtn = sqrt(n);
    for (ll i=1; i<=sqrtn; i++)
    {
        if (n%i==0)
        {
            if (n/i == i)
            {
               if(__builtin_parityll(i))
                    cnt++;
            }
            else
            {
                if(__builtin_parityll(i))
                    cnt++;
                if(__builtin_parityll(n/i))        
                    cnt++;
            }
        }
    }
    return cnt;
}

int  main()
{
    ll n;
    scanf("%lld", &n);
    printf("%I64d\n", Divisors(n));
    return 0;
}
