#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,j,q,l,a[10000]= {0},k=0,m=0,x,y,flag = 0;;
    cin >> q;
    for(i=1; i<=q; i++)
    {
        cin >> s;
        l = s.length();
        //cout << l << endl;
        for(j=0; j<l; j++)
        {
            //cout << "j = " << j << endl;
            if(s[j] == '1' && s[j+1] == '0')
            {
                j++;
                for(; s[j] != '1'; j++)
                {
                    if(s[j] != '0')
                    {
                        flag = 1;
                        a[k] = 0;
                        break;
                    }
                    a[k]++;
                }
                if(flag == 0)
                    k++;
                j--;
            }
            flag = 0;
        }
        //for(j=0;j<k;j++)
            //cout << a[j] << endl;
        for(x=0;x<k;x++)
        {
            for(y=x+1;y<k;y++)
            {
                if(a[x] == a[y])
                {
                    m++;
                    a[y]  = 30000-y;
                }
            }
        }
        cout << k << endl;
        m = 0;
        for(j=0; j<3000; j++)
        {
            a[j] = 0;
        }
        k  = 0;
        flag = 0;
    }
    return 0;
}

