#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int t, n;
int a[kMaxN];

void solve() {
  int x = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != i - 1) {
      if (x == -1) {
        x = a[i];
      } else {
        x &= a[i];
      }
    }
  }
  cout << x << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
