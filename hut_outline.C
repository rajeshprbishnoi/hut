#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void draw_line(int, int, int, int);
void draw_rectangle(int, int, int, int);
void draw_circle(int, int, int);

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
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	 // front rectangle
	draw_rectangle(150, 180, 250, 300);
	// side rectangle
	draw_rectangle(250, 180, 420, 300);
	// Door rectangle
	draw_rectangle(180, 250, 220, 300);
	// windows rectangle
	draw_rectangle(280, 220, 390, 260);
    draw_line(335, 220, 335, 260);
    draw_circle(325, 240, 3);
    draw_circle(345, 240, 3);
    draw_line(325, 240, 345, 240);
    
	// Roof of hut
	line(200, 100, 150, 180);
	draw_line(200, 100, 250, 180);
	draw_line(200, 100, 370, 100);
	draw_line(370, 100, 420, 180);
	
	//Roof sections
	draw_line(225, 140, 395, 140);
	draw_line(285, 100, 335, 180);
	draw_line(243, 100, 293, 180);
	draw_line(327, 100, 377, 180);
    
    // ventilator
	draw_circle(200, 150, 10);

    // front horizontal lines
	draw_line(150, 200, 250, 200);
	draw_line(150, 225, 250, 225);
	// front angular lines
	draw_line(150, 225, 180, 250);
	line(250, 225, 220, 250);
	
	// door vertical lines
	draw_line(199, 250, 199, 300);
	draw_line(201, 250, 201, 300);
	// door latch
	draw_circle(207, 283, 3);
	
	// Side angular lines 
	draw_line(250,180, 280, 220);
	line(280, 260, 250, 300);
	line(420, 180, 390, 220);
	draw_line(390, 260, 420, 300);
    
    draw_rectangle(293, 180, 377, 200);
    draw_rectangle(293, 280, 377, 300);
    
	
	getch();
	closegraph();
}
