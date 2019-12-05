#include <bits/stdc++.h>
using namespace std;
double const eps = 1e-5;
double const pi = acos(-1.0);
int main()
{
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase)
    {
        double m,d;

        cin >> m >> d;
        double volume = m / d;

        double lo = 0.000001, hi = 100005;

        double area = 3*m;
        area /= (4*pi*d);

        area = pow(area, (2/3.0));
        area *= (4*pi);
        cout << "Case "<< kase << ": ";
        cout << fixed << setprecision(4) << area << endl;
    }
    return 0;
}
