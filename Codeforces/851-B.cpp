#include <bits/stdc++.h>
using namespace std;
int main()
{
    double ax,ay,bx,by,cx,cy,m1,m2,ab,bc;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ab = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    bc = sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy));
    m1 = (ax-bx)/(ay-by);
    m2 = (bx-cx)/(by-cy);
    (m1 == m2 || ab != bc)? cout << "No" << endl : cout << "Yes" << endl;
    return 0;
}
