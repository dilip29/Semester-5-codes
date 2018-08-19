
#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>

void linedraw_bres(float x1,float y1,float x2,float y2)
 {
     float x,y,p,end;
     float i,step;
     float dx,dy;
    dx=(x2-x1);
    dy=(y2-y1);

    p=2*dy-dx;

    if(x1<x2)
    {

    x=x1;
    end=x2;
    y=y1;
    }
    else
    {
	x=x2;
	end=x1;
	y=y2;
    }


    while(x<end)
    {
    if(p>=0)
    {

	y=y+1;
	p=p+2*dy-2*dx;
	putpixel(x,y,5);
	delay(30);
    }
    else
    {


	p=p+2*dy;
	putpixel(x,y,5);
	delay(30);
    }

    x=x+1;
    }


}




 void linedraw_dda(float x1,float y1,float x2,float y2)
 {
     float x,y;
     int i,step;
     float dx,dy;
    dx=(x2-x1);
    dy=(y2-y1);

    if(abs(dx)>=abs(dy))
	step=abs(dx);
    else
	step=abs(dy);

    dx=dx/step;
    dy=dy/step;

    x=x1;
    y=y1;

    i=1;
    while(i<=step)
    {
	putpixel(x,y,5);
	x=(x+dx);
	y=(y+dy);
	i=i+1;
	delay(30);
    }


}

void main( )
{
    float x,y,x1,y1,x2,y2,dx,dy,step;
    int i,gd=DETECT,gm;
      float a,b,c;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter the value of x1 and y1 : ");
    scanf("%f%f",&x1,&y1);
	printf("Enter the value of x2 and y2 : ");
    scanf("%f%f",&x2,&y2);

    linedraw_bres(x1,y1,x2,y2);

    closegraph();

}

