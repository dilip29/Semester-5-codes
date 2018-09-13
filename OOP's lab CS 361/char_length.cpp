#include<iostream>
using  namespace std;
int num[8]={0};


void len_char(string str)
{
    int i=0,l=0;
    while(str[i]!='\0') {

        if (str[i] == ' ') {
            num[l]++;
            l = 0;
        } else
            l++;
        i++;

    }
    num[l]++;
}

int main()
{
    int i=0;
    string str;
    cout<<"enter lines     Note :enter '$' in new line to end entering lines"<<endl;
    while(1)
    {
        getline(cin,str);
        if(str[0]=='$')
            break;
        len_char(str);
    }
    for(i=1;i<10;i++)
        cout<<i<<" length words"<<"="<<num[i]<<endl;

    return 0;
}