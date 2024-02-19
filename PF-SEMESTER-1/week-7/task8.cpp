#include <iostream>
using namespace std;

int TotalMoney(int Age, int PriceOfWashingMachine, int PriceOfToy);

int main() {
  int Age, PriceOfWashingMachine, PriceOfToy;
  cout << "Enter Lilly's Age: ";
  cin >> Age;
  cout << "Enter the price of the washing machine: ";
  cin >> PriceOfWashingMachine;
  cout << "Enter the unit price of each toy: ";
  cin >> PriceOfToy;
  int result = TotalMoney(Age, PriceOfWashingMachine, PriceOfToy);

  if (result >= PriceOfWashingMachine) {
    int number = result - PriceOfWashingMachine;
    cout << "Yes! " << endl << number;
  }
  if (result < PriceOfWashingMachine) {
    int digit = PriceOfWashingMachine - result;
    cout << "No! " << endl << digit;
  }

  return 0;
}

int TotalMoney(int Age, int PriceOfWashingMachine, int PriceOfToy) {
  int totalMoney = 0;

  for (int i = 2; i <= Age; i += 2) {
    totalMoney += 10 * (i / 2);
    totalMoney = totalMoney - 1;
  }
  int toyIncome = (Age / 2) * PriceOfToy;
  totalMoney += toyIncome;
  return totalMoney;
}
