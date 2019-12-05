#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int time,i,j;
	char start,end,a[4] = {'<','^','>','v'};
	cin >> start >> end;
	cin >> time;
	if((start == '^' && (end == 'v')) ||
		(start == 'v' && end == '^') ||
		(start == '<' && end == '>') ||
		(start == '>' && end == '<') ||
		time == 0)
	{
		cout << "undefined" << endl;
		return 0;
	}
	else
	{
		j=0;
		while(start != a[j])
		{
			j++;
		}
		for(i=1;i<=time;i++)
		{
			j++;
			if(j > 3) j = 0;
		}
		if(a[j] == end)
			cout << "cw" << endl;
		else
			cout << "ccw" << endl;
	}
	return 0;
}
