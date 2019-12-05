#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,l,a[1100],i,j,c=0;
    while((scanf("%d",&l)) == 1)
    {
        for(i=0;i<l;i++)
            cin >> a[i];
        for(i=0;i<l;i++)
        {
            for(j=0;j< (l-1);j++)
            {
                if(a[j] > a[j+1])
                {
                    swap(a[j],a[j+1]);
                    c++;
                }
            }
        }
        cout << "Minimum exchange operations : " << c << endl;
        c = 0;
    }
    return 0;
}
