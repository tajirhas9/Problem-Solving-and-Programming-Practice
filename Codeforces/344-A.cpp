#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    int n,c=1;
    cin >> n;
    while(1)
    {
        if(n==0)
            break;
        cin >> a;
        n--;
input :
        if(n==0)
            break;
        cin >> b;
        n--;
        if(a != b)
        {
            a = b;
            c++;
            goto input;
        }
        else
        {
            goto input;
        }
    }
    cout << c;
    return 0;
}
