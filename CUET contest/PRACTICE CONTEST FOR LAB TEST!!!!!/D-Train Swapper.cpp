#include <iostream>
using namespace std;
int main()
{
    int n,l,a[60],i,j,c=0;
    cin >> n;
    while(n--)
    {
        cin >> l;
        for(i=0;i<l;i++)
            cin >> a[i];
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if(a[i] > a[j])
                {
                    swap(a[i],a[j]);
                    c++;
                }
            }
        }
        cout << "Optimal train swapping takes " << c << " swaps." << endl;
        c = 0;
        if(n==0)
            break;
    }
    return 0;
}
