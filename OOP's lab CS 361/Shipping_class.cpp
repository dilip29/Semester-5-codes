#include<iostream>
#include<string>
using namespace std;

class Package{

        private:
        double weight,cost_per_kg;
        string s_name,s_addrss,s_city,s_state,s_zip,r_name,r_addrss,r_city,r_state,r_zip;

        public:

        Package()
        {

            cout<<"\nenter details for the item"<<endl;
            cout<<"enter name,addrss,city,state,zip for sender"<<endl;
            cin>>s_name>>s_addrss>>s_city>>s_state>>s_zip;
            cout<<"enter name,addrss,city,state,zip for receipeint"<<endl;
            cin>>r_name>>r_addrss>>r_city>>r_state>>r_zip;
       
            cout<<"enter the weight in kg"<<endl;
            cin>>weight;
            cout<<"enter the cost per kg"<<endl;
            cin>>cost_per_kg;  

            if(weight*cost_per_kg<0.0)
            {
            cout<<"Invalid weights and cost per kg !!!";
            exit(1);
            }
        }

        double CalculateCost()
        {
            return weight*cost_per_kg;
        }

};


class TwodayPackage: public Package{
    private:
    double shipping_charges;
public:

TwodayPackage()
{
    cout<<"enter shipping charges "<<endl;
    cin>>shipping_charges;

}

double CalculateCost()
{

    return Package::CalculateCost()+shipping_charges;
}

};




class OvernightPackage:public Package{
  private:
  double additional_charges;

    public:

    OvernightPackage()
    {
     cout<<"enter the additional charges per kg"<<endl;
     cin>>additional_charges;
    }


    double CalculateCost()
    {
        return Package::CalculateCost()+additional_charges;
    
    }
    
};





