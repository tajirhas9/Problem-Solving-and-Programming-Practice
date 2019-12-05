#include <bits/stdc++.h>

#define  pi       acos(-1)

using namespace std;

int main()
{
    double h;

    cin >> h;

    printf("%f\n", (h*h)-(pi*(h/2.0)*(h/2.0)));

    cout << ((h*2*h)-2*(pi*(h/2.0)*(h/2.0)))/2;

    return 0;
}
