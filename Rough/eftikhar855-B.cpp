#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,p,q,r,i,sum = 0;
	long int a[1000001],mn,mx;
	cin >> n >> p >> q >> r;

	for(i = 0; i < n; i++){
		cin >> a[i];
	}

//	mn = *min_element(a, a+n);
	mx = max_element(a, a+n) - a;
//	cout << mx << " " ;//<< mn << endl;
	sort(a+mx, a+n);

	//for(i = 0; i < n; i++)
	//	cout << a[i] << endl;

	if(p < 0 && a[n-1] <= 0)
		sum += p*a[mx];

	if(p < 0 && a[n-1] > 0)
		sum += p*a[mx];

	if(p > 0 && a[n-1] > 0)
		sum += p*a[n-1];

	if(p > 0 && a[n-1] <= 0)
		sum += p*a[n-1];

	if(q < 0 && a[n-1] <= 0)
		sum += q*a[mx];

	if(q < 0 && a[n-1] > 0)
		sum += q*a[mx];

	if(q > 0 && a[n-1] > 0)
		sum += q*a[n-1];

	if(q > 0 && a[n-1] < 0)
		sum += q*a[n-1];

	if(r < 0 && a[n-1] <= 0)
		sum += r*a[mx];

	if(r < 0 && a[n-1] > 0)
		sum += r*a[mx];

	if(r > 0 && a[n-1] > 0)
		sum += r*a[n-1];

	if(r > 0 && a[n-1] < 0)
		sum += r*a[n-1];

	cout << sum << endl;

	return 0;
}
