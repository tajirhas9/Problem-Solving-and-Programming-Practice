#include <bits/stdc++.h>
using namespace std;
unsigned long long int gcd(unsigned long long int a,unsigned long long int b);
unsigned long long int fact(unsigned long long int a);
unsigned long long int a,b;
unsigned long long int g,temp;
int main()
{
    cin >> a >> b;
    cout << gcd(fact(a),fact(b));
    return 0;
}
unsigned long long int fact(unsigned long long int x)
{
    if(x==0)
        return 1;
    return x*fact(x-1);
}
unsigned long long int gcd(unsigned long long int x,unsigned long long int y)
{
    if(y>x)
        swap(y,x);
    if(x==0) g = y;
    else if(y==0) g = x;
    else
    {
        g = gcd(y,x%y);
    }
    return g;
}
