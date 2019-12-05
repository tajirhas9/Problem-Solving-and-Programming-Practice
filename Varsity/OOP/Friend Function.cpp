#include <iostream>
using namespace std;
class db;
class dm
{
	public:
	double a,b;
	void input(void);
	friend double add(dm,db);
};
class db
{
	public:
	double a,b;
	void input(void);
	friend double add(db,dm);
	void convert();
};
void dm::input()
{
	cout << "Enter Values for meters: ";
	cin >> a;
	cout << "Enter values for centimeters: ";
	cin >> b;
}
void db::input()
{
	cout << "Enter Values for feet: ";
	cin >> a;
	cout << "Enter values for inches: ";
	cin >> b;
	convert();
}
void db::convert()
{
	a *= .3048;
	b *= 2.54;
}
double add(db x,dm y)
{
	return x+y;
}
int main()
{
	dm a;
	db b;
	cout << "CLASS DM:" << endl;
	a.input();
	cout << "CLASS DB:" << endl;
	b.input();
	cout << "Friend Function Addition:" << endl;
	cout << "Total value of distance in meters: " << add(a.a,b.a) << endl;
	cout << "Total value of distance in centimeters: " << add(a.b,b.b) << endl;
}
