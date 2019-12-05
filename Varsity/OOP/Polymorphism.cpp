#include <bits/stdc++.h>
using namespace std;
class shape
{
	protected:
		double a,b;
	public:
		void getdata(double x,double y=0)
		{
			a = x;
			b = y;
		}
		virtual double displayArea(void)=0;
};
class rectangle:public shape
{
	public:
		void getdata(double x,double y)
		{
			a = x;
			b = y;
		}
		double displayArea(void)
		{
			return a*b;
		}
};
class triangle:public shape
{
	public:
		void getdata(double x,double y)
		{
			a = x;
			b = y;
		}
		double displayArea(void)
		{
			return .5*a*b;
		}
};
class circle:public shape
{
	public:
		void getdata(double r)
		{
			a=r;
		}
		double displayArea(void)
		{
			return 3.1416*a*a;
		}
};
int main()
{
	rectangle a;
	triangle b;
	circle c;
	int choice;
	double x,y;
	while(1)
	{
		cout << "Press" << endl;
		cout << "    " << "1 for area of Rectangle" << endl;
		cout << "    " << "2 for area of triangle" << endl;
		cout << "    " << "3 for area of Circle" << endl;
		cout << "    " << "4 to exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter the two sides of the rectangle: ";
				cin >> x >> y;
				a.getdata(x,y);
				cout << a.displayArea() << endl;
				break;
			case 2:
				cout << "Enter the base & height of the triangle: ";
				cin >> x >> y;
				b.getdata(x,y);
				cout << b.displayArea() << endl;
				break;
			case 3:
				cout << "Enter the radius of the circle: ";
				cin >> x;
				c.getdata(x);
				cout << c.displayArea() << endl;
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
