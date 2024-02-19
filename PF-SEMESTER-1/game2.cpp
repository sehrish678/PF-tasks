#include<iostream>
#include<windows.h>
using namespace std;

// score


main(){
    system("cls");
    boundary();
    enemy();
    player();
    gotoxy(130,4);
    cout << "SCORE: ";
    // string enemydirection = "right";
    

    while(true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
           
            moveplayerright();
        }
        if(GetAsyncKeyState(VK_UP))
        {
            moveplayerup();
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            moveplayerdown();
        }
        gotoxy(133,5);
        cout << score;

         moveenemy();
        // enemydirection = changedirection(enemydirection);
        Sleep(10);
    }
}
/// not in use now
// string changedirection(string enemydirection)
// {
//     if(enemydirection == "right" && eX == 25)
//     {
//         enemydirection = "left";
//     }
//     else if(enemydirection == "left" && eX == 20)
//     {
//         enemydirection == "right";
//     }
//     return enemydirection;
// }
    void boundary()
    {
     
}
    




// change







