#include <iostream>

using namespace std;

int n, x;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == 0) {
      continue;
    }
    if (x >= 0 && i != 1) cout << "+";
    if (x != 1 && x != -1) {
      cout << x;
    }
    if (x == -1) {
      cout << '-';
    }
    cout << "x";
    if (i != n) {
      cout << "^" << (n - i + 1);
    }
  }
  cin >> x;
  if (x == 0) return 0;
  if (x > 0) cout << "+";
  cout << x << endl;
  return 0;
}
