#include <bits/stdc++.h>
using namespace std;
#define ll long long
class children
{
	string name;
	ll b_height,d_height;
	public :
	void input(void);
	bool status(void);
	string getName(void)
	{
		return name;
	}
};
void children::input(void)
{
	cin >> name >> b_height >> d_height;
}
bool children::status(void)
{
	ll dif;
	dif = d_height-b_height;
	return (dif<5); 
}
children child[10000];
int main()
{
	ll T,i;
	cin >> T;
	for(i=0;i<T;i++)
	{
		child[i].input();
	}
	for(i=0;i<T;i++)
	{
		if(child[i].status())	cout << child[i].getName() << " Danger" << endl;
		else 					cout << child[i].getName() << " Safe" << endl;
	}
	return  0;
}


