#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a[5];
    int i,c=4,j;

    for(i=0;i<4;i++)
    {
        cin >> a[i];
        for(j=0;j<i && j >=0;j++)
        {
            if(a[j] == a[i])
            {
                c--;
                break;
            }
        }
    }
    cout << 4-c;
    return 0;
}
