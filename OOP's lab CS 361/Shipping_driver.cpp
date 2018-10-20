#include<iostream>
#include "Shipping_class.cpp"
using namespace std;
int main()
{
Package item1;
TwodayPackage item2;
OvernightPackage item3;

cout<<"cost for Standard package "<<item1.CalculateCost()<<endl;
cout<<"cost for Twoday package "<<item2.CalculateCost()<<endl;
cout<<"cost for Overnight package "<<item3.CalculateCost()<<endl;

return 0;
}
