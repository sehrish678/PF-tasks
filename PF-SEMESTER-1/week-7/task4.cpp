#include <iostream>
using namespace std;
int frequencyOfNumber(int num, int digitToCheck);
main() {
  int num;
  int digitToCheck;
  cout << "Enter a num: ";
  cin >> num;
  cout << "Enter the digitToCheck to check: ";
  cin >> digitToCheck;
  int result;
  result = frequencyOfNumber(num, digitToCheck);
  cout << "Frequency: " << result;
}

int frequencyOfNumber(int num, int digitToCheck) {

  int count = 0;
  while (num > 0) {
    int mod;
    mod = num % 10;
    num = num / 10;

    if (mod == digitToCheck) {

      count++;
    }
  }
  return count;
}
