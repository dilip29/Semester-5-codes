#include<iostream>
#include "time_class.cpp"
using namespace std;

int main()
{
int c,sec,n;
cout<<"enter the seconds"<<"\n";
cin>>sec;
Time t(sec),t1;

cout<<"enter no. of ticks\n";
cin>>n;
	
cout<<"the time in universal is : "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"\n";

if (t.gethrs()/12>0)
	cout<<"the time in standard is : "<<t.gethrs()%12<<":"<<t.getminutes()<<":"<<t.getseconds()<<"P.M."<<"\n";
else 
cout<<"the time in standard is : "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"A.M."<<"\n";


cout<<"\n updated time after calling tick function "<<n<<" times \n";
while(n>0)
{
t.tick();
n--;
}
cout<<" the time in universal is : "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"\n";

if (t.gethrs()/12>0)
	cout<<"the time in standard is : "<<t.gethrs()%12<<":"<<t.getminutes()<<":"<<t.getseconds()<<"P.M."<<"\n";
else 
cout<<"the time in standard is : "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"A.M."<<"\n";

return 0;



}
