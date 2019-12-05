#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,steps=0,a[150],i,j,mi=160,posMax,posMin;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    posMax = (max_element(a,a+n) - a );
    for(int i=0; i<n; ++i) {
        if(a[i] <= mi) {
            mi = a[i];
            posMin = i;
        }
    }
    while(posMax > 0) {
        if(posMax-1 == posMin)    posMin++;
        swap( a[posMax-1], a[posMax] );
        posMax--;
        steps++;
    }
    while(posMin < (n-1))  {
        swap(a[posMin], a[posMin+1]);
        posMin++;
        steps++;
    }
    cout << steps << endl;
    return 0;
}

