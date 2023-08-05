#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int col;
char token='x';
bool tie=false;
string n1="player1";
string n2="player2";
void f1()
{

    cout<<"\t***TIC TAC TOE***\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<space[0][0]<<"  |  "<<space[0][1]<<"  |  "<<space[0][2]<<"  \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<space[1][0]<<"  |  "<<space[1][1]<<"  |  "<<space[1][2]<<"  \n";
    cout<<"\t_____|_____|_____\n";
    cout<<"\t     |     |     \n";
    cout<<"\t  "<<space[2][0]<<"  |  "<<space[2][1]<<"  |  "<<space[2][2]<<"  \n";
    cout<<"\t     |     |     \n";
    

}
void f2()
{
    int digit;
    if (token=='x')
    {
        cout<<n1<<" please enter your key:";
        cin>>digit;
    }
    if (token=='o')
    {
        cout<<n2<<" please enter your key:";
        cin>>digit;
    }
    if (digit==1)
    {
        row=0;
        col=0;
    }
    if (digit==2)
    {
        row=0;
        col=1;
    }
    if (digit==3)
    {
        row=0;
        col=2;
    }
    if (digit==4)
    {
        row=1;
        col=0;
    }
    if (digit==5)
    {
        row=1;
        col=1;
    }
    if (digit==6)
    {
        row=1;
        col=2;
    }
    if (digit==7)
    {
        row=2;
        col=0;
    }
    if (digit==8)
    {
        row=2;
        col=1;
    }
    if (digit==9)
    {
        row=2;
        col=2;
    }
    if(digit<1 || digit>9)
    {
        cout<<"invalid !!!"<<endl;
        f2();
    }
    else{
    if(token=='x' && space[row][col]!='x' && space[row][col]!='o')
    {
    space[row][col]='x';
    token='o';
    }
    else if(token=='o' && space[row][col]!='x' && space[row][col]!='o')
    {
    space[row][col]='o';
    token='x';
    }
    else
    {
        cout<<"there is no empty space"<<endl;
        f2();
    }
    }
}
bool f3(){
    for (int i =0; i< 3; i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        {
            return true;    
        }
    
    }
    if (space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0])
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j]!='x' && space[i][j]!='o')
            {
                return false;
            }
            
        }
    }
    tie=true;
    return false;
    
}
int main()
{
    cout<<"enter the name of first player:"<<endl;
    getline(cin,n1);
    cout<<"enter the name of second player:"<<endl;
    getline(cin,n2);
    cout<<n1<<" is player-1 wil play firsr"<<endl;
    while(!f3())
    {
        f1();
        f2();
        f3();
        system("cls");
    }
    if(token=='x' && tie ==false)
    {
        f1();
        cout<<n2<<" wins!!"<<endl;
    }
    else if(token=='o' && tie ==false)
    {   
        f1();
        cout<<n1<<" wins!!"<<endl;
    }
    else 
    {
        f1();
        cout<<" it's a draw!";
    }
}