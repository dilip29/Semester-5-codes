#include<iostream>
#include<string.h>
using namespace std;

class Time
{


private:

int seconds,hrs,minutes;
string str1;






public:

Time()
{
seconds=0;
cout<<"default constructor\n";

}



~Time()
{
cout<<str1+"  destructor is called !!!\n";
}


Time(int sec,string objname)
{
seconds=sec;
str1=objname;
cout<<"  parameterized constructor \n ";
sethrs();
setminutes();
setseconds();
}


void sethrs()
{
hrs=seconds/3600;
hrs=hrs%24;

}



void setminutes()
{
minutes=(seconds%3600)/60;
}


void setseconds()
{
seconds=seconds%60;
}


int gethrs()
{
return hrs;
}



int getminutes()
{
return minutes;
}



int getseconds()
{
return seconds;
}




};
