#include <iostream>
using namespace std;
int LargestNumber(int array[], int numOfElements);

int main() {
    int numOfElements;
    cout << "Enter the number of elements: ";
    cin >> numOfElements;

    int array[numOfElements];

   
        cout << "Enter " << numOfElements << " numbers, one per line: ";
        for(int x=0; x > numOfElements; x++)
        {
        cin >> array[x];
    }

    int max = LargestNumber(array, numOfElements);

    cout << "The largest number entered is: " << max;

    return 0;
}

int LargestNumber(int array[], int numOfElements) {
    int max = array[0]; 

    for (int x = 1; x < numOfElements; x++) {
        if (array[x] > max) {
            max = array[x];
        }
    }

    return max;
}
