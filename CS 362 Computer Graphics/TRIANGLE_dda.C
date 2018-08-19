#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
float minx,miny;
float dist(float x1,float x2,float y1,float y2)
{
float dist;
dist=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
return dist;

}





 void mini(float x1,float y1,float x2,float y2)
 {
if (x1<x2)
    minx=x1,miny=y1;
else if(x1==x2)
    {

    if(y1<y2)
    minx=x1,miny=y1;
    else
    minx=x2,miny=y2;
    }
else
    minx=x2,miny=y2;


 }
 void linedraw(float x1,float y1,float x2,float y2)
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
    float x,y,x1,y1,x2,y2,x3,y3,dx,dy,step;
    int i,gd=DETECT,gm;
	float a,b,c;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter the value of x1 and y1 : ");
    scanf("%f%f",&x1,&y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%f%f",&x2,&y2);
    printf("Enter the value of x3 and y3 : ");
    scanf("%f%f",&x3,&y3);


    minx=x1,miny=y1;
    mini(minx,miny,x2,y2);
    mini(minx,miny,x3,y3);
    //mini(minx,miny,x4,y4);
    printf("%f%f",minx,miny);

      if(minx==x1 && miny==y1 )
    {
		printf("coomeie");
	       linedraw(x1,y1,x2,y2);
	      linedraw(x1,y1,x3,y3);

		if(x3 <=x2)
		linedraw(x3,y3,x2,y2);
		else
		linedraw(x2,y2,x3,y3);

	    }


	    else if(minx==x2 && miny==y2)
	    {
	       //printf("saregamapa");
		linedraw(x2,y2,x1,y1);
		linedraw(x2,y2,x3,y3);
		if(x3<=x1)
		linedraw(x3,y3,x1,y1);
		else
		linedraw(x1,y1,x3,y3);
	    }


	    else
	    {


		linedraw(x3,y3,x1,y1);
		linedraw(x3,y3,x2,y2);
		if(x1<=x2)
		linedraw(x1,y1,x2,y2);
		else
		linedraw(x2,y2,x1,y1);
	    }



    closegraph();

}

