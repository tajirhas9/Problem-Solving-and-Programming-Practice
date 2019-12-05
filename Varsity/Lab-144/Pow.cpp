#include <iostream>
using namespace std;
int power(int n,int r);
int main()
{
	int n,r;
	cin >> n >> r;
	cout << power(n,r) << endl;
	return 0;
}
int power(int n,int r)
{
	int s=n;
	for(int i=2;i<=r;i++)
		s *= n;
	return s;
}
