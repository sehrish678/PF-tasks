#include <iostream>
using namespace std;
bool isAlreadyEntered(int array[], int length, int num) {
  for (int x = 0; x < length; ++x) {
    if (array[x] == num) {
      return true;
    }
  }
  return false;
}

int main() {
  const int maxSize = 100;
  int numOfElements;

  cout << "Enter the num of elements: ";
  cin >> numOfElements;
  cout << "Enter " << numOfElements << " number, one per line:" << endl;

  for (int x = 0; x < numOfElements; ++x) {
    int input;

    std::cin >> input;

    if (isAlreadyEntered(number, x, input)) {
      cout << "Already Entered: " << input;
      --x;
    } else {
      number[x] = input;
    }
  }

  cout << "Unique number entered: ";
  for (int x = 0; x < numOfElements; ++x) {
    cout << number[x] << " ";
  }

  return 0;
}
