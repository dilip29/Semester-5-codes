#include<iostream>
#include "Tic_tac_class.cpp"
using namespace std;

int main()
{
int i,j,count=0,option;
Tic_tac_toe game;

   cout<<"\nRemember these instructions , to make a move to any given position enter the position value as shown in figure given below\n \n";
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        cout<<count++;
        if(j<2)
        cout<<"   |   ";

    }
    cout<<endl;
    if(i<2)
    cout<<"____| ____  | ____"<<endl;

}
cout<<endl;

cout<<"Choose the between player 1 or player 2 to start first"<<endl;
cin>>option;
//game.display();
game.play(option);





return 0;
}




