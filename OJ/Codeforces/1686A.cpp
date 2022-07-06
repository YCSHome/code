#include <iostream>

using namespace  std;

const int kMaxN = 1e6;

double a[kMaxN];

void solve() {
  int n;
  double Sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    Sum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    if ((double)(Sum - a[i]) / (n - 1) == a[i]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
