#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x,int y);
 void player();
 void enemy();
void boundary();
void moveplayerright();
void moveplayerleft();
void eraseplayer();
void moveenemy();
void eraseenemy();
void moveplayerup();
void moveplayerdown();
void eraseplayer();
char getCharAtxy(short int x,short int y);
string FindPlayer(char array[45][128]);

int rowSize=40;
int colSize=128;
int eX = 20;
int eY = 20;
int pX = 30;
int pY = 3;
int score = 0;


main()
{
char array[45][128]={
      "------------------------------------------------------------------------------------------------------------------------",
      "|                                                                                                                      |",
      "|                                                                                                                      |",                                                                                                                               
      "|                                                                                                                      |",
      "|                                                                                                                      |",
      "|                                                                                                                      |",
      "|                                                                                                                      |",
      "|                                                                                                                      |",
      "|                                                                                                                      |",
      "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "|                                                                                                                      |",
     "------------------------------------------------------------------------------------------------------------------------"
     }

     FindPlayer(array);

}

string FindPlayer(char array[][])
{
    for(int i=0;i<rowSize;i++)
    {
        for(int j=0;j<colSize;j++)
        {
            if(array[i][j]=='p')
            {
                player();
            }
            else if(array[i][j]=='e')
            {
                 enemy();
            }
                cout<<array[i][j];
        }
    }  
}



void player()

{ 
    gotoxy(pX,pY);
    cout <<"  ___  "<<endl;
    gotoxy(pX,pY+1);
    cout <<"( ' _ ' )"<<endl;
    gotoxy(pX,pY+2); 
    cout <<"  =====  "<<endl;  
    gotoxy(pX,pY+3);        
    cout <<" /|   |\\"<<endl;
    gotoxy(pX,pY+4); 
    cout <<"  |   |  "<<endl;
    gotoxy(pX,pY+5);
    cout <<"  '---'  "<<endl;
    gotoxy(pX,pY+6);
    cout <<"   | |   "<<endl;

}

void enemy()
{ 
    gotoxy(eX,eY);
    cout <<"   ,,^^,,"<<endl;
    gotoxy(eX,eY+1);
    cout <<"   |    |"<<endl;
    gotoxy(eX,eY+2);
    cout <<"  ( *  * )"<<endl;
    gotoxy(eX,eY+3);
    cout <<"  | ++++ |"<<endl;
    gotoxy(eX,eY+4);
    cout <<" /--|--|--\\  "<<endl;
    gotoxy(eX,eY+5);
    cout <<" @ \\    / @"<<endl;
    gotoxy(eX,eY+6);
    cout <<"    ^^^^ "<<endl;
    gotoxy(eX,eY+7);
    cout <<"    !  !  "<<endl;

}


void eraseenemy()
{
    gotoxy(eX,eY);
    cout <<"           "<<endl;
    gotoxy(eX,eY+1);
    cout <<"           "<<endl;
    gotoxy(eX,eY+2);
    cout<<"             "<<endl;
    gotoxy(eX,eY+3);
    cout <<"            "<<endl;
    gotoxy(eX,eY+4);
    cout <<"              "<<endl;
    gotoxy(eX,eY+5);    
    cout <<"           "<<endl;
    gotoxy(eX,eY+6);
    cout <<"          "<<endl;
    gotoxy(eX,eY+7);
    cout <<"            "<<endl;
}


void eraseplayer()
{
    gotoxy(pX,pY);
    cout <<"         "<<endl;
    gotoxy(pX,pY+1);                   
    cout <<"         "<<endl;
    gotoxy(pX,pY+2);
    cout <<"         "<<endl;
    gotoxy(pX,pY+3);
    cout <<"         "<<endl;
    gotoxy(pX,pY+4);
    cout <<"         "<<endl;
    gotoxy(pX,pY+5);
    cout <<"         "<<endl; 
    gotoxy(pX,pY+6);
    cout <<"         "<<endl;
}  


void moveplayerleft(){

    if(getCharAtxy(pX-1, pY+1)=='$'||getCharAtxy(pX-1, pY+2)=='$'||getCharAtxy(pX-1, pY+3)=='$'||getCharAtxy(pX-1, pY+4)=='$'||getCharAtxy(pX-1, pY+5)=='$'||getCharAtxy(pX-1, pY+6)=='$')
    {
        score += 1;
        eraseplayer();
        pX = pX - 1;
        player();
    }
    
    if(getCharAtxy(pX-1, pY+1)==' '&&getCharAtxy(pX-1, pY+2)==' '&&getCharAtxy(pX-1, pY+3)==' '&&getCharAtxy(pX-1, pY+4)==' '&&getCharAtxy(pX-1, pY+5)==' '&&getCharAtxy(pX-1, pY+6)==' ')
    {
        eraseplayer();
        pX = pX - 1;
        player();
    }
     
}

void moveplayerright()
{
    if(getCharAtxy(pX+10, pY+1)=='$'||getCharAtxy(pX+10, pY+2)=='$'||getCharAtxy(pX+10, pY+3)=='$'||getCharAtxy(pX+10, pY+4)=='$'||getCharAtxy(pX+10, pY+5)=='$'||getCharAtxy(pX+10, pY+6)=='$')
    {
        score += 1;
        eraseplayer();
        pX = pX + 1;
        player();
    }
    
    if(getCharAtxy(pX+10, pY+1)==' '&&getCharAtxy(pX+10, pY+2)==' '&&getCharAtxy(pX+10, pY+3)==' '&&getCharAtxy(pX+10, pY+4)==' '&&getCharAtxy(pX+10, pY+5)==' '&&getCharAtxy(pX+10, pY+6)==' ')
    {
        eraseplayer();
        pX = pX + 1;
        player();
    }
    
}

void moveplayerup()
{  
    if(getCharAtxy(pX + 1,pY-1) == '$'||getCharAtxy(pX + 2,pY-1) == '$'||getCharAtxy(pX + 3,pY-1) == '$'||getCharAtxy(pX + 4,pY-1) == '$'||getCharAtxy(pX + 5,pY-1) == '$'||getCharAtxy(pX + 6,pY-1) == '$'||getCharAtxy(pX +7,pY-1) == '$')
    {
        score += 1;
        eraseplayer();
        pY = pY - 1;
        player();
    }

    if(getCharAtxy(pX + 1,pY-1) == ' '&&getCharAtxy(pX + 2,pY-1) == ' '&&getCharAtxy(pX + 3,pY-1) == ' '&&getCharAtxy(pX + 4,pY-1) == ' '&&getCharAtxy(pX + 5,pY-1) == ' '&&getCharAtxy(pX + 6,pY-1) == ' '&&getCharAtxy(pX +7,pY-1) == ' ')
    {
        eraseplayer();
        pY = pY - 1;
        player();
    }
}

void moveplayerdown(){
  if(getCharAtxy(pX + 2,pY+7) == '$'||getCharAtxy(pX + 3,pY+7) == '$'||getCharAtxy(pX + 4,pY+7) == '$'||getCharAtxy(pX + 5,pY+7) == '$'||getCharAtxy(pX + 6,pY+7) == '$')
  {
    score += 1;
    eraseplayer();
    pY = pY + 1;
    player();
   }

  if(getCharAtxy(pX + 2,pY+7) == ' '&&getCharAtxy(pX + 3,pY+7) == ' '&&getCharAtxy(pX + 4,pY+7) == ' '&&getCharAtxy(pX + 5,pY+7) == ' '&&getCharAtxy(pX + 6,pY+7) == ' ')
  {
    eraseplayer();
    pY = pY + 1;  
    player();
   }
}

bool e1= false;
void moveenemy(){ 
/// change
    eraseenemy(); 
    if (!e1)
    {
        eX = eX + 1;
        if (eX == 90)
            e1 = true;
    }
    if(e1)
    {
        eX = eX - 1 ;
        if (eX == 20)
            e1 = false;
    }        
    
    enemy();

}
  
void gotoxy(int x,int y)
{
COORD coordinates;
coordinates.X=x;
coordinates.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy ={0,0};
    SMALL_RECT rect = {x,y,x,y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return
    ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE) , &ci, coordBufSize,xy ,&rect) ?
    ci.Char .AsciiChar : ' ' ;
}  

// void DetectPlayer(char array[40][128])
// {
//     for(int i=0;i<40;i++)
//     {
//         for(int j=0;j<128;j++)
//         {
//             if(array[i][j]=='p')
//             {
//                 player();
//             }
//             else if(array[i][j]=='e')
//             {
//                 enemy();
//             }
           
//         }
//     }

// }