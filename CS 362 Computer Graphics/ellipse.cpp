#include <iostream>
#include <cmath>
//#define PI 3.141

using namespace std;
int l=200,b=200;
int mat[200][200]={0};

void ellipse(int xc,int yc,int rx,int ry , double theta)
{
   // printf("reached");
float p1,p2;
int x,y,xf,yf;
x=0;
y=ry;
xf=0;
yf=0;
int x_shifted,y_shifted,m;

//region 1 
p1=(float)((rx*rx)/4) + (ry*ry) -(rx*rx*ry);

m=0;
while(m<l)
{
mat[104][m ]=255;
mat[m][104]=255;
m=m+10;
}


while((x*ry*ry) <= (y*rx*rx))
{   
    x_shifted=x*cos(theta) - y*sin(theta);

   // cout<<y_shifted<<"  ";
   // cout<<"ffhifr";
    y_shifted= x*sin(theta) + y*cos(theta);

    
    cout<<x_shifted<<" ,";
    cout<<y_shifted<<"  \n";
   // cout<<"ffhifr";
   //cout<<xc-x<<" ";
   // 1. mat[yc-y_shifted][x_shifted + xc]=255;
    //mat[yc-y_shifted][x_shifted - xc]=255;
    //mat[yc+y_shifted][x_shifted + xc]=255;
    //mat[yc+y_shifted][x_shifted - xc]=255;
  // mat[yc+y][xc+x]=255;


     mat[yc-y_shifted][xc + x_shifted]=255;
    mat[yc+y_shifted][xc-x_shifted]=255;
    mat[yc+y_shifted][xc+x_shifted]=255;
    mat[yc-y_shifted][xc-x_shifted]=255;
   // mat[yc+y_shifted][xc-x_shifted]=255;

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

while(y>=0)
{
     //  x=xf + (x- xf)*cos(theta) - (y-yf)*sin(theta);
   // y=yf + (x- xf)*sin(theta) + (y-yf)*cos(theta);
    x_shifted= x*cos(theta) - y*sin(theta);

    //cout<<x<<"  ";
   // cout<<"ffhifr";
    y_shifted= (x)*sin(theta) + (y*cos(theta));

     cout<<x_shifted<<" ,";
     cout<<y_shifted<<" \n ";
  
       mat[yc-y_shifted][xc - x_shifted]=255;
     mat[yc-y_shifted][xc + x_shifted]=255;
   // mat[yc-y_shifted][x_shifted - xc]=255;
    // mat[yc+y_shifted][x_shifted + xc]=255;
   // mat[yc+y_shifted][x_shifted - xc]=255;

   // mat[yc+y][xc+x]=255;

    mat[yc+y_shifted][xc-x_shifted]=255;
   mat[yc+y_shifted][xc+x_shifted]=255;

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
   // cout<<"dddd";
    int xc=100,yc=100,rx=30,ry=10;
    double theta=60.0;

    /*
    cout<<"enter xc\n";
    cin>>xc;
   
       cout<<"enter yc\n";
    cin>>yc;

        cout<<"enter rx\n";
    cin>>rx;

        cout<<"enter ry\n";
    cin>>ry;

    cout<<"enter theta in degrees \n";
    cin>>theta;
*/
    cout<<"ooo";
   // printf("pppp");
    theta=theta * (3.14/180);

   // printf("oooppps");

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