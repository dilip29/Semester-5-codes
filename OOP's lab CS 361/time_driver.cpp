#include<iostream>
#include "time_class.cpp"
using namespace std;
int sec;
void function_global(int sec)
{
Time t(sec);
cout<<"the time in universal is = "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"\n";

if (t.gethrs()/12>0)
cout<<"the time in standard is = "<<t.gethrs()%12<<":"<<t.getminutes()<<":"<<t.getseconds()<<"P.M."<<"\n";
else 
cout<<"the time in standard is = "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"A.M."<<"\n";


}


int main()
{
int c;
cout<<"enter the seconds"<<"\n";
cin>>sec;
cout<<"enter choice\n 1.global \n 2.default\n";
cin>>c;
if (c==1)
	function_global(sec);
else
{
	Time t(sec);
	cout<<"the time in universal is = "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"\n";

	if (t.gethrs()/12>0)
	cout<<"the time in standard is = "<<t.gethrs()%12<<":"<<t.getminutes()<<":"<<t.getseconds()<<"P.M."<<"\n";
	else 
	cout<<"the time in standard is = "<<t.gethrs()<<":"<<t.getminutes()<<":"<<t.getseconds()<<"A.M."<<"\n";
}
return 0;



}
