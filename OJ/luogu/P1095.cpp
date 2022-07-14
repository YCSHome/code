#include <iostream>

using namespace std;

int s1, s2;
int m, s, t;

int main() {
  cin >> m >> s >> t;
  for (int i = 1; i <= t; i++) {
    s1 += 17;
    if (m >= 10) {
      s2 += 60;
      m -= 10;
    } else {
      m += 4;
    }
    if (s2 > s1) {
      s1 = s2;
    }
    if (s1 > s) {
      cout << "Yes" << endl << i << endl;
      return 0;
    }
  }
  cout << "No" << endl << s1 << endl;
  return 0;
}
