

#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
float minx,miny,maxx,maxy;
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


 void maxi(float x1,float y1,float x2,float y2)
 {
if (x1<x2)
    maxx=x2,maxy=y2;
else if(x1==x2)
    {

    if(y1<y2)
    maxx=x2,maxy=y2;
    else
    maxx=x1,maxy=y1;
    }
else
    maxx=x1,maxy=y1;


 }


void linedraw(float x1,float y1,float x2,float y2)
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




void main( )
{
    float x,y,x1,y1,x2,y2,x3,y3,x4,y4,dx,dy,step;
    int i,gd=DETECT,gm;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter the value of x1 and y1 : ");
    scanf("%f%f",&x1,&y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%f%f",&x2,&y2);
    printf("Enter the value of x3 and y3 : ");
    scanf("%f%f",&x3,&y3);
    printf("Enter the value of x4 and y4: ");
    scanf("%f%f",&x4,&y4);

    minx=x1,miny=y1;
    mini(minx,miny,x2,y2);
    mini(minx,miny,x3,y3);
    mini(minx,miny,x4,y4);

       maxx=x1,maxy=y1;
    maxi(maxx,maxy,x2,y2);
    maxi(maxx,maxy,x3,y3);
    maxi(maxx,maxy,x4,y4);

    printf("%f%f\n",minx,miny);
    printf("%f%f",maxx,maxy);


/*
    a=dist(minx,x1,miny,y1);
    b=dist(minx,x2,miny,y2);
    c=dist(minx,x3,miny,y3);
    d=dist(minx,x4,miny,y4);
*/

    //x1=minx,y1=miny;
    if(minx==x1 && miny==y1 )
    {
        /*
    a=dist(x1,x2,y1,y2);
    b=dist(x1,x3,y1,y3);
    c=dist(x1,x4,y1,y4);
*/
    //draw(a,b,c);
	    if(maxx==x2 && maxy==y2)
	    {

	       	printf("oooooooooooo");
	       linedraw(x1,y1,x3,y3);
		linedraw(x1,y1,x4,y4);
		linedraw(x4,y4,x2,y2);
		linedraw(x3,y3,x2,y2);
	    }

	    else if(maxx==x3 && maxy==y3)
	    {
	       //printf("saregamapa");
		linedraw(x1,y1,x2,y2);
		linedraw(x1,y1,x4,y4);
		linedraw(x4,y4,x3,y3);
		linedraw(x2,y2,x3,y3);
	    }

	    else
	    {
	       printf("saregamapa");
		    linedraw(x1,y1,x2,y2);
		linedraw(x1,y1,x3,y3);
		linedraw(x3,y3,x4,y4);
		linedraw(x2,y2,x4,y4);
	    }

     }

    else if(minx==x2 && miny==y2)
    {
    /*
    a=dist(x2,x1,y2,y1);
    b=dist(x2,x3,y2,y3);
    c=dist(x2,x4,y2,y4);

    */  //draw(a,b,c)
	  if(maxx==x1 && maxy==y1)
	    {

		//printf("saregamapa");
	       linedraw(x2,y2,x3,y3);
		linedraw(x2,y2,x4,y4);
		linedraw(x4,y4,x1,y1);
		linedraw(x3,y3,x1,y1);
	    }

	    else if(maxx==x3 && maxy==y3)
	    {

	       //	printf("ooooopsss");
		linedraw(x2,y2,x1,y1);
		linedraw(x2,y2,x4,y4);
		linedraw(x1,y1,x3,y3);
		linedraw(x4,y4,x3,y3);
	    }

	    else
	    {

		//printf("saregamapa");
		    linedraw(x2,y2,x1,y1);
		linedraw(x2,y2,x3,y3);
		linedraw(x3,y3,x4,y4);
		linedraw(x1,y1,x4,y4);
	    }



    }

    else if(minx==x3 && miny==y3)
    {
	/*
	 a=dist(x3,x1,y3,y1);
    b=dist(x3,x2,y3,y2);
    c=dist(x3,x4,y3,y4);
	//draw(a,b,c);
*/
		if(maxx==x1 && maxy==y1)
	    {
		//printf("saregamapa");
	       linedraw(x3,y3,x2,y2);
		linedraw(x3,y3,x4,y4);
		linedraw(x2,y2,x1,y1);
		linedraw(x4,y4,x1,y1);
	    }

	    else if(maxx==x2 && maxy==y2)
	    {
		//printf("saregamapa");
		linedraw(x3,y3,x1,y1);
		linedraw(x3,y3,x4,y4);
		linedraw(x1,y1,x2,y2);
		linedraw(x4,y4,x2,y2);
	    }

	    else
	    {

		//printf("saregamapa");
		    linedraw(x3,y3,x2,y2);
		linedraw(x3,y3,x1,y1);
		linedraw(x1,y1,x4,y4);
		linedraw(x2,y2,x4,y4);

	    }



    }

    else
	    {
/*
    a=dist(x4,x1,y4,y1);
    b=dist(x4,x2,y4,y2);
    c=dist(x4,x3,y4,y3);

		*/

		if(maxx==x1 && maxy==y1)
		{
		   // printf("saregamapa");
		   linedraw(x4,y4,x2,y2);
		    linedraw(x4,y4,x3,y3);
		    linedraw(x3,y3,x1,y1);
		    linedraw(x2,y2,x1,y1);
		}

		else if(maxx==x2 && maxy==y2)
		{

		    //printf("saregamapa");
		    linedraw(x4,y4,x1,y1);
		    linedraw(x4,y4,x3,y3);
		    linedraw(x1,y1,x2,y2);
		    linedraw(x3,y3,x2,y2);
		}

		else
		{

		    //printf("saregamapa");
		    linedraw(x4,y4,x2,y2);
		    linedraw(x4,y4,x1,y1);
		    linedraw(x1,y1,x3,y3);
		    linedraw(x2,y2,x3,y3);
		}



	    }



    closegraph();

}
