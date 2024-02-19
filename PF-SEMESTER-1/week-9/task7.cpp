#include<iostream>
using namespace std;
void Conversion(string Pin);

main(){
    string Pin;
    cout << "Enter your PIN (4 digits): ";
    cin >> Pin;
    Conversion(Pin);
}

void Conversion(string Pin){
    string DanceMoves [] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
    if(Pin[0] == '\0'|| Pin[1] == '\0' || Pin[2] == '\0' || Pin[3] == '\0' ||
     !(Pin[0] >= '0' && Pin[0] <= '9') || !(Pin[1] >= '0' && Pin[0] <= '9')||
     !(Pin[2] >= '0' && Pin[2] <= '9') || !(Pin[3] >= '0' && Pin[3] <= '9')){
        cout << "Invalid input." << endl;
        return;
     }

     for(int i=0; i < Pin.length(); i++){
        int number;
        number = Pin[i] - '0';
        int Digit;
        Digit = (number+i)%10;
        cout << DanceMoves[Digit]<< "";
        if(i!= Pin.length() - 1){
            cout << ", ";
        }
     }
     cout << endl;
}