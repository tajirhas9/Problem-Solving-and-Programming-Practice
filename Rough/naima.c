#include <stdio.h>
#include <math.h>

int main ()
{
	double x1,y1,d,d1;
	double x2,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	d1 = (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	d = sqrt(d1);
	printf("%0.4lf\n",sqrt(d));
	return 0;
}
