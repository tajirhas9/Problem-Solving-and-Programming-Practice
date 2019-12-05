#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lightSpeed 186000
class planet
{
	string name;
	double dist,diam;
	int num_moon;
	void set_name(void)
	{
		cin >> name;
	}
	void set_moons(void)
	{
		cin >> num_moon;
	}
	void set_dist(void)
	{
		cin >> dist;
	}
	void set_diam(void)
	{
		cin >> diam;
	}
	public:
	string get_name(void)
	{
		return name;
	}
	int get_moons(void)
	{
		return num_moon;
	}
	double get_dist(void)
	{
		return dist;
	}
	double get_diam(void)
	{
		return diam;
	}
	void input(void);
	friend double light(planet);
};
void planet::input(void)
{
	set_name();
	set_dist();
	set_diam();
	set_moons();
}
double light(planet a)
{
	return (a.get_dist()/lightSpeed)*1000000;
	
}
planet p[100000];
int main()
{
	int T,i;
	cin >> T;
	for(i=0;i<T;i++)
		p[i].input();
	for(i=0;i<T;i++)
		cout << light(p[i]) << endl;
	return  0;
}

