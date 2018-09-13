#include<iostream>
using  namespace std;

int main()
{
    int m=0;
    string str,mon;
    char ch;
    cout<<"enter date in mm/dd/yyyy format :"<<endl;
    cin>>str;
    ch=str[1];
    if(str[0]=='0')
    {
        switch (ch) {
            case '1':
                mon = "Jan";
                break;
            case '2':
                mon = "Feb";
                break;
            case '3':
                mon = "Mar";
                break;
            case '4':
                mon = "Apr";
                break;
            case '5':
                mon = "May";
                break;
            case '6':
                mon = "Jun";
                break;
            case '7':
                mon = "Jul";
                break;
            case '8':
                mon = "Aug";
                break;
            case '9':
                mon = "Sep";
                break;
        }
    }
    else
    {
        switch (ch) {
            case '0':
                mon = "Oct";
                break;
            case '1':
                mon = "Nov";
                break;

            case '2':
                mon = "Dec";
                break;
        }
    }

    cout<<"The date in Month dd, year format is : \n "<<mon<<" ";
    m=3;
    while(m<=9)
    {
        if(m!=5)
            cout<<str[m];
        else
            cout<<", ";
        m++;
    }
    cout<<endl;

    return 0;
}