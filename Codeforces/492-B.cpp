#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,a[100005],j,i;
	double b[100000];
	cin >> n >> l;
	for(int i=0;i<n;i++)	cin >> a[i];
	sort(a,a+n);
	b[0] = a[0];
	for(i=0,j=1;i<(n-1);i++,j++)
		b[j] = 0.5*(a[i+1]-a[i]);
	b[j++] = l-a[n-1];
	sort(b,b+j);
	printf("%.10lf\n",b[j-1]);
	return 0;
}
