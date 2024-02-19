#include <iostream>
using namespace std;
main()
{
    string character;
    cout << "Seed type: ";
    cin >> character;

    int water;
    cout << "Amount of water in integer: ";
    cin >> water;

    int fertilizer;
    cout << "Amount of fertilizer: ";
    cin >> fertilizer;

    int temp;
    cout << "Enter the temperature: ";
    cin >> temp;

    if (temp >= 20 && temp <= 30)
    {
        for (int i = 0; i < water; i++)
        {
            for (int i = 0; i < water; i++)
            {
                cout << "-";
            }
            for (int i = 0; i < fertilizer; i++)
            {
                cout << character;
            }
        }
    }
    else if (temp < 20 || temp > 30)
    {
        for (int i = 0; i < water; i++)
        {
            for (int i = 0; i < water; i++)
            {
                cout << "-";
            }
        }
        cout << character;
    }
}