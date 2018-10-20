#include<iostream>
#include "Account_class.cpp"
using namespace std;

int main()
{
    double db_amt,cr_amt;

    
cout<<"Standard account "<<endl;
Account accnt1;

cout<<"Enter the amount to be debited"<<endl;
cin>>db_amt;
if (accnt1.debit(db_amt) )
    cout<<"Amount debited Successfully and current balance : "<<accnt1.getBalance()<<endl;


cout<<"Enter the amount to be credited"<<endl;
cin>>cr_amt;
if ( accnt1.credit(cr_amt) )
    cout<<"Amount credited successfully and current balance : "<<accnt1.getBalance()<<endl;





cout<<"\n\nSavings account "<<endl;
SavingsAccount accnt2;
cout<<"Enter the amount to be debited"<<endl;
cin>>db_amt;
if (accnt2.debit(db_amt) )
    cout<<"Amount debited Successfully and current balance : "<<accnt2.getBalance()<<endl;


cout<<"Enter the amount to be credited"<<endl;
cin>>cr_amt;
if ( accnt2.credit(cr_amt) )
    cout<<"Amount credited successfully and current balance : "<<accnt2.getBalance()<<endl;

accnt2.CalculateInterest();
cout<<"Current account balance is :"<<accnt2.getBalance()<<endl;




cout<<"\n\nChecking account "<<endl;
CheckingAccount accnt3;
cout<<"Enter the amount to be debited"<<endl;
cin>>db_amt;
if (accnt3.debit(db_amt) )
    cout<<"Amount debited Successfully and current balance : "<<accnt3.getBalance()<<endl;


cout<<"Enter the amount to be credited"<<endl;
cin>>cr_amt;
if ( accnt3.credit(cr_amt) )
    cout<<"Amount credited successfully and current balance : "<<accnt3.getBalance()<<endl;





}