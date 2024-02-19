#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);
void player();
void enemy();
void boundary();
void moveplayerright();
void moveplayerleft();
void eraseplayer();
void moveenemy();
void eraseenemy();
void moveEnemy2();
void moveplayerup();

void Enemy2();
void moveplayerdown();
void eraseEnemey2();
void moveEnemy3();
void moveEnemyX3();
void Enemy3();
void eraseEnemy3();

void generateBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int i);
void moveBullet();
void moveFireOfEnemy();
void generateBulletOfEnemy();
void printFireOfEnemy(int x, int y); 
void eraseFireOfEnemy(int x, int y); 

void moveFireOfEnemy3();
void makeFireinactive3(int i); 
void eraseFireOfEnemy3(int x, int y) ;
void printFireOfEnemy3(int x, int y); 
void generateBulletOfEnemy3(); 


// void moveEnemy();
void Header();
string setcolor(unsigned short color);

char getCharAtxy(short int x, short int y);
/////////
int eX = 20;
int eY = 20;
int pX = 30;
int pY = 3;
int e2X = 15;
int e2Y = 15;
int e3X = 10;
int e3Y = 10;
int fX = 0;
int fY = 0;
int counter=0;

int bulletX[10000];
int bulletY[10000];
bool bulletActive[10000];
int bulletCount = 0;

int FireX[10000];
int FireY[10000];
bool fireActive[10000];
int fireCount =0 ;

int Fire2X[10000];
int Fire2Y[10000];
int fireActive2[10000];
int fireCount2 = 0;

// score
int score = 0;
int health = 5;
main() {
  system("cls");
  
  boundary();
  enemy();
  player();
  gotoxy(130, 4);
  cout << "SCORE: ";

  gotoxy(130, 7);
  cout << "ENEMY HEALTH: ";

  // string enemydirection = "right";

  while (true) 
  {
    if (GetAsyncKeyState(VK_LEFT)) {
      moveplayerleft();
    }
    if (GetAsyncKeyState(VK_RIGHT)) {

      moveplayerright();
    }
    if (GetAsyncKeyState(VK_UP)) {
      moveplayerup();
    }
    if (GetAsyncKeyState(VK_DOWN)) {
      moveplayerdown();
    }
    if (GetAsyncKeyState(VK_SPACE)) {
      generateBullet();
    }

    moveBullet();
    if (counter == 5)
    {
      generateBulletOfEnemy();
      counter = 0;
    }
    moveFireOfEnemy();
    if(counter==5)
   { 
    generateBulletOfEnemy3(); 
    counter=0;
   }
    moveFireOfEnemy3();
    gotoxy(133, 5);
    cout << score;

    gotoxy(143, 7);
    cout << health;

    

    moveenemy();
    moveEnemy2();
    moveEnemy3();
    moveEnemyX3();
    counter++;

    // enemydirection = changedirection(enemydirection);
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
void boundary() {
  setcolor(14);
  cout << "--------------------------------------------------------------------"
          "----------------------------------------------------"
       << endl;
  cout << "--------------------------------------------------------------------"
          "----------------------------------------------------"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|          $                                                        "
          "                         $                         |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                        $          "
          "                                            $      |"
       << endl;
  cout << "|             $                                                     "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                  $                |"
       << endl;
  cout << "|                            $                                      "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "|                                                                   "
          "                                                   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "----------------------------------------------------"
       << endl;
  cout << "--------------------------------------------------------------------"
          "----------------------------------------------------"
       << endl;
}

void player()

{
  setcolor(2);
  gotoxy(pX, pY);
  cout << "  ___  " << endl;
  gotoxy(pX, pY + 1);
  cout << "( ' _ ' )" << endl;
  gotoxy(pX, pY + 2);
  cout << "  =====  " << endl;
  gotoxy(pX, pY + 3);
  cout << " /|   |\\" << endl;
  gotoxy(pX, pY + 4);
  cout << "  |   |  " << endl;
  gotoxy(pX, pY + 5);
  cout << "  '---'  " << endl;
  gotoxy(pX, pY + 6);
  cout << "   | |   " << endl;
}
void eraseplayer() {
  gotoxy(pX, pY);
  cout << "         " << endl;
  gotoxy(pX, pY + 1);
  cout << "         " << endl;
  gotoxy(pX, pY + 2);
  cout << "         " << endl;
  gotoxy(pX, pY + 3);
  cout << "         " << endl;
  gotoxy(pX, pY + 4);
  cout << "         " << endl;
  gotoxy(pX, pY + 5);
  cout << "         " << endl;
  gotoxy(pX, pY + 6);
  cout << "         " << endl;
}
void enemy() {
  setcolor(4);
  gotoxy(eX, eY);
  cout << "   ,,^^,," << endl;
  gotoxy(eX, eY + 1);
  cout << "   |    |" << endl;
  gotoxy(eX, eY + 2);
  cout << "  ( *  * )" << endl;
  gotoxy(eX, eY + 3);
  cout << "  | ++++ |" << endl;
  gotoxy(eX, eY + 4);
  cout << " /--|--|--\\  " << endl;
  gotoxy(eX, eY + 5);
  cout << " @ \\    / @" << endl;
  gotoxy(eX, eY + 6);
  cout << "    ^^^^ " << endl;
  gotoxy(eX, eY + 7);
  cout << "    !  !  " << endl;
}

void eraseenemy() {
  gotoxy(eX, eY);
  cout << "           " << endl;
  gotoxy(eX, eY + 1);
  cout << "           " << endl;
  gotoxy(eX, eY + 2);
  cout << "             " << endl;
  gotoxy(eX, eY + 3);
  cout << "            " << endl;
  gotoxy(eX, eY + 4);
  cout << "              " << endl;
  gotoxy(eX, eY + 5);
  cout << "           " << endl;
  gotoxy(eX, eY + 6);
  cout << "          " << endl;
  gotoxy(eX, eY + 7);
  cout << "            " << endl;
}

void Enemy2() {
  setcolor(4);
  gotoxy(e2X, e2Y);
  cout << " --------" << endl;
  gotoxy(e2X, e2Y + 1);
  cout << " | X   0 |" << endl;
  gotoxy(e2X, e2Y + 2);
  cout << "  -------" << endl;
  gotoxy(e2X, e2Y + 3);
  cout << "   |   | " << endl;
}

void eraseEnemey2() {
  gotoxy(e2X, e2Y);
  cout << "          " << endl;
  gotoxy(e2X, e2Y + 1);
  cout << "           " << endl;
  gotoxy(e2X, e2Y + 2);
  cout << "          " << endl;
  gotoxy(e2X, e2Y + 3);
  cout << "          " << endl;
}

void moveplayerleft() {

  if (getCharAtxy(pX - 1, pY + 1) == '$' ||
      getCharAtxy(pX - 1, pY + 2) == '$' ||
      getCharAtxy(pX - 1, pY + 3) == '$' ||
      getCharAtxy(pX - 1, pY + 4) == '$' ||
      getCharAtxy(pX - 1, pY + 5) == '$' ||
      getCharAtxy(pX - 1, pY + 6) == '$') {
    score += 1;
    eraseplayer();
    pX = pX - 1;
    player();

   
  }

  if (getCharAtxy(pX - 1, pY + 1) == ' ' &&
      getCharAtxy(pX - 1, pY + 2) == ' ' &&
      getCharAtxy(pX - 1, pY + 3) == ' ' &&
      getCharAtxy(pX - 1, pY + 4) == ' ' &&
      getCharAtxy(pX - 1, pY + 5) == ' ' &&
      getCharAtxy(pX - 1, pY + 6) == ' ') {
    eraseplayer();
    pX = pX - 1;
    player();
  }
}
void moveplayerright() {
  if (getCharAtxy(pX + 10, pY + 1) == '$' ||
      getCharAtxy(pX + 10, pY + 2) == '$' ||
      getCharAtxy(pX + 10, pY + 3) == '$' ||
      getCharAtxy(pX + 10, pY + 4) == '$' ||
      getCharAtxy(pX + 10, pY + 5) == '$' ||
      getCharAtxy(pX + 10, pY + 6) == '$') {
    score += 1;
    eraseplayer();
    pX = pX + 1;
    player();

    
  }

  if (getCharAtxy(pX + 10, pY + 1) == ' ' &&
      getCharAtxy(pX + 10, pY + 2) == ' ' &&
      getCharAtxy(pX + 10, pY + 3) == ' ' &&
      getCharAtxy(pX + 10, pY + 4) == ' ' &&
      getCharAtxy(pX + 10, pY + 5) == ' ' &&
      getCharAtxy(pX + 10, pY + 6) == ' ') {
    eraseplayer();
    pX = pX + 1;
    player();
  }
}
void moveplayerup() {
  if (getCharAtxy(pX + 1, pY - 1) == '$' ||
      getCharAtxy(pX + 2, pY - 1) == '$' ||
      getCharAtxy(pX + 3, pY - 1) == '$' ||
      getCharAtxy(pX + 4, pY - 1) == '$' ||
      getCharAtxy(pX + 5, pY - 1) == '$' ||
      getCharAtxy(pX + 6, pY - 1) == '$' ||
      getCharAtxy(pX + 7, pY - 1) == '$') {
    score += 1;
    eraseplayer();
    pY = pY - 1;
    player();

  }
  for (int i = 0; i < 7; i++) {
    if (getCharAtxy(pX + i, pY - 1) == ' ' ||
        getCharAtxy(pX + i, pY - 1) == '^') {
      eraseplayer();
      pY = pY - 1;
      player();
    }
  }

  // if(getCharAtxy(pX + 1,pY-1) == ' ' &&getCharAtxy(pX + 2,pY-1) == '
  // '&&getCharAtxy(pX + 3,pY-1) == ' '&&getCharAtxy(pX + 4,pY-1) == '
  // '&&getCharAtxy(pX + 5,pY-1) == ' '&&getCharAtxy(pX + 6,pY-1) == '
  // '&&getCharAtxy(pX +7,pY-1) == ' ')
  // {
  //     eraseplayer();
  //     pY = pY -1;
  //     player();

  // }
}
void moveplayerdown() {
  if (getCharAtxy(pX + 2, pY + 7) == '$' ||
      getCharAtxy(pX + 3, pY + 7) == '$' ||
      getCharAtxy(pX + 4, pY + 7) == '$' ||
      getCharAtxy(pX + 5, pY + 7) == '$' ||
      getCharAtxy(pX + 6, pY + 7) == '$') {
    score += 1;
    eraseplayer();
    pY = pY + 1;
    player();

   
  }
  for (int i = 0; i < 7; i++) {
    if (getCharAtxy(pX + i, pY + 7) == ' ' ||
        getCharAtxy(pX + i, pY + 7) == '^') {
      eraseplayer();
      pY = pY + 1;
      player();
    }
  }

  //   if (getCharAtxy(pX + 2, pY + 7) == ' ' &&
  //       getCharAtxy(pX + 3, pY + 7) == ' ' &&
  //       getCharAtxy(pX + 4, pY + 7) == ' ' &&
  //       getCharAtxy(pX + 5, pY + 7) == ' ' &&
  //       getCharAtxy(pX + 6, pY + 7) == ' ') {
  //     eraseplayer();
  //     pY = pY + 1;
  //     player();
  //   }
}

bool e1 = false;
void moveenemy() {

  eraseenemy();
  if (!e1) {
    eX = eX + 1;
    if (eX == 90)
      e1 = true;
  }

  if (e1) {
    eX = eX - 1;
    if (eX == 20)
      e1 = false;
  }

  enemy();
}

void gotoxy(int x, int y) {
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y) {
  CHAR_INFO ci;
  COORD xy = {0, 0};
  SMALL_RECT rect = {x, y, x, y};
  COORD coordBufSize;
  coordBufSize.X = 1;
  coordBufSize.Y = 1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize,
                           xy, &rect)
             ? ci.Char.AsciiChar
             : ' ';
}

// void WinHeader() {
//   setcolor(13);
//   cout << R"(
                                                                                                                          
// \\    / /                         ||   / |  / /                        // 
//  \\  / /      ___                 ||  /  | / /     ( )       __       //  
//   \\/ /     //   ) )   //   / /   || / /||/ /     / /     //   ) )   //   
//    / /     //   / /   //   / /    ||/ / |  /     / /     //   / /         
//   / /     ((___/ /   ((___( (     |  /  | /     / /     //   / /   //     

                                                                                                            

//     )" << endl;
// }
void Header() {
  setcolor(13);
  cout << R"(
                                                                                            
 dP""b8  dP"Yb  88""Yb 88     88 888888 8888P 
dP   `" dP   Yb 88__dP 88     88   88     dP  
Yb  "88 Yb   dP 88""Yb 88  .o 88   88    dP   
 YboodP  YbodP  88oodP 88ood8 88   88   d8888 


                                                                                                            

    )" << endl;
}

string setcolor(unsigned short color) {
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hcon, color);
  return "";
}
////for 2nd enemy to move in maze
bool e3 = false;
void moveEnemy2() {

  eraseEnemey2();
  if (!e3) {
    e2Y = e2Y + 1;
    if (e2Y == 35)
      e3 = true;
  }

  if (e3) {
    e2Y = e2Y - 1;
    if (e2Y == 20)
      e3 = false;
  }

  Enemy2();
}

// void printFire()
// {

// }

void Enemy3() {
  gotoxy(e2X, e2Y);
  cout << " --------" << endl;
  gotoxy(e2X, e2Y + 1);
  cout << " | X   0 |" << endl;
  gotoxy(e2X, e2Y + 2);
  cout << "  -------" << endl;
  gotoxy(e2X, e2Y + 3);
  cout << "   |   | " << endl;
}

void eraseEnemy3() {
  gotoxy(e2X, e2Y);
  cout << "          " << endl;
  gotoxy(e2X, e2Y + 1);
  cout << "           " << endl;
  gotoxy(e2X, e2Y + 2);
  cout << "          " << endl;
  gotoxy(e2X, e2Y + 3);
  cout << "          " << endl;
}

bool e4 = false;
void moveEnemy3() {
  eraseEnemy3();
  if (!e4) {
    e3Y = e3Y + 1;
    if (e3Y == 10)
      e4 = true;
  }
  if (e4) {
    e3Y = e3Y - 1;
    if (e3Y == 10)
      e4 = false;
  }
  Enemy3();
}

void moveEnemyX3() {
  eraseEnemy3();
  if (!e4) {
    e3X = e3X + 1;
    if (e4 == 20)
      e4 = true;
  }
  if (e3) {
    e3X = e3X - 1;
    if (e3X == 20)
      e4 = false;
  }
  Enemy3();
}

void generateBullet() {
  if(getCharAtxy(pX+3, pY-1) == ' '){
    bulletX[bulletCount] = pX + 3;
    bulletY[bulletCount] = pY - 1;
    bulletActive[bulletCount] = true;

    gotoxy(bulletX[bulletCount], bulletY[bulletCount]);
    cout << "^" << endl;
    bulletCount++;
  }
}


void printBullet(int x, int y) 
{
  gotoxy(x, y);
  cout << "^" << endl;
}

void eraseBullet(int x, int y) 
{
  gotoxy(x, y);
  cout << " " << endl;
}


void moveBullet() {
  for (int i = 0; i < bulletCount; i++) {
    if (bulletActive[i]) {
      if (getCharAtxy(bulletX[i], bulletY[i] - 1) != ' ') {
        eraseBullet(bulletX[i], bulletY[i]);
        makeBulletInactive(i);
      }
        else {
          eraseBullet(bulletX[i], bulletY[i]);
          bulletY[i] -= 1;
          printBullet(bulletX[i], bulletY[i]);
        }
      }
    }
  }



void makeBulletInactive(int i)
  { 
  bulletActive[i] = false; 
  }

// void printFire() {
//   //   if (getCharAtxy(pX + 3, pY - 1) != '-')
//   //   {

//   fX = pX + 3;
//   fY = pY - 1;
//   gotoxy(fX, fY);
//   cout << "^";

//   //   }
// }

// void eraseFire() {
//   gotoxy(fX, fY);
//   cout << " ";
// }

// void displayFire() {
//   gotoxy(fX, fY);
//   cout << "^";
// }

// void moveFire() {

//   if (getCharAtxy(fX, fY - 1) == ' ') {
//     eraseFire();
//     fY = fY - 1;
//     displayFire();

//   } else if (getCharAtxy(fX, fY - 1) == '|' || getCharAtxy(fX, fY - 1) == '-' ||
//              getCharAtxy(fX, fY - 1) == '!' || getCharAtxy(fX, fY - 1) == '0' ||
//              getCharAtxy(fX, fY - 1) == '^' || getCharAtxy(fX, fY - 1) == '@' ||
//              getCharAtxy(fX, fY - 1) == '(' || getCharAtxy(fX, fY - 1) == ')' ||
//              getCharAtxy(fX, fY - 1) == ' ') {
//     for (int i = health; i > 0; i--) {
//       i--;
//       health = i;
//     }
//     eraseFire();
//   }
// }


void generateBulletOfEnemy() {
  if(getCharAtxy(eX+3, eY-1) == ' '){
    FireX[fireCount] = eX + 3;
    FireY[fireCount] = eY - 1;
    fireActive[fireCount] = true;

    gotoxy(FireX[fireCount], FireY[fireCount]);
    cout << "@" << endl;
  
    fireCount++;
  }
}
void printFireOfEnemy(int x, int y) 
{
  gotoxy(x, y);
  cout << "@" << endl;
}


void eraseFireOfEnemy(int x, int y) 
{
  gotoxy(x, y);
  cout << " " << endl;
}

void makeFireinactive(int i)
{
  fireActive[i] = false; 
}


void moveFireOfEnemy() {
  
  for (int i = 0; i < fireCount; i++) {
    if (fireActive[i]) 
     {
  
      if (getCharAtxy(FireX[i], FireY[i] - 1) != ' ') 
      {
        eraseFireOfEnemy(FireX[i], FireY[i]);
        makeFireinactive(i);
      }
        else 
        {
          eraseFireOfEnemy(FireX[i], FireY[i]);
          FireY[i] -= 1;
          printFireOfEnemy(FireX[i], FireY[i]);
        }
       }
      
     }
      
  }

  
void generateBulletOfEnemy3() {
  if(getCharAtxy(e2X+1, e2Y) == ' '){
    Fire2X[fireCount2] = e2X +1;
    Fire2Y[fireCount2] = e2Y ;
    fireActive2[fireCount2] = true;

    gotoxy(Fire2X[fireCount2], Fire2Y[fireCount2]);
    cout << ">" << endl;
  
    fireCount2++;
  }
}
void printFireOfEnemy3(int x, int y) 
{
  gotoxy(x, y);
  cout << ">" << endl;
}


void eraseFireOfEnemy3(int x, int y) 
{
  gotoxy(x, y);
  cout << " " << endl;
}

void makeFireinactive3(int i)
{
  fireActive2[i] = false; 
}


void moveFireOfEnemy3() {
  
  for (int i = 0; i < fireCount2; i++) {
    if (fireActive2[i]) 
     {
  
      if (getCharAtxy(Fire2X[i]+1, Fire2Y[i] ) != ' ') 
      {
        eraseFireOfEnemy3(Fire2X[i], Fire2Y[i]);
        makeFireinactive3(i);
      }
        else 
        {
          eraseFireOfEnemy3(Fire2X[i], Fire2Y[i]);
          Fire2X[i] += 1;
          printFireOfEnemy3(Fire2X[i], Fire2Y[i]);
        }
       }
      
     }
      
  }