#include <iostream>
using namespace std;
void jazzifychord(string chord[], int numOfchords);
main() {
  int n;
  cout << "Enter the number of chords: ";
  cin >> n;
  string chord[n];
  cout << "Enter " << n << " chords, one per line: " << endl;
  for (int x = 0; x < n; x++) {
    cin >> chord[x];
    chord[n];
  }
  jazzifychord(chord, n);
}
void jazzifychord(string chord[], int numOfchords) {
  cout << "Jazzified chords: [";
  for (int x = 0; x < numOfchords; x++) {

    if (chord[x].back() != '7') {
      cout << chord[x] << "7";

    } else {
      cout << chord[x];
    }
    if (x != numOfchords - 1) {
      cout << ", ";
    }
  }
  cout << "]";
}
