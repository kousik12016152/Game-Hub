#include <conio.h>
#include<iostream>
#include<windows.h>
using namespace std;
bool gameover;
const int w =40;
const int h=30;
int x,y,fx,fy,score,lv;
int tailx[100],taily[100];
int ntail;
enum direction{stop=0,LEFT,RIGHT,UP,DOWN};
direction dir; 
void setup()
{
    gameover = false;
    dir = stop;
    x=w/2;
    y=h/2;
    fx = rand() %w;
    fy = rand() %h;
    score=0;
}
void draw()
{
    system("cls");
    if(lv==1)
    cout <<"\t    snake game level-1"<<endl;
    if(lv==2)
    cout <<"\t    snake game level-2"<<endl;
    for (int i=0;i<w+2;i++)
        cout<<"#";
    cout<<endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w+2; j++)
        {
            if(j==0 || j==w+1) cout<< "#";
            else if(i==y&&j==x) cout<<"S";
            else if(i==fy&&j==fx) cout<<"o";
            else 
            {
                bool print =false;
                for (int k = 0; k < ntail; k++)
                {
                    if ((tailx[k] == j)&&(taily[k] == i))
                    {
                        cout<<"s";
                        print = true;
                    }
                }
                if(!print)
                    cout<<" ";
            }
        }
        cout<<endl;    
    }
    for (int i = 0; i < w+2; i++)
        cout<<"#";
    cout<<endl;
    cout<<"score:"<<score;
}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
               dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover =true;
                break;
            
        }
    }
}
void logic1()
{

    int prex =tailx[0];
    int prey =taily[0];
    int pre2x,pre2y;
    tailx[0]=x;
    taily[0]=y;

    for (int i = 1; i < ntail; i++)
    {
        pre2x=tailx[i];
        pre2y=taily[i];
        tailx[i]=prex;
        taily[i]=prey;
        prex =pre2x;
        prey =pre2y;
    }
    
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(lv==2)    
        {if (x>w||x<=0||y>=h||y<0)
            gameover =true;}
    if(lv==1){
    if(x>=w) x=0;else if (x<0) x=w-1;
    if(y>=h) y=0;else if (y<0) y=h-1;}
    for (int i = 0; i < ntail; i++)
        if( tailx[i]==x&&taily[i]==y)
            gameover=true;
    
    if(x==fx && y==fy)
    {
        score+=10;
        fx = rand() %w;
        fy = rand() %h;
        ntail++;
    }
    
}
int main()
{
    cout<<"enter 1 for level 1 and 2 for level 2:"<<endl;
    cin>>lv;

    setup();
    while(!gameover)
    {
        draw();
        input();
        logic1();
        Sleep(5);
    }
}