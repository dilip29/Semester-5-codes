#include<iostream>
#include<string>
using  namespace std;
int num[26]={0};

void num_char(string str)
{
int len= str.size(),i=0;
while(i<len) {
    if ((str[i] >= 97 && str[i] <= 122) || str[i] >= 65 && str[i] <= 90)
        num[tolower(str[i]) - 97]++;

    i++;
    }

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
        num_char(str);
    }
	cout<<"Character   Occurences \n";
    for(i=0;i<26;i++)
    cout<<"   "<<char(i+97)<<"      =    "<<num[i]<<endl;
    return 0;
}
