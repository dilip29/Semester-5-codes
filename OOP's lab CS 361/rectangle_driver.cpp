#include<iostream>
#include "rect_class.cpp"
#include<cmath>
using namespace std;




int main()
{

int x1=0,y1=0,x2=5,y2=0,x3=0,y3=10,x4=5,y4=10;
cout<<"Enter x1 & y1"<<endl;
cin>>x1>>y1;
cout<<"Enter x2 & y2"<<endl;
cin>>x2>>y2;
cout<<"Enter x3 & y3"<<endl;
cin>>x3>>y3;
cout<<"Enter x4 & y4"<<endl;
cin>>x4>>y4;

Rectangle r(x1,y1,x2,y2,x3,y3,x4,y4);
r.verify();


return 0;
}
