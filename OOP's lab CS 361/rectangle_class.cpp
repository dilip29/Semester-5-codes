#include<iostream>
#include<cmath>
using namespace std;

class Rectangle{
private:
int x1,y1,x2,y2,x3,y3,x4,y4;
double d1,d2,d3,m;

public:

    void set (void ){
        if (x1>=0 && y1>=0 && x2>=0  && y2>=0 && x3>=0  && y3>=0  && x3>=0  && y4>=0 ){
            if (x1<=20 && y1<=20 && x2<=20  && y2<=20 && x3<=20  && y3<=20  && x3<=20  && y4<=20   ){
                cout<<"Coordinates value <=20 & in 1st Quadrant! \n";
            }
            else {
                cout<<"Value of Coordinates greater than 20 not allowed ! \n ";
                exit(1);
            }
        }
        else
        {
            cout<<"Coordinates not in 1st Quadrant\n";
            exit(1);
        }
    }




Rectangle()
{

x1=x2=x3=x4=y1=y2=y3=y4=0;

}

Rectangle(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd)
{

x1=xa;
y1=ya;

x2=xb;
y2=yb;

x3=xc;
y3=yc;

x4=xd;
y4=yd;

set();
}

double max(double d1,double d2,double d3)
{
if(d1>d2 && d1>d3)
    return d1;
else if(d2>d1 && d2>d3)
    return d2;
else 
return d3;

}



void operation(double l,double b)
    {
        cout<<"the length of Rectangle is :"<<l<<"\n";
        cout<<"the breath of Rectangle is :"<<b<<"\n";
        cout << "The area is :" <<l*b << endl;
        cout << "The perimeter is :" << 2*(l+b)<<endl;

    }


void calc() {

    if (m == d1) {
        if (d2 > d3) {
            operation(d2,d3);
            cout << "It is not  a Square \n";
        }
        if (d2 == d3) {
            operation(d2,d3);
            cout << "It is also a Square \n";
        } else {
            operation(d3,d2);
            cout << "It is not  a Square \n";
        }
    } else if (m == d2) {

        if (d1 > d3) {
            operation(d1,d3);
            cout << "It is not  a Square \n";
        }
        if (d1 == d3) {
            operation(d1,d3);
            cout << "It is also  a Square \n";
        } else {
            operation(d3,d1);
            cout << "It is not  a Square \n";
        }
    } else {

        if (d1 > d2) {
            operation(d1,d2);
            cout << "It is not  a Square \n";
        }
        if (d1 == d2) {
            operation(d1,d2);
            cout << "It is also a Square \n";
        } else {
            operation(d2,d1);
            cout << "It is not  a Square \n";
        }
    }
}


void verify()
{
    double d;

    d1=sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    d2=sqrt(pow((x1-x3),2) + pow((y1-y3),2));
    d3=sqrt(pow((x1-x4),2) + pow((y1-y4),2));

    m=max(d1,d2,d3);


    if(m==d1)
    {
        d=sqrt(pow((x3-x4),2) + pow((y3-y4),2) ) ;
        if ( m==d) {
            cout << "It is a rectangle\n";
            calc();
        }else
        cout<<"Not a rectangle\n";
    }

    else if(m==d2)
    {
        d=( sqrt(pow((x2-x4),2) + pow((y2-y4),2)) );
        if ( m==d) {
            cout << "It is a rectangle\n";
            calc();
        }
        else
        cout<<"Not a rectangle\n";
    }
    else
    {
        d=sqrt(pow((x2-x3),2) + pow((y2-y3),2));
        if ( m==d) {
            cout << "It is a rectangle\n";
            calc();
        }
        else
        cout<<"Not a rectangle\n";
    }


}


};
