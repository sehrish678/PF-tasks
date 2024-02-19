#include <iostream>
using namespace std;
main()
{
    int numOfChords;
    cout << "Enter the number of chords:";
    cin >> numOfChords;
    char chord[numOfChords];
    cout << "Enter " << numOfChords << " one per line: " << endl;
    for (int i = 0; i < numOfChords; i++)
    {
        cin >> chord[i];
        cout << chord[i] << endl;
        if (chord[i] != '7')
        {
            cout << chord[i] << "7";
        }
    }
}