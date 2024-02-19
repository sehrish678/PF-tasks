#include <iostream>
using namespace std;
string Output(string words);
main() {
  string words;
  cout << "Enter a string: ";
  cin >> words;
  Output(words);
}
string Output(string words) {
  cout << "Reversed String: ";
  for (int x = 4; x >= 0; x--) {
    cout << words[x];
  }
}