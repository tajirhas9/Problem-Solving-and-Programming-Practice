#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v1,v2,t1,t2,s,i,time1,time2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    time1 = t1+v1*s+t1;
    time2 = t2+v2*s+t2;
    cout << time1 << " " << time2 << endl;
    if(time1 == time2) cout << "Friendship" << endl;
    else if(time1<time2) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
