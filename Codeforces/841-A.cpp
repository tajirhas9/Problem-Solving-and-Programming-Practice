#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int l,n,k,i,c[30] = {0};
    char s[200];
    cin >> n >> k;
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        c[s[i]-'a']++;
    }
    for(i=0;i<30;i++)
    {
        if(c[i]>k != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
