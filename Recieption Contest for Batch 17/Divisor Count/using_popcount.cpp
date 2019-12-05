#include<bits/stdc++.h>
using namespace std;
 typedef long long ll;

bool findParity(ll n)
{
    ll cnt = __builtin_popcountll(n);
    if(cnt & 1)return true;
    else return false;
}



  ll Divisors(ll n)
{
    ll cnt = 0;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i)
            {
               // if(__builtin_parity(i))
                    if(findParity(i))
                {
                    cnt++;
                    //printf("%d ", i);
                }
            }
            else
            {
                //if(__builtin_parity(i))
                    if(findParity(i))
                {
                    cnt++;
                    //rintf("%d ", i);
                }
                //if(__builtin_parity(n/i))
                if(findParity(n/i))
                {
                    cnt++;
                    //printf("%d ", n/i);
                }
            }
        }
    }
    return cnt;
}

int  main()
{
   #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", Divisors(n));
    fprintf(stdout,"\nTIME: %.4lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    return 0;
}