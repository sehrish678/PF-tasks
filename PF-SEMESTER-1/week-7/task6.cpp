#include <iostream>
using namespace std;
int GCD(int num1, int num2);
int LCM(int num1, int num2);

main() {
  int num1, num2;
  cout << "Enter the first number: ";
  cin >> num1;

  cout << "Enter the second number: ";
  cin >> num2;

  cout << "GCD: " << GCD(num1, num2) << endl;
  cout << "LCM: " << LCM(num1, num2);
}

int GCD(int num1, int num2) {
  if (num2 == 0)
    return num1;
  else
    return GCD(num2, num1 % num2);
}

int LCM(int num1, int num2) { return num1 * num2 / GCD(int num1, int num2); }
