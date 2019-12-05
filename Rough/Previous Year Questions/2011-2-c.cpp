#include <cstdio>
using namespace std;
int main()
{
	int a,b,x,y;
	a=2;
	b=2;
	x = 4*(2*++a+3);
	y = 4*(b++*2+3);
	printf("a=%d,b=%d,x=%d,y=%d\n",a,b,x,y);
	return 0;
}
