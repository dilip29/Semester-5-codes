#include<iostream>
using namespace std;

class Account{
private:
double balance;

public:

Account()
{
    double accnt_bal;
cout<<"Enter the initial amount to be added"<<endl;
cin>>accnt_bal;
balance=accnt_bal;

}

bool credit(double amt)
{
  
    if(amt>0.0)
    {
    balance=balance+amt;
    return true;
    }
  else 
  return false;
}


bool debit(double amt)
{
    if(balance-amt < 0.0)
    {
    cout<<"debit amount exceeded"<<endl;
    return false;
    }

    else 
    {
    balance=balance-amt;
    return true;
    }


}

double getBalance()
{
    return balance;
}


};




class SavingsAccount : public Account{

private:
double interest_rate;

public:
SavingsAccount()
{
    cout<<"Enter the interest rate in percentage"<<endl;
    cin>>interest_rate;
}

void CalculateInterest()
{
    double interest;
    interest=getBalance()*interest_rate/100;

 if (Account::credit(interest) )
 cout<<"Interest of amt "<<interest<< " added successfully"<<endl;

}


};




class CheckingAccount : public Account {
private:
double fee_charged;

public:
CheckingAccount()
{
    cout<<"Enter fee charged"<<endl;
    cin>>fee_charged;
}

bool debit(double amt)
{
    if (Account::debit(amt))
    {
       cout<<"after debit"<< getBalance()<<endl;
    if(Account::debit(fee_charged))
        return true;
    else 
    return false;
    }
}

bool credit(double amt)
{
    if (Account::credit(amt))
    {
    if ( Account::debit(fee_charged) )
    return true;
    else 
    return false;
    }
}


};


