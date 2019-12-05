#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,guest_per_gate[26] = {0},total_guest,guards[26] = {0},total_guards;
    string s;
    cin >> total_guest >> total_guards;
    cin >> s;
    for(i=0;i<total_guest;i++)
    {
        guest_per_gate[s[i]-65]++;
    }
    for(i=0;i<26;i++)
    {
        if(guest_per_gate[i] == 0)
            guest_per_gate[i] = -1;
    }
    for(i=0;i<total_guest;i++)
    {
        if(guards[s[i]-65] == 0 && total_guards > 0)
        {
            guards[s[i]-65] = 1;
            total_guards--;
        }
        else if(total_guards <= 0 && guards[s[i]-65] == 0)
        {
            for(j=0;j<26;j++)
            {
                if(guest_per_gate[j] == 0)
                {
                    guards[j] = 0;
                    guards[s[i]-65] = 1;
                    guest_per_gate[j] = -1;
                    break;
                }
            }
            if(j>= 26)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        guest_per_gate[s[i]-65]--;
    }
    cout << "NO" << endl;
    return 0;
}
