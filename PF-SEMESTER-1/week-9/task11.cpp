#include <iostream>
using namespace std;
string RemoveVowels(string letter) {
  string ouput;
  for (int x = 0; x < letter.length(); x++) {
    if (letter[x] != 'a' && letter[x] != 'e' && letter[x] != 'x' &&
        letter[x] != 'o' && letter[x] != 'u' && letter[x] != 'A' &&
        letter[x] != 'E' && letter[x] != 'I' && letter[x] != 'O' &&
        letter[x] != 'U')
      ouput = ouput + letter[x];
  }
  return ouput;
}
main() {
  string letter;
  cout << "Enter a string: ";
  getline(cin, letter);
  string ouput = RemoveVowels(letter);
  cout << "String with vowels removed: " << ouput << endl;
}
