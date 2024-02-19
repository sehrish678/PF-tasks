#include <iostream>
using namespace std;
main() {
  float quarter;
  float dime;
  float nickel;
  float penny;
  float totalAmount;
  cout << "Enter quarters: ";
  cin >> quarter;
  cout << "Enter dimes: ";
  cin >> dime;
  cout << "Enter nickels: ";
  cin >> nickel;
  cout << "Enter pennies: ";
  cin >> penny;
  cout << "Enter the total amount due: $";
  cin >> totalAmount;
  string output;
  float Totalmoney =
      (quarter * 0.25 + dime * 0.10 + nickel * 0.05 + penny * 0.01);
  if (Totalmoney >= totalAmount) {
    output = "Yes";
  } else {
    output = "No";
  }
  cout << "Can you pay the amount? " << output;
}
