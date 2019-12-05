#include <bits/stdc++.h>
using namespace std;
class parent
{
	private:
	int a=10,b=100;
	public:
	int get_a(void)	{return a; };
};
class child:public parent
{
	private:
	int c,d;
	public:
	int get_c(void){ return c; };
	child(int x,int y) {c = x; d = y;};
	child(void)	{c=0;d=0;};
	child operator=(child &ob)
	{
		c = ob.c;
		d = ob.d;
		return *this;
	}	
};
int main()
{
	child ob1(6,7),*it;
	it = &ob1;
	cout << it->get_a() << endl;
}
