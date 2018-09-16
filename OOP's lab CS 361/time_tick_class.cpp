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


}

Time(int sec)
{
seconds=sec;

}



int gethrs()
{
return (seconds/3600)%24;
}

int getminutes()
{
return (seconds%3600)/60;
}

int getseconds()
{
return seconds%60;
}


void tick(void)
{

seconds=(seconds+1);

}


};
