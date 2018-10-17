#include<iostream>
#include "HugeInteger_class.cpp"
#include<string>
using namespace std;
int main()
{

HugeInteger n1,n2,res;
n1.input();
n2.input();
res.output(n1);
res.output(n2);
res.add(n1,n2);
res.subtract(n1,n2);

if(res.isEqualto(n1,n2))
cout<<"no.s are equal"<<endl;

if(res.isgreater(n1,n2))
cout<<"n1 is greater than n2"<<endl;

if (res.isgreaterthanEqualto(n1,n2))
cout<<"n1 is greater than equal to n2"<<endl;

if (res.isLessthan(n1,n2))
cout<<"n1 is less than n2"<<endl;

if (res.islessthanEqualto(n1,n2))
cout<<"n1 is less than equal to n2"<<endl;

if (res.isNotEqualto(n1,n2))
cout<<"n1 is not equal to n2"<<endl;

return 0;

}