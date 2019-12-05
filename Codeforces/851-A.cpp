#include <bits/stdc++.h>
using namespace std;
long long int n,k,t;
int main()
{
    cin >> n >> k >> t;
    if(t>=0 && t <= k)  cout << t << endl;
    else if(t > k && t <= n)    cout << k << endl;
    else    cout << (n+k)-t << endl;
    return 0;
}
