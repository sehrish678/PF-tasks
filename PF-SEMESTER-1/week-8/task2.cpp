#include <iostream>
using namespace std;
main()
{
    string myType;
    cout << "Your type: ";
    cin >> myType;
    string OpponentType;
    cout << "Opponent's type: ";
    cin >> OpponentType;
    int MyAttackPow;
    cout << "Your attack power: ";
    cin >> MyAttackPow;
    int OpponentDefense;
    cout << "The Opponent's Defense: ";
    cin >> OpponentDefense;
    int damage;
    if (myType == "fire" && OpponentType == "grass")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 2;
    }
    else if (myType == "electric" && OpponentType == "fire")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    else if (myType == "water" && OpponentType == "fire")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 2;
    }
    else if (myType == "grass" && OpponentType == "water")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 2;
    }
    else if (myType == "water" && OpponentType == "grass")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 0.5;
    }
    else if (myType == "water" && OpponentType == "electric")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 0.5;
    }
    else if (myType == "electric" && OpponentType == "water")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 2;
    }
    else if (myType == "fire" && OpponentType == "water")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 0.5;
    }
    else if (myType == "grass" && OpponentType == "fire")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 0.5;
    }

    else if ((myType == "water" && OpponentType == "water"))
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    else if ((myType == "grass" && OpponentType == "electric"))
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    else if ((myType == "fire" && OpponentType == "electric"))
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    else if ((myType == "grass" && OpponentType == "grass"))
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    else if ((myType == "grass" && OpponentType == "grass"))
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    else if (myType == "fire" && OpponentType == "fire")
    {
        damage = 50 * (MyAttackPow / OpponentDefense) * 1;
    }
    cout << "The damage is: " << damage << endl;
}