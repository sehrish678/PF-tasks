#include <iostream>
using namespace std;
string Output(string words);
main() {
  string words;
  cout << "Enter a word: ";
  cin >> words;
  Output(words);
}

string Output(string words) {
  for (int i = 0; words[i] != '\0'; i++) {
    cout << words[i] << " found at position " << i << endl;
  }
}