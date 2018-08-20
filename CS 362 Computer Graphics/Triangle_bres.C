#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
int minx,miny;
float dist(float x1,float x2,float y1,float y2)
{
float dist;
dist=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
return dist;

}





 void mini(int x1,int y1,int x2,int y2)
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



 void linedraw(int x1,int y1,int x2,int y2)
 {

	float m;
     int x,y,p,end;
     int i,step;
     int dx,dy;
    dx=(x2-x1);
    dy=(y2-y1);

    if(dx!=0)
       {

        m=dy/(1.0*dx);
       printf("value of m= %f",m);
       }


    if (dx==0)
    {
            x=x1;
            if (y1<y2)
            {
               y=y1;
               end=y2;
            }
            else
                {
                    y=y2;
                    end=y1;
                }

            while(y<end)
            {
                putpixel(x,y,5);
                delay(30);
                y++;
            }
            //return;
    }

     else if(dy==0)
    {
                  y=y1;
            if (x1<x2)
            {
               x=x1;
               end=x2;
            }
            else
            {
                x=x2;
                end=x1;
            }

            while(x<end)
            {
                putpixel(x,y,5);
                delay(30);
                x++;
            }
            //return;
    }




    else if (abs(m)<1.0)
    {

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


		p=p+2*dy-2*dx;
		putpixel(x,y,5);
		delay(30);
		y=y+1;
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

    else if((m)>1.0)
    {

        printf("4th line");
	    p=2*dx-dy;

	    if(y1<y2)
	    {

	    y=y1;
	    end=y2;
	    x=x1;
	    }
	    else
	    {
	    y=y2;
	    end=y1;
	    x=x2;
	    }


	    while(y<end)
	    {
	    if(p>=0)
	    {

	    p=p+2*dx-2*dy;
	    putpixel(x,y,5);
	    delay(30);
        x=x+1;

	    }
	    else
	    {


	    p=p+2*dx;
	    putpixel(x,y,5);
	    delay(30);

	    }

	    y=y+1;
	    }


    }


     else if (m==-1.0)
    {
printf("3rd line");
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
		    putpixel(x,y,5);
		    delay(30);
		    x++;
		    y--;
		}

    }



    else

    {

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
		    putpixel(x,y,5);
		    delay(30);
		    x++;
		    y++;
		}

    }





}


void main( )
{
    int x,y,x1,y1,x2,y2,x3,y3,dx,dy,step;
    int i,gd=DETECT,gm;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter the value of x1 and y1 : ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%d%d",&x2,&y2);
    printf("Enter the value of x3 and y3 : ");
    scanf("%d%d",&x3,&y3);


    minx=x1,miny=y1;
    mini(minx,miny,x2,y2);
    mini(minx,miny,x3,y3);
    //mini(minx,miny,x4,y4);
    printf("%d%d",minx,miny);

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

