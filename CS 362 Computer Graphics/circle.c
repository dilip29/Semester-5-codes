
#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>



void half_upper_circle(int xc,int yc,int r)
{
int p,x=0,y=r;
p=1-r;

while(x<y)
{
	x++;
    if (p<0)
	{
	 p=p+2*x+1;
	}
    else
	{
	y--;
	p=p+2*x+1-2*y;

	}

    putpixel(xc+x,yc-y,5);
    putpixel(xc+y,yc-x,5);

    putpixel(xc-x,yc-y,5);
    putpixel(xc-y,yc-x,5);

    delay(30);

}



delay(50);
}



void half_lower_circle(int xc,int yc,int r)
{
int p,x=0,y=r;
p=1-r;

while(x<y)
{
	x++;
    if (p<0)
	{
	 p=p+2*x+1;
	}
    else
	{
	y--;
	p=p+2*x+1-2*y;

	}






    	putpixel(xc-x,yc+y,5);
	putpixel(xc-y,yc+x,5);

	putpixel(xc+x,yc+y,5);
	putpixel(xc+y,yc+x,5);


    delay(30);

}



delay(50);
}




void full_circle(int xc,int yc,int r)
{
int p,x=0,y=r;
p=1-r;

while(x<y)
{
	x++;
    if (p<0)
	{
	 p=p+2*x+1;
	}
    else
	{
	y--;
	p=p+2*x+1-2*y;

	}
    putpixel(xc+x,yc+y,5);
    putpixel(xc+x,yc-y,5);
    putpixel(xc-x,yc+y,5);
    putpixel(xc-x,yc-y,5);

    putpixel(xc+y,yc+x,5);
    putpixel(xc+y,yc-x,5);
    putpixel(xc-y,yc+x,5);
    putpixel(xc-y,yc-x,5);
    delay(30);

}



delay(50);
}


void main( )
{
    int xc,yc,r;
    int i,gd=DETECT,gm;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter the center xc and yc ");
    scanf("%d%d",&xc,&yc);
	printf("Enter the radius ");
    scanf("%d",&r);

    full_circle(xc,yc,r);
    half_upper_circle(xc-2*r,yc,r);
    half_lower_circle(xc+2*r,yc,r);
    closegraph();

}

