#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,a,b,flag=0;
    cin >> a >> b;
    for(i=0;i<a;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<b;j++)
                cout << "#";
            cout << endl;
        }
        else
        {
            if(flag==0)
            {
                for(j=0;j<(b-1);j++)
                    cout << ".";
                cout << "#" << endl;
                flag = 1;
            }
            else
            {
                cout << "#";
                for(j=0;j<(b-1);j++)
                    cout << ".";
                cout << endl;
                flag = 0;
            }
        }
    }
    return 0;
}
