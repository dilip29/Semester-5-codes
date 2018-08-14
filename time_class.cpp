#include<iostream>
using namespace std;

class Time
{


private:

int seconds,hrs,minutes;



public:

Time()
{
seconds=0;
cout<<"default constructor\n";

}

Time(int sec)
{
seconds=sec;
cout<<"parameterized constructor \n ";
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
