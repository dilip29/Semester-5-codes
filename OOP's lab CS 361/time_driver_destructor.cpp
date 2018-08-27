#include<iostream>
#include "time_class.cpp"
using namespace std;

int global_sec;

void display(Time *t)
{

cout<<"the time in universal is = "<<(*t).gethrs()<<":"<<(*t).getminutes()<<":"<<(*t).getseconds()<<"\n";

if ((*t).gethrs()/12>0)
cout<<"the time in standard is = "<<(*t).gethrs()%12<<":"<<(*t).getminutes()<<":"<<(*t).getseconds()<<"P.M."<<"\n";
else 
cout<<"the time in standard is = "<<(*t).gethrs()<<":"<<(*t).getminutes()<<":"<<(*t).getseconds()<<"A.M."<<"\n";


}


void disp_static(int sec)
{

static Time t1(sec,"static");


display(&t1);


}



void show_time(int sec)
{
Time t(sec,"function");



display(&t);


}



void global_var(int sec)
{

show_time(sec);
}

int main()
{

	

	int c,sec;
	cout<<"enter the seconds"<<"\n";
	cin>>sec;

	
	cout<<"\nglobal_funct called \n";
	show_time(sec);
	

	
	
	
	
	cout<<"\n\n static object called\n";
	disp_static(sec);




	cout<<" \n \n  variable in main called\n";
	Time t2(sec ,"main");
	
	display(&t2);



	

return 0;



}
