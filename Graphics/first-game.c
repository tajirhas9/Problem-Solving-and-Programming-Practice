#include <stdio.h>
#include <graphics.h>
int main()
{
	int gd = DETECT;
	int gm;
	initgraph(&gd,&gm,NULL);
	setcolor(BLUE);
	rectangle(0,0,640,480);
	floodfill(320,240,BLUE);
	delay(3000);
	closegraph();
	return 0;
}
