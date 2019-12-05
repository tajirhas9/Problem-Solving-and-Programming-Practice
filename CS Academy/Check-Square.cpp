#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ab,da,bc,cd,ac,bd,x1,x2,x3,x4,y1,y2,y3,y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ab = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	bc = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	cd = sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
	da = sqrt((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1));
	ac = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	bd = sqrt((x2-x4)*(x2-x4)+(y2-y4)*(y2-y4));
	if(ab==bc==cd==da)
	return 0;
}
