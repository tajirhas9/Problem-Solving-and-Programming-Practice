#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int gd = DETECT,gm,x,y,i;
	initgraph(&gd,&gm,NULL);
	i=1;
	while(!kbhit())
	{
		if(i%2==1)
		{
			delay(200);
			cleardevice();
			setcolor(YELLOW);
			fillellipse(320,240,100,80);
			setcolor(BLACK);
			fillellipse(270,200,15,15);
			fillellipse(370,200,15,15);
			arc(320,240,50,130,50);
			line(320,230,310,240);
			line(320,250,310,240);
		}
		else
		{
			delay(1000);
			cleardevice();
			setcolor(YELLOW);
			fillellipse(320,240,100,80);
			setcolor(BLACK);
			line(255,215,285,215);
			line(365,215,385,215);
			arc(320,240,50,130,50);
			line(320,230,310,240);
			line(320,250,310,240);
		}
		i++;
	}
	closegraph();
	return 0;
}
