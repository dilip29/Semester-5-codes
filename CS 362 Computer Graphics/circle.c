#include <stdio.h>
#include <math.h>

int l=500,b=500;
int mat[500][500]={0};


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




    mat[yc-y][xc+x]=255;
    mat[yc-x][xc+y]=255;

    mat[yc-y][xc-x]=255;
    mat[yc-x][xc-y]=255;

    //delay(30);

}



//delay(50);
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


    mat[yc+y][xc-x]=255;
	mat[yc+x][xc-y]=255;

	mat[yc+y][xc+x]=255;
	mat[yc+x][xc+y]=255;


    //delay(30);

}



//delay(50);
}


void full_circle(int xc,int yc,int r)
{
int p,x=0,y=r;
p=1-r;

while(x<=y)
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

    mat[xc+x][yc+y]=255;
    mat[xc+x][yc-y]=255;
    mat[xc-x][yc+y]=255;
    mat[xc-x][yc-y]=255;

    mat[xc+y][yc+x]=255;
    mat[xc+y][yc-x]=255;
    mat[xc-y][yc+x]=255;
    mat[xc-y][yc-x]=255;


}



//delay(50);
}


void main( )
{
    int xc,yc,r;


    printf("Enter the center xc and yc ");
    scanf("%d%d",&xc,&yc);
	printf("Enter the radius ");
    scanf("%d",&r);

    full_circle(xc,yc,r);
    half_upper_circle(xc-2*r,yc,r);
    half_lower_circle(xc+2*r,yc,r);

    int x1=xc-3*r,x2=xc+3*r;
    while(x1<=x2)
    {
        mat[yc][x1]=255;
        x1++;
    }
   //mat[xc][yc-2*r]=255;


    int i,j,temp;
    FILE* pgmimg;
    pgmimg=fopen("pgmimg.pgm","wb");

    fprintf(pgmimg,"P2\n");
    fprintf(pgmimg,"%d %d\n",b,l);

    fprintf(pgmimg,"255\n");



    for (i = 0; i < l; i++) {
        for (j = 0; j < b; j++) {
            temp = mat[i][j];

            // Writing the gray values in the 2D array to the file
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);


}