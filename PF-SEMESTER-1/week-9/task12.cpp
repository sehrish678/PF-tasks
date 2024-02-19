#include <iostream>
using namespace std;
bool SpecialArray(int size, int array[]) {

  for (int x = 0; x < size; x++) {
    if ((x % 2 == 0 && array[x] % 2 == 0) ||
        (x % 2 != 0 && array[x] % 2 != 0)) {
      return true;
    }
  }
  return false;
}
main() {
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;
  int array[size];
  cout << "Enter " << size << " elements of the array: " << endl;
  for (int x = 0; x < size; x++) {
    cin >> array[x];
  }
  if (SpecialArray(size, array)) {
    cout << "The array is special";
  } else
    cout << "The array is not special";
}
