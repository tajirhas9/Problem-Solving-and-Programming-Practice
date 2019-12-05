#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	double x,y,x_angle,y_angle,dif;
	while(1)
	{
		scanf("%lf:%lf",&x,&y);
		if(x==0 && y == 0)	return 0;
		x_angle = (30*x+(.5*y));
		y_angle = (6*y);
		if(x_angle > y_angle)	dif = x_angle - y_angle;
		else	dif = y_angle - x_angle;
		if(dif > 180)
			dif = 360-dif;
		printf("%0.3lf\n",dif);
	}
}
