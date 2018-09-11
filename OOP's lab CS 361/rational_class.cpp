#include<iostream>
using namespace std;

class Rational{

private:
 int p;
int q;

//int add,sub,mul,div;
public:

Rational()
{

 p=0;
 q=1;

}

Rational(int a,int b)
{
 p=a;
 q=b;
}

int getnum()
{
return p;
}

int getdeno()
{
return q;
}

int setnum(int a)
{
 p=a;
}

int setdeno(int b)
{
q=b;
}


/*
~Rational()
{
cout<<"destructor is called\n";
}
*/

Rational add(Rational r1,Rational r2)
{
Rational sum;
 sum.setnum( (r1.getnum() * r2.getdeno() )+  (r2.getnum() * r1.getdeno() ) );
 sum.setdeno( (r1.getdeno() * r2.getdeno() ) );

return sum;


}


Rational sub(Rational r1,Rational r2)
{
Rational sum;
 sum.setnum( (r1.getnum() * r2.getdeno() ) - (r2.getnum() * r1.getdeno() ) );
 sum.setdeno( (r1.getdeno() * r2.getdeno() ) );

return sum;


}

Rational mul(Rational r1,Rational r2)
{
Rational sum;
 sum.setnum( r1.getnum() * r2.getnum() );
 sum.setdeno( r1.getdeno() * r2.getdeno()  );

return sum;


}


Rational div(Rational r1,Rational r2)
{
Rational sum;
 sum.setnum( r1.getnum() * r2.getdeno()  );
 sum.setdeno( r1.getdeno() * r2.getnum()  );

return sum;


}




};
