#include <iostream>

using namespace std;

const int kMaxN = 1e6;

int n, m;
int a;
int b;
int MaxA, MaxB;

void solve() {
  static const string A = "Alice", B = "Bob";
  MaxA = 0, MaxB = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    MaxA = max(a, MaxA);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b;
    MaxB = max(b, MaxB);
  }
  if (MaxA == MaxB) {
    cout << A << "\n" << B << endl;
  } else if (MaxA > MaxB) {
    cout << A << "\n" << A << endl;
  } else {
    cout << B << "\n" << B << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
