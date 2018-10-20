#include<iostream>
using namespace std;

class Tic_tac_toe{

private:
int board[3][3];
int row,col,i,j,chances=1,play_num;
public:

Tic_tac_toe()
{
    //cout<<"inside const."<<endl;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        board[i][j]=0;
   // cout<<"outie const";
    //display();
}


void display()
{
   cout<<"\n \n";
for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        cout<<board[i][j];
        if(j<2)
        cout<<"   |   ";

    }
    cout<<endl;
    if(i<2)
    cout<<"____| ____  | ____"<<endl;

}

cout<<endl;
}


void winner(int player)
{
    if(player==0)
    {
    cout<<"The game is drawn !!!"<<endl;
    exit(1);
    }

    cout<<"Congratulations Player "<<player<<" has won the game !!!!"<<endl;
    exit(1);
}

void check(int player)
{
    int count_row=0,count_col=0,count_dig1=0,count_dig2=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==player)
            count_row++;

            if(board[j][i]==player)
            count_col++;



            if(abs(i-j)==2 || i*j==1)
            if(board[i][j]==player)
            count_dig2++;
        }
                    if(board[i][i]==player)
            count_dig1++;


        if(count_row==3 || count_col==3)
        winner(player);

        count_row=0;
        count_col=0;

    }
    if(count_dig1==3 || count_dig2==3)
    winner(player);

}


void make_move(int p,int player)
{
row=p/3;
col=p%3;

    if(board[row][col]==0)
    {
    board[row][col]=player;
    chances++;
    display();
    check(1);
    check(2);
    }
    else 
    {
    cout<<"Wrong move ....enter a non-empty position !!"<<endl;
    play(player);
    }

}


void play(int player)
{
 

    if(chances>9)
    winner(0);

    cout<<"Move No. : "<<chances<<"\t\t\t";
    play_num=(player%2) +1 ;
    int p;
cout<<"Player  : "<<player<<endl;
cout<<"Enter the position to make your move !!!"<<endl;

cin>>p;
make_move(p,player);
play(play_num);
}




};

