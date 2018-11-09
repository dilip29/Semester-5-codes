#include<iostream>
using namespace std;


class Date{

private:
int date;
int month;
int year;

public:

int get_date()
{
return date;
}

int get_month()
{
return month;
}

int get_year()
{
return year;
}



void set_date(int dt)
{
 date=dt;
}

void set_month(int mn)
{
 month=mn;
}

void set_year(int yr)
{
 year=yr;
}




};



class Phone_number{

private:
int mobile_no ;
int landline ;

public:

int get_mobile()
{
return mobile_no;
}

int get_landline()
{
return landline;
}



void set_mobile(int mb)
{
 mobile_no=mb;
}


void set_landline(int ld)
{
 landline=ld;
}



};







class Employee{

private:
string name;
Date dt;
Phone_number ph;
public:

string get_name()
{
return name;
}

void set_name(string nm)
{
name=nm;
}



Employee(){

}

friend ostream & operator << (ostream &out,Employee &emp);
friend istream & operator >> (istream &in,Employee &emp);




};


istream & operator >> (istream &in, Employee &emp){
string name;
int dt,mn,yr,phn,ldn;
cout<<"Enter details of Employee \nEnter emply name"<<endl;
in>>name;
emp.set_name(name);

cout<<"enter date"<<endl;
in>>dt;
emp.dt.set_date(dt);

cout<<"enter month"<<endl;
in>>mn;
emp.dt.set_month(mn);

cout<<"enter year"<<endl;
in>>yr;
emp.dt.set_year(yr);


cout<<"enter phone no."<<endl;
in>>phn;
emp.ph.set_mobile(phn);


cout<<"enter landline no."<<endl;
in>>ldn;
emp.ph.set_landline(ldn);

return in;
}


ostream & operator << (ostream &out, Employee &emp){
out<<"\nDetails of Employee: "<<endl;

out<<"Name :"<<emp.get_name()<<endl;


out<<"Date of joining :"<<emp.dt.get_date()<<"/"<<emp.dt.get_month()<<"/"<<emp.dt.get_year()<<endl;


out<<"Mobile no. is :"<<emp.ph.get_mobile()<<endl;


out<<"Landline No. "<<emp.ph.get_landline()<<endl;

return out;
}




int main(){

Employee e1,e2;
cin>>e1;
cin>>e2;
cout<<e1<<e2;
return 0;

}
