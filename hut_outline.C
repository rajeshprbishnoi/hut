#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void draw_line(int, int, int, int);
void draw_rectangle(int, int, int, int);
void draw_circle(int, int, int);
void boundary_fill(int, int, int, int);

void draw_rectangle(int x1, int y1, int x2, int y2){
	draw_line(x1, y1, x2, y1);
	draw_line(x2, y1, x2, y2);
	draw_line(x1, y1, x1, y2);
	draw_line(x1, y2, x2, y2);
}

void circle_symmetry(int x, int y, int xc, int yc){
	putpixel(xc+x, yc-y, 15);
	putpixel(xc+y, yc-x, 15);
	putpixel(xc+y, yc+x, 15);
	putpixel(xc+x, yc+y, 15);
	putpixel(xc-x, yc+y, 15);
	putpixel(xc-y, yc+x, 15);
	putpixel(xc-y, yc-x, 15);
	putpixel(xc-x, yc-y, 15);
}

void draw_circle(int xc, int yc, int r){
	int x = 0, y = r;
	int p = 1 - r ;
	circle_symmetry(x, y, xc, yc);
	for(x = 0; x<y; x++){
		if(p<0){
			p += 2*x + 3;
		}
		else {
			p += 2*(x-y) + 5;
			y--;
		}
		circle_symmetry(x, y, xc, yc);
	}
}

void draw_line(int x1, int y1, int x2, int y2){

		float x, y, dx, dy, step;
		int i;

		dx = abs(x2-x1);
		dy = abs(y2-y1);

		if(dx>=dy)
			step = dx ;
		else
			step = dy ;

		dx = dx / step ;
		dy = dy / step ;

		x = x1;
		y = y1;
		i = 1;

		while(i<=step){
			putpixel(x,y,15);
			x += dx ;
			y += dy ;
			i += 1;
		}


}

void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	 // First rectangle
	draw_rectangle(150, 180, 250, 300);
	// second rectangle
	draw_rectangle(250, 180, 420, 300);
	// Door
	draw_rectangle(180, 250, 220, 300);
	// window
	draw_rectangle(310, 220, 360, 260);

	// Roof
	line(200, 100, 150, 180);
	draw_line(200, 100, 250, 180);
	draw_line(200, 100, 370, 100);
	draw_line(370, 100, 420, 180);
	// Roof circle
	draw_circle(200, 150, 10);

	// gate
	// vertical Lines
	draw_line(199, 250, 199, 300);
	draw_line(201, 250, 201, 300);
	// Horizontal Lines
	draw_line(180, 260, 220, 260);
	draw_line(180, 262, 220, 262);
	draw_line(180, 274, 220, 274);
	draw_line(180, 276, 220, 276);
	draw_circle(207, 283, 3);
	draw_line(180, 290, 220, 290);
	draw_line(180, 292, 220, 292);

	// window gate

	draw_line(310, 220, 325, 227);
	draw_line(325, 227, 325, 260);
	draw_circle(318, 242, 3);
	line(360, 220, 345, 227);
	draw_line(345, 227, 345, 260);
	draw_circle(352, 242, 3);

	getch();
	closegraph();
}
