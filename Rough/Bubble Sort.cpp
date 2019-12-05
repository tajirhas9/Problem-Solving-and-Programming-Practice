#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[5] = {1,2,5,10,15};
    int i,j;
    for(i=0;i<5;i++)
    {
        cout << "Pass " << i+1 << " :" << endl;
        for(j=0;j<5;j++)
        {
            if(a[j] == 15) continue;
            cout << "Comparing " << a[j] << " with " << a[j+1] << endl;
        }
        cout << endl;
    }
}
