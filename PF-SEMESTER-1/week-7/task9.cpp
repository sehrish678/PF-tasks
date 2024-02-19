#include <iomanip>
#include <iostream>

using namespace std;

int calculateTotalAmount(int Money, int year);
int main() {
  int Money, year;
  cout << "Enter Money: ";
  cin >> Money;
  cout << "Enter Year : ";
  cin >> year;
  int leftMoney = calculateTotalAmount(Money, year);
  if (leftMoney >= 0) {
    cout << "Yes! He will live a carefree life and will have " << fixed
         << setprecision(2) << leftMoney << " dollars left." << endl;
  } else {
    cout << "He will need " << fixed << setprecision(2) << -leftMoney
         << " dollars to survive." << endl;
  }

  return 0;
}

int calculateTotalAmount(int Money, int year) {
  int age = 18;
  for (int i = 1800; i <= year; i++) {
    if (i % 2 == 0) {
      Money -= 12000;
    } else {
      Money -= (12000 + 50 * age);
    }
    age++;
  }
  return Money;
}
