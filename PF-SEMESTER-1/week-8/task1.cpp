#include <iostream>
using namespace std;
bool DoesBrickFit(int height, int length, int depth, int hole1, int hole2);
main()
{
    int height;
    cin >> height;
    int length;
    cin >> length;
    int depth;
    cin >> depth;
    int hole1;
    cin >> hole1;
    int hole2;
    cin >> hole2;
    bool result = DoesBrickFit(height, length, depth, hole1, hole2);
    if (result == true)
    {
        cout << "true" << endl;
    }
    else if (result == false)
    {
        cout << "false" << endl;
    }
}

bool DoesBrickFit(int height, int length, int depth, int hole1, int hole2)
{
    if (length <= hole1 || depth <= hole2)
    {
        return true;
    }
    else
    {
        return false;
    }
}