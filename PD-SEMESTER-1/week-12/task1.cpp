#include<iostream>
#include<windows.h>

using namespace std;

void PrintMaze(char Maze[9][34]);
void movePlayerRight(char Maze[9][34]);
void movePlayerLeft(char Maze[9][34]);
void Fire(char Maze[9][34]);
void moveEnemyRight(char Maz[9][34]);
void moveEnemyLeft(char Maze[9][34]);
bool DetectWall(char Maze[9][34]);
char changeDirection(char Maze[9][34]);
bool Winner(char Maze[9][34]);


main()
{
char Maze[9][34]={
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
    "%                               %",
    "%            E                  %",
    "%                               %",
    "%                               %",
    "%            i                  %",
    "%            P                  %",
    "%                               %",
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
};
system("cls");
PrintMaze(Maze);
while(true)
{
    char Direction=changeDirection(Maze);
    system("cls");
     PrintMaze(Maze);
     if(Direction=='l')
     {
        moveEnemyLeft(Maze);
        system("cls");
         PrintMaze(Maze);
     }
     if(Direction=='r')
     {
        moveEnemyRight(Maze);
        system("cls");
         PrintMaze(Maze);
     }

     if(GetAsyncKeyState(VK_LEFT))
     {
         movePlayerLeft(Maze);
         system("cls");
         PrintMaze(Maze);
     }
     else if(GetAsyncKeyState(VK_RIGHT))
     {
         movePlayerRight(Maze);
         system("cls");
         PrintMaze(Maze);
     }
     else if(Winner(Maze))
     {
        cout<<"You Win!!!"<<endl;
        break;
     }
     else if(GetAsyncKeyState(VK_SPACE))
     {
         Fire(Maze);
         system("cls");
         PrintMaze(Maze);
         bool var=true;
         while(var)
         {
            if(DetectWall(Maze))
            {
                Fire(Maze);
               system("cls");
              PrintMaze(Maze);
            }
            else if(var=false)
            {
                system("cls");
              PrintMaze(Maze);
            }
         }
     }
     
}

}

void PrintMaze(char Maze[9][34])
{   
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            cout<<Maze[i][j];       
        }
        cout<<endl;
    }
}

void movePlayerLeft(char Maze[9][34])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i][j]=='P')
            {
                Maze[i][j]=' ';
                if(j>1)
                {
                    Maze[i][j-1]='p';
                }
                else if(j<=1)
                {
                    Maze[i][j]='P';
                }
                break;
            }
        }
    }
}


void movePlayerRight(char Maze[9][34])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i][j]=='P')
            {
                Maze[i][j]=' ';
                if(j<34)
                {
                    Maze[i][j+1]='P';
                }
                else if(j>=34)
                {
                    Maze[i][j]='P';
                }
                break;
            }
        }
    }
}

void Fire(char Maze[9][34])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i][j]=='i')
            {   
                Maze[i][j]=' ';
                Maze[i-1][j]='i';
                break;
            }
        }
    }
}

void moveEnemyLeft(char Maze[9][34])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i][j]=='E'&&Maze[i][j-1]==' ')
            {
                Maze[i][j]=' ';
                Maze[i][j-1]='E';
                break;
            }
        }
    }
}

void moveEnemyRight(char Maze[9][34])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i][j]=='E'&&Maze[i][j+1]==' ')
            {
                Maze[i][j]=' ';
                Maze[i][j+1]='E';
                break;
            }
        }
    }
}

bool DetectWall(char Maze[9][34])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i-1][j]=='%'||Maze[i][j+1]=='%'||Maze[i][j-1]=='%')
            {
                Maze[i][j]=' ';
                return false;
            }
        }
    }
}

char changeDirection(char Maze[9][34])
{   char direction;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<34;j++)
        {
            if(Maze[i][j+1]=='E')
            {
                if(Maze[i][j+1]=='%')
                {
                    direction='l';
                }
                else if(Maze[i][j-1]=='%')
                {
                    direction='r';
                }
            }

        }
    }
}




bool Winner(char Maze[9][34])
{
    bool var = true;
    for (int i = 0; i<9;i++)
    {
        for (int j = 0; j<34; j++)
        {
            if (Maze[i][j] == 'E')
            {
                var = false;
            }
        }
    }
    return var;
}

