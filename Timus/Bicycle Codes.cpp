#include <bits/stdc++.h>
using namespace std;
int main()
{
	int thief_lock=0,first_lock,second_lock,day=0;
	cin >> first_lock >> second_lock;
	while(thief_lock <= max(first_lock,second_lock))
	{
		if(day%2==0)
		{
			if(thief_lock == first_lock)
			{
				cout << "yes" << endl;
				return 0;
			}
		}
		else
		{
			if(thief_lock == second_lock)
			{
				cout << "yes" << endl;
				return 0;
			}
		}
		day++;
		thief_lock++;
	}
	cout << "no" << endl;
	return 0;
}
