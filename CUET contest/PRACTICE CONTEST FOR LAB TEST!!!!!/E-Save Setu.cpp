#include <iostream>
using namespace std;
int main()
{
    unsigned long long int n,t,total=0,i;
    string s;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> s;
        if(s== "donate")
        {
            cin >> t;
            total += t;
        }
        else if(s == "report")
            cout << total << "\n";
    }
    return 0;
}
