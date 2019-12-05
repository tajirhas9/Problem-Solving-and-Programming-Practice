#include<iostream>
#include<graphics.h>
using namespace std;

#define LEFT 37
#define UP 38
#define RIGHT 39
#define DOWN 40

class character {

	int x = 320, y = 240;
	int x_radius = 50 , y_radius = 50;
	int x_min = x-100, x_max = x+100;
	int y_min = y-100 , y_max = y+100;
/*
	int shadow_x = 320 , shadow_y = 320;
	int shadow_x_radius = 50 , y_radius = 30;
	int shadow_x_radiusMin = shadow_x_radius - 10 , shadow_x_radiusMax = shadow_x_radius + 10;
	int shadow_y_radiusMin = shadow_y_radius - 5 , shadow_y_radiusMax = shadow_y_radius + 5;
*/
	void createObject() {
		while(1) {
			int i,j;

			for(i = x_radius-10, j = y_radius+10; i <= x_radius+10; ++i, --j) {
				cleardevice();
				setcolor(GREEN);
				fillellipse(x,y,i,j);
				createShadow(x,y,i,j);
				delay(20);
			}

			for(i = x_radius+10, j = y_radius-10; i >= x_radius-10; --i, ++j) {
				cleardevice();
				setcolor(GREEN);
				fillellipse(x,y,i,j);
				createShadow(x,y,i,j);
				delay(20);
			}
		}
	}

	void createShadow(int sx, int sy, int ix, int iy) {
		iy = (iy * 2) / 5;

		sy += 120;
		setcolor(BLUE);
		fillellipse(sx,sy,ix,iy);
	}

public:
	character() {
		createObject();
	}

	void goLeft() {
		x -= 20;
	}
	void goRight() {
		x += 20;
	}

	void goUp() {
		y -= 20;
	}
	void goDown() {
		y += 20;
	}
};

void wait_for_char() {

    //Wait for a key press
    int in = 0;

	while (in == 0) {
	    in = getchar();
	}
}

bool checkKey(int ascii) {
	int x;
	cin >> x;

	return x == ascii;
}

int main()
{
	int gd = DETECT,gm,x,y,i;
	initgraph(&gd,&gm,NULL);
	
	character shape;

	while(1) {

		if(checkKey(LEFT))
			shape.goLeft();
		else if(checkKey(RIGHT))
			shape.goRight();
		else if(checkKey(UP))
			shape.goUp();
		else if(checkKey(DOWN))
			shape.goDown();
		else
			break;
	}

	wait_for_char();

	delay(10000);

	closegraph();
	return 0;
}
