#include <iostream>
using namespace std;
main() {
  string array;

  int FirstElement;
  cout << "Enter the number of elements for the first array (must be 2): ";
  cin >> FirstElement;

  cout << "Enter " << FirstElement
       << " elements for the first array, one per line:" << endl;

  int Array1[FirstElement];

  for (int x = 0; x < FirstElement; x++) {
    cin >> Array1[x];
  }

  int secondElement;
  cout << "Enter the number of elements for the second array: ";
  cin >> secondElement;

  cout << "Enter " << secondElement
       << " elements for the second array, one per line:" << endl;

  array += "[" + to_string(Array1[0]) + ", ";

  int Array2[secondElement];
  for (int x = 0; x < secondElement; x++) {
    cin >> Array2[x];
    array += to_string(Array2[x]) + ", ";
  }
  array += to_string(Array1[1]) + "]";

  cout << "Resulting array: " << array;
}
