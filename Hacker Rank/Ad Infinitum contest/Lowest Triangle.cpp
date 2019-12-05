#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
    long long int a,b,h=1;
    cin >> b >> a;
    while((.5*b*h) < a)
        h++;
    cout << h << endl;
    return 0;
}
