#include <stdio.h>
#include<math.h>

int l=500,b=500;
int mat[500][500]={0};

void ellipse(int xc,int yc,int rx,int ry , float theta)
{

float p1,p2;
int x,y,xf,yf;
float theta1=-theta;
x=0;
y=ry;
xf=0;
yf=0;
int x_shifted1,y_shifted1,m,x_shifted2,y_shifted2;
//region 1
p1=(float)((rx*rx)/4) + (ry*ry) -(rx*rx*ry);

m=0;
while(m<500)
{
    mat[m][254]=255;
    mat[254][m]=255;
    m=m+10;
}


while((x*ry*ry) <= (y*rx*rx))
{
    x_shifted1=x*cos(theta) - y*sin(theta);
    y_shifted1=x*sin(theta) + y*cos(theta);

    x_shifted2=x*cos(theta1) - y*sin(theta1);
    y_shifted2=x*sin(theta1) + y*cos(theta1);

   mat[yc-y_shifted2][xc+x_shifted2]=255;
   mat[yc+y_shifted1][xc+x_shifted1]=255;

   mat[yc-y_shifted1][xc-x_shifted1]=255;
    mat[yc+y_shifted2][xc-x_shifted2]=255;

    x++;
    if (p1<0)
    {
        p1=p1+(2*ry*ry*x)+(ry*ry);
    }


    else
    {
        y--;
        p1=p1+ (2*ry*ry*x) - (2*rx*rx*y) + (ry*ry) ;
    }


}

// region 2


p2= (float)((ry*ry) * (x+0.5)*(x+0.5)) + (rx*rx) * ((y-1)*(y-1)) - (ry*ry*rx*rx) ;
xf=0;
yf=0;
while(y>=0)
{
      x_shifted1=x*cos(theta) - y*sin(theta);
    y_shifted1=x*sin(theta) + y*cos(theta);

    x_shifted2=x*cos(theta1) - y*sin(theta1);
    y_shifted2=x*sin(theta1) + y*cos(theta1);


      mat[yc-y_shifted2][xc+x_shifted2]=255;
    mat[yc+y_shifted1][xc+x_shifted1]=255;

    mat[yc-y_shifted1][xc-x_shifted1]=255;
    mat[yc+y_shifted2][xc-x_shifted2]=255;




    y--;
    if (p2<0)
    {
        x++;
        p2=p2 + 2*ry*ry*x - 2*rx*rx*y + rx*rx ;
    }

    else
    {
        p2=p2 -2*rx*rx*y + rx*rx ;
    }
}



}

int  main( )
{

    int xc=250,yc=250,rx=100,ry=50;
    float theta;

  /*
    cout<<"enter xc\n";
    cin>>xc;
       cout<<"enter yc\n";
    cin>>yc;
        cout<<"enter rx\n";
    cin>>rx;
        cout<<"enter ry\n";
    cin>>ry;
    */
    printf("enter theta in degrees \n");
    scanf("%f",&theta);

    theta=-theta * (3.14159/180);



    ellipse(xc,yc,rx,ry,theta);

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

    return 0;
}