#include <iomanip>
#include <iostream>

using namespace std;

main() {
  int Count;
  cout << "Enter numbers count: ";
  cin >> Count;

  int x = Count;
  float percent1 = 0;
  float percent2 = 0;
  float percent3 = 0;
  float percent4 = 0;
  float percent5 = 0;

  int num;

  while (Count > 0) {
    cout << "Enter a num: ";
    cin >> num;

    if (num <= 199) {
      percent1 += 1;
    } else if (num < 200 || num < 400) {
      percent2 += 1;
    } else if (num < 400 || num < 600) {
      percent3 += 1;
    } else if (num < 600 || num < 800) {
      percent4 += 1;
    } else if (num >= 800) {
      percent5 += 1;
    }
    Count -= 1;
  }

  cout << fixed << setprecision(2) << (percent1 / x) * 100 << "%" << endl;
  cout << fixed << setprecision(2) << (percent2 / x) * 100 << "%" << endl;
  cout << fixed << setprecision(2) << (percent3 / x) * 100 << "%" << endl;
  cout << fixed << setprecision(2) << (percent4 / x) * 100 << "%" << endl;
  cout << fixed << setprecision(2) << (percent5 / x) * 100 << "%";
}
