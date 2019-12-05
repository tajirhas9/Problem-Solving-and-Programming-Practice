#include <iostream>
using namespace std;
int main()
{
	int n,i,a,c=0;
	while((cin >> n))
	{
		for(i=0;i<5;i++)
		{
			cin >> a;
			if(a==n)	c++;
			
		}
		cout << c << endl;
		c = 0;
	}
	return 0;
}
