#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,t_rem,solved=0,t_need=5;
	cin >> n >> k;
	t_rem = 240-k;
	while(t_rem >=0 && solved<n)
	{
		t_rem -= t_need;
		if(t_rem>=0)	solved++;
		else 	break;
		t_need += 5;
	}
	cout << solved << endl;
	return  0;
}
