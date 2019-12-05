#include <bits/stdc++.h>
using namespace std;
#define ll long long
class product
{
	public:
	int d_taka,d_poisa,a_taka,a_poisa,red_taka,red_poisa;
	double red;
	void get_demand(void);
	void get_agreed(void);
	void set_reduce(void);
};
bool operator < (const product &l, const product &r) { return !(l.red < r.red); }
void product::get_demand(void)
{
	cin >> d_taka >> d_poisa;
}
void product::get_agreed(void)
{
	cin >> a_taka >> a_poisa;
}
void product::set_reduce(void)
{
	double d,a;
	d = d_taka+(d_poisa/100);
	a = a_taka+(d_poisa/100);
	red = d-a;
	red_taka = red;
	
}
product p[100000];
int main()
{
	int T,i;
	cin >> T;
	for(i=0;i<T;i++)
	{
		p[i].get_demand();
	}
	for(i=0;i<T;i++)
	{
		p[i].get_agreed();
		p[i].set_reduce();
	}
	for(i=0;i<T;i++)
	{
		cout << p[i].red_taka << " " << p[i].red_poisa << endl;
	}
	return  0;
}


