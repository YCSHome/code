#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n;
int a[kMaxN];

int main() {
  cin >> n;
  cout << n << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      a[j] ^= 1;
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}
