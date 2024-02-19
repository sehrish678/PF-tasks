#include <iostream>
using namespace std;
string Nextword(string line);
main() {
  string line;
  cout << "Enter a string: ";
  getline(cin, line);
  Nextword(line);
}
string Nextword(string line) {
  char character1;
  cout << "Shifted string: ";
  for (int x = 0; line[x] != '\0'; x++) {
    if (line[x] == 'Z') {
      cout << 'A';
    } else if (line[x] == 'z') {
      cout << 'a';
    } else if (line[x] == ' ') {
      cout << line[x];
    } else {
      char character2 = line[x];
      int asciiCode = character2;
      asciiCode++;
      character1 = asciiCode;
      cout << character1;
    }
  }
}