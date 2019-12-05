#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l,i,c[110];
    string a,b;
    cin >> a >> b;
    l = a.length();
    for(i=0;i<l;i++)
    {
        c[i] = ((a[i]-'0')^(b[i]-'0'));
    }
    for(i=0;i<l;i++)
        cout << c[i];
    return 0;
}
