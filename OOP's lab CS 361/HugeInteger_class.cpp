#include<iostream>
#include<string>
using namespace std;
class HugeInteger{

private:
 int n[40];
int flag,i;

public:

HugeInteger()
{
    for(i=0;i<40;i++)
        n[i]=0;
     
    
}


void input(void)
{
    cout<<"enter any number with no. of digits <= 40 (+ve or -ve ) ";
    string str,str1;
    
    cin>>str;
    if (str[0]=='-')
    {
    flag=1;
    
    int len=str.length()-1,j;
    cout<<len<<"  ";
        if(len<=40)
        {
            len--;
            for(i=39-len,j=1;i<40;i++,j++)
                n[i]=stol(str.substr(j,1));
            
        }
        else 
        {
        cout<<"Error !!!!...number greater than 40 digit entered"<<endl;
        exit(1);
        }


    }
    else 
    {
    
        flag=0;
        int len=str.length(),j;
        if(len<=40)
        {
            len--;
            for(i=39-len,j=0;i<40;i++,j++)
                n[i]=stol(str.substr(j,1));
            
        }
        else 
        {
        cout<<"Error !!!!...number greater than 40 digit entered"<<endl;
        exit(1);
        }
    }
    
}


void output(HugeInteger obj)
{
    if (obj.flag==1)
    cout<<"-";

for(i=0;i<40;i++)
cout<<obj.n[i];
cout<<endl;

}



void add(HugeInteger n1,HugeInteger n2)
{
if (n1.flag*n2.flag==1 || (n1.flag==0 && n2.flag==0))
{
HugeInteger sum;
sum.flag=n1.flag*n2.flag;
int carry=0;
for(i=39;i>=0;i--)
{
    sum.n[i]=((n1.n[i]+n2.n[i])+carry)%10;
    carry=(n1.n[i]+n2.n[i]+carry)/10;
}
if(carry==1)
cout<<"overflow !!!"<<endl;

else{

    cout<<"the sum is :"<<endl;
    /*
    for(i=0;i<10;i++)
    {
        cout<<sum.n[i];
    }
    cout<<endl;

    */
   output(sum);
    }

}

else 
subtract(n1,n2);


}


void subtract(HugeInteger n1,HugeInteger n2)
{
   // if(n1.flag*n2.flag==0 || n1.flag*n2.flag==1)
    HugeInteger sub;
if (isgreater(n1,n2))
{
    sub.flag=0;
    for(i=39;i>=0;i--)
    {
        if(n1.n[i]<n2.n[i])
        {
            n1.n[i-1]--;
            n1.n[i]+=10;
        }
        sub.n[i]=n1.n[i]-n2.n[i];

    }
}
else 
{
  
    sub.flag=1;
        for(i=39;i>=0;i--)
        {
            if(n2.n[i]<n1.n[i])
            {
                n2.n[i-1]=n2.n[i-1]-1;
                n2.n[i]+=10;
            }
            sub.n[i]=n2.n[i]-n1.n[i];

        }
}
cout<<"the subtraction is :"<<endl;
if(sub.flag==1)
cout<<"-";

for(i=0;i<40;i++)
cout<<sub.n[i];

cout<<endl;
}



bool isgreater(HugeInteger n1,HugeInteger n2)
{
    for(i=0;i<40;i++)
    {
        if(n1.n[i]<n2.n[i])
        return false;
        if(n1.n[i]>n2.n[i])
        return true;
    
    }
    return false;
}



bool isEqualto(HugeInteger n1,HugeInteger n2)
{
    for(i=0;i<40;i++)
    {
        if(n1.n[i]!=n2.n[i])
        return false;
 
    
    }
    return true;
}



bool isNotEqualto(HugeInteger n1,HugeInteger n2)
{
if (isEqualto(n1,n2))
return false;
return true;
}


bool isgreaterthanEqualto(HugeInteger n1,HugeInteger n2)
{
if (isEqualto(n1,n2) && isgreater(n1,n2))
return true;
return false;
}

bool islessthanEqualto(HugeInteger n1,HugeInteger n2)
{
if (isEqualto(n1,n2) && isLessthan(n1,n2))
return true;
return false;
}



bool isLessthan(HugeInteger n1,HugeInteger n2)
{
if(isgreater(n1,n2))
return false;
else 
return true;
}



};