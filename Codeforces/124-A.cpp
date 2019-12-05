#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,cnt=0;
	scanf("%d %d %d",&n,&a,&b); 
	for(int i=1; i<= n; ++i ) {
		if((i-1) >= a && (n-i) <= b)	cnt++;
	}
	cout << cnt << endl;
	return 0;
}
