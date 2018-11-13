
#include <stdio.h>
#include <math.h>
int l=500,b=500;
int mat[500][500]={0};
void linedraw_bres(int x1,int y1,int x2,int y2)
 {
	float m;
     int x,y,p,end;
     int i,step;
     int dx,dy;
    dx=(x2-x1);
    dy=(y2-y1);
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
	    //putpixel(x,y,5);
	    //delay(30);
	    	mat[(int)y][(int)x]=255;
		y++;
	}
	return;
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
	    //putpixel(x,y,5);
	    //delay(30);
	    	mat[(int)y][(int)x]=255;
		x++;
	}
	return;
    }


     m=dy/(1.0*dx);
    // printf("%f",m);



    if (abs(m)<1.0)
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

		y=y+1;
		p=p+2*dy-2*dx;
		//putpixel(x,y,5);
		//delay(30);
			mat[(int)y][(int)x]=255;
		}
		else
		{


		p=p+2*dy;
		//putpixel(x,y,5);
			mat[(int)y][(int)x]=255;
		//delay(30);
		}

		x=x+1;
		}


    }

    else if(abs(m)>1.0)
    {


	    p=2*dy-dx;

	    if(y1<y2)
	    {

	    y=y1;
	    end=y2;
	    x=x1;
	    }
	    else
	    {
	    x=x2;
	    end=y1;
	    y=y2;
	    }


	    while(y<end)
	    {
	    if(p>=0)
	    {

	    x=x+1;
	    p=p+2*dy-2*dx;
	    //putpixel(x,y,5);
	    //delay(30);
	    	mat[(int)y][(int)x]=255;
		}
	    else
	    {


	    p=p+2*dy;
	    //putpixel(x,y,5);
	    	mat[(int)y][(int)x]=255;
		//delay(30);
	    }

	    y=y+1;
	    }


    }


    else if (m==-1.0)
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
		    //putpixel(x,y,5);
		    //delay(30);
		    	mat[(int)y][(int)x]=255;
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
		    //putpixel(x,y,5);
				mat[(int)y][(int)x]=255;
		    //delay(30);
		    x++;
		    y++;
		}

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
	//putpixel(x,y,5);
	mat[(int)y][(int)x]=255;
	x=(x+dx);
	y=(y+dy);
	i=i+1;
	//delay(30);
    }


}

int main( )
{
    int x,y,x1,y1,x2,y2,dx,dy,step;
   // int i,gd=DETECT,gm;

    //initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    printf("Enter the value of x1 and y1 : ");
    scanf("%d%d",&x1,&y1);
	printf("Enter the value of x2 and y2 : ");
    scanf("%d%d",&x2,&y2);

    linedraw_bres(x1,y1,x2,y2);

	  FILE* ellipseimg;
    ellipseimg=fopen("ellipseimg.pgm","wb");

    fprintf(ellipseimg,"P2\n");
    fprintf(ellipseimg,"%d %d\n",l,b);
    fprintf(ellipseimg,"255\n");

    int i,j,temp;
    for(i=0;i<l;i++)
    {
        for(j=0;j<b;j++)
        {
           temp=mat[i][j];
           fprintf(ellipseimg,"%d ",temp);
        }
        fprintf(ellipseimg,"\n");
    }

    fclose(ellipseimg);

    //closegraph();

	return 0;

}

